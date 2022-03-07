// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/19 16:49)

#ifndef MATHEMATICS_ALGEBRA_SUITE_ALGEBRA_STREAM_SIZE_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_ALGEBRA_STREAM_SIZE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class AlgebraStreamSizeTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AlgebraStreamSizeTesting); 

	private:
		void MainTest();
		void StreamSizeTest();

		void DoRunUnitTest() override;		
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_ALGEBRA_STREAM_SIZE_TESTING_H