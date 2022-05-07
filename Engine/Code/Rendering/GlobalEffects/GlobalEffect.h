///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/15 13:19)

#ifndef RENDERING_GLOBAL_EFFECTS_GLOBAL_EFFECT_H
#define RENDERING_GLOBAL_EFFECTS_GLOBAL_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE GlobalEffect : public CoreTools::Object
    {
    public:
        using ClassType = GlobalEffect;
        using ParentType = Object;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        CORE_TOOLS_OBJECT_FACTORY_DECLARE(GlobalEffect);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    protected:
        explicit GlobalEffect(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

    public:
        virtual void Draw(Renderer& renderer, VisibleSet& visibleSet) = 0;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(GlobalEffect);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(GlobalEffect);
}

#endif  // RENDERING_GLOBAL_EFFECTS_GLOBAL_EFFECT_H
