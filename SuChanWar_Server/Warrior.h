#ifndef _WARRIORH
#define _WARRIORH

#pragma once

#include "MyChar.h"




class Warrior :
	public MyChar
{
public:
	Warrior(_Team Team, CDialog* pDlg);
	~Warrior();

	void Draw();
	void Attack(_Team team, int index);
	void Play1Turn();
};

#endif
