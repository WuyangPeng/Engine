///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/14 10:39)

#include "Rendering/RenderingExport.h"

#include "DefaultEffect.h"
#include "System/Helper/PragmaWarning.h"
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
        "mov r0.w, c4.x\n"
        "mov r0.xyz, v0\n"
        "dp4 oPos.w, r0, c3\n"
        "dp4 oPos.z, r0, c2\n"
        "dp4 oPos.y, r0, c1\n"
        "dp4 oPos.x, r0, c0\n",

        // VP_VS_2_0
        "vs_2_0\n"
        "def c4, 1.00000000, 0, 0, 0\n"
        "dcl_position0 v0\n"
        "mov r0.w, c4.x\n"
        "mov r0.xyz, v0\n"
        "dp4 oPos.w, r0, c3\n"
        "dp4 oPos.z, r0, c2\n"
        "dp4 oPos.y, r0, c1\n"
        "dp4 oPos.x, r0, c0\n",

        // VP_VS_3_0
        "vs_3_0\n"
        "dcl_position o0\n"
        "def c4, 1.00000000, 0, 0, 0\n"
        "dcl_position0 v0\n"
        "mov r0.w, c4.x\n"
        "mov r0.xyz, v0\n"
        "dp4 o0.w, r0, c3\n"
        "dp4 o0.z, r0, c2\n"
        "dp4 o0.y, r0, c1\n"
        "dp4 o0.x, r0, c0\n",

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
        "END\n"
    };

    std::array<std::string, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> pPrograms{
        // PP_NONE
        "",

        // PP_PS_1_1
        "ps.1.1\n"
        "def c0, 1.000000, 0.000000, 1.000000, 1.000000\n"
        "mov r0, c0\n",

        // PP_PS_2_0
        "ps_2_0\n"
        "def c0, 1.00000000, 0.00000000, 0, 0\n"
        "mov r0.y, c0\n"
        "mov r0.xzw, c0.x\n"
        "mov oC0, r0\n",

        // PP_PS_3_0
        "ps_3_0\n"
        "def c0, 1.00000000, 0.00000000, 0, 0\n"
        "mov oC0, c0.xyxx\n",

        // PP_ARBFP1
        "!!ARBfp1.0\n"
        "PARAM c[1] = { { 1, 0 } };\n"
        "MOV result.color, c[0].xyxx;\n"
        "END\n"
    };
}

CORE_TOOLS_RTTI_DEFINE(Rendering, DefaultEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, DefaultEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, DefaultEffect);

Rendering::DefaultEffect::DefaultEffect(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }
{
    auto vshader = std::make_shared<VertexShader>("Default", 1, 1, 1, 0);
    vshader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::Position);
    vshader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float, ShaderFlags::VariableSemantic::Position);
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

    auto pshader = std::make_shared<PixelShader>("Default", 1, 1, 0, 0);
    pshader->SetInput(0, "vertexTCoord", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
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
    InsertTechnique(technique);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, DefaultEffect)

Rendering::VisualEffectInstanceSharedPtr Rendering::DefaultEffect::CreateInstance()
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto instance = std::make_shared<VisualEffectInstance>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), 0);

    instance->SetVertexConstant(0, 0, std::make_shared<ProjectionViewMatrixConstant>(CoreTools::DisableNotThrow::Disable));

    return instance;
}

Rendering::DefaultEffect::DefaultEffect(LoadConstructor value)
    : ParentType{ value }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::DefaultEffect::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::DefaultEffect::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::DefaultEffect::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();

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
        profile->SetProgram(i, pPrograms.at(i));
    }
}

uint64_t Rendering::DefaultEffect::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::DefaultEffect::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::DefaultEffect::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize();
}

CoreTools::ObjectInterfaceSharedPtr Rendering::DefaultEffect::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
