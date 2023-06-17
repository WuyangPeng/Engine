///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:47)

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