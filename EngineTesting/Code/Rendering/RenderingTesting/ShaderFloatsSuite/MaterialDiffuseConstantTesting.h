// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/06 15:11)

#ifndef RENDERING_SHADER_FLOATS_SUITE_MATERIAL_DIFFUSE_CONSTANT_TESTING_H
#define RENDERING_SHADER_FLOATS_SUITE_MATERIAL_DIFFUSE_CONSTANT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class MaterialDiffuseConstantTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MaterialDiffuseConstantTesting); 

	private:
		void MainTest();
	    void InitTest();
	    void CopyTest();	  
	    void StreamTest();
		void UpdateTest();

		void DoRunUnitTest() override; 
	};
}

#endif // RENDERING_SHADER_FLOATS_SUITE_MATERIAL_DIFFUSE_CONSTANT_TESTING_H