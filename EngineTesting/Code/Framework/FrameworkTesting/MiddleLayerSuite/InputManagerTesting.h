// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/16 09:23)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_INPUT_MANAGER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_INPUT_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class InputManagerTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = InputManagerTesting;
		using ParentType = UnitTest;

	public:
		explicit InputManagerTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void MainTest();	
		void MiddleLayerTest();
		void SetMiddleLayerTest();

		void SetNetworkManagerTest();
		void SetInputManagerExceptionTest();
		void SetObjectLogicManagerTest();
		void SetPhysicalModellingManagerExceptionTest();
		void SetMessageManagerExceptionTest();
		void SetEventManagerExceptionTest();
		void SetSystemManagerTest();
		void SetResourceManagerExceptionTest();
		void SetAudioManagerExceptionTest();
		void SetCameraSystemsManagerTest();
		void SetRenderingManagerExceptionTest();
		void SetGUIManagerExceptionTest();

		void DoRunUnitTest() final;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_INPUT_MANAGER_TESTING_H