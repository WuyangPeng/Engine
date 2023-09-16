///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:29)

#ifndef SYSTEM_CONSOLE_SUITE_READ_ATTRIBUTE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_READ_ATTRIBUTE_TESTING_H

#include "ConsoleAttributeTesting.h"

namespace System
{
    class ReadAttributeTesting final : public ConsoleAttributeTesting
    {
    public:
        using ClassType = ReadAttributeTesting;
        using ParentType = ConsoleAttributeTesting;

    public:
        explicit ReadAttributeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ReadAttributeTest();

        void DoReadAttributeTest(StandardHandle standardHandle);
        void AttributeResultTest(const AttributeType& attribute);
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_READ_ATTRIBUTE_TESTING_H