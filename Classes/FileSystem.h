#ifndef __FILE_SYSTEM_H__
#define __FILE_SYSTEM_H__

#include "cocos2d.h"
#include "PublicDefine.h"
USING_NS_CC;

class FileSystem
{
public:
	FileSystem();
	~FileSystem();

	static int getHighScore();
	static void setHighScore(int i);

	static int getLevel();
	static void setLevel(int i);

	static int getCoins();
	static void setCoins(int i);

	static int getIsScore();
	static void setIsScore(int i);

private:

};


#endif //__FILE_SYSTEM_H__

