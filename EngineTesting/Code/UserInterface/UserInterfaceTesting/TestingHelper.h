// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/09 20:17)

#ifndef USER_INTERFACE_TESTING_TESTING_HELPER_H
#define USER_INTERFACE_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace UserInterface
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 
	
		virtual int DoRun() override;			

	private:
                void AddSuites();	

		void AddMacroSuite(); 
		void AddConfigurationSuite();
		void AddInterfaceSuite();
		void AddWxWidgetsSuite();
		void AddFLTKSuite();
		void AddTrixulSuite();
		void AddXFree86Suite();

	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // USER_INTERFACE_TESTING_TESTING_HELPER_H