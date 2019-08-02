// AlarmDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "winSubProgram.h"
#include "AlarmDlg.h"
#include "afxdialogex.h"


// CAlarmDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CAlarmDlg, CDialog)

CAlarmDlg::CAlarmDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_time_alarm, pParent)
	, m_hour(0)
	, m_minute(0)
	, m_second(0)
	, m_remain_time(_T(""))
{
}

CAlarmDlg::~CAlarmDlg()
{
}

void CAlarmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_remain_time, m_remain_time);
	DDX_Control(pDX, IDC_SPIN1, m_spin1);
	DDX_Control(pDX, IDC_SPIN2, m_spin2);
	DDX_Control(pDX, IDC_SPIN3, m_spin3);
}


BEGIN_MESSAGE_MAP(CAlarmDlg, CDialog)
	ON_BN_CLICKED(IDC_setting, &CAlarmDlg::OnClickedSetting)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN3, &CAlarmDlg::OnDeltaposSpin3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CAlarmDlg::OnDeltaposSpin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, &CAlarmDlg::OnDeltaposSpin2)
//	ON_WM_UPDATEUISTATE()
ON_WM_CREATE()
END_MESSAGE_MAP()


// CAlarmDlg 메시지 처리기입니다.


void CAlarmDlg::OnClickedSetting()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	m_hour = GetDlgItemInt(IDC_hour);
	m_minute = GetDlgItemInt(IDC_minute);
	m_second = GetDlgItemInt(IDC_second);
	UpdateData(TRUE);

	if((m_hour !=0) || (m_minute!=0) || (m_second!=0)){
		SetTimer(1, 1000, NULL);
		m_remain_time.Format(_T("%d : %d : %d"), m_hour, m_minute, m_second);
	}
	else {
		AfxMessageBox(_T("시간을 설정해주세요!"));
	}
	UpdateData(FALSE);
	ShowWindow(SW_HIDE);
}


void CAlarmDlg::OnDestroy()
{
	CDialog::OnDestroy();
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	KillTimer(1);
}


void CAlarmDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 1) {
		if (m_hour <= 0 && m_minute <= 0 && m_second <= 0) {
			KillTimer(1);
			ShowWindow(SW_SHOW);
			return;
		}
		m_second--;
		if (m_second < 0 && (m_minute != 0 || m_hour != 0)) {
			m_second = 60;
			m_minute--;
			if (m_minute < 0 && m_hour != 0) {
				m_minute = 60;
				m_hour--;
			}
		}
		UpdateData(TRUE);
		m_remain_time.Format(_T("%d : %d : %d"), m_hour, m_minute, m_second);
		UpdateData(FALSE);
	}
	CDialog::OnTimer(nIDEvent);
}


void CAlarmDlg::OnDeltaposSpin3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pNMUpDown->iDelta = -pNMUpDown->iDelta;
	*pResult = 0;
}


void CAlarmDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pNMUpDown->iDelta = -pNMUpDown->iDelta;
	if (pNMUpDown->iDelta < 0)
		SetDlgItemInt(IDC_hour,59);
	else if(pNMUpDown->iDelta > 60)
		SetDlgItemInt(IDC_hour, 0);
	*pResult = 0;
}


void CAlarmDlg::OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pNMUpDown->iDelta = -pNMUpDown->iDelta;
	*pResult = 0;
}



int CAlarmDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.


	return 0;
}
