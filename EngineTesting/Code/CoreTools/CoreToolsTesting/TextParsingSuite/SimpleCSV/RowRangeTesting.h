///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/10/11 10:49)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ROW_RANGE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ROW_RANGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RowRangeTesting final : public UnitTest
    {
    public:
        using ClassType = RowRangeTesting;
        using ParentType = UnitTest;

    public:
        explicit RowRangeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void RowRangeTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ROW_RANGE_TESTING_H