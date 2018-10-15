// GammaCorrectionDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "GammaCorrectionDlg.h"
#include "afxdialogex.h"


// CGammaCorrectionDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CGammaCorrectionDlg, CDialogEx)

CGammaCorrectionDlg::CGammaCorrectionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGammaCorrectionDlg::IDD, pParent)
	, m_fGamma(2.20f)
{

}

CGammaCorrectionDlg::~CGammaCorrectionDlg()
{
}

void CGammaCorrectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GAMMA_SLIDER, m_sliderGamma);
	DDX_Text(pDX, IDC_GAMMA_EDIT, m_fGamma);
	DDV_MinMaxFloat(pDX, m_fGamma, 0.20f, 5.00f);
}


BEGIN_MESSAGE_MAP(CGammaCorrectionDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_GAMMA_EDIT, &CGammaCorrectionDlg::OnEnChangeGammaEdit)
END_MESSAGE_MAP()


// CGammaCorrectionDlg �޽��� ó�����Դϴ�.


BOOL CGammaCorrectionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_sliderGamma.SetRange(10, 250);
	m_sliderGamma.SetTicFreq(20);
	m_sliderGamma.SetPageSize(20);
	m_sliderGamma.SetPos((int)(m_fGamma*50));

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CGammaCorrectionDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if( m_sliderGamma.GetSafeHwnd() == pScrollBar->GetSafeHwnd())
	{
		int nPos = m_sliderGamma.GetPos();
		m_fGamma = (nPos/50.f);
		UpdateData(FALSE);
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CGammaCorrectionDlg::OnEnChangeGammaEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.
	UpdateData(TRUE);
	m_sliderGamma.SetPos((int)(m_fGamma*50));
	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
