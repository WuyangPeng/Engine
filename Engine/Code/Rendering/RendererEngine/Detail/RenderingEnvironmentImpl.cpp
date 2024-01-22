/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/17 16:53)

#include "Rendering/RenderingExport.h"

#include "RenderingEnvironmentImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RenderingEnvironmentImpl::RenderingEnvironmentImpl(const RendererParameter& rendererParameter) noexcept
    : rendererParameter{ rendererParameter }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingEnvironmentImpl)

void Rendering::RenderingEnvironmentImpl::Release() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

Rendering::DataFormatType Rendering::RenderingEnvironmentImpl::GetDepthStencilFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererParameter.GetDepthStencilFormat();
}

int Rendering::RenderingEnvironmentImpl::GetWidth() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererParameter.GetWidth();
}

int Rendering::RenderingEnvironmentImpl::GetHeight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererParameter.GetHeight();
}

Rendering::DataFormatType Rendering::RenderingEnvironmentImpl::GetColorFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererParameter.GetColorFormat();
}

int Rendering::RenderingEnvironmentImpl::GetNumMultiSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererParameter.GetNumMultiSamples();
}

Rendering::RenderingEnvironmentImpl::ColourType Rendering::RenderingEnvironmentImpl::GetClearColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererParameter.GetClearColor();
}

Rendering::RenderingDevice Rendering::RenderingEnvironmentImpl::GetRenderingDevice() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return RenderingDevice::Create();
}
