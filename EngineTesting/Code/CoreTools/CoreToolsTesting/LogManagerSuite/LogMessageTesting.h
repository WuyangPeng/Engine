/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 22:40)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LogMessageTesting final : public UnitTest
    {
    public:
        using ClassType = LogMessageTesting;
        using ParentType = UnitTest;

    public:
        explicit LogMessageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LogLevelTest();
        void LogFilterTest();
        void MessageTest();
        void GetFileNameTest();
        void LogAppenderIOManageAlwaysConsoleTest();
        void LogAppenderIOManageTriggerAssertTest();
        void ErrorExceptionTest();
        void StdExceptionTest();
        void StringTest();
        void IntegerTest();
        void IsDisabledTest();

        NODISCARD static LogMessage GetStringLogMessage();
        NODISCARD static LogMessage GetIntegerLogMessage();
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_TESTING_H
