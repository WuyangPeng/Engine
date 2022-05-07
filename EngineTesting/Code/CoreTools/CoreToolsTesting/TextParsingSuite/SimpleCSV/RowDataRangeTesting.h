///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/10/10 20:16)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_RANGE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_RANGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RowDataRangeTesting final : public UnitTest
    {
    public:
        using ClassType = RowDataRangeTesting;
        using ParentType = UnitTest;

    public:
        explicit RowDataRangeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void RowDataRangeTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_RANGE_TESTING_H