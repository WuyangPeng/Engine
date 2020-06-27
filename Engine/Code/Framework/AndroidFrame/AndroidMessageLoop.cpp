// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:42)

#include "Framework/FrameworkExport.h"

#include "AndroidMessageLoop.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Android/AndroidLooper.h"
#include "System/Android/AndroidInputKeyEvent.h" 
#include "System/Android/Flags/AndroidLooperFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::AndroidMessageLoop
	::AndroidMessageLoop(AndroidApp* androidApp, DisplayFunction function) noexcept
	:m_State{ androidApp }, m_Function{ function }, m_LastTime{ }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, AndroidMessageLoop)

void Framework::AndroidMessageLoop
	::EnterMessageLoop() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	for (;;)
	{
		auto events = 0;
		System::AndroidPollSource* source{ nullptr };

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26490)  
		while (System::AndroidLooperEvent::Null <= System::AndroidLooperPollAll(0, nullptr, &events, reinterpret_cast<void**>(&source)))
	#include STSTEM_WARNING_POP
		{
			if (source != nullptr)
			{
				source->process(m_State, source);
			}
		}

		if (m_Function != nullptr)
		{
			const auto timeDelta = m_LastTime.GetThisElapsedTime();

			m_Function(m_State, timeDelta);
		}

		if (m_State->GetDestroyRequested() != 0)
		{
			break;
		}			
	}
}

