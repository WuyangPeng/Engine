///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 10:22)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_BASE_MAIN_MANAGER_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_BASE_MAIN_MANAGER_TESTING_H

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class BoostMainManagerTesting final : public SingletonTesting
    {
    public:
        using ClassType = BoostMainManagerTesting;
        using ParentType = SingletonTesting;

    public:
        explicit BoostMainManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();

        void SingletonTest();
        void IncrementTest();
        void DecrementToZeroTest();

        // ���Ը�������
        void Increment() noexcept;
        void DecrementToZero(IoContextType& ioContext);

        void DoRunUnitTest() override;

    private:
        int count;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_BASE_MAIN_MANAGER_TESTING_H