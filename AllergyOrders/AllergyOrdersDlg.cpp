// AllergyOrdersDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AllergyOrders.h"
#include "AllergyOrdersDlg.h"
#include "afxdialogex.h"
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
int CAllergyOrdersDlg::g_nDrugRecordSize = 0;
int CAllergyOrdersDlg::g_nPatientRecordSize = 0;

CAllergyOrdersDlg::CAllergyOrdersDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ALLERGYORDERS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAllergyOrdersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_patientEdt);
	DDX_Control(pDX, IDC_EDIT2, m_drugEdt);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_dateDTCtrl);
	DDX_Control(pDX, IDC_LIST1, m_orderLstCtrl);
	DDX_Control(pDX, IDC_EDIT3, m_commentCtrl);
	DDX_Control(pDX, IDC_BUTTON2, m_searchDrugBtn);
	DDX_Control(pDX, IDC_BUTTON3, m_addBtn);
	DDX_Control(pDX, IDC_OK, m_orderBtn);
	DDX_Control(pDX, IDC_BUTTON1, m_searchPatientBtn);
	DDX_Control(pDX, IDC_BUTTON4, m_removeBtn);
}

BEGIN_MESSAGE_MAP(CAllergyOrdersDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAllergyOrdersDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAllergyOrdersDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAllergyOrdersDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_OK, &CAllergyOrdersDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT2, &CAllergyOrdersDlg::OnEnChangeEdit2)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CAllergyOrdersDlg::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON4, &CAllergyOrdersDlg::OnBnClickedButton4)
	ON_EN_UPDATE(IDC_EDIT1, &CAllergyOrdersDlg::OnEnUpdateEdit1)
END_MESSAGE_MAP()


// CAllergyOrdersDlg message handlers

