// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/16 09:23)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_ENGINE_MIDDLE_LAYER_INTERFACE_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_ENGINE_MIDDLE_LAYER_INTERFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class EngineMiddleLayerInterfaceTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = EngineMiddleLayerInterfaceTesting;
		using ParentType = UnitTest;

	public:
		explicit EngineMiddleLayerInterfaceTesting(const OStreamShared& stream);

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
		void SetSystemManagerExceptionTest();
		void SetResourceManagerExceptionTest();
		void SetAudioManagerExceptionTest();
		void SetCameraSystemsManagerExceptionTest();
		void SetRenderingManagerExceptionTest();
		void SetGUIManagerExceptionTest();

		void DoRunUnitTest() final;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_ENGINE_MIDDLE_LAYER_INTERFACE_TESTING_H