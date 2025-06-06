﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/19 14:16)

#include "Rendering/RenderingExport.h"

#include "LightCameraGeometry.h"
#include "Material.h"
#include "ProjectedTextureEffect.h"
#include "Detail/ProjectedTextureEffectImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/LocalEffects/Lighting.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Shaders/Shader.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ProjectedTextureEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, ProjectedTextureEffect)

CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, ProjectedTextureEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, ProjectedTextureEffect);

Rendering::ProjectedTextureEffect::ProjectedTextureEffect(ProgramFactory& factory,
                                                          const BaseRendererSharedPtr& baseRenderer,
                                                          const MaterialSharedPtr& material,
                                                          const LightSharedPtr& lighting,
                                                          const LightCameraGeometrySharedPtr& geometry,
                                                          const Texture2DSharedPtr& texture,
                                                          SamplerStateFilter filter,
                                                          SamplerStateMode mode0,
                                                          SamplerStateMode mode1)
    : ParentType{ "ProjectedTextureEffect",
                  factory,
                  baseRenderer,
                  "Resource/Shader/ProjectedTextureEffect.vs",
                  "Resource/Shader/ProjectedTextureEffect.ps",
                  material,
                  lighting,
                  geometry,
                  Rendering::GetStreamSize<ColourType>() * 4,
                  Rendering::GetStreamSize<ColourType>() * 4,
                  Rendering::GetStreamSize<ColourType>() * 2 },
      impl{ texture, filter, mode0, mode1, Rendering::GetStreamSize<Matrix4>() }
{
    ClassType::UpdateMaterialConstant();
    ClassType::UpdateLightingConstant();
    ClassType::UpdateGeometryConstant();

    const auto vertexShader = GetVertexShader();
    vertexShader->Set("ProjectorMatrix", impl->GetProjectorMatrixConstant());
    vertexShader->Set("Material", GetMaterialConstant());
    vertexShader->Set("Lighting", GetLightingConstant());
    vertexShader->Set("LightCameraGeometry", GetGeometryConstant());
    GetPixelShader()->Set("baseTexture", impl->GetTexture(), "baseSampler", impl->GetSamplerState());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ProjectedTextureEffect::ProjectedTextureEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ProjectedTextureEffect)

void Rendering::ProjectedTextureEffect::UpdateMaterialConstant()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto material = GetMaterial();

    const auto materialConstant = GetMaterialConstant();

    auto data = materialConstant->GetStorage();

    const auto emissive = material->GetEmissive();
    data.Increase<float>(emissive.GetRed());
    data.Increase<float>(emissive.GetGreen());
    data.Increase<float>(emissive.GetBlue());
    data.Increase<float>(emissive.GetAlpha());

    const auto ambient = material->GetAmbient();
    data.Increase<float>(ambient.GetRed());
    data.Increase<float>(ambient.GetGreen());
    data.Increase<float>(ambient.GetBlue());
    data.Increase<float>(ambient.GetAlpha());

    const auto diffuse = material->GetDiffuse();
    data.Increase<float>(diffuse.GetRed());
    data.Increase<float>(diffuse.GetGreen());
    data.Increase<float>(diffuse.GetBlue());
    data.Increase<float>(diffuse.GetAlpha());

    const auto specular = material->GetSpecular();
    data.Increase<float>(specular.GetRed());
    data.Increase<float>(specular.GetGreen());
    data.Increase<float>(specular.GetBlue());
    data.Increase<float>(specular.GetAlpha());

    ParentType::UpdateMaterialConstant();
}

void Rendering::ProjectedTextureEffect::UpdateLightingConstant()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto lighting = GetLighting();

    const auto lightingConstant = GetLightingConstant();

    auto data = lightingConstant->GetStorage();

    const auto ambient = lighting->GetAmbient();
    data.Increase<float>(ambient.GetRed());
    data.Increase<float>(ambient.GetGreen());
    data.Increase<float>(ambient.GetBlue());
    data.Increase<float>(ambient.GetAlpha());

    const auto diffuse = lighting->GetDiffuse();
    data.Increase<float>(diffuse.GetRed());
    data.Increase<float>(diffuse.GetGreen());
    data.Increase<float>(diffuse.GetBlue());
    data.Increase<float>(diffuse.GetAlpha());

    const auto specular = lighting->GetSpecular();
    data.Increase<float>(specular.GetRed());
    data.Increase<float>(specular.GetGreen());
    data.Increase<float>(specular.GetBlue());
    data.Increase<float>(specular.GetAlpha());

    data.Increase<float>(lighting->GetConstant());
    data.Increase<float>(lighting->GetLinear());
    data.Increase<float>(lighting->GetQuadratic());
    data.Increase<float>(lighting->GetIntensity());

    ParentType::UpdateLightingConstant();
}

void Rendering::ProjectedTextureEffect::UpdateGeometryConstant()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto geometry = GetGeometry();

    const auto geometryConstant = GetGeometryConstant();

    auto data = geometryConstant->GetStorage();

    const auto lightModelDirection = geometry->GetLightModelDirection();
    data.Increase<float>(lightModelDirection.GetRed());
    data.Increase<float>(lightModelDirection.GetGreen());
    data.Increase<float>(lightModelDirection.GetBlue());
    data.Increase<float>(lightModelDirection.GetAlpha());

    const auto cameraModelPosition = geometry->GetCameraModelPosition();
    data.Increase<float>(cameraModelPosition.GetRed());
    data.Increase<float>(cameraModelPosition.GetGreen());
    data.Increase<float>(cameraModelPosition.GetBlue());
    data.Increase<float>(cameraModelPosition.GetAlpha());

    ParentType::UpdateGeometryConstant();
}

void Rendering::ProjectedTextureEffect::SetProjectorMatrix(const Matrix4& projectorMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto projectorMatrixConstant = GetProjectorMatrixConstant();

    auto data = projectorMatrixConstant->GetStorage();

    for (const auto value : projectorMatrix.GetContainer())
    {
        data.Increase(value);
    }
}

Rendering::ProjectedTextureEffect::ConstantBufferSharedPtr Rendering::ProjectedTextureEffect::GetProjectorMatrixConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetProjectorMatrixConstant();
}

void Rendering::ProjectedTextureEffect::UpdateProjectorMatrixConstant()
{
    RENDERING_CLASS_IS_VALID_9;

    MAYBE_UNUSED const auto result = GetBaseRenderer()->Update(GetProjectorMatrixConstant());
}
