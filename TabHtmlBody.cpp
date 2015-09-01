// TabHtmlBody.cpp : 实现文件
//

#include "stdafx.h"
#include "HttpAnalysis.h"
#include "TabHtmlBody.h"
#include "afxdialogex.h"


// CTabHtmlBody 对话框
WNDPROC _lpEditProc;
HWND _editHwnd;



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

	//设置RichEdit窗口的编辑器区域，我们左边留出40像素宽度用于显示行号
	edtHtmlBody.SendMessage(EM_SETMARGINS, EC_RIGHTMARGIN | EC_LEFTMARGIN, 0x00050005 + 40);

	//设置RichEdit 为无文本长度限制，否则为64Kb的文本长度。
	edtHtmlBody.SendMessage(EM_EXLIMITTEXT, 0, -1);

	_editHwnd = edtHtmlBody.GetSafeHwnd();

	//设置新窗口地址，lpEditProc为RichEdit的内置窗口处理地址。
	_lpEditProc = (WNDPROC)::SetWindowLong(edtHtmlBody.GetSafeHwnd(), GWL_WNDPROC, (LONG)&CTabHtmlBody::SubEditProc);
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
	ClearTextMark();
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
		edtHtmlBody.SetSel(lPos, lPos + strlen);
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
void CTabHtmlBody::ColorMarkSearch(long start, long end)
{
	CHARFORMAT2 cf;
	memset(&cf, 0, sizeof(cf));
	cf.cbSize = sizeof(cf);
	cf.dwMask = CFM_BOLD | CFM_COLOR | CFM_BACKCOLOR;
	cf.dwEffects = 1;
	cf.crTextColor = RGB(0, 0, 0);
	cf.crBackColor = RGB(116, 208, 241);
	edtHtmlBody.SendMessage(EM_SETCHARFORMAT, SCF_SELECTION, (LPARAM)&cf);
}



/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：清除Edit  搜索框上一次的着色
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CTabHtmlBody::ClearTextMark()
{
	CString temp;
	//获取上一次历史结果
	edtHtmlBody.GetWindowTextW(temp);
	//把上一次的历史结果进行赋值到Edit
	edtHtmlBody.SetWindowTextW(temp);
}



/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：截获RichEdit的WM_PAINT消息，用于RichEdit刷新时显示行号
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
long CTabHtmlBody::SubEditProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	if (uMsg == WM_PAINT)
	{
		::CallWindowProc(_lpEditProc, hWnd, uMsg, wParam, lParam);
		::BeginPaint(hWnd, &ps);
		ShowLineNum(_editHwnd);
		return ::EndPaint(hWnd, &ps);
	}
	return ::CallWindowProc(_lpEditProc, hWnd, uMsg, wParam, lParam);
}



/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：显示行号
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CTabHtmlBody::ShowLineNum(HWND hEdit)
{
	RECT                        ClientRect;								//RichEdit的客户区大小
	HDC                         hdcEdit;								//RichEidtd的Dc(设备环境)
	HDC                         hdcCpb;                                 //与RichEdit兼容的Dc
	HBITMAP                     hdcBmp;                                 //RichEdit兼容的位图dc
	int                         CharHeight;								//字符的高度
	int                         chHeight;								//字符的高度,常量
	int                         FirstLine;                              //文本框中的第一个可见行的行号
	int                         ClientHeight;							//RichEdit  的客户区高度
	int                         LineCount;                              //文本的总行数
	wchar_t                     countBuf[10];                           //显示行号的缓冲区
	CHARFORMAT                  CharFmt;                                //RichEdit  中的一个结构，用于获取字符的一系列


	//获取RichEdit的Dc
	hdcEdit = ::GetDC(hEdit);
	::GetClientRect(hEdit, &ClientRect);
	//获取RichEdit的客户区高度
	ClientHeight = ClientRect.bottom - ClientRect.top;
	//创建与RichEdit兼容的DC
	hdcCpb = ::CreateCompatibleDC(hdcEdit);
	//创建与RichEdit兼容的位图Dc,我们用来显示行号用的。
	hdcBmp = ::CreateCompatibleBitmap(hdcEdit, 40, ClientHeight);
	//将位图dc选入RichEdit环境中
	::SelectObject(hdcCpb, hdcBmp);
	//填充显示行号dc的背景颜色，大家可以试试其他颜色
	::FillRect(hdcCpb, &ClientRect, ::CreateSolidBrush(0x8080ff));
	::SetBkMode(hdcCpb, TRANSPARENT);
	//获取当前RichEdit 文本中的总行数
	LineCount = ::SendMessage(hEdit, EM_GETLINECOUNT, 0, 0);

	RtlZeroMemory(&CharFmt, sizeof(CharFmt));
	CharFmt.cbSize = sizeof(CharFmt);
	::SendMessage(hEdit, EM_GETCHARFORMAT, TRUE, (long)&CharFmt);

	//获取字符高度，以英寸为单位，需要转换为磅。
	CharHeight = CharFmt.yHeight / 15;
	chHeight = CharHeight;
	CharHeight = 2;

	//设置显示行号的颜色
	::SetTextColor(hdcCpb, 0x000000);

	//获取文本框中第一个可见行的行号，没有这个行号，显示不会跟着文本的滚动而滚动。
	FirstLine = ::SendMessage(hEdit, EM_GETFIRSTVISIBLELINE, 0, 0);
	FirstLine++;
	//在位图dc中循环输出行号
	while (FirstLine <= LineCount)
	{
		::TextOut(hdcCpb, 1, CharHeight, countBuf, wsprintf(countBuf, L"%4u", FirstLine++));
		CharHeight += chHeight + 3;
		if (CharHeight > ClientHeight)break;
	}

	//将已经画好的位图真正贴在RichEdit中
	::BitBlt(hdcEdit, 0, 0, 40, ClientHeight, hdcCpb, 0, 0, SRCCOPY);
	::DeleteDC(hdcCpb);
}
