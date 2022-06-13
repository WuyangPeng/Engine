///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 0:48)

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
        void DoRunUnitTest() final;
        void MainTest();

        void FdTest();
        void FdSetTest(WinSocket winSocket);

        void StartUp();
        void Cleanup();
        NODISCARD WinSocket CreateWinSocket();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_NETWORK_MACRO_TESTING_H
