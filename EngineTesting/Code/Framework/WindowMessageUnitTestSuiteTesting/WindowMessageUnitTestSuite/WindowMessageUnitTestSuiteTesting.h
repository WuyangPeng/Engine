///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 23:35)

#ifndef WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H
#define WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
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
