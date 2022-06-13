///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:17)

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