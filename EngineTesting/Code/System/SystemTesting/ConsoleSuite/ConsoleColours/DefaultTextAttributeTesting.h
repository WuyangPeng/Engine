/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:23)

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
        void DoRunUnitTest() override;
        void MainTest();

        void DefaultTextAttributeTest();
        void DoDefaultTextAttributeTest(StandardHandle standardHandle);
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_DEFAULT_TEXT_ATTRIBUTE_TESTING_H