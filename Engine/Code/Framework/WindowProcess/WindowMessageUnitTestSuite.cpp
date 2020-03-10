// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 10:14)

#include "Framework/FrameworkExport.h"

#include "WindowMessageUnitTestSuite.h"
#include "Detail/WindowMessageUnitTestSuiteImpl.h"
#include "WindowMessageUnitTestSuiteOsPtr.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Window/Flags/WindowsKeyCodesFlags.h"

#include <iostream>

using std::cout;
using std::string;
using std::ostream;

Framework::WindowMessageUnitTestSuite
	::WindowMessageUnitTestSuite()
	:m_OsPtrTypePtr(new OsPtrType),
	 m_Impl()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// private
void Framework::WindowMessageUnitTestSuite
	::GenerateSuite()
{
	m_Impl.reset(new ImplType(GetSuiteName(),m_OsPtrTypePtr->GetOsPtr()));
}

Framework::WindowMessageUnitTestSuite
	::~WindowMessageUnitTestSuite()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowMessageUnitTestSuite
    ::IsValid() const noexcept
{
	if(ParentType::IsValid() && 
	   m_OsPtrTypePtr != nullptr)
	    return true;
	else
		return false;
}

#endif // OPEN_CLASS_INVARIANT

System::WindowLResult Framework::WindowMessageUnitTestSuite
    ::CreateMessage( HWnd hwnd, WParam wParam, LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_1;	
	ASSERTION_1(m_Impl != nullptr,"子类未调用GenerateSuite进行初始化");

	if(GetHwnd() == nullptr)	
		return AddSuiteOnCreateMessage(hwnd, wParam, lParam);	
	else	
		return ParentType::CreateMessage(hwnd,wParam,lParam);	
}

System::WindowLResult Framework::WindowMessageUnitTestSuite
	::KeyDownMessage( HWnd hwnd,WParam wParam,LParam lParam )
{
	FRAMEWORK_CLASS_IS_VALID_1;
	ASSERTION_1(m_Impl != nullptr,"子类未调用GenerateSuite进行初始化");

	switch (static_cast<System::WindowsKeyCodes>(wParam))
	{
	case System::WindowsKeyCodes::F1:
		{
			ResetTestData();
			break;
		}
		
	case System::WindowsKeyCodes::F5:
		{
			RunUnitTest();
			break;
		}

	default:
		break;
	}

	return ParentType::KeyDownMessage(hwnd,wParam,lParam);  
}

void Framework::WindowMessageUnitTestSuite
	::Display( HWND hwnd,int64_t timeDelta )
{
	FRAMEWORK_CLASS_IS_VALID_1;	

	return ParentType::Display(hwnd,timeDelta);  
}

void Framework::WindowMessageUnitTestSuite
	::DoAddSuite( const Suite& suite )
{
	FRAMEWORK_CLASS_IS_VALID_1;
	ASSERTION_1(m_Impl != nullptr,"子类未调用GenerateSuite进行初始化");

	return m_Impl->AddSuite(suite);
}

ostream* Framework::WindowMessageUnitTestSuite
	::GetOStream()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return m_OsPtrTypePtr->GetOsPtr();
}

int Framework::WindowMessageUnitTestSuite
	::GetPassedNumber() const
{
	FRAMEWORK_CLASS_IS_VALID_1;
	ASSERTION_1(m_Impl != nullptr,"子类未调用GenerateSuite进行初始化");

	return m_Impl->GetPassedNumber();
}

// private
System::WindowLResult Framework::WindowMessageUnitTestSuite
	::AddSuiteOnCreateMessage( HWnd hwnd, WParam wParam, LParam lParam )
{
	LResult result = ParentType::CreateMessage(hwnd,wParam,lParam);

	AddSuite();

	m_Impl->RunUnitTest();
	m_Impl->PrintReport();

	return result;
}

// private
void Framework::WindowMessageUnitTestSuite
	::ResetTestData()
{
	m_Impl->ResetTestData();
	*GetOStream() << "测试数据已清零。\n";
}

// private
void Framework::WindowMessageUnitTestSuite
	::RunUnitTest()
{
	m_Impl->RunUnitTest();
	m_Impl->PrintReport();
}

void Framework::WindowMessageUnitTestSuite
	::AddTest(const std::string& suiteName, Suite& suite, 
	          const std::string& testName, const UnitTestPtr& unitTest)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Impl->AddTest(suiteName, suite, testName, unitTest);
}

bool Framework::WindowMessageUnitTestSuite
	::IsPrintRun() const
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return true;
}

 