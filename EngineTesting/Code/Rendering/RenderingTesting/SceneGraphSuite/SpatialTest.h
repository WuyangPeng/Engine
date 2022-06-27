///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/14 18:51)

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
        explicit SpatialTest(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(SpatialTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;

        void GetVisibleSet(Culler& culler, bool noCull) noexcept override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        void UpdateWorldBound() noexcept override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(SpatialTest);

#include STSTEM_WARNING_POP
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_SPATIAL_TEST_H