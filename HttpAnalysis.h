
// HttpAnalysis.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CHttpAnalysisApp: 
// �йش����ʵ�֣������ HttpAnalysis.cpp
//

class CHttpAnalysisApp : public CWinApp
{
public:
	CHttpAnalysisApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CHttpAnalysisApp theApp;