// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 10:23)

#include "Rendering/RenderingExport.h"

#include "LightDirPerPixEffect.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/ShaderFloats/CameraModelPositionConstant.h"
#include "Rendering/ShaderFloats/LightAmbientConstant.h"
#include "Rendering/ShaderFloats/LightAttenuationConstant.h"
#include "Rendering/ShaderFloats/LightDiffuseConstant.h"
#include "Rendering/ShaderFloats/LightModelDirectionVectorConstant.h"
#include "Rendering/ShaderFloats/LightSpecularConstant.h"
#include "Rendering/ShaderFloats/MaterialAmbientConstant.h"
#include "Rendering/ShaderFloats/MaterialDiffuseConstant.h"
#include "Rendering/ShaderFloats/MaterialEmissiveConstant.h"
#include "Rendering/ShaderFloats/MaterialSpecularConstant.h"
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
#include SYSTEM_WARNING_DISABLE(26815)
#include SYSTEM_WARNING_DISABLE(26455)
CORE_TOOLS_RTTI_DEFINE(Rendering, LightDirPerPixEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightDirPerPixEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightDirPerPixEffect);

Rendering::LightDirPerPixEffect::LightDirPerPixEffect()
{
    VertexShaderSharedPtr vshader{ std::make_shared<VertexShader>("Wm5.LightDirPerPix", 2, 3, 1, 0) };
    vshader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::Position);
    vshader->SetInput(1, "modelNormal", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::TextureCoord1);
    vshader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(1, "vertexPosition", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::TextureCoord0);
    vshader->SetOutput(2, "vertexNormal", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::TextureCoord1);
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

    PixelShaderSharedPtr pshader{ std::make_shared<PixelShader>("Wm5.LightDirPerPix", 2, 1, 10, 0) };
    pshader->SetInput(0, "vertexPosition", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::TextureCoord0);
    pshader->SetInput(1, "vertexNormal", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::TextureCoord1);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetConstant(0, "CameraModelPosition", 1);
    pshader->SetConstant(1, "MaterialEmissive", 1);
    pshader->SetConstant(2, "MaterialAmbient", 1);
    pshader->SetConstant(3, "MaterialDiffuse", 1);
    pshader->SetConstant(4, "MaterialSpecular", 1);
    pshader->SetConstant(5, "LightModelDirection", 1);
    pshader->SetConstant(6, "LightAmbient", 1);
    pshader->SetConstant(7, "LightDiffuse", 1);
    pshader->SetConstant(8, "LightSpecular", 1);
    pshader->SetConstant(9, "LightAttenuation", 1);

    profile = pshader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 10; ++j)
        {
            profile->SetBaseRegister(i, j, msPRegisters[i][j]);
        }

        profile->SetProgram(i, msPPrograms[i]);
    }

    VisualPassSharedPtr pass{ new VisualPass{} };
    pass->SetVertexShader(vshader);
    pass->SetPixelShader(pshader);
    pass->SetAlphaState(AlphaStateSharedPtr{ new AlphaState{} });
    pass->SetCullState(CullStateSharedPtr{ new CullState{} });
    pass->SetDepthState(DepthStateSharedPtr{ new DepthState{} });
    pass->SetOffsetState(OffsetStateSharedPtr{ new OffsetState{} });
    pass->SetStencilState(StencilStateSharedPtr{ new StencilState{} });
    pass->SetWireState(WireStateSharedPtr{ new WireState{} });

    VisualTechniqueSharedPtr technique{ new VisualTechnique{} };
    technique->InsertPass(pass);
    InsertTechnique(technique);
}

