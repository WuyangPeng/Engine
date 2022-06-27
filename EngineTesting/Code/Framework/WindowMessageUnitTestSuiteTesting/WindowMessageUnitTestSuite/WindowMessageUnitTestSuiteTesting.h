///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 17:23)

#ifndef WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H
#define WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Framework/WindowMessageUnitTestSuiteTesting/SuiteWindowMessage.h"

namespace Framework
{
    class WindowMessageUnitTestSuiteTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowMessageUnitTestSuiteTesting;
        using ParentType = UnitTest;
        using WindowMessageSharedPtr = std::shared_ptr<SuiteWindowMessage>;

    public:
        explicit WindowMessageUnitTestSuiteTesting(const OStreamShared& stream, const WindowMessageSharedPtr& message);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void KeyDownMessageTest();
        void CreateMessageTest();
        void DisplayTest();

    private:
        std::weak_ptr<SuiteWindowMessage> mMessage;
    };
}

#endif  // WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H
