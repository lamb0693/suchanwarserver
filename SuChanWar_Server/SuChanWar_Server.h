
// SuChanWar_Server.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSuChanWar_ServerApp:
// �� Ŭ������ ������ ���ؼ��� SuChanWar_Server.cpp�� �����Ͻʽÿ�.
//

class CSuChanWar_ServerApp : public CWinApp
{
public:
	CSuChanWar_ServerApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSuChanWar_ServerApp theApp;