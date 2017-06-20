#if !defined(AFX_CDLGTAB02_H__8DB50534_1751_4241_8694_2CB3838F8697__INCLUDED_)
#define AFX_CDLGTAB02_H__8DB50534_1751_4241_8694_2CB3838F8697__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDlgTab02.h : header file
//
#include "resource.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgTab02 dialog

//##ModelId=40D2E34D034D
class CDlgTab02 : public CDialog
{
// Construction
public:
	//##ModelId=40D2E34D0358
	CDlgTab02(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgTab02)
	enum { IDD = IDD_TAB_DIALOG02 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgTab02)
	protected:
	//##ModelId=40D2E34D0356
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgTab02)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDLGTAB02_H__8DB50534_1751_4241_8694_2CB3838F8697__INCLUDED_)
