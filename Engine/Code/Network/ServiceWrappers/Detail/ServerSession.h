﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/14 14:01)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_SERVER_SESSION_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_SERVER_SESSION_H

#include "Network/NetworkDll.h"

#include "SessionImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ServerSession : public SessionImpl
    {
    public:
        using ClassType = ServerSession;
        using ParentType = SessionImpl;

    public:
        explicit ServerSession(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_SERVER_SESSION_H