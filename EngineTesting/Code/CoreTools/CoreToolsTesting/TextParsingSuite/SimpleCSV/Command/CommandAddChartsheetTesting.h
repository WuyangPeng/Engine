///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/06 18:27)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_ADD_CHART_SHEET_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_ADD_CHART_SHEET_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CommandAddChartSheetTesting final : public UnitTest
    {
    public:
        using ClassType = CommandAddChartSheetTesting;
        using ParentType = UnitTest;

    public:
        explicit CommandAddChartSheetTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CommandAddChartSheetTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_ADD_CHART_SHEET_TESTING_H
