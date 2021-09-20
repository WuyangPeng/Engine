// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.2 (2020/06/07 14:10)

#ifndef FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_HICON_TESTING_H
#define FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_HICON_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class WindowHIconTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowHIconTesting;
		using ParentType = UnitTest;

	public:
		explicit WindowHIconTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_HICON_TESTING_H