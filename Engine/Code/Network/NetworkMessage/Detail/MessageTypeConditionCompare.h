/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:12)

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
        NODISCARD bool IsVersionsConform(int version) const noexcept override;
        NODISCARD int GetMinVersion() const override;
        NODISCARD int GetMaxVersion() const override;

    private:
        VersionsCondition condition;
        int compareVersion;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_COMPARE_H
