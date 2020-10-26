//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:13)

#ifndef CORE_TOOLS_MESSAGE_EVENT_FWD_H
#define CORE_TOOLS_MESSAGE_EVENT_FWD_H

namespace CoreTools
{
    class ParametersInterface;
    class CallbackParameters;
    class EventInterface;

    template <typename T, typename PriorityType>
    class EventSlot;

    template <typename EventSlot>
    class EventSlotManager;

    template <typename EventSlot, typename EventType>
    class MessageManager;

    template <typename EventType>
    class Telegram;

    template <typename EventType>
    class TelegramLess;

    class BaseEntity;

    class EntityManager;

    template <typename EventType>
    class EventEntity;

    template <typename EventType>
    class TelegramMessageManager;
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_FWD_H