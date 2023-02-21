///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 14:18)

#ifndef CONCURRENT_TOOLS_TIME_SUITE_CUSTOM_TIME_TESTING_H
#define CONCURRENT_TOOLS_TIME_SUITE_CUSTOM_TIME_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CustomTimeTesting : public UnitTest
    {
    public:
        using ClassType = CustomTimeTesting;
        using ParentType = UnitTest;

    public:
        explicit CustomTimeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void TimeTest();
        void DescribeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CONCURRENT_TOOLS_TIME_SUITE_CUSTOM_TIME_TESTING_H