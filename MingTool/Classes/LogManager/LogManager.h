/*
*   ��־��¼��
*   ��ΪKxLogger�Լ�IKxLogHandler������
*   KxLogger������־�Ĺ��ˣ����ݿ����Լ����ã���������IKxLogHandler
*   IKxLogHandler����ʵ����־��Ϣ�Ĵ���������д�ļ������������̨������������ʾ��
*/
#ifndef _LOGMANAGER_H__
#define _LOGMANAGER_H__
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

#if (MING_TARGET_PLATFORM == MING_PLATFORM_LINUX)
	#include<stdlib.h>
	#include<stdio.h>
	#include<time.h>
	#include<string.h>
	#include <stdarg.h>
#endif


using namespace std;

// ��־����
enum LOG_LEVEL
{
    LOG_INFO,         // ��Ϣ����
    LOG_DEBUG,        // ���Լ���
    LOG_ERROR         // ���󼶱�

};
// ��־����������
// ʵ����־�Ĵ���
class ILogHandler
{
public:
	ILogHandler()
		:m_Tag(1)
	{ }
	virtual ~ILogHandler() { }
	// �����¼��־ʱ�ص���������־��Ϣ
	virtual bool onLog(int level, const std::string& log) = 0;
	// ����ӽ�KxLoggerʱ�ص�
	virtual void onEnter() { }
	// ��KxLogger���Ƴ�ʱ�ص�
	virtual void onExit() { }
	// ���������־ʱ�ص�
	virtual void onClean() { }

	inline int getHandleId()
	{
		return m_HandlerId;
	}

	inline void setHandleId(int handleId)
	{
		m_HandlerId = handleId;
	}

	int getTag()
	{
		return m_Tag;
	}

	inline void setTag(int tag)
	{
		m_Tag = tag;
	}

	virtual std::string getFileName()
	{
		return "";
	}

protected:
	int m_HandlerId;
	int m_Tag;
};

// ��־���󣨵�����
// ������־�Լ�IKxLogHandler���
class LogManager
{
private:
    LogManager();
    virtual ~LogManager();

public:
    static LogManager* getInstance();
    static void destroy();

    // ���һ����־������
    bool addHandler(int handleId, ILogHandler* handler);
    // ����handler�����handleId���һ����־������
    bool addHandler(ILogHandler* handler);
    // �Ƴ�һ����־������
    bool removeHandler(int handleId);
    // ����handleId����ȡһ����־������
    ILogHandler* getHandler(int id);
    // ������е���־������
    void clearHandler();

    // д��һ����־��������־���������д���
    void writelog(int tag, int level, const char* file, const char* func, int line, const char* log, ...);
    // �����־��ֻ�ǵ�����־��������onClean����
    void clearLog();

    // ������־���Լ���
    inline void setLogLevel(int lv) { m_LogLevel = lv; };
    inline int getLogLevel() { return m_LogLevel; }

    // �������ȡ��־����ʾ��Ϣ
    inline bool isShowLevel() { return m_LevelOption; }
    inline bool isShowTime() { return m_TimeOption; }
    inline bool isShowDate() { return m_DateOption; }
    inline bool isShowFile() { return m_FileOption; }
    inline bool isShowFunc() { return m_FuncOption; }
    inline bool isShowLine() { return m_LineOption; }
    inline void setShowLevel(bool b) { m_LevelOption = b; }
    inline void setShowTime(bool b) { m_TimeOption = b; }
    inline void setShowDate(bool b) { m_DateOption = b; }
    inline void setShowFile(bool b) { m_FileOption = b; }
    inline void setShowFunc(bool b) { m_FuncOption = b; }
    inline void setShowLine(bool b) { m_LineOption = b; }

	inline void HexDumpImp(const void *pdata, unsigned int len);

private:
    void updateFormat(int level, const char* log, const char* file, const char* func, int line);

private:
    int m_LogLevel;
    bool m_LevelOption;
    bool m_TimeOption;
    bool m_DateOption;
    bool m_FileOption;
    bool m_FuncOption;
    bool m_LineOption;
    std::string m_StringFormat;
    std::map<int, ILogHandler*> m_Handlers;
    static LogManager* m_Instance;
};

#define LOG(tag, level, log, ...) LogManager::getInstance()->writelog(tag, level, __FILE__, __FUNCTION__, __LINE__, log, ##__VA_ARGS__)
#define LOGDEBUG(log, ...) LogManager::getInstance()->writelog(1, LOG_LEVEL::LOG_DEBUG, __FILE__, __FUNCTION__, __LINE__, log, ##__VA_ARGS__)
#define LOGINFO(log, ...) LogManager::getInstance()->writelog(1, LOG_LEVEL::LOG_INFO, __FILE__, __FUNCTION__, __LINE__, log, ##__VA_ARGS__)
#define LOGERROR(log, ...) LogManager::getInstance()->writelog(1, LOG_LEVEL::LOG_ERROR, __FILE__, __FUNCTION__, __LINE__, log, ##__VA_ARGS__)
#define LOGBATTLE(...)       do {} while (0)

#endif //_LOGMANAGER_H__
