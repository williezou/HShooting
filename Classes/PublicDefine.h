#ifndef _PUBLIC_DEFINE_H_
#define _PUBLIC_DEFINE_H_

#include "cocos2d.h"
USING_NS_CC;

#define _SCREEN_WIDTH_ CCDirector::sharedDirector()->getWinSize().width
#define _SCREEN_HEIGHT_ CCDirector::sharedDirector()->getWinSize().height

#define _NAME_LEN_				128		//�ַ�������
#define _GUN_KIND_COUNT_		5		//ǹ������
#define _SHUT_GUN_BULLET_COUNT_		5	//����ǹ�ӵ�����

enum
{
	enGunKindNormal,	//����ǹ(ֱ��)
	enGunKindShutGun,	//����ǹ(������Ļ)
	enGunKindMDGun,		//ɢ��ǹ(�෽����)
	enGunKindCross,		//ʮ��ǹ(��������4������)
	enGunKindXCroess,	//Xʮ��ǹ
};
enum
{
	enZOrderBack,
	enZOrderMiddle,
	enZOrderFront
};
enum
{
	enMsgBulletForCreate,			//�����ӵ�����Ϣ
	enMsgEnemyForCreate,			//������˵���Ϣ
	enMsgBulletForDisappear,		//�ӵ���ʧ����Ϣ
	enMsgEnemyForDisappear,			//������ʧ����Ϣ
	enMsgAddScore					//�ӷֵ���Ϣ
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
