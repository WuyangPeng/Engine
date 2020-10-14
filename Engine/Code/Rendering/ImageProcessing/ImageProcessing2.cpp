// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 09:40)

#include "Rendering/RenderingExport.h"

#include "ImageProcessing2.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
 #include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26485)
Rendering::ImageProcessing2
	::ImageProcessing2 (int bound0, int bound1, Mathematics::Float4* imageData,PixelShaderSharedPtr mainPShader, bool useDirichlet)
    :ImageProcessingBase(bound0, bound1, 2), mBound0(bound0), mBound1(bound1)
{
    mBound0M1 = mBound0 - 1;
    mBound1M1 = mBound1 - 1;
    mDx = 1.0f/(float)mBound0M1;
    mDy = 1.0f/(float)mBound1M1;

    VisualEffectSharedPtr effect;
    VisualEffectInstanceSharedPtr instance;

    // Create the texture corresponding to the 2D image.
    mMainTexture = CreateImage(imageData);

    // Create the image processing effect.
    CreateEffect(mainPShader, effect, instance);
    mMainEffect = effect;
    mMainEffectInstance = instance;
    // mMainEffectInstance->SetPixelTexture(0, "StateSampler",    mTargets[1]->GetColorTexture(0));

    // Create the boundary effect.
    if (useDirichlet)
    {
        CreateBoundaryDirichletEffect(effect, instance);
    }
    else
    {
        CreateBoundaryNeumannEffect(effect, instance);
    }
    mBoundaryEffect = effect;
    mBoundaryEffectInstance = instance;

   // mBoundaryEffectInstance->SetPixelTexture(0, "StateSampler",  mTargets[0]->GetColorTexture(0));

    // Create the effect for drawing the results of the image processing.
    CreateDrawEffect(effect, instance);
    mDrawEffect = effect;
    mDrawEffectInstance = instance;
	// 先通过编译
   // mDrawEffectInstance->SetPixelTexture(0, "StateSampler",  mTargets[1]->GetColorTexture(0));
}

Rendering::ImageProcessing2
	::ImageProcessing2 (int bound0, int bound1, int numTargets)
    : ImageProcessingBase(bound0, bound1, numTargets), mBound0(bound0), mBound1(bound1)
{
    mBound0M1 = mBound0 - 1;
    mBound1M1 = mBound1 - 1;
    mDx = 1.0f/(float)mBound0M1;
    mDy = 1.0f/(float)mBound1M1;
}

 

Rendering::Texture2DSharedPtr Rendering::ImageProcessing2 ::CreateImage(const Mathematics::Float4* imageData)
{
    Texture2DSharedPtr reflected(std::make_shared < Texture2D>(TextureFormat(System::TextureInternalFormat::A32B32G32R32F), mBound0, mBound1, 1));

    memcpy(reflected->GetTextureData(0), imageData, mBound0*mBound1*sizeof(Mathematics::Float4));
    return reflected;
}

