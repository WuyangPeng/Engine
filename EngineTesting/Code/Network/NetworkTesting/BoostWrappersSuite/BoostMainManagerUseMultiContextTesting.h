// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:22)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_TESTING_H
#include "System/Helper/Platform.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

#include <atomic>
#include <condition_variable>

namespace Network
{
    class BoostMainManagerUseMultiContextTesting : public SingletonTesting
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

        // ≤‚ ‘∏®÷˙∫Ø ˝
        void Increment() noexcept;
        void DecrementToZero(IOContextType& ioContext);

        void DoRunUnitTest() override;

    private:
        std::atomic_int m_Count;
        std::condition_variable m_ConditionVariable;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_TESTING_H