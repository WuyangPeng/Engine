///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/21 10:27)

#ifndef RENDERING_STATE_DRAWING_STATE_H
#define RENDERING_STATE_DRAWING_STATE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Base/GraphicsObject.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE DrawingState : public GraphicsObject
    {
    public:
        using ClassType = DrawingState;
        using ParentType = GraphicsObject;

    public:
        DrawingState(GraphicsObjectType type, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DrawingState);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(DrawingState);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(DrawingState);
}

#endif  // RENDERING_STATE_DRAWING_STATE_H