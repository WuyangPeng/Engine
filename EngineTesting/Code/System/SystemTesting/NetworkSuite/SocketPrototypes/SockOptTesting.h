///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/14 16:40)

#ifndef SYSTEM_SECURITY_SUITE_SOCK_OPT_TESTING_H
#define SYSTEM_SECURITY_SUITE_SOCK_OPT_TESTING_H

#include "System/Network/Fwd/NetworkFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SockOptTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SockOptTesting;
        using ParentType = UnitTest;

    public:
        explicit SockOptTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SockOptTest();

        template <SocketLevelOption LevelOption, SocketRetrievedOption RetrievedOption, typename Option>
        void SetAndGetSockOptTest();

        template <SocketLevelOption LevelOption, SocketRetrievedOption RetrievedOption, typename Option>
        void GetSockOptTest();

        void Init();
        void Cleanup();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SOCK_OPT_TESTING_H