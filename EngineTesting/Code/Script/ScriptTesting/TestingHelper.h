// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.5 (2020/03/17 11:14)

#ifndef SCRIPT_TESTING_TESTING_HELPER_H
#define SCRIPT_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h" 

namespace Script
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper);

		virtual int DoRun() override;

	private:
                void AddSuites();

		void AddHelperSuite();
		void AddConfigurationSuite();
		void AddInterfaceSuite();
		void AddJavaSuite();
		void AddLuaSuite();
		void AddPerlSuite();
		void AddPythonSuite();
		void AddTCREScriptSuite();

	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // SCRIPT_TESTING_TESTING_HELPER_H