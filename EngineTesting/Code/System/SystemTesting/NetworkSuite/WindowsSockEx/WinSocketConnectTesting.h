///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 10:33)

#ifndef SYSTEM_NETWORK_SUITE_WIN_SOCKET_CONNECT_TESTING_H
#define SYSTEM_NETWORK_SUITE_WIN_SOCKET_CONNECT_TESTING_H

#include "WinSocketConnectByNameTesting.h"

namespace System
{
    class WinSocketConnectTesting final : public WinSocketConnectByNameTesting
    {
    public:
        using ClassType = WinSocketConnectTesting;
        using ParentType = WinSocketConnectByNameTesting;

    public:
        explicit WinSocketConnectTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoConnectTest(WinSocket socketHandle) override;
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WIN_SOCKET_CONNECT_TESTING_H