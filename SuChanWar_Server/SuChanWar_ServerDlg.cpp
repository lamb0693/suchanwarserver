
// SuChanWar_ServerDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "SuChanWar_Server.h"
#include "SuChanWar_ServerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSuChanWar_ServerDlg ��ȭ ����



CSuChanWar_ServerDlg::CSuChanWar_ServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SUCHANWAR_SERVER_DIALOG, pParent)
	, ManaT1(0)
	, ManaT2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	bPlayerReady[0] = false; bPlayerReady[1] = false;
}

void CSuChanWar_ServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListOut);
	DDX_Control(pDX, IDC_BUTTON_WARRIOR1, btnWarrior1);
	DDX_Control(pDX, IDC_BUTTON_WARROIR2, btnWarrior2);
	DDX_Control(pDX, IDC_BUTTON_START, btnStart);
	DDX_Control(pDX, IDC_BUTTON_STOP, btnStop);
	DDX_Control(pDX, IDC_BUTTON_ARCHER1, btnArcher1);
	DDX_Control(pDX, IDC_BUTTON_ARCHER2, btnArcher2);
	DDX_Control(pDX, IDC_BUTTON_WIZARD1, btnWizard1);
	DDX_Control(pDX, IDC_BUTTON_WIZARD2, btnWizard2);
	DDX_Control(pDX, IDC_BUTTON_GOLEM1, btnGolem1);
	DDX_Control(pDX, IDC_BUTTON_GOLEM2, btnGolem2);
	DDX_Control(pDX, IDC_BUTTON_DERGON1, btnDragon1);
	DDX_Control(pDX, IDC_BUTTON_DERGON2, btnDragon2);
	DDX_Control(pDX, IDC_BUTTON_SKELETON1, btnSkeleton1);
	DDX_Control(pDX, IDC_BUTTON_SKELETON2, btnSkeleton2);
	DDX_Control(pDX, IDC_STATIC_MAMA_T1, staticManaT1);
	DDX_Control(pDX, IDC_STATIC_MAMA_T2, staticManaT2);
}

BEGIN_MESSAGE_MAP(CSuChanWar_ServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST1, &CSuChanWar_ServerDlg::OnLbnSelchangeList1)
	ON_WM_NCDESTROY()
	ON_BN_CLICKED(IDC_BUTTON_START, &CSuChanWar_ServerDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CSuChanWar_ServerDlg::OnBnClickedButtonStop)
	ON_WM_TIMER()
//	ON_WM_KEYDOWN()
ON_BN_CLICKED(IDC_BUTTON_WARRIOR1, &CSuChanWar_ServerDlg::OnBnClickedButtonWarrior1)
ON_BN_CLICKED(IDC_BUTTON_WARROIR2, &CSuChanWar_ServerDlg::OnBnClickedButtonWarroir2)
ON_BN_CLICKED(IDC_BUTTON_ARCHER1, &CSuChanWar_ServerDlg::OnBnClickedButtonArcher1)
ON_BN_CLICKED(IDC_BUTTON_ARCHER2, &CSuChanWar_ServerDlg::OnBnClickedButtonArcher2)
ON_BN_CLICKED(IDC_BUTTON_WIZARD1, &CSuChanWar_ServerDlg::OnBnClickedButtonWizard1)
ON_BN_CLICKED(IDC_BUTTON_WIZARD2, &CSuChanWar_ServerDlg::OnBnClickedButtonWizard2)
ON_BN_CLICKED(IDC_BUTTON_GOLEM1, &CSuChanWar_ServerDlg::OnBnClickedButtonGolem1)
ON_BN_CLICKED(IDC_BUTTON_GOLEM2, &CSuChanWar_ServerDlg::OnBnClickedButtonGolem2)
ON_BN_CLICKED(IDC_BUTTON_DERGON1, &CSuChanWar_ServerDlg::OnBnClickedButtonDergon1)
ON_BN_CLICKED(IDC_BUTTON_DERGON2, &CSuChanWar_ServerDlg::OnBnClickedButtonDergon2)
ON_BN_CLICKED(IDC_BUTTON_SKELETON1, &CSuChanWar_ServerDlg::OnBnClickedButtonSkeleton1)
ON_BN_CLICKED(IDC_BUTTON_SKELETON2, &CSuChanWar_ServerDlg::OnBnClickedButtonSkeleton2)
ON_MESSAGE(SM_RECEIVE_BTN_CLICK, &CSuChanWar_ServerDlg::OnSmReceiveBtnClick)
END_MESSAGE_MAP()


// CSuChanWar_ServerDlg �޽��� ó����

