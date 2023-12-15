#include "stdafx.h"
#include "Archer.h"

#include "SuChanWar_ServerDlg.h"

Archer::Archer(_Team Team, CDialog * pDlg)
{
	m_nHp = 80;
	m_nRange = 200;
	m_nPower = 4;
	if (Team == Player1) m_nPos = 0;
	else m_nPos = RIGHT_END;
	m_nSpeed = 20;
	m_CharType = ARCHER;
	m_Team = Team;
	m_State = MOVE1;
	m_pDlg = pDlg;
}


Archer::~Archer()
{
}

void Archer::Draw()
{
	CString msg;
	msg.Format(_T("Archer ��ġ=%4d ü��=%3d �׸�= %d ��=%d"), m_nPos, m_nHp, m_State, m_Team);

	CSuChanWar_ServerDlg* pDlg = (CSuChanWar_ServerDlg*)m_pDlg;
	pDlg->m_ListOut.AddString(msg);
}


// �Ű������� ü���� ���� ���� �迭�󿡼��� index
//��� ������ ü���� 0 �����̸� �� ĳ���� ����
void Archer::Attack(_Team team, int index)
{
	CSuChanWar_ServerDlg* pDlg = (CSuChanWar_ServerDlg*)m_pDlg;
	if (team == Player1) {
		pDlg->arrCharP1.GetAt(index)->SetHp(pDlg->arrCharP1.GetAt(index)->GetHp() - m_nPower);
		if (rand() % 3 == 0) pDlg->arrCharP1.GetAt(index)->SetPos(pDlg->arrCharP1.GetAt(index)->GetPos() - 1);// 1/3 Ȯ���� ������� 1 �о
		if (pDlg->arrCharP1.GetAt(index)->GetHp() <= 0) pDlg->DeleteOneChar(Player1, index);
	}
	else {
		pDlg->arrCharP2.GetAt(index)->SetHp(pDlg->arrCharP2.GetAt(index)->GetHp() - m_nPower);
		if (rand() % 3 == 0) pDlg->arrCharP2.GetAt(index)->SetPos(pDlg->arrCharP2.GetAt(index)->GetPos() + 1);// 1/3 Ȯ���� ������� 1 �о
		if (pDlg->arrCharP2.GetAt(index)->GetHp() <= 0) pDlg->DeleteOneChar(Player2, index);
	}
}

// Ÿ�̸ӿ� ���� ȣ��
// ���� ����� ��� ���� ã��
// �����Ÿ� �ȿ� ������ ���� �ƴϸ� �̵��Ѵ�
// �̵� �Ÿ����� ������ ������ �ٷ� �ձ����� �̵��Ѵ�
void Archer::Play1Turn()
{
	CSuChanWar_ServerDlg* pdlg = (CSuChanWar_ServerDlg*)m_pDlg;
	int nIndex;
	int nDist;
	nIndex = GetNearestEnemy(nDist);

	if (m_Team == Player1) {
		if (m_nRange >= nDist) {
			if (m_State == ATTACK2) m_State = ATTACK1;
			else m_State = ATTACK2;
			Attack(Player2, nIndex);//���� ���� ĳ������ ���� �ε���
		}
		else {
			if (m_State == MOVE2) m_State = MOVE1;
			else m_State = MOVE2;
			if (nDist > m_nSpeed) {
				Move1Step();
			}
			else {
				SetPos(m_nPos + nDist - SHORTEST_DISTANCE);
			}
		}
	}
	else {
		if (m_nRange >= nDist) {
			if (m_State == ATTACK2) m_State = ATTACK1;
			else m_State = ATTACK2;
			Attack(Player1, nIndex);
		}
		else {
			if (m_State == MOVE2) m_State = MOVE1;
			else m_State = MOVE2;
			if (nDist > m_nSpeed) {
				Move1Step();
			}
			else {
				SetPos(m_nPos - nDist + SHORTEST_DISTANCE);
			}
		}
	}


}
