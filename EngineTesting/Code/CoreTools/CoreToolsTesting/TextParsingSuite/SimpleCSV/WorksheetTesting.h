///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/10/12 22:24)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_WORKSHEET_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_WORKSHEET_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class WorksheetTesting final : public UnitTest
    {
    public:
        using ClassType = WorksheetTesting;
        using ParentType = UnitTest;

    public:
        explicit WorksheetTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WorksheetCellTest();
        void WorksheetRangeTest();
        void WorksheetRowRangeTest();
        void WorksheetRowTest();
        void WorksheetColumnTest();
        void LastCellTest();
        void SelectedTest();
        void ColorTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_WORKSHEET_TESTING_H