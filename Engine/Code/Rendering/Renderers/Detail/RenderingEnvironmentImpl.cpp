///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/05 10:59)

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

Rendering::RenderingDevice Rendering::RenderingEnvironmentImpl::GetRenderingDevice() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return RenderingDevice{ CoreTools::DisableNotThrow::Disable };
}