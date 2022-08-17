///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/14 14:18)

#include "Rendering/RenderingExport.h"

#include "LightPntPerPixEffect.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/ShaderFloats/CameraModelPositionConstant.h"
#include "Rendering/ShaderFloats/LightAmbientConstant.h"
#include "Rendering/ShaderFloats/LightAttenuationConstant.h"
#include "Rendering/ShaderFloats/LightDiffuseConstant.h"
#include "Rendering/ShaderFloats/LightModelDirectionVectorConstant.h"
#include "Rendering/ShaderFloats/LightModelPositionConstant.h"
#include "Rendering/ShaderFloats/LightSpecularConstant.h"
#include "Rendering/ShaderFloats/MaterialAmbientConstant.h"
#include "Rendering/ShaderFloats/MaterialDiffuseConstant.h"
#include "Rendering/ShaderFloats/MaterialEmissiveConstant.h"
#include "Rendering/ShaderFloats/MaterialSpecularConstant.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h"
#include "Rendering/ShaderFloats/WorldMatrixConstant.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, LightPntPerPixEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightPntPerPixEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightPntPerPixEffect);

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

    std::array<int, 11> allPRegisters{ 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

    std::array<std::array<int, 11>*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> pRegisters{
        nullptr,
        &allPRegisters,
        &allPRegisters,
        &allPRegisters,
        &allPRegisters
    };

    std::array<std::string, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> pPrograms{
        // PP_NONE
        "",

        // PP_PS_1_1
        "",

        // PP_PS_2_0
        "ps_2_0\n"
        "def c14, 0.00000000, 0, 0, 0\n"
        "dcl t1.xyz\n"
        "dcl t0.xyz\n"
        "add r2.xyz, t0, -c9\n"
        "dp3 r0.x, r2, r2\n"
        "rsq r3.x, r0.x\n"
        "add r1.xyz, -t0, c4\n"
        "dp3 r0.x, r1, r1\n"
        "mul r3.xyz, r3.x, r2\n"
        "rsq r0.x, r0.x\n"
        "mad r4.xyz, r0.x, r1, -r3\n"
        "dp3 r1.x, r4, r4\n"
        "dp3 r0.x, t1, t1\n"
        "rsq r1.x, r1.x\n"
        "mul r1.xyz, r1.x, r4\n"
        "rsq r0.x, r0.x\n"
        "mul r4.xyz, r0.x, t1\n"
        "dp3 r0.x, r4, r1\n"
        "max r0.x, r0, c14\n"
        "pow r1, r0.x, c8.w\n"
        "dp3 r0.x, r4, r3\n"
        "dp3 r3.z, r2, c2\n"
        "dp3 r3.x, r2, c0\n"
        "dp3 r3.y, r2, c1\n"
        "dp3 r2.x, r3, r3\n"
        "cmp r3.x, r0, c14, r1\n"
        "rsq r1.x, r2.x\n"
        "mul r2.xyz, r3.x, c8\n"
        "max r3.x, -r0, c14\n"
        "rcp r1.x, r1.x\n"
        "mad r0.x, r1, c13.z, c13.y\n"
        "mad r0.x, r1, r0, c13\n"
        "mul r3.xyz, r3.x, c7\n"
        "rcp r0.x, r0.x\n"
        "mul r3.xyz, r3, c11\n"
        "mov r1.xyz, c6\n"
        "mad r1.xyz, c10, r1, r3\n"
        "mad r1.xyz, r2, c12, r1\n"
        "mul r0.x, r0, c13.w\n"
        "mad r0.xyz, r0.x, r1, c5\n"
        "mov r0.w, c7\n"
        "mov oC0, r0\n",

        // PP_PS_3_0
        "ps_3_0\n"
        "def c14, 0.00000000, 0, 0, 0\n"
        "dcl_texcoord1 v1.xyz\n"
        "dcl_texcoord0 v0.xyz\n"
        "add r1.xyz, v0, -c9\n"
        "dp3 r0.w, r1, r1\n"
        "add r0.xyz, -v0, c4\n"
        "rsq r0.w, r0.w\n"
        "mul r3.xyz, r0.w, r1\n"
        "dp3 r1.w, r0, r0\n"
        "rsq r0.w, r1.w\n"
        "mad r0.xyz, r0.w, r0, -r3\n"
        "dp3 r1.w, r0, r0\n"
        "rsq r1.w, r1.w\n"
        "dp3 r0.w, v1, v1\n"
        "rsq r0.w, r0.w\n"
        "mul r0.xyz, r1.w, r0\n"
        "mul r2.xyz, r0.w, v1\n"
        "dp3 r0.x, r2, r0\n"
        "max r1.w, r0.x, c14.x\n"
        "pow r0, r1.w, c8.w\n"
        "mov r0.w, r0.x\n"
        "dp3 r1.w, r2, r3\n"
        "dp3 r0.z, r1, c2\n"
        "dp3 r0.y, r1, c1\n"
        "dp3 r0.x, r1, c0\n"
        "dp3 r0.x, r0, r0\n"
        "cmp r0.y, r1.w, c14.x, r0.w\n"
        "rsq r0.x, r0.x\n"
        "rcp r0.w, r0.x\n"
        "max r0.x, -r1.w, c14\n"
        "mul r1.xyz, r0.y, c8\n"
        "mul r0.xyz, r0.x, c7\n"
        "mul r2.xyz, r0, c11\n"
        "mov r0.xyz, c6\n"
        "mad r2.xyz, c10, r0, r2\n"
        "mad r1.w, r0, c13.z, c13.y\n"
        "mad r0.w, r0, r1, c13.x\n"
        "rcp r0.x, r0.w\n"
        "mad r1.xyz, r1, c12, r2\n"
        "mul r0.x, r0, c13.w\n"
        "mad oC0.xyz, r0.x, r1, c5\n"
        "mov oC0.w, c7\n",

        // PP_ARBFP1
        "!!ARBfp1.0\n"
        "PARAM c[14] = { program.local[0..13] };\n"
        "TEMP R0;\n"
        "TEMP R1;\n"
        "TEMP R2;\n"
        "TEMP R3;\n"
        "ADD R1.xyz, fragment.texcoord[0], -c[9];\n"
        "ADD R0.xyz, -fragment.texcoord[0], c[4];\n"
        "DP3 R0.w, R1, R1;\n"
        "RSQ R0.w, R0.w;\n"
        "DP3 R1.w, R0, R0;\n"
        "MUL R2.xyz, R0.w, R1;\n"
        "RSQ R0.w, R1.w;\n"
        "MAD R3.xyz, R0.w, R0, -R2;\n"
        "DP3 R0.y, R3, R3;\n"
        "RSQ R0.w, R0.y;\n"
        "DP3 R0.x, fragment.texcoord[1], fragment.texcoord[1];\n"
        "RSQ R0.x, R0.x;\n"
        "MUL R0.xyz, R0.x, fragment.texcoord[1];\n"
        "MUL R3.xyz, R0.w, R3;\n"
        "DP3 R0.w, R0, R2;\n"
        "DP3 R0.y, R0, R3;\n"
        "MOV R0.x, -R0.w;\n"
        "MOV R0.z, c[8].w;\n"
        "LIT R0.yz, R0.xyzz;\n"
        "DP3 R2.z, R1, c[2];\n"
        "DP3 R2.y, R1, c[1];\n"
        "DP3 R2.x, R1, c[0];\n"
        "DP3 R0.w, R2, R2;\n"
        "RSQ R0.x, R0.w;\n"
        "MUL R2.xyz, R0.y, c[7];\n"
        "RCP R0.x, R0.x;\n"
        "MAD R0.y, R0.x, c[13].z, c[13];\n"
        "MUL R1.xyz, R0.z, c[8];\n"
        "MAD R0.w, R0.x, R0.y, c[13].x;\n"
        "MOV R0.xyz, c[10];\n"
        "MUL R2.xyz, R2, c[11];\n"
        "MAD R2.xyz, R0, c[6], R2;\n"
        "RCP R0.x, R0.w;\n"
        "MAD R1.xyz, R1, c[12], R2;\n"
        "MUL R0.x, R0, c[13].w;\n"
        "MAD result.color.xyz, R0.x, R1, c[5];\n"
        "MOV result.color.w, c[7];\n"
        "END\n"
    };
}

