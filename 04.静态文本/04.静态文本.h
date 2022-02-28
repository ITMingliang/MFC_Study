
// 04.静态文本.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CMy04静态文本App:
// 有关此类的实现，请参阅 04.静态文本.cpp
//

class CMy04静态文本App : public CWinApp
{
public:
	CMy04静态文本App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMy04静态文本App theApp;
