///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/14 14:34)

#ifndef RENDERING_LOCAL_EFFECTS_LIGHT_SPT_PER_PIX_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_LIGHT_SPT_PER_PIX_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Light.h"
#include "Rendering/SceneGraph/Material.h"
#include "Rendering/Shaders/VisualEffectInstance.h"

namespace Rendering
{
    class LightSptPerPixEffect : public VisualEffect
    {
    public:
        using ClassType = LightSptPerPixEffect;
        using ParentType = VisualEffect;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(LightSptPerPixEffect);

    public:
        explicit LightSptPerPixEffect(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD VisualEffectInstanceSharedPtr CreateInstance(const LightSharedPtr& light, const MaterialSharedPtr& material);

        NODISCARD static VisualEffectInstanceSharedPtr CreateUniqueInstance(const LightSharedPtr& light, const MaterialSharedPtr& material);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(LightSptPerPixEffect);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(LightSptPerPixEffect);
}

#endif  // RENDERING_LOCAL_EFFECTS_LIGHT_SPT_PER_PIX_EFFECT_H
