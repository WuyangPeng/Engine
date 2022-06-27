///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 17:22)

#ifndef WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_SUITE_WINDOW_MESSAGE_H
#define WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_SUITE_WINDOW_MESSAGE_H

#include "Framework/WindowProcess/WindowMessageUnitTestSuiteDetail.h"

#include <memory>

namespace Framework
{
    class SuiteWindowMessage final : public Framework::WindowMessageUnitTestSuite, public std::enable_shared_from_this<SuiteWindowMessage>
    {
    public:
        using ClassType = SuiteWindowMessage;
        using ParentType = WindowMessageUnitTestSuite;

    public:
        explicit SuiteWindowMessage(int64_t delta);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite() final;
    };

    using WindowProcessTesting = Framework::WindowProcessHandle<SuiteWindowMessage>;
}

#endif  // WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_SUITE_WINDOW_MESSAGE_H
