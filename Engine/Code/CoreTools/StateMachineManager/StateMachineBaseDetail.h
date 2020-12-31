//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 16:02)

#ifndef CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_BASE_DETAIL_H
#define CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_BASE_DETAIL_H

#include "StateMachineBase.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename EntityType, typename EventType>
CoreTools::StateMachineBase<EntityType, EventType>::StateMachineBase(StateSharedPtr currentState)
    : m_CurrentState{ currentState }, m_PreviousState{}, m_GlobalState{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename EntityType, typename EventType>
CoreTools::StateMachineBase<EntityType, EventType>::StateMachineBase(StateSharedPtr currentState, StateSharedPtr globalState)
    : m_CurrentState{ currentState }, m_PreviousState{}, m_GlobalState{ globalState }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

template <typename EntityType, typename EventType>
void CoreTools::StateMachineBase<EntityType, EventType>::Register(EntityTypePtr owner)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_CurrentState->Enter(owner);

    if (m_GlobalState)
    {
        m_GlobalState->Enter(owner);
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename EntityType, typename EventType>
bool CoreTools::StateMachineBase<EntityType, EventType>::IsValid() const noexcept
{
    if (m_CurrentState)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename EntityType, typename EventType>
typename CoreTools::StateMachineBase<EntityType, EventType>::ConstStateSharedPtr CoreTools::StateMachineBase<EntityType, EventType>::GetPreviousState() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_PreviousState;
}

template <typename EntityType, typename EventType>
typename CoreTools::StateMachineBase<EntityType, EventType>::StateSharedPtr CoreTools::StateMachineBase<EntityType, EventType>::GetPossiblePreviousState()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return std::const_pointer_cast<State>(static_cast<const ClassType*>(this)->GetPossiblePreviousState());
}

template <typename EntityType, typename EventType>
typename CoreTools::StateMachineBase<EntityType, EventType>::ConstStateSharedPtr CoreTools::StateMachineBase<EntityType, EventType>::GetPossiblePreviousState() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (m_PreviousState)
        return m_PreviousState;
    else
        return m_CurrentState;
}

template <typename EntityType, typename EventType>
typename CoreTools::StateMachineBase<EntityType, EventType>::ConstStateSharedPtr CoreTools::StateMachineBase<EntityType, EventType>::GetGlobalState() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_GlobalState;
}

template <typename EntityType, typename EventType>
typename CoreTools::StateMachineBase<EntityType, EventType>::ConstStateSharedPtr CoreTools::StateMachineBase<EntityType, EventType>::GetCurrentState() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_CurrentState;
}

template <typename EntityType, typename EventType>
bool CoreTools::StateMachineBase<EntityType, EventType>::IsInState(const State& state) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    if (typeid(*m_CurrentState) == typeid(state))
        return true;
    else
        return false;
}

template <typename EntityType, typename EventType>
bool CoreTools::StateMachineBase<EntityType, EventType>::HandleMessage(const Telegram& msg)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto result = m_CurrentState->OnMessage(msg);

    if (result.second)
    {
        if (result.first != m_CurrentState)
        {
            ChangeState(result.first);
        }

        return true;
    }

    if (m_GlobalState)
    {
        auto globalResult = m_GlobalState->OnMessage(msg);

        if (globalResult.second)
        {
            if (globalResult.first != m_CurrentState)
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

    if (m_GlobalState)
    {
        m_GlobalState->Execute(timeInterval);
    }

    auto state = m_CurrentState->Execute(timeInterval);

    if (state != m_CurrentState)
    {
        ChangeState(state);
    }
}

// private
template <typename EntityType, typename EventType>
void CoreTools::StateMachineBase<EntityType, EventType>::ChangeState(StateSharedPtr newState)
{
    auto owner = m_CurrentState->GetOwner();

    m_PreviousState = m_CurrentState;

    m_CurrentState->Exit();

    m_CurrentState = newState;

    m_CurrentState->Enter(owner);
}

#endif  //  CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_BASE_DETAIL_H
