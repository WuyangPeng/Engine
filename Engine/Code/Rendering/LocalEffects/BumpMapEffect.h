///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/07 14:12)

#ifndef RENDERING_LOCAL_EFFECTS_BUMP_MAP_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_BUMP_MAP_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/State/StateFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(BumpMapEffect, BumpMapEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE BumpMapEffect : public VisualEffect
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(BumpMapEffect);
        using ParentType = VisualEffect;

        using Vector4 = Mathematics::Vector4<float>;
        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;
        using ConstTexture2DSharedPtr = std::shared_ptr<const Texture2D>;
        using ConstSamplerStateSharedPtr = std::shared_ptr<const SamplerState>;
        using VisualSharedPtr = std::shared_ptr<Visual>;

    public:
        explicit BumpMapEffect(ProgramFactory& factory,
                               const BaseRendererSharedPtr& baseRenderer,
                               SamplerStateFilter filter,
                               SamplerStateMode mode0,
                               SamplerStateMode mode1,
                               const Texture2DSharedPtr& baseTexture,
                               const Texture2DSharedPtr& normalTexture);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(BumpMapEffect);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer) override;

        NODISCARD ConstTexture2DSharedPtr GetBaseTexture() const noexcept;
        NODISCARD ConstTexture2DSharedPtr GetNormalTexture() const noexcept;
        NODISCARD ConstSamplerStateSharedPtr GetCommonSampler() const noexcept;

        static void ComputeLightVectors(const VisualSharedPtr& mesh, const Vector4& worldLightDirection);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_BUMP_MAP_EFFECT_H
