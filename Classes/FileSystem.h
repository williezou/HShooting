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

	static int getHighScore(int type);
	static void setHighScore(int type, int i);

	static int getLevel(int type);
	static void setLevel(int type);

	static int getCoins();
	static void setCoins(int i);

	static int getIsScore();
	static void setIsScore();

private:

};


#endif //__FILE_SYSTEM_H__

