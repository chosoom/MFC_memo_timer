// FindDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "winSubProgram.h"
#include "FindDlg.h"
#include "afxdialogex.h"

#include "winSubProgramDlg.h"
// CFindDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFindDlg, CDialog)

CFindDlg::CFindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_find, pParent)
{

}

CFindDlg::~CFindDlg()
{
}

void CFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFindDlg, CDialog)
	ON_BN_CLICKED(IDC_search, &CFindDlg::OnBnClickedsearch)
END_MESSAGE_MAP()


// CFindDlg 메시지 처리기입니다.


void CFindDlg::OnBnClickedsearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CwinSubProgramDlg *pDlg = (CwinSubProgramDlg*)AfxGetMainWnd();
	GetDlgItemText(IDC_EDIT1, pDlg->m_search);
	CDialog::OnOK();
}
