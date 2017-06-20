// 3dviewerDoc.cpp : CMy3dViewerDoc 类的实现
//
 
#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的


// ATL 项目中进行定义，并允许与该项目共享文档代码。


#ifndef SHARED_HANDLERS
#include "3dviewer.h"
#endif

#include "3dviewerDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



#include "stdafx.h"
#include "3dViewer.h"

#include "3dViewerDoc.h"
#include "CGlobals.h"
#include "GraphicDialog.h"
#include "CFFT.h"
#include "CFWT.h"
//#include "COpenGL3DEx.h"
#include "CGlobals.h"

//#include "CMesh.h"
//#include "Mesh3D.h"
#include "CBmpViewerData.h"
//#include "COpenGL.h"
//#include "COpenGL3D.h"
//#include "CRelxationLabelling.h"

//#include "MeshForGeoImg.h"

//#include "DigitalGeometry.h"

//#include "Triangles.h"
#include "float.h"

//#include "MeshGlobal.h"

#include "io.h"

//#include "SubdivideMesh.h"

//#include "DlgSubdivideSetting.h"

#include "CDIBFlood.h"

struct SurfacePt
{
	double u,v;
	float r;
};



// CMy3dViewerDoc

IMPLEMENT_DYNCREATE(CMy3dViewerDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy3dViewerDoc, CDocument)
	ON_COMMAND(IDM_FILE_INFO, &CMy3dViewerDoc::OnFileInfo)
	ON_COMMAND(ID_EDIT_EQUALIZE, &CMy3dViewerDoc::OnEditEqualize)
	ON_COMMAND(ID_EDIT_UNDO, &CMy3dViewerDoc::OnEditUndo)
	ON_COMMAND(ID_EDIT_FourierTransform, &CMy3dViewerDoc::OnEditFouriertransform)
	ON_COMMAND(IDM_EDIT_FFT_PERIDOGRAM, &CMy3dViewerDoc::OnEditFftPeridogram)
	ON_COMMAND(IDM_EDIT_INVERSE, &CMy3dViewerDoc::OnEditInverse)
	ON_COMMAND(IDC_EDIT_GRAPHIC, &CMy3dViewerDoc::OnEditGraphic)
	ON_COMMAND(IDC_EDIT_FILTER, &CMy3dViewerDoc::OnEditFilter)
	ON_COMMAND(ID_EDIT_WaveletTransform, &CMy3dViewerDoc::OnEditWavelettransform)
	ON_COMMAND(ID_EDIT_InverseWaveletTransform, &CMy3dViewerDoc::OnEditInversewavelettransform)
	ON_COMMAND(IDM_EDIT_DAUB4, &CMy3dViewerDoc::OnEditDaub4)
	ON_COMMAND(IDM_EDIT_DAUB12, &CMy3dViewerDoc::OnEditDaub12)
	ON_COMMAND(IDM_EDIT_DAUB20, &CMy3dViewerDoc::OnEditDaub20)
	ON_COMMAND(ID_EDIT_InverseFourierTransform, &CMy3dViewerDoc::OnEditInverseFourierTransform)
	ON_COMMAND(ID_EDIT_REMOVE_COLOR, &CMy3dViewerDoc::OnEditRemoveColor )
	ON_COMMAND(ID_32830, &CMy3dViewerDoc::On32830)
	ON_COMMAND(ID_EDIT_RESIZE, &CMy3dViewerDoc::OnEditResize)
END_MESSAGE_MAP()


// CMy3dViewerDoc 构造/析构

CMy3dViewerDoc::CMy3dViewerDoc()
	{
	// TODO: add one-time construction code here

	m_CBmpViewerData = new CBmpViewerData;
	g_CGlobals.set_m_pCBmpviewerDoc((CMy3dViewerDoc*)this);

	//	m_pCOpenGL = (COpenGL*)new COpenGL3DEx;

	//m_pMesh[0] = new CMesh;
	//m_pMesh[1] = new CMesh;

	//m_nCurrentMeshIndex = 0;

	m_strFileName = " ";

	m_bIsNew = FALSE;

	m_bIsShow3DDepth = FALSE;

	m_strTitle[0] = " New !";
	m_strTitle[1] = " New !";

//	m_pMeshForGeoImg = NULL;
//	m_pCurrent2DMesh = NULL;
//	m_pCRelxationLabelling = NULL;
	
	
}



