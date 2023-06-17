///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:02)

#include "Rendering/RenderingExport.h"

#include "WindowsParameter.h"
#include "Detail/WindowsParameterImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::WindowsParameter Rendering::WindowsParameter::Create()
{
    return WindowsParameter{ DisableNotThrow::Disable };
}

Rendering::WindowsParameter::WindowsParameter(DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, WindowsParameter)

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, WindowsParameter)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, WindowsParameter, GetClearColor, Rendering::WindowsParameter::ColourType);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, WindowsParameter, GetWindowTitle, std::string);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, WindowsParameter, GetXPosition, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, WindowsParameter, GetYPosition, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, WindowsParameter, IsAllowResize, bool);

void Rendering::WindowsParameter::SetClearColor(float red, float green, float blue, float alpha)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetClearColor(red, green, blue, alpha);
}

void Rendering::WindowsParameter::SetWindowParameter(const std::string& windowTitle, int x, int y, bool allowResize)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetWindowParameter(windowTitle, x, y, allowResize);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, WindowsParameter, GetWindowMenuName, System::String);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, WindowsParameter, SetWindowClassName, String, void);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, WindowsParameter, GetWindowClassName, System::String);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, WindowsParameter, SetWindowMenuName, String, void);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, WindowsParameter, GetIcon, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, WindowsParameter, IsIconDefault, bool);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, WindowsParameter, GetCursor, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, WindowsParameter, IsCursorDefault, bool);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, WindowsParameter, GetBackground, System::WindowsBrushTypes);

void Rendering::WindowsParameter::SetWindowPictorialParameter(int icon, bool isIconDefault, int cursor, bool isCursorDefault, WindowsBrushTypes background)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetWindowPictorialParameter(icon, isIconDefault, cursor, isCursorDefault, background);
}