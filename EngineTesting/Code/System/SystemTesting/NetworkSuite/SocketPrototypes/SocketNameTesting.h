///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/11 18:11)

#ifndef SYSTEM_NETWORK_SUITE_SOCKET_NAME_TESTING_H
#define SYSTEM_NETWORK_SUITE_SOCKET_NAME_TESTING_H

#include "SocketPrototypesTestingBase.h"

namespace System
{
    class SocketNameTesting final : public SocketPrototypesTestingBase
    {
    public:
        using ClassType = SocketNameTesting;
        using ParentType = SocketPrototypesTestingBase;

    public:
        explicit SocketNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SocketNameTest();

        void DoSocketNameTest(WinSocket socketHandle);
        void InetNtoaTest(const WinSockInternetAddress& peerName);
        void WinSockInternetAddressTest(const WinSockInternetAddress& address, const WinSockInternetAddress& peerName);

        NODISCARD WinSockInternetAddress GetPeerNameTest(WinSocket socketHandle);
        NODISCARD void GetSockNameTest(WinSocket socketHandle);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_SOCKET_NAME_TESTING_H