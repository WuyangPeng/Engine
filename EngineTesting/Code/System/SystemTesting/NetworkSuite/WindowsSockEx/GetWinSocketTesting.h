///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:40)

#ifndef SYSTEM_SECURITY_SUITE_GET_WINSOCKET_SOCKET_TESTING_H
#define SYSTEM_SECURITY_SUITE_GET_WINSOCKET_SOCKET_TESTING_H

#include "System/Network/Fwd/NetworkFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class GetWinSocketTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetWinSocketTesting;
        using ParentType = UnitTest;

    public:
        explicit GetWinSocketTesting(const OStreamShared& stream);

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

#endif  // SYSTEM_SECURITY_SUITE_GET_WINSOCKET_SOCKET_TESTING_H