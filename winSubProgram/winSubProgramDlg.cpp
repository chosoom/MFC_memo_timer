
// winSubProgramDlg.cpp : ���� ����
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


// CwinSubProgramDlg ��ȭ ����



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


// CwinSubProgramDlg �޽��� ó����

BOOL CwinSubProgramDlg::OnInitDialog()
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
	m_toolbar = new CToolBar();
	DWORD style = WS_CHILD | WS_VISIBLE | CBRS_TOOLTIPS |(CBRS_ALIGN_TOP&CBRS_ALIGN_ANY);

	m_toolbar->CreateEx(this, TBSTYLE_FLAT, style);
	m_toolbar->LoadToolBar(IDR_TOOLBAR1);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);



	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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
			if (AfxMessageBox(_T("�������� �ʰ� �����Ͻðڽ��ϱ�?"), MB_ICONWARNING | MB_YESNO) == IDYES)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CwinSubProgramDlg::OnPaint()
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
HCURSOR CwinSubProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CwinSubProgramDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	m_toolbar->DestroyWindow();
	delete m_toolbar;
}



void CwinSubProgramDlg::OnFont()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�
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
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CFindDlg dlg;
	if (dlg.DoModal() == IDOK) {
		FINDTEXTEX ft;
		ft.chrg.cpMin = 0;
		ft.chrg.cpMax = -1;
		ft.lpstrText = m_search;
		long n = m_richEdit.FindText(FR_DOWN|FR_MATCHCASE|FR_WHOLEWORD, &ft);
		if (n == -1)
			AfxMessageBox(_T("ã�� �ܾ �����ϴ�."), MB_ICONERROR);
		else {
			m_richEdit.SetSel(ft.chrgText);
		}
	}
}


void CwinSubProgramDlg::OnTimer()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CTimerDlg dlg;
	dlg.DoModal();
}


void CwinSubProgramDlg::OnCopy()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_richEdit.Copy();
}


void CwinSubProgramDlg::OnPaste()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_richEdit.Paste();
}


void CwinSubProgramDlg::OnCut()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_richEdit.Cut();
}


void CwinSubProgramDlg::OnUndo()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_richEdit.Undo();
}


void CwinSubProgramDlg::OnStopwatch()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_alarmdlg = new CAlarmDlg;

	m_alarmdlg->Create(IDD_time_alarm);
	m_alarmdlg->m_spin1.SetRange(59, 0);
	m_alarmdlg->m_spin2.SetRange(59, 0);
	m_alarmdlg->m_spin3.SetRange(59, 0);
	m_alarmdlg->ShowWindow(SW_SHOW);
}
