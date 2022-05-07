// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/07 14:10)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_HICON_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_HICON_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

#include <map>

namespace Framework
{
	class WindowHIconTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowHIconTesting;
		using ParentType = UnitTest;
		using TChar = System::TChar;
		using HInstance = System::WindowsHInstance;

	public:
		explicit WindowHIconTesting(const OStreamShared& stream, HInstance instance);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void ConstructorTest();
		void CreateTest();

	private:
		using HIconContainer = std::map<int, const TChar*>;

	private:
		HInstance m_Instance;
		HIconContainer m_Container;
	};
}

#endif // FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_HICON_TESTING_H