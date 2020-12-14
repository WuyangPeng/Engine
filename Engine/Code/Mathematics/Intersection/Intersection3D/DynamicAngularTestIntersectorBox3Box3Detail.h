// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:21)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H

#include "DynamicAngularTestIntersectorBox3Box3.h" 

template <typename Real>
Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>
	::DynamicAngularTestIntersectorBox3Box3(const Box3& box0, const Box3& box1, Real tmax, int numSteps, const Vector3D& lhsVelocity, const Vector3D& lhsRotCenter,
											const Vector3D& lhsRotAxis, const Vector3D& rhsVelocity, const Vector3D& rhsRotCenter, const Vector3D& rhsRotAxis, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mBox0{ box0 }, mBox1{ box1 }, m_NumSteps{ numSteps },
	 m_LhsRotCenter{ lhsRotCenter }, m_LhsRotAxis{ lhsRotAxis }, m_RhsRotCenter{ rhsRotCenter }, m_RhsRotAxis{ rhsRotAxis }
{
	mQuantity = 0;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>
	::GetBox0() const
{
	return mBox0;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>
	::GetBox1() const
{
	return mBox1;
}

template <typename Real>
int Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>
	::GetQuantity() const
{
	return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>
	::GetPoint(int i) const
{
	return mPoint[i];
}

template <typename Real>
void Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>
	::Test()
{
	auto  numSteps = m_NumSteps;
	// The time step for the integration.
	auto stepsize = this->GetTMax() / static_cast<Real>(numSteps);

	// Initialize subinterval boxes.
	auto subBox0 = mBox0;
	auto subBox1 = mBox1;

	// Integrate the differential equations using Euler's method.
	for (auto istep = 1; istep <= numSteps; ++istep)
	{
		// Compute box velocities and test boxes for intersection.
		auto subTime = stepsize * static_cast<Real>(istep);
		auto newRotCenter0 = m_LhsRotCenter + subTime * this->GetLhsVelocity();
		auto newRotCenter1 = m_RhsRotCenter + subTime * this->GetRhsVelocity();
		auto diff0 = subBox0.GetCenter() - newRotCenter0;
		auto diff1 = subBox1.GetCenter() - newRotCenter1;
		auto subVelocity0 = stepsize * (this->GetLhsVelocity() + Vector3DTools::CrossProduct(m_LhsRotAxis, diff0));
		auto subVelocity1 = stepsize * (this->GetRhsVelocity() + Vector3DTools::CrossProduct(m_RhsRotAxis, diff1));

		DynamicTestIntersectorBox3Box3<Real> calc{ subBox0, subBox1,stepsize, subVelocity0, subVelocity1 };
		if (calc.IsIntersection())
		{
			SetIntersectionType(calc.GetIntersectionType());
			return;
		}

		// Update the box centers.		
		subBox0 = subBox0.GetMove(1, subVelocity0);
		subBox1 = subBox1.GetMove(1, subVelocity1);

		// Update the box axes.
		std::vector<Vector3D> axis0(3);
		std::vector<Vector3D> axis1(3);
		for (auto i = 0; i < 3; ++i)
		{
			axis0[i] = subBox0.GetAxis(i) + stepsize * Vector3DTools::CrossProduct(m_LhsRotAxis, subBox0.GetAxis(i));

			axis1[i] = subBox1.GetAxis(i) + stepsize * Vector3DTools::CrossProduct(m_RhsRotAxis, subBox1.GetAxis(i));
		}

		// Use Gram-Schmidt to orthonormalize the updated axes.  NOTE:  If
		// T/N is small and N is small, you can remove this expensive stepsize
		// with the assumption that the updated axes are nearly orthonormal.
		auto vector3DOrthonormalize0 = Vector3DTools::Orthonormalize(axis0);
		auto vector3DOrthonormalize1 = Vector3DTools::Orthonormalize(axis1);

		subBox0 = Box3{ subBox0.GetCenter(),vector3DOrthonormalize0.GetUVector(),
						vector3DOrthonormalize0.GetVVector(),vector3DOrthonormalize0.GetWVector(),
						subBox0.GetExtent0(),subBox0.GetExtent1(),subBox0.GetExtent2() };

		subBox1 = Box3{ subBox1.GetCenter(),vector3DOrthonormalize1.GetUVector(),
						vector3DOrthonormalize1.GetVVector(),vector3DOrthonormalize1.GetWVector(),
						subBox1.GetExtent0(),subBox1.GetExtent1(),subBox1.GetExtent2() };
	}

	// NOTE:  If the boxes do not intersect, then the application might want
	// to move/rotate the boxes to their new locations.  In this case you
	// want to return the final values of subBox0 and subBox1 so that the
	// application can set rkBox0 <- subBox0 and rkBox1 <- subBox1.
	// Otherwise, the application would have to solve the differential
	// equation again or compute the new box locations using the closed form
	// solution for the rigid motion.

	this->SetIntersectionType(IntersectionType::Empty);
	return;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H