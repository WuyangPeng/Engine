// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:02)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_TESTING_H

#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class ObjectTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ObjectTesting);

	private:
		void MainTest();
		 

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_TESTING_H