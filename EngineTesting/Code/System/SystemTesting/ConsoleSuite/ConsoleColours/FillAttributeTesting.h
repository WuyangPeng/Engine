///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/03 20:55)

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
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void FillAttributeTest();

        void DoFillAttributeTest(size_t index);
        void FillAttributeResultTest(const AttributeType& readAttributes, WindowsWord writeAttribute);

        void PrintTipsMessage() override;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_FILL_ATTRIBUTE_TESTING_H