#if !defined(AFX_DLGTAB01_H__56068F1D_ACEC_4DC3_9A48_DD5C8F447C39__INCLUDED_)
#define AFX_DLGTAB01_H__56068F1D_ACEC_4DC3_9A48_DD5C8F447C39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgTab01.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgTab01 dialo
#include "resource.h"
//##ModelId=40D000EB021D
class CDlgTab01 : public CDialog
{
// Construction
public:
	//##ModelId=40D000EB0229
	CDlgTab01(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgTab01)
	enum { IDD = IDD_TAB_DIALOG01 };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgTab01)
	protected:
	//##ModelId=40D000EB0227
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgTab01)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTAB01_H__56068F1D_ACEC_4DC3_9A48_DD5C8F447C39__INCLUDED_)
