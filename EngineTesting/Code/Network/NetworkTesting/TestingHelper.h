///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 16:35)

#ifndef NETWORK_TESTING_TESTING_HELPER_H
#define NETWORK_TESTING_TESTING_HELPER_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace Network
{
    class TestingHelper : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;

    public:
        TestingHelper(int argc, char** argv);
        ~TestingHelper() noexcept;
        TestingHelper(const TestingHelper& rhs) = delete;
        TestingHelper& operator=(const TestingHelper& rhs) = delete;
        TestingHelper(TestingHelper&& rhs) noexcept = delete;
        TestingHelper& operator=(TestingHelper&& rhs) noexcept = delete;

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddHelperSuite();
        void AddConfigurationSuite();
        void AddNetworkMessageSuite();
        void AddInterfaceSuite();
        void AddACEWrappersSuite();
        void AddBoostWrappersSuite();
        void AddNetworkWrappersSuite();
        void AddSocketWrappersSuite();
        void AddOpensslSuite();
        void AddMessageOrientedMiddlewareSuite();
        void AddActiveMQSuite();
        void AddNatsSuite();

        NODISCARD CoreTools::Suite GetBoostSockAcceptorSuite();
        NODISCARD CoreTools::Suite GetBoostSockConnectorSuite();
        NODISCARD CoreTools::Suite GetBoostSockStreamSuite();

        void CreateSingleton();
        void DestroySingleton();
    };
}

#endif  // NETWORK_TESTING_TESTING_HELPER_H