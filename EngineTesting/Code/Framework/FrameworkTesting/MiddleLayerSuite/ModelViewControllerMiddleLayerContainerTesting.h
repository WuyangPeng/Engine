// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.1.0 (2020/06/26 18:32)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLELAYER_CONTAINER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLELAYER_CONTAINER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class ModelViewControllerMiddleLayerContainerTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = ModelViewControllerMiddleLayerContainerTesting;
		using ParentType = UnitTest;

	public:
		explicit ModelViewControllerMiddleLayerContainerTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();		

		void MiddleLayerTest();
		void PixelMiddleLayerTest();
		void CameraMiddleLayerTest();	
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLELAYER_CONTAINER_TESTING_H