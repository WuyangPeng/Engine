/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 22:41)

#ifndef LOG_MANAGER_LOG_TESTING_H
#define LOG_MANAGER_LOG_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LogTesting final : public UnitTest
    {
    public:
        using ClassType = LogTesting;
        using ParentType = UnitTest;

    public:
        explicit LogTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LoadConfigurationTest();
        void OutTest() noexcept;
        void MessageTest();
        void GetMinLogLevelTypeTest();
    };
}

#endif  // LOG_MANAGER_LOG_TESTING_H
