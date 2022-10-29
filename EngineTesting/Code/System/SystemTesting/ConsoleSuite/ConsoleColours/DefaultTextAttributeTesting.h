///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/15 21:53)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_COLOURS_TESTING1_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_COLOURS_TESTING1_H

#include "ConsoleColoursTesting.h"

#include <vector>

namespace System
{
    class DefaultTextAttributeTesting final : public ConsoleColoursTesting
    {
    public:
        using ClassType = DefaultTextAttributeTesting;
        using ParentType = ConsoleColoursTesting;

    public:
        explicit DefaultTextAttributeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DefaultTextAttributeTest();

    private:
        using StandardHandleFlagsContainer = std::vector<StandardHandle>;

    private:
        StandardHandleFlagsContainer standardHandleFlags;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_COLOURS_TESTING1_H