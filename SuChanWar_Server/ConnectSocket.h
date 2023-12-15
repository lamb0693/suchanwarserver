#pragma once
#include "afxsock.h"

class CConnectSocket :
	public CSocket
{
public:
	CConnectSocket();
	~CConnectSocket();

	CAsyncSocket* m_pListenSocket;

	void SetListenSocket(CAsyncSocket* pSocket);

private:
	int m_team;
public:
	void SetTeam(int nTeam);
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};

