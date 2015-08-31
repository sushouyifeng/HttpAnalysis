// TabHtmlGet.cpp : 实现文件
//

#include "stdafx.h"
#include "HttpAnalysis.h"
#include "TabHtmlGet.h"
#include "afxdialogex.h"


// CTabHtmlGet 对话框

IMPLEMENT_DYNAMIC(CTabHtmlGet, CDialogEx)

CTabHtmlGet::CTabHtmlGet(CWnd* pParent /*=NULL*/)
: CDialogEx(CTabHtmlGet::IDD, pParent)
{

}

CTabHtmlGet::~CTabHtmlGet()
{
}

void CTabHtmlGet::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_Get, edtHtmlGet);
}


BEGIN_MESSAGE_MAP(CTabHtmlGet, CDialogEx)
	ON_BN_CLICKED(IDC_btnGetClear, &CTabHtmlGet::OnBnClickedbtngetclear)
	ON_BN_CLICKED(IDC_btnGetCopy, &CTabHtmlGet::OnBnClickedbtngetcopy)
	ON_BN_CLICKED(IDC_btnGetSave, &CTabHtmlGet::OnBnClickedbtngetsave)
	ON_BN_CLICKED(IDC_btnGetDown, &CTabHtmlGet::OnBnClickedbtngetdown)
END_MESSAGE_MAP()


// CTabHtmlGet 消息处理程序


/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：清除URL分析提取的数据
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CTabHtmlGet::OnBnClickedbtngetclear()
{
	// TODO:  在此添加控件通知处理程序代码
	edtHtmlGet.SetWindowTextW(L"");
}


/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：复制URL分析提取的数据
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CTabHtmlGet::OnBnClickedbtngetcopy()
{
	// TODO:  在此添加控件通知处理程序代码
	edtHtmlGet.SetSel(0, -1);
	edtHtmlGet.Copy();
	edtHtmlGet.SetSel(0, 0);
}


/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：另存为URL分析提取的数据
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CTabHtmlGet::OnBnClickedbtngetsave()
{
	// TODO:  在此添加控件通知处理程序代码
}


/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：使用迅雷下载URL分析提取的数据
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CTabHtmlGet::OnBnClickedbtngetdown()
{
	// TODO:  在此添加控件通知处理程序代码
}
