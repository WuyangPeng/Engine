///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/03 23:26)

#ifndef SYSTEM_CONSOLE_SUITE_WRITE_ATTRIBUTE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_WRITE_ATTRIBUTE_TESTING_H

#include "ConsoleAttributeTesting.h"

namespace System
{
    class WriteAttributeTesting final : public ConsoleAttributeTesting
    {
    public:
        using ClassType = WriteAttributeTesting;
        using ParentType = ConsoleAttributeTesting;

    public:
        explicit WriteAttributeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void WriteAttributeTest();
        void DoWriteAttributeTest(WindowsHandle consoleHandle);
        void ReadAttributeTest(const AttributeType& readAttribute, const AttributeType& writeAttribute);

        NODISCARD AttributeType GetWriteAttribute();

        void PrintTipsMessage();
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_WRITE_ATTRIBUTE_TESTING_H