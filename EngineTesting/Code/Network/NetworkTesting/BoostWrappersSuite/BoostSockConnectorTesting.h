///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 10:35)

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
        // Release�汾acceptTime��asynchronousConnectTimeֵҪ�㹻�󣬷������ʱ�첽�ص���δִ�С�
        static constexpr auto acceptTime = 100000000;
        static constexpr auto synchronizeConnectTime = 100;
        static constexpr auto asynchronousConnectTime = 100000000;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BOOST_SOCK_CONNECTOR_TESTING_H