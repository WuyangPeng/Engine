///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/14 11:20)

#include "Rendering/RenderingExport.h"

#include "LightAmbEffect.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/ShaderFloats/LightAmbientConstant.h"
#include "Rendering/ShaderFloats/LightAttenuationConstant.h"
#include "Rendering/ShaderFloats/MaterialAmbientConstant.h"
#include "Rendering/ShaderFloats/MaterialEmissiveConstant.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h"

namespace
{
    std::array<int, 5> dx9VRegisters{ 0, 4, 5, 6, 7 };
    std::array<int, 5> oglVRegisters{ 1, 5, 6, 7, 8 };
    std::array<std::array<int, 5>*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> vRegisters{
        nullptr,
        &dx9VRegisters,
        &dx9VRegisters,
        &dx9VRegisters,
        &oglVRegisters
    };

    std::array<std::string, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> vPrograms{
        // VP_NONE
        "",

        // VP_VS_1_1
        "vs_1_1\n"
        "def c8, 1.00000000, 0, 0, 0\n"
        "dcl_position0 v0\n"
        "mov r1.x, c7.w\n"
        "mul r1.xyz, c6, r1.x\n"
        "mul r1.xyz, r1, c5\n"
        "mov r0.w, c8.x\n"
        "mov r0.xyz, v0\n"
        "dp4 oPos.w, r0, c3\n"
        "dp4 oPos.z, r0, c2\n"
        "dp4 oPos.y, r0, c1\n"
        "dp4 oPos.x, r0, c0\n"
        "add oD0.xyz, r1, c4\n"
        "mov oD0.w, c8.x\n",

        // VP_VS_2_0
        "vs_2_0\n"
        "def c8, 1.00000000, 0, 0, 0\n"
        "dcl_position v0\n"
        "mov r1.x, c7.w\n"
        "mul r1.xyz, c6, r1.x\n"
        "mul r1.xyz, r1, c5\n"
        "mov r0.w, c8.x\n"
        "mov r0.xyz, v0\n"
        "dp4 oPos.w, r0, c3\n"
        "dp4 oPos.z, r0, c2\n"
        "dp4 oPos.y, r0, c1\n"
        "dp4 oPos.x, r0, c0\n"
        "add oD0.xyz, r1, c4\n"
        "mov oD0.w, c8.x\n",

        // VP_VS_3_0
        "vs_3_0\n"
        "dcl_position o0\n"
        "dcl_color0 o1\n"
        "def c8, 1.00000000, 0, 0, 0\n"
        "dcl_position0 v0\n"
        "mov r1.x, c7.w\n"
        "mul r1.xyz, c6, r1.x\n"
        "mul r1.xyz, r1, c5\n"
        "mov r0.w, c8.x\n"
        "mov r0.xyz, v0\n"
        "dp4 o0.w, r0, c3\n"
        "dp4 o0.z, r0, c2\n"
        "dp4 o0.y, r0, c1\n"
        "dp4 o0.x, r0, c0\n"
        "add o1.xyz, r1, c4\n"
        "mov o1.w, c8.x\n",

        // VP_ARBVP1
        "!!ARBvp1.0\n"
        "PARAM c[9] = { { 1 }, program.local[1..8] };\n"
        "TEMP R0;\n"
        "TEMP R1;\n"
        "MOV R1.xyz, c[7];\n"
        "MUL R1.xyz, R1, c[8].w;\n"
        "MUL R1.xyz, R1, c[6];\n"
        "MOV R0.w, c[0].x;\n"
        "MOV R0.xyz, vertex.position;\n"
        "DP4 result.position.w, R0, c[4];\n"
        "DP4 result.position.z, R0, c[3];\n"
        "DP4 result.position.y, R0, c[2];\n"
        "DP4 result.position.x, R0, c[1];\n"
        "ADD result.color.xyz, R1, c[5];\n"
        "MOV result.color.w, c[0].x;\n"
        "END\n"
    };

