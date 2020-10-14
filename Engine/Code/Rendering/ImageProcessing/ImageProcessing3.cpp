// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/26 09:57)

#include "Rendering/RenderingExport.h"

#include "ImageProcessing3.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
 #include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26426) 
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26446) 
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26485)
Rendering::ImageProcessing3
	::ImageProcessing3 (int bound0, int bound1, int factor0, int factor1, Mathematics::Float4* imageData, PixelShaderSharedPtr mainPShader, const Mathematics::Float4& boundaryColor, bool useDirichlet)
    : ImageProcessingBase(bound0*factor0, bound1*factor1, 2), mBound0(bound0), mBound1(bound1), mBound2(factor0*factor1), mFactor0(factor0),  mFactor1(factor1)
{
    mBound0M1 = mBound0 - 1;
    mBound1M1 = mBound1 - 1;
    mBound2M1 = mBound2 - 1;
    mDx = 1.0f/(float)mBound0M1;
    mDy = 1.0f/(float)mBound1M1;
    mDz = 1.0f/(float)mBound2M1;

	VisualEffectSharedPtr effect;
	VisualEffectInstanceSharedPtr instance;

    // Create the tiled texture corresponding to the 3D image.
    mMainTexture = CreateTiledImage(imageData);

    // Create the image processing effect.
    CreateEffect(mainPShader, effect, instance);
    mMainEffect = effect;
    mMainEffectInstance = instance;

    //mMainEffectInstance->SetPixelTexture(0, "StateSampler", mTargets[1]->GetColorTexture(0));

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

	//mBoundaryEffectInstance->SetPixelTexture(0, "StateSampler",        mTargets[0]->GetColorTexture(0));

    // Create the effect for drawing the results of the image processing.
    CreateDrawEffect(effect, instance, boundaryColor);
    mDrawEffect = effect;
    mDrawEffectInstance = instance;

	//mDrawEffectInstance->SetPixelTexture(0, "StateSampler",    mTargets[1]->GetColorTexture(0));
}

Rendering::ImageProcessing3
	::ImageProcessing3 (int bound0, int bound1, int factor0, int factor1, int numTargets)
    : ImageProcessingBase(bound0*factor0, bound1*factor1, numTargets),  mBound0(bound0), mBound1(bound1),
      mBound2(factor0*factor1), mFactor0(factor0), mFactor1(factor1)
{
    mBound0M1 = mBound0 - 1;
    mBound1M1 = mBound1 - 1;
    mBound2M1 = mBound2 - 1;
    mDx = 1.0f/(float)mBound0M1;
    mDy = 1.0f/(float)mBound1M1;
    mDz = 1.0f/(float)mBound2M1;
}

 

void Rendering::ImageProcessing3
	::Map2Dto3D (int u, int v, int& x, int& y, int& z) const noexcept
{
    x = u % mBound0;
    y = v % mBound1;
    z = (u / mBound0) + (v / mBound1) * mFactor0;
}

void Rendering::ImageProcessing3 ::Map3Dto2D(int x, int y, int z, int& u, int& v) const noexcept
{
    u = x + (z % mFactor0) * mBound0;
    v = y + (z / mFactor0) * mBound1;
}

int Rendering::ImageProcessing3
	::Map3Dto1D (int x, int y, int z) noexcept
{
   const  int u = x + (z % mFactor0) * mBound0;
    const int v = y + (z / mFactor0) * mBound1;
    return u + mNumCols*v;
}

Rendering::Texture2DSharedPtr Rendering::ImageProcessing3
	::CreateTiledImage(const Mathematics::Float4* imageData)
{
	Texture2DSharedPtr tiled ( std::make_shared<Texture2D>(TextureFormat(System::TextureInternalFormat::A32B32G32R32F), mNumCols, mNumRows, 1));

	Mathematics::Float4* textureData = (Mathematics::Float4*)tiled->GetTextureData(0);
    for (int v = 0; v < mNumRows; ++v)
    {
        for (int u = 0; u < mNumCols; ++u)
        {
            int x, y, z;
            Map2Dto3D(u, v, x, y, z);
            textureData[u + mNumCols*v] = imageData[x + mBound0*(y + mBound1*z)];
        }
    }

    return tiled;
}

