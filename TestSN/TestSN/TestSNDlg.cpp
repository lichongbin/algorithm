// TestSNDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestSN.h"
#include "TestSNDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTestSNDlg 对话框




CTestSNDlg::CTestSNDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestSNDlg::IDD, pParent)
	, m_strPrefix(_T("A"))
	, m_strSubfix(_T("Z"))
	, m_strSN(_T("000100"))
	, m_nHex(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestSNDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PREFIX, m_strPrefix);
	DDX_Text(pDX, IDC_EDIT_SUBFIX, m_strSubfix);
	DDX_Text(pDX, IDC_EDIT_SN, m_strSN);
	DDX_Control(pDX, IDC_COMBO1, m_cmbHex);
	DDX_CBIndex(pDX, IDC_COMBO1, m_nHex);
}

BEGIN_MESSAGE_MAP(CTestSNDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CTestSNDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTestSNDlg 消息处理程序

BOOL CTestSNDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//m_cmbHex.AddString(_T("10进制"));
	//m_cmbHex.AddString(_T("34进制"));

	for (int i = 2; i < 36; i++)
	{
		CString s;
		s.Format(_T("%d进制"), i);
		m_cmbHex.AddString(s);
	}

	UpdateData(FALSE);

	CString strMsg;
	strMsg = _T("要求：完成34进制的当前流水号加1\n\
				34进制:0123456789ABCDEFGHJKLMNPQRSTUVWXYZ");
	SetDlgItemText(IDC_STATIC_MSG,strMsg);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestSNDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestSNDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CTestSNDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTestSNDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();

	CString strFormat;
	CString strFullText;


	//if(m_nHex == 0)
	//{//10进制加1
	//	int nLen = m_strSN.GetLength();
	//	int nSn = _tstoi(m_strSN);
	//	strFormat.Format(_T("%%0%dd"),nLen);
	//	m_strSN.Format(strFormat,nSn+1);
	//}
	//else if(m_nHex == 1)
	//{//在此完成任意进制流水号加1，比如34，进制内容自定义

	//}

	int base = m_nHex + 2;

	m_strSN = NextSN(m_strSN, base);

	strFullText.Format(_T("%s%s%s"),m_strPrefix,m_strSN,m_strSubfix);
	SetDlgItemText(IDC_EDIT_TEXT,strFullText);
	UpdateData(FALSE);
}


int CTestSNDlg::Char2Num(TCHAR c)
{
	if (c >= _T('0') && c <= _T('9'))
	{
		return c - _T('0');
	}
	else if (c >= _T('A') && c <= _T('Z'))
	{
		return 10 + c - _T('A');
	}
	else if (c >= _T('a') && c <= _T('z'))
	{
		return 10 + c - _T('a');
	}
	else
	{
		return -1;
	}
}


TCHAR CTestSNDlg::Num2Char(int n)
{
	if (n >= 0 && n <= 9)
	{
		return n + _T('0');
	}
	else if (n >= 10 && n <= 35)
	{
		return n - 10 + _T('A');
	}
	else
	{
		return _T('*');
	}
}


CString CTestSNDlg::NextSN(CString sc, int base)
{
	const int LENGTH = sc.GetLength();
	int cum = 1;
	for (int i = LENGTH - 1; i >= 0; i--)
	{
		TCHAR c = sc.GetAt(i);
		int n = Char2Num(c) + cum;
		if (n >= base)
		{
			cum = 1;
			n -= base;
			sc.SetAt(i, Num2Char(n));
		}
		else
		{
			cum = 0;
			sc.SetAt(i, Num2Char(n));
			break;
		}
	}
	return sc;
}
