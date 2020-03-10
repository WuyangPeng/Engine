// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:46)

#include "Framework/FrameworkExport.h"

#include "WindowHCursor.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Window/WindowRegister.h"

Framework::WindowHCursor
	::WindowHCursor(const System::TChar* cursor)
	:m_HCursor(System::LoadSystemCursor(nullptr,cursor))
{
	CheckUpHCursor();

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowHCursor
	::WindowHCursor(HInstance hInstance,int cursor)
	:m_HCursor(System::LoadSystemCursor(hInstance,MAKEINTRESOURCE(cursor)))
{
	CheckUpHCursor();

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// private
void Framework::WindowHCursor
	::CheckUpHCursor()
{
	if(m_HCursor == nullptr)
	{
		m_HCursor = System::LoadSystemCursor(nullptr,IDC_ARROW);
		LOG_SINGLETON_ENGINE_APPENDER(Warn, Framework)
			<< SYSTEM_TEXT("º”‘ÿπ‚±Í ß∞‹£°")
			<< CoreTools::LogAppenderIOManageSign::TriggerAssert
			<< CoreTools::LogAppenderIOManageSign::Refresh;
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowHCursor
	::IsValid() const noexcept
{
	if(m_HCursor != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

System::WindowHCursor Framework::WindowHCursor
	::GetHCursor() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_HCursor;
}

