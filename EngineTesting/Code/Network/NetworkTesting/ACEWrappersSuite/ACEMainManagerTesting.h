///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:58)

#ifndef NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_MAIN_MANAGER_TESTING_H
#define NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_MAIN_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class ACEMainManagerTesting final : public SingletonTesting
    {
    public:
        using ClassType = ACEMainManagerTesting;
        using ParentType = SingletonTesting;

        using TestFunction = void (ClassType::*)();

    public:
        explicit ACEMainManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void SingletonTest();
        void RunTest();
    };
}

#endif  // NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_MAIN_MANAGER_TESTING_H