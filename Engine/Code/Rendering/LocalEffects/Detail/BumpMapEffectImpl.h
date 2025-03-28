/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 10:22)

#ifndef RENDERING_LOCAL_EFFECTS_BUMP_MAP_EFFECT_IMPL_H
#define RENDERING_LOCAL_EFFECTS_BUMP_MAP_EFFECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Algebra/Vector4.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/State/StateFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE BumpMapEffectImpl
    {
    public:
        using ClassType = BumpMapEffectImpl;

        using Colour = Colour<float>;
        using Math = Mathematics::Math<float>;
        using Vector2 = Mathematics::Vector2<float>;
        using Vector3 = Mathematics::Vector3<float>;
        using Vector4 = Mathematics::Vector4<float>;
        using Vector3ToolsType = Mathematics::Vector3Tools<float>;
        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;
        using ConstTexture2DSharedPtr = std::shared_ptr<const Texture2D>;
        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;
        using ConstSamplerStateSharedPtr = std::shared_ptr<const SamplerState>;
        using VisualSharedPtr = std::shared_ptr<Visual>;

    public:
        BumpMapEffectImpl() noexcept;
        BumpMapEffectImpl(SamplerStateFilter filter,
                          SamplerStateMode mode0,
                          SamplerStateMode mode1,
                          Texture2DSharedPtr baseTexture,
                          Texture2DSharedPtr normalTexture);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstTexture2DSharedPtr GetBaseTexture() const noexcept;
        NODISCARD ConstTexture2DSharedPtr GetNormalTexture() const noexcept;
        NODISCARD ConstSamplerStateSharedPtr GetCommonSampler() const noexcept;

        NODISCARD Texture2DSharedPtr GetBaseTexture() noexcept;
        NODISCARD Texture2DSharedPtr GetNormalTexture() noexcept;
        NODISCARD SamplerStateSharedPtr GetCommonSampler() noexcept;

        static void ComputeLightVectors(const VisualSharedPtr& mesh, const Vector4& worldLightDirection);

    private:
        NODISCARD static bool ComputeTangent(const Vector3& position0,
                                             const Vector2& textureCoordinate0,
                                             const Vector3& position1,
                                             const Vector2& textureCoordinate1,
                                             const Vector3& position2,
                                             const Vector2& textureCoordinate2,
                                             Vector3& tangent);

    private:
        Texture2DSharedPtr baseTexture;
        Texture2DSharedPtr normalTexture;
        SamplerStateSharedPtr commonSampler;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_BUMP_MAP_EFFECT_IMPL_H
