// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.4 (2020/03/12 11:55)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_RECEIVE_MESSAGE_LEVEL_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_RECEIVE_MESSAGE_LEVEL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class ReceiveMessageLevelTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ReceiveMessageLevelTesting);

	private:
		void MainTest();

		void ReceiveMessageTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_RECEIVE_MESSAGE_LEVEL_TESTING_H