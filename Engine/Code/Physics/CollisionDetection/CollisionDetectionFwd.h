///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/24 16:56)

#ifndef PHYSICS_COLLISION_DETECTION_FWD_H
#define PHYSICS_COLLISION_DETECTION_FWD_H

namespace Physics
{
    class BoundTreeProjectionInfo;

    template <typename MeshSharedPointer, typename Bound>
    class BoundTreeChild;

    class BoundTreeSplitTriangles;

    template <typename MeshSharedPointer, typename Bound>
    class BoundTree;

    template <typename MeshSharedPointer, typename Bound>
    class CollisionRecord;

    template <typename MeshSharedPointer, typename Bound>
    class CollisionGroup;
}

#endif  // PHYSICS_COLLISION_DETECTION_FWD_H