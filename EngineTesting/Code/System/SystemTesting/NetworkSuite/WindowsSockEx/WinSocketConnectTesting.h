/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:06)

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