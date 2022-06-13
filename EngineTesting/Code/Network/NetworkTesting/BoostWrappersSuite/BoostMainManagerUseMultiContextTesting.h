///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 16:26)
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

        // ���Ը�������
        void Increment() noexcept;
        void DecrementToZero(IOContextType& ioContext);

        void DoRunUnitTest() override;

    private:
        std::atomic_int count;
        std::condition_variable conditionVariable;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_TESTING_H