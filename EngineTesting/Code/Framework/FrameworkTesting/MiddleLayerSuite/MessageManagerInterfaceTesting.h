// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/16 09:23)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_MESSAGE_MANAGER_INTERFACE_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_MESSAGE_MANAGER_INTERFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class MessageManagerInterfaceTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = MessageManagerInterfaceTesting;
		using ParentType = UnitTest;

	public:
		explicit MessageManagerInterfaceTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void MainTest();	
		void MiddleLayerTest();
		void SetMiddleLayerTest();

		void SetNetworkManagerExceptionTest();
		void SetInputManagerExceptionTest();
		void SetObjectLogicManagerTest();
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

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_MESSAGE_MANAGER_INTERFACE_TESTING_H