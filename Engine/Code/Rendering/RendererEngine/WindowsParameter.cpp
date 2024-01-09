/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/04 09:31)

#include "Rendering/RenderingExport.h"

#include "WindowsParameter.h"
#include "Detail/WindowsParameterImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, WindowsParameter)

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

Rendering::WindowsParameter::ColourType Rendering::WindowsParameter::GetClearColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetClearColor();
}

std::string Rendering::WindowsParameter::GetWindowTitle() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowTitle();
}

int Rendering::WindowsParameter::GetXPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetXPosition();
}

int Rendering::WindowsParameter::GetYPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetYPosition();
}

bool Rendering::WindowsParameter::IsAllowResize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsAllowResize();
}

Rendering::WindowsParameter::String Rendering::WindowsParameter::GetWindowClassName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowClassName();
}

void Rendering::WindowsParameter::SetWindowClassName(const String& className)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetWindowClassName(className);
}

Rendering::WindowsParameter::String Rendering::WindowsParameter::GetWindowMenuName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowMenuName();
}

void Rendering::WindowsParameter::SetWindowMenuName(const String& menuName)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetWindowMenuName(menuName);
}

int Rendering::WindowsParameter::GetIcon() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetIcon();
}

bool Rendering::WindowsParameter::IsIconDefault() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsIconDefault();
}

int Rendering::WindowsParameter::GetCursor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCursor();
}

bool Rendering::WindowsParameter::IsCursorDefault() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->IsCursorDefault();
}

Rendering::WindowsParameter::WindowsBrushTypes Rendering::WindowsParameter::GetBackground() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBackground();
}

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

void Rendering::WindowsParameter::SetWindowPictorialParameter(int icon, bool isIconDefault, int cursor, bool isCursorDefault, WindowsBrushTypes background)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetWindowPictorialParameter(icon, isIconDefault, cursor, isCursorDefault, background);
}