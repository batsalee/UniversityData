// ExitProcess.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PinkWard.h"
#include "ExitProcess.h"
#include "afxdialogex.h"
#include "Process.h"
#include "afxwin.h"


// CExitProcess ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CExitProcess, CDialogEx)

CExitProcess::CExitProcess(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExitProcess::IDD, pParent)
{

}

CExitProcess::~CExitProcess()
{
}

void CExitProcess::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ProcessList);

	for(int i=0;i<((CProcess*)GetParent())->b;i++)
      ProcessList.InsertString(i,((CProcess*)GetParent())->a[i]);
}


BEGIN_MESSAGE_MAP(CExitProcess, CDialogEx)
END_MESSAGE_MAP()


// CExitProcess �޽��� ó�����Դϴ�.
