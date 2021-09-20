// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/09 21:43)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_PICTORIAL_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_PICTORIAL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "System/Window/Using/WindowUsing.h"

#include <map>
#include <random> 

namespace Framework
{
	class WindowPictorialTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowPictorialTesting;
		using ParentType = UnitTest;
		using TChar = System::TChar;
		using HInstance = System::WindowHInstance;

	public:
		explicit WindowPictorialTesting(const OStreamShared& stream, HInstance instance);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		using IconContainer = std::vector<std::pair<int, const TChar*>>;
		using CursorContainer = std::vector<std::pair<int, const TChar*>>;
		using BrushContainer = std::vector<System::WindowBrushTypes>;
		using IconContainerConstIter = IconContainer::const_iterator;
		using CursorContainerConstIter = CursorContainer::const_iterator;
		using BrushContainerConstIter = BrushContainer::const_iterator;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void BrushTest();
		void RandomTest(); 	

		void RandomContainer(std::default_random_engine& generator);

		void RandomIconTest();
		void RandomCursorTest();
		void RandomBrushTest();
		void RandomIconAndCursorTest();

		void DefaultIconTest();
		void DefaultCursorTest();
		void DefaultIconAndCursorTest();
		void CustomIconAndCursorTest();

		void NextIcon(std::default_random_engine& generator);
		void NextCursor(std::default_random_engine& generator);
		void NextBrush(std::default_random_engine& generator);

	private:
		HInstance m_Instance;
		IconContainer m_IconContainer;
		CursorContainer m_CursorContainer;
		BrushContainer m_BrushContainer;
		IconContainer m_TestIconContainer;
		CursorContainer m_TestCursorContainer;
		BrushContainer m_TestBrushContainer;
		IconContainerConstIter m_IconIter;
		CursorContainerConstIter m_CursorIter;
		BrushContainerConstIter m_BrushIter;
	};
}

#endif // FRAMEWORK_WINDOW_TESTING_WINDOW_REGISTER_SUITE_WINDOW_PICTORIAL_TESTING_H
