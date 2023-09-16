///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 10:31)

#ifndef SYSTEM_NETWORK_SUITE_SOCK_OPTION_TESTING_H
#define SYSTEM_NETWORK_SUITE_SOCK_OPTION_TESTING_H

#include "SocketPrototypesTestingBase.h"
#include "System/Network/Fwd/NetworkFlagsFwd.h"

namespace System
{
    class SockOptionTesting final : public SocketPrototypesTestingBase
    {
    public:
        using ClassType = SockOptionTesting;
        using ParentType = SocketPrototypesTestingBase;

    public:
        explicit SockOptionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SockOptionTest();

        template <SocketLevelOption LevelOption, SocketRetrievedOption RetrievedOption, typename Option>
        void SetAndGetSockOptionTest();

        template <SocketLevelOption LevelOption, SocketRetrievedOption RetrievedOption, typename Option>
        void GetSockOptionTest();

        template <SocketLevelOption LevelOption, SocketRetrievedOption RetrievedOption, typename Option>
        void DoSetAndGetSockOptionTest(WinSocket socketHandle);

        template <SocketLevelOption LevelOption, SocketRetrievedOption RetrievedOption, typename Option>
        void DoGetSockOptionTest(WinSocket socketHandle);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_SOCK_OPTION_TESTING_H