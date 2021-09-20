//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 20:39)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_IMPL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_IMPL_H

#include "Network/NetworkDll.h"

#include "../NetworkMessageFwd.h"
#include <memory>
#include <set>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MessageTypeConditionImpl
    {
    public:
        using ClassType = MessageTypeConditionImpl;
        using FactoryType = MessageTypeConditionImpl;
        using VersionType = std::set<int>;

    public:
        MessageTypeConditionImpl() noexcept;
        virtual ~MessageTypeConditionImpl() noexcept = default;
        MessageTypeConditionImpl(const MessageTypeConditionImpl&) = default;
        MessageTypeConditionImpl& operator=(const MessageTypeConditionImpl&) = default;
        MessageTypeConditionImpl(MessageTypeConditionImpl&&) noexcept = default;
        MessageTypeConditionImpl& operator=(MessageTypeConditionImpl&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    public:
        [[nodiscard]] virtual bool IsVersionsConform(int version) const = 0;
        [[nodiscard]] virtual int GetMinVersion() const = 0;
        [[nodiscard]] virtual int GetMaxVersion() const = 0;

        static std::shared_ptr<MessageTypeConditionImpl> Create(const VersionType& version);
        static std::shared_ptr<MessageTypeConditionImpl> Create(int beginVersion, int endVersion);
        static std::shared_ptr<MessageTypeConditionImpl> Create(VersionsCondition condition, int version);
        static std::shared_ptr<MessageTypeConditionImpl> Create();
    };

    bool operator<(const MessageTypeConditionImpl& lhs, const MessageTypeConditionImpl& rhs);
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_IMPL_H
