
// HttpAnalysisDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HttpAnalysis.h"
#include "HttpAnalysisDlg.h"
#include "afxdialogex.h"
#include "winhttp.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
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


// CHttpAnalysisDlg �Ի���



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


// CHttpAnalysisDlg ��Ϣ�������

BOOL CHttpAnalysisDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	//��ʼ��TabControl ҳ������
	InitTabControl();

	processUrl.SetRange(0, 100);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHttpAnalysisDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CHttpAnalysisDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ�Tab�ؼ���ʼ������
 * ����˵�����޲���
 * ע�����
 * �޸����ڣ�2015/08/08 21:21:00
 ***********************************************************************************************************/
bool CHttpAnalysisDlg::InitTabControl()
{
	TabContent.InsertItem(0, L"HTML ͷ");
	TabContent.InsertItem(1, L"HTML ����");
	TabContent.InsertItem(2, L"��ȡ����");

	tabHtmlHead.Create(IDD_TAB_HTML_Head, GetDlgItem(IDC_Tab_Content));
	tabHtmlBody.Create(IDD_TAB_HTML_Body, GetDlgItem(IDC_Tab_Content));
	tabHtmlGet.Create(IDD_TAB_HTML_Get, GetDlgItem(IDC_Tab_Content));

	MoveSubTab();

	//�ֱ�������ʾ������
	tabHtmlHead.ShowWindow(true);
	tabHtmlBody.ShowWindow(false);
	tabHtmlGet.ShowWindow(false);

	//����Ĭ��ѡ�
	TabContent.SetCurSel(0);
	return false;
}


/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ��ƶ�ÿһ��Tabҳ�浽���ʵ�λ��
 * ����˵����
 * ע������˱���������Ϊ�˱������һ��ʼ��������OnSize�¼�ʱ����ã���Ϊ��ʱTab�ؼ���ĸ����ڻ�û������
 * �޸����ڣ�2015/08/14
 ***********************************************************************************************************/
void CHttpAnalysisDlg::MoveSubTab()
{
	static bool isFirstTime = true;
	if (isFirstTime)
	{
		CRect  rs;
		TabContent.GetClientRect(&rs);

		//�����ӶԻ����ڸ������е�λ��
		rs.top += 30;
		rs.bottom -= 10;
		rs.left += 10;
		rs.right -= 10;

		//�����ӶԻ���ߴ粢�ƶ���ָ����λ��
		tabHtmlHead.MoveWindow(&rs);
		tabHtmlBody.MoveWindow(&rs);
		tabHtmlGet.MoveWindow(&rs);
	}
	isFirstTime = false;
}


/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ�ʵ��Tab�ؼ�ҳ����л�
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
void CHttpAnalysisDlg::OnTcnSelchangeTabContent(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
 * �������ߣ��Խ���
 * �������ܣ���ȡURL��ַ�������ַ������HTMLͷ������
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
bool CHttpAnalysisDlg::ProcessHttpRequest()
{
	// ��ȡ��Ҫ�����URL��ַ
	CString url;
	edtURL.GetWindowTextW(url);
	// ����Http�ͻ��ˣ���������
	WinHttpClient client(url.GetBuffer());
	client.SendHttpRequest();

	//�ռ����������ص�Httpͷ������
	wstring httpResponseHeader = client.GetResponseHeader();
	wstring httpResponseContent = client.GetResponseContent();

	//��Httpͷ��������ʾ��Tab��ǩҳ���ı�����
	tabHtmlHead.edtHtmlHead.SetWindowTextW(httpResponseHeader.c_str());
	tabHtmlBody.edtHtmlBody.SetWindowTextW(httpResponseContent.c_str());
	return false;
}



/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ���ʼ������ť
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
void CHttpAnalysisDlg::OnBnClickedBtnStart()
{
	ProcessHttpRequest();
}
