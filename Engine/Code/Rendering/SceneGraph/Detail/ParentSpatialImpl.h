/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:48)

#ifndef RENDERING_SCENE_GRAPH_PARENT_SPATIAL_IMPL_H
#define RENDERING_SCENE_GRAPH_PARENT_SPATIAL_IMPL_H

#include "Rendering/RenderingDll.h"

#include "SpatialImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ParentSpatialImpl final : public SpatialImpl
    {
    public:
        using ClassType = ParentSpatialImpl;
        using ParentType = SpatialImpl;

    public:
        explicit ParentSpatialImpl(CullingMode cullingMode);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetParent(const SpatialSharedPtr& aParent) override;
        NODISCARD SpatialSharedPtr GetParent() override;
        NODISCARD ConstSpatialSharedPtr GetParent() const override;

        NODISCARD SpatialImplSharedPtr Clone() const override;

    private:
        // 支持层次场景图。Spatial提供父指针。Node提供了子指针。
        SpatialWeakPtr parent;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PARENT_SPATIAL_IMPL_H
