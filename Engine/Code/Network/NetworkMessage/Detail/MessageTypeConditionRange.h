//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 20:40)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_RANGE_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_RANGE_H

#include "Network/NetworkDll.h"

#include "MessageTypeConditionImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MessageTypeConditionRange final : public MessageTypeConditionImpl
    {
    public:
        using ClassType = MessageTypeConditionRange;
        using ParentType = MessageTypeConditionImpl;

    public:
        MessageTypeConditionRange(int beginVersion, int endVersion);

        CLASS_INVARIANT_FINAL_DECLARE;

    public:
        [[nodiscard]] bool IsVersionsConform(int version) const noexcept final;
        [[nodiscard]] int GetMinVersion() const noexcept final;
        [[nodiscard]] int GetMaxVersion() const noexcept final;

    private:
        int m_BeginVersion;
        int m_EndVersion;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_RANGE_H
