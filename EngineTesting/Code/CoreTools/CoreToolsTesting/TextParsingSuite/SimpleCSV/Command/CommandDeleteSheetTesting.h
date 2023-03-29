///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/07 10:54)

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
        void DoRunUnitTest() override;
        void MainTest();

        void CommandDeleteSheetTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_COMMAND_DELETE_SHEET_TESTING_H
