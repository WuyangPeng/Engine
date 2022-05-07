///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/14 17:07)

#include "Rendering/RenderingExport.h"

#include "Texture2AddEffect.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h"

namespace
{
    constexpr auto dx9VRegisters = 0;
    constexpr auto oglVRegisters = 1;
    std::array<const int*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> vRegisters{
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
        "def c4, 1.00000000, 0, 0, 0\n"
        "dcl_position0 v0\n"
        "dcl_texcoord0 v1\n"
        "dcl_texcoord1 v2\n"
        "mov r0.w, c4.x\n"
        "mov r0.xyz, v0\n"
        "dp4 oPos.w, r0, c3\n"
        "dp4 oPos.z, r0, c2\n"
        "dp4 oPos.y, r0, c1\n"
        "dp4 oPos.x, r0, c0\n"
        "mov oT0.xy, v1\n"
        "mov oT1.xy, v2\n",

        // VP_VS_2_0
        "vs_2_0\n"
        "def c4, 1.00000000, 0, 0, 0\n"
        "dcl_position v0\n"
        "dcl_texcoord0 v1\n"
        "dcl_texcoord1 v2\n"
        "mov r0.w, c4.x\n"
        "mov r0.xyz, v0\n"
        "dp4 oPos.w, r0, c3\n"
        "dp4 oPos.z, r0, c2\n"
        "dp4 oPos.y, r0, c1\n"
        "dp4 oPos.x, r0, c0\n"
        "mov oT0.xy, v1\n"
        "mov oT1.xy, v2\n",

        // VP_VS_3_0
        "vs_3_0\n"
        "dcl_position o0\n"
        "dcl_texcoord0 o1\n"
        "dcl_texcoord1 o2\n"
        "def c4, 1.00000000, 0, 0, 0\n"
        "dcl_position0 v0\n"
        "dcl_texcoord0 v1\n"
        "dcl_texcoord1 v2\n"
        "mov r0.w, c4.x\n"
        "mov r0.xyz, v0\n"
        "dp4 o0.w, r0, c3\n"
        "dp4 o0.z, r0, c2\n"
        "dp4 o0.y, r0, c1\n"
        "dp4 o0.x, r0, c0\n"
        "mov o1.xy, v1\n"
        "mov o2.xy, v2\n",

        // VP_ARBVP1
        "!!ARBvp1.0\n"
        "PARAM c[5] = { { 1 }, program.local[1..4] };\n"
        "TEMP R0;\n"
        "MOV R0.w, c[0].x;\n"
        "MOV R0.xyz, vertex.position;\n"
        "DP4 result.position.w, R0, c[4];\n"
        "DP4 result.position.z, R0, c[3];\n"
        "DP4 result.position.y, R0, c[2];\n"
        "DP4 result.position.x, R0, c[1];\n"
        "MOV result.texcoord[0].xy, vertex.texcoord[0];\n"
        "MOV result.texcoord[1].xy, vertex.texcoord[1];\n"
        "END\n"
    };

    std::array<int, 2> allPTextureUnits{ 0, 1 };
    std::array<std::array<int, 2>*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> pTextureUnits{
        nullptr,
        &allPTextureUnits,
        &allPTextureUnits,
        &allPTextureUnits,
        &allPTextureUnits
    };

    std::array<std::string, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> pPrograms{
        // PP_NONE
        "",

        // PP_PS_1_1
        "ps.1.1\n"
        "tex t0\n"
        "tex t1\n"
        "add_sat r0, t0, t1\n",

        // PP_PS_2_0
        "ps_2_0\n"
        "dcl_2d s0\n"
        "dcl_2d s1\n"
        "dcl t0.xy\n"
        "dcl t1.xy\n"
        "texld r0, t1, s1\n"
        "texld r1, t0, s0\n"
        "add_sat r0, r1, r0\n"
        "mov oC0, r0\n",

        // PP_PS_3_0
        "ps_3_0\n"
        "dcl_2d s0\n"
        "dcl_2d s1\n"
        "dcl_texcoord0 v0.xy\n"
        "dcl_texcoord1 v1.xy\n"
        "texld r1, v1, s1\n"
        "texld r0, v0, s0\n"
        "add_sat oC0, r0, r1\n",

        // PP_ARBFP1
        "!!ARBfp1.0\n"
        "TEMP R0;\n"
        "TEMP R1;\n"
        "TEX R1, fragment.texcoord[1], texture[1], 2D;\n"
        "TEX R0, fragment.texcoord[0], texture[0], 2D;\n"
        "ADD_SAT result.color, R0, R1;\n"
        "END\n"
    };
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Texture2AddEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture2AddEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture2AddEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture2AddEffect);

