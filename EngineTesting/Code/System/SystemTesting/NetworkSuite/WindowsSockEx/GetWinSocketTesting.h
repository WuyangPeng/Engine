///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/11 20:24)

#ifndef SYSTEM_NETWORK_SUITE_GET_WINSOCKET_SOCKET_TESTING_H
#define SYSTEM_NETWORK_SUITE_GET_WINSOCKET_SOCKET_TESTING_H

#include "WindowsSockExTestingBase.h"
#include "System/Network/Fwd/NetworkFlagsFwd.h"

#include <random>
#include <vector>

namespace System
{
    class GetWinSocketTesting final : public WindowsSockExTestingBase
    {
    public:
        using ClassType = GetWinSocketTesting;
        using ParentType = WindowsSockExTestingBase;

    public:
        explicit GetWinSocketTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void GetSocketTest();

        void DoGetSocketTest(size_t index);

    private:
        using ProtocolFamiliesContainer = std::vector<ProtocolFamilies>;
        using SocketTypesContainer = std::vector<SocketTypes>;
        using SocketProtocolsContainer = std::vector<SocketProtocols>;

    private:
        ProtocolFamiliesContainer protocolFamilies;
        SocketTypesContainer socketTypes;
        SocketProtocolsContainer socketProtocols;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_NETWORK_SUITE_GET_WINSOCKET_SOCKET_TESTING_H