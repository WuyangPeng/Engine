// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:36)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_IMPL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Window/Using/WindowUsing.h"
#include "System/Window/Fwd/WindowFlagsFwd.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"
#include "CoreTools/MainFunctionHelper/TestingInformationHelper.h"

#include <map>
#include <string> 

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowMessageUnitTestSuiteImpl
	{
	public:
		using ClassType = WindowMessageUnitTestSuiteImpl;
		using WindowsKeyCodes = System::WindowsKeyCodes;
		using Suite = CoreTools::Suite;
		using OStreamShared = CoreTools::OStreamShared;
		using UnitTestSharedPtr = std::shared_ptr<CoreTools::UnitTestComposite>;

	public:
		WindowMessageUnitTestSuiteImpl(const std::string& name, const OStreamShared& streamShared);

		CLASS_INVARIANT_DECLARE;

		bool IsPrintRun() const noexcept;
		int GetPassedNumber() const noexcept;

		void RunUnitTest();
		void PrintReport();
		void ResetTestData();

		void RunUnitTestOnMessage();

		void AddSuite(const Suite& suite);
		void KeyDownMessage(WindowsKeyCodes windowsKeyCodes);

		void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);

	private:
		using SuiteUniquePtr = std::unique_ptr<Suite>;
		using ConsoleAlloc = CoreTools::ConsoleAlloc;
		using TestingInformationHelper = CoreTools::TestingInformationHelper;
		using HandlerFunction = void (ClassType::*)();
		using Process = std::map<System::WindowsKeyCodes, HandlerFunction>;

	private:
		void ResetTestDataOnMessage();

	private:
		ConsoleAlloc m_Alloc;
		TestingInformationHelper m_TestingInformationHelper;
		SuiteUniquePtr m_Suite;
		Process m_Process;
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_IMPL_H
