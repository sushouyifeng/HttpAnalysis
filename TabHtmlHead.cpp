// TabHtmlHead.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HttpAnalysis.h"
#include "TabHtmlHead.h"
#include "afxdialogex.h"


// CTabHtmlHead �Ի���

IMPLEMENT_DYNAMIC(CTabHtmlHead, CDialogEx)

CTabHtmlHead::CTabHtmlHead(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabHtmlHead::IDD, pParent)
{

}

CTabHtmlHead::~CTabHtmlHead()
{
}

void CTabHtmlHead::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edtHtmlHead);
}


BEGIN_MESSAGE_MAP(CTabHtmlHead, CDialogEx)
END_MESSAGE_MAP()


// CTabHtmlHead ��Ϣ�������
