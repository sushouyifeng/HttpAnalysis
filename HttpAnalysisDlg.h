
// HttpAnalysisDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "TabHtmlHead.h"
#include "TabHtmlBody.h"
#include "TabHtmlGet.h"
#include "ThirdParty\ATLRegExp\WinHttpClient.h"
#include "afxwin.h"

// CHttpAnalysisDlg 对话框
class CHttpAnalysisDlg : public CDialogEx
{
// 构造
public:
	CHttpAnalysisDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_HTTPANALYSIS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// Tab 控件
	CTabCtrl TabContent;
	// Tab控件初始化代码
	bool InitTabControl();
	CTabHtmlHead tabHtmlHead;
	CTabHtmlBody tabHtmlBody;
	CTabHtmlGet tabHtmlGet;
	void MoveSubTab();
	afx_msg void OnTcnSelchangeTabContent(NMHDR *pNMHDR, LRESULT *pResult);
	bool ProcessHttpRequest();
	afx_msg void OnBnClickedBtnStart();
	CEdit edtURL;
	CProgressCtrl processUrl;
	void processData(CString data);
	static bool HtmlRequestProgress(double progress);
    static CHttpAnalysisDlg* pThis;
	afx_msg void OnBnClickedBtnPaste();
	afx_msg void OnBnClickedBtnClear();
	afx_msg void OnBnClickedCheckTop();
};
