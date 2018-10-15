// BrightnessDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "BrightnessDlg.h"


// CBrightnessDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CBrightnessDlg, CDialog)

CBrightnessDlg::CBrightnessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBrightnessDlg::IDD, pParent)
	, m_nBrightness(0)
{

}

CBrightnessDlg::~CBrightnessDlg()
{
}

void CBrightnessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BRIGHTNESS_SLIDER, m_sliderBrightness);
	DDX_Text(pDX, IDC_BRIGHTNESS_EDIT, m_nBrightness);
	DDV_MinMaxInt(pDX, m_nBrightness, -100, 100);
}


BEGIN_MESSAGE_MAP(CBrightnessDlg, CDialog)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_BRIGHTNESS_EDIT, &CBrightnessDlg::OnEnChangeBrightnessEdit)
END_MESSAGE_MAP()


// CBrightnessDlg 메시지 처리기입니다.

BOOL CBrightnessDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	// 슬라이드 컨트롤의 초기화
	m_sliderBrightness.SetRange(-100, 100); // 슬라이더 최대, 최소값 범위
	m_sliderBrightness.SetTicFreq(20); // 슬라이더 눈금 간격
	m_sliderBrightness.SetPageSize(20); // 엄지단추 이외의 클릭시 움직이는 눈금 간격

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CBrightnessDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 슬라이드바에서 발생한 WM_HSCROLL 메시지인 경우 처리
	if( m_sliderBrightness.GetSafeHwnd() == pScrollBar->GetSafeHwnd() )
	{
		int nPos = m_sliderBrightness.GetPos();
		m_nBrightness = nPos;
		UpdateData(FALSE);
	}

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CBrightnessDlg::OnEnChangeBrightnessEdit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정하고  마스크에 OR 연산하여 설정된
	// ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출해야만
	// 해당 알림 메시지를 보냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_sliderBrightness.SetPos(m_nBrightness);
}
