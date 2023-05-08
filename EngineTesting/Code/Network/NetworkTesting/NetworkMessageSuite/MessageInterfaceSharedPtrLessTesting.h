///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 18:58)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_INTERFACE_SHARED_PTR_LESS_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_INTERFACE_SHARED_PTR_LESS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class MessageInterfaceSharedPtrLessTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageInterfaceSharedPtrLessTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageInterfaceSharedPtrLessTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void LessTest();
        void DoubleMessageTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_INTERFACE_SHARED_PTR_LESS_TESTING_H