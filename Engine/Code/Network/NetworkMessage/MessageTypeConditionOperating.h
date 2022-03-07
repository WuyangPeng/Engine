///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 18:01)

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
