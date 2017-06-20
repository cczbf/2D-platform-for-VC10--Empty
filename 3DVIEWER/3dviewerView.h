
// 3dviewerView.h : CMy3dViewerView 类的接口
//

#pragma once

#include "CBmpDblBuffering.h"

class CMy3dViewerView : public CView
{
private:
    CBmpViewerData *GetBmpViewerData();

protected: // 仅从序列化创建
	CMy3dViewerView();
	DECLARE_DYNCREATE(CMy3dViewerView)

// 特性
public:
	CBmpDblBuffering* m_pCBmpDblBuf; 

// 操作
public:
	CMy3dViewerDoc* GetDocument() const;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy3dViewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
//	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//afx_msg void OnSize(UINT nType, int cx, int cy);
	//afx_msg void OnTimer(UINT nIDEvent);
	//afx_msg void OnMenuitem32792();
	//afx_msg void OnUpdateMenuitem32792(CCmdUI* pCmdUI);
	//afx_msg void OnMenuitem32791();
	//afx_msg void OnUpdateMenuitem32791(CCmdUI* pCmdUI);



	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 3dviewerView.cpp 中的调试版本
inline CMy3dViewerDoc* CMy3dViewerView::GetDocument() const
   { return reinterpret_cast<CMy3dViewerDoc*>(m_pDocument); }
#endif

