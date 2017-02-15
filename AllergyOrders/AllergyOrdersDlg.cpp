
// AllergyOrdersDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AllergyOrders.h"
#include "AllergyOrdersDlg.h"
#include "afxdialogex.h"
#include "SearchPatientDlg.h"
#include "SearchDrug.h"
//#include "resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual INT_PTR DoModal();
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


// CAllergyOrdersDlg dialog



CAllergyOrdersDlg::CAllergyOrdersDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ALLERGYORDERS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAllergyOrdersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, patientCntrl);
	DDX_Control(pDX, IDC_EDIT2, drugCntrl);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, dateCntrl);
	DDX_Control(pDX, IDC_LIST1, m_orderList);
}

BEGIN_MESSAGE_MAP(CAllergyOrdersDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT2, &CAllergyOrdersDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CAllergyOrdersDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CAllergyOrdersDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAllergyOrdersDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAllergyOrdersDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CAllergyOrdersDlg message handlers

BOOL CAllergyOrdersDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAllergyOrdersDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAllergyOrdersDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAllergyOrdersDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAllergyOrdersDlg::OnLvnItemchangedList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CAllergyOrdersDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CAllergyOrdersDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString sName;
	SearchPatientDlg spd(this);
	patientCntrl.GetWindowText(sName);

	spd.name = sName;
	
	/*INT_PTR nResponse = spd.DoModal();
	if (nResponse == IDOK)
	{
		spd.DestroyWindow();
	}
	else if (nResponse == IDCANCEL)
	{
		spd.DestroyWindow();
	}
	//this->DoModal();*/
	spd.DoModal();
	patient = spd.patient;
	patientCntrl.SetWindowTextW(patient.getPatientName());
}


void CAllergyOrdersDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CAllergyOrdersDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CString dName;
	drugCntrl.GetWindowTextW(dName);
	SearchDrug sd(this);
	sd.drugName = dName;
	sd.DoModal();
	drug = sd.drug;
	drugCntrl.SetWindowTextW(drug.getDrugName());
}


INT_PTR CAboutDlg::DoModal()
{
	// TODO: Add your specialized code here and/or call the base class

	return CDialogEx::DoModal();
}


void CAllergyOrdersDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	AllergyDisplay ad(this);
	ad.patient = patient;
	ad.drug = drug;
	ad.DoModal();
}
