///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 10:50)

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
        void DoRunUnitTest() override;

        void MainTest();

        void KeyDownMessageTest();
        void CreateMessageTest();
        void DisplayTest();

    private:
        using SuiteWindowMessageWeakPtr = std::weak_ptr<SuiteWindowMessage>;

    private:
        SuiteWindowMessageWeakPtr message;
    };
}

#endif  // WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H
