/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:55)

#ifndef RENDERING_RENDERING_SCENE_GRAPH_FWD_H
#define RENDERING_RENDERING_SCENE_GRAPH_FWD_H

#include "CoreTools/Helper/SharedPtrMacro.h"

namespace Rendering
{
    enum class DepthType;
    enum class ViewFrustum;
    enum class VisualPrimitiveType;
    enum class VisualUpdateType;

    class CameraFrustumData;
    class PickLine;
    class ViewVolume;
    class Camera;
    class Spatial;
    class Node;
    class Visual;
    class Light;
    class ViewVolumeNode;
    class Particles;
    class ProjectionViewWorldUpdater;
    class PickLine;

    CORE_TOOLS_SHARED_PTR_DECLARE(Visual);
}

#endif  // RENDERING_RENDERING_SCENE_GRAPH_FWD_H