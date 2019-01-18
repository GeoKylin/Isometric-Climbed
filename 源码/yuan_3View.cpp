
// yuan_3View.cpp : Cyuan_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "yuan_3.h"
#endif

#include "yuan_3Doc.h"
#include "yuan_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cyuan_3View

IMPLEMENT_DYNCREATE(Cyuan_3View, CView)

BEGIN_MESSAGE_MAP(Cyuan_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cyuan_3View ����/����

Cyuan_3View::Cyuan_3View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cyuan_3View::~Cyuan_3View()
{
}

BOOL Cyuan_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cyuan_3View ����

void Cyuan_3View::OnDraw(CDC* pDC)
{
	Cyuan_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	//////////////////////////  �������  //////////////////////////
	int center_x = 450, center_y = 330, radious = 200;
	int x, y, r;
	int step = 1;
	float a;   
	int d = 7;         //����
	for (a = 0; a < 370; a += d)
	{
		Sleep(4000);
		bool once = false;
		//a = 137.5; once = true;
		CPen whitep(PS_SOLID, 1, RGB(255, 255, 255));
		CBrush whiteb(RGB(255, 255, 255));
		pDC->SelectObject(&whitep);
		pDC->SelectObject(&whiteb);
		pDC->Rectangle(0, 0, 1000, 1000);
		for (int n = radious / step; n >= 0; n--)
		{
			x = int(n*step*cos(n*a*3.1415927 / 180) + 0.5) + center_x;
			y = int(n*step*sin(n*a*3.1415927 / 180) + 0.5) + center_y;
			CPen changep(PS_SOLID, 1, RGB(255, 100 + n*step / 2, 0));
			CBrush changeb(RGB(235, 100 + n*step / 2, 0));
			pDC->SelectObject(&changep);
			pDC->SelectObject(&changeb);
			CString s;
			s.Format(_T("������%.2f"), a);
			pDC->TextOutW(100,100, s);
			/*********************************************
			r = 10 + n*step/2;
			pDC->Ellipse(x - r, y - r, x + r, y + r);
			/*********************************************/
			pDC->MoveTo(x, y);
			pDC->LineTo(x*0.4 + (x - (center_x - x + 0.0) / 8 * step)*0.6 + (center_y - y + 0.0) / 24, y*0.4 + (y - (center_y - y + 0.0) / 8 * step)*0.6 - (center_x - x + 0.0) / 24);
			pDC->LineTo(x - (center_x - x + 0.0) / 6 * step, y - (center_y - y + 0.0) / 6 * step);
			pDC->LineTo(x*0.4 + (x - (center_x - x + 0.0) / 8 * step)*0.6 - (center_y - y + 0.0) / 24, y*0.4 + (y - (center_y - y + 0.0) / 8 * step)*0.6 + (center_x - x + 0.0) / 24);
			pDC->LineTo(x, y);
			/*********************************************/
		}
		if (once == true) break;		
	}
}


// Cyuan_3View ��ӡ

BOOL Cyuan_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cyuan_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cyuan_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// Cyuan_3View ���

#ifdef _DEBUG
void Cyuan_3View::AssertValid() const
{
	CView::AssertValid();
}

void Cyuan_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cyuan_3Doc* Cyuan_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cyuan_3Doc)));
	return (Cyuan_3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cyuan_3View ��Ϣ�������
