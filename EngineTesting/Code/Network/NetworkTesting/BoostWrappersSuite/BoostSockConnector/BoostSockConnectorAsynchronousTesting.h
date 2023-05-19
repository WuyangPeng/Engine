///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 14:07)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_CONNECTOR_ASYNCHRONOUS_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_CONNECTOR_ASYNCHRONOUS_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockConnectorTesting.h"

namespace Network
{
    class BoostSockConnectorAsynchronousTesting final : public BoostSockConnectorTesting
    {
    public:
        using ClassType = BoostSockConnectorAsynchronousTesting;
        using ParentType = BoostSockConnectorTesting;

    public:
        explicit BoostSockConnectorAsynchronousTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void DoRunUnitTest() override;

        void MainTest() noexcept;

        void ConnectorTest();

        void AsynchronousConnectorTest();
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_CONNECTOR_ASYNCHRONOUS_TESTING_H