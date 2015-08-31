// TabHtmlBody.cpp : 实现文件
//

#include "stdafx.h"
#include "HttpAnalysis.h"
#include "TabHtmlBody.h"
#include "afxdialogex.h"


// CTabHtmlBody 对话框

IMPLEMENT_DYNAMIC(CTabHtmlBody, CDialogEx)

CTabHtmlBody::CTabHtmlBody(CWnd* pParent /*=NULL*/)
: CDialogEx(CTabHtmlBody::IDD, pParent)
{

}

CTabHtmlBody::~CTabHtmlBody()
{
}

void CTabHtmlBody::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT_Body, edtHtmlBody);
	DDX_Control(pDX, IDC_EDIT_BodyFilter, edtSearch);
}


BEGIN_MESSAGE_MAP(CTabHtmlBody, CDialogEx)
	ON_BN_CLICKED(IDC_btnBodyClear, &CTabHtmlBody::OnBnClickedbtnbodyclear)
	ON_BN_CLICKED(IDC_btnBodyCopy, &CTabHtmlBody::OnBnClickedbtnbodycopy)
	ON_BN_CLICKED(IDC_btnBodySave, &CTabHtmlBody::OnBnClickedbtnbodysave)
	ON_BN_CLICKED(IDC_btn_BodySearch, &CTabHtmlBody::OnBnClickedbtnBodysearch)
	ON_BN_CLICKED(IDC_btnBodyGet, &CTabHtmlBody::OnBnClickedbtnbodyget)
END_MESSAGE_MAP()


// CTabHtmlBody 消息处理程序


/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：清空URL分析产生的BODY内容
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CTabHtmlBody::OnBnClickedbtnbodyclear()
{
	// TODO:  在此添加控件通知处理程序代码
	edtHtmlBody.SetWindowTextW(L"");
}


/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：复制URL分析产生的BODY内容
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CTabHtmlBody::OnBnClickedbtnbodycopy()
{
	// TODO:  在此添加控件通知处理程序代码
	edtHtmlBody.SetSel(0, -1);
	edtHtmlBody.Copy();
	edtHtmlBody.SetSel(0, 0);
}



/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：另存为URL分析产生的BODY内容
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CTabHtmlBody::OnBnClickedbtnbodysave()
{
	// TODO:  在此添加控件通知处理程序代码
}



/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：在URL分析产生的BODY内容中搜索匹配的对象
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CTabHtmlBody::OnBnClickedbtnBodysearch()
{
	// TODO:  在此添加控件通知处理程序代码
	FindTextHtml();
}



/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：从URL分析产生的BODY内容中进行提取匹配的内容
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CTabHtmlBody::OnBnClickedbtnbodyget()
{
	// TODO:  在此添加控件通知处理程序代码
}



/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：初始化文本框字体
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
 BOOL CTabHtmlBody::OnInitDialog()
 {
	 CDialogEx::OnInitDialog();

	 // TODO:  在此添加额外的初始化
	 InitRichEdit();
	 return TRUE;  // return TRUE unless you set the focus to a control
	 // 异常:  OCX 属性页应返回 FALSE
 }



 /***********************************************************************************************************
  * 程序作者：赵进军
  * 函数功能：初始化文本框字体实现函数
  * 参数说明：
  * 注意事项：
  * 修改日期：
  ***********************************************************************************************************/
 void CTabHtmlBody::InitRichEdit()
 {
	 CFont fnt;
	 fnt.CreatePointFont(100, L"宋体");
	 edtHtmlBody.SetFont(&fnt);
 }



 /***********************************************************************************************************
  * 程序作者：赵进军
  * 函数功能：实现对HTML内容部分数据查找
  * 参数说明：
  * 注意事项：
  * 修改日期：
  ***********************************************************************************************************/
 void CTabHtmlBody::FindTextHtml()
 {
	 //获取需要搜索的文本
	 CString  filterStr;
	 edtSearch.GetWindowTextW(filterStr);

	 //定义FindTextW所需参数的结构体
	 FINDTEXTEX ft;
	 ft.chrg.cpMin = 0;
	 ft.chrg.cpMax = -1;
	 ft.lpstrText = filterStr.GetBuffer();
	 long lPos = -1;
	 int strlen = filterStr.GetLength();

	 do
	 {
		 lPos = edtHtmlBody.FindTextW(FR_DOWN, &ft);
		 if (-1 == lPos)
			 break;
		 //edtHtmlBody.SetSel(lPos,lPos+strlen);
		 ColorMarkSearch(lPos, lPos + strlen);
		 ft.chrg.cpMin = lPos + strlen;
	 } while (true);

 }


 /***********************************************************************************************************
  * 程序作者：赵进军
  * 函数功能：使用不同的颜色标记源文本
  * 参数说明：
  * 注意事项：
  * 修改日期：
  ***********************************************************************************************************/
 void CTabHtmlBody::ColorMarkSearch(long start,long end)
 {
	 CHARFORMAT2 cf;
	 memset(&cf,0,sizeof(cf));
	 cf.cbSize = sizeof(cf);
	 cf.dwMask = CFM_BOLD | CFM_COLOR | CFM_BACKCOLOR;
	 cf.dwEffects = 1;
	 cf.crTextColor = RGB(0,0,0);
	 cf.crBackColor = RGB(116,208,241);
	 edtHtmlBody.SendMessage(EM_SETCHARFORMAT,SCF_SELECTION,(LPARAM)&cf);
 }
