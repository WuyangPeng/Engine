///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 10:16)

#include "Rendering/RenderingExport.h"

#include "RendererParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::string;

Rendering::RendererParameterImpl::RendererParameterImpl(RendererTypes type) noexcept
    : rendererTypes{ type },
      rendererBasis{},
      colour{ 0.0f, 0.0f, 0.0f, 1.0f },
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
      background{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererParameterImpl)

Rendering::TextureFormat Rendering::RendererParameterImpl::GetColorFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererBasis.GetColorFormat();
}

Rendering::TextureFormat Rendering::RendererParameterImpl::GetDepthStencilFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererBasis.GetDepthStencilFormat();
}

int Rendering::RendererParameterImpl::GetNumMultisamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererBasis.GetNumMultisamples();
}

Rendering::Colour<float> Rendering::RendererParameterImpl::GetClearColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return colour;
}

std::string Rendering::RendererParameterImpl::GetWindowTitle() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowTitle;
}

int Rendering::RendererParameterImpl::GetXPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowX;
}

int Rendering::RendererParameterImpl::GetYPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowY;
}

int Rendering::RendererParameterImpl::GetWidth() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererBasis.GetWidth();
}

int Rendering::RendererParameterImpl::GetHeight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererBasis.GetHeight();
}

bool Rendering::RendererParameterImpl::IsAllowResize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isAllowResize;
}

Rendering::RendererTypes Rendering::RendererParameterImpl::GetRendererType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererTypes;
}

void Rendering::RendererParameterImpl::SetTextureFormat(TextureFormat colorFormat, TextureFormat depthStencilFormat, int numMultisamples) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    rendererBasis.SetTextureFormat(colorFormat, depthStencilFormat);
    rendererBasis.SetMultisamplesNumber(0 < numMultisamples ? numMultisamples : 0);
}

void Rendering::RendererParameterImpl::SetClearColor(float red, float green, float blue, float alpha) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    colour.SetColour(red, green, blue, alpha);
}

void Rendering::RendererParameterImpl::SetWindowParameter(const string& aWindowTitle, int width, int height, int x, int y, bool allowResize)
{
    RENDERING_CLASS_IS_VALID_9;

    windowTitle = aWindowTitle;
    rendererBasis.SetSize(width, height);
    windowX = x;
    windowY = y;
    isAllowResize = allowResize;
}

void Rendering::RendererParameterImpl::Resize(int width, int height) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    rendererBasis.SetSize(width, height);
}

Rendering::RendererBasis Rendering::RendererParameterImpl::GetRendererBasis() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererBasis;
}

System::String Rendering::RendererParameterImpl::GetWindowClassName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return className;
}

void Rendering::RendererParameterImpl::SetWindowClassName(const System::String& aClassName)
{
    RENDERING_CLASS_IS_VALID_9;

    className = aClassName;
}

System::String Rendering::RendererParameterImpl::GetWindowMenuName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return menuName;
}

void Rendering::RendererParameterImpl::SetWindowMenuName(const System::String& aMenuName)
{
    RENDERING_CLASS_IS_VALID_9;

    menuName = aMenuName;
}

int Rendering::RendererParameterImpl::GetIcon() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return icon;
}

bool Rendering::RendererParameterImpl::IsIconDefault() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isIconDefault;
}

int Rendering::RendererParameterImpl::GetCursor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cursor;
}

bool Rendering::RendererParameterImpl::IsCursorDefault() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isCursorDefault;
}

System::WindowsBrushTypes Rendering::RendererParameterImpl::GetBackground() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return background;
}

void Rendering::RendererParameterImpl::SetWindowPictorialParameter(int aIcon, bool aIsIconDefault, int aCursor, bool aIsCursorDefault, System::WindowsBrushTypes aBackground) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    icon = aIcon;
    isIconDefault = aIsIconDefault;
    cursor = aCursor;
    isCursorDefault = aIsCursorDefault;
    background = aBackground;
}
