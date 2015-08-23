
// HttpAnalysisDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HttpAnalysis.h"
#include "HttpAnalysisDlg.h"
#include "afxdialogex.h"
#include "winhttp.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CHttpAnalysisDlg 对话框



CHttpAnalysisDlg::CHttpAnalysisDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHttpAnalysisDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHttpAnalysisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Tab_Content, TabContent);
	DDX_Control(pDX, IDC_Edit_Url, edtURL);
	DDX_Control(pDX, IDC_Pro_Analysis, processUrl);
}

BEGIN_MESSAGE_MAP(CHttpAnalysisDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_Tab_Content, &CHttpAnalysisDlg::OnTcnSelchangeTabContent)
	//	ON_BN_CLICKED(IDC_Btn_Start, &CHttpAnalysisDlg::OnBnClickedBtnStart)
	ON_BN_CLICKED(IDC_Btn_Start, &CHttpAnalysisDlg::OnBnClickedBtnStart)
END_MESSAGE_MAP()


// CHttpAnalysisDlg 消息处理程序

BOOL CHttpAnalysisDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	//初始化TabControl 页面内容
	InitTabControl();

	processUrl.SetRange(0, 100);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CHttpAnalysisDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CHttpAnalysisDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CHttpAnalysisDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：Tab控件初始化代码
 * 参数说明：无参数
 * 注意事项：
 * 修改日期：2015/08/08 21:21:00
 ***********************************************************************************************************/
bool CHttpAnalysisDlg::InitTabControl()
{
	TabContent.InsertItem(0, L"HTML 头");
	TabContent.InsertItem(1, L"HTML 内容");
	TabContent.InsertItem(2, L"提取内容");

	tabHtmlHead.Create(IDD_TAB_HTML_Head, GetDlgItem(IDC_Tab_Content));
	tabHtmlBody.Create(IDD_TAB_HTML_Body, GetDlgItem(IDC_Tab_Content));
	tabHtmlGet.Create(IDD_TAB_HTML_Get, GetDlgItem(IDC_Tab_Content));

	MoveSubTab();

	//分别设置显示和隐藏
	tabHtmlHead.ShowWindow(true);
	tabHtmlBody.ShowWindow(false);
	tabHtmlGet.ShowWindow(false);

	//设置默认选项卡
	TabContent.SetCurSel(0);
	return false;
}


/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：移动每一个Tab页面到合适的位置
 * 参数说明：
 * 注意事项：此变量仅仅是为了避免程序一开始启动发送OnSize事件时候调用，因为这时Tab控件里的各窗口还没建立好
 * 修改日期：2015/08/14
 ***********************************************************************************************************/
void CHttpAnalysisDlg::MoveSubTab()
{
	static bool isFirstTime = true;
	if (isFirstTime)
	{
		CRect  rs;
		TabContent.GetClientRect(&rs);

		//调整子对话框在父窗口中的位置
		rs.top += 30;
		rs.bottom -= 10;
		rs.left += 10;
		rs.right -= 10;

		//设置子对话框尺寸并移动到指定的位置
		tabHtmlHead.MoveWindow(&rs);
		tabHtmlBody.MoveWindow(&rs);
		tabHtmlGet.MoveWindow(&rs);
	}
	isFirstTime = false;
}


/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：实现Tab控件页面的切换
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CHttpAnalysisDlg::OnTcnSelchangeTabContent(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	int tabSelectIndex = TabContent.GetCurSel();
	switch (tabSelectIndex)
	{
	case 0:
		tabHtmlHead.ShowWindow(true);
		tabHtmlBody.ShowWindow(false);
		tabHtmlGet.ShowWindow(false);
		break;

	case 1:
		tabHtmlHead.ShowWindow(false);
		tabHtmlBody.ShowWindow(true);
		tabHtmlGet.ShowWindow(false);
		break;

	case 2:
		tabHtmlHead.ShowWindow(false);
		tabHtmlBody.ShowWindow(false);
		tabHtmlGet.ShowWindow(true);
		break;
	default:
		break;
	}
	*pResult = 0;
}



/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：获取URL地址，请求地址，返回HTML头和内容
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
bool CHttpAnalysisDlg::ProcessHttpRequest()
{
	// 获取需要请求的URL地址
	CString url;
	edtURL.GetWindowTextW(url);
	// 构造Http客户端，发起请求
	WinHttpClient client(url.GetBuffer());
	client.SendHttpRequest();

	//收集服务器返回的Http头和内容
	wstring httpResponseHeader = client.GetResponseHeader();
	wstring httpResponseContent = client.GetResponseContent();

	//把Http头和内容显示在Tab标签页的文本框中
	tabHtmlHead.edtHtmlHead.SetWindowTextW(httpResponseHeader.c_str());
	tabHtmlBody.edtHtmlBody.SetWindowTextW(httpResponseContent.c_str());
	return false;
}



/***********************************************************************************************************
 * 程序作者：赵进军
 * 函数功能：开始分析按钮
 * 参数说明：
 * 注意事项：
 * 修改日期：
 ***********************************************************************************************************/
void CHttpAnalysisDlg::OnBnClickedBtnStart()
{
	ProcessHttpRequest();
}
