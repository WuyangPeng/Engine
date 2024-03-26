/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:03)

#ifndef SYSTEM_NETWORK_SUITE_WIN_SOCK_SERVER_ENT_TESTING_H
#define SYSTEM_NETWORK_SUITE_WIN_SOCK_SERVER_ENT_TESTING_H

#include "System/Network/Using/DatabasePrototypesUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WinSockServerEntTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WinSockServerEntTesting;
        using ParentType = UnitTest;

    public:
        explicit WinSockServerEntTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetServerEntTest();

        void WinSockServerEntTest(const WinSockServerEnt* winSockServEnt);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WIN_SOCK_SERVER_ENT_TESTING_H