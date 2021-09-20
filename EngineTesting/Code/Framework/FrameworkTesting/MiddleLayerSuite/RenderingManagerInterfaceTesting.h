// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/16 09:24)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_RENDERING_MANAGER_INTERFACE_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_RENDERING_MANAGER_INTERFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class RenderingManagerInterfaceTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = RenderingManagerInterfaceTesting;
		using ParentType = UnitTest;

	public:
		explicit RenderingManagerInterfaceTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void MainTest();	
		void MiddleLayerTest();
		void SetMiddleLayerTest();

		void SetNetworkManagerExceptionTest();
		void SetInputManagerExceptionTest();
		void SetObjectLogicManagerExceptionTest();
		void SetPhysicalModellingManagerExceptionTest();
		void SetMessageManagerExceptionTest();
		void SetEventManagerExceptionTest();
		void SetSystemManagerTest();
		void SetResourceManagerExceptionTest();
		void SetAudioManagerExceptionTest();
		void SetCameraSystemsManagerExceptionTest();
		void SetRenderingManagerExceptionTest();
		void SetGUIManagerExceptionTest();

		void DoRunUnitTest() final;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_RENDERING_MANAGER_INTERFACE_TESTING_H