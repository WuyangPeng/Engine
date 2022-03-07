///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 10:52)

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
        explicit MessageEventManagerImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
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
        EventContainer eventContainer;
        MutexUniquePtr mutex;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H
