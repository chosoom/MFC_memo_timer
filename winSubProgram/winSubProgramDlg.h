
// winSubProgramDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "AlarmDlg.h"

// CwinSubProgramDlg ��ȭ ����
class CwinSubProgramDlg : public CDialogEx
{
private:
	CToolBar *m_toolbar;
// �����Դϴ�.
public:
	CwinSubProgramDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WINSUBPROGRAM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnFont();
	CRichEditCtrl m_richEdit;
	afx_msg void OnSavefile();
	afx_msg void OnOpenfile();
	afx_msg void OnFind();
	bool m_save;
	afx_msg void OnTimer();
	CString m_search;
	afx_msg void OnCopy();
	afx_msg void OnPaste();
	afx_msg void OnCut();
	afx_msg void OnUndo();
	afx_msg void OnStopwatch();
	CAlarmDlg *m_alarmdlg;
};
