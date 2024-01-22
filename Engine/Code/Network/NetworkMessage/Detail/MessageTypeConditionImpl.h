/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:12)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_IMPL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/NetworkMessageFwd.h"

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
        using ImplSharedPtr = std::shared_ptr<MessageTypeConditionImpl>;

    public:
        MessageTypeConditionImpl() noexcept;
        virtual ~MessageTypeConditionImpl() noexcept = default;
        MessageTypeConditionImpl(const MessageTypeConditionImpl& rhs) noexcept = default;
        MessageTypeConditionImpl& operator=(const MessageTypeConditionImpl& rhs) noexcept = default;
        MessageTypeConditionImpl(MessageTypeConditionImpl&& rhs) noexcept = default;
        MessageTypeConditionImpl& operator=(MessageTypeConditionImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    public:
        NODISCARD virtual bool IsVersionsConform(int version) const = 0;
        NODISCARD virtual int GetMinVersion() const = 0;
        NODISCARD virtual int GetMaxVersion() const = 0;

        NODISCARD static ImplSharedPtr Create(const VersionType& version);
        NODISCARD static ImplSharedPtr Create(int beginVersion, int endVersion);
        NODISCARD static ImplSharedPtr Create(VersionsCondition condition, int version);
        NODISCARD static ImplSharedPtr Create();
    };

    NODISCARD bool operator<(const MessageTypeConditionImpl& lhs, const MessageTypeConditionImpl& rhs);
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_IMPL_H
