
// PinkWard.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPinkWardApp:
// �� Ŭ������ ������ ���ؼ��� PinkWard.cpp�� �����Ͻʽÿ�.
//

class CPinkWardApp : public CWinApp
{
public:
	CPinkWardApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPinkWardApp theApp;