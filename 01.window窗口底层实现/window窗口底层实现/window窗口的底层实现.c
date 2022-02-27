#include<windows.h>//�ײ�ʵ�ִ��ڵ�ͷ�ļ�


//6. �����ڹ���
LRESULT CALLBACK WindowProc(
	HWND hwnd,//��Ϣ���ڵĴ��ڵľ��
	UINT uMsg,//������Ϣ���� WM_XXXX  ��Ϣ��
	WPARAM wParam,//���̸�����Ϣ
	LPARAM lParam//��긽����Ϣ
) {

	switch (uMsg)
	{

	//���е�xxxWindowΪ��β�ķ��������������Ϣ���У�����ֱ��ִ��
    case WM_CLOSE:
		DestroyWindow(hwnd);//DestroyWindow��������һ����Ϣ  WM_DESTROY
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_LBUTTONDOWN://���
	{
		int xPos = LOWORD(lParam);
		int yPost = HIWORD(lParam);

		char buff[1024];

		wsprintf(buff, TEXT("x=%d,y=%d"), xPos, yPost);

		MessageBox(hwnd, TEXT("aaa"), TEXT("�����������"),MB_OK);
		break;
	}

	case WM_KEYDOWN://����
	{
		MessageBox(hwnd, TEXT("�����������"), TEXT("�����������"), MB_OK);
		break;
	}

	case WM_PAINT: //��ͼ
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 100, 100, TEXT("�滭����"),strlen("�滭����"));
		EndPaint(hwnd, &ps);
		break;
	}		
	
	}


	//����ֵ��Ĭ�ϴ���ʽ
	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}


//�������ں���

//WINAPI ���� _stdcal �����Ĵ���˳�򣬴��ҵ���������ջ�������ں����ķ���ǰ����ն�ջ
//WinMain 
int WINAPI WinMain(
	HINSTANCE hInstance, //Ӧ�ó���ʵ�����
	HINSTANCE hPrveInstance,//��һ��Ӧ�ó���ľ������Win32�����£�����һ��Ϊnull����������
	LPSTR lpCmdLine,//char * argv[]
	int nShowCmd   //��ʾ�����󻯣���С��������
){

	/*1.��ƴ���
	2.ע�ᴰ��
	3.��������
	4.��ʾ�͸���
	5.ͨ��ѭ��ȡ��Ϣ
	6.������Ϣ�����ڹ��̣�*/

	//1.��ƴ���
	
	WNDCLASS wc;
	wc.cbClsExtra = 0;//��Ķ����ڴ�
	wc.cbWndExtra = 0;//���ڵĶ����ڴ�
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_PEN);//���ñ���
	wc.hCursor = LoadCursor(NULL, IDC_HAND);//���ù�꣬��һ������Ϊnull������ʹ��ϵͳ�ṩ��Ĭ��
	wc.hIcon = LoadIcon(NULL, IDC_HAND);//����ͼ�꣬��һ������Ϊnull������ʹ��ϵͳ�ṩ��Ĭ��
	wc.hInstance = hInstance;//Ӧ�ó�ʽ�ľ��
	wc.lpfnWndProc = WindowProc;  //�ص����������ڹ���
	wc.lpszClassName = TEXT("WIN");//ָ������������
	wc.lpszMenuName = NULL;//�˵�����
	wc.style = 0; //��ʾ���0����Ĭ�Ϸ��



	//2.ע�ᴰ��
	RegisterClass(&wc);

	//3.��������

	/*[in, optional]  lpClassName, ����
	[in, optional]  lpWindowName,  ������
	[in]            dwStyle,   ���Ĭ�ϣ�WS_OVERLAPPEDWINDOW
	[in]            x,  ��ʾ����  Ĭ�ϣ�CW_USEDEFAULT
	[in]            y,
	[in]            nWidth, ���
	[in]            nHeight, �߶�
	[in, optional]  hWndParent, ������
	[in, optional]  hMenu, �˵�
	[in, optional]  hInstance, ʵ�����
	[in, optional]  lpParam   ����ֵ ��긽��ֵ
	*/
    HWND hwnd =	CreateWindow(wc.lpszClassName,TEXT("WINDOWS"),WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,1000,1000,NULL,NULL, hInstance,NULL);

	//4.��ʾ�͸���
	ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);
	//5.ͨ��ѭ��ȡ��Ϣ
	// 
	MSG msg;
	while (1)
	{
		if (GetMessage(&msg,NULL,0,0)==FALSE)
		{
			break;
		}
	}
	//������Ϣ
	TranslateMessage(&msg);


	//��ΪFAlSE,��ַ���Ϣ
	DispatchMessage(&msg);


	return 0;

}