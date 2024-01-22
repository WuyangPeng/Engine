/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:11)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_IMPL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_IMPL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "CoreTools/Threading/Mutex.h"
#include "Network/NetworkMessage/MessageEventContainer.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <map>
#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MessageEventManagerImpl final
    {
    public:
        using ClassType = MessageEventManagerImpl;

        using EventInterfaceSharedPtr = CoreTools::EventInterfaceSharedPtr;
        using EventInterfaceWeakPtr = CoreTools::EventInterfaceWeakPtr;

    public:
        explicit MessageEventManagerImpl(CoreTools::DisableNotThrow disableNotThrow);
        ~MessageEventManagerImpl() noexcept = default;

        MessageEventManagerImpl(const MessageEventManagerImpl& rhs);
        MessageEventManagerImpl& operator=(const MessageEventManagerImpl& rhs);
        MessageEventManagerImpl(MessageEventManagerImpl&& rhs) noexcept;
        MessageEventManagerImpl& operator=(MessageEventManagerImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        void Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent);
        void Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
        void Remove(int64_t messageId);
        void Remove(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent);
        void Insert(const std::string& messageDescribe, const NetworkMessageEventSharedPtr& messageEvent);
        void Insert(const std::string& messageDescribe, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);

        void OnEvent(int64_t socketId, int64_t messageId, const ConstMessageInterfaceSharedPtr& message);
        void OnEvent(int64_t socketId, const std::string& messageDescribe, const ConstMessageInterfaceSharedPtr& message);

        void SetCallbackEvent(const EventInterfaceSharedPtr& aEvent);
        NODISCARD EventInterfaceSharedPtr GetCallbackEvent();

    private:
        using IdEventContainer = std::map<int64_t, MessageEventContainer>;
        using DescribeEventContainer = std::map<std::string, MessageEventContainer>;
        using MutexUniquePtr = std::unique_ptr<CoreTools::Mutex>;

    private:
        IdEventContainer idEventContainer;
        DescribeEventContainer describeEventContainer;
        MutexUniquePtr mutex;
        EventInterfaceWeakPtr event;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H
