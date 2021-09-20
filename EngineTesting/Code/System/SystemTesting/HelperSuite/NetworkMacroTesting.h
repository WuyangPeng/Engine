///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/09 16:51)

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
