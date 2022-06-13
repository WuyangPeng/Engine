///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/15 10:44)

#ifndef RENDERING_LOCAL_EFFECTS_VERTEX_COLOR3_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_VERTEX_COLOR3_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/VisualEffectInstance.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VertexColor3Effect : public VisualEffect
    {
    public:
        using ClassType = VertexColor3Effect;
        using ParentType = VisualEffect;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VertexColor3Effect);

    public:
        explicit VertexColor3Effect(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD VisualEffectInstanceSharedPtr CreateInstance();

        NODISCARD static VisualEffectInstanceSharedPtr CreateUniqueInstance();
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(VertexColor3Effect);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(VertexColor3Effect);

}

#endif  // RENDERING_LOCAL_EFFECTS_VERTEX_COLOR3_EFFECT_H
