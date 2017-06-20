// CDlgTab02.cpp : implementation file
//

#include "stdafx.h"
#include "3dViewer.h"
#include "CDlgTab02.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgTab02 dialog


CDlgTab02::CDlgTab02(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgTab02::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgTab02)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgTab02::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgTab02)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgTab02, CDialog)
	//{{AFX_MSG_MAP(CDlgTab02)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgTab02 message handlers

void CDlgTab02::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CDlgTab02::OnCancel() 
{
	// TODO: Add extra cleanup here
	
//	CDialog::OnCancel();
}
