// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/19 17:05)

#ifndef MATHEMATICS_ALGEBRA_SUITE_BANDED_MATRIX_SOLVE_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_BANDED_MATRIX_SOLVE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class BandedMatrixSolveTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BandedMatrixSolveTesting); 

	private:
		void MainTest();		
		void ConstructionTest();
		void SolveTest();

		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_BANDED_MATRIX_SOLVE_TESTING_H