#pragma once


// CTimerDlg 대화 상자입니다.

class CTimerDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimerDlg)

public:
	CTimerDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTimerDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TimeDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CString m_string;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
//	afx_msg void OnStnClickedstring2();
	CString m_string2;
};
