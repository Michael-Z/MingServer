#ifndef __LOGIN_SERVICE_H__
#define __LOGIN_SERVICE_H__

#include "KxCommInterfaces.h"

class LoginService
{
public:

	static void processService(int subcmd, int uid, char *buffer, int len, IKxComm *commun);

	static void processUserLogin(int uid, char *buffer, int len, IKxComm *commun);

	//ǰ��ս��������С������
	static void processUserReconect(int uid, char *buffer, int len, IKxComm *commun);
	//�����û���¼���ύ��־��Ϣ
	static void processUserLogService(int uid, char *buffer, int len, IKxComm *commun);
	//�����û���¼���ύ������־��Ϣ
	static void processGuideLogService(int uid, char *buffer, int len, IKxComm *commun);
	//�����û�����������ʱ���ˢ����������
	static void processLoginFreshService(int uid, char *buffer, int len, IKxComm *commun);
};

#endif //__LOGIN_SERVICE_H__
