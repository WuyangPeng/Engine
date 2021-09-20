//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 16:03)

#ifndef CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_DETAIL_H
#define CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_DETAIL_H

#include "DefaultEventDispatcherDetail.h"
#include "EventDispatcherDetail.h"
#include "GenerateDispatcher.h"
#include "StateMachine.h"
#include "StateMachineRowDetail.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
template <typename Derived, typename State>
CoreTools::StateMachine<Derived, State>::StateMachine() noexcept
    : m_State{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Derived, typename State>
CoreTools::StateMachine<Derived, State>::~StateMachine() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Derived, typename State>
bool CoreTools::StateMachine<Derived, State>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26466)
template <typename Derived, typename State>
template <typename EventType>
typename CoreTools::StateMachine<Derived, State>::StateType CoreTools::StateMachine<Derived, State>::CallNoTransition(StateType state, const EventType& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return static_cast<Derived*>(this)->NoTransition(state, eventType);
}

template <typename Derived, typename State>
template <typename EventType>
typename CoreTools::StateMachine<Derived, State>::StateType CoreTools::StateMachine<Derived, State>::ProcessEvent(const EventType& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using Dispatcher = typename GenerateDispatcher<typename Derived::TransitionTable, EventType, StateType>::type;

    m_State = Dispatcher::Dispatch(*static_cast<Derived*>(this), m_State, eventType);

    return m_State;
}
#include STSTEM_WARNING_POP
template <typename Derived, typename State>
template <typename EventType>
typename CoreTools::StateMachine<Derived, State>::StateType CoreTools::StateMachine<Derived, State>::NoTransition([[maybe_unused]] StateType state, [[maybe_unused]] const EventType& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetStateType();
}

template <typename Derived, typename State>
typename CoreTools::StateMachine<Derived, State>::StateType CoreTools::StateMachine<Derived, State>::GetStateType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_State;
}

template <typename Derived, typename State>
void CoreTools::StateMachine<Derived, State>::SetStateType(StateType stateType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_State = stateType;
}

#endif  //  CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_DETAIL_H
