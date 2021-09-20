// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 15:37)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_PARAM_TYPE_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_PARAM_TYPE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/TemplateTools/ParamType.h"

namespace CoreTools
{
	class ParamTypeTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ParamTypeTesting);

	private:
		void MainTest();
            void ParamTypeTest(ParamType<int>::type integer, ParamType<std::string>::type characterString) noexcept;

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_PARAM_TYPE_TESTING_H