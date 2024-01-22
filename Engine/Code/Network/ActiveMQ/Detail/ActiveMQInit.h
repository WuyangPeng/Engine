/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:27)

#ifndef NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_INIT_H
#define NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_INIT_H

#include "Network/NetworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ActiveMQInit
    {
    public:
        using ClassType = ActiveMQInit;

    public:
        explicit ActiveMQInit(CoreTools::DisableNotThrow disableNotThrow);
        ~ActiveMQInit() noexcept;
        ActiveMQInit(const ActiveMQInit& rhs) = delete;
        ActiveMQInit& operator=(const ActiveMQInit& rhs) = delete;
        ActiveMQInit(ActiveMQInit&& rhs) noexcept = delete;
        ActiveMQInit& operator=(ActiveMQInit&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_INIT_H
