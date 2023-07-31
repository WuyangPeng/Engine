///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/22 13:14)

#ifndef RENDERING_LOCAL_EFFECTS_VOLUME_FOG_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_VOLUME_FOG_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/State/StateFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(VolumeFogEffect, VolumeFogEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VolumeFogEffect : public VisualEffect
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(VolumeFogEffect);
        using ParentType = VisualEffect;

        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;
        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;

    public:
        VolumeFogEffect(ProgramFactory& factory,
                        const BaseRendererSharedPtr& baseRenderer,
                        const Texture2DSharedPtr& texture,
                        SamplerStateFilter filter,
                        SamplerStateMode mode0,
                        SamplerStateMode mode1);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VolumeFogEffect);

        NODISCARD Texture2DSharedPtr GetTexture() noexcept;
        NODISCARD SamplerStateSharedPtr GetSamplerState() noexcept;

        void SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer) override;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_VOLUME_FOG_EFFECT_H