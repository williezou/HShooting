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
	CCLog("----------读取");
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
	//	CCLog("解密前的数据: %s  ", s.c_str());
	//	string parseKey = base64_decode(s);
	//	CCLog("解密后的数据: %s  ", parseKey.c_str());
	//	return atoi(parseKey.c_str());
	//}

	string s = CCUserDefault::sharedUserDefault()->getStringForKey(pCharBuf);
	CCLOG("解密前的数据: %s  ", s.c_str());
	string parseKey = base64_decode(s);
	CCLOG("解密后的数据: %s  ", parseKey.c_str());
	return atoi(parseKey.c_str());
}

void FileSystem::setHighScore(int iKey, string sValue)
{
	char pCharBuf[1024 * 10];
	sprintf(pCharBuf, "%s:%d", "HighScore", iKey);
	CCLOG("----------存储");
	CCLOG("存储之前HighScore：index: %d, value: %s  ", iKey, sValue.c_str());
	string sKey = base64_encode(reinterpret_cast<const unsigned char*>(sValue.c_str()), sValue.length());
	CCLOG("存储加密后的数据 HighScore：index: %d, value: %s  ", iKey, sKey.c_str());
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

