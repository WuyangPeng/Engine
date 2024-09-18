/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:02)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_SESSION_IMPL_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_SESSION_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/ServiceWrappers/ServiceWrappersInternalFwd.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ServiceSessionImpl
    {
    public:
        using ClassType = ServiceSessionImpl;
        using FactoryType = ServiceSessionFactory;

        using ConsumerSharedPtr = std::shared_ptr<ClassType>;
        using String = System::String;

    public:
        explicit ServiceSessionImpl(ConfigurationStrategy configurationStrategy) noexcept;
        virtual ~ServiceSessionImpl() noexcept = 0;

        ServiceSessionImpl(const ServiceSessionImpl& rhs) noexcept = delete;
        ServiceSessionImpl& operator=(const ServiceSessionImpl& rhs) noexcept = delete;
        ServiceSessionImpl(ServiceSessionImpl&& rhs) noexcept;
        ServiceSessionImpl& operator=(ServiceSessionImpl&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void SendTextMessage(const std::string& message);
        virtual void Response(const std::function<void(const std::string&)>& processDataCallback);
        virtual void Run();
        virtual void Stop();

    protected:
        NODISCARD std::string GetHost() const;
        NODISCARD int GetPort() const noexcept;

    private:
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_SESSION_IMPL_H
