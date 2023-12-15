#include "stdafx.h"
#include "skeleton.h"

#include "SuChanWar_ServerDlg.h"



//�Ű������� ������� ��, ��ȭ����, �������� ����ġ�� ������ ��ġ�� �� �Դϴ�
Skeleton::Skeleton(_Team Team, CDialog * pDlg, int nPos)
{
	m_nHp = 15;
	m_nRange = 5;
	m_nPower = 3;
	if (Team == Player1) m_nPos = nPos;
	else m_nPos = RIGHT_END - nPos;
	m_nSpeed = 25;
	m_CharType = SKELETON;
	m_Team = Team;
	m_State = MOVE1;
	m_pDlg = pDlg;
}


Skeleton::~Skeleton()
{
}

void Skeleton::Draw()
{
	CString msg;
	msg.Format(_T("Skeleton ��ġ=%4d ü��=%3d �׸�= %d ��=%d"), m_nPos, m_nHp, m_State, m_Team);

	CSuChanWar_ServerDlg* pDlg = (CSuChanWar_ServerDlg*)m_pDlg;
	pDlg->m_ListOut.AddString(msg);
}


// �Ű������� ü���� ���� ���� �迭�󿡼��� index
//��� ������ ü���� 0 �����̸� �� ĳ���� ����
void Skeleton::Attack(_Team team, int index)
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
// ���� ����� ��� ���� ã��
// �����Ÿ� �ȿ� ������ ���� �ƴϸ� �̵��Ѵ�
// �̵� �Ÿ����� ������ ������ �ٷ� �ձ����� �̵��Ѵ�
void Skeleton::Play1Turn()
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




