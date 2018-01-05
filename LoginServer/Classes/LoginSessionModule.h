#ifndef __SESSION_MODULE_H__
#define __SESSION_MODULE_H__
/************************************************************************/
/*                  ���Ǹ���SessionServer������ģ��                     */
/************************************************************************/

#include "BaseModule.h"

class LoginSessionModule : public BaseModule
{
public:
    LoginSessionModule(void);
    virtual ~LoginSessionModule(void);

    //����ͻ��˷�����Ϣ
    virtual void processLogic(char* buffer, unsigned int len, IKxComm *target);
    //�ͻ�����Session�������Ͽ���֪ͨ��Ϸ�������������������Դ
    virtual void processError(IKxComm *target);

private:
    //��Ҷ���
    void userDisconnect(IKxComm *target);
};

#endif
