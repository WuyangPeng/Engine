///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 10:27)

#ifndef SYSTEM_NETWORK_SUITE_ACCEPT_TESTING_H
#define SYSTEM_NETWORK_SUITE_ACCEPT_TESTING_H

#include "SocketPrototypesTestingBase.h"

namespace System
{
    class AcceptTesting final : public SocketPrototypesTestingBase
    {
    public:
        using ClassType = AcceptTesting;
        using ParentType = SocketPrototypesTestingBase;

    public:
        explicit AcceptTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AcceptTest();

        NODISCARD WinSockInternetAddress AcceptInit(WinSocket socketHandle);
        void DoAcceptTest(WinSocket socketHandle);
        void RecvTest(WinSocket acceptHandle);
        NODISCARD int DoRecvTest(WinSocket acceptHandle, int index, int remain, BufferType& buffer);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_ACCEPT_TESTING_H