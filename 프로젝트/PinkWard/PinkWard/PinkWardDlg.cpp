
// PinkWardDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "PinkWard.h"
#include "PinkWardDlg.h"
#include "afxdialogex.h"
#include "Process.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg(); 
// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPinkWardDlg 대화 상자




CPinkWardDlg::CPinkWardDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPinkWardDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPinkWardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPinkWardDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPinkWardDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPinkWardDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CPinkWardDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CPinkWardDlg 메시지 처리기

BOOL CPinkWardDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPinkWardDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPinkWardDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CPinkWardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPinkWardDlg::OnBnClickedButton1()

{
	CString command_list;
	int flag = 0;
	command_list.Format(_T("Shell32.dll, Control_RunDLL Appwiz.cpl,,0"), flag);
	ShellExecute(NULL,_T("open"),_T("Rundll32.exe"), command_list, NULL, SW_SHOW);
}


void CPinkWardDlg::OnBnClickedButton2()
{
	CProcess process;
	process.DoModal();

	process.DestroyWindow();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void DeleteAllFiles(CString szDir) 
{
	CFileFind finder;

	CString filePath = szDir + _T("\\*.*");
	BOOL bFind = finder.FindFile( filePath );

	while( bFind )
	{
		bFind = finder.FindNextFile();

		if( finder.IsDots() || finder.GetFileName() == _T("index.dat") || finder.GetFileName() == _T("Low") ) continue;

		if( finder.IsDirectory() ) {
			DeleteAllFiles( finder.GetFilePath() );
			if( !finder.GetLength() ) RemoveDirectory( finder.GetFilePath() );
		}
		
		CString filePath = finder.GetFilePath();
		DeleteFile(filePath);
	}
	finder.Close();
}

void doRemove(CString rmDir)
{
	DWORD temporaryinternetfilesAttribute = GetFileAttributes(rmDir);	// 내부 파일 삭제 후 폴더 속성 원래대로 되돌리기 위해 저장
	SetFileAttributes(rmDir, FILE_ATTRIBUTE_DIRECTORY);
	DeleteAllFiles(rmDir);
	SetFileAttributes(rmDir, temporaryinternetfilesAttribute);
}

void CPinkWardDlg::OnBnClickedButton3()
{
	// 아래 3줄은 windows 현재 사용자의 이름을 구하는 api함수
	// 디렉터리 경로명에서 사용자의 이름으로 된 폴더가 있어서 사용
	TCHAR wszUserName[100];
	ULONG dwLength=100;
	GetUserName(wszUserName, &dwLength);

	CString rmDir;

	// windows7 인터넷 임시파일 저장 경로
	rmDir = _T("C:\\Users\\") + (CString)wszUserName + _T("\\AppData\\Local\\Microsoft\\Windows\\Temporary Internet Files");
	doRemove(rmDir);

	rmDir = _T("C:\\Users\\") + (CString)wszUserName + _T("\\AppData\\Local\\Microsoft\\Windows\\Temporary Internet Files\\Low");
	doRemove(rmDir);

	rmDir = _T("C:\\Users\\") + (CString)wszUserName + _T("\\AppData\\Roaming\\Microsoft\\Windows\\Cookies");
	doRemove(rmDir);

	rmDir = _T("C:\\Users\\") + (CString)wszUserName + _T("\\AppData\\Roaming\\Microsoft\\Windows\\Cookies\\Low");
	doRemove(rmDir);

	AfxMessageBox(_T("하드디스크 최적화가 완료되었습니다."));
}