Rendering::Texture2AddEffect::Texture2AddEffect(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }
{
    auto vshader = std::make_shared<VertexShader>("Texture2Add", 3, 3, 1, 0);
    vshader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::Position);
    vshader->SetInput(1, "modelTCoord0", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    vshader->SetInput(2, "modelTCoord1", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord1);
    vshader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(1, "vertexTCoord0", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    vshader->SetOutput(2, "vertexTCoord1", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord1);
    vshader->SetConstant(0, "PVWMatrix", 4);

    auto profile = vshader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 1; ++j)
        {
            profile->SetBaseRegister(i, j, *vRegisters.at(i));
        }

        profile->SetProgram(i, vPrograms.at(i));
    }

    auto pshader = std::make_shared<PixelShader>("Texture2Add", 2, 1, 0, 2);
    pshader->SetInput(0, "vertexTCoord0", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    pshader->SetInput(1, "vertexTCoord1", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord1);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetSampler(0, "Sampler0", ShaderFlags::SamplerType::Sampler2D);
    pshader->SetSampler(1, "Sampler1", ShaderFlags::SamplerType::Sampler2D);
    profile = pshader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 2; ++j)
        {
            profile->SetTextureUnit(i, j, pTextureUnits.at(i)->at(j));
        }

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
    InsertTechnique(technique);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::PixelShaderSharedPtr Rendering::Texture2AddEffect::GetPixelShaderSharedPtr() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto pass = GetTechnique(0)->GetPass(0);
    auto pshader = pass->GetPixelShader();
    return boost::polymorphic_pointer_cast<PixelShader>(pshader->CloneObject());
}

Rendering::VisualEffectInstanceSharedPtr Rendering::Texture2AddEffect::CreateInstance(const Texture2DSharedPtr& texture0, const Texture2DSharedPtr& texture1)
{
    RENDERING_CLASS_IS_VALID_9;

    auto instance = std::make_shared<VisualEffectInstance>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), 0);

    instance->SetVertexConstant(0, 0, std::make_shared<ProjectionViewMatrixConstant>(CoreTools::DisableNotThrow::Disable));
    instance->SetPixelTexture(0, 0, TextureSharedPtr(texture0));
    instance->SetPixelTexture(0, 1, TextureSharedPtr(texture1));

    const auto pshader = GetPixelShaderSharedPtr();

    const auto filter0 = pshader->GetFilter(0);
    if (filter0 != ShaderFlags::SamplerFilter::Nearest && filter0 != ShaderFlags::SamplerFilter::Linear && !texture0->HasMipmaps())
    {
        texture0->GenerateMipmaps();
    }

    const auto filter1 = pshader->GetFilter(1);
    if (filter1 != ShaderFlags::SamplerFilter::Nearest && filter1 != ShaderFlags::SamplerFilter::Linear && !texture1->HasMipmaps())
    {
        texture1->GenerateMipmaps();
    }

    return instance;
}

Rendering::VisualEffectInstanceSharedPtr Rendering::Texture2AddEffect::CreateUniqueInstance(const Texture2DSharedPtr& texture0, ShaderFlags::SamplerFilter filter0, ShaderFlags::SamplerCoordinate coordinate00, ShaderFlags::SamplerCoordinate coordinate01, const Texture2DSharedPtr& texture1, ShaderFlags::SamplerFilter filter1, ShaderFlags::SamplerCoordinate coordinate10, ShaderFlags::SamplerCoordinate coordinate11)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto effect = std::make_shared<ClassType>(CoreTools::DisableNotThrow::Disable);

#include STSTEM_WARNING_POP

    auto pshader = effect->GetPixelShaderSharedPtr();
    pshader->SetFilter(0, filter0);
    pshader->SetCoordinate(0, 0, coordinate00);
    pshader->SetCoordinate(0, 1, coordinate01);
    pshader->SetFilter(1, filter1);
    pshader->SetCoordinate(1, 0, coordinate10);
    pshader->SetCoordinate(1, 1, coordinate11);

    return effect->CreateInstance(texture0, texture1);
}

Rendering::Texture2AddEffect::Texture2AddEffect(LoadConstructor value)
    : VisualEffect{ value }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::Texture2AddEffect::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::Texture2AddEffect::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    VisualEffect::Link(source);
}

void Rendering::Texture2AddEffect::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    VisualEffect::PostLink();

    auto pass = GetTechnique(0)->GetPass(0);
    auto vshader = pass->GetVertexShader();
    auto cloneVShader = boost::polymorphic_pointer_cast<VertexShader>(vshader->CloneObject());
    auto pshader = pass->GetPixelShader();
    auto clonePShader = boost::polymorphic_pointer_cast<PixelShader>(pshader->CloneObject());
    auto profile = cloneVShader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 1; ++j)
        {
            profile->SetBaseRegister(i, j, *vRegisters.at(i));
        }

        profile->SetProgram(i, vPrograms.at(i));
    }

    profile = clonePShader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 2; ++j)
        {
            profile->SetTextureUnit(i, j, pTextureUnits.at(i)->at(j));
        }

        profile->SetProgram(i, pPrograms.at(i));
    }
}

uint64_t Rendering::Texture2AddEffect::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return VisualEffect::Register(target);
}

void Rendering::Texture2AddEffect::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::Texture2AddEffect::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return VisualEffect::GetStreamingSize();
}
