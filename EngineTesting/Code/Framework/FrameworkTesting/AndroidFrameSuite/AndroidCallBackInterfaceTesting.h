// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/12 19:10)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_INTERFACE_TESTING_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_INTERFACE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class AndroidCallBackInterfaceTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = AndroidCallBackInterfaceTesting;
		using ParentType = UnitTest;

	public:
		explicit AndroidCallBackInterfaceTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;
		void MainTest();
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_INTERFACE_TESTING_H