BOOL CSuChanWar_ServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	// socket �ʱ�ȭ �ϰ� ���� listen ����ϳ�
	m_pListenSocket = new CListenSocket(this);

	if (m_pListenSocket->Create(9876, SOCK_STREAM)) {
		if (!m_pListenSocket->Listen()) {
			AfxMessageBox(_T("Server socket ��� ����"));
		}
	}
	else {
		AfxMessageBox(_T("Server Socket ���� ����"));
		PostQuitMessage(0);
	}
//	AfxMessageBox(_T("Socket ����մϴ� port 9876"));
	

	InitCharArr();  //  ��ü ����� point���� null�� �ʱ�� �Ѱ� count�� 0���� �ʱ�ȭ
	GameState = BEFORE_START;
	//(�ӽ�)��ư���� ����
	btnWarrior1.EnableWindow(false);
	btnWarrior2.EnableWindow(false);
	btnArcher1.EnableWindow(false);
	btnArcher2.EnableWindow(false);
	btnWizard1.EnableWindow(false);
	btnWizard2.EnableWindow(false);
	btnGolem1.EnableWindow(false);
	btnGolem2.EnableWindow(false);
	btnDragon1.EnableWindow(false);
	btnDragon2.EnableWindow(false);
	btnSkeleton1.EnableWindow(false);
	btnSkeleton2.EnableWindow(false);
	btnStart.EnableWindow(false);
	btnStop.EnableWindow(false);
	//
	//���� �ʱ�ȭ
	ManaT1 = 0;
	ManaT2 = 0;

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CSuChanWar_ServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CSuChanWar_ServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CSuChanWar_ServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSuChanWar_ServerDlg::OnLbnSelchangeList1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CSuChanWar_ServerDlg::OnNcDestroy()
{
	CDialogEx::OnNcDestroy();

	for (int i = 0; i < WarriorCount; i++)
	{
		ASSERT(pWarrior[i]!=NULL);
		delete pWarrior[i];
	}
	for (int i = 0; i < ArcherCount; i++)
	{
		ASSERT(pArcher[i] != NULL);
		delete pArcher[i];
	}
	for (int i = 0; i < WizardCount; i++)
	{
		ASSERT(pWizard[i] != NULL);
		delete pWizard[i];
	}
	for (int i = 0; i < GolemCount; i++)
	{
		ASSERT(pGolem[i] != NULL);
		delete pGolem[i];
	}
	for (int i = 0; i < DragonCount; i++)
	{
		ASSERT(pDragon[i] != NULL);
		delete pDragon[i];
	}
	for (int i = 0; i < SkeletonCount; i++)
	{
		ASSERT(pSkeleton[i] != NULL);
		delete pSkeleton[i];
	}

	// Socket �� �����Ѵ�
	if (m_pListenSocket->pPlyaer1Socket != NULL) {
		m_pListenSocket->pPlyaer1Socket->ShutDown();
		m_pListenSocket->pPlyaer1Socket->Close();
		delete m_pListenSocket->pPlyaer1Socket;
	}
	if (m_pListenSocket->pPlayer2Socket != NULL) {
		m_pListenSocket->pPlayer2Socket->ShutDown();
		m_pListenSocket->pPlayer2Socket->Close();
		delete m_pListenSocket->pPlayer2Socket;
	}
	m_pListenSocket->ShutDown();
	m_pListenSocket->Close();
	delete m_pListenSocket;
	//**

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CSuChanWar_ServerDlg::DisplayAllChar()
{
	for (int i = 0; i < arrCharP1.GetCount(); i++) {
		arrCharP1.GetAt(i)->Draw();
	}
	for (int i = 0; i < arrCharP2.GetCount(); i++) {
		arrCharP2.GetAt(i)->Draw();
	}
	m_ListOut.AddString(_T("-------"));
}


void CSuChanWar_ServerDlg::OnBnClickedButtonStart()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	SetTimer(1, TIME_INTERVAL, NULL);
	GameState = ONGAME;

	//(�ӽ�)��ư�� ����
	btnWarrior1.EnableWindow(true);
	btnWarrior2.EnableWindow(true);
	btnArcher1.EnableWindow(true);
	btnArcher2.EnableWindow(true);
	btnWizard1.EnableWindow(true);
	btnWizard2.EnableWindow(true);
	btnGolem1.EnableWindow(true);
	btnGolem2.EnableWindow(true);
	btnDragon1.EnableWindow(true);
	btnDragon2.EnableWindow(true);
	btnSkeleton1.EnableWindow(true);
	btnSkeleton2.EnableWindow(true);
	//
	btnStop.EnableWindow(true);
	btnStart.EnableWindow(false);

}


