/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 11:20)

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
        DrawingState(const std::string& name, GraphicsObjectType type);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DrawingState);

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        void CheckDrawingState();
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(DrawingState);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(DrawingState);
}

#endif  // RENDERING_STATE_DRAWING_STATE_H