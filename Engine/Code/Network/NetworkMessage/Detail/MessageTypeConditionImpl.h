//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 20:39)

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
    };

    bool operator<(const MessageTypeConditionImpl& lhs, const MessageTypeConditionImpl& rhs);
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_IMPL_H
