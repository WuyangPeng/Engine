///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:02)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_PREFIX_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_PREFIX_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class LogMessagePrefixTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(LogMessagePrefixTesting);

    private:
        void MainTest();
        void TimestampTest();
        void LogLevelTest();
        void LogFilterTest();
        void NoPrefixTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_PREFIX_TESTING_H
