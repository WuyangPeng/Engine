///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/28 15:15)

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