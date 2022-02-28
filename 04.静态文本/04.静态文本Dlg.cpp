
// 04.静态文本Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "04.静态文本.h"
#include "04.静态文本Dlg.h"
#include "afxdialogex.h"

//
//#define HBMP(filepath,width,heigth) (HBITMAP) LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,heigth,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

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


// CMy04静态文本Dlg 对话框



CMy04静态文本Dlg::CMy04静态文本Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY04_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy04静态文本Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//关联变量和控件
	DDX_Control(pDX, IDC_TEXT, m_text);
	DDX_Control(pDX, IDC_PIC, m_pic);
	DDX_Control(pDX, IDC_BUTTON_T, m_btn);
}

BEGIN_MESSAGE_MAP(CMy04静态文本Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SET, &CMy04静态文本Dlg::OnBnClickedButtonSet)
	ON_BN_CLICKED(IDC_BUTTON_SHOW, &CMy04静态文本Dlg::OnBnClickedButtonShow)
	ON_BN_CLICKED(IDC_BUTTON_T, &CMy04静态文本Dlg::OnBnClickedButtonT)
END_MESSAGE_MAP()


// CMy04静态文本Dlg 消息处理程序

BOOL CMy04静态文本Dlg::OnInitDialog()
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


	//显示图片
	//设置静态文本框为居中
	m_pic.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取句柄

	//通过路径获取bitmap句柄
#define HBMP(filepath,width,height) (HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置 应该按照控件大小进行取值
	CRect rect;
	m_pic.GetWindowRect(rect);

	m_pic.SetBitmap(HBMP(TEXT("./1.bmp"), rect.Width(), rect.Height()));
		

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy04静态文本Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy04静态文本Dlg::OnPaint()
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
HCURSOR CMy04静态文本Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//点击按钮，重置文本为呵呵呵
void CMy04静态文本Dlg::OnBnClickedButtonSet()
{
	// TODO: 在此添加控件通知处理程序代码

	m_text.SetWindowTextW(TEXT("呵呵呵"));
}


//获取文本中内容，并弹出
void CMy04静态文本Dlg::OnBnClickedButtonShow()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	//获取内容
	m_text.GetWindowTextW(str);
	MessageBox(str);
}



//修改Button内容
void CMy04静态文本Dlg::OnBnClickedButtonT()
{
	// TODO: 在此添加控件通知处理程序代码

	//修改显示内容

	m_btn.SetWindowTextW(TEXT("123456789"));

	//获取内容
	CString str;

	m_btn.GetWindowTextW(str);
	MessageBox(str);

	//设置点击状态
	m_btn.EnableWindow(FALSE);
}
