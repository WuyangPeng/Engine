// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.1.0 (2020/06/28 21:41)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_VIEW_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_VIEW_MIDDLE_LAYER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CameraMiddleLayerTesting.h"

namespace Framework
{
	class CameraViewMiddleLayerTesting final : public CameraMiddleLayerTesting
	{
	public:
		using ClassType = CameraViewMiddleLayerTesting;
		using ParentType = CameraMiddleLayerTesting;

	public:
		explicit CameraViewMiddleLayerTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void MiddleLayerTest();
		void DrawFrameRateTest();
		void TrackTest();		
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_CAMERA_VIEW_MIDDLE_LAYER_TESTING_H