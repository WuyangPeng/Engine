///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:02)

#include "Framework/FrameworkExport.h"

#include "WindowPictorial.h"
#include "Detail/WindowPictorialImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Framework/WindowRegister/WindowHBrush.h"

Framework::WindowPictorial::WindowPictorial(WindowsBrushTypes background)
    : impl{ background }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowPictorial::WindowPictorial(const TChar* icon, const TChar* cursor, WindowsBrushTypes background)
    : impl{ icon, cursor, background }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowPictorial::WindowPictorial(HInstance instance, int icon, int cursor, WindowsBrushTypes background)
    : impl{ instance, icon, cursor, background }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowPictorial::WindowPictorial(HInstance instance, int icon, const TChar* cursor, WindowsBrushTypes background)
    : impl{ instance, icon, cursor, background }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowPictorial::WindowPictorial(HInstance instance, const TChar* icon, int cursor, WindowsBrushTypes background)
    : impl{ instance, icon, cursor, background }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowPictorial::WindowPictorial(HInstance instance, bool isDefaultIcon, int icon, bool isDefaultCursor, int cursor, WindowsBrushTypes background)
    : impl{ instance, isDefaultIcon, icon, isDefaultCursor, cursor, background }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowPictorial)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowPictorial, GetHIcon, System::WindowsHIcon)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowPictorial, GetHCursor, System::WindowsHCursor)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowPictorial, GetHBrush, System::WindowsHBrush)
