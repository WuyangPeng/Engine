/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 18:07)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_ACTIVE_MQ_H
#define SYSTEM_HELPER_PRAGMA_WARNING_ACTIVE_MQ_H

#include "System/Helper/PragmaWarning.h"

#ifdef NETWORK_USE_ACTIVE_MQ

    #include SYSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(4100)
    #include SYSTEM_WARNING_DISABLE(4458)

    #include SYSTEM_WARNING_DISABLE(26409)
    #include SYSTEM_WARNING_DISABLE(26429)
    #include SYSTEM_WARNING_DISABLE(26432)
    #include SYSTEM_WARNING_DISABLE(26433)
    #include SYSTEM_WARNING_DISABLE(26440)
    #include SYSTEM_WARNING_DISABLE(26447)
    #include SYSTEM_WARNING_DISABLE(26455)
    #include SYSTEM_WARNING_DISABLE(26493)

    #include <activemq/core/ActiveMQConnectionFactory.h>
    #include <activemq/library/ActiveMQCPP.h>
    #include <cms/Connection.h>

    #include SYSTEM_WARNING_POP

#endif  // NETWORK_USE_ACTIVE_MQ

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_ACTIVE_MQ_H
