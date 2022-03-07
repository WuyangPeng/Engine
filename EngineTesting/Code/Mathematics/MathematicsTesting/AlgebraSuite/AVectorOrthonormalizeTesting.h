// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/19 17:04)

#ifndef MATHEMATICS_ALGEBRA_SUITE_AVECTOR_ORTHONORMALIZE_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_AVECTOR_ORTHONORMALIZE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class AVectorOrthonormalizeTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AVectorOrthonormalizeTesting); 

	private:
		void MainTest();
		void OrthonormalizeTest();

		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_AVECTOR_ORTHONORMALIZE_TESTING_H