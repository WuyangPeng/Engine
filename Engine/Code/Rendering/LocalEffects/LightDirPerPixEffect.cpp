///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:44)

#include "Rendering/RenderingExport.h"

#include "LightDirPerPixEffect.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
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

    std::array<int, 10> allPRegisters{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::array<std::array<int, 10>*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> pRegisters{
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
}

CORE_TOOLS_RTTI_DEFINE(Rendering, LightDirPerPixEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightDirPerPixEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightDirPerPixEffect);

Rendering::LightDirPerPixEffect::LightDirPerPixEffect(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }
{
    auto vshader = std::make_shared<VertexShader>("LightDirPerPix", 2, 3, 1, 0);
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

    auto pshader = std::make_shared<PixelShader>("LightDirPerPix", 2, 1, 10, 0);
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

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, LightDirPerPixEffect)

Rendering::VisualEffectInstanceSharedPtr Rendering::LightDirPerPixEffect::CreateInstance(const LightSharedPtr& light, const MaterialSharedPtr& material)
{
    RENDERING_CLASS_IS_VALID_9;

    auto instance = std::make_shared<VisualEffectInstance>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), 0);
    instance->SetVertexConstant(0, 0, std::make_shared<ProjectionViewMatrixConstant>(CoreTools::DisableNotThrow::Disable));
    instance->SetPixelConstant(0, 0, std::make_shared<CameraModelPositionConstant>(CoreTools::DisableNotThrow::Disable));
    instance->SetPixelConstant(0, 1, std::make_shared<MaterialEmissiveConstant>(material));
    instance->SetPixelConstant(0, 2, std::make_shared<MaterialAmbientConstant>(material));
    instance->SetPixelConstant(0, 3, std::make_shared<MaterialDiffuseConstant>(material));
    instance->SetPixelConstant(0, 4, std::make_shared<MaterialSpecularConstant>(material));
    instance->SetPixelConstant(0, 5, std::make_shared<LightModelDirectionVectorConstant>(light));
    instance->SetPixelConstant(0, 6, std::make_shared<LightAmbientConstant>(light));
    instance->SetPixelConstant(0, 7, std::make_shared<LightDiffuseConstant>(light));
    instance->SetPixelConstant(0, 8, std::make_shared<LightSpecularConstant>(light));
    instance->SetPixelConstant(0, 9, std::make_shared<LightAttenuationConstant>(light));

    return instance;
}

Rendering::VisualEffectInstanceSharedPtr Rendering::LightDirPerPixEffect::CreateUniqueInstance(const LightSharedPtr& light, const MaterialSharedPtr& material)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto effect = std::make_shared<LightDirPerPixEffect>(CoreTools::DisableNotThrow::Disable);

#include STSTEM_WARNING_POP

    return effect->CreateInstance(light, material);
}

Rendering::LightDirPerPixEffect::LightDirPerPixEffect(LoadConstructor value)
    : VisualEffect{ value }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::LightDirPerPixEffect::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::LightDirPerPixEffect::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    VisualEffect::Link(source);
}

void Rendering::LightDirPerPixEffect::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    VisualEffect::PostLink();
}

int64_t Rendering::LightDirPerPixEffect::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return VisualEffect::Register(target);
}

void Rendering::LightDirPerPixEffect::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::LightDirPerPixEffect::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return VisualEffect::GetStreamingSize();
}
