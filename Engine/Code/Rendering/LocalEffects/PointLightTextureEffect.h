///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/19 11:11)

#ifndef RENDERING_LOCAL_EFFECTS_POINT_LIGHT_TEXTURE_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_POINT_LIGHT_TEXTURE_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "LightEffect.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/State/StateFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(PointLightTextureEffect, PointLightTextureEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PointLightTextureEffect : public LightEffect
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(PointLightTextureEffect);
        using ParentType = LightEffect;

        using ColourType = Colour<float>;
        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;

    public:
        explicit PointLightTextureEffect(ProgramFactory& factory,
                                         const BaseRendererSharedPtr& baseRenderer,
                                         const MaterialSharedPtr& material,
                                         const LightSharedPtr& lighting,
                                         const LightCameraGeometrySharedPtr& geometry,
                                         const Texture2DSharedPtr& texture,
                                         SamplerStateFilter filter,
                                         SamplerStateMode mode0,
                                         SamplerStateMode mode1);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(PointLightTextureEffect);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void UpdateMaterialConstant() override;
        void UpdateLightingConstant() override;
        void UpdateGeometryConstant() override;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_POINT_LIGHT_TEXTURE_EFFECT_H
