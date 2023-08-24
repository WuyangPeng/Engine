///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 15:29)

#include "Framework/FrameworkExport.h"

#include "WindowFontInformation.h"
#include "System/Windows/WindowsFontInformation.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowFontInformation::WindowFontInformation(WindowsHWnd hWnd) noexcept
    : hWnd{ hWnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowFontInformation::IsValid() const noexcept
{
    if (ParentType::IsValid() && hWnd != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Framework::WindowFontInformation::GetStringWidth(const String& text) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return System::GetStringWidth(hWnd, text);
}

int Framework::WindowFontInformation::GetCharacterWidth(const TChar character) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return System::GetCharacterWidth(hWnd, character);
}

int Framework::WindowFontInformation::GetFontHeight() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return System::GetFontHeight(hWnd);
}
