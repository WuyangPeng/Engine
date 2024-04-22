/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 17:13)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_SET_SHEET_NAME_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_SET_SHEET_NAME_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CommandSetSheetNameTesting final : public UnitTest
    {
    public:
        using ClassType = CommandSetSheetNameTesting;
        using ParentType = UnitTest;

    public:
        explicit CommandSetSheetNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CommandSetSheetNameTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_SET_SHEET_NAME_TESTING_H
