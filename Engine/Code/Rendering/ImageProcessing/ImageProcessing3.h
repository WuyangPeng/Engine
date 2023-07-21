///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:45)

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
        static std::array<std::array<int, 2>*, 5> dirichletPTextureUnits;
        static std::array<std::string, 5> dirichletPPrograms;

        static std::array<int, 2> allNeumannPTextureUnits;
        static std::array<std::array<int, 2>*, 5> neumannPTextureUnits;
        static std::array<std::string, 5> neumannPPrograms;

        static constexpr auto allDrawPRegisters = 0;
        static std::array<const int*, 5> drawPRegisters;
        static std::array<int, 2> allDrawPTextureUnits;
        static std::array<std::array<int, 2>*, 5> drawPTextureUnits;
        static std::array<std::string, 5> drawPPrograms;
    };
}

#endif  // RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING3_H
