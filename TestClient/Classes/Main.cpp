#include <iostream>
#include <string>
#include <ctime> 
#include "TestClient.h"
#include "GameNetworkNode.h"

#include "Lua/LuaRegiest.h"
#include "Lua/LuaStack_.h"

#include "log/LogFileHandler.h"
#include "log/LogConsoleHandler.h"
#include "log/LogManager.h"


using namespace std;


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
	pFileHandle->setNewFile(true);
	pFileHandle->setFileName("TestClientOut");
	pFileHandle->setFastModel(false);
	LogManager::getInstance()->addHandler(2, pFileHandle);

	regiestLuaFunction();
	LuaStack_::getInstance()->executeScriptFile("../LuaSupport/Test/Test.lua");
	LogManager::destroy();


	while (true)
	{

	}
    return 0;
}
