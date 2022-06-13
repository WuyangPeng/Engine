///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 16:12)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_SET_SHEET_INDEX_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_SET_SHEET_INDEX_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CommandSetSheetIndexTesting final : public UnitTest
    {
    public:
        using ClassType = CommandSetSheetIndexTesting;
        using ParentType = UnitTest;

    public:
        explicit CommandSetSheetIndexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CommandSetSheetIndexTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_SET_SHEET_INDEX_TESTING_H
