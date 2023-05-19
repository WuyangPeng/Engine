///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 10:26)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_MAIN_MANAGER_USE_THREADS_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_MAIN_MANAGER_USE_THREADS_TESTING_H

#include "System/Helper/Platform.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

#include <atomic>
#include <condition_variable>

namespace Network
{
    class BoostMainManagerUseThreadsTesting final : public SingletonTesting
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

        // ���Ը�������
        void Increment() noexcept;
        void IntSleepIncrement(IoContextType& ioContext, std::atomic_int& count);
        void Int16SleepIncrement(IoContextType& ioContext, std::atomic_int16_t& count);

        void DoRunUnitTest() override;

    private:
        std::atomic_int intCount;
        std::atomic_int16_t int16Count;
        std::condition_variable conditionVariable;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_MAIN_MANAGER_USE_THREADS_TESTING_H