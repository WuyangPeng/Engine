///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/10 16:15)

#include "Rendering/RenderingExport.h"

#include "CubeMapEffect.h"
#include "Detail/CubeMapEffectImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Buffers/ConstantBufferDetail.h"
#include "Rendering/Shaders/ShaderDetail.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, CubeMapEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, CubeMapEffect)

CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, CubeMapEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, CubeMapEffect);

Rendering::CubeMapEffect::CubeMapEffect(ProgramFactory& factory,
                                        const BaseRendererSharedPtr& baseRenderer,
                                        const TextureCubeSharedPtr& texture,
                                        SamplerStateFilter filter,
                                        SamplerStateMode mode0,
                                        SamplerStateMode mode1,
                                        float reflectivity)
    : ParentType{ "CubeMapEffect", factory, baseRenderer, "Resource/Shader/CubeMapEffect.vs", "Resource/Shader/CubeMapEffect.ps" },
      impl{ texture,
            filter,
            mode0,
            mode1,
            reflectivity,
            baseRenderer->HasDepthRange01(),
            Rendering::GetStreamSize<Mathematics::Matrix4<float>>(),
            Rendering::GetStreamSize<Mathematics::Vector4<float>>(),
            Rendering::GetStreamSize<float>() }
{
    const auto vertexShader = GetVertexShader();
    const auto pixelShader = GetPixelShader();

    vertexShader->Set("ProjectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
    vertexShader->Set("WorldMatrix", impl->GetWorldMatrixConstant());
    vertexShader->Set("CameraWorldPosition", impl->GetCameraWorldPositionConstant());
    pixelShader->Set("Reflectivity", impl->GetReflectivityConstant());
    pixelShader->Set("cubeTexture", impl->GetCubeTexture(), "cubeSampler", impl->GetCubeSampler());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::CubeMapEffect::CubeMapEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CubeMapEffect)

void Rendering::CubeMapEffect::SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::SetProjectionViewWorldMatrixConstant(buffer);

    GetVertexShader()->Set("ProjectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
}

void Rendering::CubeMapEffect::UseDynamicUpdates(float dMin, float dMax)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->UseDynamicUpdates(dMin, dMax);
}

void Rendering::CubeMapEffect::SetWorldMatrix(const Matrix4& worldMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetWorldMatrix(worldMatrix);
}

Rendering::CubeMapEffect::Matrix4 Rendering::CubeMapEffect::GetWorldMatrix() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWorldMatrix();
}

Rendering::VisualEffect::ConstConstantBufferSharedPtr Rendering::CubeMapEffect::GetWorldMatrixConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetWorldMatrixConstant();
}

void Rendering::CubeMapEffect::SetCameraWorldPosition(const Vector4& cameraWorldPosition)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetCameraWorldPosition(cameraWorldPosition);
}

Rendering::CubeMapEffect::Vector4 Rendering::CubeMapEffect::GetCameraWorldPosition() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCameraWorldPosition();
}

Rendering::VisualEffect::ConstConstantBufferSharedPtr Rendering::CubeMapEffect::GetCameraWorldPositionConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCameraWorldPositionConstant();
}

float Rendering::CubeMapEffect::GetReflectivity() const
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetReflectivity();
}

void Rendering::CubeMapEffect::SetReflectivity(float reflectivity)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetReflectivity(reflectivity);
}

Rendering::VisualEffect::ConstConstantBufferSharedPtr Rendering::CubeMapEffect::GetReflectivityConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReflectivityConstant();
}

void Rendering::CubeMapEffect::UpdateFaces(const BaseRendererSharedPtr& baseRenderer, const SpatialSharedPtr& scene, Culler& culler, const APoint& envOrigin, const AVector& envDVector, const AVector& envUVector, const AVector& envRVector)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->UpdateFaces(baseRenderer, scene, culler, envOrigin, envDVector, envUVector, envRVector);
}
