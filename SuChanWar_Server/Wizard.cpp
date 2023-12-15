#include "stdafx.h"
#include "Wizard.h"

#include "SuChanWar_ServerDlg.h"



Wizard::Wizard(_Team Team, CDialog* pDlg)
{
	m_nHp = 130;
	m_nRange = 40;
	m_nPower = 4;
	if (Team == Player1) m_nPos = 0;
	else m_nPos = RIGHT_END;
	m_nSpeed = 20;
	m_CharType = WIZARD;
	m_Team = Team;
	m_State = MOVE1;
	m_pDlg = pDlg;
}

Wizard::~Wizard()
{
}

void Wizard::Draw()
{
	CString msg;
	msg.Format(_T("Wizard ��ġ=%4d ü��=%3d �׸�= %d ��=%d"), m_nPos, m_nHp, m_State, m_Team);

	CSuChanWar_ServerDlg* pDlg = (CSuChanWar_ServerDlg*)m_pDlg;
	pDlg->m_ListOut.AddString(msg);
}


// �Ű������� ü���� ���� ���� �迭�󿡼��� index
//��� ������ ü���� 0 �����̸� �� ĳ���� ����
void Wizard::Attack(_Team team, int index)
{
	CSuChanWar_ServerDlg* pDlg = (CSuChanWar_ServerDlg*)m_pDlg;
	if (team == Player1) {
		pDlg->arrCharP1.GetAt(index)->SetHp(pDlg->arrCharP1.GetAt(index)->GetHp() - m_nPower);
		if (pDlg->arrCharP1.GetAt(index)->GetHp() <= 0) pDlg->DeleteOneChar(Player1, index);
	}
	else {
		pDlg->arrCharP2.GetAt(index)->SetHp(pDlg->arrCharP2.GetAt(index)->GetHp() - m_nPower);
		if (pDlg->arrCharP2.GetAt(index)->GetHp() <= 0) pDlg->DeleteOneChar(Player2, index);
	}
}

// Ÿ�̸ӿ� ���� ȣ��
// ��� ���� ã��
// �����Ÿ� �ȿ� ������ ����
// �ѹ��� �������� �ʾ����� �̵��Ѵ�
// �̵� �Ÿ����� ������ ������ �ٷ� �ձ����� �̵��Ѵ�
void Wizard::Play1Turn()
{
	CSuChanWar_ServerDlg* pDlg = (CSuChanWar_ServerDlg*)m_pDlg;
	int nDist = RIGHT_END + 1;
	int nTempDist;
	bool bAttacked = false; //�ѹ��̶� ���� �ߴ°�?

	if (m_Team == Player1) {
		for (int i = 0; i < pDlg->arrCharP2.GetCount(); i++)
		{
			nTempDist = GetDistance(pDlg->arrCharP2.GetAt(i));
			if ( m_nRange >= nTempDist ) {
				Attack(Player2, i);
				bAttacked = true;
			}
			if (nTempDist < nDist) {
				nDist = nTempDist;
			}
		}
	}
	else {
		for (int i = 0; i < pDlg->arrCharP1.GetCount(); i++)
		{
			if ( m_nRange >= GetDistance(pDlg->arrCharP1.GetAt(i)) ) {
				Attack(Player1, i);
				bAttacked = true;
			}
		}
	}
	if (bAttacked) {
		if (m_State == ATTACK2) m_State = ATTACK1;
		else m_State = ATTACK2;
	}
	else {
		if (m_State == MOVE2) m_State = MOVE1;
		else m_State = MOVE2;

		if (nDist > m_nSpeed) {
			Move1Step();
		}
		else {
			if (m_Team == Player1) {
				SetPos(m_nPos + nDist - SHORTEST_DISTANCE);
			}
			else {
				SetPos(m_nPos - nDist + SHORTEST_DISTANCE);
			}
		}
	}

}
