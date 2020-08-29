// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 13:37)

#ifndef MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_RAY3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_RAY3_TRIANGLE3_DETAIL_H

#include "StaticTestIntersectorRay3Triangle3.h"
#include "IntersectorLine3Triangle3DataDetail.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay3Triangle3<Real>
	::StaticTestIntersectorRay3Triangle3(const Ray3& ray, const Triangle3& triangle, const Real epsilon) 
	:ParentType{ epsilon }, m_Ray{ ray }, m_Triangle{ triangle }
{
	Test();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::StaticTestIntersectorRay3Triangle3<Real>
	::~StaticTestIntersectorRay3Triangle3() 
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorRay3Triangle3<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real>
const Mathematics::Ray3<Real> Mathematics::StaticTestIntersectorRay3Triangle3<Real>
	::GetRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorRay3Triangle3<Real>
	::GetTriangle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Triangle;
}

// private
template <typename Real>
void Mathematics::StaticTestIntersectorRay3Triangle3<Real>
	::Test() 
{
	// Compute the offset origin, edges, and normal.
	auto diff = m_Ray.GetOrigin() - m_Triangle.GetVertex(0);
	auto edge1 = m_Triangle.GetVertex(1) - m_Triangle.GetVertex(0);
	auto edge2 = m_Triangle.GetVertex(2)- m_Triangle.GetVertex(0);
	auto normal = Vector3DTools::CrossProduct(edge1,edge2);

	// Solve Q + t*D = b1*E1 + b2*E2 (Q = kDiff, D = ray direction,
	// E1 = kEdge1, E2 = kEdge2, N = Cross(E1,E2)) by
	//   |Dot(D,N)|*b1 = sign(Dot(D,N))*Dot(D,Cross(Q,E2))
	//   |Dot(D,N)|*b2 = sign(Dot(D,N))*Dot(D,Cross(E1,Q))
	//   |Dot(D,N)|*t = -sign(Dot(D,N))*Dot(Q,N)
	auto DdN = Vector3DTools::DotProduct(m_Ray.GetDirection(),normal);
	Real sign;
	if (DdN > Math::GetZeroTolerance())
	{
		sign = static_cast<Real>(1);
	}
	else if (DdN < -Math::GetZeroTolerance())
	{
		sign = (Real)-1;
		DdN = -DdN;
	}
	else
	{
		// Ray and triangle are parallel, call it a "no intersection"
		// even if the ray does intersect.
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	auto DdQxE2 = sign*  Vector3DTools::DotProduct(m_Ray.GetDirection(), Vector3DTools::CrossProduct( diff,edge2));
	if (DdQxE2 >= Math<Real>::GetValue(0))
	{
		auto DdE1xQ = sign*Vector3DTools::DotProduct(m_Ray.GetDirection(), Vector3DTools::CrossProduct( edge1,diff));
		if (DdE1xQ >= Math<Real>::GetValue(0))
		{
			if (DdQxE2 + DdE1xQ <= DdN)
			{
				// Line intersects triangle, check if ray does.
				auto QdN = -sign*Vector3DTools::DotProduct(diff,normal);
				if (QdN >= Math<Real>::GetValue(0))
				{
					// Ray intersects triangle.
		
					this->SetIntersectionType(IntersectionType::Point);
					return;
				}
				// else: t < 0, no intersection
			}
			// else: b1+b2 > 1, no intersection
		}
		// else: b2 < 0, no intersection
	}
	// else: b1 < 0, no intersection
	
	this->SetIntersectionType(IntersectionType::Empty);
}
 
#endif // MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_RAY3_TRIANGLE3_DETAIL_H