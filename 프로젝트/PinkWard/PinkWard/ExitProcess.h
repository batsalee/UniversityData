#pragma once
#include "afxwin.h"


// CExitProcess ��ȭ �����Դϴ�.

class CExitProcess : public CDialogEx
{
	DECLARE_DYNAMIC(CExitProcess)

public:
	CExitProcess(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CExitProcess();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListBox ProcessList;
};
