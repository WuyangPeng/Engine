///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 16:37)

#ifndef PHYSICS_COLLISION_DETECTION_COLLISION_GROUP_DETAIL_H
#define PHYSICS_COLLISION_DETECTION_COLLISION_GROUP_DETAIL_H

#include "CollisionGroup.h"
#include "CollisionRecordDetail.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

template <typename MeshSharedPointer, class Bound>
Physics::CollisionGroup<MeshSharedPointer, Bound>::CollisionGroup() noexcept
    : records{}
{
    PHYSICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename MeshSharedPointer, typename Bound>
bool Physics::CollisionGroup<MeshSharedPointer, Bound>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename MeshSharedPointer, class Bound>
bool Physics::CollisionGroup<MeshSharedPointer, Bound>::Add(const std::shared_ptr<CollisionRecord<MeshSharedPointer, Bound>>& record)
{
    PHYSICS_CLASS_IS_VALID_1;

    for (auto rec = records.begin(); rec != records.end(); ++rec)
    {
        if (record == *rec)
        {
            return false;
        }
    }

    records.emplace_back(record);
    return true;
}

template <typename MeshSharedPointer, class Bound>
bool Physics::CollisionGroup<MeshSharedPointer, Bound>::Remove(const std::shared_ptr<CollisionRecord<MeshSharedPointer, Bound>>& record) noexcept
{
    PHYSICS_CLASS_IS_VALID_1;

    for (auto rec = records.begin(); rec != records.end(); ++rec)
    {
        if (record == *rec)
        {
            records.erase(rec);
            return true;
        }
    }

    return false;
}

template <typename MeshSharedPointer, class Bound>
void Physics::CollisionGroup<MeshSharedPointer, Bound>::TestIntersection()
{
    PHYSICS_CLASS_IS_VALID_1;

    const auto numRecords = boost::numeric_cast<int>(records.size());
    for (auto i0 = 0; i0 < numRecords; ++i0)
    {
        auto record0 = records.at(i0);
        for (auto i1 = i0 + 1; i1 < numRecords; ++i1)
        {
            auto record1 = records.at(i1);
            Physics::TestIntersection(*record0, *record1);
        }
    }
}

template <typename MeshSharedPointer, class Bound>
void Physics::CollisionGroup<MeshSharedPointer, Bound>::FindIntersection()
{
    PHYSICS_CLASS_IS_VALID_1;

    const auto numRecords = boost::numeric_cast<int>(records.size());
    for (auto i0 = 0; i0 < numRecords; ++i0)
    {
        auto record0 = records.at(i0);
        for (auto i1 = i0 + 1; i1 < numRecords; ++i1)
        {
            auto record1 = records.at(i1);
            Physics::FindIntersection(*record0, *record1);
        }
    }
}

template <typename MeshSharedPointer, class Bound>
void Physics::CollisionGroup<MeshSharedPointer, Bound>::TestIntersection(float tmax)
{
    PHYSICS_CLASS_IS_VALID_1;

    const auto numRecords = boost::numeric_cast<int>(records.size());
    for (auto i0 = 0; i0 < numRecords; i0++)
    {
        auto record0 = records.at(i0);
        for (auto i1 = i0 + 1; i1 < numRecords; ++i1)
        {
            auto record1 = records.at(i1);
            Physics::TestIntersection(*record0, *record1, tmax);
        }
    }
}

template <typename MeshSharedPointer, class Bound>
void Physics::CollisionGroup<MeshSharedPointer, Bound>::FindIntersection(float tmax)
{
    PHYSICS_CLASS_IS_VALID_1;

    const auto numRecords = boost::numeric_cast<int>(records.size());
    for (auto i0 = 0; i0 < numRecords; ++i0)
    {
        auto record0 = records.at(i0);
        for (auto i1 = i0 + 1; i1 < numRecords; ++i1)
        {
            auto record1 = records.at(i1);
            Physics::FindIntersection(*record0, *record1, tmax);
        }
    }
}

#endif  // PHYSICS_COLLISION_DETECTION_COLLISION_GROUP_DETAIL_H