///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:45)

#include "Rendering/RenderingExport.h"

#include "ImageProcessing2.h"
#include "System/Helper/PragmaWarning.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"

Rendering::ImageProcessing2::ImageProcessing2(int bound0, int bound1, const std::vector<Mathematics::Float4>& imageData, const PixelShaderSharedPtr& mainPShader, bool useDirichlet)
    : ParentType{ bound0, bound1, 2 },
      bound0{ bound0 },
      bound1{ bound1 },
      bound0M1{ bound0 - 1 },
      bound1M1{ bound1 - 1 },
      dx{ 1.0f / bound0M1 },
      dy{ 1.0f / bound1M1 }
{
    VisualEffectSharedPtr effect{ nullptr };
    VisualEffectInstanceSharedPtr instance{ nullptr };

    SetMainTexture(CreateImage(imageData));

    CreateEffect(mainPShader, effect, instance);
    SetMainEffect(effect);
    SetMainEffectInstance(instance);
    instance->SetPixelTexture(0, "StateSampler", GetColorTexture(1));

    if (useDirichlet)
    {
        CreateBoundaryDirichletEffect(effect, instance);
    }
    else
    {
        CreateBoundaryNeumannEffect(effect, instance);
    }
    SetBoundaryEffect(effect);
    SetBoundaryEffectInstance(instance);

    instance->SetPixelTexture(0, "StateSampler", GetColorTexture(0));

    CreateDrawEffect(effect, instance);
    SetDrawEffect(effect);
    SetDrawEffectInstance(instance);

    instance->SetPixelTexture(0, "StateSampler", GetColorTexture(1));

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ImageProcessing2::ImageProcessing2(int bound0, int bound1, int numTargets)
    : ParentType{ bound0, bound1, numTargets },
      bound0{ bound0 },
      bound1{ bound1 },
      bound0M1{ bound0 - 1 },
      bound1M1{ bound1 - 1 },
      dx{ 1.0f / bound0M1 },
      dy{ 1.0f / bound1M1 }
{
    bound0M1 = bound0 - 1;
    bound1M1 = bound1 - 1;
    dx = 1.0f / (float)bound0M1;
    dy = 1.0f / (float)bound1M1;

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ImageProcessing2)

Rendering::Texture2DSharedPtr Rendering::ImageProcessing2::CreateImage(MAYBE_UNUSED const std::vector<Mathematics::Float4>& imageData)
{
    RENDERING_CLASS_IS_VALID_1;

    auto reflected = std::make_shared<Texture2D>(System::EnumCastUnderlying<DataFormatType>(System::TextureInternalFormat::RGBA32F), bound0, bound1, 1);

    return reflected;
}

void Rendering::ImageProcessing2::CreateBoundaryDirichletEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance)
{
    RENDERING_CLASS_IS_VALID_1;

    auto pshader = std::make_shared<PixelShader>("BoundaryDirichlet2", 1, 1, 0, 2);

    pshader->SetInput(0, "vertexTCoord", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetSampler(0, "MaskSampler", ShaderFlags::SamplerType::Sampler2D);
    pshader->SetSampler(1, "StateSampler", ShaderFlags::SamplerType::Sampler2D);

    auto profile = pshader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 2; ++j)
        {
            profile->SetTextureUnit(i, j, dirichletPTextureUnits.at(i)->at(j));
        }

        profile->SetProgram(i, dirichletPPrograms.at(i));
    }

    CreateEffect(pshader, effect, instance);
}

void Rendering::ImageProcessing2::CreateBoundaryNeumannEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance)
{
    RENDERING_CLASS_IS_VALID_1;

    auto pshader = std::make_shared<PixelShader>("BoundaryNeumann2", 1, 1, 0, 2);

    pshader->SetInput(0, "vertexTCoord", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetSampler(0, "OffsetSampler", ShaderFlags::SamplerType::Sampler2D);
    pshader->SetSampler(1, "StateSampler", ShaderFlags::SamplerType::Sampler2D);

    auto profile = pshader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 2; ++j)
        {
            profile->SetTextureUnit(i, j, neumannPTextureUnits.at(i)->at(j));
        }

        profile->SetProgram(i, neumannPPrograms.at(i));
    }

    CreateEffect(pshader, effect, instance);
}

void Rendering::ImageProcessing2::CreateDrawEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance)
{
    RENDERING_CLASS_IS_VALID_1;

    auto pshader = std::make_shared<PixelShader>("DrawImage2", 1, 1, 0, 1);

    pshader->SetInput(0, "vertexTCoord", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetSampler(0, "StateSampler", ShaderFlags::SamplerType::Sampler2D);

    auto profile = pshader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 2; ++j)
        {
            profile->SetTextureUnit(i, j, drawPTextureUnits.at(i)->at(j));
        }

        profile->SetProgram(i, drawPPrograms.at(i));
    }

    CreateEffect(pshader, effect, instance);
}

