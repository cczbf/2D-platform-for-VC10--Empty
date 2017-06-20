// DlgTab01.cpp : implementation file
//

#include "stdafx.h"
#include "3dViewer.h"
#include "resource.h"
#include "CDlgTab01.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgTab01 dialog


CDlgTab01::CDlgTab01(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgTab01::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgTab01)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgTab01::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgTab01)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgTab01, CDialog)
	//{{AFX_MSG_MAP(CDlgTab01)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgTab01 message handlers

void CDlgTab01::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CDlgTab01::OnCancel() 
{
	// TODO: Add extra cleanup here
	
//	CDialog::OnCancel();
}
