///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 14:22)

#ifndef CONCURRENT_TOOLS_TIME_SUITE_CUSTOM_TIME_TESTING_H
#define CONCURRENT_TOOLS_TIME_SUITE_CUSTOM_TIME_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CustomTimeTesting final : public UnitTest
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