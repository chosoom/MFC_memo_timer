// TimerDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "winSubProgram.h"
#include "TimerDlg.h"
#include "afxdialogex.h"


// CTimerDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTimerDlg, CDialog)

CTimerDlg::CTimerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TimeDlg, pParent)
	, m_string(_T(""))
	, m_string2(_T(""))
{

}

CTimerDlg::~CTimerDlg()
{
}

void CTimerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_string, m_string);
	DDX_Text(pDX, IDC_string2, m_string2);
}


BEGIN_MESSAGE_MAP(CTimerDlg, CDialog)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CTimerDlg �޽��� ó�����Դϴ�.


int CTimerDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetTimer(0, 1000, NULL);

	return 0;
}


void CTimerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nIDEvent == 0) {
		CTime t;
		t = CTime::GetCurrentTime();
		CString str;
		UpdateData(true);
		str.Format(_T("%d�� %d�� %d��"), t.GetYear(), t.GetMonth(), t.GetHour());
		m_string2 = str;
		str.Format(_T("���� �ð� : %d : %d : %d"), t.GetHour(), t.GetMinute(), t.GetSecond());
		m_string = str;
		UpdateData(false);
	}
	CDialog::OnTimer(nIDEvent);
}


void CTimerDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	KillTimer(0);
}

