///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 18:01)

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
