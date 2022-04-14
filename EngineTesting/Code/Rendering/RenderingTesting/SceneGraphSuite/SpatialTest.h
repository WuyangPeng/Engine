// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/04 18:00)

#ifndef RENDERING_SCENE_GRAPH_SUITE_SPATIAL_TEST_H
#define RENDERING_SCENE_GRAPH_SUITE_SPATIAL_TEST_H

#include "Rendering/SceneGraph/Visual.h"

namespace Rendering
{
    class SpatialTest : public Visual
    {
    public:
        using ClassType = SpatialTest;
        using ParentType = Visual;

    public:
        SpatialTest();

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(SpatialTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        ControllerInterfaceSharedPtr Clone() const override;

        void GetVisibleSet(Culler& culler, bool noCull) override;
        ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        void UpdateWorldBound() override;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(SpatialTest);

#include STSTEM_WARNING_POP
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_SPATIAL_TEST_H