std::array<int, 2> Rendering::ImageProcessing2::allDirichletPTextureUnits{ 0, 1 };
std::array<std::array<int, 2>*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessing2::dirichletPTextureUnits{
    nullptr,
    &allDirichletPTextureUnits,
    &allDirichletPTextureUnits,
    &allDirichletPTextureUnits,
    &allDirichletPTextureUnits
};

std::array<std::string, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessing2::dirichletPPrograms{
    // PP_NONE
    "",

    // PP_PS_1_1
    "",

    // PP_PS_2_0
    "ps_2_0\n"
    "dcl_2d s0\n"
    "dcl_2d s1\n"
    "dcl t0.xy\n"
    "texld r0, t0, s1\n"
    "texld r1, t0, s0\n"
    "mul r0, r1, r0\n"
    "mov oC0, r0\n",

    // PP_PS_3_0
    "ps_3_0\n"
    "dcl_2d s0\n"
    "dcl_2d s1\n"
    "dcl_texcoord0 v0.xy\n"
    "texld r1, v0, s1\n"
    "texld r0, v0, s0\n"
    "mul oC0, r0, r1\n",

    // PP_ARBFP1
    "!!ARBfp1.0\n"
    "TEMP R0;\n"
    "TEMP R1;\n"
    "TEX R1, fragment.texcoord[0], texture[1], 2D;\n"
    "TEX R0, fragment.texcoord[0], texture[0], 2D;\n"
    "MUL result.color, R0, R1;\n"
    "END\n"
};

std::array<int, 2> Rendering::ImageProcessing2::msAllNeumannPTextureUnits{ 0, 1 };
std::array<std::array<int, 2>*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessing2::neumannPTextureUnits{
    nullptr,
    &msAllNeumannPTextureUnits,
    &msAllNeumannPTextureUnits,
    &msAllNeumannPTextureUnits,
    &msAllNeumannPTextureUnits
};

std::array<std::string, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessing2::neumannPPrograms{
    // PP_NONE
    "",

    // PP_PS_1_1
    "",

    // PP_PS_2_0
    "ps_2_0\n"
    "dcl_2d s0\n"
    "dcl_2d s1\n"
    "dcl t0.xy\n"
    "texld r0, t0, s0\n"
    "add r0.xy, t0, r0\n"
    "texld r0, r0, s1\n"
    "mov oC0, r0\n",

    // PP_PS_3_0
    "ps_3_0\n"
    "dcl_2d s0\n"
    "dcl_2d s1\n"
    "dcl_texcoord0 v0.xy\n"
    "texld r0.xy, v0, s0\n"
    "add r0.xy, v0, r0\n"
    "texld r0, r0, s1\n"
    "mov oC0, r0\n",

    // PP_ARBFP1
    "!!ARBfp1.0\n"
    "TEMP R0;\n"
    "TEX R0.xy, fragment.texcoord[0], texture[0], 2D;\n"
    "ADD R0.xy, fragment.texcoord[0], R0;\n"
    "TEX result.color, R0, texture[1], 2D;\n"
    "END\n"
};

std::array<int, 2> Rendering::ImageProcessing2::msAllDrawPTextureUnits{ 0, 1 };
std::array<std::array<int, 2>*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessing2::drawPTextureUnits{
    nullptr,
    &msAllDrawPTextureUnits,
    &msAllDrawPTextureUnits,
    &msAllDrawPTextureUnits,
    &msAllDrawPTextureUnits
};

std::array<std::string, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessing2::drawPPrograms{
    // PP_NONE
    "",

    // PP_PS_1_1
    "",

    // PP_PS_2_0
    "ps_2_0\n"
    "dcl_2d s0\n"
    "dcl t0.xy\n"
    "texld r0, t0, s0\n"
    "mov oC0, r0\n",

    // PP_PS_3_0
    "ps_3_0\n"
    "dcl_2d s0\n"
    "dcl_texcoord0 v0.xy\n"
    "texld r0, v0, s0\n"
    "mov oC0, r0\n",

    // PP_ARBFP1
    "!!ARBfp1.0\n"
    "TEX result.color, fragment.texcoord[0], texture[0], 2D;\n"
    "END\n"
};

int Rendering::ImageProcessing2::GetBound0() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bound0;
}

int Rendering::ImageProcessing2::GetBound1() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bound1;
}

float Rendering::ImageProcessing2::GetDx() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return dx;
}

float Rendering::ImageProcessing2::GetDy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return dy;
}
