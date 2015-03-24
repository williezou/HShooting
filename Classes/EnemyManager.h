#ifndef __ENEMY_MANAGER_H__
#define __ENEMY_MANAGER_H__

#include "PublicDefine.h"
/************************************************************************/
/* ���˹�����                                                           */
/************************************************************************/
class EnemyManager : public Sender, public CCObject
{
protected:
	CCTexture2D* m_pTexture;			//ͼƬ����
	float		 m_fSpeed;				//�ƶ��ٶ�

	int			 m_nHp;					//Ѫ��
	int			 m_nScore;				//����
	int			 m_nCD;					//CD������
	int			 m_nCDTime;				//CDʱ��
public:
	static EnemyManager* CreateEnemyManager(CCTexture2D* pTexture, float fSpeed, int nCD, int nScore, int nHp, Receiver* pReceiver);
	void  EnemyManagerLoop();
protected:
	bool Init(CCTexture2D* pTexture, float fSpeed, int nCD, int nScore, int nHp, Receiver* pReceiver);

	bool IsCreate();
	void Create();
};
#endif //__ENEMY_MANAGER_H__

