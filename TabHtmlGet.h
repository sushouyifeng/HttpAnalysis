#pragma once


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
};
