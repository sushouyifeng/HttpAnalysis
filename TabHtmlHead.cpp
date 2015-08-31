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
	DDX_Control(pDX, IDC_EDIT_Head, edtHtmlHead);
}


BEGIN_MESSAGE_MAP(CTabHtmlHead, CDialogEx)
	ON_BN_CLICKED(IDC_btnHeadClear, &CTabHtmlHead::OnBnClickedbtnheadclear)
	ON_BN_CLICKED(IDC_btnHeadCopy, &CTabHtmlHead::OnBnClickedbtnheadcopy)
	ON_BN_CLICKED(IDC_btnHeadSave, &CTabHtmlHead::OnBnClickedbtnheadsave)
END_MESSAGE_MAP()


// CTabHtmlHead 消息处理程序


/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：清除URL分析结果头内容
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CTabHtmlHead::OnBnClickedbtnheadclear()
{
	edtHtmlHead.SetWindowTextW(L"");
}


/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：复制URL分析结果头内容
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CTabHtmlHead::OnBnClickedbtnheadcopy()
{
	edtHtmlHead.SetSel(0, -1);
	edtHtmlHead.Copy();
	edtHtmlHead.SetSel(0, 0);
}


/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：另存为URL分析结果头内容
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CTabHtmlHead::OnBnClickedbtnheadsave()
{
	// TODO:  在此添加控件通知处理程序代码
}
