///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/15 10:54)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SERVER_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SERVER_TESTING_H

#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class ServerTesting : public SingletonTesting
    {
    public:
        using ClassType = ServerTesting;
        using ParentType = SingletonTesting;

    public:
        explicit ServerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void ACETest();
        void BoostTest();
        void NetworkTest();

        void ACEConstructionTest();
        void BoostConstructionTest();
        void NetworkConstructionTest();
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SERVER_TESTING_H