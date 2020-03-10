// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:25)

#include "Framework/FrameworkExport.h"

#include "AndroidMessageLoop.h"
#include "System/Android/AndroidInputKeyEvent.h"
#include "System/Android/AndroidLooper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Helper/ConfigMacro.h"

Framework::AndroidMessageLoop
	::AndroidMessageLoop(AndroidApp* state,DisplayPtr function)
	:m_State(state),
	 m_Function(function),
	 m_LastTime()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,AndroidMessageLoop)


void Framework::AndroidMessageLoop
	::EnterMessageLoop()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	for(;;)
	{
		int events = 0;
		struct System::AndroidPollSource* source = nullptr;

		while (System::AndroidLooperEvent(0) <= System::AndroidLooperPollAll(0, nullptr,
			                                    &events,
												reinterpret_cast<void**>(&source)))
		{
			if (source != nullptr)
				source->process(m_State, source);
		}		

		if(m_Function != nullptr)
		{
			int64_t timeDelta = m_LastTime.GetThisElapsedTime();

			m_Function(m_State,timeDelta);			
		}

		if (m_State->GetDestroyRequested() != 0)
			break;
	}
}

