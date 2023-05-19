///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/11 09:26)

#ifndef NETWORK_TESTING_TESTING_HELPER_H
#define NETWORK_TESTING_TESTING_HELPER_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace Network
{
    class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
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
        void AddOpensslSuite();
        void AddMessageOrientedMiddlewareSuite();
        void AddActiveMQSuite();
        void AddNatsSuite();
        void AddKafkaSuite();

        NODISCARD CoreTools::Suite GetBoostSockAcceptorSuite();
        NODISCARD CoreTools::Suite GetBoostSockConnectorSuite();
        NODISCARD CoreTools::Suite GetBoostSockStreamSuite();

        void CreateSingleton();
        void ReleaseSingleton();
    };
}

#endif  // NETWORK_TESTING_TESTING_HELPER_H