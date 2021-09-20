// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/16 09:24)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_SYSTEM_MANAGER_INTERFACE_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_SYSTEM_MANAGER_INTERFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class SystemManagerInterfaceTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = SystemManagerInterfaceTesting;
		using ParentType = UnitTest;

	public:
		explicit SystemManagerInterfaceTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void MainTest();	
		void MiddleLayerTest();
		void SetMiddleLayerTest();

		void SetNetworkManagerExceptionTest();
		void SetInputManagerTest();
		void SetObjectLogicManagerTest();
		void SetPhysicalModellingManagerExceptionTest();
		void SetMessageManagerTest();
		void SetEventManagerTest();
		void SetSystemManagerExceptionTest();
		void SetResourceManagerTest();
		void SetAudioManagerTest();
		void SetCameraSystemsManagerTest();
		void SetRenderingManagerTest();
		void SetGUIManagerExceptionTest();
		void SetEngineManagerTest();

		void DoRunUnitTest() final;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_SYSTEM_MANAGER_INTERFACE_TESTING_H