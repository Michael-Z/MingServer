#include <iostream>
#include <string>
#include <ctime> 
#include "TestClient.h"
#include "GameNetworkNode.h"

//#include "Lua/LuaRegiest.h"
//#include "Lua/LuaStack.h"

#include "log/LogFileHandler.h"
#include "log/LogConsoleHandler.h"
#include "log/LogManager.h"

#include "CommonHead.h"
#include <io.h>
//#include <cstring>

void listFiles(const char * dir)
{
	char dirNew[200];
	strcpy(dirNew, dir);
	strcat(dirNew, "\\*.*");    // ��Ŀ¼�������"\\*.*"���е�һ������

	intptr_t handle;
	_finddata_t findData;

	handle = _findfirst(dirNew, &findData);
	if (handle == -1)        // ����Ƿ�ɹ�
		return;

	do
	{
		if (findData.attrib & _A_SUBDIR)
		{
			if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
				continue;

			//cout << findData.name << "\t<dir>\n";

			KX_LOGDEBUG(" findData.name=%s <dir>", findData.name);

			// ��Ŀ¼�������"\\"����������Ŀ¼��������һ������
			strcpy(dirNew, dir);
			strcat(dirNew, "\\");
			strcat(dirNew, findData.name);

			listFiles(dirNew);
		}
		else
		{
			KX_LOGDEBUG(" findData.name=%s size=%d", findData.name, findData.size);
			//cout << findData.name << "\t" << findData.size << " bytes.\n";
		}
			
	} while (_findnext(handle, &findData) == 0);

	_findclose(handle);    // �ر��������
}


using namespace std;

void   Delay(int   time)//time*1000Ϊ���� 
{
	clock_t   now = clock();

	while (clock() - now < time);
}

int main(int argc, char ** argv) 
{
	
	//TestClient::getInstance()->onServerInit();
	//auto poll = CGameNetworkNode::getInstance()->getPoller();
	//poll->poll();

	//Delay(3 * 1000);   //��ʱ5��
	//TestClient::getInstance()->login();

	//while (true)
	//{
	//	poll->poll();
	//}

	//char temp = ' ';
	//cout << "��¼��,������ر�" << endl;
	//scanf("%c", &temp);
 //   TestClient::destroy();

	LogManager::getInstance()->setShowTime(false);
	LogManager::getInstance()->setShowDate(false);
	LogManager::getInstance()->addHandler(1, new LogConsoleHandler());
	LogFileHandler* pFileHandle = new LogFileHandler();
	pFileHandle->setFilePath("../bin/");
	pFileHandle->setFileName("TestOut");
	pFileHandle->setFastModel(false);
	LogManager::getInstance()->addHandler(2, pFileHandle);

	//regiestLuaFunction();
	//LuaStack::getInstance()->executeScriptFile("main.lua");
	//LogManager::destroy();
	
	std::string dir = "./";

	listFiles(dir.c_str());

	while (true)
	{

	}
    return 0;
}
