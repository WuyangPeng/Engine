///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/29 13:47)

#ifndef CORE_TOOLS_MESSAGE_EVENT_MESSAGE_TELEGRAM_MANAGER_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_MESSAGE_TELEGRAM_MANAGER_DETAIL_H

#include "EntityManagerDetail.h"
#include "Telegram.h"
#include "TelegramMessageManager.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename EventType>
CoreTools::TelegramMessageManager<EventType>::TelegramMessageManager(int64_t difference)
    : telegramLess{ difference }, eventContainer{ telegramLess }, registerContainer{}, eventRegisterContainer{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename EventType>
bool CoreTools::TelegramMessageManager<EventType>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename EventType>
bool CoreTools::TelegramMessageManager<EventType>::RegisterAllEvent(int64_t entityId)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return registerContainer.insert(entityId).second;
}

template <typename EventType>
bool CoreTools::TelegramMessageManager<EventType>::UnRegisterAllEvent(int64_t entityId)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return registerContainer.erase(entityId) != 0;
}

template <typename EventType>
bool CoreTools::TelegramMessageManager<EventType>::Register(EventType eventType, int64_t entityId)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return eventRegisterContainer[eventType].insert(entityId).second;
}

template <typename EventType>
bool CoreTools::TelegramMessageManager<EventType>::UnRegister(EventType eventType, int64_t entityId)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return eventRegisterContainer[eventType].erase(entityId) != 0;
}

template <typename EventType>
void CoreTools::TelegramMessageManager<EventType>::CallEvent(const Telegram& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    eventContainer.insert(telegram);
}

template <typename EventType>
void CoreTools::TelegramMessageManager<EventType>::CallEventImmediately(int64_t currentTime, const Telegram& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (telegram.GetDispatchMillisecondTime() <= currentTime)
    {
        auto receiver = telegram.GetReceiver();
        if (receiver.empty())
        {
            DisposeAllEvent(telegram);
        }
        else
        {
            DisposeEvent(telegram);
        }
    }
    else
    {
        CallEvent(telegram);
    }
}

template <typename EventType>
void CoreTools::TelegramMessageManager<EventType>::DispatchDelayEvent(int64_t currentTime)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto iter = eventContainer.begin(); iter != eventContainer.end();)
    {
        if (iter->GetDispatchMillisecondTime() <= currentTime)
        {
            if (auto receiver = iter->GetReceiver(); receiver.empty())
            {
                DisposeAllEvent(*iter);
            }
            else
            {
                DisposeEvent(*iter);
            }

            eventContainer.erase(iter++);
        }
        else
        {
            break;
        }
    }
}

template <typename EventType>
void CoreTools::TelegramMessageManager<EventType>::DisposeEvent(const Telegram& telegram)
{
    for (auto receiver = telegram.GetReceiver(); auto id : receiver)
    {
        EXCEPTION_TRY
        {
            const auto& container = eventRegisterContainer[telegram.GetMessageType()];

            if (registerContainer.contains(id) || container.contains(id))
            {
                DisposeEvent(id, telegram);
            }
        }
        EXCEPTION_ENGINE_EXCEPTION_CATCH(CoreTools)
    }
}

template <typename EventType>
void CoreTools::TelegramMessageManager<EventType>::DisposeAllEvent(const Telegram& telegram)
{
    auto registerContainerClone = registerContainer;
    const auto& container = eventRegisterContainer[telegram.GetMessageType()];

    registerContainerClone.insert(container.begin(), container.end());

    for (auto id : registerContainerClone)
    {
        try
        {
            DisposeEvent(id, telegram);
        }
        catch (const CoreTools::Error& error)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
}

template <typename EventType>
void CoreTools::TelegramMessageManager<EventType>::DisposeEvent(int64_t entityId, const Telegram& telegram)
{
    const auto entity = ENTITY_MANAGER_SINGLETON.GetEntity(entityId);

    if (auto eventEntity = boost::polymorphic_pointer_downcast<EventEntity>(entity); !eventEntity->EventFunction(telegram))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("EventFunction 失败"));
    }
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_MESSAGE_TELEGRAM_MANAGER_DETAIL_H