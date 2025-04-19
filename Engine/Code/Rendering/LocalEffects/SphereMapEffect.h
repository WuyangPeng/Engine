///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/19 16:17)

#ifndef RENDERING_LOCAL_EFFECTS_SPHERE_MAP_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_SPHERE_MAP_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/State/StateFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(SphereMapEffect, SphereMapEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SphereMapEffect : public VisualEffect
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(SphereMapEffect);
        using ParentType = VisualEffect;

        using ColourType = Colour<float>;
        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;
        using ConstantBufferSharedPtr = std::shared_ptr<ConstantBuffer>;
        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;

    public:
        explicit SphereMapEffect(ProgramFactory& factory,
                                 const BaseRendererSharedPtr& baseRenderer,
                                 const Texture2DSharedPtr& texture,
                                 SamplerStateFilter filter,
                                 SamplerStateMode mode0,
                                 SamplerStateMode mode1);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(SphereMapEffect);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD Texture2DSharedPtr GetTexture() noexcept;
        NODISCARD SamplerStateSharedPtr GetSamplerState() noexcept;
        NODISCARD ConstantBufferSharedPtr GetViewWorldMatrixConstant() noexcept;

        void SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer) override;

        void SetViewWorldMatrix(const Matrix4& viewWorldMatrix);

        NODISCARD Matrix4 GetViewWorldMatrix() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_SPHERE_MAP_EFFECT_H
