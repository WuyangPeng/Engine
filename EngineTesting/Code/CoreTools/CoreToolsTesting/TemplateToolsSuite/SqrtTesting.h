// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 15:37)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_SQRT_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_SQRT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class SqrtTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SqrtTesting);

	private:
		void MainTest();
		void SqrtTest();
		void IfThenElseTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_SQRT_TESTING_H


