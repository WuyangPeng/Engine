// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:22)

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

        // ≤‚ ‘∏®÷˙∫Ø ˝
        void Increment() noexcept;
        void IntSleepIncrement(IOContextType& ioContext, std::atomic_int& count);
        void Int16SleepIncrement(IOContextType& ioContext, std::atomic_int16_t& count);

        void DoRunUnitTest() override;

    private:
        std::atomic_int m_IntCount;
        std::atomic_int16_t m_Int16Count;
        std::condition_variable m_ConditionVariable;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_MAIN_MANAGER_USE_THREADS_TESTING_H