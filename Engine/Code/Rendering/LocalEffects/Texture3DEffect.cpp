// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 14:51)

#include "Rendering/RenderingExport.h"

#include "Texture3DEffect.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h"

#include "System/Helper/PragmaWarning.h"

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
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26434)
#include SYSTEM_WARNING_DISABLE(26815)
CORE_TOOLS_RTTI_DEFINE(Rendering, Texture3DEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture3DEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture3DEffect);

Rendering::Texture3DEffect ::Texture3DEffect(ShaderFlags::SamplerFilter filter, ShaderFlags::SamplerCoordinate coordinate0, ShaderFlags::SamplerCoordinate coordinate1, ShaderFlags::SamplerCoordinate coordinate2)
{
    VertexShaderSharedPtr vshader{ std::make_shared<VertexShader>("Wm5.Texture2D", 2, 2, 1, 0) };
    vshader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::Position);
    vshader->SetInput(1, "modelTCoord", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::TextureCoord0);
    vshader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(1, "vertexTCoord", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::TextureCoord0);
    vshader->SetConstant(0, "PVWMatrix", 4);
    auto profile = vshader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 1; ++j)
        {
            profile->SetBaseRegister(i, j, msVRegisters[i][j]);
        }

        profile->SetProgram(i, msVPrograms[i]);
    }

    PixelShaderSharedPtr pshader{ std::make_shared<PixelShader>("Wm5.Texture2D", 1, 1, 0, 1) };
    pshader->SetInput(0, "vertexTCoord", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::TextureCoord0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetSampler(0, "BaseSampler", ShaderFlags::SamplerType::Sampler2D);
    pshader->SetFilter(0, filter);
    pshader->SetCoordinate(0, 0, coordinate0);
    pshader->SetCoordinate(0, 1, coordinate1);
    pshader->SetCoordinate(0, 2, coordinate2);
    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 1; ++j)
        {
            profile->SetTextureUnit(i, j, msPTextureUnits[i][j]);
        }

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

Rendering::PixelShader* Rendering::Texture3DEffect ::GetPixelShader() const
{
    return const_cast<PixelShader*>(GetTechnique(0)->GetPass(0)->GetPixelShader().get());
}

Rendering::VisualEffectInstance* Rendering::Texture3DEffect ::CreateInstance(Texture3D* texture) const
{
    VisualEffectInstance* instance = nullptr;  //  CoreTools::New0 < VisualEffectInstance>(VisualEffectSharedPtr((VisualEffect*)this), 0);
    instance->SetVertexConstant(0, 0, ShaderFloatSharedPtr(std::make_shared<ProjectionViewMatrixConstant>()));
    instance->SetPixelTexture(0, 0, TextureSharedPtr(texture));

    const ShaderFlags::SamplerFilter filter = GetPixelShader()->GetFilter(0);
    if (filter != ShaderFlags::SamplerFilter::Nearest && filter != ShaderFlags::SamplerFilter::Linear && !texture->HasMipmaps())
    {
        texture->GenerateMipmaps();
    }

    return instance;
}

Rendering::VisualEffectInstance* Rendering::Texture3DEffect ::CreateUniqueInstance(Texture3D* texture, ShaderFlags::SamplerFilter filter, ShaderFlags::SamplerCoordinate coordinate0,
                                                                                   ShaderFlags::SamplerCoordinate coordinate1, ShaderFlags::SamplerCoordinate coordinate2)
{
    const Texture3DEffect* effect = nullptr;  // CoreTools::New0<Texture3DEffect>();
    PixelShader* pshader = effect->GetPixelShader();
    pshader->SetFilter(0, filter);
    pshader->SetCoordinate(0, 0, coordinate0);
    pshader->SetCoordinate(0, 1, coordinate1);
    pshader->SetCoordinate(0, 2, coordinate2);
    return effect->CreateInstance(texture);
}

// Streaming support.

Rendering::Texture3DEffect ::Texture3DEffect(LoadConstructor value)
    : VisualEffect{ value }
{
}

void Rendering::Texture3DEffect ::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::Texture3DEffect ::Link(CoreTools::ObjectLink& source)
{
    VisualEffect::Link(source);
}

void Rendering::Texture3DEffect ::PostLink()
{
    VisualEffect::PostLink();

    auto pass = GetTechnique(0)->GetPass(0);
    auto vshader = pass->GetVertexShader();
    auto pshader = pass->GetPixelShader();
    auto profile = const_cast<ShaderProfileData*>(vshader->GetProfile().get());

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 1; ++j)
        {
            profile->SetBaseRegister(i, j, msVRegisters[i][j]);
        }

        profile->SetProgram(i, msVPrograms[i]);
    }

    profile = const_cast<ShaderProfileData*>(pshader->GetProfile().get());

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 1; ++j)
        {
            profile->SetTextureUnit(i, j, msPTextureUnits[i][j]);
        }

        profile->SetProgram(i, msPPrograms[i]);
    }
}

uint64_t Rendering::Texture3DEffect ::Register(CoreTools::ObjectRegister& target) const
{
    return VisualEffect::Register(target);
}

void Rendering::Texture3DEffect ::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::Texture3DEffect ::GetStreamingSize() const
{
    return VisualEffect::GetStreamingSize();
}

// Profiles.

int Rendering::Texture3DEffect::msDx9VRegisters[1]{ 0 };
int Rendering::Texture3DEffect::msOglVRegisters[1]{ 1 };
int* Rendering::Texture3DEffect::msVRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]{
    0,
    msDx9VRegisters,
    msDx9VRegisters,
    msDx9VRegisters,
    msOglVRegisters
};

std::string Rendering::Texture3DEffect::msVPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]{
    // VP_NONE
    "",

    // VP_VS_1_1
    "vs_1_1\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord0 v1\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oT0.xyz, v1\n",

    // VP_VS_2_0
    "vs_2_0\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord0 v1\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oT0.xyz, v1\n",

    // VP_VS_3_0
    "vs_3_0\n"
    "dcl_position o0\n"
    "dcl_texcoord0 o1\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord0 v1\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 o0.w, r0, c3\n"
    "dp4 o0.z, r0, c2\n"
    "dp4 o0.y, r0, c1\n"
    "dp4 o0.x, r0, c0\n"
    "mov o1.xyz, v1\n",

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
    "MOV result.texcoord[0].xyz, vertex.texcoord[0];\n"
    "END\n"
};

int Rendering::Texture3DEffect::msAllPTextureUnits[1] = { 0 };
int* Rendering::Texture3DEffect::msPTextureUnits[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]{
    0,
    msAllPTextureUnits,
    msAllPTextureUnits,
    msAllPTextureUnits,
    msAllPTextureUnits
};

std::string Rendering::Texture3DEffect::msPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]{
    // PP_NONE
    "",

    // PP_PS_1_1
    "ps.1.1\n"
    "tex t0\n"
    "mov r0, t0\n",

    // PP_PS_2_0
    "ps_2_0\n"
    "dcl_volume s0\n"
    "dcl t0.xyz\n"
    "texld r0, t0, s0\n"
    "mov oC0, r0\n",

    // PP_PS_3_0
    "ps_3_0\n"
    "dcl_volume s0\n"
    "dcl_texcoord0 v0.xyz\n"
    "texld r0, v0, s0\n"
    "mov oC0, r0\n",

    // PP_ARBFP1
    "!!ARBfp1.0\n"
    "TEX result.color, fragment.texcoord[0], texture[0], 3D;\n"
    "END\n"
};

#include STSTEM_WARNING_POP