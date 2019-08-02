
// winSubProgramDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include "AlarmDlg.h"

// CwinSubProgramDlg 대화 상자
class CwinSubProgramDlg : public CDialogEx
{
private:
	CToolBar *m_toolbar;
// 생성입니다.
public:
	CwinSubProgramDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WINSUBPROGRAM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
