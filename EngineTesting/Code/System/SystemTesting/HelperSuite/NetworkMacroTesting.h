///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:40)

#ifndef SYSTEM_TESTING_HELPER_SUITE_NETWORK_MACRO_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_NETWORK_MACRO_TESTING_H

#include "System/Network/Using/SocketPrototypesUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class NetworkMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = NetworkMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit NetworkMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FdTest();
        void FdSetTest(WinSocket winSocket);

        void StartUp();
        void Cleanup();
        NODISCARD WinSocket CreateWinSocket();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_NETWORK_MACRO_TESTING_H
