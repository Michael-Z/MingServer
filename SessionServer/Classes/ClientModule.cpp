#include "ClientModule.h"
#include "KxCore.h"
#include "SessionClient.h"
#include "SessionConnect.h"
#include "NetworkManager.h"
#include "Protocol.h"
#include "SessionServer.h"
#include "BufferData.h"
#include <set>


ClientModule::ClientModule(void)
{
}

ClientModule::~ClientModule(void)
{
}

void ClientModule::processLogic(char* buffer, unsigned int len, IKxComm *target)
{
    SessionClient* pClient = dynamic_cast<SessionClient*>(target);
	ServerConfig * pServerConfig = SessionServer::getInstance()->getServerCoinfig();

	// ֱ��ת������Ϸ������
	Head* head = reinterpret_cast<Head*>(buffer);
	int nMainCmd = head->MainCommand();
	int nSubCmd = head->SubCommand();
	head->uid = pClient->getGuestId();//������֮��ͨѶ�����ID

	//LOGIN_DATA* a = reinterpret_cast<LOGIN_DATA*>(head->data());

	KX_LOGDEBUG("ClientModule onRecy Message!");

	pClient->sendDataToServer(nMainCmd, nSubCmd, buffer, len);
}

void ClientModule::processError(IKxComm *target)
{
    // ��Ҷ���
    this->userDisconnect(target);
}

// 1. �������з����������XXX������
// 2. ��ClientManager���Ƴ������
void ClientModule::userDisconnect(IKxComm *target)
{
    SessionClient *pClient = dynamic_cast<SessionClient*>(target);
    if (pClient == NULL)
    {
        return;
    }

    // ����������Ϣ
    Head head;
    head.MakeCommand(1, 1);
    head.length = sizeof(head);
    head.uid = pClient->getUserId();

    // �������ݵ���˸�֪��ɫ����
    // ����������Ϣ�����ָ���ķ�����
    pClient->sendDataToAllServer(reinterpret_cast<char*>(&head), sizeof(head));
    // �ر�socket����NetWorkManager�к�clean�Ƴ�
    pClient->clean();
}
