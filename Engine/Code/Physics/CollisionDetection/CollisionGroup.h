///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 16:38)

#ifndef PHYSICS_COLLISION_DETECTION_COLLISION_GROUP_H
#define PHYSICS_COLLISION_DETECTION_COLLISION_GROUP_H

#include "Physics/PhysicsDll.h"

#include "CollisionRecord.h"

namespace Physics
{
    template <typename MeshSharedPointer, typename Bound>
    class CollisionGroup
    {
    public:
        using ClassType = CollisionGroup<MeshSharedPointer, Bound>;

    public:
        CollisionGroup() noexcept;

        CLASS_INVARIANT_DECLARE;

        bool Add(const std::shared_ptr<CollisionRecord<MeshSharedPointer, Bound>>& record);
        bool Remove(const std::shared_ptr<CollisionRecord<MeshSharedPointer, Bound>>& record) noexcept;

        void TestIntersection();
        void FindIntersection();

        void TestIntersection(float tmax);
        void FindIntersection(float tmax);

    private:
        using CollisionRecordSharedPtr = std::shared_ptr<CollisionRecord<MeshSharedPointer, Bound>>;

    private:
        std::vector<CollisionRecordSharedPtr> records;
    };
}

#endif  // PHYSICS_COLLISION_DETECTION_COLLISION_GROUP_H