CMy3dViewerDoc::~CMy3dViewerDoc()
{
		if ( m_CBmpViewerData != NULL )
		{
			delete m_CBmpViewerData;
			m_CBmpViewerData = NULL;
		}
//	if(pScreenDatas)
//		delete pScreenDatas;
#ifdef For3D
		if ( m_pCOpenGL != NULL )
		{
			delete m_pCOpenGL;
			this->m_pCOpenGL = NULL;
		}
		if (m_pMesh != NULL)
		{
			delete m_pMesh[0];
			delete m_pMesh[1];
		}
		
		if(m_pMeshForGeoImg != NULL)
			delete m_pMeshForGeoImg;

		if(m_pCRelxationLabelling != NULL)
			delete m_pCRelxationLabelling;
#endif
}

BOOL CMy3dViewerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码


	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMy3dViewerDoc 序列化



void CMy3dViewerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMy3dViewerDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持


void CMy3dViewerDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。


	// 内容部分应由“;”分隔



	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；


	SetSearchContent(strSearchContent);
}

void CMy3dViewerDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy3dViewerDoc 诊断

#ifdef _DEBUG
void CMy3dViewerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy3dViewerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy3dViewerDoc 命令

BOOL CMy3dViewerDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
    //if (!CDocument::OnOpenDocument(lpszPathName))
	//	return FALSE;
	
	// TODO: Add your specialized creation code here
	HANDLE hDib;
	hDib = m_CDIB.OpenDIB((LPSTR)lpszPathName);

	int w,h;
	HANDLE hDib0 = m_CDIB.CopyDib(hDib);
	HANDLE hRaw = m_CDIB.Dib2BWRaw8(hDib0,&w,&h);//hDib0 is freed in this call
/*
	//m_bIsShow3DDepth = true;
	if (m_bIsShow3DDepth)
	{	
		if(m_pMesh[m_nCurrentMeshIndex] != NULL)
			delete m_pMesh[m_nCurrentMeshIndex];
		
		m_pMesh[m_nCurrentMeshIndex] = new CMesh;

		((COpenGL3DEx *)(m_pCOpenGL))->m_pCMesh = m_pMesh[m_nCurrentMeshIndex]; 
		((COpenGL3DEx *)(m_pCOpenGL))->m_pCMesh->m_nType = 0;
		
		((COpenGL3DEx *)(this->m_pCOpenGL))->m_pCMesh->LoadFromRaw(hRaw, w, h);
		((COpenGL3DEx *)(this->m_pCOpenGL))->m_pCMesh->Normalize(0.5f);
		GlobalFree ( hRaw );
		
		m_nCurrentMeshIndex = (m_nCurrentMeshIndex + 1) % 2;

		// Borrowing the following functions to initize the COpenGL
		hRaw = GlobalAlloc(GHND, 4*sizeof(BYTE));
		((COpenGL3DEx *)(this->m_pCOpenGL))->Load3DData(hRaw, 2, 2, 0.0, 0.0, 0.0, 0.0);
		GlobalFree ( hRaw );		
	}
	*/
	if ( hDib != NULL )
	{
		m_CBmpViewerData->SetNewPosition();
		m_CBmpViewerData->SetDIBHandle(hDib);
		//m_CDIBOrg.FreeDib();
		this->UpdateView();
		this->SetPathName(lpszPathName);
	}
	
	CMainFrame* pMainFrame	= (CMainFrame*)AfxGetMainWnd( );
//	pMainFrame->Set2DView();

	return TRUE;

}


BOOL CMy3dViewerDoc::UpdateView ()
{
// This example uses CDocument::GetFirstViewPosition
// and GetNextView to repaint each view.void CMyDoc::OnRepaintAllViews()
   POSITION pos = GetFirstViewPosition();
   BOOL bRet	= FALSE;
   while (pos != NULL)
   {
      CView* pView = GetNextView(pos);
	  pView->Invalidate(FALSE);
	  pView->UpdateWindow();
	  bRet	= TRUE;
   }
   //   g_CGlobals.m_pCMainFrame->SetFocus();
   return bRet;
}


