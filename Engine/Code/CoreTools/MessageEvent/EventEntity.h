/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:23)

#ifndef CORE_TOOLS_MESSAGE_EVENT_BASE_EVENT_ENTITY_H
#define CORE_TOOLS_MESSAGE_EVENT_BASE_EVENT_ENTITY_H

#include "CoreTools/CoreToolsDll.h"

#include "BaseEntity.h"
#include "TelegramDetail.h"

namespace CoreTools
{
    template <typename EventType = int>
    class EventEntity : public BaseEntity
    {
    public:
        using ClassType = EventEntity<EventType>;
        using ParentType = BaseEntity;

        using TelegramType = Telegram<EventType>;
        using EntityEventType = EventType;
        using EventEntitySharedPtr = std::shared_ptr<EventEntity>;

    public:
        NODISCARD static EventEntitySharedPtr Create();

    protected:
        explicit EventEntity(DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD virtual bool EventFunction(const TelegramType& telegram) = 0;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_BASE_EVENT_ENTITY_H