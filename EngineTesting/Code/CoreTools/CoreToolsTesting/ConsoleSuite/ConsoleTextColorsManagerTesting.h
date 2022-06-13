///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 14:33)

#ifndef CORE_TOOLS_CONSOLE_SUITE_CONSOLE_TEXT_COLORS_MANAGER_TESTING_H
#define CORE_TOOLS_CONSOLE_SUITE_CONSOLE_TEXT_COLORS_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ConsoleTextColorsManagerTesting final : public UnitTest
    {
    public:
        using ClassType = ConsoleTextColorsManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleTextColorsManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ConsoleTextColorsManageTest();
    };
}

#endif  // CORE_TOOLS_CONSOLE_SUITE_CONSOLE_TEXT_COLORS_MANAGER_TESTING_H
