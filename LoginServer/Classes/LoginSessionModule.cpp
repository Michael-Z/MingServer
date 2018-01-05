#include "LoginSessionModule.h"
#include "GateManager.h"
#include "LoginService.h"

LoginSessionModule::LoginSessionModule(void)
{
}

LoginSessionModule::~LoginSessionModule(void)
{
}

void LoginSessionModule::processLogic(char* buffer, unsigned int len, IKxComm *target)
{
	// ֱ��ת������Ϸ������
	Head* head = reinterpret_cast<Head*>(buffer);
	int nMainCmd = head->MainCommand();
	int nSubCmd = head->SubCommand();
	int uid = head->uid;
	int length = head->length;

	switch (nMainCmd)
	{
	case CMD_LOGIN_SERVER:
		LoginService::processService(nSubCmd, uid, buffer, length, target);
		break;
	default:
		break;
	}
}

void LoginSessionModule::processError(IKxComm *target)
{
    // ��Ҷ���
    this->userDisconnect(target);
}

// 1. �������з����������XXX������
// 2. ��ClientManager���Ƴ������
void LoginSessionModule::userDisconnect(IKxComm *target)
{

}
