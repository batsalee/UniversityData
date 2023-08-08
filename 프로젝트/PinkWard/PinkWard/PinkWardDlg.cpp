
// PinkWardDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "PinkWard.h"
#include "PinkWardDlg.h"
#include "afxdialogex.h"
#include "Process.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg(); 
// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CPinkWardDlg ��ȭ ����




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


// CPinkWardDlg �޽��� ó����

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

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CPinkWardDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	DWORD temporaryinternetfilesAttribute = GetFileAttributes(rmDir);	// ���� ���� ���� �� ���� �Ӽ� ������� �ǵ����� ���� ����
	SetFileAttributes(rmDir, FILE_ATTRIBUTE_DIRECTORY);
	DeleteAllFiles(rmDir);
	SetFileAttributes(rmDir, temporaryinternetfilesAttribute);
}

void CPinkWardDlg::OnBnClickedButton3()
{
	// �Ʒ� 3���� windows ���� ������� �̸��� ���ϴ� api�Լ�
	// ���͸� ��θ��� ������� �̸����� �� ������ �־ ���
	TCHAR wszUserName[100];
	ULONG dwLength=100;
	GetUserName(wszUserName, &dwLength);

	CString rmDir;

	// windows7 ���ͳ� �ӽ����� ���� ���
	rmDir = _T("C:\\Users\\") + (CString)wszUserName + _T("\\AppData\\Local\\Microsoft\\Windows\\Temporary Internet Files");
	doRemove(rmDir);

	rmDir = _T("C:\\Users\\") + (CString)wszUserName + _T("\\AppData\\Local\\Microsoft\\Windows\\Temporary Internet Files\\Low");
	doRemove(rmDir);

	rmDir = _T("C:\\Users\\") + (CString)wszUserName + _T("\\AppData\\Roaming\\Microsoft\\Windows\\Cookies");
	doRemove(rmDir);

	rmDir = _T("C:\\Users\\") + (CString)wszUserName + _T("\\AppData\\Roaming\\Microsoft\\Windows\\Cookies\\Low");
	doRemove(rmDir);

	AfxMessageBox(_T("�ϵ��ũ ����ȭ�� �Ϸ�Ǿ����ϴ�."));
}
