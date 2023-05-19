///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 10:24)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_TESTING_H

#include "System/Helper/Platform.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

#include <atomic>
#include <condition_variable>

namespace Network
{
    class BoostMainManagerUseMultiContextTesting final : public SingletonTesting
    {
    public:
        using ClassType = BoostMainManagerUseMultiContextTesting;
        using ParentType = SingletonTesting;

    public:
        explicit BoostMainManagerUseMultiContextTesting(const OStreamShared& stream);

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
        std::atomic_int count;
        std::condition_variable conditionVariable;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_TESTING_H