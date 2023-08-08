// Process.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PinkWard.h"
#include "Process.h"
#include "afxdialogex.h"
#include <TlHelp32.h> // �̰� ���μ������� ���
#include <psapi.h>
#include "ExitProcess.h"
#include <afxwin.h>

#pragma comment(lib, "psapi")  







// CProcess ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CProcess, CDialogEx)




	CProcess::CProcess(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProcess::IDD, pParent)
{



}

CProcess::~CProcess()
{
}

void CProcess::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}


BEGIN_MESSAGE_MAP(CProcess, CDialogEx)
	//	ON_BN_CLICKED(IDC_BUTTON1, &CProcess::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON1, &CProcess::OnBnClickedButton1)
END_MESSAGE_MAP()


// CProcess �޽��� ó�����Դϴ�.








void CProcess::OnBnClickedButton1()
{
	DWORD aProcesses[1024]={0,}, cbNeeded, cProcesses;
	unsigned int i = 0;
	b=0; // ������� �ʱ�ȭ

	CExitProcess *exit = new CExitProcess;//�ڽ� ���̾�α� ��ü ����


	//�������� ���μ����� ��� ���Ѵ�
	if (!EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded))
		return;

	//�������� ���μ����� ������ ���Ѵ�
	cProcesses = cbNeeded / sizeof(DWORD);

	//�� ���μ����� ���� �̸� �� ���μ��� ���̵� ���ϰ� Ÿ�� ���μ����� ������ �����Ų��
	for ( i = 0; i < cProcesses; i++ )
	{
		TCHAR szProcessName[MAX_PATH] = _T("unknown"); //���μ��� �̸��� ���� �迭 �ʱ�ȭ
		HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, aProcesses[i] );
		// ���μ����� �ڵ��� ��´�.
		if (NULL != hProcess )
		{
			HMODULE hMod;
			DWORD cbNeeded;

			if (EnumProcessModules( hProcess, &hMod, sizeof(hMod), &cbNeeded))  
				GetModuleBaseName( hProcess, hMod, szProcessName, sizeof(szProcessName)); //���μ��� �̸��� ���Ѵ�(szProcessName)
		}

		BOOL bRet;
		CString strComp = szProcessName; //���μ��� �̸��� stsrComp����

		//���ؼ� ������ �⺻���μ����� �����Ѵ�.
		if(strComp.MakeLower()!=CString("rundll32.exe").MakeLower() &&strComp.MakeLower()!=CString("taskhost.exe").MakeLower() &&
			strComp.MakeLower()!=CString("wmiprvse.exe").MakeLower() &&strComp.MakeLower()!=CString("dwm.exe").MakeLower() &&
			strComp.MakeLower()!=CString("lsass.exe").MakeLower() &&strComp.MakeLower()!=CString("explorer.exe").MakeLower() &&
			strComp.MakeLower()!=CString("smss.exe").MakeLower() &&strComp.MakeLower()!=CString("hkcmd.exe").MakeLower() &&
			strComp.MakeLower()!=CString("igxpers.exe").MakeLower() &&
			strComp.MakeLower()!=CString("srvany.exe").MakeLower() &&strComp.MakeLower()!=CString("IMEDICTUPADTE.EXE").MakeLower() &&
			strComp.MakeLower()!=CString("StSess.exe").MakeLower() &&strComp.MakeLower()!=CString("LMS.exe").MakeLower() &&
			strComp.MakeLower()!=CString("Bootcamp.exe").MakeLower() &&strComp.MakeLower()!=CString("winlogon.exe").MakeLower() &&
			strComp.MakeLower()!=CString("wuaclt.exe").MakeLower() &&strComp.MakeLower()!=CString("HeciServer.exe").MakeLower() &&
			strComp.MakeLower()!=CString("taskmgr.exe").MakeLower() &&strComp.MakeLower()!=CString("igfxtray.exe").MakeLower() &&
			strComp.MakeLower()!=CString("audiodg.exe").MakeLower() &&strComp.MakeLower()!=CString("KorlME.exe").MakeLower() &&
			strComp.MakeLower()!=CString("csrss.exe").MakeLower() &&strComp.MakeLower()!=CString("RAVCpl64.exe").MakeLower() &&
			strComp.MakeLower()!=CString("dasHost.exe").MakeLower() &&strComp.MakeLower()!=CString("dllhost.exe").MakeLower() &&
			strComp.MakeLower()!=CString("PinkWard.exe").MakeLower() &&	strComp.MakeLower()!=CString("devenv.exe").MakeLower() && 
			strComp.MakeLower()!=CString("MSBulid.exe").MakeLower() &&strComp.MakeLower()!=CString("vcpkgsrv.exe").MakeLower() &&
			strComp.MakeLower()!=CString("conhost.exe").MakeLower() && strComp.MakeLower()!=CString("bdcam64.bin").MakeLower() 
			&& strComp.MakeLower()!=CString("bdcam.exe *32").MakeLower())
		{

			HANDLE hKillProc = OpenProcess(PROCESS_TERMINATE, FALSE, aProcesses[i]);
			if(strComp!="unknown")
				a[b++]=strComp;

			if(hKillProc != NULL)
			{
				DWORD ExitCode = 0;

				GetExitCodeProcess( hKillProc, &ExitCode );
				bRet = TerminateProcess(hKillProc, ExitCode );
				if( bRet )
					WaitForSingleObject(hKillProc, INFINITE);

				CloseHandle(hKillProc);
			}
		}
		CloseHandle( hProcess );
	}


	CExitProcess exitprocess;
	exitprocess.DoModal();
	exitprocess.DestroyWindow();
	OnDestroy(); 
	OnOK();
}





//BOOL CProcess::OnInitDialog()
//{
//	CDialogEx::OnInitDialog();
//	static CFont   font ;  //������� �߰�
//	LOGFONT        LogFont;      
//
//	GetDlgItem(IDC_STATIC1)->GetFont()->GetLogFont(&LogFont);
//
//	LogFont.lfWeight = 500;
//	LogFont.lfHeight = 18 ;
//
//	font.CreateFontIndirect( &LogFont);
//	GetDlgItem(IDC_STATIC1)->SetFont(&font);
//	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
//}
