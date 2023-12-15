
// SuChanWar_ServerDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "MyChar.h"
#include "Warrior.h"
#include "Archer.h"
#include "Wizard.h"
#include "Golem.h"
#include "Dragon.h"
#include "skeleton.h"

#include "ListenSocket.h"

//�� ĳ������ �����Դϴ�
#define WARRIOR_COST 10
#define ARCHER_COST 20
#define WIZARD_COST 30
#define GOLEM_COST 50
#define DRAGON_COST 80
#define SKELETON_ARMY_COST 30
//Ÿ�̸� 1ȸ ȣ��� �����ϴ� ������ ���Դϴ�
#define MANA_UP 1
#define MAX_MANA 150//���� �ִ�ġ

#define MAX_CHARACTER 75//�� ������ ���� �� �ִ� �ִ� ĳ���� ��
// CSuChanWar_ServerDlg ��ȭ ����
class CSuChanWar_ServerDlg : public CDialogEx
{
	// �����Դϴ�.
public:
	CSuChanWar_ServerDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SUCHANWAR_SERVER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	// ��� �����
	CListBox m_ListOut;

	Warrior* pWarrior[MAX_WARRIOR];
	int WarriorCount;
	Archer* pArcher[MAX_ARCHER];
	int ArcherCount;
	Wizard* pWizard[MAX_WIZARD];
	int WizardCount;
	Golem* pGolem[MAX_GOLEM];
	int GolemCount;
	Dragon* pDragon[MAX_DRAGON];
	int DragonCount;
	Skeleton* pSkeleton[MAX_SKELETON];
	int SkeletonCount;
	

	CListenSocket* m_pListenSocket;

	CArray <MyChar*, MyChar*> arrCharP1;
	CArray <MyChar*, MyChar*> arrCharP2;

	gState GameState;

	bool bPlayerReady[2];

	void DisplayAllChar();

	afx_msg void OnNcDestroy();
	
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	bool InitCharArr();
	bool MakeOneWarrior(_Team team);
	bool MakeOneArcher(_Team team);
	bool MakeOneWizard(_Team team);
	bool MakeOneGolem(_Team team);
	bool MakeOneDragon(_Team team);
	bool MakeOneSkeletonArmy(_Team team);

	bool DeleteOneChar(_Team team, int index);


	

	
	// ���� ������ ĳ���� ����
	void CleanUpGame();

	CButton btnStart;
	CButton btnStop;
	
	//(�ӽ�)���� ���� ��ư�� �Լ���
	CButton btnWarrior1;
	CButton btnWarrior2;
	afx_msg void OnBnClickedButtonWarrior1();
	afx_msg void OnBnClickedButtonWarroir2();
	CButton btnArcher1;
	CButton btnArcher2;
	afx_msg void OnBnClickedButtonArcher1();
	afx_msg void OnBnClickedButtonArcher2();
	CButton btnWizard1;
	CButton btnWizard2;
	afx_msg void OnBnClickedButtonWizard1();
	afx_msg void OnBnClickedButtonWizard2();
	CButton btnGolem1;
	CButton btnGolem2;
	afx_msg void OnBnClickedButtonGolem1();
	afx_msg void OnBnClickedButtonGolem2();
	CButton btnDragon1;
	CButton btnDragon2;
	afx_msg void OnBnClickedButtonDergon1();
	afx_msg void OnBnClickedButtonDergon2();
	CButton btnSkeleton1;
	CButton btnSkeleton2;
	afx_msg void OnBnClickedButtonSkeleton1();
	afx_msg void OnBnClickedButtonSkeleton2();
	//

	// �� 1�� Mana
	int ManaT1;
	// �� 2�� Mana
	int ManaT2;
	CStatic staticManaT1;
	CStatic staticManaT2;
	CString strMana;//������ ǥ���� ���ڿ�


					// Ŭ���̾�Ʈ�� ���� ���ڿ��� ����� �Լ�
	void MakeClientString();
	// Ŭ���̾�Ʈ�� ���� ������(���ڿ�)
//	CString pszSendString;

	unsigned char m_szSend[1024];
	unsigned char m_szReceive[1024];
protected:
	afx_msg LRESULT OnSmReceiveBtnClick(WPARAM wParam, LPARAM lParam);
};

