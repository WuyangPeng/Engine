///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:22)

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
        NODISCARD bool IsVersionsConform(int version) const noexcept override;
        NODISCARD int GetMinVersion() const noexcept override;
        NODISCARD int GetMaxVersion() const override;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_ALL_H
