///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:31)

#ifndef RENDERING_SCENE_GRAPH_SUITE_VISUAL_TEST_H
#define RENDERING_SCENE_GRAPH_SUITE_VISUAL_TEST_H

#include "Rendering/SceneGraph/Visual.h"

namespace Rendering
{
    class VisualTest : public Visual
    {
    public:
        using ClassType = VisualTest;
        using ParentType = Visual;

    public:
        explicit VisualTest(VisualPrimitiveType type);
        VisualTest(VisualPrimitiveType type,
                   const VertexFormatSharedPtr& vertexformat,
                   const VertexBufferSharedPtr& vertexbuffer,
                   const IndexBufferSharedPtr& indexbuffer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(VisualTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ControllerSharedPtr Clone() const override;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(VisualTest);

#include SYSTEM_WARNING_POP
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_VISUAL_TEST_H