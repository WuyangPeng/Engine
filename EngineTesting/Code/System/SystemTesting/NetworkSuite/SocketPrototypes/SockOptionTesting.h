/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:05)

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