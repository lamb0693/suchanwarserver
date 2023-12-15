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
	int m_nProductionTime;//�ذ� �����ұ��?(���ð�)
};

#endif