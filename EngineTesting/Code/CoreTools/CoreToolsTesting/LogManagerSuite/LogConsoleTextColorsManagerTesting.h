///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 10:59)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOG_CONSOLE_TEXT_COLORS_MANAGER_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOG_CONSOLE_TEXT_COLORS_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class LogConsoleTextColorsManagerTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(LogConsoleTextColorsManagerTesting);

    private:
        void MainTest();
        void ErrorConsoleTextColorsManagerTest();
        void OutputConsoleTextColorsManagerTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_LOG_CONSOLE_TEXT_COLORS_MANAGER_TESTING_H
