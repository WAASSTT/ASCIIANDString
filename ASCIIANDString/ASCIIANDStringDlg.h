
// ASCIIANDStringDlg.h: 头文件
//

#pragma once


// CASCIIANDStringDlg 对话框
class CASCIIANDStringDlg : public CDialogEx
{
// 构造
public:
	CASCIIANDStringDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ASCIIANDSTRING_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

DECLARE_MESSAGE_MAP()
public:
	CEdit m_editInput;
	CEdit m_editOutput;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
