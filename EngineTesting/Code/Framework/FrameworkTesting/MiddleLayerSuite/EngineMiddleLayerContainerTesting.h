// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/16 09:23)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_ENGINE_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_ENGINE_MIDDLE_LAYER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class EngineMiddleLayerContainerTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = EngineMiddleLayerContainerTesting;
		using ParentType = UnitTest;

	public:
		explicit EngineMiddleLayerContainerTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void MainTest();
		void DefaultEngineMiddleLayerTest();
		void EngineMiddleLayerTest();
		void SetMiddleLayerTest();

		void DoRunUnitTest() final;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_ENGINE_MIDDLE_LAYER_TESTING_H