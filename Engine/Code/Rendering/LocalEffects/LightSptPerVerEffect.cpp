///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/14 14:37)

#include "Rendering/RenderingExport.h"

#include "LightSptPerVerEffect.h"
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
#include "Rendering/ShaderFloats/LightSpotConstant.h"
#include "Rendering/ShaderFloats/MaterialAmbientConstant.h"
#include "Rendering/ShaderFloats/MaterialDiffuseConstant.h"
#include "Rendering/ShaderFloats/MaterialEmissiveConstant.h"
#include "Rendering/ShaderFloats/MaterialSpecularConstant.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h"
#include "Rendering/ShaderFloats/WorldMatrixConstant.h"

namespace
{
    std::array<int, 14> dx9VRegisters{ 0, 4, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

    std::array<int, 14> oglVRegisters{ 1, 5, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

    std::array<std::array<int, 14>*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> vRegisters{
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
        "def c20, 1.00000000, 0.00000000, 0, 0\n"
        "dcl_position0 v0\n"
        "dcl_texcoord1 v1\n"
        "add r0.xyz, v0, -c13\n"
        "dp3 r0.w, r0, r0\n"
        "add r2.xyz, -v0, c8\n"
        "rsq r0.w, r0.w\n"
        "mul r1.xyz, r0.w, r0\n"
        "dp3 r1.w, r2, r2\n"
        "rsq r0.w, r1.w\n"
        "mad r2.xyz, r0.w, r2, -r1\n"
        "dp3 r3.xy, r1, c14\n"
        "dp3 r0.w, r2, r2\n"
        "rsq r0.w, r0.w\n"
        "mul r2.xyz, r0.w, r2\n"
        "dp3 r2.y, v1, r2\n"
        "dp3 r1.x, r1, v1\n"
        "sge r0.w, r3.x, c18.y\n"
        "sge r1.w, c20.y, r0\n"
        "sge r0.w, r0, c20.y\n"
        "mul r0.w, r0, r1\n"
        "max r0.w, -r0, r0\n"
        "slt r0.w, c20.y, r0\n"
        "mov r2.x, -r1\n"
        "mov r2.z, c12.w\n"
        "lit r1.yz, r2.xyzz\n"
        "mov r3.z, c18.w\n"
        "lit r2.z, r3.xyzz\n"
        "mov r1.w, r2.z\n"
        "add r0.w, -r0, c20.x\n"
        "mul r1.xyz, r0.w, r1.yzww\n"
        "dp3 r2.z, r0, c6\n"
        "dp3 r2.x, r0, c4\n"
        "dp3 r2.y, r0, c5\n"
        "dp3 r0.w, r2, r2\n"
        "mul r2.xyz, r1.y, c12\n"
        "rsq r0.w, r0.w\n"
        "mul r0.xyz, r1.x, c11\n"
        "rcp r0.w, r0.w\n"
        "mad r1.x, r0.w, c19.z, c19.y\n"
        "mad r0.w, r0, r1.x, c19.x\n"
        "mul r2.xyz, r2, c17\n"
        "mad r0.xyz, r0, c16, r2\n"
        "mul r0.xyz, r1.z, r0\n"
        "mov r1.xyz, c10\n"
        "mad r1.xyz, c15, r1, r0\n"
        "rcp r0.w, r0.w\n"
        "mul r0.x, r0.w, c19.w\n"
        "mad oD0.xyz, r0.x, r1, c9\n"
        "mov r0.w, c20.x\n"
        "mov r0.xyz, v0\n"
        "dp4 oPos.w, r0, c3\n"
        "dp4 oPos.z, r0, c2\n"
        "dp4 oPos.y, r0, c1\n"
        "dp4 oPos.x, r0, c0\n"
        "mov oD0.w, c11\n",

        // VP_VS_2_0
        "vs_2_0\n"
        "def c20, 1.00000000, 0.00000000, 0, 0\n"
        "dcl_position v0\n"
        "dcl_texcoord1 v1\n"
        "add r1.xyz, v0, -c13\n"
        "dp3 r0.x, r1, r1\n"
        "add r2.xyz, -v0, c8\n"
        "dp3 r0.w, r2, r2\n"
        "rsq r0.x, r0.x\n"
        "mul r0.xyz, r0.x, r1\n"
        "rsq r0.w, r0.w\n"
        "mad r2.xyz, r0.w, r2, -r0\n"
        "dp3 r1.w, r0, c14\n"
        "dp3 r0.w, r2, r2\n"
        "rsq r0.w, r0.w\n"
        "mul r2.xyz, r0.w, r2\n"
        "dp3 r2.y, v1, r2\n"
        "sge r0.w, r1, c18.y\n"
        "sge r2.x, c20.y, r0.w\n"
        "sge r0.w, r0, c20.y\n"
        "mul r0.w, r0, r2.x\n"
        "dp3 r0.x, r0, v1\n"
        "mov r2.x, -r0\n"
        "mov r2.z, c12.w\n"
        "lit r2.yz, r2.xyzz\n"
        "max r2.x, -r0.w, r0.w\n"
        "pow r0, r1.w, c18.w\n"
        "slt r0.x, c20.y, r2\n"
        "dp3 r2.x, r1, c4\n"
        "mov r2.w, r0\n"
        "add r0.x, -r0, c20\n"
        "mul r0.xyz, r0.x, r2.yzww\n"
        "dp3 r2.z, r1, c6\n"
        "dp3 r2.y, r1, c5\n"
        "dp3 r0.w, r2, r2\n"
        "mul r1.xyz, r0.x, c11\n"
        "rsq r0.x, r0.w\n"
        "mul r2.xyz, r0.y, c12\n"
        "rcp r0.x, r0.x\n"
        "mad r0.y, r0.x, c19.z, c19\n"
        "mad r0.w, r0.x, r0.y, c19.x\n"
        "mul r2.xyz, r2, c17\n"
        "mad r1.xyz, r1, c16, r2\n"
        "mul r0.xyz, r0.z, r1\n"
        "mov r1.xyz, c10\n"
        "mad r1.xyz, c15, r1, r0\n"
        "rcp r0.w, r0.w\n"
        "mul r0.x, r0.w, c19.w\n"
        "mad oD0.xyz, r0.x, r1, c9\n"
        "mov r0.w, c20.x\n"
        "mov r0.xyz, v0\n"
        "dp4 oPos.w, r0, c3\n"
        "dp4 oPos.z, r0, c2\n"
        "dp4 oPos.y, r0, c1\n"
        "dp4 oPos.x, r0, c0\n"
        "mov oD0.w, c11\n",

        // VP_VS_3_0
        "vs_3_0\n"
        "dcl_position o0\n"
        "dcl_color0 o1\n"
        "def c20, 1.00000000, 0.00000000, 0, 0\n"
        "dcl_position0 v0\n"
        "dcl_texcoord1 v1\n"
        "add r1.xyz, v0, -c13\n"
        "dp3 r1.w, r1, r1\n"
        "rsq r1.w, r1.w\n"
        "mul r2.xyz, r1.w, r1\n"
        "mov r0.xyz, v0\n"
        "mov r0.w, c20.x\n"
        "dp4 o0.w, r0, c3\n"
        "dp4 o0.z, r0, c2\n"
        "dp4 o0.y, r0, c1\n"
        "dp3 r1.w, r2, c14\n"
        "dp4 o0.x, r0, c0\n"
        "if_ge r1.w, c18.y\n"
        "add r0.xyz, -v0, c8\n"
        "dp3 r0.w, r0, r0\n"
        "rsq r0.w, r0.w\n"
        "mad r0.xyz, r0.w, r0, -r2\n"
        "dp3 r0.w, r0, r0\n"
        "rsq r0.w, r0.w\n"
        "mul r3.xyz, r0.w, r0\n"
        "pow r0, r1.w, c18.w\n"
        "dp3 r0.y, v1, r3\n"
        "dp3 r0.x, v1, r2\n"
        "mov r0.z, c12.w\n"
        "mov r0.x, -r0\n"
        "lit r0.yz, r0.xyzz\n"
        "else\n"
        "mov r0.yzw, c20.y\n"
        "endif\n"
        "dp3 r2.z, r1, c6\n"
        "dp3 r2.x, r1, c4\n"
        "dp3 r2.y, r1, c5\n"
        "dp3 r0.x, r2, r2\n"
        "rsq r0.x, r0.x\n"
        "rcp r1.w, r0.x\n"
        "mul r1.xyz, r0.z, c12\n"
        "mad r2.x, r1.w, c19.z, c19.y\n"
        "mul r0.xyz, r0.y, c11\n"
        "mul r1.xyz, r1, c17\n"
        "mad r1.xyz, r0, c16, r1\n"
        "mad r0.x, r1.w, r2, c19\n"
        "mul r2.xyz, r0.w, r1\n"
        "rcp r0.x, r0.x\n"
        "mov r1.xyz, c10\n"
        "mad r1.xyz, c15, r1, r2\n"
        "mul r0.x, r0, c19.w\n"
        "mad o1.xyz, r0.x, r1, c9\n"
        "mov o1.w, c11\n",

        // VP_ARBVP1
        "!!ARBvp1.0\n"
        "PARAM c[21] = { { 1, 0 }, program.local[1..20] };\n"
        "TEMP R0;\n"
        "TEMP R1;\n"
        "TEMP R2;\n"
        "ADD R1.xyz, vertex.position, -c[14];\n"
        "DP3 R0.x, R1, R1;\n"
        "ADD R2.xyz, -vertex.position, c[9];\n"
        "DP3 R0.w, R2, R2;\n"
        "RSQ R0.x, R0.x;\n"
        "MUL R0.xyz, R0.x, R1;\n"
        "RSQ R0.w, R0.w;\n"
        "MAD R2.xyz, R0.w, R2, -R0;\n"
        "DP3 R0.w, R2, R2;\n"
        "RSQ R1.w, R0.w;\n"
        "MUL R2.xyz, R1.w, R2;\n"
        "DP3 R0.w, R0, c[15];\n"
        "SGE R1.w, R0, c[19].y;\n"
        "DP3 R2.y, vertex.texcoord[1], R2;\n"
        "DP3 R0.x, R0, vertex.texcoord[1];\n"
        "MOV R2.x, -R0;\n"
        "MOV R2.z, c[13].w;\n"
        "LIT R0.yz, R2.xyzz;\n"
        "ABS R1.w, R1;\n"
        "DP3 R2.z, R1, c[7];\n"
        "DP3 R2.x, R1, c[5];\n"
        "DP3 R2.y, R1, c[6];\n"
        "POW R0.w, R0.w, c[19].w;\n"
        "SGE R0.x, c[0].y, R1.w;\n"
        "MAD R0.xyz, -R0.yzww, R0.x, R0.yzww;\n"
        "DP3 R0.w, R2, R2;\n"
        "MUL R1.xyz, R0.x, c[12];\n"
        "RSQ R0.x, R0.w;\n"
        "MUL R2.xyz, R0.y, c[13];\n"
        "RCP R0.x, R0.x;\n"
        "MAD R0.y, R0.x, c[20].z, c[20];\n"
        "MAD R0.w, R0.x, R0.y, c[20].x;\n"
        "MUL R2.xyz, R2, c[18];\n"
        "MAD R1.xyz, R1, c[17], R2;\n"
        "MUL R0.xyz, R0.z, R1;\n"
        "MOV R1.xyz, c[16];\n"
        "MAD R1.xyz, R1, c[11], R0;\n"
        "RCP R0.w, R0.w;\n"
        "MUL R0.x, R0.w, c[20].w;\n"
        "MAD result.color.xyz, R0.x, R1, c[10];\n"
        "MOV R0.w, c[0].x;\n"
        "MOV R0.xyz, vertex.position;\n"
        "DP4 result.position.w, R0, c[4];\n"
        "DP4 result.position.z, R0, c[3];\n"
        "DP4 result.position.y, R0, c[2];\n"
        "DP4 result.position.x, R0, c[1];\n"
        "MOV result.color.w, c[12];\n"
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

CORE_TOOLS_RTTI_DEFINE(Rendering, LightSptPerVerEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightSptPerVerEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightSptPerVerEffect);

CLASS_INVARIANT_STUB_DEFINE(Rendering, LightSptPerVerEffect)

Rendering::LightSptPerVerEffect::LightSptPerVerEffect(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }
{
    auto vshader = std::make_shared<VertexShader>("LightSptPerVer", 2, 2, 14, 0);

    vshader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::Position);
    vshader->SetInput(1, "modelNormal", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::TextureCoord1);
    vshader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(1, "vertexColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    vshader->SetConstant(0, "PVWMatrix", 4);
    vshader->SetConstant(1, "WMatrix", 4);
    vshader->SetConstant(2, "CameraModelPosition", 1);
    vshader->SetConstant(3, "MaterialEmissive", 1);
    vshader->SetConstant(4, "MaterialAmbient", 1);
    vshader->SetConstant(5, "MaterialDiffuse", 1);
    vshader->SetConstant(6, "MaterialSpecular", 1);
    vshader->SetConstant(7, "LightModelPosition", 1);
    vshader->SetConstant(8, "LightModelDirection", 1);
    vshader->SetConstant(9, "LightAmbient", 1);
    vshader->SetConstant(10, "LightDiffuse", 1);
    vshader->SetConstant(11, "LightSpecular", 1);
    vshader->SetConstant(12, "LightSpotCutoff", 1);
    vshader->SetConstant(13, "LightAttenuation", 1);

    auto profile = vshader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 14; ++j)
        {
            profile->SetBaseRegister(i, j, vRegisters.at(i)->at(j));
        }

        profile->SetProgram(i, vPrograms.at(i));
    }

    auto pshader = std::make_shared<PixelShader>("LightSptPerVer", 1, 1, 0, 0);
    pshader->SetInput(0, "vertexColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
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

Rendering::VisualEffectInstanceSharedPtr Rendering::LightSptPerVerEffect::CreateInstance(const LightSharedPtr& light, const MaterialSharedPtr& material)
{
    RENDERING_CLASS_IS_VALID_9;

    auto instance = std::make_shared<VisualEffectInstance>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), 0);

    instance->SetVertexConstant(0, 0, std::make_shared<ProjectionViewMatrixConstant>(CoreTools::DisableNotThrow::Disable));
    instance->SetVertexConstant(0, 1, std::make_shared<WorldMatrixConstant>(CoreTools::DisableNotThrow::Disable));
    instance->SetVertexConstant(0, 2, std::make_shared<CameraModelPositionConstant>(CoreTools::DisableNotThrow::Disable));
    instance->SetVertexConstant(0, 3, std::make_shared<MaterialEmissiveConstant>(material));
    instance->SetVertexConstant(0, 4, std::make_shared<MaterialAmbientConstant>(material));
    instance->SetVertexConstant(0, 5, std::make_shared<MaterialDiffuseConstant>(material));
    instance->SetVertexConstant(0, 6, std::make_shared<MaterialSpecularConstant>(material));
    instance->SetVertexConstant(0, 7, std::make_shared<LightModelPositionConstant>(light));
    instance->SetVertexConstant(0, 8, std::make_shared<LightModelDirectionVectorConstant>(light));
    instance->SetVertexConstant(0, 9, std::make_shared<LightAmbientConstant>(light));
    instance->SetVertexConstant(0, 10, std::make_shared<LightDiffuseConstant>(light));
    instance->SetVertexConstant(0, 11, std::make_shared<LightSpecularConstant>(light));
    instance->SetVertexConstant(0, 12, std::make_shared<LightSpotConstant>(light));
    instance->SetVertexConstant(0, 13, std::make_shared<LightAttenuationConstant>(light));

    return instance;
}

Rendering::VisualEffectInstanceSharedPtr Rendering::LightSptPerVerEffect::CreateUniqueInstance(const LightSharedPtr& light, const MaterialSharedPtr& material)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto effect = std::make_shared<ClassType>(CoreTools::DisableNotThrow::Disable);

#include STSTEM_WARNING_POP

    return effect->CreateInstance(light, material);
}

Rendering::LightSptPerVerEffect::LightSptPerVerEffect(LoadConstructor value)
    : VisualEffect{ value }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::LightSptPerVerEffect::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::LightSptPerVerEffect::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    VisualEffect::Link(source);
}

void Rendering::LightSptPerVerEffect::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    VisualEffect::PostLink();
}

int64_t Rendering::LightSptPerVerEffect::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return VisualEffect::Register(target);
}

void Rendering::LightSptPerVerEffect::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::LightSptPerVerEffect::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return VisualEffect::GetStreamingSize();
}
