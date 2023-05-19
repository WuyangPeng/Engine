///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 10:16)

#ifndef NETWORK_TESTING_ACE_WRAPPERS_SUITE_SOCK_ACE_HANDLE_SET_ITERATOR_TESTING_H
#define NETWORK_TESTING_ACE_WRAPPERS_SUITE_SOCK_ACE_HANDLE_SET_ITERATOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class SockACEHandleSetIteratorTesting final : public SingletonTesting
    {
    public:
        using ClassType = SockACEHandleSetIteratorTesting;
        using ParentType = SingletonTesting;

    public:
        explicit SockACEHandleSetIteratorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();

        void HandleSetTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_ACE_WRAPPERS_SUITE_SOCK_ACE_HANDLE_SET_ITERATOR_TESTING_H