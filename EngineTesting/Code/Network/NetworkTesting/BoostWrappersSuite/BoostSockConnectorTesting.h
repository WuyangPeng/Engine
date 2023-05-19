///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 10:35)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BOOST_SOCK_CONNECTOR_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BOOST_SOCK_CONNECTOR_TESTING_H

#include "BoostSockTesting.h"

namespace Network
{
    class BoostSockConnectorTesting : public BoostSockTesting
    {
    public:
        using ClassType = BoostSockConnectorTesting;
        using ParentType = BoostSockTesting;

    public:
        explicit BoostSockConnectorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    protected:
        using TestingType = SockConnector;
        using TestingTypeSharedPtr = std::shared_ptr<SockConnector>;

    protected:
        void ServerThread();
        void DoServerThread();

        NODISCARD static constexpr int GetAcceptTime() noexcept
        {
            return acceptTime;
        }

        NODISCARD static constexpr int GetAsynchronousConnectTime() noexcept
        {
            return asynchronousConnectTime;
        }

        NODISCARD static constexpr int GetSynchronizeConnectTime() noexcept
        {
            return synchronizeConnectTime;
        }

    private:
        // Release版本acceptTime和asynchronousConnectTime值要足够大，否则测试时异步回调还未执行。
        static constexpr auto acceptTime = 100000000;
        static constexpr auto synchronizeConnectTime = 100;
        static constexpr auto asynchronousConnectTime = 100000000;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BOOST_SOCK_CONNECTOR_TESTING_H