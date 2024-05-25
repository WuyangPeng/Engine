/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:01)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_MESSAGE_MANAGER_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_MESSAGE_MANAGER_TESTING_H

#include "Flags/EventPriorityFlags.h"
#include "Detail/EventSubclass.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MessageManagerTesting final : public UnitTest
    {
    public:
        using ClassType = MessageManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto value = 5;

        using EventSubclassSharedPtr = std::shared_ptr<EventSubclass>;
        using EventSlotType = EventSlot<EventSubclass, EventPriority>;
        using TestingType = MessageManager<EventSlotType, int>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SuccessTest();
        void UnregisteredExceptionTest();

        NODISCARD EventSubclassSharedPtr GetEventSubclass();
        NODISCARD int64_t RegisteredTest(const EventSubclassSharedPtr& eventSubclass, TestingType& messageManager);
        void CallEventTest(const EventSubclass& eventSubclass, TestingType& messageManager, const CallbackParameters& callbackParameters);
        void DelayCallEventTest(const EventSubclass& eventSubclass, TestingType& messageManager, const CallbackParameters& callbackParameters);
        void DispatchDelayEventTest(const EventSubclass& eventSubclass, TestingType& messageManager, const CallbackParameters& callbackParameters);
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_MESSAGE_MANAGER_TESTING_H