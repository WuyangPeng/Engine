// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:52)

#include "Framework/FrameworkExport.h"

#include "WindowMessageUnitTestSuiteImpl.h"
#include "System/Window/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

using std::string;
using std::make_unique;
using namespace std::literals;

Framework::WindowMessageUnitTestSuiteImpl
	::WindowMessageUnitTestSuiteImpl(const string& name, const  OStreamShared& streamShared)
    : m_Alloc{ CoreTools::DisableNotThrow::Disable }, m_TestingInformationHelper{ CoreTools::DisableNotThrow::Disable },
	 m_Suite{ make_unique<Suite>(name, streamShared, m_TestingInformationHelper.IsPrintRun()) },
	 m_Process{ { System::WindowsKeyCodes::F1,&ClassType::ResetTestDataOnMessage },
			    { System::WindowsKeyCodes::F5,&ClassType::RunUnitTestOnMessage } }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowMessageUnitTestSuiteImpl
	::IsValid() const noexcept
{
	if (m_Suite != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

bool Framework::WindowMessageUnitTestSuiteImpl
	::IsPrintRun() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_TestingInformationHelper.IsPrintRun();
}

int Framework::WindowMessageUnitTestSuiteImpl
	::GetPassedNumber() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Suite->GetPassedNumber();
}

void Framework::WindowMessageUnitTestSuiteImpl
	::RunUnitTest()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Suite->RunUnitTest();
}

void Framework::WindowMessageUnitTestSuiteImpl
	::PrintReport()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Suite->PrintReport();
}

void Framework::WindowMessageUnitTestSuiteImpl
	::ResetTestData()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Suite->ResetTestData();
}

void Framework::WindowMessageUnitTestSuiteImpl
	::RunUnitTestOnMessage()
{
	RunUnitTest();
	PrintReport();
}

void Framework::WindowMessageUnitTestSuiteImpl
	::AddSuite(const Suite& suite)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Suite->AddSuite(suite);
}

void Framework::WindowMessageUnitTestSuiteImpl
	::KeyDownMessage(System::WindowsKeyCodes windowsKeyCodes)
{
	FRAMEWORK_CLASS_IS_VALID_1; 

	const auto iter = m_Process.find(windowsKeyCodes);
	if (iter != m_Process.cend())
	{
		(this->*(iter->second))();
	} 
}

void Framework::WindowMessageUnitTestSuiteImpl
	::AddTest(const string& suiteName, Suite& suite, const string& testName, const UnitTestSharedPtr& unitTest)
{
	const auto testLoopCount = m_TestingInformationHelper.GetLoopCount(suiteName, testName);

	if (0 < testLoopCount)
	{
		unitTest->SetTestLoopCount(testLoopCount);
		unitTest->SetRandomSeed(m_TestingInformationHelper.GetRandomSeed());
		suite.AddTest(unitTest);
	}
	else if (testLoopCount < 0)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			<< SYSTEM_TEXT("≤‚ ‘"s)
			<< testName
			<< SYSTEM_TEXT("Œ¥≈‰÷√£°‘⁄≤‚ ‘Ã◊º˛£∫"s)
			<< suite.GetName()
			<< SYSTEM_TEXT("°£"s)
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

// private
void Framework::WindowMessageUnitTestSuiteImpl
	::ResetTestDataOnMessage()
{
	ResetTestData();
	m_Suite->GetStream() << "≤‚ ‘ ˝æ›“—«Â¡„°£\n";
}

