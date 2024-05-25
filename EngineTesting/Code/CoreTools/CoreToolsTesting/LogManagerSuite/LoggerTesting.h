/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 22:40)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LoggerTesting final : public UnitTest
    {
    public:
        using ClassType = LoggerTesting;
        using ParentType = UnitTest;

    public:
        explicit LoggerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void BaseTest();
        void DoBaseTest(const Logger& logger, LogLevel logLevel);
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_TESTING_H