void CSuChanWar_ServerDlg::OnBnClickedButtonStop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	KillTimer(1);
	GameState = GAME_PAUSE;

	//(�ӽ�)��ư�� ����
	btnWarrior1.EnableWindow(false);
	btnWarrior2.EnableWindow(false);
	btnArcher1.EnableWindow(false);
	btnArcher2.EnableWindow(false);
	btnWizard1.EnableWindow(false);
	btnWizard2.EnableWindow(false);
	btnGolem1.EnableWindow(false);
	btnGolem2.EnableWindow(false);
	btnDragon1.EnableWindow(false);
	btnDragon2.EnableWindow(false);
	btnSkeleton1.EnableWindow(false);
	btnSkeleton2.EnableWindow(false);
	//
	btnStart.SetWindowTextW(_T("�����"));
	btnStop.EnableWindow(false);
	btnStart.EnableWindow(true);
}


void CSuChanWar_ServerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	// �� Ŭ���̾�Ʈ ���� �Ѵ� ���� �����̸� Ÿ�̸Ӹ� �����ϰ� �ʱ�ȭ �Ѵ�
	if (m_pListenSocket->pPlyaer1Socket == NULL && m_pListenSocket->pPlayer2Socket == NULL) {
		KillTimer(1);
		CleanUpGame();
		GameState = BEFORE_START;
	}
	
	// �Ѹ��̶� ���� �ְų�, �������� �Ѹ��� �غ�Ϸ� ��ư ������ ���̸� �׳� �����Ѵ�
	if (!bPlayerReady[0] || !bPlayerReady[1]) return; 
	if (m_pListenSocket->pPlyaer1Socket == NULL) {
		bPlayerReady[0] = false;
		return;
	}
	if (m_pListenSocket->pPlayer2Socket == NULL) {
		bPlayerReady[1] = false;
		return;
	}

	// �Ѵ� ���� �� ���� �� �����̴�. 
	switch (GameState) {
	case ONGAME:
		DisplayAllChar();
		break;
	case PLAYER1_WIN:
		KillTimer(1);
//		AfxMessageBox(_T("������ �¸�"));
		// sokcet���� �¸� �� ����
		m_szSend[0] = GAMEEND;
		m_szSend[1] = 1;
		m_pListenSocket->pPlyaer1Socket->Send(m_szSend, 1024);
		m_pListenSocket->pPlayer2Socket->Send(m_szSend, 1024);
		CleanUpGame();
		break;
	case PLAYER2_WIN:
		KillTimer(1);
//		AfxMessageBox(_T("�������� �¸�"));
		// socket���� �¸� �� ����
		m_szSend[0] = GAMEEND;
		m_szSend[1] = 2;
		m_pListenSocket->pPlyaer1Socket->Send(m_szSend, 1024);
		m_pListenSocket->pPlayer2Socket->Send(m_szSend, 1024);
		CleanUpGame();
		break;
	}
	
	ManaT1 += MANA_UP;
	ManaT2 += MANA_UP;
	if (ManaT1 >= MAX_MANA) ManaT1 = MAX_MANA;
	if (ManaT2 >= MAX_MANA) ManaT2 = MAX_MANA;
	
	//������ �ø��� ǥ���Ѵ�
	strMana.Format(_T("���� : %d"), ManaT1);
	staticManaT1.SetWindowTextW((LPCTSTR)strMana.GetBuffer());
	strMana.Format(_T("���� : %d"), ManaT2);
	staticManaT2.SetWindowTextW((LPCTSTR)strMana.GetBuffer());

	for (int i = 0; i < arrCharP1.GetCount(); i++) {
		arrCharP1.GetAt(i)->Play1Turn();
		if (arrCharP1.GetAt(i)->GetCharType() == DRAGON) {//ĳ���Ͱ� �巹������ �˻�
			arrCharP1.GetAt(i)->SetHp(arrCharP1.GetAt(i)->GetHp() - SUICIDE_POWER);//�巹���̸� SUACIDE_POWER(���� �� ���ݷ�) ��ŭ ü���� ���ҽ�Ų��
			if (arrCharP1.GetAt(i)->GetHp() <= 0) {//���� �巹���� ü���� 0���� ������
				DeleteOneChar(Player1, i);//�巹���� �����Ѵ�
			}
		}
	}
	for (int i = 0; i < arrCharP2.GetCount(); i++) {
		arrCharP2.GetAt(i)->Play1Turn();
		if (arrCharP2.GetAt(i)->GetCharType() == DRAGON) {
			arrCharP2.GetAt(i)->SetHp(arrCharP2.GetAt(i)->GetHp() - SUICIDE_POWER);
			if (arrCharP2.GetAt(i)->GetHp() <= 0) {
				DeleteOneChar(Player2, i);
			}
		}
	
	}

	if (ManaT1 < 0) {
		TRACE(_T("\n��1������ 0�̸��Դϴ�"));
		ManaT1 = 0;
	}
	if (ManaT2 < 0) {
		TRACE(_T("\n��2������ 0�̸��Դϴ�"));
		ManaT2 = 0;
	}

	// ���� �����͸� �迭�� ����� ������
	MakeClientString();//Ŭ���̾�Ʈ�� ���� ���ڿ��� �����
	// ������ socket���� ���� data�� ����
	m_pListenSocket->SendDataPlayer1(m_szSend);
	m_pListenSocket->SendDataPlayer2(m_szSend);

	CDialogEx::OnTimer(nIDEvent);
}

