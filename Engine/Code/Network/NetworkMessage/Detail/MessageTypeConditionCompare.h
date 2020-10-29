//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 20:39)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_COMPARE_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_COMPARE_H

#include "Network/NetworkDll.h"

#include "MessageTypeConditionImpl.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MessageTypeConditionCompare final : public MessageTypeConditionImpl
    {
    public:
        using ClassType = MessageTypeConditionCompare;
        using ParentType = MessageTypeConditionImpl;

    public:
        MessageTypeConditionCompare(VersionsCondition condition, int version) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

    public:
        [[nodiscard]] bool IsVersionsConform(int version) const noexcept final;
        [[nodiscard]] int GetMinVersion() const final;
        [[nodiscard]] int GetMaxVersion() const final;

    private:
        VersionsCondition m_Condition;
        int m_Version;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_COMPARE_H
