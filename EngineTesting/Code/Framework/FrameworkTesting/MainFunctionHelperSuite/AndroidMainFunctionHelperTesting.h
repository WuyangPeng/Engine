// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.3.0.2 (2020/06/02 14:26)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_ANDROID_MAIN_FUNCTION_HELPER_TESTING_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_ANDROID_MAIN_FUNCTION_HELPER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class AndroidMainFunctionHelperTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = AndroidMainFunctionHelperTesting;
		using ParentType = UnitTest;

	public:
		explicit AndroidMainFunctionHelperTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void AndroidMainFunctionHelper1Test();
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_ANDROID_MAIN_FUNCTION_HELPER_TESTING_H