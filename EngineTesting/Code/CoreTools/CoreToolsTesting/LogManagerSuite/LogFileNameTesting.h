/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 22:39)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOG_FILE_NAME_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOG_FILE_NAME_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LogFileNameTesting final : public UnitTest
    {
    public:
        using ClassType = LogFileNameTesting;
        using ParentType = UnitTest;

    public:
        explicit LogFileNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LogFileNameTest();
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_LOG_FILE_NAME_TESTING_H
