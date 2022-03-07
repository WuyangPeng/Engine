// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.4 (2020/03/13 16:20)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_CONNECTOR_SYNCHRONIZE_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_CONNECTOR_SYNCHRONIZE_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockConnectorTesting.h"

namespace Network
{
    class BoostSockConnectorSynchronizeTesting : public BoostSockConnectorTesting
    {
    public:
        using ClassType = BoostSockConnectorSynchronizeTesting;
        using ParentType = BoostSockConnectorTesting;

    public:
        explicit BoostSockConnectorSynchronizeTesting(const OStreamShared& stream);
        CLASS_INVARIANT_OVERRIDE_DECLARE;
        using TestFunction = void (ClassType::*)();

    private:
        void DoRunUnitTest() override;

        void MainTest() noexcept;

        void ConnectorTest();

        void SynchronizeConnectorTest();
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_CONNECTOR_SYNCHRONIZE_TESTING_H