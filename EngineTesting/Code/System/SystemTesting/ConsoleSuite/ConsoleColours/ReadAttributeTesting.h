///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/03 21:55)

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
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ReadAttributeTest();

        void DoReadAttributeTest(StandardHandle standardHandle);
        void AttributeResultTest(AttributeType attribute);
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_READ_ATTRIBUTE_TESTING_H