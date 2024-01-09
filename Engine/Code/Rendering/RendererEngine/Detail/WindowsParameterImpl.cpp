/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 16:14)

#include "Rendering/RenderingExport.h"

#include "WindowsParameterImpl.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::WindowsParameterImpl::WindowsParameterImpl() noexcept
    : colour{ 0.0f, 0.0f, 0.0f, 1.0f },
      windowTitle{},
      windowX{ 0 },
      windowY{ 0 },
      isAllowResize{ true },
      className{},
      menuName{},
      icon{ 0 },
      isIconDefault{ false },
      cursor{ 0 },
      isCursorDefault{ false },
      background{ WindowsBrushTypes::Null }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, WindowsParameterImpl)

Rendering::WindowsParameterImpl::ColourType Rendering::WindowsParameterImpl::GetClearColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return colour;
}

std::string Rendering::WindowsParameterImpl::GetWindowTitle() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowTitle;
}

int Rendering::WindowsParameterImpl::GetXPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowX;
}

int Rendering::WindowsParameterImpl::GetYPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowY;
}

bool Rendering::WindowsParameterImpl::IsAllowResize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isAllowResize;
}

void Rendering::WindowsParameterImpl::SetClearColor(float red, float green, float blue, float alpha) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    colour.SetColour(red, green, blue, alpha);
}

void Rendering::WindowsParameterImpl::SetWindowParameter(const std::string& aWindowTitle, int x, int y, bool allowResize)
{
    RENDERING_CLASS_IS_VALID_9;

    windowTitle = aWindowTitle;
    windowX = x;
    windowY = y;
    isAllowResize = allowResize;
}

System::String Rendering::WindowsParameterImpl::GetWindowClassName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return className;
}

void Rendering::WindowsParameterImpl::SetWindowClassName(const String& aClassName)
{
    RENDERING_CLASS_IS_VALID_9;

    className = aClassName;
}

System::String Rendering::WindowsParameterImpl::GetWindowMenuName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return menuName;
}

void Rendering::WindowsParameterImpl::SetWindowMenuName(const String& aMenuName)
{
    RENDERING_CLASS_IS_VALID_9;

    menuName = aMenuName;
}

int Rendering::WindowsParameterImpl::GetIcon() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return icon;
}

bool Rendering::WindowsParameterImpl::IsIconDefault() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isIconDefault;
}

int Rendering::WindowsParameterImpl::GetCursor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cursor;
}

bool Rendering::WindowsParameterImpl::IsCursorDefault() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isCursorDefault;
}

System::WindowsBrushTypes Rendering::WindowsParameterImpl::GetBackground() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return background;
}

void Rendering::WindowsParameterImpl::SetWindowPictorialParameter(int aIcon, bool aIsIconDefault, int aCursor, bool aIsCursorDefault, WindowsBrushTypes aBackground) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    icon = aIcon;
    isIconDefault = aIsIconDefault;
    cursor = aCursor;
    isCursorDefault = aIsCursorDefault;
    background = aBackground;
}
