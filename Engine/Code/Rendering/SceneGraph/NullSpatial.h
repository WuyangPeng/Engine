/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:54)

#ifndef RENDERING_SCENE_GRAPH_NULL_SPATIAL_H
#define RENDERING_SCENE_GRAPH_NULL_SPATIAL_H

#include "Rendering/RenderingDll.h"

#include "Spatial.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE NullSpatial final : public Spatial
    {
    public:
        using ClassType = NullSpatial;
        using ParentType = Spatial;

    public:
        explicit NullSpatial(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        void GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull) noexcept override;
        NODISCARD ControllerSharedPtr Clone() const override;

        NODISCARD bool IsNullObject() const noexcept override;

    private:
        void UpdateWorldBound() noexcept override;
    };
}

#endif  // RENDERING_SCENE_GRAPH_NULL_SPATIAL_H
