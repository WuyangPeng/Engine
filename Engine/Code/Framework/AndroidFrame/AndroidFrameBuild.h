// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:24)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_H

#include "AndroidMessageLoop.h"
#include "System/Android/AndroidNativeAppGlue.h"

namespace Framework
{
	template <typename AndroidProcess>
	class AndroidFrameBuild
	{
	public:
		typedef AndroidFrameBuild<AndroidProcess> ClassType;
		typedef System::AndroidApp AndroidApp;

	public:
		explicit AndroidFrameBuild(AndroidApp* state);
		virtual ~AndroidFrameBuild();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void EnterMessageLoop();

		AndroidApp* GetAndroidApp();

	private:
		bool InitApplication();

	private:
		AndroidApp* m_State;
		AndroidProcess m_AndroidProcess;
		AndroidMessageLoop m_AndroidMessageLoop;
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_H
