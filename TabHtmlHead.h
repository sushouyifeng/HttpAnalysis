#pragma once


// CTabHtmlHead �Ի���

class CTabHtmlHead : public CDialogEx
{
	DECLARE_DYNAMIC(CTabHtmlHead)

public:
	CTabHtmlHead(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTabHtmlHead();

// �Ի�������
	enum { IDD = IDD_TAB_HTML_Head };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
