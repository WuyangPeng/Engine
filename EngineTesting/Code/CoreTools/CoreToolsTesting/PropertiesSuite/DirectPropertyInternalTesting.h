// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 18:40)

#ifndef CORE_TOOLS_PROPERTIES_SUITE_DIRECT_PROPERTY_INTERNAL_TESTING_H
#define CORE_TOOLS_PROPERTIES_SUITE_DIRECT_PROPERTY_INTERNAL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

#include <string>

namespace CoreTools
{
	class DirectPropertyInternalTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(DirectPropertyInternalTesting);

	private:
		void MainTest();
		void GetSetTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_PROPERTIES_SUITE_DIRECT_PROPERTY_INTERNAL_TESTING_H

