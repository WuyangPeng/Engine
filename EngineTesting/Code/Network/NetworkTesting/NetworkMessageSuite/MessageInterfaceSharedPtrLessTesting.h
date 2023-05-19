///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/12 10:03)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_INTERFACE_SHARED_PTR_LESS_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_INTERFACE_SHARED_PTR_LESS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class MessageInterfaceSharedPtrLessTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageInterfaceSharedPtrLessTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageInterfaceSharedPtrLessTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void LessTest();
        void DoubleMessageTest();
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_INTERFACE_SHARED_PTR_LESS_TESTING_H