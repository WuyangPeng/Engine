//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:43)

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
    : m_TelegramLess{ difference }, m_EventContainer{ m_TelegramLess }, m_RegisterContainer{}, m_EventRegisterContainer{}
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
bool CoreTools::TelegramMessageManager<EventType>::RegisterAllEvent(uint64_t entityID)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_RegisterContainer.insert(entityID).second;
}

template <typename EventType>
bool CoreTools::TelegramMessageManager<EventType>::UnregisterAllEvent(uint64_t entityID)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_RegisterContainer.erase(entityID) != 0;
}

template <typename EventType>
bool CoreTools::TelegramMessageManager<EventType>::Register(EventType eventType, uint64_t entityID)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_EventRegisterContainer[eventType].insert(entityID).second;
}

template <typename EventType>
bool CoreTools::TelegramMessageManager<EventType>::Unregister(EventType eventType, uint64_t entityID)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_EventRegisterContainer[eventType].erase(entityID) != 0;
}

template <typename EventType>
void CoreTools::TelegramMessageManager<EventType>::CallEvent(const Telegram& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_EventContainer.insert(telegram);
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

    for (auto iter = m_EventContainer.begin(); iter != m_EventContainer.end();)
    {
        if (iter->GetDispatchMillisecondTime() <= currentTime)
        {
            auto receiver = iter->GetReceiver();
            if (receiver.empty())
            {
                DisposeAllEvent(*iter);
            }
            else
            {
                DisposeEvent(*iter);
            }

            m_EventContainer.erase(iter++);
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
    auto receiver = telegram.GetReceiver();
    for (auto id : receiver)
    {
        EXCEPTION_TRY
        {
            const auto& container = m_EventRegisterContainer[telegram.GetMessageType()];

            if (m_RegisterContainer.find(id) != m_RegisterContainer.cend() || container.find(id) != container.cend())
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
    auto registerContainer = m_RegisterContainer;
    const auto& container = m_EventRegisterContainer[telegram.GetMessageType()];

    registerContainer.insert(container.begin(), container.end());

    for (auto id : registerContainer)
    {
        try
        {
            DisposeEvent(id, telegram);
        }
        catch (CoreTools::Error& error)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
                << error
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }
}

template <typename EventType>
void CoreTools::TelegramMessageManager<EventType>::DisposeEvent(uint64_t entityID, const Telegram& telegram)
{
    auto entity = ENTITY_MANAGER_SINGLETON.GetEntity(entityID);

    auto eventEntity = boost::polymorphic_pointer_downcast<EventEntity>(entity);

    eventEntity->EventFunction(telegram);
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_MESSAGE_TELEGRAM_MANAGER_DETAIL_H