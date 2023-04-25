///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/19 10:18)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_SOURCE_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_SOURCE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class BufferSourceTesting final : public UnitTest
    {
    public:
        using ClassType = BufferSourceTesting;
        using ParentType = UnitTest;

    public:
        explicit BufferSourceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ReadBoolTest();
        void ReadStringTest();
        void ReadIntTest();
        void ReadEnumTest();
        void ReadAggregateTest();
        void ReadObjectAssociatedTest();
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_SOURCE_TESTING_H