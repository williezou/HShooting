#include "FileSystem.h"
#include "base64.h"
#include <iostream>

FileSystem::FileSystem()
{
}

FileSystem::~FileSystem()
{
}

int FileSystem::getHighScore(int iKey)
{
	CCLog("----------��ȡ");
	char pCharBuf[1024 * 10];
	sprintf(pCharBuf, "%s:%d", "HighScore", iKey);
	//if (!CCUserDefault::sharedUserDefault()->getIntegerForKey(pCharBuf))
	//{
	//	CCUserDefault::sharedUserDefault()->setIntegerForKey(pCharBuf, 0);
	//	return 0;
	//}
	//else
	//{
	//	string s = CCUserDefault::sharedUserDefault()->getStringForKey(pCharBuf);
	//	CCLog("����ǰ������: %s  ", s.c_str());
	//	string parseKey = base64_decode(s);
	//	CCLog("���ܺ������: %s  ", parseKey.c_str());
	//	return atoi(parseKey.c_str());
	//}

	string s = CCUserDefault::sharedUserDefault()->getStringForKey(pCharBuf);
	CCLOG("����ǰ������: %s  ", s.c_str());
	string parseKey = base64_decode(s);
	CCLOG("���ܺ������: %s  ", parseKey.c_str());
	return atoi(parseKey.c_str());
}

void FileSystem::setHighScore(int iKey, string sValue)
{
	char pCharBuf[1024 * 10];
	sprintf(pCharBuf, "%s:%d", "HighScore", iKey);
	CCLOG("----------�洢");
	CCLOG("�洢֮ǰHighScore��index: %d, value: %s  ", iKey, sValue.c_str());
	string sKey = base64_encode(reinterpret_cast<const unsigned char*>(sValue.c_str()), sValue.length());
	CCLOG("�洢���ܺ������ HighScore��index: %d, value: %s  ", iKey, sKey.c_str());
	CCUserDefault::sharedUserDefault()->setStringForKey(pCharBuf, sKey);
	CCUserDefault::sharedUserDefault()->flush();
}

int FileSystem::getLevel(int iKey)
{
	int level = 0;
	char pCharBuf[1024 * 10];
	sprintf(pCharBuf, "%s:%d", "Level", iKey);

	string s = CCUserDefault::sharedUserDefault()->getStringForKey(pCharBuf);
	string parseKey = base64_decode(s);
	return atoi(parseKey.c_str());
}

void FileSystem::setLevel(int iKey, string sValue)
{
	char pCharBuf[1024 * 10];
	sprintf(pCharBuf, "%s:%d", "Level", iKey);
	string sKey = base64_encode(reinterpret_cast<const unsigned char*>(sValue.c_str()), sValue.length());
	CCUserDefault::sharedUserDefault()->setStringForKey(pCharBuf, sKey);
	CCUserDefault::sharedUserDefault()->flush();
}

int FileSystem::getCoins(int iKey)
{
	char pCharBuf[1024 * 10];
	sprintf(pCharBuf, "%s:%d", "Coins", iKey);
	string s = CCUserDefault::sharedUserDefault()->getStringForKey(pCharBuf);
	string parseKey = base64_decode(s);
	return atoi(parseKey.c_str());
}

void FileSystem::setCoins(int iKey, string sValue)
{
	char pCharBuf[1024 * 10];
	sprintf(pCharBuf, "%s:%d", "Coins", iKey);
	string sKey = base64_encode(reinterpret_cast<const unsigned char*>(sValue.c_str()), sValue.length());
	CCUserDefault::sharedUserDefault()->setStringForKey(pCharBuf, sKey);
	CCUserDefault::sharedUserDefault()->flush();
}

int FileSystem::getIsScore(int iKey)
{
	char pCharBuf[1024 * 10];
	sprintf(pCharBuf, "isScore");
	string s = CCUserDefault::sharedUserDefault()->getStringForKey(pCharBuf);
	string parseKey = base64_decode(s);
	return atoi(parseKey.c_str());
}

void FileSystem::setIsScore(int iKey, string sValue)
{
	char pCharBuf[1024 * 10];
	sprintf(pCharBuf, "%s:%d", "isScore", iKey);
	string sKey = base64_encode(reinterpret_cast<const unsigned char*>(sValue.c_str()), sValue.length());
	CCUserDefault::sharedUserDefault()->setStringForKey(pCharBuf, sKey);
	CCUserDefault::sharedUserDefault()->flush();
}