Rendering::LightPntPerPixEffect::LightPntPerPixEffect(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }
{
    auto vshader = std::make_shared<VertexShader>("LightPntPerPix", 2, 3, 1, 0);
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
            profile->SetBaseRegister(i, j, *vRegisters.at(i));
        }

        profile->SetProgram(i, vPrograms.at(i));
    }

    auto pshader = std::make_shared<PixelShader>("LightPntPerPix", 2, 1, 11, 0);
    pshader->SetInput(0, "vertexPosition", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::TextureCoord0);
    pshader->SetInput(1, "vertexNormal", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::TextureCoord1);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetConstant(0, "WMatrix", 4);
    pshader->SetConstant(1, "CameraModelPosition", 1);
    pshader->SetConstant(2, "MaterialEmissive", 1);
    pshader->SetConstant(3, "MaterialAmbient", 1);
    pshader->SetConstant(4, "MaterialDiffuse", 1);
    pshader->SetConstant(5, "MaterialSpecular", 1);
    pshader->SetConstant(6, "LightModelPosition", 1);
    pshader->SetConstant(7, "LightAmbient", 1);
    pshader->SetConstant(8, "LightDiffuse", 1);
    pshader->SetConstant(9, "LightSpecular", 1);
    pshader->SetConstant(10, "LightAttenuation", 1);

    profile = pshader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 11; ++j)
        {
            profile->SetBaseRegister(i, j, (*pRegisters.at(i)).at(j));
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

CLASS_INVARIANT_STUB_DEFINE(Rendering, LightPntPerPixEffect)

Rendering::VisualEffectInstanceSharedPtr Rendering::LightPntPerPixEffect::CreateInstance(const LightSharedPtr& light, const MaterialSharedPtr& material)
{
    RENDERING_CLASS_IS_VALID_9;

    auto instance = std::make_shared<VisualEffectInstance>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), 0);

    instance->SetVertexConstant(0, 0, std::make_shared<ProjectionViewMatrixConstant>(CoreTools::DisableNotThrow::Disable));
    instance->SetPixelConstant(0, 0, std::make_shared<WorldMatrixConstant>(CoreTools::DisableNotThrow::Disable));
    instance->SetPixelConstant(0, 1, std::make_shared<CameraModelPositionConstant>(CoreTools::DisableNotThrow::Disable));
    instance->SetPixelConstant(0, 2, std::make_shared<MaterialEmissiveConstant>(material));
    instance->SetPixelConstant(0, 3, std::make_shared<MaterialAmbientConstant>(material));
    instance->SetPixelConstant(0, 4, std::make_shared<MaterialDiffuseConstant>(material));
    instance->SetPixelConstant(0, 5, std::make_shared<MaterialSpecularConstant>(material));
    instance->SetPixelConstant(0, 6, std::make_shared<LightModelPositionConstant>(light));
    instance->SetPixelConstant(0, 7, std::make_shared<LightAmbientConstant>(light));
    instance->SetPixelConstant(0, 8, std::make_shared<LightDiffuseConstant>(light));
    instance->SetPixelConstant(0, 9, std::make_shared<LightSpecularConstant>(light));
    instance->SetPixelConstant(0, 10, std::make_shared<LightAttenuationConstant>(light));

    return instance;
}

