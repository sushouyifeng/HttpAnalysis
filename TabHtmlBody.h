#pragma once
#include "afxwin.h"


// CTabHtmlBody �Ի���

class CTabHtmlBody : public CDialogEx
{
	DECLARE_DYNAMIC(CTabHtmlBody)

public:
	CTabHtmlBody(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTabHtmlBody();

// �Ի�������
	enum { IDD = IDD_TAB_HTML_Body };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit edtHtmlBody;
};
