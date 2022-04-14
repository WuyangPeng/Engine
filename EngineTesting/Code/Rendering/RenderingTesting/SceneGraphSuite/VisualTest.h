// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/04 18:59)

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
        explicit VisualTest(VisualPrimitiveType type = VisualPrimitiveType::None);
        VisualTest(VisualPrimitiveType type, const VertexFormatSharedPtr& vertexformat,
                   const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(VisualTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        ControllerInterfaceSharedPtr Clone() const override;

        ObjectInterfaceSharedPtr CloneObject() const override;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(VisualTest);

#include STSTEM_WARNING_POP
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_VISUAL_TEST_H