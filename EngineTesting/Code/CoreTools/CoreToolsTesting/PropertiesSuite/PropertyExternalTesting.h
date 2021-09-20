// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:40)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_TESTING_H
#define CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

#include <string>

namespace CoreTools
{
	class PropertyExternalTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PropertyExternalTesting);

	private:
		void MainTest();
		void GetSetTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_PROPERTIES_SUITE_PROPERTY_EXTERNAL_TESTING_H


