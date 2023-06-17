///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:02)

#ifndef RENDERING_STATE_SUITE_DRAWING_STATE_TEST_H
#define RENDERING_STATE_SUITE_DRAWING_STATE_TEST_H

#include "Rendering/State/DrawingState.h"

namespace Rendering
{
    class DrawingStateTest : public DrawingState
    {
    public:
        using ClassType = DrawingStateTest;
        using ParentType = DrawingState;
        using DrawingStateTestSharedPtr = std::shared_ptr<DrawingStateTest>;

    private:
        enum class DrawingStateTestCreate
        {
            Init,
        };

    public:
        NODISCARD static DrawingStateTestSharedPtr Create(const std::string& name, GraphicsObjectType type);
        DrawingStateTest(DrawingStateTestCreate drawingStateTestCreate, const std::string& name, GraphicsObjectType type);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DrawingStateTest);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(DrawingStateTest);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(DrawingStateTest);
}

#endif  // RENDERING_STATE_SUITE_DRAWING_STATE_TEST_H
