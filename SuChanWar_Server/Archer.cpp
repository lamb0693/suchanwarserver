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
	msg.Format(_T("Archer 위치=%4d 체력=%3d 그림= %d 팀=%d"), m_nPos, m_nHp, m_State, m_Team);

	CSuChanWar_ServerDlg* pDlg = (CSuChanWar_ServerDlg*)m_pDlg;
	pDlg->m_ListOut.AddString(msg);
}


// 매개변수는 체력을 깍을 팀과 배열상에서의 index
//결과 상대방의 체력이 0 이하이면 그 캐릭터 삭제
void Archer::Attack(_Team team, int index)
{
	CSuChanWar_ServerDlg* pDlg = (CSuChanWar_ServerDlg*)m_pDlg;
	if (team == Player1) {
		pDlg->arrCharP1.GetAt(index)->SetHp(pDlg->arrCharP1.GetAt(index)->GetHp() - m_nPower);
		if (rand() % 3 == 0) pDlg->arrCharP1.GetAt(index)->SetPos(pDlg->arrCharP1.GetAt(index)->GetPos() - 1);// 1/3 확률로 상대방방을 1 밀어냄
		if (pDlg->arrCharP1.GetAt(index)->GetHp() <= 0) pDlg->DeleteOneChar(Player1, index);
	}
	else {
		pDlg->arrCharP2.GetAt(index)->SetHp(pDlg->arrCharP2.GetAt(index)->GetHp() - m_nPower);
		if (rand() % 3 == 0) pDlg->arrCharP2.GetAt(index)->SetPos(pDlg->arrCharP2.GetAt(index)->GetPos() + 1);// 1/3 확률로 상대방방을 1 밀어냄
		if (pDlg->arrCharP2.GetAt(index)->GetHp() <= 0) pDlg->DeleteOneChar(Player2, index);
	}
}

// 타이머에 의해 호출
// 가장 가까운 상대 편을 찾고
// 사정거리 안에 있으면 공격 아니면 이동한다
// 이동 거리보다 가까이 있으면 바로 앞까지만 이동한다
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
			Attack(Player2, nIndex);//공격 당할 캐릭터의 팀과 인덱스
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