// ��� Ÿ���� ĳ���� �迭�� point�� NULL�� �ʱ�ȭ
bool CSuChanWar_ServerDlg::InitCharArr()
{
	for (int i = 0; i < MAX_WARRIOR; i++) {
		pWarrior[i] = NULL;
	}
	WarriorCount = 0;

	for (int i = 0; i < MAX_ARCHER; i++) {
		pArcher[i] = NULL;
	}
	ArcherCount = 0;

	for (int i = 0; i < MAX_WIZARD; i++) {
		pWizard[i] = NULL;
	}
	WizardCount = 0;

	for (int i = 0; i < MAX_GOLEM; i++) {
		pGolem[i] = NULL;
	}
	GolemCount = 0;

	for (int i = 0; i < MAX_DRAGON; i++) {
		pDragon[i] = NULL;
	}
	DragonCount = 0;

	for (int i = 0; i < MAX_SKELETON; i++) {
		pSkeleton[i] = NULL;
	}
	SkeletonCount = 0;

	return true;
}


// Warrior ��ü�� �ϳ� �����, Warrior �迭�� �ְ�, ���� ���� arrCharP1 or  arrCharP2
//�� point�� �߰��Ѵ�  �����ϸ� false�� return �Ѵ�
// Warrior count�� ���� ���Ѿ� ��
bool CSuChanWar_ServerDlg::MakeOneWarrior(_Team team)
{
	if (WarriorCount == MAX_WARRIOR) return false;
	pWarrior[WarriorCount] = new Warrior(team, (CDialog*) this);
	ASSERT(pWarrior[WarriorCount] != NULL);
	if (team == Player1) {
		arrCharP1.Add((MyChar*)pWarrior[WarriorCount]);
		ManaT1 -= WARRIOR_COST;
	}
	else {
		arrCharP2.Add((MyChar*)pWarrior[WarriorCount]);
		ManaT2 -= WARRIOR_COST;
	}
	WarriorCount++;
	
	return true;
}

bool CSuChanWar_ServerDlg::MakeOneArcher(_Team team)
{
	if (ArcherCount == MAX_ARCHER) return false;
	pArcher[ArcherCount] = new Archer(team, (CDialog*) this);
	ASSERT(pArcher[ArcherCount] != NULL);
	if (team == Player1) {
		arrCharP1.Add((MyChar*)pArcher[ArcherCount]);
		ManaT1 -= ARCHER_COST;
	}
	else {
		arrCharP2.Add((MyChar*)pArcher[ArcherCount]);
		ManaT2 -= ARCHER_COST;
	}
	ArcherCount++;

	return true;
}

bool CSuChanWar_ServerDlg::MakeOneWizard(_Team team)
{
	if (WizardCount == MAX_WIZARD) return false;
	pWizard[WizardCount] = new Wizard(team, (CDialog*) this);
	ASSERT(pWizard[WizardCount] != NULL);
	if (team == Player1) {
		arrCharP1.Add((MyChar*)pWizard[WizardCount]);
		ManaT1 -= WIZARD_COST;
	}
	else {
		arrCharP2.Add((MyChar*)pWizard[WizardCount]);
		ManaT2 -= WIZARD_COST;
	}
	WizardCount++;

	return true;
}

bool CSuChanWar_ServerDlg::MakeOneGolem(_Team team)
{
	if (GolemCount == MAX_GOLEM) return false;
	pGolem[GolemCount] = new Golem(team, (CDialog*) this);
	ASSERT(pGolem[GolemCount] != NULL);
	if (team == Player1) {
		arrCharP1.Add((MyChar*)pGolem[GolemCount]);
		ManaT1 -= GOLEM_COST;
	}
	else {
		arrCharP2.Add((MyChar*)pGolem[GolemCount]);
		ManaT2 -= GOLEM_COST;
	}
	GolemCount++;

	return true;
}

