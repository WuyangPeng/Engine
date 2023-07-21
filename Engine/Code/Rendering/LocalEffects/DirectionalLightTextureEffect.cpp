///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/12 11:09)

#include "Rendering/RenderingExport.h"

#include "DirectionalLightTextureEffect.h"
#include "Light.h"
#include "LightCameraGeometry.h"
#include "Material.h"
#include "Detail/DirectionalLightTextureEffectImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Shaders/Shader.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, DirectionalLightTextureEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, DirectionalLightTextureEffect)

CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, DirectionalLightTextureEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, DirectionalLightTextureEffect);

Rendering::DirectionalLightTextureEffect::DirectionalLightTextureEffect(ProgramFactory& factory,
                                                                        const BaseRendererSharedPtr& baseRenderer,
                                                                        const MaterialSharedPtr& material,
                                                                        const LightSharedPtr& lighting,
                                                                        const LightCameraGeometrySharedPtr& geometry,
                                                                        const Texture2DSharedPtr& texture,
                                                                        SamplerStateFilter filter,
                                                                        SamplerStateMode mode0,
                                                                        SamplerStateMode mode1)
    : ParentType{ factory,
                  baseRenderer,
                  "Resource/Shader/DirectionalLightEffect.vs",
                  "Resource/Shader/DirectionalLightEffect.ps",
                  material,
                  lighting,
                  geometry,
                  Rendering::GetStreamSize<Colour>() * 4,
                  Rendering::GetStreamSize<Colour>() * 4,
                  Rendering::GetStreamSize<Colour>() * 2 },
      impl{ texture, filter, mode0, mode1 }
{
    ClassType::UpdateMaterialConstant();
    ClassType::UpdateLightingConstant();
    ClassType::UpdateGeometryConstant();

    const auto pixelShader = GetPixelShader();

    pixelShader->Set("Material", GetMaterialConstant());
    pixelShader->Set("Lighting", GetLightingConstant());
    pixelShader->Set("LightCameraGeometry", GetGeometryConstant());
    pixelShader->Set("baseTexture", impl->GetTexture(), "baseSampler", impl->GetSamplerState());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::DirectionalLightTextureEffect::DirectionalLightTextureEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DirectionalLightTextureEffect)

void Rendering::DirectionalLightTextureEffect::UpdateMaterialConstant()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto material = GetMaterial();

    const auto materialConstant = GetMaterialConstant();

    auto data = materialConstant->GetData();

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

void Rendering::DirectionalLightTextureEffect::UpdateLightingConstant()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto lighting = GetLighting();

    const auto lightingConstant = GetLightingConstant();

    auto data = lightingConstant->GetData();

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

void Rendering::DirectionalLightTextureEffect::UpdateGeometryConstant()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto geometry = GetGeometry();

    const auto geometryConstant = GetGeometryConstant();

    auto data = geometryConstant->GetData();

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
