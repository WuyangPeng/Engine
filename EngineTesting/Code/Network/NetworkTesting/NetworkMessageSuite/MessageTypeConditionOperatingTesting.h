// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.4 (2020/03/12 11:51)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TYPE_CONDITION_OPERATING_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TYPE_CONDITION_OPERATING_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class MessageTypeConditionOperatingTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MessageTypeConditionOperatingTesting);

	private:
		void MainTest();

		void OperatingTest();

		void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_TYPE_CONDITION_OPERATING_TESTING_H