bool CSuChanWar_ServerDlg::MakeOneDragon(_Team team)
{
	if (DragonCount == MAX_DRAGON) return false;
	pDragon[DragonCount] = new Dragon(team, (CDialog*) this);    // index? ����
	ASSERT(pDragon[DragonCount] != NULL);
	if (team == Player1) {
		arrCharP1.Add((MyChar*)pDragon[DragonCount]);
		ManaT1 -= DRAGON_COST;
	}
	else {
		arrCharP2.Add((MyChar*)pDragon[DragonCount]);
		ManaT2 -= DRAGON_COST;
	}
	DragonCount++;

	return true;
}

bool CSuChanWar_ServerDlg::MakeOneSkeletonArmy(_Team team)
{
	if (SkeletonCount > (MAX_SKELETON - ONETIME_SKELETON)) return false;

	if(team == Player1) ManaT1 -= SKELETON_ARMY_COST;
	else ManaT2 -= SKELETON_ARMY_COST;

	for (int i = 0; i < ONETIME_SKELETON; i++)
	{
		pSkeleton[SkeletonCount] = new Skeleton(team, (CDialog*) this, i*7);
		ASSERT(pSkeleton[SkeletonCount] != NULL);
		if (team == Player1) arrCharP1.Add((MyChar*)pSkeleton[SkeletonCount]);
		else arrCharP2.Add((MyChar*)pSkeleton[SkeletonCount]);
		SkeletonCount++;
	}

	return true;
}

// �ش� �����͸� ���ͼ�
// ĳ���� Ÿ���� ���ϰ�
// �� ĳ���� �迭���� ���� �ּҸ� ������ �����͸� ã��
// �� �������� ��ü�� ���ְ�
// �迭�� ������ ���� ���� ��� ������ �� ��� �´�
// �ش� ĳ���� Ÿ���� ���� ����
// team ������ arrCharP1 or arrChar P2�� �����͸� ����
// �����ϸ� false�� return
bool CSuChanWar_ServerDlg::DeleteOneChar(_Team team, int index)
{
	MyChar* pChar;
	int nRemove=-1;//������ ĳ������ �����͸� CArray ���� ���ͼ� 
				   //�� Ÿ���� ��ü �����Ϳ����� ���� ����� ã�Ƽ� �ε����� ���� ����
	if (team == Player1) {
		pChar = arrCharP1.GetAt(index);
		arrCharP1.RemoveAt(index);
	}
	else {
		pChar = arrCharP2.GetAt(index);
		arrCharP2.RemoveAt(index);
	}

	switch (pChar->GetCharType()) {
	case WARRIOR:
		for (int i = 0; i < WarriorCount; i++)
		{
			if (pWarrior[i] == pChar) {
				ASSERT(pWarrior[i] != NULL);
				delete pWarrior[i];
				nRemove = i;
			}
		}
		ASSERT(nRemove > -1);//-1�̸� �� ã�� ���̴�
		WarriorCount--;
		for (int i = nRemove; i < WarriorCount; i++) {
			pWarrior[i] = pWarrior[i + 1];
			ASSERT(pWarrior[i] != NULL);
		}
		pWarrior[WarriorCount] = NULL;
		break;

	case ARCHER:
		for (int i = 0; i < ArcherCount; i++)
		{
			if (pArcher[i] == pChar) {
				ASSERT(pArcher[i] != NULL);
				delete pArcher[i];
				nRemove = i;
			}
		}
		ASSERT(nRemove > -1);
		ArcherCount--;
		for (int i = nRemove; i < ArcherCount; i++) {
			pArcher[i] = pArcher[i + 1];
			ASSERT(pArcher[i] != NULL);
		}
		pArcher[ArcherCount] = NULL;
		break;

	case WIZARD:
		for (int i = 0; i < WizardCount; i++)
		{
			if (pWizard[i] == pChar) {
				ASSERT(pWizard[i] != NULL);
				delete pWizard[i];
				nRemove = i;
			}
		}
		ASSERT(nRemove > -1);
		WizardCount--;
		for (int i = nRemove; i < WizardCount; i++) {
			pWizard[i] = pWizard[i + 1];
			ASSERT(pWizard[i] != NULL);
		}
		pWizard[WizardCount] = NULL;
		break;

	case GOLEM:
		for (int i = 0; i < GolemCount; i++)
		{
			if (pGolem[i] == pChar) {
				ASSERT(pGolem[i] != NULL);
				delete pGolem[i];
				nRemove = i;
			}
		}
		ASSERT(nRemove > -1);
		GolemCount--;
		for (int i = nRemove; i < GolemCount; i++) {
			pGolem[i] = pGolem[i + 1];
			ASSERT(pGolem[i] != NULL);
		}
		pGolem[GolemCount] = NULL;
		break;

	case DRAGON:
		for (int i = 0; i < DragonCount; i++)
		{
			if (pDragon[i] == pChar) {
				ASSERT(pDragon[i] != NULL);
				delete pDragon[i];
				nRemove = i;
			}
		}
		ASSERT(nRemove > -1);
		DragonCount--;
		for (int i = nRemove; i < DragonCount; i++) {
			pDragon[i] = pDragon[i + 1];
			ASSERT(pDragon[i] != NULL);
		}
		pDragon[DragonCount] = NULL;
		break;

	case SKELETON:
		for (int i = 0; i < SkeletonCount; i++)
		{
			if (pSkeleton[i] == pChar) {
				ASSERT(pSkeleton[i] != NULL);
				delete pSkeleton[i];
				nRemove = i;
			}
		}
		ASSERT(nRemove > -1);
		SkeletonCount--;
		for (int i = nRemove; i < SkeletonCount; i++) {
			pSkeleton[i] = pSkeleton[i + 1];
			ASSERT(pSkeleton[i] != NULL);
		}
		pSkeleton[SkeletonCount] = NULL;
		break;
	}
	
	return true;
}




