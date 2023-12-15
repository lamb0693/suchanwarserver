#ifndef _SKELETONH
#define _SKELETONH

#pragma once

#include "MyChar.h"




class Skeleton :
	public MyChar
{
public:
	//�Ű������� ������� ��, ��ȭ����, �������� ����ġ�� ������ ��ġ�� �� �Դϴ�
	Skeleton(_Team Team, CDialog * pDlg, int nPos);
	~Skeleton();

	void Draw();
	void Attack(_Team team, int index);
	void Play1Turn();
};

#endif