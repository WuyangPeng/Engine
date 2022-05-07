// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/27 13:45)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BANDED_MATRIX_INVERT_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BANDED_MATRIX_INVERT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class BandedMatrixInvertTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BandedMatrixInvertTesting); 

	private:
		void MainTest();   
		void BandedTest();
	 
		void DoRunUnitTest() override;	 
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BANDED_MATRIX_INVERT_TESTING_H