Rendering::VisualEffectInstance* Rendering::LightDirPerPixEffect::CreateInstance(Light* light,
                                                                                 Material* material) const
{
    VisualEffectInstance* instance = nullptr;  //    CoreTools::New0<VisualEffectInstance>(VisualEffectSharedPtr((VisualEffect*)this), 0);
    instance->SetVertexConstant(0, 0, ShaderFloatSharedPtr(std::make_shared<ProjectionViewMatrixConstant>()));
    instance->SetPixelConstant(0, 0, ShaderFloatSharedPtr(std::make_shared<CameraModelPositionConstant>()));
    instance->SetPixelConstant(0, 1, ShaderFloatSharedPtr(std::make_shared<MaterialEmissiveConstant>(MaterialSharedPtr(material))));
    instance->SetPixelConstant(0, 2, ShaderFloatSharedPtr(std::make_shared<MaterialAmbientConstant>(MaterialSharedPtr(material))));
    instance->SetPixelConstant(0, 3, ShaderFloatSharedPtr(std::make_shared<MaterialDiffuseConstant>(MaterialSharedPtr(material))));
    instance->SetPixelConstant(0, 4, ShaderFloatSharedPtr(std::make_shared<MaterialSpecularConstant>(MaterialSharedPtr(material))));
    instance->SetPixelConstant(0, 5, ShaderFloatSharedPtr(std::make_shared<LightModelDirectionVectorConstant>(LightSharedPtr(light))));
    instance->SetPixelConstant(0, 6, ShaderFloatSharedPtr(std::make_shared<LightAmbientConstant>(LightSharedPtr(light))));
    instance->SetPixelConstant(0, 7, ShaderFloatSharedPtr(std::make_shared<LightDiffuseConstant>(LightSharedPtr(light))));
    instance->SetPixelConstant(0, 8, ShaderFloatSharedPtr(std::make_shared<LightSpecularConstant>(LightSharedPtr(light))));
    instance->SetPixelConstant(0, 9, ShaderFloatSharedPtr(std::make_shared<LightAttenuationConstant>(LightSharedPtr(light))));

    return instance;
}

Rendering::VisualEffectInstance* Rendering::LightDirPerPixEffect::CreateUniqueInstance(
    Light* light, Material* material)
{
    const LightDirPerPixEffect* effect =  nullptr;  // CoreTools::New0<LightDirPerPixEffect>();
    return effect->CreateInstance(light, material);
}

// Streaming support.

Rendering::LightDirPerPixEffect ::LightDirPerPixEffect(LoadConstructor value)
    : VisualEffect{ value }
{
}

void Rendering::LightDirPerPixEffect ::Load(CoreTools::BufferSource& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::LightDirPerPixEffect ::Link(CoreTools::ObjectLink& source)
{
    VisualEffect::Link(source);
}

void Rendering::LightDirPerPixEffect ::PostLink()
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
        for (auto j = 0; j < 10; ++j)
        {
            profile->SetBaseRegister(i, j, msPRegisters[i][j]);
        }

        profile->SetProgram(i, msPPrograms[i]);
    }
}

uint64_t Rendering::LightDirPerPixEffect ::Register(CoreTools::ObjectRegister& target) const
{
    return VisualEffect::Register(target);
}

void Rendering::LightDirPerPixEffect ::Save(CoreTools::BufferTarget& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::LightDirPerPixEffect ::GetStreamingSize() const
{
    return VisualEffect::GetStreamingSize();
}

// Profiles.

int Rendering::LightDirPerPixEffect::msDx9VRegisters[1]{ 0 };
int Rendering::LightDirPerPixEffect::msOglVRegisters[1]{ 1 };
int* Rendering::LightDirPerPixEffect::msVRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]{
    0,
    msDx9VRegisters,
    msDx9VRegisters,
    msDx9VRegisters,
    msOglVRegisters
};

std::string Rendering::LightDirPerPixEffect::msVPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]{
    // VP_NONE
    "",

    // VP_VS_1_1
    "",

    // VP_VS_2_0
    "vs_2_0\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position v0\n"
    "dcl_texcoord1 v1\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oT0.xyz, v0\n"
    "mov oT1.xyz, v1\n",

    // VP_VS_3_0
    "vs_3_0\n"
    "dcl_position o0\n"
    "dcl_texcoord0 o1\n"
    "dcl_texcoord1 o2\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord1 v1\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 o0.w, r0, c3\n"
    "dp4 o0.z, r0, c2\n"
    "dp4 o0.y, r0, c1\n"
    "dp4 o0.x, r0, c0\n"
    "mov o1.xyz, v0\n"
    "mov o2.xyz, v1\n",

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
    "MOV result.texcoord[0].xyz, vertex.position;\n"
    "MOV result.texcoord[1].xyz, vertex.texcoord[1];\n"
    "END\n"
};

int Rendering::LightDirPerPixEffect::msAllPRegisters[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int* Rendering::LightDirPerPixEffect::msPRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]{
    0,
    msAllPRegisters,
    msAllPRegisters,
    msAllPRegisters,
    msAllPRegisters
};

