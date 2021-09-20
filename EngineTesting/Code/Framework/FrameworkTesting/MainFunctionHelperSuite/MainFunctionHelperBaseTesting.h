// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.3.0.1 (2020/05/29 12:40)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_MAIN_FUNCTION_HELPER_BASE_TESTING_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_MAIN_FUNCTION_HELPER_BASE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class MainFunctionHelperBaseTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = MainFunctionHelperBaseTesting;
		using ParentType = UnitTest;

	public:
		explicit MainFunctionHelperBaseTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void MainFunctionHelperBase1Test();
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_SUITE_MAIN_FUNCTION_HELPER_BASE_TESTING_H