#include "mfc.h"

MyApp app;  //全局应用程序对象，有且仅有一个

BOOL MyApp::InitInstance() {
	//创建窗口
	MyFramc* framec = new MyFramc;

	//显示和更新
	framec->ShowWindow(SW_SHOWNORMAL);
	framec->UpdateWindow();

	m_pMainWnd = framec;//保存指向应用程序的主窗口的指针

	return TRUE;  //返回正常初始化
}

 BEGIN_MESSAGE_MAP(MyFramc, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
    ON_WM_PAINT()

 END_MESSAGE_MAP()

MyFramc::MyFramc() {
	Create(NULL, TEXT("mfc"));
}


void MyFramc::OnLButtonDown(UINT, CPoint point) 
{
	TCHAR buff[1024];
	wsprintf(buff, TEXT("x=%d,y=%d"), point.x, point.y);

	/*CString str;
	str.Format(TEXT("x=%d,,,,,y=%d"), point.x, point.y);*/

	MessageBox(buff);

}


void MyFramc::OnChar(UINT key, UINT, UINT)
{
	
	CString str;
	str.Format(TEXT("按下了%c 键"), key);

	MessageBox(str);

}


void MyFramc::OnPaint()
{

	CPaintDC dc(this);
	dc.TextOutW(100, 100, TEXT("HELLOW"));

	dc.Ellipse(25, 75, 100, 120);

	//MessageBox(L"aaaa");

}

