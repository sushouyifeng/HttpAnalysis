// TabHtmlGet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HttpAnalysis.h"
#include "TabHtmlGet.h"
#include "afxdialogex.h"


// CTabHtmlGet �Ի���

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


// CTabHtmlGet ��Ϣ�������


/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ����URL������ȡ������
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
void CTabHtmlGet::OnBnClickedbtngetclear()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	edtHtmlGet.SetWindowTextW(L"");
}


/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ�����URL������ȡ������
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
void CTabHtmlGet::OnBnClickedbtngetcopy()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	edtHtmlGet.SetSel(0, -1);
	edtHtmlGet.Copy();
	edtHtmlGet.SetSel(0, 0);
}


/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ����ΪURL������ȡ������
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
void CTabHtmlGet::OnBnClickedbtngetsave()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ�ʹ��Ѹ������URL������ȡ������
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
void CTabHtmlGet::OnBnClickedbtngetdown()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
