#include "FileSystem.h"
#include <iostream>

FileSystem::FileSystem()
{
}

FileSystem::~FileSystem()
{
}

int FileSystem::getHighScore()
{
	int score = 0;
	char* pCharBuf = NULL;
	sprintf(pCharBuf, "HighScore:%d");
	if (!CCUserDefault::sharedUserDefault()->getIntegerForKey(pCharBuf))
	{
		CCUserDefault::sharedUserDefault()->setIntegerForKey(pCharBuf, 0);
	}
	else
	{
		score = CCUserDefault::sharedUserDefault()->getIntegerForKey(pCharBuf);
	}
	return score;
}

void FileSystem::setHighScore(int i)
{
	char* pCharBuf = NULL;
	sprintf(pCharBuf, "HighScore:%d");
	CCUserDefault::sharedUserDefault()->setIntegerForKey(pCharBuf, i);
	CCUserDefault::sharedUserDefault()->flush();
}

int FileSystem::getLevel()
{
	int level = 0;
	char* pCharBuf = NULL;
	sprintf(pCharBuf, "Level:%d");
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

void FileSystem::setLevel(int i)
{
	char* pCharBuf = NULL;
	sprintf(pCharBuf, "Level:%d");
	CCUserDefault::sharedUserDefault()->setIntegerForKey(pCharBuf, i);
	CCUserDefault::sharedUserDefault()->flush();
}

int FileSystem::getCoins()
{
	int coins = 0;
	char* pCharBuf = NULL;
	sprintf(pCharBuf, "Level:%d");
	if (!CCUserDefault::sharedUserDefault()->getIntegerForKey(pCharBuf))
	{
		CCUserDefault::sharedUserDefault()->setIntegerForKey(pCharBuf, 0);
	}
	else
	{
		coins = CCUserDefault::sharedUserDefault()->getIntegerForKey(pCharBuf);
	}
	return coins;
}

void FileSystem::setCoins(int i)
{
	char* pCharBuf = NULL;
	sprintf(pCharBuf, "Coins:%d");
	CCUserDefault::sharedUserDefault()->setIntegerForKey(pCharBuf, i);
	CCUserDefault::sharedUserDefault()->flush();
}

int FileSystem::getIsScore()
{
	int score = 0;

	char* pCharBuf = NULL;
	sprintf(pCharBuf, "isScore");
	if (!CCUserDefault::sharedUserDefault()->getIntegerForKey(pCharBuf))
	{
		CCUserDefault::sharedUserDefault()->setIntegerForKey(pCharBuf, 0);
	}
	else
	{
		score = CCUserDefault::sharedUserDefault()->getIntegerForKey(pCharBuf);
	}
	return score;
}

void FileSystem::setIsScore(int i)
{
	char* pCharBuf = NULL;
	sprintf(pCharBuf, "isScore");
	CCUserDefault::sharedUserDefault()->setIntegerForKey(pCharBuf, i);
	CCUserDefault::sharedUserDefault()->flush();
}

