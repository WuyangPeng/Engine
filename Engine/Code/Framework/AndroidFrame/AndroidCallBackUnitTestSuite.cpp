// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 13:25)

#include "Framework/FrameworkExport.h"

#include "AndroidCallBackUnitTestSuite.h"
#include "Detail/AndroidCallBackUnitTestSuiteImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Detail/AndroidCallBackUnitTestSuiteImpl.h"
#include "Framework/WindowProcess/WindowMessageUnitTestSuiteOsPtr.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "System/Android/AndroidInputKeyEvent.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h"

#include <iostream>

using std::cout;
using std::string;
using std::ostream;

Framework::AndroidCallBackUnitTestSuite
	::AndroidCallBackUnitTestSuite()
	:m_OsPtrTypePtr(new OsPtrType),m_Impl(),
	 m_IsInit(false)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// private
void Framework::AndroidCallBackUnitTestSuite
	::GenerateSuite()
{
	m_Impl.reset(new ImplType(GetSuiteName(),m_OsPtrTypePtr->GetOsPtr()));
}

Framework::AndroidCallBackUnitTestSuite
	::~AndroidCallBackUnitTestSuite()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::AndroidCallBackUnitTestSuite
    ::IsValid() const noexcept
{
	if(ParentType::IsValid() && 
	   m_OsPtrTypePtr != nullptr)
	    return true;
	else
		return false;
}

#endif // OPEN_CLASS_INVARIANT

bool Framework::AndroidCallBackUnitTestSuite
	::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_1;
	ASSERTION_1(m_Impl != nullptr,"����δ����GenerateSuite���г�ʼ��");

	if(!m_IsInit)
	{
		m_IsInit = true;
		return AddSuiteOnInitialize();	
	}
	else
		return true;	
}

int Framework::AndroidCallBackUnitTestSuite 
    ::KeyDownMessage(struct AndroidApp* state,
			         AndroidInputEvent* event)
{
    FRAMEWORK_CLASS_IS_VALID_1;
	ASSERTION_1(m_Impl != nullptr,"����δ����GenerateSuite���г�ʼ��");

	System::AndroidKeyCodes keyCode = System::AndroidKeyEventGetKeyCode(event);

	switch(keyCode)
	{
	case System::AndroidKeyCodes::F1:
		{
			ResetTestData();
			break;
		}
		
	case System::AndroidKeyCodes::F5:
		{
			RunUnitTest();
			break;
		}

	default:
		break;
	}

	return ParentType::KeyDownMessage(state, event); 	 	
}

void Framework::AndroidCallBackUnitTestSuite
	::Display(struct AndroidApp* state,int64_t timeDelta)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	ASSERTION_1(m_Impl != nullptr,"����δ����GenerateSuite���г�ʼ��");	

	return ParentType::Display(state, timeDelta);  
}

void Framework::AndroidCallBackUnitTestSuite
	::DoAddSuite( const Suite& suite )
{
	FRAMEWORK_CLASS_IS_VALID_1;
	ASSERTION_1(m_Impl != nullptr,"����δ����GenerateSuite���г�ʼ��");

	return m_Impl->AddSuite(suite);
}

ostream* Framework::AndroidCallBackUnitTestSuite
	::GetOStream() const
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return  m_OsPtrTypePtr->GetOsPtr();
}

int Framework::AndroidCallBackUnitTestSuite
	::GetPassedNumber() const
{
	FRAMEWORK_CLASS_IS_VALID_1;
	ASSERTION_1(m_Impl != nullptr,"����δ����GenerateSuite���г�ʼ��");

	return m_Impl->GetPassedNumber();
}

// private
bool Framework::AndroidCallBackUnitTestSuite
	:: AddSuiteOnInitialize()
{
	bool result = ParentType::Initialize();

	AddSuite();

	m_Impl->RunUnitTest();
	m_Impl->PrintReport();

	return result;
}

// private
void Framework::AndroidCallBackUnitTestSuite
	::ResetTestData()
{
	m_Impl->ResetTestData();
	*GetOStream() << "�������������㡣\n";
}

// private
void Framework::AndroidCallBackUnitTestSuite
	::RunUnitTest()
{
	m_Impl->RunUnitTest();
	m_Impl->PrintReport();
}

void Framework::AndroidCallBackUnitTestSuite
	::AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestPtr& unitTest)
{
	m_Impl->AddTest(suiteName, suite, testName, unitTest);
}

bool  Framework::AndroidCallBackUnitTestSuite
	::IsPrintRun() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return false;
}