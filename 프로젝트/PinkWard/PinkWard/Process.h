#pragma once
#include "afxwin.h"


// CProcess ��ȭ �����Դϴ�.

class CProcess : public CDialogEx
{
	DECLARE_DYNAMIC(CProcess)

public:
	CProcess(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CProcess();
	
	

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_Process };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedButton1();
	DWORD b;
	CString a[200];
	
//	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
//	virtual BOOL OnInitDialog();
};
