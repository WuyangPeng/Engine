///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 13:59)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_CONNECTOR_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_CONNECTOR_TESTING_H

#include "SingletonTesting.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class SockConnectorTesting : public SingletonTesting
    {
    public:
        using ClassType = SockConnectorTesting;
        using ParentType = SingletonTesting;

    public:
        explicit SockConnectorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();

        void ACETest();
        void BoostTest();
        void NetworkTest();
        void NullTest();

        void ACEConstructionTest();
        void BoostConstructionTest();
        void NetworkConstructionTest();
        void NullConstructionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_CONNECTOR_TESTING_H