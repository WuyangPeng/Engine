///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 15:29)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_SLOT_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_SLOT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class EventSlotTesting final : public UnitTest
    {
    public:
        using ClassType = EventSlotTesting;
        using ParentType = UnitTest;

    public:
        explicit EventSlotTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void SlotTest();
        void OperatorTest();
        void UInt64PriorityTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_SLOT_TESTING_H