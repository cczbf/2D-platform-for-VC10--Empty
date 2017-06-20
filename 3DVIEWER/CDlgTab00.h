#if !defined(AFX_CDLGTAB00_H__325263A9_CFAC_46A0_AC45_D5EBB1073A67__INCLUDED_)
#define AFX_CDLGTAB00_H__325263A9_CFAC_46A0_AC45_D5EBB1073A67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CDlgTab00.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgTab00 dialog

//##ModelId=40D515590340
class CDlgTab00 : public CDialog
{
// Construction
public:
	//##ModelId=40D51559034A
	CDlgTab00(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgTab00)
	enum { IDD = IDD_TAB_DIALOG00 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgTab00)
	protected:
	//##ModelId=40D515590348
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgTab00)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CDLGTAB00_H__325263A9_CFAC_46A0_AC45_D5EBB1073A67__INCLUDED_)
