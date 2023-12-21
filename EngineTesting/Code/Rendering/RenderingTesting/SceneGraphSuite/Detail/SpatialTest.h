/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/07 14:03)

#ifndef RENDERING_SCENE_GRAPH_SUITE_SPATIAL_TEST_H
#define RENDERING_SCENE_GRAPH_SUITE_SPATIAL_TEST_H

#include "Rendering/SceneGraph/Spatial.h"

namespace Rendering
{
    class SpatialTest final : public Spatial
    {
    public:
        using ClassType = SpatialTest;
        using ParentType = Spatial;

        using SpatialTestSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static SpatialTestSharedPtr Create(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(SpatialTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ControllerSharedPtr Clone() const override;
        void GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull) noexcept override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        enum class Constructor
        {
            Default,
        };

    public:
        explicit SpatialTest(const std::string& name, Constructor constructor);

    private:
        void UpdateWorldBound() noexcept override;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(SpatialTest);

#include SYSTEM_WARNING_POP
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_SPATIAL_TEST_H