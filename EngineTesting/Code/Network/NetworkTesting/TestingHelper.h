// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/11 18:53)

#ifndef NETWORK_TESTING_TESTING_HELPER_H
#define NETWORK_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
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

        CoreTools::Suite GetBoostSockAcceptorSuite();
        CoreTools::Suite GetBoostSockConnectorSuite();
        CoreTools::Suite GetBoostSockStreamSuite();

        void CreateSingleton();
        void DestroySingleton();
    };
}

#endif  // NETWORK_TESTING_TESTING_HELPER_H