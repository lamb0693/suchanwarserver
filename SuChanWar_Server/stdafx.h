
// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������ 
// ��� �ִ� ���� �����Դϴ�.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // �Ϻ� CString �����ڴ� ��������� ����˴ϴ�.

// MFC�� ���� �κа� ���� ������ ��� �޽����� ���� ����⸦ �����մϴ�.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC �ٽ� �� ǥ�� ���� ����Դϴ�.
#include <afxext.h>         // MFC Ȯ���Դϴ�.





#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 ���� ��Ʈ�ѿ� ���� MFC �����Դϴ�.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Windows ���� ��Ʈ�ѿ� ���� MFC �����Դϴ�.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC�� ���� �� ��Ʈ�� ���� ����


#include <afxsock.h>            // MFC ���� Ȯ��

#define SM_RECEIVE_BTN_CLICK WM_USER+5

#define TIME_INTERVAL 200


typedef enum __Chartype { WARRIOR, ARCHER, WIZARD, GOLEM, DRAGON, SKELETON }_CharType;
typedef enum __Team { Player1, Player2 }_Team;
typedef enum __State { MOVE1, MOVE2, ATTACK1, ATTACK2 }_State;
typedef enum __gState { BEFORE_START, ONGAME, PLAYER1_WIN, PLAYER2_WIN, GAME_PAUSE } gState;
typedef enum __MESSAGE_TYPE { INFORM_TEAM, GAME_DATA , BTN_CLICK, GAMEEND} _MESSAGE_TYPE;







