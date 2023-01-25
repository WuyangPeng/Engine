///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/11 23:54)

#ifndef SYSTEM_NETWORK_SUITE_WIN_SOCKET_CONNECT_BY_NAME_TESTING_H
#define SYSTEM_NETWORK_SUITE_WIN_SOCKET_CONNECT_BY_NAME_TESTING_H

#include "WindowsSockExTestingBase.h"

namespace System
{
    class WinSocketConnectByNameTesting : public WindowsSockExTestingBase
    {
    public:
        using ClassType = WinSocketConnectByNameTesting;
        using ParentType = WindowsSockExTestingBase;

    public:
        explicit WinSocketConnectByNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        virtual void DoConnectTest(WinSocket socketHandle);
        void RecvTest(WinSocket socketHandle);
        void SendTest(WinSocket socketHandle);

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ConnectTest();
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WIN_SOCKET_CONNECT_BY_NAME_TESTING_H