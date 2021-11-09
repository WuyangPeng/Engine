///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.3 (2021/09/23 21:46)

#ifndef BOOK_NETWORK_PROGRAMMING_TESTING_HELPER_H
#define BOOK_NETWORK_PROGRAMMING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

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

        void AddComputerNetworksSuite();

        void AddInternetworkingWithTCPIPSuite();

        NODISCARD Suite GetPrinciplesProtocolsAndArchitecturesSuite();

        NODISCARD Suite GetDesignImplementationAndInternalsSuite();

        NODISCARD Suite GetClientServerProgrammingAndApplicationsSuite();

        void AddUNIXNetworkProgrammingSuite();

        NODISCARD Suite GetUNIXNetworkProgrammingTheSocketsNetworkingAPISuite();

        NODISCARD Suite GetUNIXNetworkProgrammingInterprocessCommunicationSuite();

        void AddConfiguringWindowsServer2008NetworkInfrastructureSuite();

        void AddAdvancedCORBAProgrammingWithCppSuite();

        void AddComputerNetworksASystemApproachSuite();

        void AddComputerNetworksATopDownApproachSuite();

        void AddTCPIPProtocolSuite();

        void AddCryptographyAndNetworkSecuritySuite();
    };
}

#endif  // BOOK_NETWORK_PROGRAMMING_TESTING_HELPER_H