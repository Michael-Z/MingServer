#include "LoginService.h"
#include "helper/BufferTool.h"
#include "common/GameUserManager.h"
#include "GateManager.h"

using namespace std;


void LoginService::processService(int subcmd, int uid, char *buffer, int len, IKxComm *commun)
{
	switch (subcmd)
	{
	case LOGIN_CMD::CMD_LOGIN_CS:
		processUserLogin(uid, buffer, len, commun);
		break;
	default:
		break;
	}
}

void LoginService::processUserLogin(int uid, char *buffer, int len, IKxComm *commun)
{
	// ֱ��ת������Ϸ������
	Head* head = reinterpret_cast<Head*>(buffer);

	if (head->uid != uid || head->uid < 0)
	{
		return;
	}

	LOGIN_DATA *loginCS = reinterpret_cast<LOGIN_DATA*>(head->data());

	// ���CGameUser
	GameUser* pGameUser = CGameUserManager::getInstance()->getGameUser(uid);
	if (NULL == pGameUser)
	{
		//���û�
		pGameUser = CGameUserManager::getInstance()->newGameUser(uid);
	}
	else
	{
		// ����������û������ߺ����һ��ʱ�����Զ��Ƴ�
		// �ķ������޳��Ƴ��б����ݣ��������Զ��ͷţ���Ϊ�Һ������ֻ�����
		CGameUserManager::getInstance()->donotDeleteUser(uid);
		pGameUser->refreshModel(MODELTYPE_USER);
	}

	int nCurTime = KxBaseServer::getInstance()->getTimerManager()->getTimestamp();
	UserModel *pUserModel = dynamic_cast<UserModel*>(pGameUser->getModel(MODELTYPE_USER));



	// ��ʼ�·�����
	LOGIN_DATA loginSC;

	BufferData* bufferRe = newBufferData(MAIN_CMD::CMD_LOGIN_SERVER, LOGIN_CMD::CMD_LOGIN_SC);
	loginSC.accountId = loginCS->accountId;
	loginSC.passwd = loginCS->passwd;
	bufferRe->writeData(loginSC);

	//����д�����ݳ���
	char* bu = bufferRe->getBuffer();
	Head* headRe = reinterpret_cast<Head*>(bu);
	headRe->uid = uid;
	headRe->length = bufferRe->getDataLength();

	GateManager::getInstance()->Send(bufferRe->getBuffer(), headRe->length);

	//�����û�����
	//sendUserModel(loginCS->id, pUserModel);
	KX_LOGDEBUG("LoginFinish uid = %d", headRe->uid);
}

void LoginService::processUserReconect(int uid, char *buffer, int len, IKxComm *commun)
{
	// ���CGameUser
	GameUser* pGameUser = CGameUserManager::getInstance()->getGameUser(uid);
	if (NULL == pGameUser)
	{
		return;
	}

	//��������
	CGameUserManager::getInstance()->reSetGameUserData(uid);
	// ����������û������ߺ����һ��ʱ�����Զ��Ƴ�
	// �ķ������޳��Ƴ��б����ݣ��������Զ��ͷţ���Ϊ�Һ������ֻ�����
	CGameUserManager::getInstance()->donotDeleteUser(uid);
}

