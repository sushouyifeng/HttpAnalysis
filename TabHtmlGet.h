#pragma once
#include "afxwin.h"


// CTabHtmlGet �Ի���

class CTabHtmlGet : public CDialogEx
{
	DECLARE_DYNAMIC(CTabHtmlGet)

public:
	CTabHtmlGet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTabHtmlGet();

// �Ի�������
	enum { IDD = IDD_TAB_HTML_Get };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbtngetclear();
	afx_msg void OnBnClickedbtngetcopy();
	afx_msg void OnBnClickedbtngetsave();
	afx_msg void OnBnClickedbtngetdown();
	CEdit edtHtmlGet;
};
