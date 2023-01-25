///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/12 14:09)

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