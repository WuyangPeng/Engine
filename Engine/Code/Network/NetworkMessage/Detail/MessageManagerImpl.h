///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:21)

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
        NODISCARD FactoryFunction Find(int64_t messageId, int version) const;
        NODISCARD FactoryFunction Find(const std::string& messageDescribe, int version) const;

        void Insert(int64_t messageId, const MessageTypeCondition& messageTypeCondition, FactoryFunction function);
        void Insert(const std::string& messageDescribe, const MessageTypeCondition& messageTypeCondition, FactoryFunction function);
        void Remove(int64_t messageId, const MessageTypeCondition& messageTypeCondition);
        void Remove(int64_t messageId);

        void SetFullVersion(int aFullVersion) noexcept;
        NODISCARD int GetFullVersion() const noexcept;

    private:
        using ConditionContainer = std::map<MessageTypeCondition, FactoryFunction, MessageTypeConditionOperating>;
        using IdFactoryContainer = std::map<int64_t, ConditionContainer>;
        using DescribeFactoryContainer = std::map<std::string, ConditionContainer>;

    private:
        IdFactoryContainer idFactories;
        DescribeFactoryContainer describeFactories;
        int fullVersion;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_IMPL_H
