// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.5 (2020/03/16 18:41)

#ifndef DATABASE_TESTING_HELPER_SUITE_USER_MACRO_TESTING_H
#define DATABASE_TESTING_HELPER_SUITE_USER_MACRO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Database
{
	class UserMacroTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(UserMacroTesting);

	private:
		void MainTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // DATABASE_TESTING_HELPER_SUITE_USER_MACRO_TESTING_H