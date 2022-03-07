// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/19 17:09)

#ifndef MATHEMATICS_ALGEBRA_SUITE_Vector2_ORTHONORMALIZE_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_Vector2_ORTHONORMALIZE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Vector2OrthonormalizeTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Vector2OrthonormalizeTesting); 

	private:
		void MainTest();
		void OrthonormalizeTest();

		void DoRunUnitTest() override;	 
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_Vector2_ORTHONORMALIZE_TESTING_H