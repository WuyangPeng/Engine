///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/20 20:16)

#ifndef RENDERING_LOCAL_EFFECTS_TEXTURE_3D_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_TEXTURE_3D_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/State/StateFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Texture3DEffect, Texture3DEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture3DEffect : public VisualEffect
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Texture3DEffect);
        using ParentType = VisualEffect;

        using Texture3DSharedPtr = std::shared_ptr<Texture3D>;
        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;

    public:
        explicit Texture3DEffect(ProgramFactory& factory,
                                 const BaseRendererSharedPtr& baseRenderer,
                                 const Texture3DSharedPtr& texture,
                                 SamplerStateFilter filter,
                                 SamplerStateMode mode0,
                                 SamplerStateMode mode1,
                                 SamplerStateMode mode2);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(Texture3DEffect);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD Texture3DSharedPtr GetTexture() noexcept;
        NODISCARD SamplerStateSharedPtr GetSamplerState() noexcept;

        void SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer) override;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_TEXTURE_3D_EFFECT_H
