// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/08/01 13:24)

#include "Framework/FrameworkExport.h"

#include "AndroidCallBackUnitTestSuiteImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestComposite.h"

using std::string;
using std::ostream;

Framework::AndroidCallBackUnitTestSuiteImpl
	::AndroidCallBackUnitTestSuiteImpl(const string& name, ostream* osPtr)
	:m_SuitePtr(new Suite(name, osPtr)), m_TestingInformationHelper{}
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::AndroidCallBackUnitTestSuiteImpl
	::IsValid() const noexcept
{
	if(m_SuitePtr != nullptr)
	    return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Framework::AndroidCallBackUnitTestSuiteImpl
	::AddSuite( const Suite& suite )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SuitePtr->AddSuite(suite);
}

void Framework::AndroidCallBackUnitTestSuiteImpl
	::RunUnitTest()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SuitePtr->RunUnitTest();
}

void Framework::AndroidCallBackUnitTestSuiteImpl
	::PrintReport()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SuitePtr->PrintReport();
}

void Framework::AndroidCallBackUnitTestSuiteImpl
	::ResetTestData()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SuitePtr->ResetTestData();
}

int Framework::AndroidCallBackUnitTestSuiteImpl
	::GetPassedNumber() const
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return m_SuitePtr->GetPassedNumber();
}

void Framework::AndroidCallBackUnitTestSuiteImpl
	::AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestPtr& unitTest)
{
	try
	{
		int testLoopCount = m_TestingInformationHelper.GetLoopCount(suiteName, testName);

		if (0 < testLoopCount)
		{
			unitTest->SetTestLoopCount(testLoopCount);
			unitTest->SetRandomSeed(m_TestingInformationHelper.GetRandomSeed());
			suite.AddTest(unitTest);
		}
		else if (testLoopCount < 0)
		{
			LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
				<< "²âÊÔÎ´ÅäÖÃ"
				<< CoreTools::LogAppenderIOManageSign::TriggerAssert
				<< CoreTools::LogAppenderIOManageSign::Refresh;
		}
	}
	catch (CoreTools::Error& error)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			<< error
			<< CoreTools::LogAppenderIOManageSign::TriggerAssert
			<< CoreTools::LogAppenderIOManageSign::Refresh;
	}
}
