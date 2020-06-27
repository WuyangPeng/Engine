// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:40)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_MESSAGE_LOOP_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_MESSAGE_LOOP_H

#include "Framework/FrameworkDll.h"

#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "CoreTools/Time/CustomTime.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE AndroidMessageLoop
	{
	public:
		using ClassType = AndroidMessageLoop;
		using AndroidApp = System::AndroidApp;
		using DisplayFunction = void(*)(AndroidApp* androidApp, int64_t timeDelta);
		using CustomTime = CoreTools::CustomTime;

	public:
		AndroidMessageLoop(AndroidApp* androidApp, DisplayFunction function) noexcept;

		CLASS_INVARIANT_DECLARE;

		void EnterMessageLoop() noexcept;

	private:
		AndroidApp* m_State;
		DisplayFunction m_Function;
		CustomTime m_LastTime;
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_MESSAGE_LOOP_H
