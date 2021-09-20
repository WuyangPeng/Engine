// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:59)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_CALLBACK_PARAMETERS_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_CALLBACK_PARAMETERS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class CallbackParametersTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CallbackParametersTesting);

	private:
		void MainTest();
		void BuiltInTest();
		void ParametersInterfaceTest();
		void InvalidParametersTest();
		void InvalidTypeTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_CLASS_INVARIANT_SUITE_CALLBACK_PARAMETERS_TESTING_H