std::string Rendering::LightDirPerPixEffect::msPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]{
    // PP_NONE
    "",

    // PP_PS_1_1
    "",

    // PP_PS_2_0
    "ps_2_0\n"
    "def c10, 0.00000000, 0, 0, 0\n"
    "dcl t1.xyz\n"
    "dcl t0.xyz\n"
    "add r1.xyz, -t0, c0\n"
    "dp3 r0.x, r1, r1\n"
    "rsq r0.x, r0.x\n"
    "mad r2.xyz, r0.x, r1, -c5\n"
    "dp3 r1.x, r2, r2\n"
    "dp3 r0.x, t1, t1\n"
    "rsq r1.x, r1.x\n"
    "mul r1.xyz, r1.x, r2\n"
    "rsq r0.x, r0.x\n"
    "mul r2.xyz, r0.x, t1\n"
    "dp3 r0.x, r2, r1\n"
    "max r0.x, r0, c10\n"
    "pow r1, r0.x, c4.w\n"
    "dp3 r0.x, r2, c5\n"
    "max r2.x, -r0, c10\n"
    "cmp r0.x, r0, c10, r1\n"
    "mul r2.xyz, r2.x, c3\n"
    "mul r2.xyz, r2, c7\n"
    "mov r1.xyz, c2\n"
    "mad r1.xyz, c6, r1, r2\n"
    "mul r0.xyz, r0.x, c4\n"
    "mad r0.xyz, r0, c8, r1\n"
    "mul r0.xyz, r0, c9.w\n"
    "add r0.xyz, r0, c1\n"
    "mov r0.w, c3\n"
    "mov oC0, r0\n",

    // PP_PS_3_0
    "ps_3_0\n"
    "def c10, 0.00000000, 0, 0, 0\n"
    "dcl_texcoord1 v1.xyz\n"
    "dcl_texcoord0 v0.xyz\n"
    "add r0.xyz, -v0, c0\n"
    "dp3 r0.w, r0, r0\n"
    "rsq r0.w, r0.w\n"
    "mad r0.xyz, r0.w, r0, -c5\n"
    "dp3 r1.x, r0, r0\n"
    "rsq r1.x, r1.x\n"
    "dp3 r0.w, v1, v1\n"
    "mul r0.xyz, r1.x, r0\n"
    "rsq r0.w, r0.w\n"
    "mul r1.xyz, r0.w, v1\n"
    "dp3 r0.x, r1, r0\n"
    "max r1.w, r0.x, c10.x\n"
    "pow r0, r1.w, c4.w\n"
    "dp3 r0.w, r1, c5\n"
    "mov r1.x, r0\n"
    "max r0.y, -r0.w, c10.x\n"
    "mul r0.xyz, r0.y, c3\n"
    "cmp r0.w, r0, c10.x, r1.x\n"
    "mul r1.xyz, r0, c7\n"
    "mov r0.xyz, c2\n"
    "mad r0.xyz, c6, r0, r1\n"
    "mul r1.xyz, r0.w, c4\n"
    "mad r0.xyz, r1, c8, r0\n"
    "mul r0.xyz, r0, c9.w\n"
    "add oC0.xyz, r0, c1\n"
    "mov oC0.w, c3\n",

    // PP_ARBFP1
    "!!ARBfp1.0\n"
    "PARAM c[10] = { program.local[0..9] };\n"
    "TEMP R0;\n"
    "TEMP R1;\n"
    "ADD R1.xyz, -fragment.texcoord[0], c[0];\n"
    "DP3 R0.x, R1, R1;\n"
    "RSQ R0.x, R0.x;\n"
    "MAD R0.xyz, R0.x, R1, -c[5];\n"
    "DP3 R0.w, R0, R0;\n"
    "RSQ R0.w, R0.w;\n"
    "DP3 R1.x, fragment.texcoord[1], fragment.texcoord[1];\n"
    "RSQ R1.x, R1.x;\n"
    "MUL R0.xyz, R0.w, R0;\n"
    "MUL R1.xyz, R1.x, fragment.texcoord[1];\n"
    "DP3 R0.y, R1, R0;\n"
    "DP3 R0.x, R1, c[5];\n"
    "MOV R0.x, -R0;\n"
    "MOV R0.z, c[4].w;\n"
    "LIT R0.yz, R0.xyzz;\n"
    "MUL R1.xyz, R0.y, c[3];\n"
    "MOV R0.xyw, c[6].xyzz;\n"
    "MUL R1.xyz, R1, c[7];\n"
    "MAD R1.xyz, R0.xyww, c[2], R1;\n"
    "MUL R0.xyz, R0.z, c[4];\n"
    "MAD R0.xyz, R0, c[8], R1;\n"
    "MUL R0.xyz, R0, c[9].w;\n"
    "ADD result.color.xyz, R0, c[1];\n"
    "MOV result.color.w, c[3];\n"
    "END\n"
};

#include STSTEM_WARNING_POP