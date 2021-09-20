// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:28)

#include "Framework/FrameworkExport.h"

#include "WindowPictorialImpl.h"
#include "Framework/WindowRegister/WindowHBrush.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_unique;

Framework::WindowPictorialImpl
	::WindowPictorialImpl(WindowBrushTypes background)
	:m_WindowsHIcon{ }, m_WindowsHCursor{ }, m_WindowsHBrush{ CreateWindowsHBrush(background) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorialImpl
	::WindowPictorialImpl(const TChar* icon, const TChar* cursor, WindowBrushTypes background)
	:m_WindowsHIcon{ icon }, m_WindowsHCursor{ cursor }, m_WindowsHBrush{ CreateWindowsHBrush(background) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorialImpl
	::WindowPictorialImpl(HInstance instance, int icon, int cursor, WindowBrushTypes background)
	:m_WindowsHIcon{ instance, icon }, m_WindowsHCursor{ instance, cursor }, m_WindowsHBrush{ CreateWindowsHBrush(background) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorialImpl
	::WindowPictorialImpl(HInstance instance, int icon, const TChar* cursor, WindowBrushTypes background)
	:m_WindowsHIcon{ instance, icon }, m_WindowsHCursor{ cursor }, m_WindowsHBrush{ CreateWindowsHBrush(background) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorialImpl
	::WindowPictorialImpl(HInstance instance, const TChar* icon, int cursor, WindowBrushTypes background)
	:m_WindowsHIcon{ icon }, m_WindowsHCursor{ instance, cursor }, m_WindowsHBrush{ CreateWindowsHBrush(background) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorialImpl
	::WindowPictorialImpl(HInstance instance, bool isDefaultIcon, int icon, bool isDefaultCursor, int cursor, WindowBrushTypes background)
	:m_WindowsHIcon{ WindowHIcon::Create(instance,isDefaultIcon,icon) },
	 m_WindowsHCursor{ WindowHCursor::Create(instance,isDefaultCursor,cursor) },
	 m_WindowsHBrush{ CreateWindowsHBrush(background) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// static
Framework::WindowPictorialImpl::WindowHBrushUniquePtr Framework::WindowPictorialImpl
	::CreateWindowsHBrush(WindowBrushTypes background)
{
	if (background != WindowBrushTypes::Null)
		return make_unique<WindowHBrush>(background);
	else
		return nullptr;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowPictorialImpl)

System::WindowsHIcon Framework::WindowPictorialImpl
	::GetHIcon() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_WindowsHIcon.GetHIcon();
}

System::WindowsHCursor Framework::WindowPictorialImpl
	::GetHCursor() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_WindowsHCursor.GetHCursor();
}

System::WindowsHBrush Framework::WindowPictorialImpl
	::GetHBrush() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	if (m_WindowsHBrush != nullptr)
		return m_WindowsHBrush->GetHBrush();
	else
		return nullptr;
}
 
