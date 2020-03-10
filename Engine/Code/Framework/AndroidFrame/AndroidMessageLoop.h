// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:24)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_MESSAGE_LOOP_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_MESSAGE_LOOP_H

#include "Framework/FrameworkDll.h"

#include "System/Android/AndroidNativeAppGlue.h"
#include "CoreTools/Time/CustomTime.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE AndroidMessageLoop
	{
	public:
		typedef AndroidMessageLoop ClassType;
		typedef System::AndroidApp AndroidApp;
		typedef void (*DisplayPtr)(AndroidApp* state ,int64_t timeDelta);

	public:
		AndroidMessageLoop(AndroidApp* state,
			               DisplayPtr function);

		CLASS_INVARIANT_DECLARE;

		void EnterMessageLoop();

	private:
		AndroidApp* m_State;
		DisplayPtr m_Function;
		CoreTools::CustomTime m_LastTime;
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_MESSAGE_LOOP_H
