// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 19:00)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_PARAMETERS_INTERFACE_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_PARAMETERS_INTERFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class ParametersInterfaceTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ParametersInterfaceTesting);

	private:
		void MainTest();
		void CloneTest();
		void SubclassTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_CLASS_INVARIANT_SUITE_PARAMETERS_INTERFACE_TESTING_H