// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/07 16:59)

#ifndef RENDERING_CURVES_SURFACES_SUITE_PRINCIPAL_CURVATURE_INFO_TESTING_H
#define RENDERING_CURVES_SURFACES_SUITE_PRINCIPAL_CURVATURE_INFO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class PrincipalCurvatureInfoTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PrincipalCurvatureInfoTesting); 

	private:
		void MainTest();
	    void InitTest();	     

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_CURVES_SURFACES_SUITE_PRINCIPAL_CURVATURE_INFO_TESTING_H