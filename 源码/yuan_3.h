
// yuan_3.h : yuan_3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cyuan_3App:
// �йش����ʵ�֣������ yuan_3.cpp
//

class Cyuan_3App : public CWinAppEx
{
public:
	Cyuan_3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cyuan_3App theApp;
