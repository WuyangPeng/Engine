// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:36)

#include "Framework/FrameworkExport.h"

#include "WindowHIcon.h"
#include "System/Window/WindowRegister.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Helper/WindowsMacro.h"

Framework::WindowHIcon
	::WindowHIcon(const TChar* icon) noexcept
	:m_HIcon{ System::LoadSystemIcon(nullptr, icon) }
{
	CheckUpHIcon();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowHIcon
	::WindowHIcon(HInstance instance, int icon)
	:m_HIcon{ System::LoadSystemIcon(instance, System::MakeIntreSource(boost::numeric_cast<System::WindowWord>(icon))) }
{
	CheckUpHIcon();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
} 

// private
void Framework::WindowHIcon
	::CheckUpHIcon() noexcept
{
	if (m_HIcon == nullptr)
	{
		m_HIcon = System::LoadSystemIcon(nullptr, System::g_Application);

		LOG_SINGLETON_ENGINE_APPENDER(Warn, Framework)
			<< SYSTEM_TEXT("º”‘ÿÕº±Í ß∞‹£°")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowHIcon) 

System::WindowHIcon Framework::WindowHIcon
	::GetHIcon() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_HIcon;
}

Framework::WindowHIcon Framework::WindowHIcon
	::Create(HInstance instance, bool isDefaultIcon, int icon)
{
	if (isDefaultIcon)
	{
		if(icon == 0)
			return WindowHIcon{ };
		else
			return WindowHIcon{ nullptr, icon };
	}
	else
	{
		return WindowHIcon{ instance,icon };
	}
}

