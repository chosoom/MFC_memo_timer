// TimerDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "winSubProgram.h"
#include "TimerDlg.h"
#include "afxdialogex.h"


// CTimerDlg 대화 상자입니다.

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


// CTimerDlg 메시지 처리기입니다.


int CTimerDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetTimer(0, 1000, NULL);

	return 0;
}


void CTimerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 0) {
		CTime t;
		t = CTime::GetCurrentTime();
		CString str;
		UpdateData(true);
		str.Format(_T("%d년 %d월 %d일"), t.GetYear(), t.GetMonth(), t.GetHour());
		m_string2 = str;
		str.Format(_T("현재 시각 : %d : %d : %d"), t.GetHour(), t.GetMinute(), t.GetSecond());
		m_string = str;
		UpdateData(false);
	}
	CDialog::OnTimer(nIDEvent);
}


void CTimerDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	KillTimer(0);
}

