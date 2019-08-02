
// winSubProgramDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "winSubProgram.h"
#include "winSubProgramDlg.h"
#include "afxdialogex.h"
#include "resource.h"

#include "TimerDlg.h"
#include "FindDlg.h"

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
public:
//	afx_msg void OnSavefile();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_COMMAND(ID_savefile, &CAboutDlg::OnSavefile)
END_MESSAGE_MAP()


// CwinSubProgramDlg 대화 상자



CwinSubProgramDlg::CwinSubProgramDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WINSUBPROGRAM_DIALOG, pParent)
	, m_save(false)
	, m_search(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CwinSubProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT, m_richEdit);
}

BEGIN_MESSAGE_MAP(CwinSubProgramDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
//	ON_EN_CHANGE(IDC_RICHEDIT21, &CwinSubProgramDlg::OnEnChangeRichedit21)
ON_COMMAND(ID_font, &CwinSubProgramDlg::OnFont)
//ON_COMMAND(ID_color, &CwinSubProgramDlg::OnColor)
//ON_COMMAND(ID_timer, &CwinSubProgramDlg::OnTimer)
ON_COMMAND(ID_savefile, &CwinSubProgramDlg::OnSavefile)
ON_COMMAND(ID_openfile, &CwinSubProgramDlg::OnOpenfile)
ON_COMMAND(ID_find, &CwinSubProgramDlg::OnFind)
ON_COMMAND(ID_timer, &CwinSubProgramDlg::OnTimer)
ON_COMMAND(ID_copy, &CwinSubProgramDlg::OnCopy)
ON_COMMAND(ID_paste, &CwinSubProgramDlg::OnPaste)
ON_COMMAND(ID_cut, &CwinSubProgramDlg::OnCut)
ON_COMMAND(ID_undo, &CwinSubProgramDlg::OnUndo)
ON_COMMAND(ID_stopwatch, &CwinSubProgramDlg::OnStopwatch)
END_MESSAGE_MAP()


// CwinSubProgramDlg 메시지 처리기

BOOL CwinSubProgramDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_toolbar = new CToolBar();
	DWORD style = WS_CHILD | WS_VISIBLE | CBRS_TOOLTIPS |(CBRS_ALIGN_TOP&CBRS_ALIGN_ANY);

	m_toolbar->CreateEx(this, TBSTYLE_FLAT, style);
	m_toolbar->LoadToolBar(IDR_TOOLBAR1);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CwinSubProgramDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if (nID == SC_CLOSE) {
		if (!m_save) {
			if (AfxMessageBox(_T("저장하지 않고 종료하시겠습니까?"), MB_ICONWARNING | MB_YESNO) == IDYES)
				OnClose();
		}
		else
			OnClose();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CwinSubProgramDlg::OnPaint()
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
HCURSOR CwinSubProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CwinSubProgramDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_toolbar->DestroyWindow();
	delete m_toolbar;
}



void CwinSubProgramDlg::OnFont()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CFontDialog dlg;
	CHARFORMAT cf;
	m_richEdit.GetDefaultCharFormat(cf);
	if (dlg.DoModal() == IDOK) {
		dlg.GetCharFormat(cf);
		if (m_richEdit.GetSelText() == _T(""))
			m_richEdit.SetDefaultCharFormat(cf);
		else
			m_richEdit.SetSelectionCharFormat(cf);
	}
}


void CwinSubProgramDlg::OnSavefile()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString m_string;
	CStdioFile file;
	CFileException ex;
	CFileDialog dlg(FALSE, _T("*.txt"), NULL, OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT, _T("TXT Files(*.txt)|*.txt|"), NULL);
	if (dlg.DoModal() == IDOK) {
		m_string = dlg.GetPathName();
		if (m_string.Right(4) != ".txt")
			m_string += ".txt";
		file.Open(m_string, CFile::modeCreate | CFile::modeReadWrite, &ex);
		UpdateData(true);
		file.WriteString(m_richEdit.GetSelText());
		file.Close();
		m_save = true;
	}
}


void CwinSubProgramDlg::OnOpenfile()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다
	CString m_string,str,s;
	CStdioFile file;
	CFileException ex;
	CFileDialog dlg(TRUE,_T(".txt"),NULL,OFN_FILEMUSTEXIST|OFN_OVERWRITEPROMPT,_T("TXT File(*.txt)|*.txt|"),NULL);
	if (dlg.DoModal() == IDOK) {
		m_string = dlg.GetPathName();
		if (m_string.Right(4) != ".txt")
			m_string += ".txt";
		file.Open(m_string, CFile::modeReadWrite | CFile::typeText, &ex);
		while (file.ReadString(str))
			s += str + _T("\r\n");
		m_richEdit.ReplaceSel(s);
	}
}


void CwinSubProgramDlg::OnFind()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CFindDlg dlg;
	if (dlg.DoModal() == IDOK) {
		FINDTEXTEX ft;
		ft.chrg.cpMin = 0;
		ft.chrg.cpMax = -1;
		ft.lpstrText = m_search;
		long n = m_richEdit.FindText(FR_DOWN|FR_MATCHCASE|FR_WHOLEWORD, &ft);
		if (n == -1)
			AfxMessageBox(_T("찾는 단어가 없습니다."), MB_ICONERROR);
		else {
			m_richEdit.SetSel(ft.chrgText);
		}
	}
}


void CwinSubProgramDlg::OnTimer()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CTimerDlg dlg;
	dlg.DoModal();
}


void CwinSubProgramDlg::OnCopy()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_richEdit.Copy();
}


void CwinSubProgramDlg::OnPaste()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_richEdit.Paste();
}


void CwinSubProgramDlg::OnCut()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_richEdit.Cut();
}


void CwinSubProgramDlg::OnUndo()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_richEdit.Undo();
}


void CwinSubProgramDlg::OnStopwatch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_alarmdlg = new CAlarmDlg;

	m_alarmdlg->Create(IDD_time_alarm);
	m_alarmdlg->m_spin1.SetRange(59, 0);
	m_alarmdlg->m_spin2.SetRange(59, 0);
	m_alarmdlg->m_spin3.SetRange(59, 0);
	m_alarmdlg->ShowWindow(SW_SHOW);
}
