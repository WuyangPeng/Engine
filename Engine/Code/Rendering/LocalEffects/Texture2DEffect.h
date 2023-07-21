///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:43)

#ifndef RENDERING_LOCAL_EFFECTS_TEXTURE2D_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_TEXTURE2D_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/State/StateFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Texture2DEffect, Texture2DEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture2DEffect : public VisualEffect
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Texture2DEffect);
        using ParentType = VisualEffect;

        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;
        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;

    public:
        Texture2DEffect(ProgramFactory& factory,
                        const BaseRendererSharedPtr& baseRenderer,
                        const Texture2DSharedPtr& texture,
                        SamplerStateFilter filter,
                        SamplerStateMode mode0,
                        SamplerStateMode mode1);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture2DEffect);

        NODISCARD Texture2DSharedPtr GetTexture() noexcept;
        NODISCARD SamplerStateSharedPtr GetSamplerState() noexcept;

        void SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer) override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Texture2DEffect);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Texture2DEffect);
}

#endif  // RENDERING_LOCAL_EFFECTS_TEXTURE2D_EFFECT_H
