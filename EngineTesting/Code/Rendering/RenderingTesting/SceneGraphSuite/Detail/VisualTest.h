/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/20 16:23)

#ifndef RENDERING_SCENE_GRAPH_SUITE_VISUAL_TEST_H
#define RENDERING_SCENE_GRAPH_SUITE_VISUAL_TEST_H

#include "Rendering/SceneGraph/Visual.h"

namespace Rendering
{
    class VisualTest final : public Visual
    {
    public:
        using ClassType = VisualTest;
        using ParentType = Visual;

    public:
        explicit VisualTest(const std::string& name);
        VisualTest(const std::string& name,
                   const VertexFormatSharedPtr& vertexFormat,
                   const VertexBufferSharedPtr& vertexBuffer,
                   const IndexBufferSharedPtr& indexBuffer);

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