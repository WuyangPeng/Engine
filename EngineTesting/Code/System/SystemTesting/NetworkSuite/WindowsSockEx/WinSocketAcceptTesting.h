/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:05)

#ifndef SYSTEM_NETWORK_SUITE_WIN_SOCKET_ACCEPT_TESTING_H
#define SYSTEM_NETWORK_SUITE_WIN_SOCKET_ACCEPT_TESTING_H

#include "WindowsSockExTestingBase.h"
#include "System/Network/Using/WindowsSockExUsing.h"

namespace System
{
    class WinSocketAcceptTesting final : public WindowsSockExTestingBase
    {
    public:
        using ClassType = WinSocketAcceptTesting;
        using ParentType = WindowsSockExTestingBase;

    public:
        explicit WinSocketAcceptTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AcceptTest();

        void DoAcceptTest(WinSocket socketHandle);
        void RecvTest(WinSocket acceptHandle);
        NODISCARD WinSockInternetAddress AcceptInit(WinSocket socketHandle);
        NODISCARD int DoRecvTest(CharBufferType& buffer, int index, int remain, WinSocket acceptHandle, WindowsDWord& numberOfBytesRecvD);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WIN_SOCKET_ACCEPT_TESTING_H