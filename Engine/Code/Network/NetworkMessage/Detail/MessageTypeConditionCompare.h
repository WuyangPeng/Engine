///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 11:02)

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
        NODISCARD bool IsVersionsConform(int version) const noexcept final;
        NODISCARD int GetMinVersion() const final;
        NODISCARD int GetMaxVersion() const final;

    private:
        VersionsCondition condition;
        int m_Version;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_COMPARE_H
