/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/11 19:17)

#ifndef RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TEST_H
#define RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TEST_H

#include "Rendering/Base/GraphicsObject.h"

namespace Rendering
{
    class GraphicsObjectTest final : public GraphicsObject
    {
    public:
        using ClassType = GraphicsObjectTest;
        using ParentType = GraphicsObject;

        using GraphicsObjectTestSharedPtr = std::shared_ptr<GraphicsObjectTest>;

    private:
        enum class GraphicsObjectTestCreate
        {
            Init,
        };

    public:
        NODISCARD static GraphicsObjectTestSharedPtr Create(const std::string& name, GraphicsObjectType type);
        GraphicsObjectTest(GraphicsObjectTestCreate graphicsObjectTestCreate, const std::string& name, GraphicsObjectType type);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(GraphicsObjectTest);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(GraphicsObjectTest);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(GraphicsObjectTest);
}

#endif  // RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TEST_H
