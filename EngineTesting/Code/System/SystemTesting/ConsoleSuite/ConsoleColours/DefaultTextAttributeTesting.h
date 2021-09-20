///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/09 14:48)

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
        using StandardHandleFlagsCollection = std::vector<StandardHandle>;

    private:
        StandardHandleFlagsCollection standardHandleFlags;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_COLOURS_TESTING1_H