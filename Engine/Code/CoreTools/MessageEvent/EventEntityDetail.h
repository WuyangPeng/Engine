//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:39)

#ifndef CORE_TOOLS_MESSAGE_EVENT_BASE_EVENT_ENTITY_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_BASE_EVENT_ENTITY_DETAIL_H

#include "EventEntity.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename EventType>
CoreTools::EventEntity<EventType>::EventEntity()
    : ParentType{}
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