///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/11 20:23)

#ifndef FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_TESTING_H
#define FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class WindowMessageTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowMessageTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowMessageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest() noexcept;
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_TESTING_H