void CMy3dViewerDoc::OnFileInfo()
{
	// TODO: 在此添加命令处理程序代码
		HANDLE	hDib0	= m_CBmpViewerData->GetDIBHandle();
		CString	CStr;

		WORD nW		= m_CDIB.DIBWidth(hDib0);
		WORD nH		= m_CDIB.DIBHeight(hDib0);
		
		CStr.Format("Width:%d\r\nHeight:%d", nW,nH );
		AfxGetMainWnd()->MessageBox(CStr, "图像信息", MB_OK);
}


void CMy3dViewerDoc::OnEditEqualize()
{
	// TODO: Add your command handler code here
		HANDLE	hDib0	= m_CBmpViewerData->GetDIBHandle();

		DWORD	pdwHistoR[256],	pdwHistoG[256],	pdwHistoB[256];
		BYTE	pbHEqMapR[256],	pbHEqMapG[256],	pbHEqMapB[256];

		WORD nW = m_CDIB.DIBWidth(hDib0);
		WORD nH = m_CDIB.DIBHeight(hDib0);

		m_CDIB.Histogram( hDib0, pdwHistoR, pdwHistoG, pdwHistoB);
		m_CDIB.HistogramEqualization(pdwHistoR, pbHEqMapR, nW, nH);
		m_CDIB.HistogramEqualization(pdwHistoG, pbHEqMapG, nW, nH);
		m_CDIB.HistogramEqualization(pdwHistoB, pbHEqMapB, nW, nH);

		HANDLE	hDib1	= m_CDIB.CopyDib(hDib0);

		m_CDIB.DIBCurveMapping(hDib1, hDib0, pbHEqMapR, pbHEqMapG, pbHEqMapB);

		m_CBmpViewerData->SetDIBHandle(NULL);// call this function with NULL to delete hDib0
		hDib0 = NULL;

		m_CBmpViewerData->SetDIBHandle(hDib1);

		this->UpdateView();	
}

void CMy3dViewerDoc::OnEditUndo()
{
	// TODO: Add your command handler code here

	int nToolID = 0;

	if (g_CGlobals.m_pCMainFrame->m_pCToolBase != NULL)
		nToolID = g_CGlobals.m_pCMainFrame->m_pCToolBase->get_m_nToolID();
	
	if( nToolID != 3)
	{
		m_CBmpViewerData->Undo();// call this function with NULL to delete hDib0
	}
	else
	{	
	#ifdef For3D
		((COpenGL3DEx *)(m_pCOpenGL))->m_pCMesh = (m_pMesh[m_nCurrentMeshIndex] ); 
		m_nCurrentMeshIndex = (m_nCurrentMeshIndex + 1)%2;
        
		if(g_CGlobals.m_pDlgTab02 != NULL)
			g_CGlobals.m_pDlgTab02->Invalidate();		
	#endif For3D
	}

	this->UpdateView();		
}

void CMy3dViewerDoc::OnEditFouriertransform()
{
	// TODO: Add your command handler code here
	//	CFFT CFFT;
	#define CFFT (g_CGlobals.m_CFFT)

	HANDLE hDib = this->m_CBmpViewerData->GetDIBHandle();

//	_int32 nW, nH;
	int nW, nH;

	HANDLE hRaw = this->m_CDIB.Dib2BWRaw16(hDib, &nW, &nH);
	
	CRawImage16 CRawImage16;

	CRawImage16.Copy (hRaw, nW, nH);

	CFFT.SetWorkingImage(&CRawImage16);
	g_CGlobals.SetMeanGrayBeforeFFT (CFFT.MeanGrayOf_image());
	CFFT.FFT2D();
	CFFT.CopyMagnitude();
//	CFFT.CopyPeridogram();

	this->TransferByBuffer(
				CRawImage16.m_hPixels,
				CRawImage16.m_nWidth,
				CRawImage16.m_nHeight,
				0,0,0,0
		);

	CFFT.SetWorkingImage(NULL);	
    
	#undef CFFT
}


