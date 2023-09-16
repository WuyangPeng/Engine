///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/16 09:55)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_HANDLE_SET_ITERATOR_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_HANDLE_SET_ITERATOR_TESTING_H

#include "SingletonTesting.h"

namespace Network
{
    class HandleSetIteratorTesting final : public SingletonTesting
    {
    public:
        using ClassType = HandleSetIteratorTesting;
        using ParentType = SingletonTesting;

    public:
        explicit HandleSetIteratorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void ACETest();
        void BoostTest();
        void NetworkTest();
        void NullTest();

        void ACEConstructionTest();
        void BoostConstructionTest();
        void NetworkConstructionTest();
        void NullConstructionTest();

        void ACEOperatorTest();
        void BoostOperatorExceptionTest();
        void NetworkOperatorExceptionTest();
        void NullOperatorExceptionTest();
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_HANDLE_SET_ITERATOR_TESTING_H