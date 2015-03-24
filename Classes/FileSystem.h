#ifndef __FILE_SYSTEM_H__
#define __FILE_SYSTEM_H__

#include "cocos2d.h"
#include "PublicDefine.h"

using namespace std;
USING_NS_CC;

enum
{
	DATA_HIGHSCORE,		//��߷�
	DATA_LEVEL,			//�ȼ�
	DATA_COINS,			//���
	DATA_ISSCORE,		//��ǰ����
};

class FileSystem
{
public:
	FileSystem();
	~FileSystem();

	static int getHighScore(int iKey);
	static void setHighScore(int iKey, string sValue);

	static int getLevel(int iKey);
	static void setLevel(int iKey, string sValue);

	static int getCoins(int iKey);
	static void setCoins(int iKey, string sValue);

	static int getIsScore(int iKey);
	static void setIsScore(int iKey, string sValue);

};


#endif //__FILE_SYSTEM_H__

