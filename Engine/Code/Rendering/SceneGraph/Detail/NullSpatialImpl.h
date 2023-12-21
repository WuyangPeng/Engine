///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.2 (2023/12/07 10:58)

#ifndef RENDERING_SCENE_GRAPH_NULL_SPATIAL_IMPL_H
#define RENDERING_SCENE_GRAPH_NULL_SPATIAL_IMPL_H

#include "Rendering/RenderingDll.h"

#include "SpatialImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE NullSpatialImpl final : public SpatialImpl
    {
    public:
        using ClassType = NullSpatialImpl;
        using ParentType = SpatialImpl;

    public:
        explicit NullSpatialImpl(CullingMode cullingMode) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SetParent(const SpatialSharedPtr& aParent) noexcept override;
        NODISCARD SpatialSharedPtr GetParent() override;
        NODISCARD ConstSpatialSharedPtr GetParent() const override;

        NODISCARD SpatialImplSharedPtr Clone() const override;
    };
}

#endif  // RENDERING_SCENE_GRAPH_NULL_SPATIAL_IMPL_H
