#include "mfc.h"

MyApp app;  //ȫ��Ӧ�ó���������ҽ���һ��

BOOL MyApp::InitInstance() {
	//��������
	MyFramc* framec = new MyFramc;

	//��ʾ�͸���
	framec->ShowWindow(SW_SHOWNORMAL);
	framec->UpdateWindow();

	m_pMainWnd = framec;//����ָ��Ӧ�ó���������ڵ�ָ��

	return TRUE;  //����������ʼ��
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
	str.Format(TEXT("������%c ��"), key);

	MessageBox(str);

}


void MyFramc::OnPaint()
{

	CPaintDC dc(this);
	dc.TextOutW(100, 100, TEXT("HELLOW"));

	dc.Ellipse(25, 75, 100, 120);

	//MessageBox(L"aaaa");

}