BOOL CAllergyOrdersDlg::OnInitDialog()
{

	CDialog::OnInitDialog();           // Call default ::OnInitDialog
	setFont();
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

	setIcon(); //Set icons for buttons

	setList();	//set list
	///////////
	//CMFCButton* appButton = new CMFCButton;
	//m_searchPatientBtn.cre
	//m_searchPatientBtn.Create(_T("MfcButton1"), WS_CHILD | WS_VISIBLE, CRect(10, 10, 70, 50), this);
	//m_searchPatientBtn.SetIcon(searchIcon);
	//CFont* font1;
	// in a LOGFONT structure.
	//LOGFONT lf;
	// clear out structure
//	memset(&lf, 0, sizeof(LOGFONT));
	// request a 12-pixel-height font
	//lf.lfHeight = 50;
	// request a face name "Arial"
	//_tcsncpy_s(lf.lfFaceName, LF_FACESIZE, _T("Arial"), 20);

	//CFont font1;
	//font1.CreateFontIndirect(&lf);  // create the font

	//LOGFONT lf;                        // Used to create the CFont.
	//font1=GetFont();
	//CFont *currentFont = GetFont();
	//font1->GetLogFont(&lf);
	//lf.lfHeight = 20;
	//font_.DeleteObject();
	//font1->CreateFontIndirect(&lf);    // Create the font.

									  // Use the font to paint a control.
	//SetFont(&font_);
	//m_searchPatientBtn.SetFont(font1,true);
	//m_searchPatientBtn
		//appButton->GetStyle();



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

/*
This method will get the text entered in the Edit control-m_patientCtrl and call SearchPatientDlg class.
SearchPatientDlg is the dialog class containing MFC dialog to search for a patient.
If user selects a patient from the list in SearchPatientDlg dialog then value selected is mapped into a patient object of this class and patient name is diaplayed in edit control-m_patientCtrl.
*/
void CAllergyOrdersDlg::OnBnClickedButton1()
{
	CInputValidator validator;
	CString sPatientName;
	m_patientEdt.GetWindowText(sPatientName);
	sPatientName.Trim(); 
	if (validator.CheckValid(sPatientName))
	{
		try
		{
			int nRowsize;
			COrderService orderService;
			nRowsize = orderService.SearchPatient(sPatientName,true);
			if (nRowsize == 0)
			{
				MessageBox("No entries with this name.");
				return;
			}
			SearchPatientDlg searchPatientDialogObj(this);
			searchPatientDialogObj.m_sPatientName = sPatientName;

			INT_PTR nResponse = searchPatientDialogObj.DoModal();
			if (nResponse == IDOK)
			{
				m_patientArray.SetAtGrow(g_nPatientRecordSize + 1, searchPatientDialogObj.m_patient);
				m_patientEdt.SetWindowText(m_patientArray[g_nPatientRecordSize + 1].GetPatientName());
				searchPatientDialogObj.DestroyWindow();
				m_searchDrugBtn.EnableWindow(true);
			}
			else if (nResponse == IDCANCEL)
			{
				searchPatientDialogObj.DestroyWindow();
			}

		}
		catch (CException* e)
		{
			MessageBox(_T("Error in patient search"));
			e->Delete();
		}
	}
	else
	{
		MessageBox("Invalid Entry.\nEnter valid patient name.");
	}
}


/*
This method will get the text entered in the Edit control-m_drugCtrl and call SearchDrugDlg dialog class.
SearchDrugis the dialog class containing MFC dialog to search for a drug.
If user selects a drug from the list in SearchDrugDlg dialog then value selected is mapped into a drug object array of this class and current drug name is diaplayed in edit control-m_DrugCtrl.
g_iDrugRecordSize points to current drug object position. To add new object to the array it is made to point to +1 position.
*/

void CAllergyOrdersDlg::OnBnClickedButton2()
{
	CInputValidator validator;
	CString sDrugName;
	m_drugEdt.GetWindowText(sDrugName);
	sDrugName.Trim();
	if (validator.CheckValid(sDrugName))
	{
		try {
			int nRowsize;
			COrderService orderService;
			nRowsize = orderService.SearchDrug(sDrugName, true);
			if (nRowsize == 0)
			{
				MessageBox("No entries with this name.");
				return;
			}
			SearchDrugDlg searchDrugDlgObj(this);
			searchDrugDlgObj.m_sDrugName = sDrugName;
			INT_PTR nResponse = searchDrugDlgObj.DoModal();
			if (nResponse == IDOK)
			{
				m_drugArray.SetAtGrow(g_nDrugRecordSize + 1, searchDrugDlgObj.m_drug);
				m_drugEdt.SetWindowText(m_drugArray[g_nDrugRecordSize + 1].GetDrugName());
				searchDrugDlgObj.DestroyWindow();
				m_addBtn.EnableWindow(true);
			}
			else if (nResponse == IDCANCEL)
			{
				searchDrugDlgObj.DestroyWindow();
			}
		}
		catch (CException* e)
		{
			MessageBox(_T("Error in drug search"));
			e->Delete();
		}
	}
}


INT_PTR CAboutDlg::DoModal()
{
	return CDialogEx::DoModal();
}

/*
The following method:
#1. if search has not been used.
	This method will get the text entered in the Edit controls-m_patientCtrl and m_drugCtrl.
	then it will check if ptient and drug with that name exists.
	#1.1	if both patient and drug exist without any duplicates then the method will add it to list control-m_orderListCtrl
	#1.2	if either patient or drug is not present or more than one record is present for any of them then method returns to AllergyOrderDlg dialog class.
#2. if search has been used for patient or drug then the respective objects would have already been mapped.
	in that case, values will be directly added to list control-m_orderListCtrl.
	*/

void CAllergyOrdersDlg::OnBnClickedButton3()
{
	CString sComment;
	m_commentCtrl.GetWindowText(sComment);
	if (sComment.GetLength() > 100)
	{
		MessageBox("Max length for comment: 100 characters.");
		return;
	}
	AllergyDisplayDlg allergyDisplayDlgObj(this);
	allergyDisplayDlgObj.m_patient = m_patientArray[g_nPatientRecordSize + 1];
	allergyDisplayDlgObj.m_drug = m_drugArray[g_nDrugRecordSize + 1];
	INT_PTR nResponse = allergyDisplayDlgObj.DoModal(m_drugArray,m_patientArray);
	if (nResponse == IDOK)
	{
		int nItem;
		CTime dateCt;
		CString sDate;
		allergyDisplayDlgObj.DestroyWindow();
		//setting orderList with items.
		nItem = m_orderLstCtrl.InsertItem(0,m_patientArray[g_nPatientRecordSize + 1].GetPatientName());
		m_orderLstCtrl.SetItemText(nItem, 1, m_drugArray[g_nDrugRecordSize + 1].GetDrugName());
		m_dateDTCtrl.GetTime(dateCt);
		sDate = dateCt.Format("%Y-%m-%d");
		m_orderLstCtrl.SetItemText(nItem, 2, sDate);
		m_orderLstCtrl.SetItemText(nItem, 3, sComment);
		g_nDrugRecordSize++;
		g_nPatientRecordSize++;
		m_orderBtn.EnableWindow(true);
		m_patientEdt.SetWindowText("");
		m_drugEdt.SetWindowText("");
		m_commentCtrl.SetWindowText("");
	}
	else if (nResponse == IDCANCEL)
	{
		allergyDisplayDlgObj.DestroyWindow();
	}
}

/*
This method is called when order button is clicked.
It inserts the order details  into the order table.
*/
void CAllergyOrdersDlg::OnBnClickedOk()
{
	//OnOK();
	COrderService orderService;
	CString sDate;
	CString sComment;
	//int iPatientId, iDrugId;
	if (g_nDrugRecordSize != 0)
	{
		try
		{
			int j = 1;
			for (int i = 0; i < m_orderLstCtrl.GetItemCount();j++, i++)
			{
				//iPatientId = _ttoi(m_orderLstCtrl.GetItemText(i, 0));
				//iDrugId = _ttoi(m_orderLstCtrl.GetItemText(i, 1));
				sDate = m_orderLstCtrl.GetItemText(i, 2);
				sComment = m_orderLstCtrl.GetItemText(i, 3);
				while (m_patientArray[j].GetPatientId() == NULL) 
					j++;
				orderService.SaveOrders(m_patientArray[j].GetPatientId(), m_drugArray[j].GetDrugId(), sDate, sComment);
			}
			MessageBox(_T("Order placed sucessfully"));
		}
		catch (CException* e)
		{
			MessageBox(_T("Error in placing order."));
			e->Delete();
		}
	}
	else
	{
		MessageBox("Invalid Entry");
	}
	CDialogEx::OnOK();
}


void CAllergyOrdersDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
/*	CWnd* pwndCtrl = GetFocus();
	CWnd* pwndCtrlNext = pwndCtrl;
	int ctrl_ID = pwndCtrl->GetDlgCtrlID();

	CString sFromPatientCtrl;
	int iRowSize;
	COrderService orderService;
	CInputValidator validator;
	CString sFromDrugCtrl;
	switch (ctrl_ID) {
	case IDC_EDIT1:
		m_patientEdt.GetWindowText(sFromPatientCtrl);
		if (sFromPatientCtrl.IsEmpty() | !validator.CheckValid(sFromPatientCtrl))
		{
			MessageBox("Invalid patient entry.");
			return;
		}
		iRowSize = orderService.SearchPatient(sFromPatientCtrl, false);
		if (iRowSize == 0)
		{
			//no patient record available with the entered name
			MessageBox(_T("No patient with this name. Please search and select a patient."));
			return;
		}
		else
		{
			//refer to patient object present in global array
			m_patientArray.SetAtGrow(g_nPatientRecordSize + 1, theApp.m_patientArray[1]);
			m_searchDrugBtn.EnableWindow(true);
			m_drugEdt.SetFocus();
		}

		break;
	case IDC_EDIT2:
		m_drugEdt.GetWindowText(sFromDrugCtrl);
		if (sFromDrugCtrl.IsEmpty() | !validator.CheckValid(sFromDrugCtrl))
		{
			MessageBox("Invalid drug entry.");
			return;
		}
		iRowSize = orderService.SearchDrug(sFromDrugCtrl, false);
		if (iRowSize == 0)
		{
			MessageBox(_T("No drug with this name. Please search and select a drug."));
			return;
		}
		else
		{
			m_drugArray.SetAtGrow(g_nDrugRecordSize + 1, theApp.m_drugArray[1]);
			m_addBtn.EnableWindow(true);
			m_dateDTCtrl.SetFocus();
		}
		break;
	case IDC_DATETIMEPICKER1:
		m_commentCtrl.SetFocus();
		break;
	case IDC_EDIT3:
		m_addBtn.SetFocus();
		break;
	default:
		break;
	}*/
}


void CAllergyOrdersDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sFromDrugCtrl;
	int iRowSize;
	COrderService orderService;
	m_drugEdt.GetWindowText(sFromDrugCtrl);
	if (sFromDrugCtrl.IsEmpty() | (sFromDrugCtrl.GetLength() <3))
	{
		return;
	}
	iRowSize = orderService.SearchDrug(sFromDrugCtrl, true);
	if (iRowSize == 1)
	{
		m_drugArray.SetAtGrow(g_nDrugRecordSize + 1, theApp.m_drugArray[1]);
		m_drugEdt.SetWindowText(theApp.m_drugArray[1].GetDrugName());
		m_addBtn.EnableWindow(true);
		
	}
	
	return;
}









void CAllergyOrdersDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	POSITION pos = m_orderLstCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		m_removeBtn.EnableWindow(false);
	}
	else
		m_removeBtn.EnableWindow(true);
	*pResult = 0;
}


void CAllergyOrdersDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	POSITION pos = m_orderLstCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(_T("No patient was selected. Please select a patient from the list or cancel the search."));
		return;
	}
	else
	{
		CString msg = _T("Do you want to delete the order?");
		CString title = _T("Confirm");
		if (MessageBoxA(msg,title,MB_YESNO) == IDYES)
		{
			int item = m_orderLstCtrl.GetNextSelectedItem(pos);
			m_orderLstCtrl.DeleteItem(item);
			m_patientArray.RemoveAt(item,1);
			m_drugArray.RemoveAt(item, 1);
		}
			int nItem = m_orderLstCtrl.GetNextSelectedItem(pos);
			
	}
}