void Rendering::ImageProcessing2
	::CreateBoundaryDirichletEffect (VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance)
{
    // sampler2D MaskSampler = sampler_state
    // {
    //    MinFilter = Nearest;
    //    MagFilter = Nearest;
    //    WrapS     = Clamp;
    //    WrapT     = Clamp;
    // };
    // sampler2D StateSampler = sampler_state
    // {
    //    MinFilter = Nearest;
    //    MagFilter = Nearest;
    //    WrapS     = Clamp;
    //    WrapT     = Clamp;
    // };
    // void p_BoundaryDirichlet
    // (
    //     in float2 vertexTCoord : TEXCOORD0,
    //     out float4 pixelColor : COLOR
    // )
    // {
    //     float4 mask = tex2D(MaskSampler, vertexTCoord);
    //     float4 state = tex2D(StateSampler, vertexTCoord);
    //     pixelColor = mask*state;
    // }

    PixelShaderSharedPtr pshader(std::make_shared < PixelShader>("Wm5.BoundaryDirichlet2", 1, 1, 0, 2)); 
	 
    pshader->SetInput(0, "vertexTCoord", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetSampler(0, "MaskSampler", ShaderFlags::SamplerType::Sampler2D);
    pshader->SetSampler(1, "StateSampler", ShaderFlags::SamplerType::Sampler2D);
	
	auto profile = pshader->GetProfile();

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 2; ++j)
		{
			profile->SetTextureUnit(i, j, msDirichletPTextureUnits[i][j]);
		}

		profile->SetProgram(i, msDirichletPPrograms[i]);
	} 

    CreateEffect(pshader, effect, instance);

    // Create the mask texture.
    Texture2DSharedPtr maskTexture(std::make_shared < Texture2D>(TextureFormat(System::TextureInternalFormat::A32B32G32R32F), mBound0, mBound1, 1));

    Mathematics::Float4* mask = (Mathematics::Float4*)maskTexture->GetTextureData(0);
    Mathematics::Float4 one(1.0f, 1.0f, 1.0f, 1.0f);
    Mathematics::Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
    int x = 0, y = 0;

    // Interior.
    for (y = 1; y < mBound1M1; ++y)
    {
        for (x = 1; x < mBound0M1; ++x)
        {
            mask[Index(x,y)] = one;
        }
    }

    // Edge-interior.
    for (x = 1; x < mBound0M1; ++x)
    {
        mask[Index(x,0)] = zero;
        mask[Index(x,mBound1M1)] = zero;
    }
    for (y = 1; y < mBound1M1; ++y)
    {
        mask[Index(0,y)] = zero;
        mask[Index(mBound0M1,y)] = zero;
    }

    // Corners.
    mask[Index(0,0)] = zero;
    mask[Index(mBound0M1,0)] = zero;
    mask[Index(0,mBound1M1)] = zero;
    mask[Index(mBound0M1,mBound1M1)] = zero;

    instance->SetPixelTexture(0, "MaskSampler", maskTexture);
}

void Rendering::ImageProcessing2
	::CreateBoundaryNeumannEffect (VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance)
{
    // sampler2D OffsetSampler = sampler_state
    // {
    //    MinFilter = Nearest;
    //    MagFilter = Nearest;
    //    WrapS     = Clamp;
    //    WrapT     = Clamp;
    // };
    // sampler2D StateSampler = sampler_state
    // {
    //    MinFilter = Nearest;
    //    MagFilter = Nearest;
    //    WrapS     = Clamp;
    //    WrapT     = Clamp;
    // };
    // void p_BoundaryNeumann
    // (
    //     in float2 vertexTCoord : TEXCOORD0,
    //     out float4 pixelColor : COLOR
    // )
    // {
    //     float2 offset = tex2D(OffsetSampler, vertexTCoord).xy;
    //     float2 tc = float2(vertexTCoord.x + offset.x,
    //         vertexTCoord.y + offset.y);
    //     float4 state = tex2D(StateSampler, tc);
    //     pixelColor = state;
    // }

    PixelShaderSharedPtr pshader(std::make_shared < PixelShader>("Wm5.BoundaryNeumann2", 1, 1, 0, 2));
	 
	 
    pshader->SetInput(0, "vertexTCoord", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetSampler(0, "OffsetSampler", ShaderFlags::SamplerType::Sampler2D);
    pshader->SetSampler(1, "StateSampler", ShaderFlags::SamplerType::Sampler2D);

	auto profile = pshader->GetProfile();

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 2; ++j)
		{
			profile->SetTextureUnit(i, j, msNeumannPTextureUnits[i][j]);
		}

		profile->SetProgram(i, msNeumannPPrograms[i]);
	} 
	 
    CreateEffect(pshader, effect, instance);

    // Create the offset texture.
    Texture2DSharedPtr offsetTexture(std::make_shared < Texture2D>(TextureFormat(System::TextureInternalFormat::A32B32G32R32F), mBound0, mBound1, 1));

    Mathematics::Float4* offset = (Mathematics::Float4*)offsetTexture->GetTextureData(0);
    Mathematics::Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
    Mathematics::Float4 x0EdgeOffset(+mDx, 0.0f, 0.0f, 0.0f);
    Mathematics::Float4 x1EdgeOffset(-mDx, 0.0f, 0.0f, 0.0f);
    Mathematics::Float4 y0EdgeOffset(0.0f, +mDy, 0.0f, 0.0f);
    Mathematics::Float4 y1EdgeOffset(0.0f, -mDy, 0.0f, 0.0f);
    int x = 0, y = 0;

    // Interior.
    for (y = 1; y < mBound1M1; ++y)
    {
        for (x = 1; x < mBound0M1; ++x)
        {
            offset[Index(x,y)] = zero;
        }
    }

    // Edge-interior.
    for (x = 1; x < mBound0M1; ++x)
    {
        offset[Index(x,0)] = y0EdgeOffset;
        offset[Index(x,mBound1M1)] = y1EdgeOffset;
    }
    for (y = 1; y < mBound1M1; ++y)
    {
        offset[Index(0,y)] = x0EdgeOffset;
        offset[Index(mBound0M1,y)] = x1EdgeOffset;
    }

    // Corners.
    offset[Index(0,0)] = Mathematics::Float4(+mDx, +mDy, 0.0f, 0.0f);
    offset[Index(mBound0M1,0)] = Mathematics::Float4(-mDx, +mDy, 0.0f, 0.0f);
    offset[Index(0,mBound1M1)] = Mathematics::Float4(+mDx, -mDy, 0.0f, 0.0f);
    offset[Index(mBound0M1,mBound1M1)] = Mathematics::Float4(-mDx, -mDy, 0.0f, 0.0f);

    instance->SetPixelTexture(0, "OffsetSampler", offsetTexture);
}

