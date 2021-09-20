// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.1.0 (2020/06/26 17:56)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class ModelViewControllerMiddleLayerTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = ModelViewControllerMiddleLayerTesting;
		using ParentType = UnitTest;

	public:
		explicit ModelViewControllerMiddleLayerTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void MiddleLayerTest();
		void SetMiddleLayerTest();		
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_TESTING_H