/*
* KxCS��ܹ���ͷ�ļ�
* KxCS����ǻ���KxServer��Cocos2d-x������ͬ����ܣ�CS��ʾClient & Server
* ֧�ְ���KxCS˼���д��Cocos2d-x��Ϸʵ������ͬ������֤����
* ���ͻ����߼����뿽��������������д������ʼ�����뼴��ʵ����֤
*/
#ifndef __KXCSCOMM_H__
#define __KXCSCOMM_H__

//#include <map>
//#include <list>
//#include <deque>
//#include <vector>
//#include <string>
//#include "KxPlatform.h"

//#define RunningInServer
//#ifndef RunningInServer

//#include "cocos2d.h"
//
//using cocos2d::Ref;
//using cocos2d::Component;
//using cocos2d::Node;
//using cocos2d::Scene;
//using cocos2d::Layer;
//using cocos2d::Scheduler;
//using cocos2d::Vec2;
//using cocos2d::Director;
//using cocos2d::Color3B;
//using cocos2d::Size;
//using cocos2d::Rect;
//using cocos2d::Touch;
//using cocos2d::Event;
//using cocos2d::Point;
//
//#define LOG CCLOG

//#else

// �������Զ����Ref��
//#define Scene Node
//#define Layer Node
//
//#ifndef LOG
//#define LOG LOGINFO
//#endif 

//#endif // !RunningInServer


//#if KX_TARGET_PLATFORM == KX_PLATFORM_LINUX
//#include<stdlib.h>
//#include<stdio.h>
//#include<time.h>
//#include<string.h>
//#endif


//�����ĺ�
//#define SAFE_RETAIN(ref) do { if(NULL != ref) { ref->retain(); } } while (0);
//#define SAFE_RELEASE(ref) do { if(NULL != ref) { ref->release(); ref = NULL; } } while (0);
//#define SAFE_DELETE(ref) do { if(NULL != ref) { delete ref; ref = NULL; } } while (0);

//���ڵ����ڴ�й¶�ĺ�
//#define SAFE_RETAIN(ref) do { if(NULL != ref) { LOG("retain %d On File %s Line %d",ref->_ID, __FILE__, __LINE__); ref->retain(); } } while (0);
//#define SAFE_RELEASE(ref) do { if(NULL != ref) { LOG("release %d On File %s Line %d",ref->_ID, __FILE__, __LINE__); ref->release(); ref = NULL; } } while (0);


//#define CHECK_BREAK(success) if(!(success)) break;
//#define CHECK_CONTINUE(success) if(!(success)) continue;
//#define CHECK_RETURN_FALSE(success) if(!(success)) { LOGERROR("Execute False On File %s Line %d : %s", __FILE__, __LINE__, #success); return false; };
//#define CHECK_RETURN_VOID(success) if(!(success)) return;
//#define CHECK_RETURN_NULL(success) if(!(success)) { LOGERROR("Execute False On File %s Line %d : %s", __FILE__, __LINE__, #success); return NULL; };
//#define CHECK_RETURN_INT(success) if(!(success)) { LOGERROR("Execute False On File %s Line %d : %s", __FILE__, __LINE__, #success); return -1; };
//#define CHECK_RETURN_DEBUG_VOID(success) if(!(success)) { LOGERROR("Execute False On File %s Line %d : %s", __FILE__, __LINE__, #success); return; };

//typedef std::vector<int>				VecInt;
//typedef std::vector<float>				VecFloat;
//typedef std::vector<std::vector<int> >   VecVecInt;
//typedef std::vector<std::vector<float> > VecVecFloat;
//typedef std::map<std::string, float>	MapStrFloat;

#endif // !__KXCSCOMM_H__
