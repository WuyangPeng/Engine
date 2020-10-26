//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 16:02)

#ifndef CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_ENTITY_DETAIL_H
#define CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_ENTITY_DETAIL_H

#include "StateEntity.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Subclass, typename EventType>
CoreTools::StateEntity<Subclass, EventType>::StateEntity(StateSharedPtr currentState)
    : ParentType{}, m_StateMachineBase{ currentState }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Subclass, typename EventType>
CoreTools::StateEntity<Subclass, EventType>::StateEntity(StateSharedPtr currentState, StateSharedPtr globalState)
    : ParentType{}, m_StateMachineBase{ currentState, globalState }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Subclass, typename EventType>
bool CoreTools::StateEntity<Subclass, EventType>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Subclass, typename EventType>
void CoreTools::StateEntity<Subclass, EventType>::DoRegister()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto owner = boost::polymorphic_pointer_downcast<Subclass>(ParentType::shared_from_this());

    m_StateMachineBase.Register(owner);
}

template <typename Subclass, typename EventType>
bool CoreTools::StateEntity<Subclass, EventType>::EventFunction(const Telegram& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_StateMachineBase.HandleMessage(telegram);
}

template <typename Subclass, typename EventType>
void CoreTools::StateEntity<Subclass, EventType>::Update(int64_t timeInterval)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_StateMachineBase.Update(timeInterval);
}

template <typename Subclass, typename EventType>
typename CoreTools::StateEntity<Subclass, EventType>::ConstStateSharedPtr CoreTools::StateEntity<Subclass, EventType>::GetCurrentState() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_StateMachineBase.GetCurrentState();
}

template <typename Subclass, typename EventType>
typename CoreTools::StateEntity<Subclass, EventType>::ConstStateSharedPtr CoreTools::StateEntity<Subclass, EventType>::GetGlobalState() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_StateMachineBase.GetGlobalState();
}

template <typename Subclass, typename EventType>
typename CoreTools::StateEntity<Subclass, EventType>::StateSharedPtr CoreTools::StateEntity<Subclass, EventType>::GetPossiblePreviousState()
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_StateMachineBase.GetPossiblePreviousState();
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_BASE_EVENT_ENTITY_DETAIL_H