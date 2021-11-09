///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/09/29 17:59)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_DELETE_SHEET_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_DELETE_SHEET_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CommandDeleteSheetTesting final : public UnitTest
    {
    public:
        using ClassType = CommandDeleteSheetTesting;
        using ParentType = UnitTest;

    public:
        explicit CommandDeleteSheetTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CommandDeleteSheetTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_DELETE_SHEET_TESTING_H
