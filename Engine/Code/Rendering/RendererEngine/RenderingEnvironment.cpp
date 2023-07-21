///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/25 16:26)

#include "Rendering/RenderingExport.h"

#include "RenderingEnvironment.h"
#include "Detail/RenderingEnvironmentFactory.h"
#include "Detail/RenderingEnvironmentImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, RenderingEnvironment)

Rendering::RenderingEnvironment::RenderingEnvironment(const EnvironmentParameter& environmentParameter, const RendererParameter& rendererParameter)
    : impl{ CoreTools::ImplCreateUseFactory::Default, environmentParameter, rendererParameter }
{
    impl->InitEnvironment();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingEnvironment)

void Rendering::RenderingEnvironment::Release()
{
    RENDERING_CLASS_IS_VALID_9;

    impl->Release();
}

Rendering::RenderingDevice Rendering::RenderingEnvironment::GetRenderingDevice() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetRenderingDevice();
}

int Rendering::RenderingEnvironment::GetWidth() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWidth();
}

int Rendering::RenderingEnvironment::GetHeight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetHeight();
}

Rendering::DataFormatType Rendering::RenderingEnvironment::GetColorFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetColorFormat();
}

Rendering::DataFormatType Rendering::RenderingEnvironment::GetDepthStencilFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDepthStencilFormat();
}

int Rendering::RenderingEnvironment::GetNumMultiSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumMultiSamples();
}

Rendering::RenderingEnvironment::ColourType Rendering::RenderingEnvironment::GetClearColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetClearColor();
}
