// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.1 (2019/08/30 22:56)

#ifndef BOOK_NETWORK_PROGRAMMING_TESTING_HELPER_H
#define BOOK_NETWORK_PROGRAMMING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace CoreTools
{
    class Suite;
}

namespace BookNetworkProgramming
{
    class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;
        using Suite = CoreTools::Suite;

    public:
        TestingHelper(int argc, char** argv);

    private:


        void InitSuite();

        void AddNetworkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite();

        void AddMultiplayerGameProgrammingSuite();

        void AddNetworkProgrammingForMicrosoftWindowsSuite();

        void AddEffectiveTCPIPProgrammingSuite();

        void AddInternetworkingWithTCPIPSuite();

        void AddInternetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite(Suite& internetworkingWithTCPIPSuite);

        void AddInternetworkingWithTCPIPDesignImplementationAndInternalsSuite(Suite& internetworkingWithTCPIPSuite);

        void AddInternetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite(Suite& internetworkingWithTCPIPSuite);

        void AddUNIXNetworkProgrammingSuite();

        void AddUNIXNetworkProgrammingTheSocketsNetworkingAPISuite(Suite& unixNetworkProgrammingSuite);

        void AddUNIXNetworkProgrammingInterprocessCommunicationSuite(Suite& unixNetworkProgrammingSuite);

        void AddConfiguringWindowsServer2008NetworkInfrastructureSuite();

        void AddAdvancedCORBAProgrammingWithCppSuite();
    };
}

#endif  // BOOK_NETWORK_PROGRAMMING_TESTING_HELPER_H