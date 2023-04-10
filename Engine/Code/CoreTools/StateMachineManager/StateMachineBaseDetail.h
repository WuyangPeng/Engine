///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:01)

#ifndef CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_BASE_DETAIL_H
#define CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_BASE_DETAIL_H

#include "StateMachineBase.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename EntityType, typename EventType>
CoreTools::StateMachineBase<EntityType, EventType>::StateMachineBase(StateSharedPtr currentState) noexcept
    : currentState{ currentState }, previousState{}, globalState{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename EntityType, typename EventType>
CoreTools::StateMachineBase<EntityType, EventType>::StateMachineBase(StateSharedPtr currentState, StateSharedPtr globalState) noexcept
    : currentState{ currentState }, previousState{}, globalState{ globalState }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename EntityType, typename EventType>
void CoreTools::StateMachineBase<EntityType, EventType>::Register(EntityTypePtr owner)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    currentState->Enter(owner);

    if (globalState)
    {
        globalState->Enter(owner);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename EntityType, typename EventType>
bool CoreTools::StateMachineBase<EntityType, EventType>::IsValid() const noexcept
{
    if (currentState)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename EntityType, typename EventType>
typename CoreTools::StateMachineBase<EntityType, EventType>::ConstStateSharedPtr CoreTools::StateMachineBase<EntityType, EventType>::GetPreviousState() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return previousState;
}

template <typename EntityType, typename EventType>
typename CoreTools::StateMachineBase<EntityType, EventType>::StateSharedPtr CoreTools::StateMachineBase<EntityType, EventType>::GetPossiblePreviousState() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return std::const_pointer_cast<State>(static_cast<const ClassType*>(this)->GetPossiblePreviousState());

#include STSTEM_WARNING_POP
}

template <typename EntityType, typename EventType>
typename CoreTools::StateMachineBase<EntityType, EventType>::ConstStateSharedPtr CoreTools::StateMachineBase<EntityType, EventType>::GetPossiblePreviousState() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (previousState)
        return previousState;
    else
        return currentState;
}

template <typename EntityType, typename EventType>
typename CoreTools::StateMachineBase<EntityType, EventType>::ConstStateSharedPtr CoreTools::StateMachineBase<EntityType, EventType>::GetGlobalState() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return globalState;
}

template <typename EntityType, typename EventType>
typename CoreTools::StateMachineBase<EntityType, EventType>::ConstStateSharedPtr CoreTools::StateMachineBase<EntityType, EventType>::GetCurrentState() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return currentState;
}

template <typename EntityType, typename EventType>
bool CoreTools::StateMachineBase<EntityType, EventType>::IsInState(const State& state) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (typeid(*currentState) == typeid(state))
        return true;
    else
        return false;
}

template <typename EntityType, typename EventType>
bool CoreTools::StateMachineBase<EntityType, EventType>::HandleMessage(const Telegram& msg)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (const auto result = currentState->OnMessage(msg); result.second)
    {
        if (result.first != currentState)
        {
            ChangeState(result.first);
        }

        return true;
    }

    if (globalState)
    {
        if (const auto globalResult = globalState->OnMessage(msg); globalResult.second)
        {
            if (globalResult.first != currentState)
            {
                ChangeState(globalResult.first);
            }

            return true;
        }
    }

    return false;
}

template <typename EntityType, typename EventType>
void CoreTools::StateMachineBase<EntityType, EventType>::Update(int64_t timeInterval)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (globalState)
    {
        globalState->Execute(timeInterval);
    }

    const auto state = currentState->Execute(timeInterval);

    if (state != currentState)
    {
        ChangeState(state);
    }
}

template <typename EntityType, typename EventType>
void CoreTools::StateMachineBase<EntityType, EventType>::ChangeState(const StateSharedPtr& newState)
{
    auto owner = currentState->GetOwner();

    previousState = currentState;

    currentState->Exit();

    currentState = newState;

    currentState->Enter(owner);
}

#endif  //  CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_BASE_DETAIL_H