void CMy3dViewerDoc::TransferByBuffer(HANDLE hHtArray,
									 DWORD dwWidth, 
									 DWORD dwHeight,
									 DWORD dwScaleX,
									 DWORD dwScaleY,
									 DWORD dwLevels,
									 DWORD dwLimitLevels
									 )
{
	
	HANDLE hDib;
	m_CDIB.set_m_dwWidth(dwWidth); 
    m_CDIB.set_m_dwHeight(dwHeight);
	m_CDIB.set_m_dwScaleX(dwScaleX);
	m_CDIB.set_m_dwScaleY(dwScaleY);
	m_CDIB.set_m_dwLevels(dwLevels);
	m_CDIB.set_m_dwLimitLevels(dwLimitLevels);

	hDib = m_CDIB.HtArray2Dib(hHtArray);
	if ( hDib != NULL )
	{
		m_CBmpViewerData->SetDIBHandle(hDib);
		//m_CDIBOrg.FreeDib();
		this->UpdateView();
	}
	
//	GenerateMeshFromImg();
}



void CMy3dViewerDoc::OnEditFftPeridogram()
{
	// TODO: Add your command handler code here
	CFFT CFFT;
	HANDLE hDib = this->m_CBmpViewerData->GetDIBHandle();

//	_int32 nW, nH;
	int nW, nH;

	HANDLE hRaw = this->m_CDIB.Dib2BWRaw16(hDib, &nW, &nH);
	
	CRawImage16 CRawImage16;

	CRawImage16.Copy (hRaw, nW, nH);

	CFFT.SetWorkingImage(&CRawImage16);
	g_CGlobals.SetMeanGrayBeforeFFT (CFFT.MeanGrayOf_image());
	CFFT.FFT2D();
//	CFFT.CopyMagnitude();
	CFFT.CopyPeridogram();
	this->TransferByBuffer(
				CRawImage16.m_hPixels,
				CRawImage16.m_nWidth,
				CRawImage16.m_nHeight,
				0,0,0,0
		);

	CFFT.SetWorkingImage(NULL);
		
}


void CMy3dViewerDoc::OnEditInverse()
{
	// TODO: Add your command handler code here
	    HANDLE	hDib0	= m_CBmpViewerData->GetDIBHandle();

		BYTE	pbMap[256];
		for ( int i = 0; i < 256; i++ )
			pbMap[i]	= 255- i;

		HANDLE	hDib1	= m_CDIB.CopyDib(hDib0);

		m_CDIB.DIBCurveMapping(hDib1, hDib0, pbMap);

		m_CBmpViewerData->SetDIBHandle(NULL);// call this function with NULL to delete hDib0
		hDib0 = NULL;
		
		m_CBmpViewerData->SetDIBHandle(hDib1);


	#ifdef For3D
		GenerateMeshFromImg();
    #endif
		this->UpdateView();	
}


void CMy3dViewerDoc::OnEditGraphic()
{
	// TODO: Add your command handler code here
	CGraphicDialog dlg ;
	dlg.DoModal() ;
}

void CMy3dViewerDoc::OnEditFilter()
{
	// TODO: Add your command handler code here

    HANDLE	hSrcDib	= m_CBmpViewerData->GetDIBHandle();
	HANDLE	hDstDib	= m_CDIB.CopyDib(hSrcDib);

	double * hMap = (double *) new BYTE[5 * 5 * sizeof(double)] ;

	double dF[5], dFt[5] ;
	dF[0] = dFt[0] = 1.0 / 24.0 ;
	dF[1] = dFt[1] = 5.0 / 24.0 ;
	dF[2] = dFt[2] = 12.0 / 24.0 ;
	dF[3] = dFt[3] = 5.0 / 24.0 ;
	dF[4] = dFt[4] = 1.0 / 24.0 ;

	for(int i = 0 ; i < 5 ; i ++)
	{
		for(int j = 0 ; j < 5 ; j ++)
			hMap[i * 5 + j] = dF[i] * dFt[j] ;
	}
	m_CDIB.LowFilterDib(hDstDib, hSrcDib,hMap) ;

	m_CBmpViewerData->SetDIBHandle(NULL);// call this function with NULL to delete hSrcDib
	hSrcDib = NULL;
		
	m_CBmpViewerData->SetDIBHandle(hDstDib);

	#ifdef For3D
	GenerateMeshFromImg();
    #endif
	this->UpdateView();
	
	delete hMap;
}