///////////////////////////////////////////////////
////////////////////Functions
//////////////////////////////////////

void CAllergyOrdersDlg::setFont()
{
	//setting font for buttons
	LOGFONT lf;                        // Used to create the CFont.


	memset(&lf, 0, sizeof(LOGFONT));   // Clear out structure.
	lf.lfHeight = 20;                  // Request a 20-pixel-high font
	strcpy_s(lf.lfFaceName, "Arial");    //    with face name "Arial".
	m_font.CreateFontIndirect(&lf);    // Create the font
	GetDlgItem(IDC_BUTTON1)->SetFont(&m_font); //set font for search patient
	GetDlgItem(IDC_BUTTON2)->SetFont(&m_font);//set font for search drug
	GetDlgItem(IDC_BUTTON3)->SetFont(&m_font);//set font for add order
	GetDlgItem(IDC_BUTTON4)->SetFont(&m_font);//set font for remove order
}

void CAllergyOrdersDlg::setIcon()
{
	// set icon for search buttons
	HICON searchIcon;
	searchIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
	m_searchDrugBtn.SetIcon(searchIcon);
	m_searchPatientBtn.SetIcon(searchIcon);
	HICON addIcon;
	addIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	//addIcon = (HICON)::LoadImage(GetModuleHandle("Wizards.dll"), MAKEINTRESOURCE(IDC_BUTTON3), IDI_ICON1, 16, 16, 0);
	//addIcon = (HICON)LoadImage(hInstance, MAKEINTRESOURCE(1), IMAGE_ICON,::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON), 0);
	m_addBtn.SetIcon(addIcon);
	HICON minusIcon;
	minusIcon = AfxGetApp()->LoadIcon(IDI_ICON3);
	m_removeBtn.SetIcon(minusIcon);
}

void CAllergyOrdersDlg::setList()
{
	/*
	The following code will set headings for the list control which displays the orders to be placed.
	*/
	m_orderLstCtrl.SetExtendedStyle(m_orderLstCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	try
	{
		m_orderLstCtrl.InsertColumn(0, _T("Patient Name"), LVCFMT_LEFT, 150);
		m_orderLstCtrl.InsertColumn(1, _T("Drug Name"), LVCFMT_LEFT, 200);
		m_orderLstCtrl.InsertColumn(2, _T("Date"), LVCFMT_LEFT, 150);
		m_orderLstCtrl.InsertColumn(3, _T("Comment"), LVCFMT_LEFT, 200);
	}
	catch (CException* e)
	{
		MessageBox(_T("Error creating List Control"));
		e->Delete();
		this->DestroyWindow();
	}
}




void CAllergyOrdersDlg::OnEnUpdateEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.

	// TODO:  Add your control notification handler code here
	CString sFromPatientCtrl;
	int iRowSize;
	COrderService orderService;
	m_patientEdt.GetWindowText(sFromPatientCtrl);
	if (sFromPatientCtrl.IsEmpty() | (sFromPatientCtrl.GetLength() <3))
	{
		return;
	}
	iRowSize = orderService.SearchPatient(sFromPatientCtrl, true);
	if (iRowSize == 1)
	{
		m_patientArray.SetAtGrow(g_nPatientRecordSize + 1, theApp.m_patientArray[1]);
		m_patientEdt.SetWindowText(theApp.m_patientArray[1].GetPatientName());
		m_searchDrugBtn.EnableWindow(true);
	}
	return;
}
