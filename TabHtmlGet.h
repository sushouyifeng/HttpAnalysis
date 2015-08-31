#pragma once
#include "afxwin.h"


// CTabHtmlGet 对话框

class CTabHtmlGet : public CDialogEx
{
	DECLARE_DYNAMIC(CTabHtmlGet)

public:
	CTabHtmlGet(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTabHtmlGet();

// 对话框数据
	enum { IDD = IDD_TAB_HTML_Get };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbtngetclear();
	afx_msg void OnBnClickedbtngetcopy();
	afx_msg void OnBnClickedbtngetsave();
	afx_msg void OnBnClickedbtngetdown();
	CEdit edtHtmlGet;
};
