// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.1.0 (2020/06/27 22:41)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MODEL_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MODEL_MIDDLE_LAYER_TESTING_H

#include "CameraMiddleLayerTesting.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class CameraModelMiddleLayerTesting : public CameraMiddleLayerTesting
	{
	public:
		using ClassType = CameraModelMiddleLayerTesting;
		using ParentType = CameraMiddleLayerTesting;

	public:
		explicit CameraModelMiddleLayerTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE; 

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void MiddleLayerTest();
		void FrameRateTest();
		void CameraMotionSpeedTest();
		void CameraMotionMoveTest();		
		void MoveObjectTest(); 
		void TrackBallDownTest();
		void RotateTrackBallTest(); 
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_MODEL_MIDDLE_LAYER_TESTING_H