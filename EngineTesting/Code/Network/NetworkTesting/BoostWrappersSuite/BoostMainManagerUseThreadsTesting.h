///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 16:30)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_MAIN_MANAGER_USE_THREADS_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_MAIN_MANAGER_USE_THREADS_TESTING_H

#include "System/Helper/Platform.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

#include <atomic>
#include <condition_variable>

namespace Network
{
    class BoostMainManagerUseThreadsTesting : public SingletonTesting
    {
    public:
        using ClassType = BoostMainManagerUseThreadsTesting;
        using ParentType = SingletonTesting;

    public:
        explicit BoostMainManagerUseThreadsTesting(const OStreamShared& stream);
        CLASS_INVARIANT_OVERRIDE_DECLARE;
        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();

        void SingletonTest();
        void IncrementTest();
        void SleepIncrementTest();

        // 测试辅助函数
        void Increment() noexcept;
        void IntSleepIncrement(IOContextType& ioContext, std::atomic_int& count);
        void Int16SleepIncrement(IOContextType& ioContext, std::atomic_int16_t& count);

        void DoRunUnitTest() override;

    private:
        std::atomic_int intCount;
        std::atomic_int16_t int16Count;
        std::condition_variable conditionVariable;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_MAIN_MANAGER_USE_THREADS_TESTING_H