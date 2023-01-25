///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/12 14:09)

#ifndef SYSTEM_NETWORK_SUITE_WIN_SOCKET_SEND_TO_TESTING_H
#define SYSTEM_NETWORK_SUITE_WIN_SOCKET_SEND_TO_TESTING_H

#include "WindowsSockExTestingBase.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    class WinSocketSendToTesting final : public WindowsSockExTestingBase
    {
    public:
        using ClassType = WinSocketSendToTesting;
        using ParentType = WindowsSockExTestingBase;

    public:
        explicit WinSocketSendToTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using MessageType = std::vector<char>;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SendToTest();

        void DoSendToTest(WinSocket socketHandle);

        NODISCARD int WinSocketSendToTest(MessageType& iov, uint32_t sendNum, WinSocket socketHandle, WinSockInternetAddress address, WindowsDWord& numberOfBytesSent);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WIN_SOCKET_SEND_TO_TESTING_H