// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 13:46)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_LINK_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_LINK_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

namespace CoreTools
{ 
	class ObjectLinkTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ObjectLinkTesting);

	private:
		void MainTest();
            void InsertObjectPtrTest() noexcept; 

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_LINK_TESTING_H