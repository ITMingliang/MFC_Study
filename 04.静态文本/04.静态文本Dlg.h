
// 04.静态文本Dlg.h: 头文件
//

#pragma once


// CMy04静态文本Dlg 对话框
class CMy04静态文本Dlg : public CDialogEx
{
// 构造
public:
	CMy04静态文本Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY04_DIALOG };
#endif

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
	//设置文本
	afx_msg void OnBnClickedButtonSet();
	//显示文本
	afx_msg void OnBnClickedButtonShow();
	//获取文本 + 设置按钮的状态
	afx_msg void OnBnClickedButtonT();
private:
	// 哈哈哈静态文本框
	CStatic m_text;
	// 图片静态框
	CStatic m_pic;
	// 修改按钮文本
	CButton m_btn;
};
