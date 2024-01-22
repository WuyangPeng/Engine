/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:19)

#ifndef CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_DETAIL_H
#define CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_DETAIL_H

#include "DefaultEventDispatcherDetail.h"
#include "EventDispatcherDetail.h"
#include "GenerateDispatcher.h"
#include "StateMachine.h"
#include "StateMachineRowDetail.h"
#include "System/Helper/PragmaWarning/PolymorphicCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Derived, typename State>
CoreTools::StateMachine<Derived, State>::StateMachine() noexcept
    : state{}
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

template <typename Derived, typename State>
template <typename EventType>
typename CoreTools::StateMachine<Derived, State>::StateType CoreTools::StateMachine<Derived, State>::CallNoTransition(StateType aState, const EventType& eventType)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return boost::polymorphic_downcast<Derived*>(this)->NoTransition(aState, eventType);
}

template <typename Derived, typename State>
template <typename EventType>
typename CoreTools::StateMachine<Derived, State>::StateType CoreTools::StateMachine<Derived, State>::ProcessEvent(const EventType& eventType)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    using Dispatcher = typename GenerateDispatcher<typename Derived::TransitionTable, EventType, StateType>::type;

    state = Dispatcher::Dispatch(boost::polymorphic_downcast<Derived&>(*this), state, eventType);

    return state;
}

template <typename Derived, typename State>
template <typename EventType>
typename CoreTools::StateMachine<Derived, State>::StateType CoreTools::StateMachine<Derived, State>::NoTransition([[maybe_unused]] StateType aState, [[maybe_unused]] const EventType& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetStateType();
}

template <typename Derived, typename State>
typename CoreTools::StateMachine<Derived, State>::StateType CoreTools::StateMachine<Derived, State>::GetStateType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return state;
}

template <typename Derived, typename State>
void CoreTools::StateMachine<Derived, State>::SetStateType(StateType stateType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    state = stateType;
}

#endif  //  CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_DETAIL_H
