#pragma once
#include "afxcmn.h"


// CAlarmDlg ��ȭ �����Դϴ�.

class CAlarmDlg : public CDialog
{
	DECLARE_DYNAMIC(CAlarmDlg)

public:
	CAlarmDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAlarmDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_time_alarm };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	UINT m_hour;
	UINT m_minute;
	UINT m_second;
	afx_msg void OnClickedSetting();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString m_remain_time;
	afx_msg void OnDeltaposSpin3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult);

//	afx_msg void OnUpdateUIState(UINT /*nAction*/, UINT /*nUIElement*/);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CSpinButtonCtrl m_spin1;
	CSpinButtonCtrl m_spin2;
	CSpinButtonCtrl m_spin3;
};
