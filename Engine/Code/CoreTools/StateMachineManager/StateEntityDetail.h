/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:20)

#ifndef CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_ENTITY_DETAIL_H
#define CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_ENTITY_DETAIL_H

#include "StateEntity.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Subclass, typename EventType>
CoreTools::StateEntity<Subclass, EventType>::StateEntity(const StateSharedPtr& currentState)
    : ParentType{ DisableNotThrow::Disable }, stateMachineBase{ currentState }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Subclass, typename EventType>
CoreTools::StateEntity<Subclass, EventType>::StateEntity(const StateSharedPtr& currentState, const StateSharedPtr& globalState)
    : ParentType{ DisableNotThrow::Disable }, stateMachineBase{ currentState, globalState }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#include SYSTEM_WARNING_POP

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

    const auto owner = boost::polymorphic_pointer_downcast<Subclass>(ParentType::shared_from_this());

    stateMachineBase.Register(owner);
}

template <typename Subclass, typename EventType>
bool CoreTools::StateEntity<Subclass, EventType>::EventFunction(const TelegramType& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return stateMachineBase.HandleMessage(telegram);
}

template <typename Subclass, typename EventType>
void CoreTools::StateEntity<Subclass, EventType>::Update(int64_t timeInterval)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return stateMachineBase.Update(timeInterval);
}

template <typename Subclass, typename EventType>
typename CoreTools::StateEntity<Subclass, EventType>::ConstStateSharedPtr CoreTools::StateEntity<Subclass, EventType>::GetCurrentState() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return stateMachineBase.GetCurrentState();
}

template <typename Subclass, typename EventType>
typename CoreTools::StateEntity<Subclass, EventType>::ConstStateSharedPtr CoreTools::StateEntity<Subclass, EventType>::GetGlobalState() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return stateMachineBase.GetGlobalState();
}

template <typename Subclass, typename EventType>
typename CoreTools::StateEntity<Subclass, EventType>::StateSharedPtr CoreTools::StateEntity<Subclass, EventType>::GetPossiblePreviousState() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return stateMachineBase.GetPossiblePreviousState();
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_BASE_EVENT_ENTITY_DETAIL_H