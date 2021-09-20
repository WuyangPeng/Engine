// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/23 22:55)

#ifndef FRAMEWORK_TESTING_TESTING_HELPER_H
#define FRAMEWORK_TESTING_TESTING_HELPER_H 

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace Framework
{
	class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		using ClassType = TestingHelper;
		using ParentType = CMainFunctionTestingHelper;

	public:
		TestingHelper(int argc, char** argv);
		~TestingHelper() noexcept;
		TestingHelper(const TestingHelper& rhs) = delete;
		TestingHelper& operator=(const TestingHelper& rhs) = delete;
		TestingHelper(TestingHelper&& rhs) noexcept = delete;
		TestingHelper& operator=(TestingHelper&& rhs) noexcept = delete;

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void InitSuite();

		void AddHelperSuite();
		void AddMainFunctionHelperSuite();
		void AddWindowCreateSuite();
		void AddWindowProcessSuite();
		void AddWindowRegisterSuite();
		void AddApplicationSuite();
		void AddMiddleLayerSuite();
		void AddWindowsAPIFrameSuite();
		void AddOpenGLGlutFrameSuite();
		void AddAndroidFrameSuite();
		void AddLinuxFrameSuite();
		void AddMacintoshFrameSuite();
		void AddConsoleFrameSuite();
	};
}

#endif // FRAMEWORK_TESTING_TESTING_HELPER_H
