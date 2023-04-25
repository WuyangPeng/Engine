///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/12 15:54)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOG_LEVEL_MANAGER_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOG_LEVEL_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LogLevelManagerTesting final : public UnitTest
    {
    public:
        using ClassType = LogLevelManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit LogLevelManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void ValidTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_LOG_LEVEL_MANAGER_TESTING_H
