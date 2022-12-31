///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/05 0:49)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_MODE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_MODE_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ConsoleModeTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleModeTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleModeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD WindowsDWord GetCurrentMode(WindowsHandle consoleHandle);
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_MODE_TESTING_H