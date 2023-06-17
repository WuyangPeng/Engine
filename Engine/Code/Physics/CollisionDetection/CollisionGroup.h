///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 16:38)

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
