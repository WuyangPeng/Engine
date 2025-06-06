/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:25)

#ifndef CORE_TOOLS_MESSAGE_EVENT_MESSAGE_TELEGRAM_MANAGER_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_MESSAGE_TELEGRAM_MANAGER_DETAIL_H

#include "EntityManagerDetail.h"
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
bool CoreTools::TelegramMessageManager<EventType>::UnRegisterAllEvent(int64_t entityId) noexcept
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
void CoreTools::TelegramMessageManager<EventType>::CallEvent(const TelegramType& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    eventContainer.insert(telegram);
}

template <typename EventType>
void CoreTools::TelegramMessageManager<EventType>::CallEventImmediately(int64_t currentTime, const TelegramType& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (telegram.GetDispatchMillisecondTime() <= currentTime)
    {
        if (auto receiver = telegram.GetReceiver();
            receiver.empty())
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
void CoreTools::TelegramMessageManager<EventType>::DisposeEvent(const TelegramType& telegram)
{
    for (auto receiver = telegram.GetReceiver();
         auto id : receiver)
    {
        EXCEPTION_TRY
        {
            if (const auto& container = eventRegisterContainer[telegram.GetMessageType()];
                registerContainer.contains(id) || container.contains(id))
            {
                DisposeEvent(id, telegram);
            }
        }
        EXCEPTION_ENGINE_EXCEPTION_CATCH(CoreTools)
    }
}

template <typename EventType>
void CoreTools::TelegramMessageManager<EventType>::DisposeAllEvent(const TelegramType& telegram)
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
void CoreTools::TelegramMessageManager<EventType>::DisposeEvent(int64_t entityId, const TelegramType& telegram)
{
    const auto entity = ENTITY_MANAGER_SINGLETON.GetEntity(entityId);

    if (auto eventEntity = boost::polymorphic_pointer_downcast<EventEntityType>(entity);
        !eventEntity->EventFunction(telegram))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("EventFunction ʧ��"));
    }
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_MESSAGE_TELEGRAM_MANAGER_DETAIL_H