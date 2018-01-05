#ifndef __LOCAL_DEFAULT_H__
#define __LOCAL_DEFAULT_H__

#include "../FileUtils/Data.h"
#include "../XML/XML.h"



#define GetIntFromXML		LocalDefault::getInstance()->getIntegerForKeyValue
#define SetIntToXML			LocalDefault::getInstance()->setIntegerForKeyValue
#define GetStringFromXML	LocalDefault::getInstance()->getStringForKeyValue
#define SetStringToXML		LocalDefault::getInstance()->setStringForKeyValue
#define GetBoolFromXML		LocalDefault::getInstance()->getBoolForKeyValue
#define SetBoolToXML		LocalDefault::getInstance()->setBoolForKeyValue
#define GetFloatFromXML		LocalDefault::getInstance()->getFloatForKeyValue
#define SetFloatToXML		LocalDefault::getInstance()->setFloatForKeyValue
#define GetDoubleFromXML	LocalDefault::getInstance()->getDoubleForKeyValue
#define SetDoubleToXML		LocalDefault::getInstance()->setDoubleForKeyValue
#define GetDataFromXML		LocalDefault::getInstance()->getDataForKeyValue
#define SetDataToXML		LocalDefault::getInstance()->setDataForKeyValue

class  LocalDefault
{
public:
	LocalDefault();
	~LocalDefault();
	static LocalDefault* getInstance();
	static void destroyInstance();
public:
	enum ENCRYPT_TYPE  //�Ƿ����
	{
		IS_EN,
		NO_EN
	};
public:
	bool	getBoolForKeyValue(const string nKey);											//��boolֵ
	int		getIntegerForKeyValue(const string nKey);										//��intֵ
	float	getFloatForKeyValue(const string nKey);											//��floatֵ
	double	getDoubleForKeyValue(const string nKey);											//��floatֵ
	string	getStringForKeyValue(const string nKey);                                        //��stringֵ
	Data	getDataForKeyValue(const char* pKey);

	void	setBoolForKeyValue(const string nKey, bool value) ;								//дboolֵ
	void	setIntegerForKeyValue(const string nKey, int value) ;							//дintֵ
	void	setFloatForKeyValue(const string nKey, float value) ;							//дfloatֵ
	void	setDoubleForKeyValue(const string nKey, double value);							//дdoubleֵ
	void	setStringForKeyValue(const string nKey, const std::string& value) ;				//дstringֵ
	void	setDataForKeyValue(const char* pKey, const Data& value) ;

	MING_SYNTHESIZE(ENCRYPT_TYPE, _mIsEn, Encryption);
private:

	const std::string& getXMLFilePath();
	bool isXMLFileExist();
    void initXMLFilePath();
	bool init();

	std::string	EncryptData(const char* szPass) const;		//�ַ�������
	std::string	CrevasseData(const char* szEncryPass) const;

	void setValueForKey(const char* pKey, const char* pValue);
	string getValueForKey(const char* pKey);

    static LocalDefault* _userDefault;
    static std::string _filePath;
    static bool _isFilePathInitialized;
	XML* _mXML;

};




#endif // __LOCAL_DEFAULT_H__
