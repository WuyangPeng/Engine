/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:47)

#ifndef CORE_TOOLS_MESSAGE_EVENT_BASE_EVENT_ENTITY_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_BASE_EVENT_ENTITY_DETAIL_H

#include "EventEntity.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename EventType>
typename CoreTools::EventEntity<EventType>::EventEntitySharedPtr CoreTools::EventEntity<EventType>::Create()
{
    return std::make_shared<ClassType>(DisableNotThrow::Disable);
}

template <typename EventType>
CoreTools::EventEntity<EventType>::EventEntity(DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename EventType>
bool CoreTools::EventEntity<EventType>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // CORE_TOOLS_MESSAGE_EVENT_BASE_EVENT_ENTITY_DETAIL_H