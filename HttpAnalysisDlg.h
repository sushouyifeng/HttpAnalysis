
// HttpAnalysisDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "TabHtmlHead.h"
#include "TabHtmlBody.h"
#include "TabHtmlGet.h"
#include "ThirdParty\ATLRegExp\WinHttpClient.h"
#include "afxwin.h"

// CHttpAnalysisDlg �Ի���
class CHttpAnalysisDlg : public CDialogEx
{
// ����
public:
	CHttpAnalysisDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_HTTPANALYSIS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// Tab �ؼ�
	CTabCtrl TabContent;
	// Tab�ؼ���ʼ������
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
