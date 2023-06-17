///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:42)

#ifndef RENDERING_LOCAL_EFFECTS_LIGHT_DIR_PER_PIX_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_LIGHT_DIR_PER_PIX_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Light.h"
#include "Rendering/SceneGraph/Material.h"
#include "Rendering/Shaders/VisualEffectInstance.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE LightDirPerPixEffect : public VisualEffect
    {
    public:
        using ClassType = LightDirPerPixEffect;
        using ParentType = VisualEffect;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(LightDirPerPixEffect);

    public:
        explicit LightDirPerPixEffect(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD VisualEffectInstanceSharedPtr CreateInstance(const LightSharedPtr& light, const MaterialSharedPtr& material);

        NODISCARD static VisualEffectInstanceSharedPtr CreateUniqueInstance(const LightSharedPtr& light, const MaterialSharedPtr& material);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(LightDirPerPixEffect);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(LightDirPerPixEffect);
}

#endif  // RENDERING_LOCAL_EFFECTS_LIGHT_DIR_PER_PIX_EFFECT_H
