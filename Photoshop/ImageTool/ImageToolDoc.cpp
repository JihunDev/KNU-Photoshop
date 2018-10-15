// ImageToolDoc.cpp : CImageToolDoc Ŭ������ ����
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


// CImageToolDoc ����/�Ҹ�

CImageToolDoc::CImageToolDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

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
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}


// CImageToolDoc ����

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


// CImageToolDoc ���

BOOL CImageToolDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return m_Dib.Load(lpszPathName);
}

BOOL CImageToolDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return m_Dib.Save(lpszPathName);
}

void CImageToolDoc::OnWindowDuplicate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	AfxNewImage(m_Dib);
}

void CImageToolDoc::OnEditCopy()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	if( m_Dib.IsValid() )
		m_Dib.CopyToClipboard();
}

void CImageToolDoc::OnImageInverse()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	DibInverse(dib);
	AfxNewImage(dib);
}

void CImageToolDoc::OnImageBrightness()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CHistogramDlg dlg;
	dlg.SetImage(m_Dib);
	dlg.DoModal();
}


void CImageToolDoc::OnHistoEqualize()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	DibHistEqual(dib);
	AfxNewImage(dib);
}


void CImageToolDoc::OnImageArithmetic()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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
			AfxMessageBox(_T("������ ũ�Ⱑ �ٸ��ϴ�!!"));
	}
}


void CImageToolDoc::OnBitplaneSlicing()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

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
