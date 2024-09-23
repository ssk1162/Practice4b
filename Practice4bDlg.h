﻿
// Practice4bDlg.h: 헤더 파일
//

#pragma once
#include "CUnitTableDlg.h"

// CPractice4bDlg 대화 상자
class CPractice4bDlg : public CDialogEx
{
// 생성입니다.
public:
	CPractice4bDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACTICE4B_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double m_dPresentValue;
	double m_dChangeValue;
	CString m_strPresentUnit;
	CString m_strChangeUnit;
	CString m_strUnit;
	CListBox m_listPresentUnit;
	CListBox m_listChangeUnit;
	int m_nUnitSelect;
	afx_msg void OnRadioLength();
	afx_msg void OnRadioWeight();
	void ComputeUnitValue();
	afx_msg void OnChangeEditPresentValue();
	afx_msg void OnSelchangeListPresentUnit();
	afx_msg void OnSelchangeListChangeUnit();
	bool m_bUnitViewed;
	CUnitTableDlg m_dlgUnitTable;
	afx_msg void OnClickedButtonUnitView();
};
