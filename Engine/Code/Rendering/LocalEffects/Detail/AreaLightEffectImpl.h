/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 10:05)

#ifndef RENDERING_LOCAL_EFFECTS_AREA_LIGHT_EFFECT_IMPL_H
#define RENDERING_LOCAL_EFFECTS_AREA_LIGHT_EFFECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/State/StateFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE AreaLightEffectImpl
    {
    public:
        using ClassType = AreaLightEffectImpl;

        using ConstantBufferSharedPtr = std::shared_ptr<ConstantBuffer>;
        using ConstConstantBufferSharedPtr = std::shared_ptr<const ConstantBuffer>;
        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;
        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;

    public:
        AreaLightEffectImpl() noexcept;
        AreaLightEffectImpl(SamplerStateFilter filter,
                            SamplerStateMode mode0,
                            SamplerStateMode mode1,
                            Texture2DSharedPtr baseTexture,
                            Texture2DSharedPtr normalTexture,
                            int numMaterialConstantBytes,
                            int numLightingConstantBytes,
                            int numGeometryConstantBytes);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstConstantBufferSharedPtr GetMaterialConstant() const noexcept;
        NODISCARD ConstConstantBufferSharedPtr GetCameraConstant() const noexcept;
        NODISCARD ConstConstantBufferSharedPtr GetAreaLightConstant() const noexcept;
        NODISCARD ConstantBufferSharedPtr GetMaterialConstant() noexcept;
        NODISCARD ConstantBufferSharedPtr GetCameraConstant() noexcept;
        NODISCARD ConstantBufferSharedPtr GetAreaLightConstant() noexcept;
        NODISCARD Texture2DSharedPtr GetBaseTexture() noexcept;
        NODISCARD Texture2DSharedPtr GetNormalTexture() noexcept;
        NODISCARD SamplerStateSharedPtr GetCommonSampler() noexcept;

    private:
        ConstantBufferSharedPtr materialConstant;
        ConstantBufferSharedPtr cameraConstant;
        ConstantBufferSharedPtr areaLightConstant;
        Texture2DSharedPtr baseTexture;
        Texture2DSharedPtr normalTexture;
        SamplerStateSharedPtr commonSampler;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_AREA_LIGHT_EFFECT_IMPL_H
