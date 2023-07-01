///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:45)

#include "Rendering/RenderingExport.h"

#include "Texture2ColorBlendEffect.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

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
        "mov_sat r0, t0\n"
        "mad r0, 1-r0, t1, t0\n",

        // PP_PS_2_0
        "ps_2_0\n"
        "dcl_2d s0\n"
        "dcl_2d s1\n"
        "def c0, 1.00000000, 0, 0, 0\n"
        "dcl t0.xy\n"
        "dcl t1.xy\n"
        "texld r1, t0, s0\n"
        "texld r0, t1, s1\n"
        "add r2, -r1, c0.x\n"
        "mad r0, r2, r0, r1\n"
        "mov oC0, r0\n",

        // PP_PS_3_0
        "ps_3_0\n"
        "dcl_2d s0\n"
        "dcl_2d s1\n"
        "def c0, 1.00000000, 0, 0, 0\n"
        "dcl_texcoord0 v0.xy\n"
        "dcl_texcoord1 v1.xy\n"
        "texld r0, v0, s0\n"
        "texld r1, v1, s1\n"
        "add r2, -r0, c0.x\n"
        "mad oC0, r2, r1, r0\n",

        // PP_ARBFP1
        "!!ARBfp1.0\n"
        "PARAM c[1] = { { 1 } };\n"
        "TEMP R0;\n"
        "TEMP R1;\n"
        "TEMP R2;\n"
        "TEX R0, fragment.texcoord[0], texture[0], 2D;\n"
        "TEX R1, fragment.texcoord[1], texture[1], 2D;\n"
        "ADD R2, -R0, c[0].x;\n"
        "MAD result.color, R2, R1, R0;\n"
        "END\n"
    };
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Texture2ColorBlendEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture2ColorBlendEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture2ColorBlendEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture2ColorBlendEffect);

Rendering::Texture2ColorBlendEffect::Texture2ColorBlendEffect(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture2ColorBlendEffect::Texture2ColorBlendEffect(LoadConstructor value)
    : VisualEffect{ value }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::Texture2ColorBlendEffect::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    VisualEffect::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::Texture2ColorBlendEffect::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    VisualEffect::Link(source);
}

void Rendering::Texture2ColorBlendEffect::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    VisualEffect::PostLink();
}

int64_t Rendering::Texture2ColorBlendEffect::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return VisualEffect::Register(target);
}

void Rendering::Texture2ColorBlendEffect::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    VisualEffect::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::Texture2ColorBlendEffect::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return VisualEffect::GetStreamingSize();
}
