///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/15 10:48)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_CLIENT_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_CLIENT_TESTING_H

#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class ClientTesting : public SingletonTesting
    {
    public:
        using ClassType = ClientTesting;
        using ParentType = SingletonTesting;

    public:
        explicit ClientTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void ACETest();
        void BoostTest();
        void NetworkTest();
        void NullTest();

        void ACEConstructionTest();
        void BoostConstructionTest();
        void NetworkConstructionTest();
        void NullConstructionTest();
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_CLIENT_TESTING_H