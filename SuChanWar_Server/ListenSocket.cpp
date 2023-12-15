#include "stdafx.h"
#include "ListenSocket.h"


#include "SuChanWar_ServerDlg.h"

CListenSocket::CListenSocket(CDialog* pDlg)
{
	m_pDlg = pDlg;
}


CListenSocket::~CListenSocket()
{
}


void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CSuChanWar_ServerDlg* pDlg = (CSuChanWar_ServerDlg*)m_pDlg;

	if (pPlyaer1Socket == NULL) {
		pPlyaer1Socket = new CConnectSocket;
		if (Accept(*pPlyaer1Socket)) {
			pPlyaer1Socket->SetListenSocket(this);
			pPlyaer1Socket->SetTeam(1);
		}
		else {
			delete pPlyaer1Socket;
			AfxMessageBox(_T("Player1 ���� ����"));
		}
//		AfxMessageBox(_T("Player 1 �����߳���"));
		pDlg->m_szSend[0] = INFORM_TEAM;  // message ���� 1 �� �̸� �˷��ֱ�
		pDlg->m_szSend[1] = 1;  // ��1�̴�
		SendDataPlayer1(pDlg->m_szSend);
	}
	else {
		if (pPlayer2Socket == NULL) {
			pPlayer2Socket = new CConnectSocket;
			if (Accept(*pPlayer2Socket)) {
				pPlayer2Socket->SetListenSocket(this);
				pPlayer2Socket->SetTeam(2);
			}
			else {
				delete pPlayer2Socket;
				AfxMessageBox(_T("Player2 ���� ����"));
			}
//			AfxMessageBox(_T("Player 2 �����߳���"));
			pDlg->m_szSend[0] = INFORM_TEAM;  // message ���� 1 �� �̸� �˷��ֱ�
			pDlg->m_szSend[1] = 2;  // ��2�̴�
			SendDataPlayer2(pDlg->m_szSend);
		}
		// �Ѵ� null�� �ƴϸ� ���� �ȵ�
	}

	CAsyncSocket::OnAccept(nErrorCode);
}


void CListenSocket::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	CAsyncSocket::OnClose(nErrorCode);
}


void CListenSocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	CAsyncSocket::OnReceive(nErrorCode);
}


void CListenSocket::CloseConnectSocket(CSocket* pClient)
{
	if (pClient == pPlyaer1Socket) {
		pPlyaer1Socket->ShutDown();
		pPlyaer1Socket->Close();
		delete pPlyaer1Socket;
		pPlyaer1Socket = NULL;
	}
	if (pClient == pPlayer2Socket) {
		pPlayer2Socket->ShutDown();
		pPlayer2Socket->Close();
		delete  pPlayer2Socket;
		pPlayer2Socket = NULL;
	}

}


void CListenSocket::SendDataPlayer1(unsigned char *  szMessage)
{
/*
	TCHAR* pszMessage;
	pszMessage = (TCHAR*) strMessage.GetBuffer();

	pPlyaer1Socket->Send(pszMessage, lstrlen(pszMessage) * 2);
*/
	if (pPlyaer1Socket == NULL) return;
	pPlyaer1Socket->Send(szMessage, 1024);
}


void CListenSocket::SendDataPlayer2(unsigned char *  szMessage)
{
/*
	TCHAR* pszMessage;
	pszMessage = (TCHAR*)strMessage.GetBuffer();
	pPlayer2Socket->Send(pszMessage, lstrlen(pszMessage) * 2);
*/
	if (pPlayer2Socket == NULL) return;
	pPlayer2Socket->Send(szMessage, 1024);
}
