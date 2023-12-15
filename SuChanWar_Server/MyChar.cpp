#include "stdafx.h"
#include "MyChar.h"
#include "SuChanWar_ServerDlg.h"

MyChar::MyChar()
{
}


MyChar::~MyChar()
{
}


// 가장 가까운 적의 인덱스를 알아옴
int MyChar::GetNearestEnemy(int& nDistance)
{
	CSuChanWar_ServerDlg* pDlg = (CSuChanWar_ServerDlg*)m_pDlg;
	int nResult = 0;
	nDistance = RIGHT_END + 1;
	int nTempDisance;
	if (m_Team == Player1) {
		for (int i = 0; i < pDlg->arrCharP2.GetCount(); i++)
		{
			nTempDisance = GetDistance( pDlg->arrCharP2.GetAt(i) );
			if (nTempDisance < nDistance) {
				nResult = i;
				nDistance = nTempDisance;
			}
		}
	}
	else {
		for (int i = 0; i < pDlg->arrCharP1.GetCount(); i++)
		{
			nTempDisance = GetDistance(pDlg->arrCharP1.GetAt(i));
			if (nTempDisance < nDistance) {
				nResult = i;
				nDistance = nTempDisance;
			}
		}
	}
	return nResult;
}

_CharType MyChar::GetCharType()
{
	return m_CharType;
}


void MyChar::SetPos(int nPos)
{
	CSuChanWar_ServerDlg* pDlg = (CSuChanWar_ServerDlg*)m_pDlg;
	m_nPos = nPos;
	if (m_nPos >= RIGHT_FLEG)
		pDlg->GameState = PLAYER1_WIN;
	if (m_nPos <= LEFT_FLEG)
		pDlg->GameState = PLAYER2_WIN;
}

void MyChar::Move1Step()
{
	CSuChanWar_ServerDlg* pDlg = (CSuChanWar_ServerDlg*)m_pDlg;
	if (m_Team == Player1) {
		m_nPos += m_nSpeed;
		if (m_nPos >= RIGHT_FLEG)
			pDlg->GameState = PLAYER1_WIN;
	}
	else {
		m_nPos -= m_nSpeed;
		if (m_nPos <= LEFT_FLEG)
			pDlg->GameState = PLAYER2_WIN;
	}
}