// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.3 (2019/09/06 15:10)

#ifndef RENDERING_SHADER_FLOATS_SUITE_CAMERA_WORLD_DIRECTION_VECTOR_CONSTANT_TESTING_H
#define RENDERING_SHADER_FLOATS_SUITE_CAMERA_WORLD_DIRECTION_VECTOR_CONSTANT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class CameraWorldDirectionVectorConstantTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CameraWorldDirectionVectorConstantTesting); 

	private:
		void MainTest();
	    void InitTest();
	    void CopyTest();	  
	    void StreamTest();
		void UpdateTest();

		void DoRunUnitTest() override; 
	};
}

#endif // RENDERING_SHADER_FLOATS_SUITE_CAMERA_WORLD_DIRECTION_VECTOR_CONSTANT_TESTING_H