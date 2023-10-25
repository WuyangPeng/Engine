///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 11:18)

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
        void MainTest();
        void LoadConfigurationTest();
        void OutTest() noexcept;
        void MessageTest();
        void GetMinLogLevelTypeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // LOG_MANAGER_LOG_TESTING_H
