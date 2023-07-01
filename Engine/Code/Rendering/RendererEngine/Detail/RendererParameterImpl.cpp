///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 15:03)

#include "Rendering/RenderingExport.h"

#include "RendererParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RendererParameterImpl::RendererParameterImpl(RendererTypes rendererType)
    : rendererType{ rendererType },
      rendererBasis{},
      windowsParameter{ WindowsParameter::Create() }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererParameterImpl)

void Rendering::RendererParameterImpl::SetRendererType(RendererTypes aRendererType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    rendererType = aRendererType;
}

Rendering::DataFormatType Rendering::RendererParameterImpl::GetColorFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererBasis.GetColorFormat();
}

Rendering::DataFormatType Rendering::RendererParameterImpl::GetDepthStencilFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererBasis.GetDepthStencilFormat();
}

int Rendering::RendererParameterImpl::GetNumMultiSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererBasis.GetNumMultiSamples();
}

Rendering::RendererParameterImpl::ColourType Rendering::RendererParameterImpl::GetClearColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowsParameter.GetClearColor();
}

std::string Rendering::RendererParameterImpl::GetWindowTitle() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowsParameter.GetWindowTitle();
}

int Rendering::RendererParameterImpl::GetXPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowsParameter.GetXPosition();
}

int Rendering::RendererParameterImpl::GetYPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowsParameter.GetYPosition();
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

    return windowsParameter.IsAllowResize();
}

Rendering::RendererTypes Rendering::RendererParameterImpl::GetRendererType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererType;
}

void Rendering::RendererParameterImpl::SetTextureFormat(DataFormatType colorFormat, DataFormatType depthStencilFormat, int numMultiSamples)
{
    RENDERING_CLASS_IS_VALID_9;

    rendererBasis.SetDataFormat(colorFormat, depthStencilFormat);
    rendererBasis.SetMultiSamplesNumber(0 < numMultiSamples ? numMultiSamples : 0);
}

void Rendering::RendererParameterImpl::SetClearColor(float red, float green, float blue, float alpha)
{
    RENDERING_CLASS_IS_VALID_9;

    windowsParameter.SetClearColor(red, green, blue, alpha);
}

void Rendering::RendererParameterImpl::SetWindowParameter(const std::string& windowTitle, int width, int height, int x, int y, bool allowResize)
{
    RENDERING_CLASS_IS_VALID_9;

    windowsParameter.SetWindowParameter(windowTitle, x, y, allowResize);
    rendererBasis.SetSize(width, height);
}

void Rendering::RendererParameterImpl::Resize(int width, int height)
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

    return windowsParameter.GetWindowClassName();
}

void Rendering::RendererParameterImpl::SetWindowClassName(const System::String& className)
{
    RENDERING_CLASS_IS_VALID_9;

    windowsParameter.SetWindowClassName(className);
}

System::String Rendering::RendererParameterImpl::GetWindowMenuName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowsParameter.GetWindowMenuName();
}

void Rendering::RendererParameterImpl::SetWindowMenuName(const System::String& menuName)
{
    RENDERING_CLASS_IS_VALID_9;

    windowsParameter.SetWindowMenuName(menuName);
}

int Rendering::RendererParameterImpl::GetIcon() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowsParameter.GetIcon();
}

bool Rendering::RendererParameterImpl::IsIconDefault() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowsParameter.IsIconDefault();
}

int Rendering::RendererParameterImpl::GetCursor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowsParameter.GetCursor();
}

bool Rendering::RendererParameterImpl::IsCursorDefault() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowsParameter.IsCursorDefault();
}

System::WindowsBrushTypes Rendering::RendererParameterImpl::GetBackground() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowsParameter.GetBackground();
}

void Rendering::RendererParameterImpl::SetWindowPictorialParameter(int icon, bool isIconDefault, int cursor, bool isCursorDefault, WindowsBrushTypes background)
{
    RENDERING_CLASS_IS_VALID_9;

    windowsParameter.SetWindowPictorialParameter(icon, isIconDefault, cursor, isCursorDefault, background);
}
