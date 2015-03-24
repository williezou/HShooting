#ifndef __BACK_GROUND_H__
#define __BACK_GROUND_H__

#include "PublicDefine.h"

/************************************************************************/
/* ����������:ʵ���˱����Ĺ���											*/
/* Ϊ�����ı������������������:											*/
/* ���������Ϊ���Ժ���չ�����ķḻ�̶�									*/
/************************************************************************/

class BackGroundNode : public CCNode
{
protected:
	float m_fSpeed;				//�������ٶ�
	float m_fDisplacement;		//������λ�ƣ�Ϊ���ж���λ��

public:
	static BackGroundNode* CreateBackGround(const char* pFileName);
protected:
	bool Init(const char* pFileName);
	//ѭ������
	void BackGroundLoop(float ft);
	//�ж��Ƿ������Ԥ������ӿڣ�Ϊ�Ժ���չ���ܣ�
	bool IsMove();
	//����
	void Move();
	//�ж��Ƿ���Ҫ����(�������������˵��[����]���ǽ�����ͼ��λ��ԭ��)
	bool IsReset();
	//[����]:������ͼ��λ��ԭ��
	void Reset();

protected:
	enum
	{
		enTagBack1,
		enTagBack2
	};
};

#endif //__BACK_GROUND_H__

