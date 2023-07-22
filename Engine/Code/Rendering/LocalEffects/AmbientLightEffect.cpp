///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/06 17:27)

#include "Rendering/RenderingExport.h"

#include "AmbientLightEffect.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/ShaderFloats/LightAttenuationConstant.h"
#include "Rendering/Shaders/ProgramSources.h"
#include "Rendering/Shaders/Shader.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, AmbientLightEffect)

CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, AmbientLightEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, AmbientLightEffect);

Rendering::AmbientLightEffect::AmbientLightEffect(ProgramFactory& factory,
                                                  const BaseRendererSharedPtr& baseRenderer,
                                                  const MaterialSharedPtr& material,
                                                  const LightSharedPtr& lighting)
    : ParentType{ factory,
                  baseRenderer,
                  "Resource/Shader/AmbientLightEffect.vs",
                  "Resource/Shader/AmbientLightEffect.ps",
                  material,
                  lighting,
                  nullptr,
                  Rendering::GetStreamSize<Colour>() * 2,
                  Rendering::GetStreamSize<Colour>() * 2,
                  0 }
{
    ClassType::UpdateMaterialConstant();
    GetVertexShader()->Set("Material", GetMaterialConstant());

    ClassType::UpdateLightingConstant();
    GetVertexShader()->Set("Lighting", GetLightingConstant());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, AmbientLightEffect)

Rendering::AmbientLightEffect::AmbientLightEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::AmbientLightEffect::UpdateMaterialConstant()
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

    ParentType::UpdateMaterialConstant();
}

void Rendering::AmbientLightEffect::UpdateLightingConstant()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto lighting = GetLighting();

    const auto lightingConstant = GetLightingConstant();

    auto data = lightingConstant->GetData();

    const auto emissive = lighting->GetAmbient();
    data.Increase<float>(emissive.GetRed());
    data.Increase<float>(emissive.GetGreen());
    data.Increase<float>(emissive.GetBlue());
    data.Increase<float>(emissive.GetAlpha());

    data.Increase<float>(lighting->GetConstant());
    data.Increase<float>(lighting->GetLinear());
    data.Increase<float>(lighting->GetQuadratic());
    data.Increase<float>(lighting->GetIntensity());

    ParentType::UpdateLightingConstant();
}