Rendering::VisualEffectInstanceSharedPtr Rendering::LightPntPerPixEffect::CreateUniqueInstance(const LightSharedPtr& light, const MaterialSharedPtr& material)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto effect = std::make_shared<ClassType>(CoreTools::DisableNotThrow::Disable);

#include STSTEM_WARNING_POP

    return effect->CreateInstance(light, material);
}

Rendering::LightPntPerPixEffect::LightPntPerPixEffect(LoadConstructor value)
    : VisualEffect{ value }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::LightPntPerPixEffect::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::LightPntPerPixEffect::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    VisualEffect::Link(source);
}

void Rendering::LightPntPerPixEffect::PostLink()
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
            profile->SetBaseRegister(i, j, (*vRegisters.at(i)));
        }

        profile->SetProgram(i, vPrograms.at(i));
    }

    profile = clonePShader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 11; ++j)
        {
            profile->SetBaseRegister(i, j, (*pRegisters.at(i)).at(j));
        }

        profile->SetProgram(i, pPrograms.at(i));
    }
}

int64_t Rendering::LightPntPerPixEffect::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return VisualEffect::Register(target);
}

void Rendering::LightPntPerPixEffect::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::LightPntPerPixEffect::GetStreamingSize() const
{
    return VisualEffect::GetStreamingSize();
}
