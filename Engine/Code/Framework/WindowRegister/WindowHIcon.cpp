// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:46)

#include "Framework/FrameworkExport.h"

#include "WindowHIcon.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Window/WindowRegister.h"

Framework::WindowHIcon
	::WindowHIcon(const System::TChar* icon)
	:m_HIcon(System::LoadSystemIcon(nullptr,icon))
{
	CheckUpHIcon();

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowHIcon
	::WindowHIcon(HInstance hInstance,int icon)
	:m_HIcon(System::LoadSystemIcon(hInstance,MAKEINTRESOURCE(icon)))
{
	CheckUpHIcon();

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// private
void Framework::WindowHIcon
	::CheckUpHIcon()
{
	if(m_HIcon == nullptr)
	{
		m_HIcon = System::LoadSystemIcon(nullptr, IDI_APPLICATION);
		LOG_SINGLETON_ENGINE_APPENDER(Warn, Framework)
			<< SYSTEM_TEXT("º”‘ÿÕº±Í ß∞‹£°")
			<< CoreTools::LogAppenderIOManageSign::TriggerAssert
			<< CoreTools::LogAppenderIOManageSign::Refresh;
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowHIcon
	::IsValid() const noexcept
{
	if(m_HIcon != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

System::WindowHIcon Framework::WindowHIcon
	::GetHIcon() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_HIcon;
}


