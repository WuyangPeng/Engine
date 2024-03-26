/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:06)

#ifndef SYSTEM_NETWORK_SUITE_NETWORK_TESTING_BASE_H
#define SYSTEM_NETWORK_SUITE_NETWORK_TESTING_BASE_H

#include "System/Network/Using/SocketPrototypesUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class NetworkTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = NetworkTestingBase;
        using ParentType = UnitTest;

    public:
        explicit NetworkTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void WinSockStartUpTest();
        void WinSockCleanupTest();

        void CreateTcpClientProcessTest();
        void CreateUdpClientProcessTest();

        void CloseSocketTest(WinSocket socketHandle);

        NODISCARD uint16_t GetTcpPort() const;
        NODISCARD uint16_t GetUdpPort() const;
        NODISCARD std::string GetAddress() const;
        NODISCARD WinSockInternetAddress GetAddress(uint16_t port) const noexcept;
        NODISCARD WinSockInternetAddress GetAddress(uint16_t port, const std::string& hostname) const noexcept;
    };
}

#endif  // SYSTEM_NETWORK_SUITE_NETWORK_TESTING_BASE_H