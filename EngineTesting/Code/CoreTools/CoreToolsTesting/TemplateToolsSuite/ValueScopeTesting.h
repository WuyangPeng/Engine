// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 15:37)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_VALUE_SCOPE_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_VALUE_SCOPE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class ValueScopeTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ValueScopeTesting);

	private:
		void MainTest();
		void CastTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_VALUE_SCOPE_TESTING_H


