// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 09:32)

#ifndef RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING2_H
#define RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING2_H

#include "Rendering/RenderingDll.h"

#include "ImageProcessingBase.h"
#include "Mathematics/Base/Float.h"

namespace Rendering
{
    class ImageProcessing2 : public ImageProcessingBase
    {
    public:
        // Construction and destruction.  Objects of this class should not be
        // instantiated until the shader profile is known.  Thus, do not create
        // such an object in an application constructor, but do so in
        // OnInitialize or later.

        // Use this constructor for the standard image processing pipeline.
        ImageProcessing2(int bound0, int bound1, Mathematics::Float4* imageData, PixelShaderSharedPtr mainPShader, bool useDirichlet);

        // Use this constructor when you want to set up your own pipeline for
        // processing the image.
        ImageProcessing2(int bound0, int bound1, int numTargets);

        // Member access.
        int GetBound0() const noexcept;
        int GetBound1() const noexcept;
        float GetDx() const noexcept;
        float GetDy() const noexcept;

        // Create a texture corresponding to the 2D image data.
        Texture2DSharedPtr CreateImage(const Mathematics::Float4* imageData);

        // Set boundary pixels to (0,0,0,0).
        void CreateBoundaryDirichletEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance);

        // Set boundary pixels so that boundary derivatives are zero.
        void CreateBoundaryNeumannEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance);

        // Draw the image.
        void CreateDrawEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance);

    private:
        void CreateVertexShader();

        int mBound0, mBound1, mBound0M1, mBound1M1;
        float mDx, mDy;

        // Profile information for BoundaryDirichlet.fx.
        static int msAllDirichletPTextureUnits[2];
        static int* msDirichletPTextureUnits[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
        static std::string msDirichletPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];

        // Profile information for BoundaryNeumann.fx.
        static int msAllNeumannPTextureUnits[2];
        static int* msNeumannPTextureUnits[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
        static std::string msNeumannPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];

        // Profile information for ScreenShader.fx, function v_ScreenShader and
        // p_ScreenShader2.
        static int msAllDrawPTextureUnits[2];
        static int* msDrawPTextureUnits[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
        static std::string msDrawPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
    };
}

#endif  // RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING2_H
