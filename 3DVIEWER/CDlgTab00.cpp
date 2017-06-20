// CDlgTab00.cpp : implementation file
//

#include "stdafx.h"
#include "3dViewer.h"
#include "CDlgTab00.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgTab00 dialog


CDlgTab00::CDlgTab00(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgTab00::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgTab00)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgTab00::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgTab00)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgTab00, CDialog)
	//{{AFX_MSG_MAP(CDlgTab00)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgTab00 message handlers

void CDlgTab00::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CDlgTab00::OnCancel() 
{
	// TODO: Add extra cleanup here
	
//	CDialog::OnCancel();
}
