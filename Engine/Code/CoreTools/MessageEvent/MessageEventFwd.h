///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:22)

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