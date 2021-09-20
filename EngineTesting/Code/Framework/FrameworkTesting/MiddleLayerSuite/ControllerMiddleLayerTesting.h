// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.1.0 (2020/06/26 23:14)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_CONTROLLER_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_CONTROLLER_MIDDLE_LAYER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class ControllerMiddleLayerTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = ControllerMiddleLayerTesting;
		using ParentType = UnitTest;

	public:
		explicit ControllerMiddleLayerTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void MiddleLayerTest(); 
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_CONTROLLER_MIDDLE_LAYER_TESTING_H