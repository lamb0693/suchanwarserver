#ifndef _ARCHERH
#define _ARCHERH

#pragma once

#include "MyChar.h"




class Archer :
	public MyChar
{
public:
	Archer(_Team Team, CDialog * pDlg);
	~Archer();

	void Draw();
	void Attack(_Team team, int index);
	void Play1Turn();
};

#endif