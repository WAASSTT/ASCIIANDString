
// ASCIIANDStringDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "ASCIIANDString.h"
#include "ASCIIANDStringDlg.h"

#include <string>
#include <vector>

#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CASCIIANDStringDlg 对话框



CASCIIANDStringDlg::CASCIIANDStringDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ASCIIANDSTRING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CASCIIANDStringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editInput);
	//  DDX_Control(pDX, IDCANCEL, m_editOutput);
	//  DDX_Control(pDX, IDC_EDIT2, m_editOutput);
	DDX_Control(pDX, IDC_EDIT2, m_editOutput);
}

BEGIN_MESSAGE_MAP(CASCIIANDStringDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CASCIIANDStringDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CASCIIANDStringDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CASCIIANDStringDlg 消息处理程序

BOOL CASCIIANDStringDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON);
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	 // 将默认按钮设为NULL
	CWnd* pDefBtn = GetDlgItem(IDOK);
	if (pDefBtn != nullptr) {
		pDefBtn->SendMessage(BM_SETSTYLE, BS_PUSHBUTTON, TRUE);
		pDefBtn->ModifyStyle(0, BS_DEFPUSHBUTTON);
		pDefBtn->SetFocus();
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

BOOL CASCIIANDStringDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) {
		// 如果按下了回车键，则不响应该事件
		CWnd* pFocus = GetFocus();
		if (pFocus != nullptr && pFocus->IsKindOf(RUNTIME_CLASS(CEdit))) {
			// 如果当前焦点在编辑框中，则不禁止回车键
			return CDialog::PreTranslateMessage(pMsg);
		}
		return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CASCIIANDStringDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CASCIIANDStringDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CASCIIANDStringDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CASCIIANDStringDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strInput;
	// 获取CEdit控件中输入的字符
	m_editInput.GetWindowText(strInput);
	if (strInput.IsEmpty()) {
		// 如果用户没有输入，弹出提示对话框
		AfxMessageBox(_T("请输入字符或字符串！"));
		return;
	}
	if (strInput.FindOneOf(_T("\r\n")) != -1) {
		// 包含换行符
		strInput.Replace(_T("\r\n"), _T(""));
	}
	else {
		// 不包含换行符
	}
	// 将字符转换为Unicode
	USES_CONVERSION;
	wchar_t* pszUnicode = new wchar_t[strInput.GetLength() + 1];
	char* postJsonAlarmCstr2T2A = T2A(strInput);
	::MultiByteToWideChar(CP_ACP, 0, postJsonAlarmCstr2T2A, -1, pszUnicode, strInput.GetLength() + 1);
	pszUnicode[strInput.GetLength()] = L'\0';

	// 将Unicode字符串转换为十进制数值
	CString strUnicode;
	for (int i = 0; i < strInput.GetLength(); i++) {
		CString strChar;
		unsigned int nUnicodeValue = pszUnicode[i];
		if (i == strInput.GetLength() - 1)
		{
			strChar.Format(_T("%d"), nUnicodeValue);
		}
		else {
			strChar.Format(_T("%d,\r\n"), nUnicodeValue);
		}
		strUnicode += strChar;
	}
	// 输出结果
	m_editOutput.SetWindowText(strUnicode);
	m_editInput.UpdateData(false);
	// 释放内存
	delete[] pszUnicode;
}


void CASCIIANDStringDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strInput;
	// 获取CEdit控件中输入的十六进制字符串
	m_editInput.GetWindowText(strInput);
	if (strInput.IsEmpty()) {
		// 如果用户没有输入，弹出提示对话框
		AfxMessageBox(_T("请输入一个十进制编码,每个编码按逗号分隔！"));
		return;
	}
	if (strInput.FindOneOf(_T("\r\n")) != -1) {
		// 包含换行符
		strInput.Replace(_T("\r\n"), _T(""));
	}
	else {
		// 不包含换行符
	}
	if (strInput.FindOneOf(_T(" ")) != -1)
	{
		strInput.Replace(_T(" "), _T(""));
	}
	CString strResult;
	std::vector<CString> tokens;
	CString delimiter = _T(",");
	int pos = 0;
	LPCTSTR str = strInput.GetString();
	while (*str != _T('\0')) {
		LPCTSTR p = _tcsstr(str + pos, delimiter);  // 查找分隔符在字符串中的位置
		if (p == nullptr) {
			// 分隔符不存在，将剩余部分作为最后一个子串
			CString last_token = str + pos;
			if (!last_token.IsEmpty()) {
				tokens.push_back(last_token);
			}
			break;
		}

		// 取出分割出来的子串，并添加到列表中
		CString token(str + pos, p - str - pos);
		if (!token.IsEmpty()) {
			tokens.push_back(token);
		}
		pos = p - str + _tcslen(delimiter);  // 更新查找的起始位置
	}
	// 处理空字符串的情况
	if (*str == _T('\0')) {
		tokens.push_back(_T(""));
	}
	// 转换每个编码为字符
	for (int i = 0; i < tokens.size(); i++) {
		// 将Unicode字符转换为多字节字符
		CString hex_str;
		hex_str.Format(_T("%04X"), _ttoi(tokens[i]));  // 将10进制数转换为4位16进制数
		wchar_t wc = _tcstoul(hex_str, nullptr, 16);  // 将16进制数转换为宽字符型
		CString szMultiByte(wc);  // 将宽字符型转换为CString
		// 添加到结果字符串
		strResult += szMultiByte;
	}
	m_editOutput.SetWindowText(strResult);
	m_editInput.UpdateData(false);
}
