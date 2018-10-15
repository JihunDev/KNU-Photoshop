// ImageToolDoc.cpp : CImageToolDoc 클래스의 구현
//

#include "stdafx.h"
#include "ImageTool.h"
#include "FileNewDlg.h"
#include "ImageToolDoc.h"

#include "Dib.h"
#include "DibEnhancement.h"

#include "BrightnessDlg.h"
#include "ContrastDlg.h"
#include "GammaCorrectionDlg.h"
#include "HistogramDlg.h"
#include "ArithmeticDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageToolDoc

IMPLEMENT_DYNCREATE(CImageToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageToolDoc, CDocument)
	ON_COMMAND(ID_WINDOW_DUPLICATE, &CImageToolDoc::OnWindowDuplicate)
	ON_COMMAND(ID_EDIT_COPY, &CImageToolDoc::OnEditCopy)
	ON_COMMAND(ID_IMAGE_INVERSE, &CImageToolDoc::OnImageInverse)
	ON_COMMAND(ID_IMAGE_BRIGHTNESS, &CImageToolDoc::OnImageBrightness)
	ON_COMMAND(ID_IMAGE_CONTRAST, &CImageToolDoc::OnImageContrast)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CImageToolDoc::OnGammaCorrection)
	ON_COMMAND(ID_VIEW_HISTOGRAM, &CImageToolDoc::OnViewHistogram)
	ON_COMMAND(ID_HISTO_EQUALIZE, &CImageToolDoc::OnHistoEqualize)
	ON_COMMAND(ID_IMAGE_ARITHMETIC, &CImageToolDoc::OnImageArithmetic)
	ON_COMMAND(ID_BITPLANE_SLICING, &CImageToolDoc::OnBitplaneSlicing)
END_MESSAGE_MAP()


// CImageToolDoc 생성/소멸

CImageToolDoc::CImageToolDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CImageToolDoc::~CImageToolDoc()
{
}

BOOL CImageToolDoc::OnNewDocument()
{
	if(!CDocument::OnNewDocument())
		return FALSE;
	BOOL bSuccess = TRUE;
	if(theApp.m_pNewDib == NULL)
	{
		CFileNewDlg dlg;
					
		if( dlg.DoModal() == IDOK )
		{
			if( dlg.m_nType == 0)
				bSuccess = m_Dib.CreateGrayImage(dlg.m_nWidth, dlg.m_nHeight);
			else
				bSuccess = m_Dib.CreateRGBImage(dlg.m_nWidth, dlg.m_nHeight);
		}
		else
		{
			bSuccess = FALSE;
		}
	}
	else
	{
		m_Dib.Copy(theApp.m_pNewDib);
		theApp.m_pNewDib = NULL;
	}
	return bSuccess;
}





// CImageToolDoc serialization

void CImageToolDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// CImageToolDoc 진단

#ifdef _DEBUG
void CImageToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageToolDoc 명령

BOOL CImageToolDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return m_Dib.Load(lpszPathName);
}

BOOL CImageToolDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return m_Dib.Save(lpszPathName);
}

void CImageToolDoc::OnWindowDuplicate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	AfxNewImage(m_Dib);
}

void CImageToolDoc::OnEditCopy()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if( m_Dib.IsValid() )
		m_Dib.CopyToClipboard();
}

void CImageToolDoc::OnImageInverse()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDib dib = m_Dib;
	DibInverse(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnImageBrightness()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CBrightnessDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;
		DibBrightness(dib, dlg.m_nBrightness);
		AfxNewImage(dib);
	}
}

void CImageToolDoc::OnImageContrast()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CContrastDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;
		DibContrast(dib, dlg.m_nContrast);
		AfxNewImage(dib);
	}
}


void CImageToolDoc::OnGammaCorrection()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CGammaCorrectionDlg dlg;
	if( dlg.DoModal() == IDOK)
	{
		CDib dib = m_Dib;
		DibGammaCorrection(dib, dlg.m_fGamma);
		AfxNewImage(dib);
	}
}


void CImageToolDoc::OnViewHistogram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CHistogramDlg dlg;
	dlg.SetImage(m_Dib);
	dlg.DoModal();
}


void CImageToolDoc::OnHistoEqualize()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDib dib = m_Dib;
	DibHistEqual(dib);
	AfxNewImage(dib);
}


void CImageToolDoc::OnImageArithmetic()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CArithmeticDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CImageToolDoc* pDoc1 = (CImageToolDoc*)dlg.m_pDoc1;
		CImageToolDoc* pDoc2 = (CImageToolDoc*)dlg.m_pDoc2;
		
		CDib dib;
		BOOL ret =FALSE;

		switch( dlg.m_nFunction )
		{
		case 0: ret = DibAdd(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 1: ret = DibSub(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 2: ret = DibAve(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 3: ret = DibDif(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 4: ret = DibAND(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 5: ret = DibOR(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		}

		if(ret)
			AfxNewImage(dib);
		else
			AfxMessageBox(_T("영상의 크기가 다릅니다!!"));
	}
}


void CImageToolDoc::OnBitplaneSlicing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	register int i;

	int w = m_Dib.GetWidth();
	int h = m_Dib.GetHeight();

	CDib dib;
	dib.CreateGrayImage(w, h);

	for( i=0; i<8; i++ )
	{
		DibBitPlane(m_Dib, i, dib);
		AfxNewImage(dib);
	}
}
