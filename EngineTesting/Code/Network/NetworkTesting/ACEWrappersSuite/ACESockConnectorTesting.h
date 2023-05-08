///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 14:16)

#ifndef NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_CONNECTOR_TESTING_H
#define NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_CONNECTOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class ACESockConnectorTesting : public SingletonTesting
    {
    public:
        using ClassType = ACESockConnectorTesting;
        using ParentType = SingletonTesting;

    public:
        explicit ACESockConnectorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();

        void ConnectorTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_CONNECTOR_TESTING_H