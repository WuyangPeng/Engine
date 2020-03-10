// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:20)

#include "Framework/FrameworkExport.h"

#include "WindowFontInformation.h"
#include "System/Window/WindowFontInformation.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowFontInformation
	::WindowFontInformation(HWnd hwnd)
	:m_Hwnd(hwnd)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowFontInformation
	::~WindowFontInformation()
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowFontInformation
    ::IsValid() const noexcept
{
    if(ParentType::IsValid() && m_Hwnd != nullptr)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

int Framework::WindowFontInformation
    ::GetStringWidth( const System::String& text ) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return System::GetStringWidth(m_Hwnd,text);
}

int Framework::WindowFontInformation
	::GetCharacterWidth( const TCHAR character ) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return System::GetCharacterWidth(m_Hwnd,character);
}

int Framework::WindowFontInformation
	::GetFontHeight() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return System::GetFontHeight(m_Hwnd);
}

