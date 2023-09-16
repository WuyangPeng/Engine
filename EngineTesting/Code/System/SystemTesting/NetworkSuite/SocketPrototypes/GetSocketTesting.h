///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 10:30)

#ifndef SYSTEM_NETWORK_SUITE_GET_SOCKET_TESTING_H
#define SYSTEM_NETWORK_SUITE_GET_SOCKET_TESTING_H

#include "SocketPrototypesTestingBase.h"
#include "System/Network/Fwd/NetworkFlagsFwd.h"

#include <random>
#include <vector>

namespace System
{
    class GetSocketTesting final : public SocketPrototypesTestingBase
    {
    public:
        using ClassType = GetSocketTesting;
        using ParentType = SocketPrototypesTestingBase;

    public:
        explicit GetSocketTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
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

#endif  // SYSTEM_NETWORK_SUITE_GET_SOCKET_TESTING_H