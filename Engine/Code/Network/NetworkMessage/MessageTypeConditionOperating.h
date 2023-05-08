///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.7 (2023/05/08 10:04)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_OPERATING_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_OPERATING_H

#include "Network/NetworkDll.h"

#include "NetworkMessageFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageTypeConditionOperating final
    {
    public:
        using ClassType = MessageTypeConditionOperating;

    public:
        MessageTypeConditionOperating() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool operator()(const MessageTypeCondition& lhs, const MessageTypeCondition& rhs) const;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_CONDITION_OPERATING_H
