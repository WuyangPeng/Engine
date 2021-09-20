//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 15:39)

#ifndef CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_DETAIL_H

#include "CallbackParameters.h"
#include "EventSlot.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <iostream>

template <typename T, typename PriorityType>
CoreTools::EventSlot<T, PriorityType>::EventSlot(const SubclassSmartPointerType& smartPointer, PriorityType priority, CallbackMemberFunction callbackMemberFunction) noexcept
    : m_SubclassWeakPointer{ smartPointer }, m_Priority{ priority }, m_CallbackMemberFunction{ callbackMemberFunction }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T, typename PriorityType>
bool CoreTools::EventSlot<T, PriorityType>::IsValid() const noexcept
{
    if (m_CallbackMemberFunction != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T, typename PriorityType>
bool CoreTools::EventSlot<T, PriorityType>::operator()(const CallbackParameters& callbackParameters)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto subclassSmartPointer = m_SubclassWeakPointer.lock();

    if (subclassSmartPointer)
    {
        return ((*subclassSmartPointer).*m_CallbackMemberFunction)(callbackParameters);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("事件未被正确移除。"s));
    }
}

template <typename T, typename PriorityType>
PriorityType CoreTools::EventSlot<T, PriorityType>::GetPriority() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Priority;
}

template <typename T, typename PriorityType>
const typename CoreTools::EventSlot<T, PriorityType>::ConstSubclassSmartPointerType CoreTools::EventSlot<T, PriorityType>::GetConstSmartPointer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_SubclassWeakPointer.lock();
}

template <typename T, typename PriorityType>
bool CoreTools::operator<(const EventSlot<T, PriorityType>& lhs, const EventSlot<T, PriorityType>& rhs) noexcept
{
    return lhs.GetPriority() < rhs.GetPriority();
}

template <typename T, typename PriorityType>
std::ostream& CoreTools::operator<<(std::ostream& os, const EventSlot<T, PriorityType>& lhs)
{
    os << "Slot Priority = " << lhs.GetPriority();

    return os;
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_DETAIL_H