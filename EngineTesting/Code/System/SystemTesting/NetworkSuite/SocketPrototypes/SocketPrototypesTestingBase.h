///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/09 21:30)

#ifndef SYSTEM_NETWORK_SUITE_SOCKET_PROTOTYPES_TESTING_BASE_H
#define SYSTEM_NETWORK_SUITE_SOCKET_PROTOTYPES_TESTING_BASE_H

#include "System/Network/Using/SocketPrototypesUsing.h"
#include "System/SystemTesting/NetworkSuite/NetworkTestingBase.h"

namespace System
{
    class SocketPrototypesTestingBase : public NetworkTestingBase
    {
    public:
        using ClassType = SocketPrototypesTestingBase;
        using ParentType = NetworkTestingBase;

    public:
        explicit SocketPrototypesTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto defaultHttpPort = 80;

    protected:
        NODISCARD std::string GetConnectHostname() const;
    };
}

#endif  // SYSTEM_NETWORK_SUITE_SOCKET_PROTOTYPES_TESTING_BASE_H