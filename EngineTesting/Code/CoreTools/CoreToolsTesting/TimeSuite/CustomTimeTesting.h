/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 10:10)

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
        void DoRunUnitTest() override;
        void MainTest();

        void TimeTest();
        void DescribeTest();
    };
}

#endif  // CONCURRENT_TOOLS_TIME_SUITE_CUSTOM_TIME_TESTING_H