#ifndef _SKELETONH
#define _SKELETONH

#pragma once

#include "MyChar.h"




class Skeleton :
	public MyChar
{
public:
	//매개변수는 순서대로 팀, 대화상자, 팀에따른 끝위치와 생산할 위치의 차 입니다
	Skeleton(_Team Team, CDialog * pDlg, int nPos);
	~Skeleton();

	void Draw();
	void Attack(_Team team, int index);
	void Play1Turn();
};

#endif