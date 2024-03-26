/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:06)

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
        void SendTest(WinSocket socketHandle) const;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ConnectTest();
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WIN_SOCKET_CONNECT_BY_NAME_TESTING_H