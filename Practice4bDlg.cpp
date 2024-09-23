
// Practice4bDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Practice4b.h"
#include "Practice4bDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CPractice4bDlg 대화 상자



CPractice4bDlg::CPractice4bDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRACTICE4B_DIALOG, pParent)
	, m_dPresentValue(0)
	, m_dChangeValue(_T(""))
	, m_strPresentUnit(_T(""))
	, m_strChangeUnit(_T(""))
	, m_strUnit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPractice4bDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PRESENT_VALUE, m_dPresentValue);
	DDX_Text(pDX, IDC_EDIT_CHANGE_VALUE, m_dChangeValue);
	DDX_Text(pDX, IDC_EDIT_PRESNET_UNIT, m_strPresentUnit);
	DDX_Text(pDX, IDC_EDIT_CHANGE_UNIT, m_strChangeUnit);
	DDX_Text(pDX, IDC_EDIT_UNIT, m_strUnit);
	DDX_Control(pDX, IDC_LIST_PRESENT_UNIT, m_listPresentUnit);
	DDX_Control(pDX, IDC_LIST_CHANGE_UNIT, m_listChangeUnit);
}

BEGIN_MESSAGE_MAP(CPractice4bDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_RADIO_LENGTH, &CPractice4bDlg::OnRadioLength)
	ON_COMMAND(IDC_RADIO_WEIGHT, &CPractice4bDlg::OnRadioWeight)
END_MESSAGE_MAP()


// CPractice4bDlg 메시지 처리기

BOOL CPractice4bDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPractice4bDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPractice4bDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CPractice4bDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPractice4bDlg::OnRadioLength()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	m_nUnitSelect = 1;
	m_listPresentUnit.ResetContent(); // 왼쪽 ListBox 아이템 삭제
	m_listChangeUnit.ResetContent(); // 오른쪽 ListBox 아이템 삭제
	m_strUnit.Empty();
	m_dPresentValue = m_dChangeValue = 0;

	m_listPresentUnit.AddString(_T("미터(m)")); // 왼쪽 ListBox 아이템 생성
	m_listPresentUnit.AddString(_T("인치(in)"));
	m_listPresentUnit.AddString(_T("야드(yd)"));

	m_listChangeUnit.AddString(_T("미터(m)")); // 오른쪽 ListBox 아이템 생성
	m_listChangeUnit.AddString(_T("인치(in)"));
	m_listChangeUnit.AddString(_T("야드(yd)"));

	m_listPresentUnit.SetCurSel(0);  // 왼쪽 ListBox 첫번째 아이템 선택
	m_listChangeUnit.SetCurSel(0);  // 오른쪽 ListBox 첫번째 아이템 선택
	m_strUnit = m_strUnit + _T("미터(m) --> 미터(m)"); // 변환될 단위 문자열 생성
	m_strPresentUnit = _T("m");
	m_strChangeUnit = _T("m");
	UpdateData(FALSE);

}


void CPractice4bDlg::OnRadioWeight()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	m_nUnitSelect = 2;
	m_listPresentUnit.ResetContent(); // 왼쪽 ListBox 아이템 삭제
	m_listChangeUnit.ResetContent(); // 오른쪽 ListBox 아이템 삭제
	m_strUnit.Empty();
	m_dPresentValue = m_dChangeValue = 0;

	m_listPresentUnit.AddString(_T("그램(g)")); // 왼쪽 ListBox 아이템 생성
	m_listPresentUnit.AddString(_T("온스(oz)"));
	m_listPresentUnit.AddString(_T("파운드(lb)"));

	m_listChangeUnit.AddString(_T("그램(g)")); // 오른쪽 ListBox 아이템 생성
	m_listChangeUnit.AddString(_T("온스(oz)"));
	m_listChangeUnit.AddString(_T("파운드(lb)"));

	m_listPresentUnit.SetCurSel(0);  // 왼쪽 ListBox 첫번째 아이템 선택
	m_listChangeUnit.SetCurSel(0);  // 오른쪽 ListBox 첫번째 아이템 선택
	m_strUnit = m_strUnit + _T("그램(g) --> 그램(g)"); // 변환될 단위 문자열 생성
	m_strPresentUnit = _T("g");
	m_strChangeUnit = _T("g");
	UpdateData(FALSE);

}


void CPractice4bDlg::ComputeUnitValue()
{
	// TODO: 여기에 구현 코드 추가.



}
