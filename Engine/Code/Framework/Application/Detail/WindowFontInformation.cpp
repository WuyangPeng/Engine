// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:56)

#include "Framework/FrameworkExport.h"

#include "WindowFontInformation.h"
#include "System/Window/WindowFontInformation.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowFontInformation
	::WindowFontInformation(HWnd hwnd) noexcept
	:m_Hwnd{ hwnd }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowFontInformation
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_Hwnd != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int Framework::WindowFontInformation
	::GetStringWidth(const String& text) const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return System::GetStringWidth(m_Hwnd, text);
}

int Framework::WindowFontInformation
	::GetCharacterWidth(const TChar character) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return System::GetCharacterWidth(m_Hwnd, character);
}

int Framework::WindowFontInformation
	::GetFontHeight() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return System::GetFontHeight(m_Hwnd);
}

