/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:05)

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
        void DoRunUnitTest() override;
        void MainTest();

        void ShutDownTest(ShutdownHow shutdownHow);

        void DoShutDownTest(WinSocket socketHandle, ShutdownHow shutdownHow);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_SHUT_DOWN_TESTING_H