// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/14 0:57)

#ifndef FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_WINDOW_APPLICATION_INFORMATION_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_WINDOW_APPLICATION_INFORMATION_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowApplicationInformationTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowApplicationInformationTesting;
		using ParentType = UnitTest;
		using HInstance = System::WindowsHInstance;

	public:
		explicit WindowApplicationInformationTesting(const OStreamShared& stream, HInstance instance);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void InformationTest();
		void AllowResizeTest();
		void NotAllowedResizeTest();
		void RendererParameterTest();

	private:
		HInstance m_Instance;
	};
}

#endif // FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_WINDOW_APPLICATION_INFORMATION_TESTING_H