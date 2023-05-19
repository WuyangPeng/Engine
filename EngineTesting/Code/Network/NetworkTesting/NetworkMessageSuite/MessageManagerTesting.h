///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/12 10:39)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_MANAGER_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class MessageManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void FullVersionTest();
        void ManagerTest();
        void ExceptionTest();
        void DescribeTest();
        void DescribeExceptionTest();
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_MANAGER_TESTING_H