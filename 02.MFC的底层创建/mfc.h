#include <afxwin.h>  //mfc��ͷ�ļ�

class MyApp: public CWinApp  //CWinAppӦ�ó�ʽ��
{
public:
	//�������
	virtual BOOL InitInstance();


};


class MyFramc:public CFrameWnd //���ڿ����
{
public:
	MyFramc();

	//������
	DECLARE_MESSAGE_MAP();

	//������Ϣ
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnChar(UINT key, UINT, UINT);
	afx_msg void OnPaint();

};
