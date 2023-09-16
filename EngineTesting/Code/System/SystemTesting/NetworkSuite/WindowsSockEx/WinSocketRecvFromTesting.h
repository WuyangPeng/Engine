///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 10:33)

#ifndef SYSTEM_NETWORK_SUITE_WIN_SOCKET_RECV_FROM_TESTING_H
#define SYSTEM_NETWORK_SUITE_WIN_SOCKET_RECV_FROM_TESTING_H

#include "WindowsSockExTestingBase.h"
#include "System/Network/Using/SocketPrototypesUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    class WinSocketRecvFromTesting final : public WindowsSockExTestingBase
    {
    public:
        using ClassType = WinSocketRecvFromTesting;
        using ParentType = WindowsSockExTestingBase;

    public:
        explicit WinSocketRecvFromTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RecvFromTest();

        void DoRecvFromTest(WinSocket socketHandle);
        NODISCARD int WinSocketRecvFromTest(BufferType& buffer, int index, int remain, WinSockInternetAddress address, WinSocket socketHandle, WindowsDWord& numberOfBytesRecvd);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WIN_SOCKET_RECV_FROM_TESTING_H