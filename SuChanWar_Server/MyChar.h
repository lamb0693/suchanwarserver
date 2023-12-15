#ifndef _MyCharH
#define _MyCharH

#pragma once

#define RIGHT_END 1600
#define LEFT_FLEG 130//오른쪽 팀이 이 깃발까지 오면 승리합니다
#define RIGHT_FLEG (RIGHT_END-LEFT_FLEG)//왼쪽 팀이 이 깃발까지 오면 승리합니다

#define SHORTEST_DISTANCE 4//움직이는 경우 상대편 유닛과 떨어져야하는 최소 거리

#define SUICIDE_POWER 8//자신 스스로를 공격할 떄의 힘
#define ONETIME_SKELETON 13//한번에 만들 해골의 양

#define MAX_WARRIOR 70
#define MAX_ARCHER 60
#define MAX_WIZARD 50
#define MAX_GOLEM 25
#define MAX_DRAGON 12
#define MAX_SKELETON 120

class MyChar
{
public:
	MyChar();
	~MyChar();
protected:
	// 유닛의 체력입니다
	int m_nHp;
	// 유닛의 사정거리입니다
	int m_nRange;
	// 유닛의 공격력입니다
	int m_nPower;
	// 위치
	int m_nPos;
	// 속도
	int m_nSpeed;
	//타입
	_CharType m_CharType;
	// 팀
	_Team m_Team;
	// 유닛 모습
	_State m_State;

	

	CDialog* m_pDlg;
public:
	virtual void Attack(_Team team, int index) = 0;
	virtual void Draw() = 0;

	// //체력을 알아옵니다
	int GetHp() { return m_nHp; }
	// 체력을 설정합니다
	void SetHp(int nHp) { m_nHp = nHp; }
	
	// 상대방과의 거리 알아옴
	int GetDistance(MyChar* pMychar) 
	{
		return abs( m_nPos - pMychar->GetPos() );
	}

	// 위치 알아옴
	int GetPos() { return m_nPos; }
	void SetPos(int nPos);

	// 사정거리 알아옴
	int GetRange() { return m_nRange; }

	void Move1Step();

	// //상태를 알아옵니다
	_State GetState() { return m_State; }

	// 상태를 설정합니다
	void SetState(_State State) { m_State = State; }
	
	// 가장 가까운 적의 인덱스를 알아옴
	int GetNearestEnemy(int& nDistance);
	//케릭터의 타입을 알아옴
	_CharType GetCharType();
	// 한 턴 실행
	virtual void Play1Turn() = 0;
	
};

#endif 