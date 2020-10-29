//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 20:38)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_IMPL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_IMPL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
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

    public:
        explicit MessageEventManagerImpl(CoreTools::DisableNotThrow disableNotThrow);
        ~MessageEventManagerImpl() noexcept = default;

        MessageEventManagerImpl(const MessageEventManagerImpl& rhs);
        MessageEventManagerImpl& operator=(const MessageEventManagerImpl& rhs);
        MessageEventManagerImpl(MessageEventManagerImpl&& rhs) noexcept;
        MessageEventManagerImpl& operator=(MessageEventManagerImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        void Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);
        void Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
        void Remove(int64_t messageID);
        void Remove(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);

        void OnEvent(int64_t messageID, uint64_t socketID, const ConstMessageInterfaceSharedPtr& message);

    private:
        using EventContainer = std::map<int64_t, MessageEventContainer>;
        using MutexUniquePtr = std::unique_ptr<CoreTools::Mutex>;

    private:
        EventContainer m_EventContainer;
        MutexUniquePtr m_Mutex;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H