void CMy3dViewerDoc::OnEditWavelettransform()
{
	// TODO: Add your command handler code here
	
	CFWT CFWT(g_CGlobals.m_CTransformedImage.m_nTransformFilterID);
	HANDLE hDib = this->m_CBmpViewerData->GetDIBHandle();

	int nW, nH;

	HANDLE hRaw = this->m_CDIB.Dib2BWRaw16(hDib, &nW, &nH);
	
	CRawImage16 CRawImage16;

	CRawImage16.Copy (hRaw, nW, nH);
	CRawImage16.ExpandToPowerOf2Dim((unsigned __int32*)&nW, (unsigned __int32*)&nH);

	CFWT.SetWorkingImage(&CRawImage16);

	CFWT.FWT2D();
	CFWT.CopyWT();//Format the result and copy to CRawImage buffer

	long nM,nN;

	float *zr = CFWT.GetWTReal(&nM,&nN);
	g_CGlobals.m_CTransformedImage.SetData(zr,(__int32)nW, (__int32)nH);//Store the transform for reconstruct

	this->TransferByBuffer(
				CRawImage16.m_hPixels,
				CRawImage16.m_nWidth,
				CRawImage16.m_nHeight,
				0,0,0,0
		);

	CFWT.SetWorkingImage(NULL);

}


void CMy3dViewerDoc::OnEditInversewavelettransform()
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here

	CFWT CFWT(g_CGlobals.m_CTransformedImage.m_nTransformFilterID);
	HANDLE hDib = this->m_CBmpViewerData->GetDIBHandle();

	int nW, nH;

	HANDLE hRaw = this->m_CDIB.Dib2BWRaw16(hDib, &nW, &nH);
	
	CRawImage16 CRawImage16;

	CRawImage16.Copy (hRaw, nW, nH);

	CFWT.SetWorkingImage(&CRawImage16);
	
	_int32 nW1, nH1;

	float *lpData =
	g_CGlobals.m_CTransformedImage.GetData(&nW1, &nH1);

	CFWT.SetReal4Transform(lpData, nW1, nH1);
	CFWT.IFWT2D();
	CFWT.CopyWT(FALSE);//Not visualize the result in decibel(·Ö±´) Format the result and copy to CRawImage buffer
//	CFFT.CopyPeridogram();

	this->TransferByBuffer(
				CRawImage16.m_hPixels,
				CRawImage16.m_nWidth,
				CRawImage16.m_nHeight,
				0,0,0,0
		);

	CFWT.SetWorkingImage(NULL);
	
	
}


void CMy3dViewerDoc::OnEditDaub12() 
{
	// TODO: Add your command handler code here
g_CGlobals.m_CTransformedImage.m_nTransformFilterID	= 2;	
}

void CMy3dViewerDoc::OnEditDaub20() 
{
	// TODO: Add your command handler code here
	g_CGlobals.m_CTransformedImage.m_nTransformFilterID	= 3;
}

void CMy3dViewerDoc::OnEditDaub4() 
{
	// TODO: Add your command handler code here
g_CGlobals.m_CTransformedImage.m_nTransformFilterID	= 0;	
}


void CMy3dViewerDoc::OnEditInverseFourierTransform()
{
	// TODO: Add your command handler code here
 //	CFFT CFFT;
#define CFFT g_CGlobals.m_CFFT

	HANDLE hDib = this->m_CBmpViewerData->GetDIBHandle();
	if ( hDib == NULL ) return;
	if( CFFT.zr== NULL ) return;
	if( CFFT.zi== NULL ) return;

//	_int32 nW, nH;
	int nW, nH;

 	HANDLE hRaw = this->m_CDIB.Dib2BWRaw16(hDib, &nW, &nH);
	
	CRawImage16 CRawImage16;

	CRawImage16.Copy (hRaw, nW, nH);

	CFFT.SetWorkingImage(&CRawImage16);
	g_CGlobals.SetMeanGrayBeforeFFT (CFFT.MeanGrayOf_image());
	CFFT.IFFT2D();
	CFFT.CopyMagnitude();
//	CFFT.CopyPeridogram();

	this->TransferByBuffer(
				CRawImage16.m_hPixels,
				CRawImage16.m_nWidth,
				CRawImage16.m_nHeight,
				0,0,0,0
		);

	CFFT.SetWorkingImage(NULL);	
#undef  CFFT 
}
 
