/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:02)

#ifndef NETWORK_SERVICE_WRAPPERS_SOCKET_SESSION_IMPL_H
#define NETWORK_SERVICE_WRAPPERS_SOCKET_SESSION_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/ServiceWrappers/ServiceWrappersInternalFwd.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SessionImpl
    {
    public:
        using ClassType = SessionImpl;
        using FactoryType = SessionFactory;

        using SessionSharedPtr = std::shared_ptr<ClassType>;

    public:
        explicit SessionImpl(ConfigurationStrategy configurationStrategy) noexcept;
        virtual ~SessionImpl() noexcept = 0;
        SessionImpl(const SessionImpl& rhs) noexcept = delete;
        SessionImpl& operator=(const SessionImpl& rhs) noexcept = delete;
        SessionImpl(SessionImpl&& rhs) noexcept;
        SessionImpl& operator=(SessionImpl&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    private:
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SOCKET_SESSION_IMPL_H