// ���� ������ ĳ���� ����
void CSuChanWar_ServerDlg::CleanUpGame()
{

	for (int i = 0; i < WarriorCount; i++)
	{
		ASSERT(pWarrior[i] != NULL);
		delete pWarrior[i];
		pWarrior[i] = NULL;
	}
	WarriorCount = 0;

	for (int i = 0; i < ArcherCount; i++)
	{
		ASSERT(pArcher[i] != NULL);
		delete pArcher[i];
		pArcher[i] = NULL;
	}
	ArcherCount = 0;

	for (int i = 0; i < WizardCount; i++)
	{
		ASSERT(pWizard[i] != NULL);
		delete pWizard[i];
		pWizard[i] = NULL;
	}
	WizardCount = 0;

	for (int i = 0; i < GolemCount; i++)
	{
		ASSERT(pGolem[i] != NULL);
		delete pGolem[i];
		pGolem[i] = NULL;
	}
	GolemCount = 0;

	for (int i = 0; i < DragonCount; i++)
	{
		ASSERT(pDragon[i] != NULL);
		delete pDragon[i];
		pDragon[i] = NULL;
	}
	DragonCount = 0;

	for (int i = 0; i < SkeletonCount; i++)
	{
		ASSERT(pSkeleton[i] != NULL);
		delete pSkeleton[i];
		pSkeleton[i] = NULL;
	}
	SkeletonCount = 0;

	ManaT1 = 0;
	ManaT2 = 0;
	strMana.Format(_T("���� : %d"), ManaT1);
	staticManaT1.SetWindowTextW((LPCTSTR)strMana.GetBuffer());
	strMana.Format(_T("���� : %d"), ManaT2);
	staticManaT2.SetWindowTextW((LPCTSTR)strMana.GetBuffer());

	arrCharP1.RemoveAll();
	arrCharP2.RemoveAll();
	GameState = BEFORE_START;
	btnStart.SetWindowTextW(_T("����"));
	//Ÿ�̸Ӵ� �̹� Ÿ�̸ӿ��� �׾���

	bPlayerReady[0] = false;
	bPlayerReady[1] = false;

	//(�ӽ�)��ư�� ����
	btnWarrior1.EnableWindow(false);
	btnWarrior2.EnableWindow(false);
	btnArcher1.EnableWindow(false);
	btnArcher2.EnableWindow(false);
	btnWizard1.EnableWindow(false);
	btnWizard2.EnableWindow(false);
	btnGolem1.EnableWindow(false);
	btnGolem2.EnableWindow(false);
	btnDragon1.EnableWindow(false);
	btnDragon2.EnableWindow(false);
	btnSkeleton1.EnableWindow(false);
	btnSkeleton2.EnableWindow(false);

	btnStop.EnableWindow(false);
	btnStart.EnableWindow(true);
}


