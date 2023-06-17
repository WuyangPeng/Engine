///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 19:48)

#ifndef FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H
#define FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class WindowMessageUnitTestSuiteTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowMessageUnitTestSuiteTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowMessageUnitTestSuiteTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest() noexcept;
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H
