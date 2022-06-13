///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 13:57)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SERVER_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SERVER_TESTING_H

#include "Network/Interface/NetworkInternalFwd.h"
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

        void ACETest();
        void BoostTest();
        void NetworkTest();

        void ACEConstructionTest();
        void BoostConstructionTest();
        void NetworkConstructionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SERVER_TESTING_H