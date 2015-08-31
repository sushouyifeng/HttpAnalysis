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
	DDX_Control(pDX, IDC_EDIT_Head, edtHtmlHead);
}


BEGIN_MESSAGE_MAP(CTabHtmlHead, CDialogEx)
	ON_BN_CLICKED(IDC_btnHeadClear, &CTabHtmlHead::OnBnClickedbtnheadclear)
	ON_BN_CLICKED(IDC_btnHeadCopy, &CTabHtmlHead::OnBnClickedbtnheadcopy)
	ON_BN_CLICKED(IDC_btnHeadSave, &CTabHtmlHead::OnBnClickedbtnheadsave)
END_MESSAGE_MAP()


// CTabHtmlHead ��Ϣ�������


/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ����URL�������ͷ����
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
void CTabHtmlHead::OnBnClickedbtnheadclear()
{
	edtHtmlHead.SetWindowTextW(L"");
}


/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ�����URL�������ͷ����
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
void CTabHtmlHead::OnBnClickedbtnheadcopy()
{
	edtHtmlHead.SetSel(0, -1);
	edtHtmlHead.Copy();
	edtHtmlHead.SetSel(0, 0);
}


/***********************************************************************************************************
 * �������ߣ��Խ���
 * �������ܣ����ΪURL�������ͷ����
 * ����˵����
 * ע�����
 * �޸����ڣ�
 ***********************************************************************************************************/
void CTabHtmlHead::OnBnClickedbtnheadsave()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