    std::array<std::string, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> pPrograms{
        // PP_NONE
        "",

        // PP_PS_1_1
        "ps.1.1\n"
        "mov r0, v0\n",

        // PP_PS_2_0
        "ps_2_0\n"
        "dcl v0\n"
        "mov oC0, v0\n",

        // PP_PS_3_0
        "ps_3_0\n"
        "dcl_color0 v0\n"
        "mov oC0, v0\n",

        // PP_ARBFP1
        "!!ARBfp1.0\n"
        "MOV result.color, fragment.color.primary;\n"
        "END\n"
    };
}

CORE_TOOLS_RTTI_DEFINE(Rendering, LightAmbEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightAmbEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightAmbEffect);

Rendering::LightAmbEffect::LightAmbEffect(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }
{
    auto vshader = std::make_shared<VertexShader>("LightAmb", 1, 2, 5, 0);
    vshader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(1, "vertexColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    vshader->SetConstant(0, "PVWMatrix", 4);
    vshader->SetConstant(1, "MaterialEmissive", 1);
    vshader->SetConstant(2, "MaterialAmbient", 1);
    vshader->SetConstant(3, "LightAmbient", 1);
    vshader->SetConstant(4, "LightAttenuation", 1);

    auto profile = vshader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 5; ++j)
        {
            profile->SetBaseRegister(i, j, (*vRegisters.at(i)).at(j));
        }

        profile->SetProgram(i, vPrograms.at(i));
    }

    auto pshader = std::make_shared<PixelShader>("LightAmb", 1, 1, 0, 0);
    pshader->SetInput(0, "vertexColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);

    profile = pshader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        profile->SetProgram(i, pPrograms.at(i));
    }

    auto pass = std::make_shared<VisualPass>(CoreTools::DisableNotThrow::Disable);
    pass->SetVertexShader(vshader);
    pass->SetPixelShader(pshader);
    pass->SetAlphaState(std::make_shared<AlphaState>(CoreTools::DisableNotThrow::Disable));
    pass->SetCullState(std::make_shared<CullState>(CoreTools::DisableNotThrow::Disable));
    pass->SetDepthState(std::make_shared<DepthState>(CoreTools::DisableNotThrow::Disable));
    pass->SetOffsetState(std::make_shared<OffsetState>(CoreTools::DisableNotThrow::Disable));
    pass->SetStencilState(std::make_shared<StencilState>(CoreTools::DisableNotThrow::Disable));
    pass->SetWireState(std::make_shared<WireState>(CoreTools::DisableNotThrow::Disable));

    auto technique = std::make_shared<VisualTechnique>(CoreTools::DisableNotThrow::Disable);
    technique->InsertPass(pass);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, LightAmbEffect)

Rendering::VisualEffectInstanceSharedPtr Rendering::LightAmbEffect::CreateInstance(const LightSharedPtr& light, const MaterialSharedPtr& material)
{
    RENDERING_CLASS_IS_VALID_9;

    auto instance = std::make_shared<VisualEffectInstance>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), 0);

    instance->SetVertexConstant(0, 0, std::make_shared<ProjectionViewMatrixConstant>(CoreTools::DisableNotThrow::Disable));
    instance->SetVertexConstant(0, 1, std::make_shared<MaterialEmissiveConstant>(material));
    instance->SetVertexConstant(0, 2, std::make_shared<MaterialAmbientConstant>(material));
    instance->SetVertexConstant(0, 3, std::make_shared<LightAmbientConstant>(light));
    instance->SetVertexConstant(0, 4, std::make_shared<LightAttenuationConstant>(light));

    return instance;
}

Rendering::VisualEffectInstanceSharedPtr Rendering::LightAmbEffect::CreateUniqueInstance(const LightSharedPtr& light, const MaterialSharedPtr& material)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto effect = std::make_shared<LightAmbEffect>(CoreTools::DisableNotThrow::Disable);

#include STSTEM_WARNING_POP

    return effect->CreateInstance(light, material);
}

Rendering::LightAmbEffect::LightAmbEffect(LoadConstructor value)
    : ParentType{ value }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::LightAmbEffect::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::LightAmbEffect::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    VisualEffect::Link(source);
}

void Rendering::LightAmbEffect::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    VisualEffect::PostLink();
}

int64_t Rendering::LightAmbEffect::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return VisualEffect::Register(target);
}

void Rendering::LightAmbEffect::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::LightAmbEffect::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return VisualEffect::GetStreamingSize();
}
