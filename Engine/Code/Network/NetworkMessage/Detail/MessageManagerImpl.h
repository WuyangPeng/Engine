//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 20:38)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/MessageTypeConditionOperating.h"

#include <map>
#include <string>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MessageManagerImpl final
    {
    public:
        using ClassType = MessageManagerImpl;
        using FactoryFunction = MessageInterface::FactoryFunction;

    public:
        MessageManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] FactoryFunction Find(int64_t messageID, int version) const;
        void Insert(int64_t messageID, const MessageTypeCondition& messageTypeCondition, FactoryFunction function);
        void Remove(int64_t messageID, const MessageTypeCondition& messageTypeCondition);
        void Remove(int64_t messageID);

        void SetFullVersion(int fullVersion) noexcept;
        [[nodiscard]] int GetFullVersion() const noexcept;

    private:
        using ConditionContainer = std::map<MessageTypeCondition, FactoryFunction, MessageTypeConditionOperating>;
        using FactoryContainer = std::map<int64_t, ConditionContainer>;

    private:
        FactoryContainer m_Factories;
        int m_FullVersion;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H
