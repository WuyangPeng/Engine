// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 18:59)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_SLOT_MANAGER_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_SLOT_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class EventSlotManagerTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(EventSlotManagerTesting);

	private:
		void MainTest();
		void SuccessTest();
		void UnregisteredExceptionTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_CLASS_INVARIANT_SUITE_EVENT_SLOT_MANAGER_TESTING_H