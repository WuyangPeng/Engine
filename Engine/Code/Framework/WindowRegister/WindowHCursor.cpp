// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:34)

#include "Framework/FrameworkExport.h"

#include "WindowHCursor.h"
#include "System/Window/WindowRegister.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowHCursor
	::WindowHCursor(const TChar* cursor) noexcept
	:m_HCursor{ System::LoadSystemCursor(nullptr, cursor) }
{
	CheckUpHCursor();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowHCursor
	::WindowHCursor(HInstance instance, int cursor)
	:m_HCursor{ System::LoadSystemCursor(instance, System::MakeIntreSource(boost::numeric_cast<System::WindowWord>(cursor))) }
{
	CheckUpHCursor();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
void Framework::WindowHCursor
	::CheckUpHCursor() noexcept
{
	if (m_HCursor == nullptr)
	{
		m_HCursor = System::LoadSystemCursor(nullptr, System::g_Arrow);

		LOG_SINGLETON_ENGINE_APPENDER(Warn, Framework)
			<< SYSTEM_TEXT("º”‘ÿπ‚±Í ß∞‹£°")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowHCursor)

System::WindowHCursor Framework::WindowHCursor
	::GetHCursor() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_HCursor;
}

Framework::WindowHCursor Framework::WindowHCursor
	::Create(HInstance instance, bool isDefaultCursor, int cursor)
{
	if (isDefaultCursor)
	{
		if (cursor == 0)
			return WindowHCursor{ };
		else
			return WindowHCursor{ nullptr, cursor };
	}
	else
	{
		return WindowHCursor{ instance,cursor };
	}
}

