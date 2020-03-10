// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 10:05)

#include "Framework/FrameworkExport.h"

#include "WindowMessageUnitTestSuiteImpl.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::string;
using std::ostream;

Framework::WindowMessageUnitTestSuiteImpl
	::WindowMessageUnitTestSuiteImpl(const string& name, ostream* osPtr)
	:m_SuitePtr(new Suite(name,osPtr)),m_Alloc(),m_TestingInformationHelper()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowMessageUnitTestSuiteImpl
	::IsValid() const noexcept
{
	if(m_SuitePtr != nullptr)
	    return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Framework::WindowMessageUnitTestSuiteImpl
	::AddSuite( const Suite& suite )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SuitePtr->AddSuite(suite);
}

void Framework::WindowMessageUnitTestSuiteImpl
	::RunUnitTest()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SuitePtr->RunUnitTest();
}

void Framework::WindowMessageUnitTestSuiteImpl
	::PrintReport()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SuitePtr->PrintReport();
}

void Framework::WindowMessageUnitTestSuiteImpl
	::ResetTestData()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_SuitePtr->ResetTestData();
}

int Framework::WindowMessageUnitTestSuiteImpl
	::GetPassedNumber() const
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return m_SuitePtr->GetPassedNumber();
}

void Framework::WindowMessageUnitTestSuiteImpl
	::AddTest(const std::string& suiteName, Suite& suite,const std::string& testName, const UnitTestPtr& unitTest)
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
			<< "����δ����"
			<< CoreTools::LogAppenderIOManageSign::TriggerAssert
			<< CoreTools::LogAppenderIOManageSign::Refresh;
	}
}

