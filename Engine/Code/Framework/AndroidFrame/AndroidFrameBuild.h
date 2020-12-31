// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:40)

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
		using ClassType = AndroidFrameBuild<AndroidProcess>;
		using AndroidApp = System::AndroidApp;

	public:
		explicit AndroidFrameBuild(AndroidApp* state);
		virtual ~AndroidFrameBuild() = default;
		AndroidFrameBuild(const AndroidFrameBuild& rhs) noexcept = default;
		AndroidFrameBuild& operator=(const AndroidFrameBuild& rhs) noexcept = default;
		AndroidFrameBuild(AndroidFrameBuild&& rhs) noexcept = default;
		AndroidFrameBuild& operator=(AndroidFrameBuild&& rhs) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void EnterMessageLoop();

		AndroidApp* GetAndroidApp() noexcept;

	private:
		bool InitApplication();

	private:
		static constexpr auto sm_Interval = 60;

		AndroidApp* m_State;
		AndroidProcess m_AndroidProcess;
		AndroidMessageLoop m_AndroidMessageLoop;
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_FRAME_BUILD_H
