///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/10 13:35)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_ACTIVE_MQ_H
#define SYSTEM_HELPER_PRAGMA_WARNING_ACTIVE_MQ_H

#include "System/Helper/PragmaWarning.h"

#ifdef NETWORK_USE_ACTIVE_MQ

    #include STSTEM_WARNING_PUSH
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

    #include STSTEM_WARNING_POP

#endif  // NETWORK_USE_ACTIVE_MQ

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_ACTIVE_MQ_H
