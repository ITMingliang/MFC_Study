#include <afxwin.h>  //mfc的头文件

class MyApp: public CWinApp  //CWinApp应用程式类
{
public:
	//程序入口
	virtual BOOL InitInstance();


};


class MyFramc:public CFrameWnd //窗口框架类
{
public:
	MyFramc();

	//声明宏
	DECLARE_MESSAGE_MAP();

	//声明消息
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnChar(UINT key, UINT, UINT);
	afx_msg void OnPaint();

};
