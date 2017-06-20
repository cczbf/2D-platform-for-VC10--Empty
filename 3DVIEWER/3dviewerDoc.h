
// 3dviewerDoc.h : CMy3dViewerDoc 类的接口
//


#pragma once


#include "cdiborg.h"
#include "CHtArray2Dib.h"



class CMesh;
class C2DMesh;
class CMeshForGeoImg;
class CRelxationLabelling;
class CBmpViewerData;
class COpenGL;

struct STATISTIC
{
	CString strAverageOfStretchRatio ;
	CString strCoviarianceOfStretchRatio;		
	CString strGeoRatio ;	
};


class CMy3dViewerDoc : public CDocument
{
protected: // 仅从序列化创建
	CMy3dViewerDoc();
	DECLARE_DYNCREATE(CMy3dViewerDoc)
	 
// Attributes
public:
	 CBmpViewerData		*m_CBmpViewerData;
     CHtArray2Dib				m_CDIB;
	 CDIBOrg						m_CDIBOrg;
/*
     CMesh						*m_pMesh[2];
	 int								m_nCurrentMeshIndex;
	*/ // removed zbf20160329
	STATISTIC					m_struStatistic[2];
	 bool								m_bIsNew;

 	 //static CRelxationLabelling *m_pCRelxationLabelling;
     
	 //CMeshForGeoImg		*m_pMeshForGeoImg; // removed zbf20160329
   	 //C2DMesh					*m_pCurrent2DMesh;       // removed zbf20160329
	 	 
	 //bool         m_bIsOpen3DModel;

	 //
	 CString						m_strTitle[2]; //save the two buffer title
	 CString						m_strFileName; //save the current file name
	 //CString          m_strLabelName;

	 //added by xdh,
	 //to control the switch between 2D image and 3d mesh
	 bool								m_bIsShow3DDepth;
	 //bool m_bIsCapture;

//	 	COpenGL				*m_pCOpenGL; //removed zbf20160329
	 


// 操作
public:

      BOOL	UpdateView ();
	 
	  void		TransferByBuffer(HANDLE hHtArray,
												DWORD dwWidth, 
												DWORD dwHeight,
												DWORD dwScaleX,
												DWORD dwScaleY,
												DWORD dwLevels,
												DWORD dwLimitLevels
						);


// 重写
public:
	virtual BOOL		OnNewDocument();
	virtual void			Serialize(CArchive& ar);
	BOOL					OnOpenDocument(LPCTSTR lpszPathName);
	BOOL					OnSaveDocument(LPCTSTR lpszPathName);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMy3dViewerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFileInfo();
	afx_msg void OnEditEqualize();
	afx_msg void OnEditUndo();
	afx_msg void OnEditFouriertransform();
	afx_msg void OnEditFftPeridogram();
	afx_msg void OnEditInverse();
	afx_msg void OnEditGraphic();
	afx_msg void OnEditFilter();
	afx_msg void OnEditWavelettransform();
	afx_msg void OnEditInversewavelettransform();
	afx_msg void OnEditDaub4();
	afx_msg void OnEditDaub12();
	afx_msg void OnEditDaub20();
	afx_msg void OnEditInverseFourierTransform();
	afx_msg void OnEditRemoveColor();
	afx_msg void On32830();
	afx_msg void OnEditResize();
};
