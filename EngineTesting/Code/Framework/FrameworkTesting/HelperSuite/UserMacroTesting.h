// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.1 (2020/05/24 12:56)

#ifndef FRAMEWORK_HELPER_SUITE_USER_MACRO_TESTING_H
#define FRAMEWORK_HELPER_SUITE_USER_MACRO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class UserMacroTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = UserMacroTesting;
		using ParentType = UnitTest;		

	public:
		explicit UserMacroTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;	 

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void MacroExistTest();
		void AndroidTestMacroValidTest();
	};
}

#endif // FRAMEWORK_HELPER_SUITE_USER_MACRO_TESTING_H