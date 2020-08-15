// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:24)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_IMPL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_IMPL_H

#include "Network/NetworkDll.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MessageTypeConditionImpl
    {
    public:
        using ClassType = MessageTypeConditionImpl;

    public:
        MessageTypeConditionImpl() noexcept;
        virtual ~MessageTypeConditionImpl();
        MessageTypeConditionImpl(const MessageTypeConditionImpl&) = default;
        MessageTypeConditionImpl& operator=(const MessageTypeConditionImpl&) = default;
        MessageTypeConditionImpl(MessageTypeConditionImpl&&) noexcept = default;
        MessageTypeConditionImpl& operator=(MessageTypeConditionImpl&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    public:
        virtual bool IsVersionsConform(int version) const = 0;
        virtual int GetMinVersion() const = 0;
        virtual int GetMaxVersion() const = 0;
    };

    bool operator<(const MessageTypeConditionImpl& lhs, const MessageTypeConditionImpl& rhs);
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_IMPL_H
