// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.2 (2020/06/08 21:50)

#ifndef FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_HBRUSH_TESTING_H
#define FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_HBRUSH_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 
#include "System/Window/Fwd/WindowFlagsFwd.h"
#include <vector>

namespace Framework
{
	class WindowHBrushTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowHBrushTesting;
		using ParentType = UnitTest;

	public:
		explicit WindowHBrushTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void BrushTest();

	private:
		using Container = std::vector<System::WindowBrushTypes>;

	private:
		Container m_Container;
	};
}

#endif // FRAMEWORK_WINDOW_REGISTER_SUITE_WINDOW_HBRUSH_TESTING_H