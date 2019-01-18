
// yuan_3View.cpp : Cyuan_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cyuan_3View 构造/析构

Cyuan_3View::Cyuan_3View()
{
	// TODO:  在此处添加构造代码

}

Cyuan_3View::~Cyuan_3View()
{
}

BOOL Cyuan_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cyuan_3View 绘制

void Cyuan_3View::OnDraw(CDC* pDC)
{
	Cyuan_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	//////////////////////////  定义参数  //////////////////////////
	int center_x = 450, center_y = 330, radious = 200;
	int x, y, r;
	int step = 1;
	float a;   
	int d = 7;         //进度
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
			s.Format(_T("度数：%.2f"), a);
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


// Cyuan_3View 打印

BOOL Cyuan_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cyuan_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void Cyuan_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// Cyuan_3View 诊断

#ifdef _DEBUG
void Cyuan_3View::AssertValid() const
{
	CView::AssertValid();
}

void Cyuan_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cyuan_3Doc* Cyuan_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cyuan_3Doc)));
	return (Cyuan_3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cyuan_3View 消息处理程序
