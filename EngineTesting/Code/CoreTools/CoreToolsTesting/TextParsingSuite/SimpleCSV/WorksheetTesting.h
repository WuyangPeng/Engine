///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/08 16:37)

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
        void DoRunUnitTest() override;
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