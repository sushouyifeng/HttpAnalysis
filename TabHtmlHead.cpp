// TabHtmlHead.cpp : 实现文件
//

#include "stdafx.h"
#include "HttpAnalysis.h"
#include "TabHtmlHead.h"
#include "afxdialogex.h"


// CTabHtmlHead 对话框

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


// CTabHtmlHead 消息处理程序
