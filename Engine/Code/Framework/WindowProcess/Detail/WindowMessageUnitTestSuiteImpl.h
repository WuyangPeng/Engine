///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 14:59)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_IMPL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "WindowMessageUnitTestSuiteStream.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/Console/ConsoleAlloc.h"
#include "CoreTools/MainFunctionHelper/TestingInformationHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

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
        using UnitTestComposite = CoreTools::UnitTestComposite;
        using UnitTestSharedPtr = std::shared_ptr<UnitTestComposite>;

    public:
        explicit WindowMessageUnitTestSuiteImpl(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsPrintRun() const noexcept;
        NODISCARD int GetPassedNumber() const noexcept;
        NODISCARD OStreamShared GetStreamShared() noexcept;

        void RunUnitTest();
        void PrintReport();
        void ResetTestData();

        void RunUnitTestOnMessage();
        void KeyDownMessage(WindowsKeyCodes windowsKeyCodes);

        void AddSuite(const Suite& suite);
        void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);

    private:
        using SuiteUniquePtr = std::unique_ptr<Suite>;
        using ConsoleAlloc = CoreTools::ConsoleAlloc;
        using TestingInformationHelper = CoreTools::TestingInformationHelper;
        using HandlerFunction = void (ClassType::*)();
        using Process = std::map<WindowsKeyCodes, HandlerFunction>;
        using StreamUniquePtr = std::unique_ptr<WindowMessageUnitTestSuiteStream>;

    private:
        void ResetTestDataOnMessage();

    private:
        StreamUniquePtr stream;
        ConsoleAlloc alloc;
        TestingInformationHelper testingInformationHelper;
        SuiteUniquePtr windowSuite;
        Process process;
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_IMPL_H
