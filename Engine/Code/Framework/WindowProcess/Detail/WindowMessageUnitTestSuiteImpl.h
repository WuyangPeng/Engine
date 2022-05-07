///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:20)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_IMPL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
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
        using UnitTestSharedPtr = std::shared_ptr<CoreTools::UnitTestComposite>;

    public:
        WindowMessageUnitTestSuiteImpl(const std::string& name, const OStreamShared& streamShared);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsPrintRun() const noexcept;
        NODISCARD int GetPassedNumber() const noexcept;

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
        ConsoleAlloc alloc;
        TestingInformationHelper testingInformationHelper;
        SuiteUniquePtr windowSuite;
        Process process;
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_IMPL_H
