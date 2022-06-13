///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 16:10)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_ADD_CHARTSHEET_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_ADD_CHARTSHEET_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CommandAddChartsheetTesting final : public UnitTest
    {
    public:
        using ClassType = CommandAddChartsheetTesting;
        using ParentType = UnitTest;

    public:
        explicit CommandAddChartsheetTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CommandAddChartsheetTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_ADD_CHARTSHEET_TESTING_H
