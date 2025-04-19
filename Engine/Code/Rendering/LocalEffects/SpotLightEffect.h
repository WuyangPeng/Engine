///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/20 11:15)

#ifndef RENDERING_LOCAL_EFFECTS_SPOT_LIGHT_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_SPOT_LIGHT_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "LightEffect.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/DataTypes/Colour.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SpotLightEffect : public LightEffect
    {
    public:
        using ClassType = SpotLightEffect;
        using ParentType = LightEffect;

        using ColourType = Colour<float>;

    public:
        explicit SpotLightEffect(ProgramFactory& factory,
                                 const BaseRendererSharedPtr& baseRenderer,
                                 bool select,
                                 const MaterialSharedPtr& material,
                                 const LightSharedPtr& lighting,
                                 const LightCameraGeometrySharedPtr& geometry);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(SpotLightEffect);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void UpdateMaterialConstant() override;
        void UpdateLightingConstant() override;
        void UpdateGeometryConstant() override;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_SPOT_LIGHT_EFFECT_H
