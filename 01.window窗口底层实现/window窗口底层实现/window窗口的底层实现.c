#include<windows.h>//底层实现窗口的头文件


//6. 处理窗口过程
LRESULT CALLBACK WindowProc(
	HWND hwnd,//消息属于的窗口的句柄
	UINT uMsg,//具体消息名称 WM_XXXX  消息名
	WPARAM wParam,//键盘附加信息
	LPARAM lParam//鼠标附加信息
) {

	switch (uMsg)
	{

	//所有的xxxWindow为结尾的方法，不会进入消息队列，而是直接执行
    case WM_CLOSE:
		DestroyWindow(hwnd);//DestroyWindow发送另外一个消息  WM_DESTROY
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_LBUTTONDOWN://鼠标
	{
		int xPos = LOWORD(lParam);
		int yPost = HIWORD(lParam);

		char buff[1024];

		wsprintf(buff, TEXT("x=%d,y=%d"), xPos, yPost);

		MessageBox(hwnd, TEXT("aaa"), TEXT("鼠标的左键按下"),MB_OK);
		break;
	}

	case WM_KEYDOWN://键盘
	{
		MessageBox(hwnd, TEXT("鼠标的左键按下"), TEXT("鼠标的左键按下"), MB_OK);
		break;
	}

	case WM_PAINT: //绘图
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 100, 100, TEXT("绘画内容"),strlen("绘画内容"));
		EndPaint(hwnd, &ps);
		break;
	}		
	
	}


	//返回值用默认处理方式
	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}


//程序的入口函数

//WINAPI 代表 _stdcal 参数的传递顺序，从右到左依次入栈，并且在函数的返回前，清空堆栈
//WinMain 
int WINAPI WinMain(
	HINSTANCE hInstance, //应用程序实例句柄
	HINSTANCE hPrveInstance,//上一个应用程序的句柄，在Win32环境下，参数一般为null，不起作用
	LPSTR lpCmdLine,//char * argv[]
	int nShowCmd   //显示命令：最大化，最小化，正常
){

	/*1.设计窗口
	2.注册窗口
	3.创建窗口
	4.显示和更新
	5.通过循环取消息
	6.处理消息（窗口过程）*/

	//1.设计窗口
	
	WNDCLASS wc;
	wc.cbClsExtra = 0;//类的额外内存
	wc.cbWndExtra = 0;//窗口的额外内存
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_PEN);//设置背景
	wc.hCursor = LoadCursor(NULL, IDC_HAND);//设置光标，第一个参数为null，代表使用系统提供的默认
	wc.hIcon = LoadIcon(NULL, IDC_HAND);//设置图标，第一个参数为null，代表使用系统提供的默认
	wc.hInstance = hInstance;//应用程式的句柄
	wc.lpfnWndProc = WindowProc;  //回调函数，窗口过程
	wc.lpszClassName = TEXT("WIN");//指定窗口类名称
	wc.lpszMenuName = NULL;//菜单名称
	wc.style = 0; //显示风格，0代表默认风格



	//2.注册窗口
	RegisterClass(&wc);

	//3.创建窗口

	/*[in, optional]  lpClassName, 类名
	[in, optional]  lpWindowName,  标题名
	[in]            dwStyle,   风格，默认：WS_OVERLAPPEDWINDOW
	[in]            x,  显示坐标  默认：CW_USEDEFAULT
	[in]            y,
	[in]            nWidth, 宽度
	[in]            nHeight, 高度
	[in, optional]  hWndParent, 父窗口
	[in, optional]  hMenu, 菜单
	[in, optional]  hInstance, 实例句柄
	[in, optional]  lpParam   附加值 鼠标附加值
	*/
    HWND hwnd =	CreateWindow(wc.lpszClassName,TEXT("WINDOWS"),WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,1000,1000,NULL,NULL, hInstance,NULL);

	//4.显示和更新
	ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);
	//5.通过循环取消息
	// 
	MSG msg;
	while (1)
	{
		if (GetMessage(&msg,NULL,0,0)==FALSE)
		{
			break;
		}
	}
	//翻译消息
	TranslateMessage(&msg);


	//不为FAlSE,则分发消息
	DispatchMessage(&msg);


	return 0;

}