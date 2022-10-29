///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/19 11:09)

#include "Rendering/RenderingExport.h"

#include "ImageProcessing3.h"
#include "System/Helper/PragmaWarning.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"

Rendering::ImageProcessing3::ImageProcessing3(int bound0, int bound1, int factor0, int factor1, const std::vector<Mathematics::Float4>& imageData, const PixelShaderSharedPtr& mainPShader, const Mathematics::Float4& boundaryColor, bool useDirichlet)
    : ParentType{ bound0 * factor0, bound1 * factor1, 2 },
      bound0{ bound0 },
      bound1{ bound1 },
      bound2{ factor0 * factor1 },
      bound0M1{ bound0 - 1 },
      bound1M1{ bound1 - 1 },
      bound2M1{ bound2 - 1 },
      factor0{ factor0 },
      factor1{ factor1 },
      dx{ 1.0f / bound0M1 },
      dy{ 1.0f / bound1M1 },
      dz{ 1.0f / bound2M1 }
{
    VisualEffectSharedPtr effect{};
    VisualEffectInstanceSharedPtr instance{};

    SetMainTexture(CreateTiledImage(imageData));

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

    CreateDrawEffect(effect, instance, boundaryColor);
    SetDrawEffect(effect);
    SetDrawEffectInstance(instance);

    instance->SetPixelTexture(0, "StateSampler", GetColorTexture(1));

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ImageProcessing3)

Rendering::ImageProcessing3::ImageProcessing3(int bound0, int bound1, int factor0, int factor1, int numTargets)
    : ParentType{ bound0 * factor0, bound1 * factor1, numTargets },
      bound0{ bound0 },
      bound1{ bound1 },
      bound2{ factor0 * factor1 },
      bound0M1{ bound0 - 1 },
      bound1M1{ bound1 - 1 },
      bound2M1{ bound2 - 1 },
      factor0{ factor0 },
      factor1{ factor1 },
      dx{ 1.0f / bound0M1 },
      dy{ 1.0f / bound1M1 },
      dz{ 1.0f / bound2M1 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::ImageProcessing3::Map2Dto3D(int u, int v, int& x, int& y, int& z) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    x = u % bound0;
    y = v % bound1;
    z = (u / bound0) + (v / bound1) * factor0;
}

void Rendering::ImageProcessing3::Map3Dto2D(int x, int y, int z, int& u, int& v) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    u = x + (z % factor0) * bound0;
    v = y + (z / factor0) * bound1;
}

int Rendering::ImageProcessing3::Map3Dto1D(int x, int y, int z) noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto u = x + (z % factor0) * bound0;
    const auto v = y + (z / factor0) * bound1;
    return u + GetNumCols() * v;
}

Rendering::Texture2DSharedPtr Rendering::ImageProcessing3::CreateTiledImage(MAYBE_UNUSED const std::vector<Mathematics::Float4>& imageData)
{
    RENDERING_CLASS_IS_VALID_9;

    auto tiled = std::make_shared<Texture2D>(System::EnumCastUnderlying<DataFormatType>(System::TextureInternalFormat::RGBA32F), GetNumCols(), GetNumRows(), 1);

    return tiled;
}

void Rendering::ImageProcessing3::CreateBoundaryDirichletEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance)
{
    RENDERING_CLASS_IS_VALID_9;

    auto pshader = std::make_shared<PixelShader>("BoundaryDirichlet3", 1, 1, 0, 2);

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

void Rendering::ImageProcessing3::CreateBoundaryNeumannEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance)
{
    RENDERING_CLASS_IS_VALID_9;

    auto pshader = std::make_shared<PixelShader>("BoundaryNeumann3", 1, 1, 0, 2);

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

void Rendering::ImageProcessing3::CreateDrawEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance, const Mathematics::Float4& boundaryColor)
{
    RENDERING_CLASS_IS_VALID_9;

    auto pshader = std::make_shared<PixelShader>("DrawImage3", 1, 1, 1, 2);

    pshader->SetInput(0, "vertexTCoord", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetConstant(0, "BoundaryColor", 1);
    pshader->SetSampler(0, "StateSampler", ShaderFlags::SamplerType::Sampler2D);
    pshader->SetSampler(1, "MaskSampler", ShaderFlags::SamplerType::Sampler2D);

    auto profile = pshader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 1; ++j)
        {
            profile->SetBaseRegister(i, j, *drawPRegisters.at(i));
        }

        for (auto j = 0; j < 2; ++j)
        {
            profile->SetTextureUnit(i, j, drawPTextureUnits.at(i)->at(j));
        }

        profile->SetProgram(i, drawPPrograms.at(i));
    }

    CreateEffect(pshader, effect, instance);

    auto boundaryColorConstant = std::make_shared<ShaderFloat>(1);

    (*boundaryColorConstant)[0] = boundaryColor[0];
    (*boundaryColorConstant)[1] = boundaryColor[1];
    (*boundaryColorConstant)[2] = boundaryColor[2];
    (*boundaryColorConstant)[3] = boundaryColor[3];
    instance->SetPixelConstant(0, "BoundaryColor", boundaryColorConstant);
}

