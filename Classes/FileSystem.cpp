#include "FileSystem.h"
#include <iostream>

FileSystem::FileSystem()
{
}

FileSystem::~FileSystem()
{
}

int FileSystem::getHighScore(int type)
{
	int score = 0;
	CCString* pStrBuf = NULL;
	pStrBuf = CCString::createWithFormat("highScore:%d", type);
	if (!CCUserDefault::sharedUserDefault()->getIntegerForKey((char*)pStrBuf))
	{
		CCUserDefault::sharedUserDefault()->setIntegerForKey((char*)pStrBuf, 0);
	}
	else
	{
		score = CCUserDefault::sharedUserDefault()->getIntegerForKey((char*)pStrBuf);
	}
	return score;
}

void FileSystem::setHighScore(int type, int i)
{
	CCString* pStrBuf = NULL;
	pStrBuf = CCString::createWithFormat("highScore:%d", type);
	CCUserDefault::sharedUserDefault()->setIntegerForKey((char*)pStrBuf, i);
}

int FileSystem::getLevel(int type)
{
	int level = 0;
	char* pCharBuf = NULL;
	sprintf(pCharBuf, "highScore:%d", type);
	if (!CCUserDefault::sharedUserDefault()->getIntegerForKey(pCharBuf))
	{
		CCUserDefault::sharedUserDefault()->setIntegerForKey(pCharBuf, 0);
	}
	else
	{
		level = CCUserDefault::sharedUserDefault()->getIntegerForKey(pCharBuf);
	}
	return level;
}

void FileSystem::setLevel(int type)
{

}

int FileSystem::getCoins()
{
	return 0;
}

void FileSystem::setCoins(int i)
{

}

int FileSystem::getIsScore()
{
	return 0;
}

void FileSystem::setIsScore()
{

}

