///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 14:18)

#ifndef CONCURRENT_TOOLS_TIME_SUITE_CUSTOM_TIME_TESTING_H
#define CONCURRENT_TOOLS_TIME_SUITE_CUSTOM_TIME_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class CustomTimeTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CustomTimeTesting);

    private:
        void MainTest();
        void TimeTest();
        void DescribeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CONCURRENT_TOOLS_TIME_SUITE_CUSTOM_TIME_TESTING_H