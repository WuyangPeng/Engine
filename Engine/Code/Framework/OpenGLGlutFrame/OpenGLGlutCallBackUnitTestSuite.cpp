// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 13:20)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutCallBackUnitTestSuite.h"
#include "Detail/OpenGLGlutCallBackUnitTestSuiteImpl.h"
#include "Framework/WindowProcess/WindowMessageUnitTestSuiteOsPtr.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h" 

#include <iostream>

using std::cout;
using std::string;
using std::ostream;

Framework::OpenGLGlutCallBackUnitTestSuite
	::OpenGLGlutCallBackUnitTestSuite()
	:m_OsPtrTypePtr(new OsPtrType),
	 m_Impl(),m_IsInit(false)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// private
void Framework::OpenGLGlutCallBackUnitTestSuite
	::GenerateSuite()
{
	m_Impl.reset(new ImplType(GetSuiteName(),m_OsPtrTypePtr->GetOsPtr()));
}

Framework::OpenGLGlutCallBackUnitTestSuite
	::~OpenGLGlutCallBackUnitTestSuite()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::OpenGLGlutCallBackUnitTestSuite
    ::IsValid() const noexcept
{
	if(ParentType::IsValid() && 
	   m_OsPtrTypePtr != nullptr)
	    return true;
	else
		return false;
}

#endif // OPEN_CLASS_INVARIANT

bool Framework::OpenGLGlutCallBackUnitTestSuite
    ::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_1;	
	FRAMEWORK_ASSERTION_1(m_Impl != nullptr,"子类未调用GenerateSuite进行初始化");

	if(!m_IsInit)
	{
		m_IsInit = true;
		return AddSuiteOnInitialize();	
	}
	return true;
}

bool Framework::OpenGLGlutCallBackUnitTestSuite
	::SpecialKeysDown(int key,int xCoordinate,int yCoordinate)
{
	FRAMEWORK_CLASS_IS_VALID_1;
	FRAMEWORK_ASSERTION_1(m_Impl != nullptr,"子类未调用GenerateSuite进行初始化");

	switch (static_cast<System::GlutKeyCodes>(key))
	{
	case System::GlutKeyCodes::F1:
		{
			ResetTestData(); 
			break;
		}
		
	case System::GlutKeyCodes::F5:
		{
			RunUnitTest();
			break;
		}

	default:
		break;
	}

	return ParentType::SpecialKeysDown(key, xCoordinate, yCoordinate);  
}

bool Framework::OpenGLGlutCallBackUnitTestSuite
	::IdleFunction()
{
	FRAMEWORK_CLASS_IS_VALID_1;	

	return ParentType::IdleFunction();  
}

void Framework::OpenGLGlutCallBackUnitTestSuite
	::DoAddSuite( const Suite& suite )
{
	FRAMEWORK_CLASS_IS_VALID_1;
	FRAMEWORK_ASSERTION_1(m_Impl != nullptr,"子类未调用GenerateSuite进行初始化");

	return m_Impl->AddSuite(suite);
}

ostream* Framework::OpenGLGlutCallBackUnitTestSuite
	::GetOStream()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return m_OsPtrTypePtr->GetOsPtr();
}

int Framework::OpenGLGlutCallBackUnitTestSuite
	::GetPassedNumber() const
{
	FRAMEWORK_CLASS_IS_VALID_1;
	FRAMEWORK_ASSERTION_1(m_Impl != nullptr,"子类未调用GenerateSuite进行初始化");

	return m_Impl->GetPassedNumber();
}

bool  Framework::OpenGLGlutCallBackUnitTestSuite
	::IsPrintRun() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return true;
}

// private
bool Framework::OpenGLGlutCallBackUnitTestSuite
	:: AddSuiteOnInitialize()
{
	bool result = ParentType::Initialize();

	AddSuite();

	m_Impl->RunUnitTest();
	m_Impl->PrintReport();

	return result;
}

// private
void Framework::OpenGLGlutCallBackUnitTestSuite
	::ResetTestData()
{
	m_Impl->ResetTestData();
	*GetOStream() << "测试数据已清零。\n";
}

// private
void Framework::OpenGLGlutCallBackUnitTestSuite
	::RunUnitTest()
{
	m_Impl->RunUnitTest();
	m_Impl->PrintReport();
}

void Framework::OpenGLGlutCallBackUnitTestSuite
	::AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestPtr& unitTest)
{
	m_Impl->AddTest(suiteName,suite,testName, unitTest);
}

 