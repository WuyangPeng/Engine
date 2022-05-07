///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/12 13:37)

#include "Rendering/RenderingExport.h"

#include "ShaderManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::ShaderManagerImpl::ShaderManagerImpl() noexcept
    : vertexShaderProfile{ ShaderFlags::VertexShaderProfile::None }, pixelShaderProfile{ ShaderFlags::PixelShaderProfile::None }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderManagerImpl)

void Rendering::ShaderManagerImpl::SetVertexProfile(VertexShaderProfile profile) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexShaderProfile = profile;
}

Rendering::ShaderManagerImpl::VertexShaderProfile Rendering::ShaderManagerImpl::GetVertexProfile() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexShaderProfile;
}

void Rendering::ShaderManagerImpl::SetPixelProfile(PixelShaderProfile profile) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    pixelShaderProfile = profile;
}

Rendering::ShaderManagerImpl::PixelShaderProfile Rendering::ShaderManagerImpl::GetPixelProfile() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return pixelShaderProfile;
}