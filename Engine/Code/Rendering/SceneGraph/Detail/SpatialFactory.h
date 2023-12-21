///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.2 (2023/12/07 11:02)

#ifndef RENDERING_SCENE_GRAPH_SPATIAL_FACTORY_H
#define RENDERING_SCENE_GRAPH_SPATIAL_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/SceneGraphInternalFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SpatialFactory
    {
    public:
        using ClassType = SpatialFactory;
        using SpatialSharedPtr = std::shared_ptr<SpatialImpl>;

    public:
        SpatialFactory() noexcept = delete;

        NODISCARD static SpatialSharedPtr Create(CullingMode cullingMode, bool isNull);
    };
}

#endif  // RENDERING_SCENE_GRAPH_SPATIAL_FACTORY_H
