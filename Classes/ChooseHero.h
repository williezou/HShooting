#ifndef _CHOOSE_HERO_H_
#define _CHOOSE_HERO_H_

#include "PublicDefine.h"
/************************************************************************/
/* Hero选择层                                                           */
/************************************************************************/
class ChooseHero : public CCLayer
{
protected:
	int			m_nSelectHeroKind;		//当前选中的英雄类型
	bool		m_bIsClickLeft;		//点击屏幕左侧（false为点击屏幕右侧）
public:
	static CCScene* CreateScene();
protected:
	CREATE_FUNC(ChooseHero);
	bool init();

	//触摸回调
	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	//键盘返回回调（应添加菜单）
	virtual void  keyBackClicked();
	enum
	{
		enZOrderHomeBtn,
		enZOrderPauseBtn,
		enZOrderAudioBtn,
		enZOrderMissileBtn,
	};

	enum
	{
		enTagPlayer,
		enTagBackGround,

	};

};

#endif //_CHOOSE_HERO_H_

