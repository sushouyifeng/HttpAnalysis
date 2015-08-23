#pragma once


// edtURL 对话框

class edtURL : public CDialog
{
	DECLARE_DYNAMIC(edtURL)

public:
	edtURL(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~edtURL();

// 对话框数据
	enum { IDD = IDD_HTTPANALYSIS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