void Rendering::ImageProcessing3
	::CreateBoundaryDirichletEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance)
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

    PixelShaderSharedPtr pshader (std::make_shared<PixelShader>("Wm5.BoundaryDirichlet3",   1, 1, 0, 2));
 
	 
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
	Texture2DSharedPtr maskTexture ( std::make_shared<Texture2D>(TextureFormat(System::TextureInternalFormat::A32B32G32R32F), mNumCols, mNumRows, 1));

	Mathematics::Float4* mask = (Mathematics::Float4*)maskTexture->GetTextureData(0);
	Mathematics::Float4 one(1.0f, 1.0f, 1.0f, 1.0f);
	Mathematics::Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
        int x = 0, y = 0, z = 0;

    // Interior.
    for (z = 1; z < mBound2M1; ++z)
    {
        for (y = 1; y < mBound1M1; ++y)
        {
            for (x = 1; x < mBound0M1; ++x)
            {
                mask[Map3Dto1D(x, y, z)] = one;
            }
        }
    }

    // x-face-interior.
    for (z = 1; z < mBound2M1; ++z)
    {
        for (y = 1; y < mBound1M1; ++y)
        {
            mask[Map3Dto1D(0, y, z)] = zero;
            mask[Map3Dto1D(mBound0M1, y, z)] = zero;
        }
    }

    // y-face-interior.
    for (z = 1; z < mBound2M1; ++z)
    {
        for (x = 1; x < mBound0M1; ++x)
        {
            mask[Map3Dto1D(x, 0, z)] = zero;
            mask[Map3Dto1D(x, mBound1M1, z)] = zero;
        }
    }

    // z-face-interior.
    for (y = 1; y < mBound1M1; ++y)
    {
        for (x = 1; x < mBound0M1; ++x)
        {
            mask[Map3Dto1D(x, y, 0)] = zero;
            mask[Map3Dto1D(x, y, mBound2M1)] = zero;
        }
    }

    // x-edge-interior.
    for (x = 1; x < mBound0M1; ++x)
    {
        mask[Map3Dto1D(x, 0, 0)] = zero;
        mask[Map3Dto1D(x, 0, mBound2M1)] = zero;
        mask[Map3Dto1D(x, mBound1M1, 0)] = zero;
        mask[Map3Dto1D(x, mBound1M1, mBound2M1)] = zero;
    }

    // y-edge-interior.
    for (y = 1; y < mBound1M1; ++y)
    {
        mask[Map3Dto1D(0, y, 0)] = zero;
        mask[Map3Dto1D(0, y, mBound2M1)] = zero;
        mask[Map3Dto1D(mBound0M1, y, 0)] = zero;
        mask[Map3Dto1D(mBound0M1, y, mBound2M1)] = zero;
    }

    // z-edge-interior
    for (z = 1; z < mBound2M1; ++z)
    {
        mask[Map3Dto1D(0, 0, z)] = zero;
        mask[Map3Dto1D(0, mBound1M1, z)] = zero;
        mask[Map3Dto1D(mBound0M1, 0, z)] = zero;
        mask[Map3Dto1D(mBound0M1, mBound1M1, z)] = zero;
    }

    // Corners.
    mask[Map3Dto1D(0, 0, 0)] = zero;
    mask[Map3Dto1D(mBound0M1, 0, 0)] = zero;
    mask[Map3Dto1D(0, mBound1M1, 0)] = zero;
    mask[Map3Dto1D(mBound0M1, mBound1M1, 0)] = zero;
    mask[Map3Dto1D(0, 0, mBound2M1)] = zero;
    mask[Map3Dto1D(mBound0M1, 0, mBound2M1)] = zero;
    mask[Map3Dto1D(0, mBound1M1, mBound2M1)] = zero;
    mask[Map3Dto1D(mBound0M1, mBound1M1, mBound2M1)] = zero;

    instance->SetPixelTexture(0, "MaskSampler", maskTexture);
}

