#ifndef _DRAGONH
#define _DRAGONH

#pragma once

#include "MyChar.h"




class Dragon :
	public MyChar
{
public:
	Dragon(_Team Team, CDialog * pDlg);
	~Dragon();

	void Draw();
	void Attack(_Team team, int index);
	void Play1Turn();

private:
	int m_nProductionTime;//해골 생산할까요?(대기시간)
};

#endif