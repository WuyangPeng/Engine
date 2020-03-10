// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 15:33)

#ifndef PHYSICS_COLLISION_DETECTION_COLLISION_GROUP_H
#define PHYSICS_COLLISION_DETECTION_COLLISION_GROUP_H

#include "Physics/PhysicsDll.h"

#include "CollisionRecord.h"

// Class Mesh must have the following functions in its interface.
//    int GetNumVertices () const;
//    Float3 GetPosition (int i) const;
//    int GetNumTriangles () const;
//    bool GetTriangle (int triangle, int& i0, int& i1, int& i2) const;
//    bool GetModelTriangle (int triangle, APoint* modelTriangle) const;
//    bool GetWorldTriangle (int triangle, APoint* worldTriangle) const;
//    const Transform& GetWorldTransform () const;
//
// Class Bound must have the following functions in its interface.
//    Bound ();  // default constructor
//    void ComputeFromData (int numElements, int stride, const char* data);
//    void TransformBy (const Transform& transform, Bound& bound) const;
//    bool TestIntersection (const Bound& bound) const;
//    bool TestIntersection (const Bound& bound, float tmax,
//        const AVector& velocity0, const AVector& velocity1) const;

namespace Physics
{
	template <typename MeshSmartPointer, typename Bound>
	class CollisionGroup
	{
	public:
		CollisionGroup ();
		~CollisionGroup ();

		// CollisionGroup assumes responsibility for deleting the collision
		// records, so the input records should be dynamically allocated.
		bool Add (std::shared_ptr<CollisionRecord<MeshSmartPointer,Bound> > record);
		bool Remove (std::shared_ptr<CollisionRecord<MeshSmartPointer,Bound> > record);

		// Intersection queries.  If two objects in the group collide, the
		// corresponding records process the information accordingly.

		// The objects are assumed to be stationary (velocities are ignored) and
		// all pairs of objects are compared.
		void TestIntersection ();
		void FindIntersection ();

		// The objects are assumed to be moving.  Objects are compared when at
		// least one of them has a velocity vector associated with it (that
		// vector is allowed to be the zero vector).
		void TestIntersection (float tmax);
		void FindIntersection (float tmax);

		// The CollisionRecord callback function is executed for each pair of
		// intersecting triangles.  The Intersector<float,Mathematics::Vector3Df> used in the
		// collision system is passed to the application via the callback.  The
		// following information is available from the intersector.
		//
		// TestIntersection() calls:
		//   int type = intersector.GetIntersectionType();
		//   <type is IT_OTHER for nonparallel triangles>;
		//   <type is IT_PLANE for parallel triangles>;
		//
		// FindIntersection() calls:
		//   int type = intersector.GetIntersectionType();
		//   <type is IT_POINT for a single point of intersection>;
		//   <type is IT_SEGMENT for a segment of intersection points>;
		//   <type is IT_PLANE for a polygon of intersection points>;
		//   int numPoints = intersector.GetQuantity();
		//   Mathematics::Vector3Df point = intersector.GetPoint(i);  // 0 <= i < numPoints
		//
		// TestIntersection(tmax) calls:
		//   float contactTime = intersector.GetContactTime(); // in [0,tmax]
		//   int type = intersector.GetIntersectionType();
		//   <type is IT_OTHER for nonparallel triangles>;
		//   <type is IT_PLANE for parallel triangles>;
		//
		// FindIntersection(tmax) calls:
		//   float contactTime = intersector.GetContactTime(); // in [0,tmax]
		//   int type = intersector.GetIntersectionType();
		//   <type is IT_POINT for a single point of intersection>;
		//   <type is IT_SEGMENT for a segment of intersection points>;
		//   <type is IT_PLANE for a polygon of intersection points>;
		//   int numPoints = intersector.GetQuantity();
		//   Mathematics::Vector3Df point = intersector.GetPoint(i);  // 0 <= i < numPoints

	protected:
		typedef std::shared_ptr<CollisionRecord<MeshSmartPointer,Bound> > CollisionRecordPtr;
		std::vector<CollisionRecordPtr> mRecords;
	};
}

#endif // PHYSICS_COLLISION_DETECTION_COLLISION_GROUP_H
