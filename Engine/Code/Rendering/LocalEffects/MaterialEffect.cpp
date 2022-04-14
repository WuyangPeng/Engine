// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 13:37)

#include "Rendering/RenderingExport.h"

#include "MaterialEffect.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/ShaderFloats/MaterialDiffuseConstant.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26492)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26815)
CORE_TOOLS_RTTI_DEFINE(Rendering, MaterialEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, MaterialEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, MaterialEffect);

Rendering::MaterialEffect::MaterialEffect()
{
    VertexShaderSharedPtr vshader{ std::make_shared<VertexShader>("Wm5.Material", 1, 2, 2, 0) };
    vshader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(1, "vertexColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    vshader->SetConstant(0, "PVWMatrix", 4);
    vshader->SetConstant(1, "MaterialDiffuse", 1);

    auto profile = vshader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 2; ++j)
        {
            profile->SetBaseRegister(i, j, msVRegisters[i][j]);
        }

        profile->SetProgram(i, msVPrograms[i]);
    }

    PixelShaderSharedPtr pshader{ std::make_shared<PixelShader>("Wm5.Material", 1, 1, 0, 0) };
    pshader->SetInput(0, "vertexColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        profile->SetProgram(i, msPPrograms[i]);
    }

    VisualPassSharedPtr pass{};
    pass->SetVertexShader(vshader);
    pass->SetPixelShader(pshader);
    pass->SetAlphaState(AlphaStateSharedPtr{});
    pass->SetCullState(CullStateSharedPtr{});
    pass->SetDepthState(DepthStateSharedPtr{});
    pass->SetOffsetState(OffsetStateSharedPtr{});
    pass->SetStencilState(StencilStateSharedPtr{});
    pass->SetWireState(WireStateSharedPtr{});

    VisualTechniqueSharedPtr technique{};
    technique->InsertPass(pass);
    InsertTechnique(technique);
}

Rendering::VisualEffectInstance* Rendering::MaterialEffect::CreateInstance(Material* material) const noexcept
{
    material;
    VisualEffectInstance* instance = nullptr;  // CoreTools::New0 < VisualEffectInstance>(VisualEffectSharedPtr((VisualEffect*)this), 0);
    // instance->SetVertexConstant(0, "PVWMatrix", ShaderFloatSharedPtr(CoreTools::New0<ProjectionViewMatrixConstant>()));
    // instance->SetVertexConstant(0, "MaterialDiffuse", ShaderFloatSharedPtr(CoreTools::New0<MaterialDiffuseConstant>(MaterialSharedPtr(material))));
    return instance;
}

Rendering::VisualEffectInstance* Rendering::MaterialEffect::CreateUniqueInstance(Material* material) noexcept
{
    const MaterialEffect* effect = nullptr;  // CoreTools::New0<MaterialEffect>();
    if (effect == nullptr)
        return nullptr;
    return effect->CreateInstance(material);
}

// Streaming support.

Rendering::MaterialEffect::MaterialEffect(LoadConstructor value)
    : VisualEffect{ value }
{
}

void Rendering::MaterialEffect::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::MaterialEffect::Link(CoreTools::ObjectLink& source)
{
    VisualEffect::Link(source);
}

void Rendering::MaterialEffect::PostLink()
{
    VisualEffect::PostLink();

    auto pass = GetTechnique(0)->GetPass(0);
    auto vshader = pass->GetVertexShader();
    auto pshader = pass->GetPixelShader();
    auto profile = const_cast<ShaderProfileData*>(vshader->GetProfile().get());

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 2; ++j)
        {
            profile->SetBaseRegister(i, j, msVRegisters[i][j]);
        }

        profile->SetProgram(i, msVPrograms[i]);
    }

    profile = const_cast<ShaderProfileData*>(pshader->GetProfile().get());

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        profile->SetProgram(i, msPPrograms[i]);
    }
}

uint64_t Rendering::MaterialEffect::Register(CoreTools::ObjectRegister& target) const
{
    return VisualEffect::Register(target);
}

void Rendering::MaterialEffect::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::MaterialEffect::GetStreamingSize() const
{
    return VisualEffect::GetStreamingSize();
}

// Profiles.

int Rendering::MaterialEffect::msDx9VRegisters[2]{ 0, 4 };
int Rendering::MaterialEffect::msOglVRegisters[2]{ 1, 5 };
int* Rendering::MaterialEffect::msVRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]{
    0,
    msDx9VRegisters,
    msDx9VRegisters,
    msDx9VRegisters,
    msOglVRegisters
};

std::string Rendering::MaterialEffect::msVPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]{
    // VP_NONE
    "",

    // VP_VS_1_1
    "vs_1_1\n"
    "def c5, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "mov r0.w, c5.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oD0, c4\n",

    // VP_VS_2_0
    "vs_2_0\n"
    "def c5, 1.00000000, 0, 0, 0\n"
    "dcl_position v0\n"
    "mov r0.w, c5.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oD0, c4\n",

    // VP_VS_3_0
    "vs_3_0\n"
    "dcl_position o0\n"
    "dcl_color0 o1\n"
    "def c5, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "mov r0.w, c5.x\n"
    "mov r0.xyz, v0\n"
    "dp4 o0.w, r0, c3\n"
    "dp4 o0.z, r0, c2\n"
    "dp4 o0.y, r0, c1\n"
    "dp4 o0.x, r0, c0\n"
    "mov o1, c4\n",

    // VP_ARBVP1
    "!!ARBvp1.0\n"
    "PARAM c[6] = { { 1 }, program.local[1..5] };\n"
    "TEMP R0;\n"
    "MOV R0.w, c[0].x;\n"
    "MOV R0.xyz, vertex.position;\n"
    "DP4 result.position.w, R0, c[4];\n"
    "DP4 result.position.z, R0, c[3];\n"
    "DP4 result.position.y, R0, c[2];\n"
    "DP4 result.position.x, R0, c[1];\n"
    "MOV result.color, c[5];\n"
    "END\n"
};

std::string Rendering::MaterialEffect::msPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]{
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

CoreTools::ObjectInterfaceSharedPtr Rendering::MaterialEffect::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP
