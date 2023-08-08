#pragma once
#include "afxwin.h"


// CProcess 대화 상자입니다.

class CProcess : public CDialogEx
{
	DECLARE_DYNAMIC(CProcess)

public:
	CProcess(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CProcess();
	
	

// 대화 상자 데이터입니다.
	enum { IDD = IDD_Process };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedButton1();
	DWORD b;
	CString a[200];
	
//	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
//	virtual BOOL OnInitDialog();
};
