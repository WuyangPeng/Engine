/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:24)

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