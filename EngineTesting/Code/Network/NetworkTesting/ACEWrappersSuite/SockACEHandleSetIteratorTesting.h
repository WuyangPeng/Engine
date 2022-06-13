///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 14:17)

#ifndef NETWORK_TESTING_ACE_WRAPPERS_SUITE_SOCK_ACE_HANDLE_SET_ITERATOR_TESTING_H
#define NETWORK_TESTING_ACE_WRAPPERS_SUITE_SOCK_ACE_HANDLE_SET_ITERATOR_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class SockACEHandleSetIteratorTesting : public SingletonTesting
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