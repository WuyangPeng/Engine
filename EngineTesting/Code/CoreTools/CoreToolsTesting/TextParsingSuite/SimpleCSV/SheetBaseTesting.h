///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/10/12 17:05)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_SHEET_BASE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_SHEET_BASE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SheetBaseTesting final : public UnitTest
    {
    public:
        using ClassType = SheetBaseTesting;
        using ParentType = UnitTest;

    public:
        explicit SheetBaseTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SheetBaseTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_SHEET_BASE_TESTING_H