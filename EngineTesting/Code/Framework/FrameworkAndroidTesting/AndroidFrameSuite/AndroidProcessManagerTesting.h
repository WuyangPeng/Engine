// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 20:17)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_MANAGE_TESTING_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_MANAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace System
{
    class AndroidApp;
}

namespace Framework
{
	class AndroidProcessManagerTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = AndroidProcessManagerTesting;
		using ParentType = UnitTest;
		using AndroidApp = System::AndroidApp;

	public:
		explicit AndroidProcessManagerTesting(AndroidApp* androidApp, const OStreamShared& osPtr );
		virtual ~AndroidProcessManagerTesting();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		void MainTest();
		void AndroidCallBackPtrTest();
		void CallbackSucceedTest();	

		void DoRunUnitTest() final;

	private:
		AndroidApp* m_AndroidApp;	
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_MANAGE_TESTING_H