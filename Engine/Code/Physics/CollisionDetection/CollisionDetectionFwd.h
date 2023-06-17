///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 16:38)

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