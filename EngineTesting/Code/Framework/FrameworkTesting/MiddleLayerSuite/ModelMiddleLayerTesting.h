// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.1.0 (2020/06/26 21:30)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_MEDEL_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_MEDEL_MIDDLE_LAYER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class ModelMiddleLayerTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = ModelMiddleLayerTesting;
		using ParentType = UnitTest;

	public:
		explicit ModelMiddleLayerTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void MiddleLayerTest();
		void FrameRateTest();		
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_MEDEL_MIDDLE_LAYER_TESTING_H