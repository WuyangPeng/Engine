///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/06 17:27)

#ifndef RENDERING_LOCAL_EFFECTS_LIGHT_AMBIENT_LIGHT_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_LIGHT_AMBIENT_LIGHT_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "LightEffect.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/LocalEffects/Lighting.h" 
#include "Rendering/LocalEffects/Material.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE AmbientLightEffect : public LightEffect
    {
    public:
        using ClassType = AmbientLightEffect;
        using ParentType = LightEffect;

        using Colour = Colour<float>;

    public:
        explicit AmbientLightEffect(ProgramFactory& factory,
                                    const BaseRendererSharedPtr& baseRenderer,
                                    const MaterialSharedPtr& material,
                                    const LightSharedPtr& lighting);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(AmbientLightEffect);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void UpdateMaterialConstant() override;
        void UpdateLightingConstant() override;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(AmbientLightEffect);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(AmbientLightEffect);
}

#endif  // RENDERING_LOCAL_EFFECTS_LIGHT_AMBIENT_LIGHT_EFFECT_H
