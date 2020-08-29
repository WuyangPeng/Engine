// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:24)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_COMPARE_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_COMPARE_H

#include "Network/NetworkDll.h"

#include "MessageTypeConditionImpl.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MessageTypeConditionCompare : public MessageTypeConditionImpl
    {
    public:
        using ClassType = MessageTypeConditionCompare;
        using ParentType = MessageTypeConditionImpl;

    public:
        MessageTypeConditionCompare(VersionsCondition condition, int version) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    public:
        bool IsVersionsConform(int version) const noexcept override;
        int GetMinVersion() const override;
        int GetMaxVersion() const override;

    private:
        VersionsCondition m_Condition;
        int m_Version;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_COMPARE_H
