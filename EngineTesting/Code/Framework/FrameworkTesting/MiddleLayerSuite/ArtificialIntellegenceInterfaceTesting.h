// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/16 09:22)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_ARTIFICIAL_INTELLEGENCE_INTERFACE_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_ARTIFICIAL_INTELLEGENCE_INTERFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class ArtificialIntellegenceInterfaceTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = ArtificialIntellegenceInterfaceTesting;
		using ParentType = UnitTest;

	public:
		explicit ArtificialIntellegenceInterfaceTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();	
		void MiddleLayerTest();
		void SetMiddleLayerTest();

		void SetNetworkManagerTest();
		void SetInputManagerTest();
		void SetObjectLogicManagerExceptionTest();
		void SetPhysicalModellingManagerTest();
		void SetMessageManagerTest();
		void SetEventManagerExceptionTest();
		void SetSystemManagerTest();
		void SetResourceManagerExceptionTest();
		void SetAudioManagerExceptionTest();
		void SetCameraSystemsManagerExceptionTest();
		void SetRenderingManagerExceptionTest();
		void SetGUIManagerExceptionTest();

	 
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_ARTIFICIAL_INTELLEGENCE_INTERFACE_TESTING_H