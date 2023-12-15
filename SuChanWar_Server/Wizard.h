#ifndef _WIZARDH
#define _WIZARDH

#pragma once

#include "MyChar.h"




class Wizard :
	public MyChar
{
public:
	Wizard(_Team Team, CDialog* pDlg);
	~Wizard();

	void Draw();
	void Attack(_Team team, int index);
	void Play1Turn();
};

#endif