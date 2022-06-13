///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/23 15:38)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_INIT_VALUE_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_INIT_VALUE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class MultipleMessageInitValueTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MultipleMessageInitValueTesting);

	private:
		void MainTest();

		void BaseTest();

		void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MULTIPLE_MESSAGE_INIT_VALUE_TESTING_H