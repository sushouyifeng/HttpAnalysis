#pragma once
#include "afxwin.h"


// CTabHtmlBody 对话框

class CTabHtmlBody : public CDialogEx
{
	DECLARE_DYNAMIC(CTabHtmlBody)

public:
	CTabHtmlBody(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTabHtmlBody();

// 对话框数据
	enum { IDD = IDD_TAB_HTML_Body };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit edtHtmlBody;
};
