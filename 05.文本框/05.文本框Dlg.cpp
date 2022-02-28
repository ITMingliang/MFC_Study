
// 05.文本框Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "05.文本框.h"
#include "05.文本框Dlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy05文本框Dlg 对话框



CMy05文本框Dlg::CMy05文本框Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY05_DIALOG, pParent)
	, m_text1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy05文本框Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_text1);
}

BEGIN_MESSAGE_MAP(CMy05文本框Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CMy05文本框Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy05文本框Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy05文本框Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy05文本框Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CMy05文本框Dlg 消息处理程序

BOOL CMy05文本框Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// TODO: 在此添加额外的初始化代码

	m_edit1.SetWindowTextW(TEXT("测试复制文字"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy05文本框Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy05文本框Dlg::OnPaint()
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
HCURSOR CMy05文本框Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy05文本框Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码


	exit(0); //退出程序

	//退出当前对话框
	//CDialog::OnOK();
	//CDialog::OnCancel();
}

void CMy05文本框Dlg::OnOK()
{
	// TODO:  在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}

void CMy05文本框Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取edit1的内容，然后赋值给edit2

	CString str;
	//获取值
	m_edit1.GetWindowTextW(str);
	//赋值
	m_edit2.SetWindowTextW(str);;

}


void CMy05文本框Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	//设置内容
     m_text1 = TEXT("哈哈");

	//将变量内容 同步到控件中
	UpdateData(FALSE);
}


void CMy05文本框Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	MessageBox(m_text1);

}
