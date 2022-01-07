///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 16:16)

#ifndef CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_DETAIL_H
#define CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_DETAIL_H

#include "State.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename EventType>
CoreTools::State<EventType>::State() noexcept
    : m_Entity{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename EventType>
bool CoreTools::State<EventType>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename EntityType>
void CoreTools::State<EntityType>::Enter(EntityTypeSharedPtr entity)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Entity = entity;

    DoEnter();
}

template <typename EntityType>
typename CoreTools::State<EntityType>::EntityTypeSharedPtr CoreTools::State<EntityType>::GetOwner()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto entity = m_Entity.lock();

    if (entity)
    {
        return entity;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("实体已释放"s));
    }
}

template <typename EntityType>
typename CoreTools::State<EntityType>::StateSharedPtr CoreTools::State<EntityType>::GetPossiblePreviousState()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetOwner()->GetPossiblePreviousState();
}

// static
template <typename EventType>
template <typename StateType, typename ResultType, typename... Args>
static std::shared_ptr<ResultType> CoreTools::State<EventType>::MakeState(Args&&... args)
{
    return std::make_shared<StateType>(args...);
}

template <typename EntityType>
const CoreTools::Rtti& CoreTools::State<EntityType>::GetRttiType() const noexcept
{
    return GetCurrentRttiType();
}

template <typename EntityType>
const CoreTools::Rtti& CoreTools::State<EntityType>::GetCurrentRttiType() noexcept
{
    static const CoreTools::Rtti rtti{ "CoreTools.State<EntityType>", nullptr };

    return rtti;
}

template <typename EntityType>
bool CoreTools::State<EntityType>::IsExactly(const Rtti& rtti) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetRttiType().IsExactly(rtti);
}

#endif  // CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_DETAIL_H