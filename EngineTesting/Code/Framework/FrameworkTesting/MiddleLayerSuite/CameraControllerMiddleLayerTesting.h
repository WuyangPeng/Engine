// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.1.0 (2020/06/28 22:25)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_CONTROLLER_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_CONTROLLER_MIDDLE_LAYER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 
#include "CameraMiddleLayerTesting.h"
#include "Framework/MiddleLayer/CameraControllerMiddleLayer.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

namespace Framework
{
	class CameraControllerMiddleLayerTesting final : public CameraMiddleLayerTesting
	{
	public:
		using ClassType = CameraControllerMiddleLayerTesting;
		using ParentType = CameraMiddleLayerTesting;

	public:
		explicit CameraControllerMiddleLayerTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void MiddleLayerTest();
		void KeyDownTest(); 
		void CameraMotionMoveTest();
		void MoveObjectTest();
		void TrackBallDownTest();
		void RotateTrackBallTest();
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_CONTROLLER_MIDDLE_LAYER_TESTING_H