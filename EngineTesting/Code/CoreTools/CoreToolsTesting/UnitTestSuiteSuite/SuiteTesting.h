///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 14:01)

#ifndef CONCURRENT_TOOLS_UNIT_TEST_SUITE_SUITE_TESTING_H
#define CONCURRENT_TOOLS_UNIT_TEST_SUITE_SUITE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class SuiteTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SuiteTesting);

    private:
        void MainTest();
        void NameTest();
        void StreamTest();
        void AddTestTest();
        void AddSuiteTest();
        void TestDataTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CONCURRENT_TOOLS_UNIT_TEST_SUITE_SUITE_TESTING_H