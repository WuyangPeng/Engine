/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/18 09:36)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_TCP_CLIENT_SERVICE_CONSUMER_H
#define NETWORK_BOOST_WRAPPERS_BOOST_TCP_CLIENT_SERVICE_CONSUMER_H

#include "Network/NetworkDll.h"

#include "Network/ServiceWrappers/Detail/ClientServiceConsumer.h"

#include <thread>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostTcpClientServiceConsumer final : public ClientServiceConsumer
    {
    public:
        using ClassType = BoostTcpClientServiceConsumer;
        using ParentType = ClientServiceConsumer;

    public:
        explicit BoostTcpClientServiceConsumer(ServiceSession& serviceSession, const ConfigurationStrategy& configurationStrategy) noexcept;
        ~BoostTcpClientServiceConsumer() noexcept;
        BoostTcpClientServiceConsumer(const BoostTcpClientServiceConsumer& rhs) = delete;
        BoostTcpClientServiceConsumer& operator=(const BoostTcpClientServiceConsumer& rhs) = delete;
        BoostTcpClientServiceConsumer(BoostTcpClientServiceConsumer&& rhs) noexcept = delete;
        BoostTcpClientServiceConsumer& operator=(BoostTcpClientServiceConsumer&& rhs) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Response(const std::function<void(const std::string&)>& processDataCallback) override;
        void Close() override;

    private:
        void Run();
        void Join();

    private:
        ServiceSession& serviceSession;
        volatile std::atomic_bool isStop;
        std::thread thread;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_TCP_CLIENT_SERVICE_CONSUMER_H
