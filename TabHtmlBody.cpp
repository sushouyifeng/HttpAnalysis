// TabHtmlBody.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HttpAnalysis.h"
#include "TabHtmlBody.h"
#include "afxdialogex.h"


// CTabHtmlBody �Ի���

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


// CTabHtmlBody ��Ϣ�������


/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ����URL����������BODY����
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
void CTabHtmlBody::OnBnClickedbtnbodyclear()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	edtHtmlBody.SetWindowTextW(L"");
}


/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ�����URL����������BODY����
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
void CTabHtmlBody::OnBnClickedbtnbodycopy()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	edtHtmlBody.SetSel(0, -1);
	edtHtmlBody.Copy();
	edtHtmlBody.SetSel(0, 0);
}



/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ����ΪURL����������BODY����
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
void CTabHtmlBody::OnBnClickedbtnbodysave()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}



/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ���URL����������BODY����������ƥ��Ķ���
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
void CTabHtmlBody::OnBnClickedbtnBodysearch()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	FindTextHtml();
}



/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ���URL����������BODY�����н�����ȡƥ�������
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
void CTabHtmlBody::OnBnClickedbtnbodyget()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}



/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ���ʼ���ı�������
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
 BOOL CTabHtmlBody::OnInitDialog()
 {
	 CDialogEx::OnInitDialog();

	 // TODO:  �ڴ���Ӷ���ĳ�ʼ��
	 InitRichEdit();
	 return TRUE;  // return TRUE unless you set the focus to a control
	 // �쳣:  OCX ����ҳӦ���� FALSE
 }



 /***********************************************************************************************************
  * �������ߣ��Խ���
  * �������ܣ���ʼ���ı�������ʵ�ֺ���
  * ����˵����
  * ע�����
  * �޸����ڣ�
  ***********************************************************************************************************/
 void CTabHtmlBody::InitRichEdit()
 {
	 CFont fnt;
	 fnt.CreatePointFont(100, L"����");
	 edtHtmlBody.SetFont(&fnt);
 }



 /***********************************************************************************************************
  * �������ߣ��Խ���
  * �������ܣ�ʵ�ֶ�HTML���ݲ������ݲ���
  * ����˵����
  * ע�����
  * �޸����ڣ�
  ***********************************************************************************************************/
 void CTabHtmlBody::FindTextHtml()
 {
	 //��ȡ��Ҫ�������ı�
	 CString  filterStr;
	 edtSearch.GetWindowTextW(filterStr);

	 //����FindTextW��������Ľṹ��
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
  * �������ߣ��Խ���
  * �������ܣ�ʹ�ò�ͬ����ɫ���Դ�ı�
  * ����˵����
  * ע�����
  * �޸����ڣ�
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
