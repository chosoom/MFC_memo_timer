// FindDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "winSubProgram.h"
#include "FindDlg.h"
#include "afxdialogex.h"

#include "winSubProgramDlg.h"
// CFindDlg ��ȭ �����Դϴ�.

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


// CFindDlg �޽��� ó�����Դϴ�.


void CFindDlg::OnBnClickedsearch()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CwinSubProgramDlg *pDlg = (CwinSubProgramDlg*)AfxGetMainWnd();
	GetDlgItemText(IDC_EDIT1, pDlg->m_search);
	CDialog::OnOK();
}
