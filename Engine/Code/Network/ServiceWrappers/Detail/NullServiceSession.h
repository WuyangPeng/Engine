///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/11 17:03)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_NULL_SERVICE_SESSION_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_NULL_SERVICE_SESSION_H

#include "Network/NetworkDll.h"

#include "ServiceSessionImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullServiceSession final : public ServiceSessionImpl
    {
    public:
        using ClassType = NullServiceSession;
        using ParentType = ServiceSessionImpl;

    public:
        explicit NullServiceSession(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_NULL_SERVICE_SESSION_H