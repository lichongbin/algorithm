// TestSNDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CTestSNDlg 对话框
class CTestSNDlg : public CDialog
{
// 构造
public:
	CTestSNDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TESTSN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strPrefix;
public:
	CString m_strSubfix;
public:
	CString m_strSN;
public:
	CComboBox m_cmbHex;
public:
	int m_nHex;
public:
	afx_msg void OnBnClickedOk();

private:
	int Char2Num(TCHAR c);
	TCHAR Num2Char(int n);
	CString NextSN(CString sc, int base);
};
