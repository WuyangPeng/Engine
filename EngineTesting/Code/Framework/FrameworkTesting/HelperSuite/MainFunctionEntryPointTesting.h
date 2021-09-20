// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.1 (2020/05/26 09:48)

#ifndef FRAMEWORK_HELPER_SUITE_MAIN_FUNCTION_ENTRY_POINT_TESTING_H
#define FRAMEWORK_HELPER_SUITE_MAIN_FUNCTION_ENTRY_POINT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class MainFunctionEntryPointTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = MainFunctionEntryPointTesting;
		using ParentType = UnitTest;		

	public:
		explicit MainFunctionEntryPointTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;	 

	private:
		void DoRunUnitTest() final;

		void MainTest();		

		void WinMainEntryPoint1Test();
		void WinMainEntryPoint2Test();
		void MainEntryPoint1Test();
		void GlutMainEntryPoint1Test();
		void AndroidMainEntryPoint1Test();
	};
}

#endif // FRAMEWORK_HELPER_SUITE_MAIN_FUNCTION_ENTRY_POINT_TESTING_H