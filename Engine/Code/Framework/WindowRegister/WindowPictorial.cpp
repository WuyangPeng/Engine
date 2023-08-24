///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/03 19:31)

#include "Framework/FrameworkExport.h"

#include "WindowPictorial.h"
#include "Detail/WindowPictorialImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowRegister/WindowHBrush.h"

Framework::WindowPictorial::WindowPictorial(BrushTypes background)
    : impl{ background }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorial::WindowPictorial(const TChar* icon, const TChar* cursor, BrushTypes background)
    : impl{ icon, cursor, background }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorial::WindowPictorial(HInstance instance, int icon, int cursor, BrushTypes background)
    : impl{ instance, icon, cursor, background }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorial::WindowPictorial(HInstance instance, int icon, const TChar* cursor, BrushTypes background)
    : impl{ instance, icon, cursor, background }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorial::WindowPictorial(HInstance instance, const TChar* icon, int cursor, BrushTypes background)
    : impl{ instance, icon, cursor, background }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorial::WindowPictorial(HInstance instance, bool isDefaultIcon, int icon, bool isDefaultCursor, int cursor, BrushTypes background)
    : impl{ instance, isDefaultIcon, icon, isDefaultCursor, cursor, background }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowPictorial)

System::WindowsHIcon Framework::WindowPictorial::GetHIcon() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetHIcon();
}

System::WindowsHCursor Framework::WindowPictorial::GetHCursor() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetHCursor();
}

System::WindowsHBrush Framework::WindowPictorial::GetHBrush() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetHBrush();
}
