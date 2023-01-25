///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/11 23:54)

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