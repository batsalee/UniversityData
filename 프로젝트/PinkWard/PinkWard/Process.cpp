// Process.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PinkWard.h"
#include "Process.h"
#include "afxdialogex.h"
#include <TlHelp32.h> // 이거 프로세스관련 헤더
#include <psapi.h>
#include "ExitProcess.h"
#include <afxwin.h>

#pragma comment(lib, "psapi")  







// CProcess 대화 상자입니다.

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


// CProcess 메시지 처리기입니다.








void CProcess::OnBnClickedButton1()
{
	DWORD aProcesses[1024]={0,}, cbNeeded, cProcesses;
	unsigned int i = 0;
	b=0; // 멤버변수 초기화

	CExitProcess *exit = new CExitProcess;//자식 다이얼로그 객체 생성


	//실행중인 프로세스를 모두 구한다
	if (!EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded))
		return;

	//실행중인 프로세스의 개수를 구한다
	cProcesses = cbNeeded / sizeof(DWORD);

	//각 프로세스에 대한 이름 및 프로세스 아이디를 구하고 타겟 프로세스를 강제로 종료시킨다
	for ( i = 0; i < cProcesses; i++ )
	{
		TCHAR szProcessName[MAX_PATH] = _T("unknown"); //프로세스 이름을 받을 배열 초기화
		HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, aProcesses[i] );
		// 프로세스의 핸들을 얻는다.
		if (NULL != hProcess )
		{
			HMODULE hMod;
			DWORD cbNeeded;

			if (EnumProcessModules( hProcess, &hMod, sizeof(hMod), &cbNeeded))  
				GetModuleBaseName( hProcess, hMod, szProcessName, sizeof(szProcessName)); //프로세스 이름을 구한다(szProcessName)
		}

		BOOL bRet;
		CString strComp = szProcessName; //프로세스 이름을 stsrComp대입

		//비교해서 윈도우 기본프로세스를 제외한다.
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
//	static CFont   font ;  //여기부터 추가
//	LOGFONT        LogFont;      
//
//	GetDlgItem(IDC_STATIC1)->GetFont()->GetLogFont(&LogFont);
//
//	LogFont.lfWeight = 500;
//	LogFont.lfHeight = 18 ;
//
//	font.CreateFontIndirect( &LogFont);
//	GetDlgItem(IDC_STATIC1)->SetFont(&font);
//	// TODO:  여기에 추가 초기화 작업을 추가합니다.
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
//}
