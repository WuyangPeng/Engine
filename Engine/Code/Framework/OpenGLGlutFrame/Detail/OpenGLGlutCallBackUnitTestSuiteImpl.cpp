// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 15:58)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutCallBackUnitTestSuiteImpl.h"
#include "System/Window/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTestComposite.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::string;
using std::make_shared;

Framework::OpenGLGlutCallBackUnitTestSuiteImpl
	::OpenGLGlutCallBackUnitTestSuiteImpl(const string& name, const OStreamShared& streamShared)
	: m_TestingInformationHelper{ }, m_Suite{ make_shared<Suite>(name,streamShared,m_TestingInformationHelper.IsPrintRun()) },
	  m_Process{ { System::WindowsKeyCodes::F1,&ClassType::ResetTestDataOnMessage },
				 { System::WindowsKeyCodes::F5,&ClassType::RunUnitTestOnMessage } }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::OpenGLGlutCallBackUnitTestSuiteImpl
	::IsValid() const noexcept
{
	if (m_Suite != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl
	::AddSuite(const Suite& suite)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Suite->AddSuite(suite);
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl
	::RunUnitTest()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Suite->RunUnitTest();
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl
	::PrintReport()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Suite->PrintReport();
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl
	::ResetTestData()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Suite->ResetTestData();
}

int Framework::OpenGLGlutCallBackUnitTestSuiteImpl
	::GetPassedNumber() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Suite->GetPassedNumber();
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl
	::AddTest(const string& suiteName, Suite& suite, const string& testName, const UnitTestSharedPtr& unitTest)
{
	try
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
				<< SYSTEM_TEXT("≤‚ ‘")
				<< testName
				<< SYSTEM_TEXT("Œ¥≈‰÷√£°‘⁄≤‚ ‘Ã◊º˛£∫")
				<< suite.GetName()
				<< SYSTEM_TEXT("°£")
				<< LOG_SINGLETON_TRIGGER_ASSERT;
		}
	}
	catch (const CoreTools::Error& error)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			<< error
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

void Framework::OpenGLGlutCallBackUnitTestSuiteImpl
	::KeyDownMessage(WindowsKeyCodes windowsKeyCodes)
{
	const auto iter = m_Process.find(windowsKeyCodes);
	if (iter != m_Process.cend())
	{
		(this->*(iter->second))();
	}
}

bool Framework::OpenGLGlutCallBackUnitTestSuiteImpl
	::IsPrintRun() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_TestingInformationHelper.IsPrintRun();
}

// private
void Framework::OpenGLGlutCallBackUnitTestSuiteImpl
	::RunUnitTestOnMessage()
{
	RunUnitTest();
	PrintReport();
}

// private
void Framework::OpenGLGlutCallBackUnitTestSuiteImpl
	::ResetTestDataOnMessage()
{
	ResetTestData();
	m_Suite->GetStream() << "≤‚ ‘ ˝æ›“—«Â¡„°£\n";
} 