void Rendering::ImageProcessing3
	::CreateBoundaryNeumannEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance)
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
    //     float4 state = tex2D(StateSampler, vertexTCoord + offset);
    //     pixelColor = state;
    // }

    PixelShaderSharedPtr pshader ( std::make_shared<PixelShader>("Wm5.BoundaryNeumann3",  1, 1, 0, 2));
	 
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
	Texture2DSharedPtr offsetTexture ( std::make_shared<Texture2D>(TextureFormat(System::TextureInternalFormat::A32B32G32R32F), mNumCols, mNumRows, 1));

	Mathematics::Float4* offset = (Mathematics::Float4*)offsetTexture->GetTextureData(0);
	Mathematics::Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
	Mathematics::Float4 x0FaceOffset(+mColSpacing, 0.0f, 0.0f, 0.0f);
	Mathematics::Float4 x1FaceOffset(-mColSpacing, 0.0f, 0.0f, 0.0f);
	Mathematics::Float4 y0FaceOffset(0.0f, +mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 y1FaceOffset(0.0f, -mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 z0FaceOffset(+mBound0*mColSpacing, 0.0f, 0.0f, 0.0f);
	Mathematics::Float4 z1FaceOffset(-mBound0*mColSpacing, 0.0f, 0.0f, 0.0f);
	Mathematics::Float4 x00EdgeOffset(+mBound0*mColSpacing, +mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 x01EdgeOffset(-mBound0*mColSpacing, +mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 x10EdgeOffset(+mBound0*mColSpacing, -mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 x11EdgeOffset(-mBound0*mColSpacing, -mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 y00EdgeOffset((+mBound0 + 1)*mColSpacing, 0.0f, 0.0f, 0.0f);
	Mathematics::Float4 y01EdgeOffset((-mBound0 + 1)*mColSpacing, 0.0f, 0.0f, 0.0f);
	Mathematics::Float4 y10EdgeOffset((+mBound0 - 1)*mColSpacing, 0.0f, 0.0f, 0.0f);
	Mathematics::Float4 y11EdgeOffset((-mBound0 - 1)*mColSpacing, 0.0f, 0.0f, 0.0f);
	Mathematics::Float4 z00EdgeOffset(+mColSpacing, +mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 z01EdgeOffset(+mColSpacing, -mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 z10EdgeOffset(-mColSpacing, +mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 z11EdgeOffset(-mColSpacing, -mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 c000Offset((+mBound0 + 1)*mColSpacing, +mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 c100Offset((+mBound0 - 1)*mColSpacing, +mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 c010Offset((+mBound0 + 1)*mColSpacing, -mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 c110Offset((+mBound0 - 1)*mColSpacing, -mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 c001Offset((-mBound0 + 1)*mColSpacing, +mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 c101Offset((-mBound0 - 1)*mColSpacing, +mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 c011Offset((-mBound0 + 1)*mColSpacing, -mRowSpacing, 0.0f, 0.0f);
	Mathematics::Float4 c111Offset((-mBound0 - 1)*mColSpacing, -mRowSpacing, 0.0f, 0.0f);
        int x = 0, y = 0, z = 0;

    // Interior.
    for (z = 1; z < mBound2M1; ++z)
    {
        for (y = 1; y < mBound1M1; ++y)
        {
            for (x = 1; x < mBound0M1; ++x)
            {
                offset[Map3Dto1D(x, y, z)] = zero;
            }
        }
    }

    // x-face-interior.
    for (z = 1; z < mBound2M1; ++z)
    {
        for (y = 1; y < mBound1M1; ++y)
        {
            offset[Map3Dto1D(0, y, z)] = x0FaceOffset;
            offset[Map3Dto1D(mBound0M1, y, z)] = x1FaceOffset;
        }
    }

    // y-face-interior.
    for (z = 1; z < mBound2M1; ++z)
    {
        for (x = 1; x < mBound0M1; ++x)
        {
            offset[Map3Dto1D(x, 0, z)] = y0FaceOffset;
            offset[Map3Dto1D(x, mBound1M1, z)] = y1FaceOffset;
        }
    }

    // z-face-interior.
    for (y = 1; y < mBound1M1; ++y)
    {
        for (x = 1; x < mBound0M1; ++x)
        {
            offset[Map3Dto1D(x, y, 0)] = z0FaceOffset;
            offset[Map3Dto1D(x, y, mBound2M1)] = z1FaceOffset;
        }
    }

    // x-edge-interior.
    for (x = 1; x < mBound0M1; ++x)
    {
        offset[Map3Dto1D(x, 0, 0)] = x00EdgeOffset;
        offset[Map3Dto1D(x, 0, mBound2M1)] = x01EdgeOffset;
        offset[Map3Dto1D(x, mBound1M1, 0)] = x10EdgeOffset;
        offset[Map3Dto1D(x, mBound1M1, mBound2M1)] = x11EdgeOffset;
    }

    // y-edge-interior.
    for (y = 1; y < mBound1M1; ++y)
    {
        offset[Map3Dto1D(0, y, 0)] = y00EdgeOffset;
        offset[Map3Dto1D(0, y, mBound2M1)] = y01EdgeOffset;
        offset[Map3Dto1D(mBound0M1, y, 0)] = y10EdgeOffset;
        offset[Map3Dto1D(mBound0M1, y, mBound2M1)] = y11EdgeOffset;
    }

    // z-edge-interior
    for (z = 1; z < mBound2M1; ++z)
    {
        offset[Map3Dto1D(0, 0, z)] = z00EdgeOffset;
        offset[Map3Dto1D(0, mBound1M1, z)] = z01EdgeOffset;
        offset[Map3Dto1D(mBound0M1, 0, z)] = z10EdgeOffset;
        offset[Map3Dto1D(mBound0M1, mBound1M1, z)] = z11EdgeOffset;
    }

    // Corners.
    offset[Map3Dto1D(0, 0, 0)] = c000Offset;
    offset[Map3Dto1D(mBound0M1, 0, 0)] = c100Offset;
    offset[Map3Dto1D(0, mBound1M1, 0)] = c010Offset;
    offset[Map3Dto1D(mBound0M1, mBound1M1, 0)] = c110Offset;
    offset[Map3Dto1D(0, 0, mBound2M1)] = c001Offset;
    offset[Map3Dto1D(mBound0M1, 0, mBound2M1)] = c101Offset;
    offset[Map3Dto1D(0, mBound1M1, mBound2M1)] = c011Offset;
    offset[Map3Dto1D(mBound0M1, mBound1M1, mBound2M1)] = c111Offset;

    instance->SetPixelTexture(0, "OffsetSampler", offsetTexture);
}

void Rendering::ImageProcessing3
	::CreateDrawEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance, const Mathematics::Float4& boundaryColor)
{
    // sampler2D StateSampler = sampler_state
    // {
    //    MinFilter = Nearest;
    //    MagFilter = Nearest;
    //    WrapS     = Clamp;
    //    WrapT     = Clamp;
    // };
    // sampler2D MaskSampler = sampler_state
    // {
    //    MinFilter = Nearest;
    //    MagFilter = Nearest;
    //    WrapS     = Clamp;
    //    WrapT     = Clamp;
    // };
    // void p_ScreenShader3
    // (
    //     in float2 vertexTCoord : TEXCOORD0,
    //     uniform float4 BoundaryColor,
    //     out float4 pixelColor : COLOR
    // )
    // {
    //     float4 state = tex2D(StateSampler, vertexTCoord);
    //     float4 mask = tex2D(MaskSampler, vertexTCoord);
    //     float4 one = float4(1.0f, 1.0f, 1.0f, 1.0f);
    //     pixelColor = mask*state + (one - mask)*BoundaryColor;
    // }

    PixelShaderSharedPtr pshader ( std::make_shared<PixelShader>("Wm5.DrawImage3", 1, 1, 1, 2));
 
	 
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
			profile->SetBaseRegister(i, j, msDrawPRegisters[i][j]);
		}

		for (auto j = 0; j < 2; ++j)
		{
			profile->SetTextureUnit(i, j, msDrawPTextureUnits[i][j]);
		}

		profile->SetProgram(i, msDrawPPrograms[i]);
	}
	 

    CreateEffect(pshader, effect, instance);

    ShaderFloatSharedPtr boundaryColorConstant ( std::make_shared<ShaderFloat>(1));
    float* data = boundaryColorConstant->GetData();
    data[0] = boundaryColor.GetFirstValue();
    data[1] = boundaryColor.GetSecondValue();
    data[2] = boundaryColor.GetThirdValue();
    data[3] = boundaryColor.GetFourthValue();
    instance->SetPixelConstant(0, "BoundaryColor", boundaryColorConstant);

	Texture2DSharedPtr maskTexture ( std::make_shared<Texture2D>(TextureFormat(System::TextureInternalFormat::A32B32G32R32F), mNumCols, mNumRows, 1));
	Mathematics::Float4* mask = (Mathematics::Float4*)maskTexture->GetTextureData(0);
	memset(mask, 0, mNumCols*mNumRows*sizeof(Mathematics::Float4));
	Mathematics::Float4 one(1.0f, 1.0f, 1.0f, 1.0f);

    for (int z = 1; z < mBound2M1; ++z)
    {
        for (int y = 1; y < mBound1M1; ++y)
        {
            for (int x = 1; x < mBound0M1; ++x)
            {
                mask[Map3Dto1D(x, y, z)] = one;
            }
        }
    }

    instance->SetPixelTexture(0, "MaskSampler", maskTexture);
}

int Rendering::ImageProcessing3::msAllDirichletPTextureUnits[2]   { 0, 1 };
int* Rendering::ImageProcessing3::msDirichletPTextureUnits[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]  
{
    0,
    msAllDirichletPTextureUnits,
    msAllDirichletPTextureUnits,
    msAllDirichletPTextureUnits,
    msAllDirichletPTextureUnits
};

std::string Rendering::ImageProcessing3::msDirichletPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]  
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

int Rendering::ImageProcessing3::msAllNeumannPTextureUnits[2]  { 0, 1 };
int* Rendering::ImageProcessing3::msNeumannPTextureUnits[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]  
{
    0,
    msAllNeumannPTextureUnits,
    msAllNeumannPTextureUnits,
    msAllNeumannPTextureUnits,
    msAllNeumannPTextureUnits
};

std::string Rendering::ImageProcessing3::msNeumannPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]  
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

int Rendering::ImageProcessing3::msAllDrawPRegisters[1]   { 0 };
int* Rendering::ImageProcessing3::msDrawPRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]  
{
    0,
    msAllDrawPRegisters,
    msAllDrawPRegisters,
    msAllDrawPRegisters,
    msAllDrawPRegisters
};

int Rendering::ImageProcessing3::msAllDrawPTextureUnits[2]   { 0, 1 };
int* Rendering::ImageProcessing3::msDrawPTextureUnits[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]  
{
    0,
    msAllDrawPTextureUnits,
    msAllDrawPTextureUnits,
    msAllDrawPTextureUnits,
    msAllDrawPTextureUnits
};

std::string Rendering::ImageProcessing3::msDrawPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)]  
{
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



 int Rendering::ImageProcessing3
	 ::GetBound0() const noexcept
{
	return mBound0;
}

 int Rendering::ImageProcessing3 ::GetBound1() const noexcept
{
	return mBound1;
}

 int Rendering::ImageProcessing3 ::GetBound2() const noexcept
{
	return mBound2;
}

 int Rendering::ImageProcessing3 ::GetFactor0() const noexcept
{
	return mFactor0;
}

 int Rendering::ImageProcessing3 ::GetFactor1() const noexcept
{ 
	return mFactor1;
}

 float Rendering::ImageProcessing3 ::GetDx() const noexcept
{
	return mDx;
}

 float Rendering::ImageProcessing3 ::GetDy() const noexcept
{
	return mDy;
}

 float Rendering::ImageProcessing3 ::GetDz() const noexcept
{
	return mDz;
}

 #include STSTEM_WARNING_POP