// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 15:49)

#ifndef PHYSICS_COLLISION_DETECTION_COLLISION_GROUP_DETAIL_H
#define PHYSICS_COLLISION_DETECTION_COLLISION_GROUP_DETAIL_H

#include "CollisionGroup.h"

template <class MeshSmartPointer, class Bound>
Physics::CollisionGroup<MeshSmartPointer, Bound>
	::CollisionGroup ()
{
}

template <class MeshSmartPointer, class Bound>
Physics::CollisionGroup<MeshSmartPointer, Bound>
	::~CollisionGroup ()
{
    
}

template <class MeshSmartPointer, class Bound>
bool Physics::CollisionGroup<MeshSmartPointer, Bound>
	::Add (std::shared_ptr<CollisionRecord<MeshSmartPointer,Bound> >  record)
{
    auto rec = mRecords.begin();
	auto end = mRecords.end();
    for (; rec != end; ++rec)
    {
        if (record == *rec)
        {
            return false;
        }
    }

    mRecords.push_back(record);
    return true;
}

template <class MeshSmartPointer, class Bound>
bool Physics::CollisionGroup<MeshSmartPointer, Bound>
	::Remove (std::shared_ptr<CollisionRecord<MeshSmartPointer,Bound> >  record)
{
	auto rec = mRecords.begin();
	auto end = mRecords.end();
    for (; rec != end; ++rec)
    {
        if (record == *rec)
        {
            mRecords.erase(rec);
            return true;
        }
    }

    return false;
}

template <class MeshSmartPointer, class Bound>
void Physics::CollisionGroup<MeshSmartPointer, Bound>
	::TestIntersection ()
{
    // Objects are assumed to be stationary, compare all pairs.
    const int numRecords = (int)mRecords.size();
    for (int i0 = 0; i0 < numRecords; ++i0)
    {
        CollisionRecordPtr record0 = mRecords[i0];
        for (int i1 = i0 + 1; i1 < numRecords; ++i1)
        {
            CollisionRecordPtr record1 = mRecords[i1];
            TestIntersection(*record0,*record1);
        }
    }
}

template <class MeshSmartPointer, class Bound>
void Physics::CollisionGroup<MeshSmartPointer, Bound>
	::FindIntersection ()
{
    // Objects are assumed to be stationary, compare all pairs.
    const int numRecords = (int)mRecords.size();
    for (int i0 = 0; i0 < numRecords; ++i0)
    {
        CollisionRecordPtr record0 = mRecords[i0];
        for (int i1 = i0 + 1; i1 < numRecords; ++i1)
        {
            CollisionRecordPtr record1 = mRecords[i1];
            FindIntersection(*record0,*record1);
        }
    }
}

template <class MeshSmartPointer, class Bound>
void Physics::CollisionGroup<MeshSmartPointer, Bound>
	::TestIntersection (float tmax)
{
    // Objects are assumed to be moving, compare all pairs.
    const int numRecords = (int)mRecords.size();
    for (int i0 = 0; i0 < numRecords; i0++)
    {
        CollisionRecordPtr record0 = mRecords[i0];
        for (int i1 = i0 + 1; i1 < numRecords; ++i1)
        {
            CollisionRecordPtr record1 = mRecords[i1];
			TestIntersection(*record0,*record1,tmax);
            if (record0->GetVelocity() || record1->GetVelocity())
            {
                record0->TestIntersection(tmax, *record1);
            }
        }
    }
}

template <class MeshSmartPointer, class Bound>
void Physics::CollisionGroup<MeshSmartPointer, Bound>
	::FindIntersection (float tmax)
{
    // Objects are assumed to be moving, compare all pairs.
    const int numRecords = (int)mRecords.size();
    for (int i0 = 0; i0 < numRecords; ++i0)
    {
        CollisionRecordPtr record0 = mRecords[i0];
        for (int i1 = i0 + 1; i1 < numRecords; ++i1)
        {
            CollisionRecordPtr record1 = mRecords[i1];
            FindIntersection(*record0,*record1,tmax);
        }
    }
}

#endif // PHYSICS_COLLISION_DETECTION_COLLISION_GROUP_DETAIL_H