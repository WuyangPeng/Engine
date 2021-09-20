// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/24 21:42)

#ifndef FRAMEWORK_APPLICATION_SUITE_CAMERA_MOTION_TESTING_H
#define FRAMEWORK_APPLICATION_SUITE_CAMERA_MOTION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Rendering/SceneGraph/Camera.h" 

namespace Framework
{
	class CameraMotionTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = CameraMotionTesting;
		using ParentType = UnitTest;
		using CameraSmartPointer = Rendering::CameraSharedPtr;

	public:
		explicit CameraMotionTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void BaseTest();
		void SpeedTest();
		void MoveTest();		

		void AssertCamera(const CameraSmartPointer& lhs, const CameraSmartPointer& rhs);
	};
}

#endif // FRAMEWORK_APPLICATION_SUITE_CAMERA_MOTION_TESTING_H
