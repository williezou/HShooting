#ifndef _PUBLIC_DEFINE_H_
#define _PUBLIC_DEFINE_H_

#include "cocos2d.h"
USING_NS_CC;

#define _SCREEN_WIDTH_ CCDirector::sharedDirector()->getWinSize().width
#define _SCREEN_HEIGHT_ CCDirector::sharedDirector()->getWinSize().height

#define _NAME_LEN_				128		//字符串长度
#define _GUN_KIND_COUNT_		5		//枪的种类
#define _SHUT_GUN_BULLET_COUNT_		5	//多重枪子弹个数

enum
{
	enGunKindNormal,	//基本枪(直射)
	enGunKindShutGun,	//多重枪(单方向弹幕)
	enGunKindMDGun,		//散射枪(多方向单射)
	enGunKindCross,		//十字枪(上下左右4个方向)
	enGunKindXCroess,	//X十字枪
};
enum
{
	enZOrderBack,
	enZOrderMiddle,
	enZOrderFront
};
enum
{
	enMsgBulletForCreate,			//创造子弹的消息
	enMsgEnemyForCreate,			//创造敌人的消息
	enMsgBulletForDisappear,		//子弹消失的消息
	enMsgEnemyForDisappear,			//敌人消失的消息
	enMsgAddScore					//加分的消息
};

class Receiver
{
public:
	virtual void OnMsgReceive(int enMsg, void* pData, int nSize) = 0;
};

class Sender
{
protected:
	Receiver* m_pReceiver;

public:
	void SetReceiver(Receiver* pReceiver)
	{
		m_pReceiver = pReceiver;
	}
	void SendMsg(int enMsg, void* pData, int nSize)
	{
		m_pReceiver->OnMsgReceive(enMsg, pData, nSize);
	}

};

struct BulletForCreateMsg
{
	CCPoint ptBulletStartPoint;
	CCPoint ptBulletEndPoint;
	bool IsShutGun;
	int nBulletDamage;
};

class Bullet;
struct BulletForDisappearMsg
{
	Bullet* pSelf;
};

class Enemy;
struct EnemyForDisappearMsg
{
	Enemy* pSelf;
};

struct  EnemyForCreateMsg
{
	CCTexture2D* pTexture;
	float fSpeed;
	CCPoint pStartPoint;
	int nScore;
	int nHp;
};

struct AddScoreMsg
{
	int nScore;
};

class VisibleRect
{
public:
	inline static CCRect getVisibleRect()
	{
		lazyInit();
		return CCRectMake(s_visibleRect.origin.x, s_visibleRect.origin.y, s_visibleRect.size.width, s_visibleRect.size.height);
	}

	inline static CCPoint left()
	{
		lazyInit();
		return ccp(s_visibleRect.origin.x, s_visibleRect.origin.y + s_visibleRect.size.height / 2);
	}

	inline static CCPoint right()
	{
		lazyInit();
		return ccp(s_visibleRect.origin.x + s_visibleRect.size.width, s_visibleRect.origin.y + s_visibleRect.size.height / 2);
	}

private:
	inline static void lazyInit()
	{
		if (s_visibleRect.size.width == 0.0f && s_visibleRect.size.height == 0.0f)
		{
			CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
			s_visibleRect.origin = pEGLView->getVisibleOrigin();
			s_visibleRect.size = pEGLView->getVisibleSize();
		}
	}

	static CCRect s_visibleRect;

};

#endif //_PUBLIC_DEFINE_H_
