/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 10:18)

#ifndef RENDERING_LOCAL_EFFECTS_AREA_LIGHT_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_AREA_LIGHT_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/State/StateFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(AreaLightEffect, AreaLightEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE AreaLightEffect : public VisualEffect
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(AreaLightEffect);
        using ParentType = VisualEffect;

        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;

    public:
        explicit AreaLightEffect(const std::string& name,
                                 ProgramFactory& factory,
                                 const BaseRendererSharedPtr& baseRenderer,
                                 SamplerStateFilter filter,
                                 SamplerStateMode mode0,
                                 SamplerStateMode mode1,
                                 const Texture2DSharedPtr& baseTexture,
                                 const Texture2DSharedPtr& normalTexture);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(AreaLightEffect);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer) override;

        NODISCARD ConstConstantBufferSharedPtr GetMaterialConstant() const noexcept;
        NODISCARD ConstConstantBufferSharedPtr GetCameraConstant() const noexcept;
        NODISCARD ConstConstantBufferSharedPtr GetAreaLightConstant() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_AREA_LIGHT_EFFECT_H