void Rendering::ImageProcessing2
	::CreateDrawEffect (VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance)
{
    // sampler2D StateSampler = sampler_state
    // {
    //    MinFilter = Nearest;
    //    MagFilter = Nearest;
    //    WrapS     = Clamp;
    //    WrapT     = Clamp;
    // };
    // void p_ScreenShader2
    // (
    //     in float2 vertexTCoord : TEXCOORD0,
    //     out float4 pixelColor : COLOR
    // )
    // {
    //     pixelColor = tex2D(StateSampler, vertexTCoord);
    // }

    PixelShaderSharedPtr pshader ( std::make_shared<PixelShader>("Wm5.DrawImage2",  1, 1, 0, 1));
	// 先通过编译
	 
    pshader->SetInput(0, "vertexTCoord", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    pshader->SetOutput(0, "pixelColor", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Color0);
    pshader->SetSampler(0, "StateSampler", ShaderFlags::SamplerType::Sampler2D);

	auto profile = pshader->GetProfile();

	for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
	{
		for (auto j = 0; j < 2; ++j)
		{
			profile->SetTextureUnit(i, j, msDrawPTextureUnits[i][j]);
		}

		profile->SetProgram(i, msDrawPPrograms[i]);
	}
	 
    CreateEffect(pshader, effect, instance);
}

int Rendering::ImageProcessing2::msAllDirichletPTextureUnits[2]  { 0, 1 };
int* Rendering::ImageProcessing2::msDirichletPTextureUnits[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    0,
    msAllDirichletPTextureUnits,
    msAllDirichletPTextureUnits,
    msAllDirichletPTextureUnits,
    msAllDirichletPTextureUnits
};

std::string Rendering::ImageProcessing2::msDirichletPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]
{
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

int Rendering::ImageProcessing2::msAllNeumannPTextureUnits[2] { 0, 1 };
int* Rendering::ImageProcessing2::msNeumannPTextureUnits[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    0,
    msAllNeumannPTextureUnits,
    msAllNeumannPTextureUnits,
    msAllNeumannPTextureUnits,
    msAllNeumannPTextureUnits
};

std::string Rendering::ImageProcessing2::msNeumannPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
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

int Rendering::ImageProcessing2::msAllDrawPTextureUnits[2] { 0, 1 };
int* Rendering::ImageProcessing2::msDrawPTextureUnits[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
    0,
    msAllDrawPTextureUnits,
    msAllDrawPTextureUnits,
    msAllDrawPTextureUnits,
    msAllDrawPTextureUnits
};

std::string Rendering::ImageProcessing2::msDrawPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)] 
{
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


 int Rendering::ImageProcessing2
	 ::GetBound0() const noexcept
{
	return mBound0;
}

 int Rendering::ImageProcessing2 ::GetBound1() const noexcept
{
	return mBound1;
}

 float Rendering::ImageProcessing2 ::GetDx() const noexcept
{
	return mDx;
}

 float Rendering::ImageProcessing2 ::GetDy() const noexcept
{
	return mDy;
}

 #include STSTEM_WARNING_POP