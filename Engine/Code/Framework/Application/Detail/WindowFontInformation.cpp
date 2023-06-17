///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:49)

#include "Framework/FrameworkExport.h"

#include "WindowFontInformation.h"
#include "System/Windows/WindowsFontInformation.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowFontInformation::WindowFontInformation(WindowsHWnd hwnd) noexcept
    : hwnd{ hwnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowFontInformation::IsValid() const noexcept
{
    if (ParentType::IsValid() && hwnd != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Framework::WindowFontInformation::GetStringWidth(const String& text) const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return System::GetStringWidth(hwnd, text);
}

int Framework::WindowFontInformation::GetCharacterWidth(const TChar character) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return System::GetCharacterWidth(hwnd, character);
}

int Framework::WindowFontInformation::GetFontHeight() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return System::GetFontHeight(hwnd);
}
