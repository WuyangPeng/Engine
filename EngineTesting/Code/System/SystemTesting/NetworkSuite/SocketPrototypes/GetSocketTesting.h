///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/05 15:11)

#ifndef SYSTEM_SECURITY_SUITE_GET_SOCKET_TESTING_H
#define SYSTEM_SECURITY_SUITE_GET_SOCKET_TESTING_H

#include "System/Network/Fwd/NetworkFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class GetSocketTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetSocketTesting;
        using ParentType = UnitTest;

    public:
        explicit GetSocketTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void GetSocketTest();

        void Init();
        void Cleanup();

    private:
        using ProtocolFamiliesFlagsCollection = std::vector<ProtocolFamilies>;
        using SocketTypesFlagsCollection = std::vector<SocketTypes>;
        using SocketProtocolsFlagsCollection = std::vector<SocketProtocols>;

    private:
        ProtocolFamiliesFlagsCollection protocolFamiliesFlags;
        SocketTypesFlagsCollection socketTypesFlags;
        SocketProtocolsFlagsCollection socketProtocolsFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_GET_SOCKET_TESTING_H