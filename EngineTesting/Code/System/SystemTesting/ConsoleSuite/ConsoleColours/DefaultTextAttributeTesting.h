///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/03 20:11)

#ifndef SYSTEM_CONSOLE_SUITE_DEFAULT_TEXT_ATTRIBUTE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_DEFAULT_TEXT_ATTRIBUTE_TESTING_H

#include "ConsoleStandardHandlesTesting.h"

namespace System
{
    class DefaultTextAttributeTesting final : public ConsoleStandardHandlesTesting
    {
    public:
        using ClassType = DefaultTextAttributeTesting;
        using ParentType = ConsoleStandardHandlesTesting;

    public:
        explicit DefaultTextAttributeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DefaultTextAttributeTest();
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_DEFAULT_TEXT_ATTRIBUTE_TESTING_H