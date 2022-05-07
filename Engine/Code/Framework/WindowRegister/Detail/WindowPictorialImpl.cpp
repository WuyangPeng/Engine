///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 17:20)

#include "Framework/FrameworkExport.h"

#include "WindowPictorialImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowRegister/WindowHBrush.h"

using std::make_unique;

Framework::WindowPictorialImpl::WindowPictorialImpl(WindowsBrushTypes background)
    : windowsHIcon{}, windowsHCursor{}, windowsHBrush{ CreateWindowsHBrush(background) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorialImpl::WindowPictorialImpl(const TChar* icon, const TChar* cursor, WindowsBrushTypes background)
    : windowsHIcon{ icon }, windowsHCursor{ cursor }, windowsHBrush{ CreateWindowsHBrush(background) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorialImpl::WindowPictorialImpl(HInstance instance, int icon, int cursor, WindowsBrushTypes background)
    : windowsHIcon{ instance, icon }, windowsHCursor{ instance, cursor }, windowsHBrush{ CreateWindowsHBrush(background) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorialImpl::WindowPictorialImpl(HInstance instance, int icon, const TChar* cursor, WindowsBrushTypes background)
    : windowsHIcon{ instance, icon }, windowsHCursor{ cursor }, windowsHBrush{ CreateWindowsHBrush(background) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorialImpl::WindowPictorialImpl(HInstance instance, const TChar* icon, int cursor, WindowsBrushTypes background)
    : windowsHIcon{ icon }, windowsHCursor{ instance, cursor }, windowsHBrush{ CreateWindowsHBrush(background) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorialImpl::WindowPictorialImpl(HInstance instance, bool isDefaultIcon, int icon, bool isDefaultCursor, int cursor, WindowsBrushTypes background)
    : windowsHIcon{ WindowHIcon::Create(instance, isDefaultIcon, icon) },
      windowsHCursor{ WindowHCursor::Create(instance, isDefaultCursor, cursor) },
      windowsHBrush{ CreateWindowsHBrush(background) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// static
Framework::WindowPictorialImpl::WindowHBrushUniquePtr Framework::WindowPictorialImpl::CreateWindowsHBrush(WindowsBrushTypes background)
{
    if (background != WindowsBrushTypes::Null)
        return make_unique<WindowHBrush>(background);
    else
        return nullptr;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowPictorialImpl)

System::WindowsHIcon Framework::WindowPictorialImpl::GetHIcon() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return windowsHIcon.GetHIcon();
}

System::WindowsHCursor Framework::WindowPictorialImpl::GetHCursor() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return windowsHCursor.GetHCursor();
}

System::WindowsHBrush Framework::WindowPictorialImpl::GetHBrush() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (windowsHBrush != nullptr)
        return windowsHBrush->GetHBrush();
    else
        return nullptr;
}
