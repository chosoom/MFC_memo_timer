#pragma once


// CTimerDlg ��ȭ �����Դϴ�.

class CTimerDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimerDlg)

public:
	CTimerDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTimerDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TimeDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CString m_string;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
//	afx_msg void OnStnClickedstring2();
	CString m_string2;
};
