///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:44)

#include "Rendering/RenderingExport.h"

#include "LightPntPerVerEffect.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/ShaderFloats/CameraModelPositionConstant.h"
#include "Rendering/ShaderFloats/LightAmbientConstant.h"
#include "Rendering/ShaderFloats/LightAttenuationConstant.h"
#include "Rendering/ShaderFloats/LightDiffuseConstant.h"
#include "Rendering/ShaderFloats/LightModelPositionConstant.h"
#include "Rendering/ShaderFloats/LightSpecularConstant.h"
#include "Rendering/ShaderFloats/MaterialAmbientConstant.h"
#include "Rendering/ShaderFloats/MaterialDiffuseConstant.h"
#include "Rendering/ShaderFloats/MaterialEmissiveConstant.h"
#include "Rendering/ShaderFloats/MaterialSpecularConstant.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h"
#include "Rendering/ShaderFloats/WorldMatrixConstant.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

namespace
{
    std::array<int, 12> dx9VRegisters{ 0, 4, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };

    std::array<int, 12> oglVRegisters{ 1, 5, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };

    std::array<std::array<int, 12>*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> vRegisters{
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
        "def c18, 1.00000000, 0, 0, 0\n"
        "dcl_position0 v0\n"
        "dcl_texcoord1 v1\n"
        "add r1.xyz, v0, -c13\n"
        "dp3 r0.x, r1, r1\n"
        "add r2.xyz, -v0, c8\n"
        "dp3 r0.w, r2, r2\n"
        "rsq r0.x, r0.x\n"
        "mul r0.xyz, r0.x, r1\n"
        "rsq r0.w, r0.w\n"
        "mad r2.xyz, r0.w, r2, -r0\n"
        "dp3 r0.x, v1, r0\n"
        "dp3 r0.w, r2, r2\n"
        "rsq r0.w, r0.w\n"
        "mul r2.xyz, r0.w, r2\n"
        "dp3 r0.w, v1, r2\n"
        "dp3 r2.z, r1, c6\n"
        "dp3 r2.x, r1, c4\n"
        "dp3 r2.y, r1, c5\n"
        "dp3 r1.x, r2, r2\n"
        "mov r0.x, -r0\n"
        "mov r0.y, c12.w\n"
        "lit r0.yz, r0.xwzy\n"
        "rsq r0.x, r1.x\n"
        "rcp r0.w, r0.x\n"
        "mul r1.xyz, r0.z, c12\n"
        "mul r0.xyz, r0.y, c11\n"
        "mul r2.xyz, r0, c15\n"
        "mad r1.w, r0, c17.z, c17.y\n"
        "mad r0.w, r0, r1, c17.x\n"
        "mov r0.xyz, c10\n"
        "mad r0.xyz, c14, r0, r2\n"
        "mad r1.xyz, r1, c16, r0\n"
        "rcp r0.w, r0.w\n"
        "mul r0.x, r0.w, c17.w\n"
        "mad oD0.xyz, r0.x, r1, c9\n"
        "mov r0.w, c18.x\n"
        "mov r0.xyz, v0\n"
        "dp4 oPos.w, r0, c3\n"
        "dp4 oPos.z, r0, c2\n"
        "dp4 oPos.y, r0, c1\n"
        "dp4 oPos.x, r0, c0\n"
        "mov oD0.w, c11\n",

        // VP_VS_2_0
        "vs_2_0\n"
        "def c18, 1.00000000, 0, 0, 0\n"
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
        "dp3 r0.x, v1, r0\n"
        "dp3 r0.w, r2, r2\n"
        "rsq r0.w, r0.w\n"
        "mul r2.xyz, r0.w, r2\n"
        "dp3 r0.w, v1, r2\n"
        "dp3 r2.z, r1, c6\n"
        "dp3 r2.x, r1, c4\n"
        "dp3 r2.y, r1, c5\n"
        "dp3 r1.x, r2, r2\n"
        "mov r0.x, -r0\n"
        "mov r0.y, c12.w\n"
        "lit r0.yz, r0.xwzy\n"
        "rsq r0.x, r1.x\n"
        "rcp r0.w, r0.x\n"
        "mul r1.xyz, r0.z, c12\n"
        "mul r0.xyz, r0.y, c11\n"
        "mul r2.xyz, r0, c15\n"
        "mad r1.w, r0, c17.z, c17.y\n"
        "mad r0.w, r0, r1, c17.x\n"
        "mov r0.xyz, c10\n"
        "mad r0.xyz, c14, r0, r2\n"
        "mad r1.xyz, r1, c16, r0\n"
        "rcp r0.w, r0.w\n"
        "mul r0.x, r0.w, c17.w\n"
        "mad oD0.xyz, r0.x, r1, c9\n"
        "mov r0.w, c18.x\n"
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
        "def c18, 1.00000000, 0, 0, 0\n"
        "dcl_position0 v0\n"
        "dcl_texcoord1 v1\n"
        "add r1.xyz, v0, -c13\n"
        "dp3 r0.x, r1, r1\n"
        "add r2.xyz, -v0, c8\n"
        "dp3 r0.w, r2, r2\n"
        "rsq r0.x, r0.x\n"
        "mul r0.xyz, r0.x, r1\n"
        "rsq r0.w, r0.w\n"
        "mad r2.xyz, r0.w, r2, -r0\n"
        "dp3 r0.x, v1, r0\n"
        "dp3 r0.w, r2, r2\n"
        "rsq r0.w, r0.w\n"
        "mul r2.xyz, r0.w, r2\n"
        "dp3 r0.w, v1, r2\n"
        "dp3 r2.z, r1, c6\n"
        "dp3 r2.x, r1, c4\n"
        "dp3 r2.y, r1, c5\n"
        "dp3 r1.x, r2, r2\n"
        "mov r0.x, -r0\n"
        "mov r0.y, c12.w\n"
        "lit r0.yz, r0.xwzy\n"
        "rsq r0.x, r1.x\n"
        "rcp r0.w, r0.x\n"
        "mul r1.xyz, r0.z, c12\n"
        "mul r0.xyz, r0.y, c11\n"
        "mul r2.xyz, r0, c15\n"
        "mad r1.w, r0, c17.z, c17.y\n"
        "mad r0.w, r0, r1, c17.x\n"
        "mov r0.xyz, c10\n"
        "mad r0.xyz, c14, r0, r2\n"
        "mad r1.xyz, r1, c16, r0\n"
        "rcp r0.w, r0.w\n"
        "mul r0.x, r0.w, c17.w\n"
        "mad o1.xyz, r0.x, r1, c9\n"
        "mov r0.w, c18.x\n"
        "mov r0.xyz, v0\n"
        "dp4 o0.w, r0, c3\n"
        "dp4 o0.z, r0, c2\n"
        "dp4 o0.y, r0, c1\n"
        "dp4 o0.x, r0, c0\n"
        "mov o1.w, c11\n",

        // VP_ARBVP1
        "!!ARBvp1.0\n"
        "PARAM c[19] = { { 1 }, program.local[1..18] };\n"
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
        "DP3 R0.x, vertex.texcoord[1], R0;\n"
        "DP3 R0.w, R2, R2;\n"
        "RSQ R0.w, R0.w;\n"
        "MUL R2.xyz, R0.w, R2;\n"
        "DP3 R0.w, vertex.texcoord[1], R2;\n"
        "DP3 R2.z, R1, c[7];\n"
        "DP3 R2.x, R1, c[5];\n"
        "DP3 R2.y, R1, c[6];\n"
        "DP3 R1.x, R2, R2;\n"
        "MOV R0.x, -R0;\n"
        "MOV R0.y, c[13].w;\n"
        "LIT R0.yz, R0.xwzy;\n"
        "RSQ R0.x, R1.x;\n"
        "RCP R0.w, R0.x;\n"
        "MUL R1.xyz, R0.z, c[13];\n"
        "MUL R0.xyz, R0.y, c[12];\n"
        "MUL R2.xyz, R0, c[16];\n"
        "MAD R1.w, R0, c[18].z, c[18].y;\n"
        "MAD R0.w, R0, R1, c[18].x;\n"
        "MOV R0.xyz, c[15];\n"
        "MAD R0.xyz, R0, c[11], R2;\n"
        "MAD R1.xyz, R1, c[17], R0;\n"
        "RCP R0.w, R0.w;\n"
        "MUL R0.x, R0.w, c[18].w;\n"
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

        // PP_PS_ARB
        "!!ARBfp1.0\n"
        "MOV result.color, fragment.color.primary;\n"
        "END\n"
    };
}

CORE_TOOLS_RTTI_DEFINE(Rendering, LightPntPerVerEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, LightPntPerVerEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, LightPntPerVerEffect);

CLASS_INVARIANT_STUB_DEFINE(Rendering, LightPntPerVerEffect)

Rendering::LightPntPerVerEffect::LightPntPerVerEffect(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::LightPntPerVerEffect::LightPntPerVerEffect(LoadConstructor value)
    : VisualEffect{ value }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::LightPntPerVerEffect::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::LightPntPerVerEffect::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    VisualEffect::Link(source);
}

void Rendering::LightPntPerVerEffect::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    VisualEffect::PostLink();
}

int64_t Rendering::LightPntPerVerEffect::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return VisualEffect::Register(target);
}

void Rendering::LightPntPerVerEffect::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::LightPntPerVerEffect::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return VisualEffect::GetStreamingSize();
}
