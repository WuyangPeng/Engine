///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 20:48)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_IMPL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/MainFunctionHelper/TestingInformationHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"
#include "Framework/WindowProcess/Detail/WindowMessageUnitTestSuiteStream.h"

#include <string>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE AndroidCallBackUnitTestSuiteImpl
    {
    public:
        using ClassType = AndroidCallBackUnitTestSuiteImpl;

        using Suite = CoreTools::Suite;
        using OStreamShared = CoreTools::OStreamShared;
        using UnitTestComposite = CoreTools::UnitTestComposite;
        using UnitTestSharedPtr = std::shared_ptr<UnitTestComposite>;

    public:
        explicit AndroidCallBackUnitTestSuiteImpl(const std::string& name);

        CLASS_INVARIANT_DECLARE;

        void AddSuite(const Suite& aSuite);
        void RunUnitTest();
        void PrintReport();
        void ResetTestData();
        NODISCARD int GetPassedNumber() const noexcept;

        void AddTest(const std::string& suiteName, Suite& aSuite, const std::string& testName, const UnitTestSharedPtr& unitTest);

        NODISCARD bool IsPrintRun() const noexcept;

        NODISCARD OStreamShared GetStreamShared() const noexcept;

    private:
        using SuiteSharedPtr = std::shared_ptr<Suite>;
        using TestingInformationHelper = CoreTools::TestingInformationHelper;
        using StreamSharedPtr = std::shared_ptr<WindowMessageUnitTestSuiteStream>;

    private:
        void DoAddTest(const std::string& suiteName, Suite& aSuite, const std::string& testName, const UnitTestSharedPtr& unitTest);

    private:
        StreamSharedPtr stream;
        TestingInformationHelper testingInformationHelper;
        SuiteSharedPtr suite;
    };
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_IMPL_H