std::array<int, 2> Rendering::ImageProcessing3::allDirichletPTextureUnits{ 0, 1 };
std::array<std::array<int, 2>*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessing3::dirichletPTextureUnits{
    nullptr,
    &allDirichletPTextureUnits,
    &allDirichletPTextureUnits,
    &allDirichletPTextureUnits,
    &allDirichletPTextureUnits
};

std::array<std::string, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessing3::dirichletPPrograms{
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

std::array<int, 2> Rendering::ImageProcessing3::allNeumannPTextureUnits{ 0, 1 };
std::array<std::array<int, 2>*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessing3::neumannPTextureUnits{
    nullptr,
    &allNeumannPTextureUnits,
    &allNeumannPTextureUnits,
    &allNeumannPTextureUnits,
    &allNeumannPTextureUnits
};

std::array<std::string, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessing3::neumannPPrograms{
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

std::array<const int*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessing3::drawPRegisters{
    nullptr,
    &allDrawPRegisters,
    &allDrawPRegisters,
    &allDrawPRegisters,
    &allDrawPRegisters
};

std::array<int, 2> Rendering::ImageProcessing3::allDrawPTextureUnits{ 0, 1 };
std::array<std::array<int, 2>*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessing3::drawPTextureUnits{
    nullptr,
    &allDrawPTextureUnits,
    &allDrawPTextureUnits,
    &allDrawPTextureUnits,
    &allDrawPTextureUnits
};

std::array<std::string, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessing3::drawPPrograms{
    // PP_NONE
    "",

    // PP_PS_1_1
    "",

    // PP_PS_2_0
    "ps_2_0\n"
    "dcl_2d s0\n"
    "dcl_2d s1\n"
    "def c1, 1.00000000, 0, 0, 0\n"
    "dcl t0.xy\n"
    "texld r0, t0, s1\n"
    "texld r1, t0, s0\n"
    "add r2, -r0, c1.x\n"
    "mul r2, r2, c0\n"
    "mad r0, r0, r1, r2\n"
    "mov oC0, r0\n",

    // PP_PS_3_0
    "ps_3_0\n"
    "dcl_2d s0\n"
    "dcl_2d s1\n"
    "def c1, 1.00000000, 0, 0, 0\n"
    "dcl_texcoord0 v0.xy\n"
    "texld r1, v0, s1\n"
    "add r0, -r1, c1.x\n"
    "mul r2, r0, c0\n"
    "texld r0, v0, s0\n"
    "mad oC0, r1, r0, r2\n",

    // PP_ARBFP1
    "!!ARBfp1.0\n"
    "PARAM c[2] = { program.local[0],\n"
    "		{ 1 } };\n"
    "TEMP R0;\n"
    "TEMP R1;\n"
    "TEMP R2;\n"
    "TEX R0, fragment.texcoord[0], texture[1], 2D;\n"
    "ADD R1, -R0, c[1].x;\n"
    "MUL R2, R1, c[0];\n"
    "TEX R1, fragment.texcoord[0], texture[0], 2D;\n"
    "MAD result.color, R0, R1, R2;\n"
    "END\n"
};

int Rendering::ImageProcessing3::GetBound0() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bound0;
}

int Rendering::ImageProcessing3::GetBound1() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bound1;
}

int Rendering::ImageProcessing3::GetBound2() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bound2;
}

int Rendering::ImageProcessing3::GetFactor0() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return factor0;
}

int Rendering::ImageProcessing3::GetFactor1() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return factor1;
}

float Rendering::ImageProcessing3::GetDx() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return dx;
}

float Rendering::ImageProcessing3::GetDy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return dy;
}

float Rendering::ImageProcessing3::GetDz() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return dz;
}
