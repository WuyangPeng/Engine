///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/26 18:04)

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