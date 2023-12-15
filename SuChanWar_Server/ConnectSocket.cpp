#include "stdafx.h"
#include "ConnectSocket.h"
#include "ListenSocket.h"
#include "SuChanWar_ServerDlg.h"


CConnectSocket::CConnectSocket()
{
}


CConnectSocket::~CConnectSocket()
{
}


void CConnectSocket::SetListenSocket(CAsyncSocket* pSocket)
{
	m_pListenSocket = pSocket;
}


void CConnectSocket::SetTeam(int nTeam)
{
	m_team = nTeam;
}


void CConnectSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CListenSocket* pServerSocket = (CListenSocket*) m_pListenSocket;
	pServerSocket->CloseConnectSocket(this);

	CSocket::OnClose(nErrorCode);
}


void CConnectSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
/*
	CString strTmp = _T("");

	TCHAR szBuffer[1024];
	::ZeroMemory(szBuffer, sizeof(szBuffer));

	if (Receive(szBuffer, sizeof(szBuffer)) > 0) {
		strTmp.Format(_T("%s") , szBuffer);
	}
*/

	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	CSuChanWar_ServerDlg* pDlg = (CSuChanWar_ServerDlg*) pServerSocket->m_pDlg;

	if (Receive(pDlg->m_szReceive, 1024) > 0) {
		pDlg->SendMessageW(SM_RECEIVE_BTN_CLICK);
	}

	CSocket::OnReceive(nErrorCode);
}
