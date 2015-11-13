#pragma once
#include "afxwin.h"
#include "afxcmn.h"


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
	CRichEditCtrl edtHtmlBody;
	afx_msg void OnBnClickedbtnbodyclear();
	afx_msg void OnBnClickedbtnbodycopy();
	afx_msg void OnBnClickedbtnbodysave();
	afx_msg void OnBnClickedbtnBodysearch();
	afx_msg void OnBnClickedbtnbodyget();
	virtual BOOL OnInitDialog();
	void InitRichEdit();
	CEdit edtSearch;
	void FindTextHtml();
	void ColorMarkSearch(long start, long end);
	void ClearTextMark();
	static long SubEditProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static	void ShowLineNum(HWND hEdit);
	CComboBox cmbbRegStyle;
	CEdit edtMatchNumber;
	afx_msg void OnBnClickedbtnStockreg();
	afx_msg void OnCbnSelchangeComboBodyregular();
	void InitCommboxList();
};