void CSuChanWar_ServerDlg::OnBnClickedButtonWarrior1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (arrCharP2.GetCount() >= MAX_CHARACTER) {
		TRACE(_T("�������� ���� ���̻� ���� �Ұ���"));
		return;
	}
	if (ManaT1>=WARRIOR_COST)
	{
		ManaT1 -= WARRIOR_COST;
		MakeOneWarrior(Player1);
	}
}


void CSuChanWar_ServerDlg::OnBnClickedButtonWarroir2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (arrCharP2.GetCount() >= MAX_CHARACTER) {
		TRACE(_T("���������� ���� ���̻� ���� �Ұ���"));
		return;
	}
	if (ManaT2 >= WARRIOR_COST)
	{
		ManaT2 -= WARRIOR_COST;
		MakeOneWarrior(Player2);
	}
}


void CSuChanWar_ServerDlg::OnBnClickedButtonArcher1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (arrCharP2.GetCount() >= MAX_CHARACTER) {
		TRACE(_T("�������� ���� ���̻� ���� �Ұ���"));
		return;
	}
	if (ManaT1 >= ARCHER_COST)
	{
		ManaT1 -= ARCHER_COST;
		MakeOneArcher(Player1);
	}
}


void CSuChanWar_ServerDlg::OnBnClickedButtonArcher2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (arrCharP2.GetCount() >= MAX_CHARACTER) {
		TRACE(_T("���������� ���� ���̻� ���� �Ұ���"));
		return;
	}
	if (ManaT2 >= ARCHER_COST)
	{
		ManaT2 -= ARCHER_COST;
		MakeOneArcher(Player2);
	}
}


void CSuChanWar_ServerDlg::OnBnClickedButtonWizard1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (arrCharP2.GetCount() >= MAX_CHARACTER) {
		TRACE(_T("�������� ���� ���̻� ���� �Ұ���"));
		return;
	}
	if (ManaT1 >= WIZARD_COST)
	{
		ManaT1 -= WIZARD_COST;
		MakeOneWizard(Player1);
	}
}


void CSuChanWar_ServerDlg::OnBnClickedButtonWizard2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (arrCharP2.GetCount() >= MAX_CHARACTER) {
		TRACE(_T("���������� ���� ���̻� ���� �Ұ���"));
		return;
	}
	if (ManaT2 >= WIZARD_COST)
	{
		ManaT2 -= WIZARD_COST;
		MakeOneWizard(Player2);
	}
}


void CSuChanWar_ServerDlg::OnBnClickedButtonGolem1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (arrCharP2.GetCount() >= MAX_CHARACTER) {
		TRACE(_T("�������� ���� ���̻� ���� �Ұ���"));
		return;
	}
	if (ManaT1 >= GOLEM_COST)
	{
		ManaT1 -= GOLEM_COST;
		MakeOneGolem(Player1);
	}
}


void CSuChanWar_ServerDlg::OnBnClickedButtonGolem2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (arrCharP2.GetCount() >= MAX_CHARACTER) {
		TRACE(_T("���������� ���� ���̻� ���� �Ұ���"));
		return;
	}
	if (ManaT2 >= GOLEM_COST)
	{
		ManaT2 -= GOLEM_COST;
		MakeOneGolem(Player2);
	}
}


void CSuChanWar_ServerDlg::OnBnClickedButtonDergon1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (arrCharP2.GetCount() >= MAX_CHARACTER) {
		TRACE(_T("�������� ���� ���̻� ���� �Ұ���"));
		return;
	}
	if (ManaT1 >= DRAGON_COST)
	{
		ManaT1 -= DRAGON_COST;
		MakeOneDragon(Player1);
	}

}


void CSuChanWar_ServerDlg::OnBnClickedButtonDergon2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (arrCharP2.GetCount() >= MAX_CHARACTER) {
		TRACE(_T("���������� ���� ���̻� ���� �Ұ���"));
		return;
	}
	if (ManaT2 >= DRAGON_COST)
	{
		ManaT2 -= DRAGON_COST;
		MakeOneDragon(Player2);
	}
}


void CSuChanWar_ServerDlg::OnBnClickedButtonSkeleton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (arrCharP1.GetCount() >= MAX_CHARACTER) {
		TRACE(_T("�������� ���� ���̻� ���� �Ұ���"));
		return;
	}
	if (ManaT1 >= SKELETON_ARMY_COST)
	{
		ManaT1 -= SKELETON_ARMY_COST;
		MakeOneSkeletonArmy(Player1);
	}
}


void CSuChanWar_ServerDlg::OnBnClickedButtonSkeleton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (arrCharP2.GetCount() >= MAX_CHARACTER) {
		TRACE(_T("���������� ���� ���̻� ���� �Ұ���"));
		return;
	}
	if (ManaT2 >= SKELETON_ARMY_COST)
	{
		ManaT2 -= SKELETON_ARMY_COST;
		MakeOneSkeletonArmy(Player2);
	}
}


