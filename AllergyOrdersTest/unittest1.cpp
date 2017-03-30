#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AllergyOrders/AllergyOrdersDlg.h"
#include "../AllergyOrders/AllergyOrdersDlg.cpp"
#include "../AllergyOrders/SearchDrugDlg.h"
#include "../AllergyOrders/SearchDrugDlg.cpp"
#include "../AllergyOrders/SearchPatientDlg.h"
#include "../AllergyOrders/SearchPatientDlg.cpp"
#include "../AllergyOrders/AllergyDisplayDlg.h"
#include "../AllergyOrders/AllergyDisplayDlg.cpp"
#include "../AllergyOrders/AllergyOrders.h"
#include "../AllergyOrders/AllergyOrders.cpp"
#include "../AllergyOrders/CDrug.h"
#include "../AllergyOrders/CDrug.cpp"
#include "../AllergyOrders/CPatient.h"
#include "../AllergyOrders/CPatient.cpp"
#include "../AllergyOrders/CDBConnection.h"
#include "../AllergyOrders/CDBConnection.cpp"
#include "../AllergyOrders/COrderService.h"
#include "../AllergyOrders/COrderService.cpp"
#include "../AllergyOrders/InputValidator.h"
#include "../AllergyOrders/InputValidator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AllergyOrdersTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		//test for: GetPatientDrugInteractionRecordSize(patientId, drugId) of CDBConnection class
		//case: valid patient ID and valid drug ID
		//result: 1
		TEST_METHOD(TestGetPatientDrugInteractionRecordSizeValid)
		{
			CDBConnection conn;
			Assert::AreEqual(1, conn.GetPatientDrugInteractionRecordSize(1, 1));
		}
		//test for: GetPatientDrugInteractionRecordSize(patientId, drugId) method of CDBConnection class
		//case: invalid patient ID and valid drug ID
		//result: 0
		TEST_METHOD(TestGetPatientDrugInteractionRecordSizeInvalidPatient)
		{
			CDBConnection conn;
			Assert::AreEqual(0, conn.GetPatientDrugInteractionRecordSize(10, 1));
		}
		//test for: GetPatientDrugInteractionRecordSize(patientId, drugId) method of CDBConnection class
		//case: valid patient ID and invalid drug ID
		//result: 0
		TEST_METHOD(TestGetPatientDrugInteractionRecordSizeInvalidDrug)
		{
			CDBConnection conn;
			Assert::AreEqual(0, conn.GetPatientDrugInteractionRecordSize(1, 10));
		}
		//test for: GetPatientDrugInteractionRecordSize(patientId, drugId) method of CDBConnection class
		//case: invalid patient ID and invalid drug ID
		//result: 0
		TEST_METHOD(TestGetPatientDrugInteractionRecordSizeInvalidPatientDrug)
		{
			CDBConnection conn;
			Assert::AreEqual(0, conn.GetPatientDrugInteractionRecordSize(10, 10));
		}
		//test for: GetDrugInteractionRecordSize(drugId) method of CDBConnection class
		//case: valid drug ID
		//result: 1
		TEST_METHOD(TestGetDrugInteractionRecordSizeValid)
		{
			CDBConnection conn;
			Assert::AreEqual(1, conn.GetDrugInteractionRecordSize(2));
		}
		//test for: GetDrugInteractionRecordSize(drugId) method of CDBConnection class
		//case: invalid drug ID
		//result: 0
		TEST_METHOD(TestGetDrugInteractionRecordSizeInvalid)
		{
			CDBConnection conn;
			Assert::AreEqual(0, conn.GetDrugInteractionRecordSize(10));
		}
		//test for: ListPatientDrugInteraction(patientId, drugId) method of COrderService class
		//case: valid patient ID and valid drug ID
		//result: 1
		TEST_METHOD(TestListPatientDrugInteractionValid)
		{
			COrderService ser;
			Assert::AreEqual(1, ser.ListPatientDrugInteraction(1,1));
		}
		//test for: ListPatientDrugInteraction(patientId, drugId) method of COrderService class
		//case: invalid patient ID and valid drug ID
		//result: 0
		TEST_METHOD(TestListPatientDrugInteractionInvalidPatientId)
		{
			COrderService ser;
			Assert::AreEqual(0, ser.ListPatientDrugInteraction(10, 1));
		}
		//test for: ListPatientDrugInteraction(patientId, drugId) method of COrderService class
		//case: valid patient ID and invalid drug ID
		//result: 0
		TEST_METHOD(TestListPatientDrugInteractionInvalidDrugId)
		{
			COrderService ser;
			Assert::AreEqual(0, ser.ListPatientDrugInteraction(1, 10));
		}
		//test for: ListPatientDrugInteraction(patientId, drugId) method of COrderService class
		//case: invalid patient ID and invalid drug ID
		//result: 0
		TEST_METHOD(TestListPatientDrugInteractionInvalidPatientIdDrugId)
		{
			COrderService ser;
			Assert::AreEqual(0, ser.ListPatientDrugInteraction(10, 10));
		}
		//test for: ListDrugDrugInteraction(drugId) method of COrderService class
		//case: valid drug ID
		//result: 1
		TEST_METHOD(TestListDrugDrugInteractionValid)
		{
			COrderService ser;
			Assert::AreEqual(1, ser.ListDrugDrugInteraction(2));
		}
		//test for: ListDrugDrugInteraction(drugId) method of COrderService class
		//case: invalid drug ID
		//result: 0
		TEST_METHOD(TestListDrugDrugInteractionInvalid)
		{
			COrderService ser;
			Assert::AreEqual(0, ser.ListDrugDrugInteraction(10));
		}
		//test for: SearchPatient(sPatientName, bSearch) method of COrderService class
		//case: valid string for patient name and search flag(bSearch) is set to true
		//result: integer greater than 0
		TEST_METHOD(TestSearchPatientValid)
		{
			COrderService ser;
			Assert::AreNotEqual(0, ser.SearchPatient(_T("anirudh"), false));
		}
		//test for: SearchPatient(sPatientName, bSearch) method of COrderService class
		//case: invalid string for patient name and search flag(bSearch) is set to false
		//result: 0
		TEST_METHOD(TestSearchPatientInvalid)
		{
			COrderService ser;
			Assert::AreEqual(0, ser.SearchPatient(_T("abc"), false));
		}
		//test for: SearchPatient(sPatientName, bSearch) method of COrderService class
		//case: invalid string for patient name and search flag(bSearch) is set to false
		//result: 0
		TEST_METHOD(TestSearchPatientValidMultiple)
		{
			COrderService ser;
			Assert::AreEqual(0, ser.SearchPatient(_T("a"), false));
		}
		//test for: SearchDrug(sDrugName, bSearch) method of COrderService class
		//case: invalid string as drug name  and search flag(bSearch) is set to false
		//result: integer greater than 0
		TEST_METHOD(TestSearchDrugtValid)
		{
			COrderService ser;
			Assert::AreNotEqual(0, ser.SearchDrug(_T("aspirin"), false));
		}
		//test for: SearchDrug(sDrugName, bSearch) method of COrderService class
		//case: invalid string as drug name  and search flag(bSearch) is set to false
		//result: 0
		TEST_METHOD(TestSearchDrugInvalid)
		{
			COrderService ser;
			Assert::AreEqual(0, ser.SearchDrug(_T("abc"), false));
		}
		//test for: SearchDrug(sDrugName, bSearch) method of COrderService class
		//case: invalid string as drug name  and search flag(bSearch) is set to false
		//result: 0
		TEST_METHOD(TestSearchDrugValidMultiple)
		{
			COrderService ser;
			Assert::AreEqual(0, ser.SearchDrug(_T("a"), false));
		}
		//test for: GetPatientRecordSize(sPatientName, bSearch) method of CDBConnection class
		//case: valid string as patient name and search flag(bSearch) is set to false
		//result: integer greater than 0
		TEST_METHOD(TestGetPatientRecordSizeValid)
		{
			CDBConnection conn;
			Assert::AreNotEqual(0, conn.GetPatientRecordSize(_T("anirudh"), false));
		}
		//test for: GetPatientRecordSize(sPatientName, bSearch) method of CDBConnection class
		//case: invalid string as patient name and search flag(bSearch) is set to false
		//result: 0
		TEST_METHOD(TestGetPatientRecordSizeInvalid)
		{
			CDBConnection conn;
			Assert::AreEqual(0, conn.GetPatientRecordSize(_T("abc"), false));
		}
		//test for: GetPatientRecordSize(sPatientName, bSearch) method of CDBConnection class
		//case: invalid string as patient name and search flag(bSearch) is set to false
		//result: 0
		TEST_METHOD(TestGetPatientRecordSizeValidMultiple)
		{
			CDBConnection conn;
			Assert::AreEqual(0, conn.GetPatientRecordSize(_T("a"), false));
		}
		//test for: GetDrugRecordSize(sDrugName, bSearch) method of CDBConnection class
		//case: valid string as drug name and search flag(bSearch) is set to false
		//result: 1
		TEST_METHOD(TestGetDrugRecordSizeValid)
		{
			CDBConnection conn;
			Assert::AreEqual(1, conn.GetDrugRecordSize(_T("asthalin"), false));
		}
		//test for: GetDrugRecordSize(sDrugName, bSearch) method of CDBConnection class
		//case: invalid string as drug name and search flag(bSearch) is set to false
		//result: 0
		TEST_METHOD(TestGetDrugRecordSizeInvalid)
		{
			CDBConnection conn;
			Assert::AreEqual(0, conn.GetDrugRecordSize(_T("abc"), false));
		}
		//test for: GetDrugRecordSize(sDrugName, bSearch) method of CDBConnection class
		//case: invalid string as drug name and search flag(bSearch) is set to false
		//result: 0
		TEST_METHOD(TestGetDrugRecordSizeValidMultiple)
		{
			CDBConnection conn;
			Assert::AreEqual(0, conn.GetDrugRecordSize(_T("a"), false));
		}
		//test for: SearchPatient(sPatientName, bSearch) method of COrderService class
		//case: valid string for patient name and search flag(bSearch) is set to true
		//result: integer greater than 0
		TEST_METHOD(TestSearchPatientValidWithSearch)
		{
			COrderService ser;
			Assert::AreNotEqual(0, ser.SearchPatient(_T("anirudh"), true));
		}
		//test for: SearchPatient(sPatientName, bSearch) method of COrderService class
		//case: invalid string for patient name and search flag(bSearch) is set to true
		//result: 0
		TEST_METHOD(TestSearchPatientInvalidWithSearch)
		{
			COrderService ser;
			Assert::AreEqual(0, ser.SearchPatient(_T("abc"), true));
		}
		//test for: SearchPatient(sPatientName, bSearch) method of COrderService class
		//case: valid string for patient name and search flag(bSearch) is set to true
		//result: integer greater than 0
		TEST_METHOD(TestSearchPatientValidMultipleWithSearch)
		{
			COrderService ser;
			Assert::AreNotEqual(0, ser.SearchPatient(_T("a"), true));
		}
		//test for: GetDrugRecordSize(sDrugName, bSearch) method of COrderService class
		//case: valid string as drug name and search flag(bSearch) is set to true
		//result: 1
		TEST_METHOD(TestSearchDrugtValidWithSearch)
		{
			COrderService ser;
			Assert::AreEqual(1, ser.SearchDrug(_T("aspirin"), true));
		}
		//test for: GetDrugRecordSize(sDrugName, bSearch) method of COrderService class
		//case: invalid string as drug name and search flag(bSearch) is set to true
		//result: 0
		TEST_METHOD(TestSearchDrugInvalidWithSearch)
		{
			COrderService ser;
			Assert::AreEqual(0, ser.SearchDrug(_T("abc"), true));
		}
		//test for: GetDrugRecordSize(sDrugName, bSearch) method of COrderService class
		//case: valid string as drug name  and search flag(bSearch) is set to true
		//result: integer greater than 0
		TEST_METHOD(TestSearchDrugValidMultipleWithSearch)
		{
			COrderService ser;
			Assert::AreNotEqual(0, ser.SearchDrug(_T("a"), true));
		}
		//test for: GetPatientRecordSize(sPatientName, bSearch) method of CDBConnection class
		//case: valid string as patient name and search flag(bSearch) is set to true
		//result: integer that is greater than 0
		TEST_METHOD(TestGetPatientRecordSizeValidWithSearch)
		{
			CDBConnection conn;
			Assert::AreNotEqual(0, conn.GetPatientRecordSize(_T("anirudh"), true));
		}
		//test for: GetPatientRecordSize(sPatientName, bSearch) method of CDBConnection class
		//case: invalid string as patient name and search flag(bSearch) is set to true
		//result: 0
		TEST_METHOD(TestGetPatientRecordSizeInvalidWithSearch)
		{
			CDBConnection conn;
			Assert::AreEqual(0, conn.GetPatientRecordSize(_T("abc"), true));
		}
		//test for: GetPatientRecordSize(sPatientName, bSearch) method of CDBConnection class
		//case: valid string as patient name and search flag(bSearch) is set to true
		//result: integer greater than 1
		TEST_METHOD(TestGetPatientRecordSizeValidMultipleWithSearch)
		{
			CDBConnection conn;
			Assert::AreNotEqual(0, conn.GetPatientRecordSize(_T("a"), true));
		}
		//test for: GetDrugRecordSize(sDrugName, bSearch) method of CDBConnection class
		//case: valid string as drug name and search flag(bSearch) is set to true
		//result: 1
		TEST_METHOD(TestGetDrugRecordSizeValidWithSearch)
		{
			CDBConnection conn;
			Assert::AreEqual(1, conn.GetDrugRecordSize(_T("asthalin"), true));
		}
		//test for: GetDrugRecordSize(sDrugName, bSearch) method of CDBConnection class
		//case: invalid string as drug name and search flag(bSearch) is set to true
		//result: integer greater than 0
		TEST_METHOD(TestGetDrugRecordSizeInvalidWithSearch)
		{
			CDBConnection conn;
			Assert::AreEqual(0, conn.GetDrugRecordSize(_T("abc"), true));
		}
		//test for: GetDrugRecordSize(sDrugName, bSearch) method of CDBConnection class
		//case: valid string as drug name and search flag(bSearch) is set to true
		//result: integer greater than 0
		TEST_METHOD(TestGetDrugRecordSizeValidMultipleWithSearch)
		{
			CDBConnection conn;
			Assert::AreNotEqual(0, conn.GetDrugRecordSize(_T("a"), true));
		}
		//test for: CheckValid(sValue) method of CInputValidator class
		//case: valid string as parameter
		//result: false
		TEST_METHOD(TestCheckValid1)
		{
			CInputValidator validator;
			Assert::AreNotEqual(false, validator.CheckValid(_T("abc")));
		}
		//test for: CheckValid(sValue) method of CInputValidator class
		//case: valid string as parameter
		//result: false
		TEST_METHOD(TestCheckValid2)
		{
			CInputValidator validator;
			Assert::AreNotEqual(false, validator.CheckValid(_T("123")));
		}
		//test for: CheckValid(sValue) method of CInputValidator class
		//case: valid string as parameter
		//result: false
		TEST_METHOD(TestCheckValid3)
		{
			CInputValidator validator;
			Assert::AreNotEqual(false, validator.CheckValid(_T(" ")));
		}
		//test for: CheckValid(sValue) method of CInputValidator class
		//case: valid string as parameter
		//result: false
		TEST_METHOD(TestCheckValid4)
		{
			CInputValidator validator;
			Assert::AreNotEqual(false, validator.CheckValid(_T("abc12")));
		}
		//test for: CheckValid(sValue) method of CInputValidator class
		//case: valid string as parameter
		//result: false
		TEST_METHOD(TestCheckValid5)
		{
			CInputValidator validator;
			Assert::AreNotEqual(false, validator.CheckValid(_T("abc ")));
		}
		//test for: CheckValid(sValue) method of CInputValidator class
		//case: valid string as parameter
		//result: false
		TEST_METHOD(TestCheckValid6)
		{
			CInputValidator validator;
			Assert::AreNotEqual(false, validator.CheckValid(_T("12abc")));
		}
		//test for: CheckValid(sValue) method of CInputValidator class
		//case: valid string as parameter
		//result: false
		TEST_METHOD(TestCheckValid7)
		{
			CInputValidator validator;
			Assert::AreNotEqual(false, validator.CheckValid(_T("12 ")));
		}
		//test for: CheckValid(sValue) method of CInputValidator class
		//case: valid string as parameter
		//result: false
		TEST_METHOD(TestCheckValid8)
		{
			CInputValidator validator;
			Assert::AreNotEqual(false, validator.CheckValid(_T(" abc")));
		}
		//test for: CheckValid(sValue) method of CInputValidator class
		//case: valid string as parameter
		//result: false
		TEST_METHOD(TestCheckValid9)
		{
			CInputValidator validator;
			Assert::AreNotEqual(false, validator.CheckValid(_T(" 123")));
		}
		//test for: CheckValid(sValue) method of CInputValidator class
		//case: valid string as parameter
		//result: false
		TEST_METHOD(TestCheckValid10)
		{
			CInputValidator validator;
			Assert::AreNotEqual(false, validator.CheckValid(_T("abc123 ")));
		}
		//test for: CheckValid(sValue) method of CInputValidator class
		//case: invalid string as parameter
		//result: false
		TEST_METHOD(TestCheckValidInvalid1)
		{
			CInputValidator validator;
			Assert::AreEqual(false, validator.CheckValid(_T("@123")));
		}
		//test for: CheckValid(sValue) method of CInputValidator class
		//case: invalid string as parameter
		//result: false
		TEST_METHOD(TestCheckValidInvalid2)
		{
			CInputValidator validator;
			Assert::AreEqual(false, validator.CheckValid(_T("abc.")));
		}
		//test for: CheckValid(sValue) method of CInputValidator class
		//case: invalid string as parameter
		//result: false
		TEST_METHOD(TestCheckValidInvalid3)
		{
			CInputValidator validator;
			Assert::AreEqual(false, validator.CheckValid(_T("  ..")));
		}
		//test for: CheckValid(sValue) method of CInputValidator class
		//case:  using empty string as parameter
		//result: false
		TEST_METHOD(TestCheckValidInvalid4)
		{
			CInputValidator validator;
			Assert::AreEqual(false, validator.CheckValid(_T("")));
		}
	};
}