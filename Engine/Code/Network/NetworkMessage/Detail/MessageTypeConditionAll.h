//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 20:39)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_ALL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_ALL_H

#include "Network/NetworkDll.h"

#include "MessageTypeConditionImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MessageTypeConditionAll final : public MessageTypeConditionImpl
    {
    public:
        using ClassType = MessageTypeConditionAll;
        using ParentType = MessageTypeConditionImpl;

    public:
        MessageTypeConditionAll() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

    public:
        [[nodiscard]] bool IsVersionsConform(int version) const noexcept final;
        [[nodiscard]] int GetMinVersion() const noexcept final;
        [[nodiscard]] int GetMaxVersion() const final;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_ALL_H
