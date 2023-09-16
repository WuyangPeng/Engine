///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:47)

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

        // 测试辅助函数
        void Increment() noexcept;
        void DecrementToZero(IoContextType& ioContext);

        void DoRunUnitTest() override;

    private:
        int count;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_BASE_MAIN_MANAGER_TESTING_H