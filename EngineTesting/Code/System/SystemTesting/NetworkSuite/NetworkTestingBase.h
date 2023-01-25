///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/07 22:21)

#ifndef SYSTEM_NETWORK_SUITE_NETWORK_TESTING_BASE_H
#define SYSTEM_NETWORK_SUITE_NETWORK_TESTING_BASE_H

#include "System/Network/Using/SocketPrototypesUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <array>

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
        static constexpr auto bufferSize = 256;
        using BufferType = std::array<char, bufferSize>;

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