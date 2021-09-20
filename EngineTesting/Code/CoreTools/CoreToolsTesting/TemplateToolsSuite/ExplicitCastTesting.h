// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 15:36)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_EXPLICIT_CAST_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_EXPLICIT_CAST_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/TemplateTools/ExplicitCast.h"

#include <string>

namespace CoreTools
{
	class ExplicitCastTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ExplicitCastTesting);

	private:
		void MainTest();
		void CastTest();
		void IntegerTest(int value);
		void StringTest(const std::string& value);
		void PtrTest(const std::string* value);

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_EXPLICIT_CAST_TESTING_H


