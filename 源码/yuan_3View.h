
// yuan_3View.h : Cyuan_3View ��Ľӿ�
//

#pragma once


class Cyuan_3View : public CView
{
protected: // �������л�����
	Cyuan_3View();
	DECLARE_DYNCREATE(Cyuan_3View)

// ����
public:
	Cyuan_3Doc* GetDocument() const;

// ����
public:
	int matrix[601][601];

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Cyuan_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // yuan_3View.cpp �еĵ��԰汾
inline Cyuan_3Doc* Cyuan_3View::GetDocument() const
   { return reinterpret_cast<Cyuan_3Doc*>(m_pDocument); }
#endif

