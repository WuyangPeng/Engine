//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:23)

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
        using SubclassWeakPointerType = std::weak_ptr<T>;
        using EventSlotPriorityType = PriorityType;
        using SubclassSmartPointerType = std::shared_ptr<T>;
        using SubclassType = T;
        static_assert(std::is_base_of_v<EventInterface, SubclassType>, "SubclassType is base of EventInterface");

        using ClassType = EventSlot<SubclassType, EventSlotPriorityType>;
        using CallbackMemberFunction = typename SubclassType::CallbackMemberFunction;
        using ConstSubclassSmartPointerType = std::shared_ptr<const T>;

    public:
        EventSlot(const SubclassSmartPointerType& smartPointer, PriorityType priority, CallbackMemberFunction callbackMemberFunction);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool operator()(const CallbackParameters& callbackParameters);
        [[nodiscard]] PriorityType GetPriority() const;

        [[nodiscard]] const ConstSubclassSmartPointerType GetConstSmartPointer() const;

    private:
        SubclassWeakPointerType m_SubclassWeakPointer;
        PriorityType m_Priority;
        CallbackMemberFunction m_CallbackMemberFunction;
    };

    template <typename T, typename PriorityType>
    [[nodiscard]] bool operator<(const EventSlot<T, PriorityType>& lhs, const EventSlot<T, PriorityType>& rhs);

    template <typename T, typename PriorityType>
    std::ostream& operator<<(std::ostream& os, const EventSlot<T, PriorityType>& lhs);
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_H
