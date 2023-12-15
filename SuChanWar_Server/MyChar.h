#ifndef _MyCharH
#define _MyCharH

#pragma once

#define RIGHT_END 1600
#define LEFT_FLEG 130//������ ���� �� ��߱��� ���� �¸��մϴ�
#define RIGHT_FLEG (RIGHT_END-LEFT_FLEG)//���� ���� �� ��߱��� ���� �¸��մϴ�

#define SHORTEST_DISTANCE 4//�����̴� ��� ����� ���ְ� ���������ϴ� �ּ� �Ÿ�

#define SUICIDE_POWER 8//�ڽ� �����θ� ������ ���� ��
#define ONETIME_SKELETON 13//�ѹ��� ���� �ذ��� ��

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
	// ������ ü���Դϴ�
	int m_nHp;
	// ������ �����Ÿ��Դϴ�
	int m_nRange;
	// ������ ���ݷ��Դϴ�
	int m_nPower;
	// ��ġ
	int m_nPos;
	// �ӵ�
	int m_nSpeed;
	//Ÿ��
	_CharType m_CharType;
	// ��
	_Team m_Team;
	// ���� ���
	_State m_State;

	

	CDialog* m_pDlg;
public:
	virtual void Attack(_Team team, int index) = 0;
	virtual void Draw() = 0;

	// //ü���� �˾ƿɴϴ�
	int GetHp() { return m_nHp; }
	// ü���� �����մϴ�
	void SetHp(int nHp) { m_nHp = nHp; }
	
	// ������� �Ÿ� �˾ƿ�
	int GetDistance(MyChar* pMychar) 
	{
		return abs( m_nPos - pMychar->GetPos() );
	}

	// ��ġ �˾ƿ�
	int GetPos() { return m_nPos; }
	void SetPos(int nPos);

	// �����Ÿ� �˾ƿ�
	int GetRange() { return m_nRange; }

	void Move1Step();

	// //���¸� �˾ƿɴϴ�
	_State GetState() { return m_State; }

	// ���¸� �����մϴ�
	void SetState(_State State) { m_State = State; }
	
	// ���� ����� ���� �ε����� �˾ƿ�
	int GetNearestEnemy(int& nDistance);
	//�ɸ����� Ÿ���� �˾ƿ�
	_CharType GetCharType();
	// �� �� ����
	virtual void Play1Turn() = 0;
	
};

#endif 