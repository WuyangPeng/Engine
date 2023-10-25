///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 17:32)

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
        void DoRunUnitTest() override;
        void MainTest();

        void ConsoleTextColorsManageTest();
    };
}

#endif  // CORE_TOOLS_CONSOLE_SUITE_CONSOLE_TEXT_COLORS_MANAGER_TESTING_H
