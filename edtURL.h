#pragma once


// edtURL �Ի���

class edtURL : public CDialog
{
	DECLARE_DYNAMIC(edtURL)

public:
	edtURL(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~edtURL();

// �Ի�������
	enum { IDD = IDD_HTTPANALYSIS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
