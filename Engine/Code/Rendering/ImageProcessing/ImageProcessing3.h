///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/19 10:58)

#ifndef RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING3_H
#define RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING3_H

#include "Rendering/RenderingDll.h"

#include "ImageProcessingBase.h"
#include "Mathematics/Base/Float.h"

namespace Rendering
{
    class ImageProcessing3 : public ImageProcessingBase
    {
    public:
        using ClassType = ImageProcessing3;
        using ParentType = ImageProcessingBase;

    public:
        ImageProcessing3(int bound0,
                         int bound1,
                         int factor0,
                         int factor1,
                         const std::vector<Mathematics::Float4>& imageData,
                         const PixelShaderSharedPtr& mainPShader,
                         const Mathematics::Float4& boundaryColor,
                         bool useDirichlet);

        ImageProcessing3(int bound0, int bound1, int factor0, int factor1, int numTargets);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetBound0() const noexcept;
        NODISCARD int GetBound1() const noexcept;
        NODISCARD int GetBound2() const noexcept;
        NODISCARD int GetFactor0() const noexcept;
        NODISCARD int GetFactor1() const noexcept;
        NODISCARD float GetDx() const noexcept;
        NODISCARD float GetDy() const noexcept;
        NODISCARD float GetDz() const noexcept;

        void Map2Dto3D(int u, int v, int& x, int& y, int& z) const noexcept;

        void Map3Dto2D(int x, int y, int z, int& u, int& v) const noexcept;

        NODISCARD int Map3Dto1D(int x, int y, int z) noexcept;

        NODISCARD Texture2DSharedPtr CreateTiledImage(const std::vector<Mathematics::Float4>& imageData);

        void CreateBoundaryDirichletEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance);

        void CreateBoundaryNeumannEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance);

        void CreateDrawEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance, const Mathematics::Float4& boundaryColor);

    private:
        int bound0;
        int bound1;
        int bound2;
        int bound0M1;
        int bound1M1;
        int bound2M1;
        int factor0;
        int factor1;
        float dx;
        float dy;
        float dz;

        static std::array<int, 2> allDirichletPTextureUnits;
        static std::array<std::array<int, 2>*, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> dirichletPTextureUnits;
        static std::array<std::string, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> dirichletPPrograms;

        static std::array<int, 2> allNeumannPTextureUnits;
        static std::array<std::array<int, 2>*, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> neumannPTextureUnits;
        static std::array<std::string, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> neumannPPrograms;

        static constexpr auto allDrawPRegisters = 0;
        static std::array<const int*, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> drawPRegisters;
        static std::array<int, 2> allDrawPTextureUnits;
        static std::array<std::array<int, 2>*, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> drawPTextureUnits;
        static std::array<std::string, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> drawPPrograms;
    };
}

#endif  // RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING3_H
