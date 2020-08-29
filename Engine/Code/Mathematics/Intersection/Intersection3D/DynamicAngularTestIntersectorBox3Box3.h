// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:42)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h" 
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicAngularTestIntersectorBox3Box3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicAngularTestIntersectorBox3Box3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		DynamicAngularTestIntersectorBox3Box3(const Box3& box0, const Box3& box1, Real tmax, int numSteps, const Vector3D& lhsVelocity, const Vector3D& lhsRotCenter,
											  const Vector3D& lhsRotAxis, const Vector3D& rhsVelocity, const Vector3D& rhsRotCenter, const Vector3D& rhsRotAxis, const Real epsilon = Math::GetZeroTolerance());

		// Object access.
		const Box3 GetBox0() const;
		const Box3 GetBox1() const;

		// The intersection set for dynamic find-intersection.
		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;

	private:
		// Dynamic test-intersection query where the boxes have constant linear
		// velocities *and* constant angular velocities.  The length of the
		// rotation axes are the angular speeds.  A differential equation solver
		// is used to predict the intersection.  The input numSteps is the
		// number of iterations for the numerical ODE solver.
		void Test();

		// The objects to intersect.
		Box3 mBox0;
		Box3 mBox1;

		// The intersection set for dynamic find-intersection.  The worst case
		// is a polygon with 8 vertices.
		int mQuantity;
		Vector3D mPoint[8];
		int m_NumSteps;
		Vector3D m_LhsRotCenter;
		Vector3D m_LhsRotAxis;
		Vector3D m_RhsRotCenter;
		Vector3D m_RhsRotAxis;
	};

	using DynamicAngularTestIntersectorBox3Box3f = DynamicAngularTestIntersectorBox3Box3<float>;
	using DynamicAngularTestIntersectorBox3Box3d = DynamicAngularTestIntersectorBox3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_H
