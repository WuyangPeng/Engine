///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/29 13:36)

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

        using Telegram = Telegram<EventType>;
        using EntityEventType = EventType;
        using EventEntitySharedPtr = std::shared_ptr<EventEntity>;

    public:
        NODISCARD static EventEntitySharedPtr Create();

    protected:
        explicit EventEntity(DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD virtual bool EventFunction(const Telegram& telegram) = 0;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_BASE_EVENT_ENTITY_H