// Ŭ���̾�Ʈ�� ���� ���ڿ��� ����� �Լ�
void CSuChanWar_ServerDlg::MakeClientString()
{

	unsigned char* pCurrent;
	pCurrent = m_szSend;
	*pCurrent = GAME_DATA;// ���� ���� ������

	pCurrent++; *pCurrent = 1; pCurrent++; *pCurrent = arrCharP1.GetCount();  // ���� ���� ���� �ֱ�
	pCurrent++; *pCurrent = ManaT1 / 100;   pCurrent++; *pCurrent = ManaT1 % 100;
	for (int i = 0; i < arrCharP1.GetCount(); i++) {
		pCurrent++;  *pCurrent = arrCharP1.GetAt(i)->GetHp() / 100;
		pCurrent++;  *pCurrent = arrCharP1.GetAt(i)->GetHp() % 100;
		pCurrent++;  *pCurrent = arrCharP1.GetAt(i)->GetPos()/100 ;
		pCurrent++;  *pCurrent = arrCharP1.GetAt(i)->GetPos() % 100;
		pCurrent++;  *pCurrent = arrCharP1.GetAt(i)->GetCharType();
		pCurrent++;  *pCurrent = arrCharP1.GetAt(i)->GetState();
	}
	pCurrent++;  *pCurrent = 2; pCurrent++; *pCurrent = arrCharP2.GetCount();  // ���� ���� �ֱ�
	pCurrent++; *pCurrent = ManaT2 / 100;   pCurrent++; *pCurrent = ManaT2 % 100;
	for (int i = 0; i < arrCharP2.GetCount(); i++) {
		pCurrent++;  *pCurrent = arrCharP2.GetAt(i)->GetHp() / 100;
		pCurrent++;  *pCurrent = arrCharP2.GetAt(i)->GetHp() % 100;
		pCurrent++;  *pCurrent = arrCharP2.GetAt(i)->GetPos() / 100;
		pCurrent++;  *pCurrent = arrCharP2.GetAt(i)->GetPos() % 100;
		pCurrent++;  *pCurrent = arrCharP2.GetAt(i)->GetCharType();
		pCurrent++;  *pCurrent = arrCharP2.GetAt(i)->GetState();
	}
	pCurrent++;
	*pCurrent = NULL;

	ASSERT((pCurrent - m_szSend) < 1024); // 1024byte�Ѿ� ������ Ȯ��
}


afx_msg LRESULT CSuChanWar_ServerDlg::OnSmReceiveBtnClick(WPARAM wParam, LPARAM lParam)
{
	int msgType = m_szReceive[0];
	int btnType = m_szReceive[1];//� ĳ���� ���� ��ư�� ���ȴ°�, 6���� �غ�Ϸ� ��ư
	int nTeam = m_szReceive[2]-1;//������ 1�Ǵ� 2�� ���ƿ�(�׷��� 1����)
	
	// ���簡 �ƽ� ĳ���� ����� �ȸ���� ����  // 
	// skeleton 3���� ���� ������ ������ �Ѿ �� �ִ� 
	// ���߿� Ȯ�� ���
	if (msgType == BTN_CLICK) {
		if (nTeam == 0 &&  arrCharP1.GetCount() >= MAX_CHARACTER) {
			TRACE(_T("�������� ���� ���̻� ���� �Ұ���"));
			return 0;
		}
		if (nTeam == 1 && arrCharP2.GetCount() >= MAX_CHARACTER) {
			TRACE(_T("���������� ���� ���̻� ���� �Ұ���"));
			return 0;
		}
		
		ASSERT(btnType >= 0 && btnType < 7);
		switch (btnType)
		{
		case WARRIOR:
			MakeOneWarrior((_Team)nTeam);
			break;
		case ARCHER:
			MakeOneArcher((_Team)nTeam);
			break;
		case WIZARD:
			MakeOneWizard((_Team)nTeam);
			break;
		case GOLEM:
			MakeOneGolem((_Team)nTeam);
			break;
		case DRAGON:
			MakeOneDragon((_Team)nTeam);
			break;
		case SKELETON:
			MakeOneSkeletonArmy((_Team)nTeam);
			break;
		case 6:
			bPlayerReady[nTeam] = true;
			if (bPlayerReady[0] == true && bPlayerReady[1] == true) {
				SetTimer(1, TIME_INTERVAL, NULL);
				GameState = ONGAME;
			}
		}
	}
	return 0;
}
