///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/12 15:11)

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
        void MainTest();
        void BaseTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_TESTING_H
