///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/11 17:58)

#ifndef SYSTEM_NETWORK_SUITE_SHUT_DOWN_TESTING_H
#define SYSTEM_NETWORK_SUITE_SHUT_DOWN_TESTING_H

#include "SocketPrototypesTestingBase.h"
#include "System/Network/Fwd/NetworkFlagsFwd.h"

namespace System
{
    class ShutDownTesting final : public SocketPrototypesTestingBase
    {
    public:
        using ClassType = ShutDownTesting;
        using ParentType = SocketPrototypesTestingBase;

    public:
        explicit ShutDownTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ShutDownTest(ShutdownHow shutdownHow);

        void DoShutDownTest(WinSocket socketHandle, ShutdownHow shutdownHow);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_SHUT_DOWN_TESTING_H