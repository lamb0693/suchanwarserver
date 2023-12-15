#pragma once
#include "afxsock.h"
#include "ConnectSocket.h"

class CListenSocket :
	public CAsyncSocket
{
public:
	CListenSocket(CDialog* pDlg);
	~CListenSocket();

	CDialog* m_pDlg;
	CConnectSocket* pPlyaer1Socket = NULL;
	CConnectSocket* pPlayer2Socket = NULL;

	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	void CloseConnectSocket(CSocket* pClient);
	void SendDataPlayer1(unsigned char *  szMessage);
	void SendDataPlayer2(unsigned char *  szMessage);
};

