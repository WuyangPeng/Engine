/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:23)

#ifndef SYSTEM_CONSOLE_SUITE_FILL_ATTRIBUTE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_FILL_ATTRIBUTE_TESTING_H

#include "ConsoleAttributeTesting.h"

namespace System
{
    class FillAttributeTesting final : public ConsoleAttributeTesting
    {
    public:
        using ClassType = FillAttributeTesting;
        using ParentType = ConsoleAttributeTesting;

    public:
        explicit FillAttributeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void FillAttributeTest();
        void DoFillAttributeTest(size_t index);
        void FillAttributeResultTest(const AttributeType& readAttributes, WindowsWord writeAttribute);
        void DoFillAttributeResultTest(WindowsWord writeAttribute, WindowsWord readAttribute);

        void PrintTipsMessage() override;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_FILL_ATTRIBUTE_TESTING_H