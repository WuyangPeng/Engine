// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/11 18:53)

#ifndef NETWORK_TESTING_TESTING_HELPER_H
#define NETWORK_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace Network
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper);
            ~TestingHelper();
	private:
		void AddSuites();

		void AddHelperSuite();
		void AddConfigurationSuite();
		void AddNetworkMessageSuite();
		void AddInterfaceSuite();
		void AddACEWrappersSuite();
		void AddBoostWrappersSuite();
		void AddNetworkWrappersSuite();
		void AddSocketWrappersSuite();
		void AddOpensslSuite();

		void AddBoostSockAcceptorSuite(Suite& boostWrappersSuite);
		void AddBoostSockConnectorSuite(Suite& boostWrappersSuite);
		void AddBoostSockStreamSuite(Suite& boostWrappersSuite);

		virtual int DoRun() override;

		void CreateSingleton();
		void DestroySingleton();

	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // NETWORK_TESTING_TESTING_HELPER_H