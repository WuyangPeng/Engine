// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 20:15)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_TESTING_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace System
{
    class AndroidApp;
}

namespace Framework
{
	class AndroidCallBackTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = AndroidCallBackTesting;
		using ParentType = UnitTest;
		using AndroidApp = System::AndroidApp;

	public:
		explicit AndroidCallBackTesting(AndroidApp* androidApp, const OStreamShared& osPtr );
		virtual ~AndroidCallBackTesting();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		void MainTest();
		void MessageTest();				

		void DoRunUnitTest() final;	

	private:
		AndroidApp* m_AndroidApp;
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_CALL_BACK_TESTING_H