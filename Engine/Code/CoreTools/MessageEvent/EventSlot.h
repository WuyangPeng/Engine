/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:22)

#ifndef CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_H
#define CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_H

#include "CoreTools/CoreToolsDll.h"

#include "EventInterface.h"
#include "MessageEventFwd.h"

#include <iosfwd>

namespace CoreTools
{
    template <typename T, typename PriorityType = int>
    class EventSlot final
    {
    public:
        using SubclassWeakPtr = std::weak_ptr<T>;
        using EventSlotPriorityType = PriorityType;
        using SubclassSharedPtr = std::shared_ptr<T>;
        using SubclassType = T;

        static_assert(std::is_base_of_v<EventInterface, SubclassType>, "SubclassType is base of EventInterface");

        using ClassType = EventSlot<SubclassType, EventSlotPriorityType>;

        using CallbackMemberFunction = typename SubclassType::CallbackMemberFunction;
        using ConstSubclassSharedPtr = std::shared_ptr<const T>;

    public:
        EventSlot(const SubclassSharedPtr& subclass, PriorityType priority, CallbackMemberFunction callbackMemberFunction) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool operator()(const CallbackParameters& callbackParameters);
        NODISCARD PriorityType GetPriority() const noexcept;

        NODISCARD ConstSubclassSharedPtr GetConstSharedPtr() const;

    private:
        SubclassWeakPtr subclass;
        PriorityType priority;
        CallbackMemberFunction callbackMemberFunction;
    };

    template <typename T, typename PriorityType>
    NODISCARD bool operator<(const EventSlot<T, PriorityType>& lhs, const EventSlot<T, PriorityType>& rhs) noexcept;

    template <typename T, typename PriorityType>
    std::ostream& operator<<(std::ostream& os, const EventSlot<T, PriorityType>& lhs);
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_H
