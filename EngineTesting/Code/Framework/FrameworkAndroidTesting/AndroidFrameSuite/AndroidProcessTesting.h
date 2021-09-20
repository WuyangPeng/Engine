// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 20:25)

#ifndef FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_TESTING_H
#define FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"

namespace Framework
{
	class AndroidProcessAndroidCallBackInterface : public AndroidCallBackInterface
	{
	public:
		using ClassType = AndroidProcessAndroidCallBackInterface;
		using ParentType = AndroidCallBackInterface;

	public:
		explicit AndroidProcessAndroidCallBackInterface(int64_t delta);
		virtual ~AndroidProcessAndroidCallBackInterface();

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};

	class AndroidProcessTesting : public CoreTools::UnitTest
	{
	public:
		using ClassType = AndroidProcessTesting;
		using ParentType = UnitTest;
		using AndroidApp = System::AndroidApp;

	public:
		explicit AndroidProcessTesting(AndroidApp* androidApp, const OStreamShared& osPtr  );
		virtual ~AndroidProcessTesting();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		void MainTest();
		void CallbackSucceedTest();				

		void DoRunUnitTest() final;	

	private:
		AndroidApp* m_AndroidApp;	
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_SUITE_ANDROID_PROCESS_TESTING_H