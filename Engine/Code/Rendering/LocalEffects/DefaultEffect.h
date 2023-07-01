///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:42)

#ifndef RENDERING_LOCAL_EFFECTS_DEFAULT_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_DEFAULT_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE DefaultEffect : public VisualEffect
    {
    public:
        using ClassType = DefaultEffect;
        using ParentType = VisualEffect;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DefaultEffect);

    public:
        explicit DefaultEffect(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(DefaultEffect);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(DefaultEffect);
}

#endif  // RENDERING_LOCAL_EFFECTS_DEFAULT_EFFECT_H
