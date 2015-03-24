#ifndef __ENEMY_MANAGER_H__
#define __ENEMY_MANAGER_H__

#include "PublicDefine.h"
/************************************************************************/
/* 敌人管理类                                                           */
/************************************************************************/
class EnemyManager : public Sender, public CCObject
{
protected:
	CCTexture2D* m_pTexture;			//图片纹理
	float		 m_fSpeed;				//移动速度

	int			 m_nHp;					//血量
	int			 m_nScore;				//分数
	int			 m_nCD;					//CD计数器
	int			 m_nCDTime;				//CD时间
public:
	static EnemyManager* CreateEnemyManager(CCTexture2D* pTexture, float fSpeed, int nCD, int nScore, int nHp, Receiver* pReceiver);
	void  EnemyManagerLoop();
protected:
	bool Init(CCTexture2D* pTexture, float fSpeed, int nCD, int nScore, int nHp, Receiver* pReceiver);

	bool IsCreate();
	void Create();
};
#endif //__ENEMY_MANAGER_H__

