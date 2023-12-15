#ifndef _GOLEMH
#define _GOLEMH

#pragma once

#include "MyChar.h"



class Golem :
public MyChar
{
public:
	Golem(_Team Team, CDialog * pDlg);
	~Golem();

	void Draw();
	void Attack(_Team team, int index);
	void Play1Turn();
};

#endif