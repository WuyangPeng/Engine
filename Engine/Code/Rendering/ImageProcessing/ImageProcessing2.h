///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/18 18:05)

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
        using ClassType = ImageProcessing2;
        using ParentType = ImageProcessingBase;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    public:
        ImageProcessing2(int bound0,
                         int bound1,
                         const std::vector<Mathematics::Float4>& imageData,
                         const PixelShaderSharedPtr& mainPShader,
                         bool useDirichlet);

        ImageProcessing2(int bound0, int bound1, int numTargets);

        NODISCARD int GetBound0() const noexcept;
        NODISCARD int GetBound1() const noexcept;
        NODISCARD float GetDx() const noexcept;
        NODISCARD float GetDy() const noexcept;

        NODISCARD Texture2DSharedPtr CreateImage(const std::vector<Mathematics::Float4>& imageData);

        void CreateBoundaryDirichletEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance);

        void CreateBoundaryNeumannEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance);

        void CreateDrawEffect(VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance);

    private:
        void CreateVertexShader();

    private:
        int bound0;
        int bound1;
        int bound0M1;
        int bound1M1;
        float dx;
        float dy;

        static std::array<int, 2> allDirichletPTextureUnits;
        static std::array<std::array<int, 2>*, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> dirichletPTextureUnits;
        static std::array<std::string, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> dirichletPPrograms;

        static std::array<int, 2> msAllNeumannPTextureUnits;
        static std::array<std::array<int, 2>*, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> neumannPTextureUnits;
        static std::array<std::string, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> neumannPPrograms;

        static std::array<int, 2> msAllDrawPTextureUnits;
        static std::array<std::array<int, 2>*, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> drawPTextureUnits;
        static std::array<std::string, System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)> drawPPrograms;
    };
}

#endif  // RENDERING_IMAGE_PROCESSING_IMAGE_PROCESSING2_H
