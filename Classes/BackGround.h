#ifndef __BACK_GROUND_H__
#define __BACK_GROUND_H__

#include "PublicDefine.h"

/************************************************************************/
/* 滚动背景类:实现了背景的滚动											*/
/* 为滚动的背景设立单独类的意义:											*/
/* 这样设计是为了以后拓展背景的丰富程度									*/
/************************************************************************/

class BackGroundNode : public CCNode
{
protected:
	float m_fSpeed;				//滚屏的速度
	float m_fDisplacement;		//滚屏的位移（为了判定复位）

public:
	static BackGroundNode* CreateBackGround(const char* pFileName);
protected:
	bool Init(const char* pFileName);
	//循环背景
	void BackGroundLoop(float ft);
	//判断是否滚屏（预留这个接口，为以后拓展功能）
	bool IsMove();
	//滚屏
	void Move();
	//判断是否需要重置(对于这个工程来说，[重置]就是将背景图复位到原点)
	bool IsReset();
	//[重置]:将背景图复位到原点
	void Reset();

protected:
	enum
	{
		enTagBack1,
		enTagBack2
	};
};

#endif //__BACK_GROUND_H__