BOOL CMy3dViewerDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
		// TODO: Add your specialized code here and/or call the base class
	HANDLE hDib	= m_CBmpViewerData->GetDIBHandle ();
	if ( hDib != NULL )
	{
		if (strstr(lpszPathName, ".bmp"))
		{
		  m_CDIB.WriteDIB((LPSTR)lpszPathName, hDib);
		  return TRUE;
		}
		#ifdef For3D
		else
			if (strstr(lpszPathName, ".ply"))
			{
				((COpenGL3DEx *)(this->m_pCOpenGL))->m_pCMesh->Write(lpszPathName);
			}
			else
		{
			MessageBeep(MB_ICONASTERISK);
			return FALSE;
		}
      #endif
	}
	#ifdef For3D
	else
	{
		((COpenGL3DEx *)(this->m_pCOpenGL))->m_pCMesh->Write(lpszPathName);
	}
	#endif For3D

	
	//	return CDocument::OnSaveDocument(lpszPathName);
	return FALSE;	
}
 
 


void CMy3dViewerDoc::OnEditRemoveColor()
{
	// TODO: Add your command handler code here
	    HANDLE	hDib0	= m_CBmpViewerData->GetDIBHandle();

		HANDLE	hDib1	= m_CDIB.CopyDib(hDib0);

		m_CDIB.ColorDibToBWDib(hDib1, hDib0);
		m_CBmpViewerData->SetDIBHandle(NULL);// call this function with NULL to delete hDib0
		hDib0 = NULL;
		
		m_CBmpViewerData->SetDIBHandle(hDib1);


	#ifdef For3D
		GenerateMeshFromImg();
    #endif
		this->UpdateView();	
}





void CMy3dViewerDoc::On32830()
{
	// TODO: 在此添加命令处理程序代码
}


void CMy3dViewerDoc::OnEditResize()
{
	// TODO: Add your command handler code here
 
	CMy3dViewerDoc*		pDoc	= g_CGlobals.get_m_pCBmpviewerDoc(); 
	POSITION					POS		= pDoc->GetFirstViewPosition ();
	CView*							pView	= pDoc->GetNextView(POS);
	CDC* 							pDC		= pView->GetDC();
	HDC								hDC		= pDC->m_hDC;
	
	int h0	=	(pDoc->m_CBmpViewerData)->get_m_h0();
//	int h1	=	(pDoc->m_CBmpViewerData)->get_m_h1();
	int w0	=	(pDoc->m_CBmpViewerData)->get_m_w0();
//	int w1	=	(pDoc->m_CBmpViewerData)->get_m_w1();

	int x0	=	(pDoc->m_CBmpViewerData)->get_m_x0();
//	int x1	=	(pDoc->m_CBmpViewerData)->get_m_x1();
	int y0	=	(pDoc->m_CBmpViewerData)->get_m_y0();
//	int y1	=	(pDoc->m_CBmpViewerData)->get_m_y1();


 	//if (g_CGlobals.m_hSrcDIB !=NULL)
	//	GlobalFree(g_CGlobals.m_hSrcDIB);

    //HANDLE	hSrcDib	= m_CBmpViewerData->GetDIBHandle();
	//HANDLE	hDstDib	= m_CDIB.CopyDib(hSrcDib);
	
	HANDLE	hSrcDib	= ((CDIB)(pDoc->m_CDIB)).DibFromDC(hDC,x0, y0, w0, h0);	
	HANDLE	hDstDib	= m_CDIB.CopyDib(hSrcDib);

	m_CBmpViewerData->SetDIBHandle(NULL);// call this function with NULL to delete Dib-in-display.
		
	m_CBmpViewerData->SetDIBHandle(hDstDib);
	this->UpdateView();

}
