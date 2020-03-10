// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/15 10:05)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H

#include "StaticFindIntersectorTriangle3Triangle3.h"
#include "TrianglePlaneRelations.h"
#include "TriangleProjectOntoAxis.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Objects3D/Plane3Detail.h"
#include "Mathematics/Objects3D/Triangle3Detail.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"


template <typename Real>
Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::StaticFindIntersectorTriangle3Triangle3(const Triangle3& lhsTriangle,const Triangle3& rhsTriangle,bool reportCoplanarIntersections,const Real epsilon)
	:ParentType{ epsilon }, m_LhsTriangle{ lhsTriangle }, m_RhsTriangle{ rhsTriangle }, m_ReportCoplanarIntersections{ reportCoplanarIntersections }
{
	Find();

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::Find()
{
	// 获取m_LhsTriangle的平面
	Plane3 lhsPlane0{ m_LhsTriangle };

	// 计算三角形m_RhsTriangle顶点到平面lhsPlane0的有符号距离。使用epsilon-thick测试。
	TrianglePlaneRelations<Real> rhsTrianglePlaneRelations{ m_RhsTriangle, lhsPlane0, this->GetEpsilon() };

	if (rhsTrianglePlaneRelations.GetPositive() == 3 || rhsTrianglePlaneRelations.GetNegative() == 3)
	{
		// 三角形m_RhsTriangle完全在平面lhsPlane的一侧。
		return;
	}
 
	if (rhsTrianglePlaneRelations.GetZero() == 3)
	{
		// 三角形m_RhsTriangle由平面lhsPlane包含。
		if (m_ReportCoplanarIntersections)
		{
			GetCoplanarIntersection(lhsPlane0, m_LhsTriangle, m_RhsTriangle);
			return;
		}
		return;
	}

 	// 检查三角形m_RhsTriangle和平面lhsPlane之间的接触。
	if (rhsTrianglePlaneRelations.GetPositive() == 0 || rhsTrianglePlaneRelations.GetNegative() == 0)
	{
		if (rhsTrianglePlaneRelations.GetZero() == 2)
		{ 
			// 三角形m_RhsTriangle的边在平面lhsPlane中。
			for (int i = 0; i < 3; ++i)
			{
				if (rhsTrianglePlaneRelations.GetSign(i) != 0)
				{
					auto iM = (i + 2) % 3;
					auto iP = (i + 1) % 3;
					 IntersectsSegment(lhsPlane0, m_LhsTriangle, m_RhsTriangle.GetVertex()[iM],m_RhsTriangle.GetVertex()[iP]);
					 return;
				}
			}
		}
		else 
		{
			MATHEMATICS_ASSERTION_2(rhsTrianglePlaneRelations.GetZero() == 1, "三角形和平面接触计算错误！");

			// 三角形m_RhsTriangle的顶点在平面lhsPlane中。
			for (auto i = 0; i < 3; ++i)
			{
				if (rhsTrianglePlaneRelations.GetSign(i) == 0)
				{
					 ContainsPoint(m_LhsTriangle, lhsPlane0, m_RhsTriangle.GetVertex()[i]);
					 return;
				}
			}
		}
	} 		

	// 此时，三角形m_RhsTriangle横向与平面lhsPlane相交。计算交点的线段。
	// 然后测试这个线段和三角形m_LhsTriangle之间的交集。
	if (rhsTrianglePlaneRelations.GetZero() == 0)
	{
		auto sign = (rhsTrianglePlaneRelations.GetPositive() == 1 ? NumericalValueSymbol::Positive : NumericalValueSymbol::Negative);
		for (auto i = 0; i < 3; ++i)
		{
			if (rhsTrianglePlaneRelations.GetSign(i) == sign)
			{
				int iM = (i + 2) % 3;
				int iP = (i + 1) % 3;
				auto t = rhsTrianglePlaneRelations.GetDistance(i) / (rhsTrianglePlaneRelations.GetDistance(i) - rhsTrianglePlaneRelations.GetDistance(iM));
				auto intr0 = m_RhsTriangle.GetVertex()[i] + t*(m_RhsTriangle.GetVertex()[iM] - m_RhsTriangle.GetVertex()[i]);
				t = rhsTrianglePlaneRelations.GetDistance(i) / (rhsTrianglePlaneRelations.GetDistance(i) - rhsTrianglePlaneRelations.GetDistance(iP));
				auto intr1 = m_RhsTriangle.GetVertex()[i] + t*(m_RhsTriangle.GetVertex()[iP] - m_RhsTriangle.GetVertex()[i]);
				 IntersectsSegment(lhsPlane0, m_LhsTriangle, intr0, intr1);
				 return;
			}
		}
	}
		
	// zero1 == 1
	for (int i = 0; i < 3; ++i)
	{
		if (rhsTrianglePlaneRelations.GetSign(i) == NumericalValueSymbol::Zero)
		{
			auto iM = (i + 2) % 3;
			auto iP = (i + 1) % 3;
			auto t = rhsTrianglePlaneRelations.GetDistance(iM) / (rhsTrianglePlaneRelations.GetDistance(iM) - rhsTrianglePlaneRelations.GetDistance(iP));
			auto intr0 = m_RhsTriangle.GetVertex()[iM] + t*(m_RhsTriangle.GetVertex()[iP] - m_RhsTriangle.GetVertex()[iM]);
			 IntersectsSegment(lhsPlane0,m_LhsTriangle, m_RhsTriangle.GetVertex()[i], intr0);
			 return;
		}
	}	

	MATHEMATICS_ASSERTION_2(false, "逻辑不应该执行到这里！\n");
}



template <typename Real>
Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::~StaticFindIntersectorTriangle3Triangle3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}


#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else
		return false;
}


#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::Triangle3 Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::GetLhsTriangle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_LhsTriangle;
}


template <typename Real>
typename const Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>::Triangle3 Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::GetRhsTriangle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_RhsTriangle;
}


template <typename Real>
int Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::GetQuantity () const
{
	return mQuantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::GetPoint (int i) const
{
	return mPoint[i];
}


template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::ProjectOntoAxis (const Triangle3& triangle, const Vector3D& axis, Real& fmin,Real& fmax)
{
	auto dot0 = Vector3DTools::DotProduct(axis,triangle.GetVertex()[0]);
	auto dot1 = Vector3DTools::DotProduct(axis,triangle.GetVertex()[1]);
	auto dot2 = Vector3DTools::DotProduct(axis,triangle.GetVertex()[2]);

	fmin = dot0;
	fmax = fmin;

	if (dot1 < fmin)
	{
		fmin = dot1;
	}
	else if (dot1 > fmax)
	{
		fmax = dot1;
	}

	if (dot2 < fmin)
	{
		fmin = dot2;
	}
	else if (dot2 > fmax)
	{
		fmax = dot2;
	}
}
 

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::GetInterval (const Triangle3& triangle, const Line3& line,const Real distance[3], const int sign[3], Real param[2])
{
	// Project triangle onto line.
	Real proj[3];
	int i;
	for (i = 0; i < 3; i++)
	{
		auto diff = triangle.GetVertex()[i] - line.GetOrigin();
		proj[i] = Vector3DTools::DotProduct(line.GetDirection(),diff);
	}

	// Compute transverse intersections of triangle edges with line.
	Real numer, denom;
	int i0, i1, i2;
	int quantity = 0;
	for (i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
	{
		if (sign[i0]*sign[i1] < 0)
		{
			MATHEMATICS_ASSERTION_0(quantity < 2, "Unexpected condition\n");
			numer = distance[i0]*proj[i1] - distance[i1]*proj[i0];
			denom = distance[i0] - distance[i1];
			param[quantity++] = numer/denom;
		}
	}

	// Check for grazing contact.
	if (quantity < 2)
	{
		for (i0 = 1, i1 = 2, i2 = 0; i2 < 3; i0 = i1, i1 = i2++)
		{
			if (sign[i2] == 0)
			{
				MATHEMATICS_ASSERTION_0(quantity < 2, "Unexpected condition\n");
				param[quantity++] = proj[i2];
			}
		}
	}

	// Sort.
	MATHEMATICS_ASSERTION_0(quantity == 1 || quantity == 2, "Unexpected condition\n");
	if (quantity == 2)
	{
		if (param[0] > param[1])
		{
			Real save = param[0];
			param[0] = param[1];
			param[1] = save;
		}
	}
	else
	{
		param[1] = param[0];
	}
}

template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::ContainsPoint (const Triangle3& triangle, const Plane3& plane,const Vector3D& point)
{
	// Generate a coordinate system for the plane.  The incoming triangle has
	// vertices <V0,V1,V2>.  The incoming plane has unit-length normal N.
	// The incoming point is P.  V0 is chosen as the origin for the plane. The
	// coordinate axis directions are two unit-length vectors, U0 and U1,
	// constructed so that {U0,U1,N} is an orthonormal set.  Any point Q
	// in the plane may be written as Q = V0 + x0*U0 + x1*U1.  The coordinates
	// are computed as x0 = Dot(U0,Q-V0) and x1 = Dot(U1,Q-V0).
	Vector3D U0, U1;
	auto vector3DOrthonormalBasis =	Vector3DTools::GenerateComplementBasis(plane.GetNormal());
	U0 = vector3DOrthonormalBasis.GetUVector();
	U1 = vector3DOrthonormalBasis.GetVVector();

	// Compute the planar coordinates for the points P, V1, and V2.  To
	// simplify matters, the origin is subtracted from the points, in which
	// case the planar coordinates are for P-V0, V1-V0, and V2-V0.
	auto PmV0 = point - triangle.GetVertex()[0];
	auto V1mV0 = triangle.GetVertex()[1] - triangle.GetVertex()[0];
	auto V2mV0 = triangle.GetVertex()[2] - triangle.GetVertex()[0];

	// The planar representation of P-V0.
	Vector2D<Real> ProjP{ Vector3DTools::DotProduct(U0,PmV0), Vector3DTools::DotProduct(U1,PmV0) };

	// The planar representation of the triangle <V0-V0,V1-V0,V2-V0>.
	std::vector<Vector2D<Real> > ProjV;

	ProjV.push_back(Vector2D<Real>::sm_Zero);
	ProjV.push_back(Vector2D<Real>(Vector3DTools::DotProduct(U0,V1mV0),Vector3DTools::DotProduct(U1,V1mV0)));
	ProjV.push_back(Vector2D<Real>(Vector3DTools::DotProduct(U0,V2mV0),Vector3DTools::DotProduct(U1,V2mV0)));


	// Test whether P-V0 is in the triangle <0,V1-V0,V2-V0>.
	if (Query2<Real>(ProjV).ToTriangle(ProjP,0,1,2) <= 0)
	{
		// Report the point of intersection to the caller.
		this->SetIntersectionType(IntersectionType::Point);
		mQuantity = 1;
		mPoint[0] = point;
		return true;
	}

	return false;
}

template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::IntersectsSegment (const Plane3& plane, const Triangle3& triangle,const Vector3D& end0, const Vector3D& end1)
{
	// Compute the 2D representations of the triangle vertices and the
	// segment endpoints relative to the plane of the triangle.  Then
	// compute the intersection in the 2D space.

	// Project the triangle and segment onto the coordinate plane most
	// aligned with the plane normal.
	auto maxNormal = 0;
	auto fmax = Math::FAbs(plane.GetNormal().GetXCoordinate());
	auto absMax = Math::FAbs(plane.GetNormal().GetYCoordinate());
	if (absMax > fmax)
	{
		maxNormal = 1;
		fmax = absMax;
	}
	absMax = Math::FAbs(plane.GetNormal().GetZCoordinate());
	if (absMax > fmax)
	{
		maxNormal = 2;
	}


	Vector2D<Real> projEnd0, projEnd1;
	int i;

	Vector2D<Real> projTriV[3];

	if (maxNormal == 0)
	{
		// Project onto yz-plane.
		for (i = 0; i < 3; ++i)
		{
			projTriV[i][0] = triangle.GetVertex()[i].GetYCoordinate();
			projTriV[i][1] = triangle.GetVertex()[i].GetZCoordinate();
			projEnd0.SetXCoordinate(end0.GetYCoordinate());
			projEnd0.SetYCoordinate(end0.GetZCoordinate());
			projEnd1.SetXCoordinate(end1.GetYCoordinate());
			projEnd1.SetYCoordinate(end1.GetZCoordinate());
		}
	}
	else if (maxNormal == 1)
	{
		// Project onto xz-plane.
		for (i = 0; i < 3; ++i)
		{
			projTriV[i][0]  = triangle.GetVertex()[i].GetXCoordinate();
			projTriV[i][1] = triangle.GetVertex()[i].GetZCoordinate();
			projEnd0.SetXCoordinate(end0.GetXCoordinate());
			projEnd0[1] = end0.GetZCoordinate();
			projEnd1.SetXCoordinate(end1.GetXCoordinate());
			projEnd1[1] = end1.GetZCoordinate();
		}
	}
	else
	{
		// Project onto xy-plane.
		for (i = 0; i < 3; ++i)
		{
			projTriV[i][0] = triangle.GetVertex()[i].GetXCoordinate();
			projTriV[i][1]= triangle.GetVertex()[i].GetYCoordinate();
			projEnd0.SetXCoordinate(end0.GetXCoordinate());
			projEnd0[1] = end0.GetYCoordinate();
			projEnd1.SetXCoordinate(end1.GetXCoordinate());
			projEnd1[1] = end1.GetYCoordinate();
		}
	}

	Triangle2<Real> projTri{ projTriV[0],projTriV[1],projTriV[2] };

	Segment2<Real> projSeg{ projEnd0, projEnd1 };
	StaticFindIntersectorSegment2Triangle2<Real> calc{ projSeg, projTri };
	if (!calc.IsIntersection())
	{
		return false;
	}

	Vector2D<Real> intr[2];
	if (calc.GetIntersectionType() == IntersectionType::Segment)
	{
		this->SetIntersectionType(IntersectionType::Segment);
		mQuantity = 2;
		intr[0] = calc.GetPoint(0);
		intr[1] = calc.GetPoint(1);
	}
	else
	{
		MATHEMATICS_ASSERTION_0(calc.GetIntersectionType() == IntersectionType::Point,"Intersection must be a point\n");
		this->SetIntersectionType(IntersectionType::Point);
		mQuantity = 1;
		intr[0] = calc.GetPoint(0);
	}

	// Unproject the segment of intersection.
	if (maxNormal == 0)
	{
		Real invNX = ((Real)1)/plane.GetNormal().GetXCoordinate();
		for (i = 0; i < mQuantity; ++i)
		{
			mPoint[i][1] = intr[i].GetXCoordinate();
			mPoint[i][2] = intr[i].GetYCoordinate();
			mPoint[i][0] = invNX*(plane.GetConstant() -	plane.GetNormal().GetYCoordinate()*mPoint[i].GetYCoordinate() -	plane.GetNormal().GetZCoordinate()*mPoint[i].GetZCoordinate());
		}
	}
	else if (maxNormal == 1)
	{
		Real invNY = ((Real)1)/plane.GetNormal().GetYCoordinate();
		for (i = 0; i < mQuantity; ++i)
		{
			mPoint[i][0] = intr[i].GetXCoordinate();
			mPoint[i][1] = intr[i].GetYCoordinate();
			mPoint[i][2] = invNY*(plane.GetConstant() -	plane.GetNormal().GetXCoordinate()*mPoint[i].GetXCoordinate() -	plane.GetNormal().GetZCoordinate()*mPoint[i].GetZCoordinate());
		}
	}
	else
	{
		Real invNZ = ((Real)1)/plane.GetNormal().GetZCoordinate();
		for (i = 0; i < mQuantity; ++i)
		{
			mPoint[i][0] = intr[i].GetXCoordinate();
			mPoint[i][1] = intr[i].GetYCoordinate();
			mPoint[i][2] = invNZ*(plane.GetConstant() -	plane.GetNormal().GetXCoordinate()*mPoint[i].GetXCoordinate() -	plane.GetNormal().GetYCoordinate()*mPoint[i].GetYCoordinate());
		}
	}

	return true;
}

template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::GetCoplanarIntersection (const Plane3& plane, const Triangle3& tri0,const Triangle3& tri1)
{
	// Project triangles onto coordinate plane most aligned with plane
	// normal.
	auto maxNormal = 0;
	auto fmax = Math::FAbs(plane.GetNormal().GetXCoordinate());
	auto absMax = Math::FAbs(plane.GetNormal().GetYCoordinate());
	if (absMax > fmax)
	{
		maxNormal = 1;
		fmax = absMax;
	}
	absMax = Math::FAbs(plane.GetNormal().GetZCoordinate());
	if (absMax > fmax)
	{
		maxNormal = 2;
	}


	int i;
	Vector2D<Real> projTri0V[3];
	Vector2D<Real> projTri1V[3];

	if (maxNormal == 0)
	{
		// Project onto yz-plane.
		for (i = 0; i < 3; ++i)
		{
			projTri0V[i][0] = tri0.GetVertex()[i].GetYCoordinate();
			projTri0V[i][1]  = tri0.GetVertex()[i].GetZCoordinate();
			projTri1V[i][0]  = tri1.GetVertex()[i].GetYCoordinate();
			projTri1V[i][1] = tri1.GetVertex()[i].GetZCoordinate();
		}
	}
	else if (maxNormal == 1)
	{
		// Project onto xz-plane.
		for (i = 0; i < 3; ++i)
		{
			projTri0V[i][0] = tri0.GetVertex()[i].GetXCoordinate();
			projTri0V[i][1] = tri0.GetVertex()[i].GetZCoordinate();
			projTri1V[i][0] = tri1.GetVertex()[i].GetXCoordinate();
			projTri1V[i][1] = tri1.GetVertex()[i].GetZCoordinate();
		}
	}
	else
	{
		// Project onto xy-plane.
		for (i = 0; i < 3; ++i)
		{
			projTri0V[i][0] = tri0.GetVertex()[i].GetXCoordinate();
			projTri0V[i][1] = tri0.GetVertex()[i].GetYCoordinate();
			projTri1V[i][0] = tri1.GetVertex()[i].GetXCoordinate();
			projTri1V[i][1] = tri1.GetVertex()[i].GetYCoordinate();
		}
	}

	Triangle2<Real> projTri0{ projTri0V[0],projTri0V[1],projTri0V[2] };
	Triangle2<Real> projTri1{ projTri1V[0],projTri1V[1],projTri1V[2] };

	// 2D triangle intersection routines require counterclockwise ordering.
	Vector2D<Real> save;
	auto edge0 = projTri0.GetVertex()[1] - projTri0.GetVertex()[0];
	auto edge1 = projTri0.GetVertex()[2] - projTri0.GetVertex()[0];
	if (Vector2DTools<Real>::DotPerp(edge0,edge1) < Real{})
	{
		// Triangle is clockwise, reorder it.
		projTri0 = Triangle2<Real>{ projTri0V[0],projTri0V[2],projTri0V[1] };
	}

	edge0 = projTri1.GetVertex()[1] - projTri1.GetVertex()[0];
	edge1 = projTri1.GetVertex()[2] - projTri1.GetVertex()[0];
	if (Vector2DTools<Real>::DotPerp(edge0,edge1) < Real{})
	{
		// Triangle is clockwise, reorder it.
		projTri1 = Triangle2<Real>{ projTri1V[0],projTri1V[2],projTri1V[1] };
	}

	StaticFindIntersectorTriangle2Triangle2<Real> intr(projTri0,projTri1);
	if (!intr.IsIntersection())
	{
		return false;
	}

	// Map 2D intersections back to the 3D triangle space.
	mQuantity = intr.GetQuantity();
	if (maxNormal == 0)
	{
		auto invNX = ((Real)1)/plane.GetNormal().GetXCoordinate();
		for (i = 0; i < mQuantity; i++)
		{
			mPoint[i][1] = intr.GetPoint(i).GetXCoordinate();
			mPoint[i][2] = intr.GetPoint(i).GetYCoordinate();
			mPoint[i][0] = invNX*(plane.GetConstant() -	plane.GetNormal().GetYCoordinate()*mPoint[i].GetYCoordinate() -	plane.GetNormal().GetZCoordinate()*mPoint[i].GetZCoordinate());
		}
	}
	else if (maxNormal == 1)
	{
		auto invNY = ((Real)1)/plane.GetNormal().GetYCoordinate();
		for (i = 0; i < mQuantity; i++)
		{
			mPoint[i][0] = intr.GetPoint(i).GetXCoordinate();
			mPoint[i][2] = intr.GetPoint(i).GetYCoordinate();
			mPoint[i][1] = invNY*(plane.GetConstant() -	plane.GetNormal().GetXCoordinate()*mPoint[i].GetXCoordinate() -	plane.GetNormal().GetZCoordinate()*mPoint[i].GetZCoordinate());
		}
	}
	else
	{
		auto invNZ = ((Real)1)/plane.GetNormal().GetZCoordinate();
		for (i = 0; i < mQuantity; i++)
		{
			mPoint[i][0] = intr.GetPoint(i).GetXCoordinate();
			mPoint[i][1] = intr.GetPoint(i).GetYCoordinate();
			mPoint[i][2] = invNZ * (plane.GetConstant() - plane.GetNormal().GetXCoordinate()*mPoint[i].GetXCoordinate() - plane.GetNormal().GetYCoordinate()*mPoint[i].GetYCoordinate());
		}
	}

	this->SetIntersectionType(IntersectionType::Plane);
	return true;
}

template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::TestOverlap (Real tmax, Real speed,Real umin, Real umax, Real vmin, Real vmax, Real& tfirst, Real& tlast)
{
	// Constant velocity separating axis test.

	Real t;

	if (vmax < umin) // V on left of U
	{
		if (speed <= Real{}) // V moving away from U
		{
			return false;
		}

		// Find first time of contact on this axis.
		t = (umin - vmax)/speed;
		if (t > tfirst)
		{
			tfirst = t;
		}

		// Quick out: intersection after desired time interval.
		if (tfirst > tmax)
		{
			return false;   
		}

		// Find last time of contact on this axis.
		t = (umax - vmin)/speed;
		if (t < tlast)
		{
			tlast = t;
		}

		// Quick out: intersection before desired time interval.
		if (tfirst > tlast)
		{
			return false; 
		}
	}
	else if (umax < vmin)   // V on right of U
	{
		if (speed >= Real{}) // V moving away from U
		{
			return false;
		}

		// Find first time of contact on this axis.
		t = (umax - vmin)/speed;
		if (t > tfirst)
		{
			tfirst = t;
		}

		// Quick out: intersection after desired time interval.
		if (tfirst > tmax)
		{
			return false;   
		}

		// Find last time of contact on this axis.
		t = (umin - vmax)/speed;
		if (t < tlast)
		{
			tlast = t;
		}

		// Quick out: intersection before desired time interval.
		if (tfirst > tlast)
		{
			return false; 
		}

	}
	else // V and U on overlapping interval
	{
		if (speed > Real{})
		{
			// Find last time of contact on this axis.
			t = (umax - vmin)/speed;
			if (t < tlast)
			{
				tlast = t;
			}

			// Quick out: intersection before desired interval.
			if (tfirst > tlast)
			{
				return false; 
			}
		}
		else if (speed < Real{})
		{
			// Find last time of contact on this axis.
			t = (umin - vmax)/speed;
			if (t < tlast)
			{
				tlast = t;
			}

			// Quick out: intersection before desired interval.
			if (tfirst > tlast)
			{
				return false;
			}
		}
	}
	return true;
}

template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::FindOverlap (Real tmax, Real speed,const Configuration& UC, const Configuration& VC, ContactSide& side,Configuration& TUC, Configuration& TVC, Real& tfirst, Real& tlast)
{
	// Constant velocity separating axis test.  UC and VC are the new
	// potential configurations, and TUC and TVC are the best known
	// configurations.

	Real t;

	if (VC.mMax < UC.mMin) // V on left of U
	{
		if (speed <= Real{}) // V moving away from U
		{
			return false;
		}

		// Find first time of contact on this axis.
		t = (UC.mMin - VC.mMax)/speed;

		// If this is the new maximum first time of contact, set side and
		// configuration.
		if (t > tfirst)
		{
			tfirst = t;
			side = CS_LEFT;
			TUC = UC;
			TVC = VC;
		}

		// Quick out: intersection after desired interval.
		if (tfirst > tmax)
		{
			return false;
		}

		// Find last time of contact on this axis.
		t = (UC.mMax - VC.mMin)/speed;
		if (t < tlast)
		{
			tlast = t;
		}

		// Quick out: intersection before desired interval.
		if (tfirst > tlast)
		{
			return false;
		}
	}
	else if (UC.mMax < VC.mMin)   // V on right of U
	{
		if (speed >= Real{}) // V moving away from U
		{
			return false;
		}

		// Find first time of contact on this axis.
		t = (UC.mMax - VC.mMin)/speed;

		// If this is the new maximum first time of contact, set side and
		// configuration.
		if (t > tfirst)
		{
			tfirst = t;
			side = CS_RIGHT;
			TUC = UC;
			TVC = VC;
		}

		// Quick out: intersection after desired interval.
		if (tfirst > tmax)
		{
			return false;   
		}

		// Find last time of contact on this axis.
		t = (UC.mMin - VC.mMax)/speed;
		if (t < tlast)
		{
			tlast = t;
		}

		// Quick out: intersection before desired interval.
		if (tfirst > tlast)
		{
			return false;
		}
	}
	else // V and U on overlapping interval
	{
		if (speed > Real{})
		{
			// Find last time of contact on this axis.
			t = (UC.mMax - VC.mMin)/speed;
			if (t < tlast)
			{
				tlast = t;
			}

			// Quick out: intersection before desired interval.
			if (tfirst > tlast)
			{
				return false;
			}
		}
		else if (speed < Real{})
		{
			// Find last time of contact on this axis.
			t = (UC.mMin - VC.mMax)/speed;
			if (t < tlast)
			{
				tlast = t;
			}

			// Quick out: intersection before desired interval.
			if (tfirst > tlast)
			{
				return false;
			}
		}
	}
	return true;
}

template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::TestOverlap (const Vector3D& axis,Real tmax, const Vector3D& velocity, Real& tfirst, Real& tlast)
{
	Real min0, max0, min1, max1;
	ProjectOntoAxis(m_LhsTriangle, axis, min0, max0);
	ProjectOntoAxis(m_RhsTriangle, axis, min1, max1);
	auto speed = Vector3DTools::DotProduct(velocity,axis);
	return TestOverlap(tmax, speed, min0, max0, min1, max1, tfirst, tlast);
}

template <typename Real>
bool Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::FindOverlap (const Vector3D& axis,Real tmax, const Vector3D& velocity, ContactSide& side,Configuration& tcfg0, Configuration& tcfg1, Real& tfirst,Real& tlast)
{
	Configuration cfg0, cfg1;
	ProjectOntoAxis(m_LhsTriangle, axis, cfg0);
	ProjectOntoAxis(m_RhsTriangle, axis, cfg1);
	auto speed = Vector3DTools::DotProduct(velocity,axis);
	return FindOverlap(tmax, speed, cfg0, cfg1, side, tcfg0, tcfg1,tfirst, tlast);
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::ProjectOntoAxis (const Triangle3& triangle, const Vector3D& axis,Configuration& cfg)
{
	// Find projections of vertices onto potential separating axis.
	auto d0 = Vector3DTools::DotProduct(axis,triangle.GetVertex()[0]);
	auto d1 = Vector3DTools::DotProduct(axis,triangle.GetVertex()[1]);
	auto d2 = Vector3DTools::DotProduct(axis,triangle.GetVertex()[2]);

	// Explicit sort of vertices to construct a Configuration object.
	if (d0 <= d1)
	{
		if (d1 <= d2) // D0 <= D1 <= D2
		{
			if (d0 != d1)
			{
				if (d1 != d2)
				{
					cfg.mMap = M111;
				}
				else
				{
					cfg.mMap = M12;
				}
			}
			else // ( D0 == D1 )
			{
				if (d1 != d2)
				{
					cfg.mMap = M21;
				}
				else
				{
					cfg.mMap = M3;
				}
			}
			cfg.mIndex[0] = 0;
			cfg.mIndex[1] = 1;
			cfg.mIndex[2] = 2;
			cfg.mMin = d0;
			cfg.mMax = d2;
		}
		else if (d0 <= d2) // D0 <= D2 < D1
		{
			if (d0 != d2)
			{
				cfg.mMap = M111;
				cfg.mIndex[0] = 0;
				cfg.mIndex[1] = 2;
				cfg.mIndex[2] = 1;
			}
			else
			{
				cfg.mMap = M21;
				cfg.mIndex[0] = 2;
				cfg.mIndex[1] = 0;
				cfg.mIndex[2] = 1;
			}
			cfg.mMin = d0;
			cfg.mMax = d1;
		}
		else // D2 < D0 <= D1
		{
			if (d0 != d1)
			{
				cfg.mMap = M111;
			}
			else
			{
				cfg.mMap = M12;
			}

			cfg.mIndex[0] = 2;
			cfg.mIndex[1] = 0;
			cfg.mIndex[2] = 1;
			cfg.mMin = d2;
			cfg.mMax = d1;
		}
	}
	else if (d2 <= d1) // D2 <= D1 < D0
	{
		if (d2 != d1)
		{
			cfg.mMap = M111;
			cfg.mIndex[0] = 2;
			cfg.mIndex[1] = 1;
			cfg.mIndex[2] = 0;
		}
		else
		{
			cfg.mMap = M21;
			cfg.mIndex[0] = 1;
			cfg.mIndex[1] = 2;
			cfg.mIndex[2] = 0;

		}
		cfg.mMin = d2;
		cfg.mMax = d0;
	}
	else if (d2 <= d0) // D1 < D2 <= D0
	{
		if (d2 != d0) 
		{
			cfg.mMap = M111;
		}
		else
		{
			cfg.mMap = M12;
		}

		cfg.mIndex[0] = 1;
		cfg.mIndex[1] = 2;
		cfg.mIndex[2] = 0;
		cfg.mMin = d1;
		cfg.mMax = d0;
	}
	else // D1 < D0 < D2
	{
		cfg.mMap = M111;
		cfg.mIndex[0] = 1;
		cfg.mIndex[1] = 0;
		cfg.mIndex[2] = 2;
		cfg.mMin = d1;
		cfg.mMax = d2;
	}
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::FindContactSet (const Triangle3& tri0, const Triangle3& tri1,ContactSide& side, Configuration& cfg0, Configuration& cfg1)
{
	if (side == CS_RIGHT) // tri1 to the right of tri0
	{
		if (cfg0.mMap == M21 || cfg0.mMap == M111)
		{
			// tri0 touching tri1 at a single point
			this->SetIntersectionType(IntersectionType::Point);
			mQuantity = 1;
			mPoint[0] = tri0.GetVertex()[cfg0.mIndex[2]];
		}
		else if (cfg1.mMap == M12 || cfg1.mMap == M111)
		{
			// tri1 touching tri0 at a single point
			this->SetIntersectionType(IntersectionType::Point);
			mQuantity = 1;
			mPoint[0] = tri1.GetVertex()[cfg1.mIndex[0]];
		}
		else if (cfg0.mMap == M12)
		{
			if (cfg1.mMap == M21)
			{
				// edge0-edge1 intersection
				GetEdgeEdgeIntersection(tri0.GetVertex()[cfg0.mIndex[1]], tri0.GetVertex()[cfg0.mIndex[2]],tri1.GetVertex()[cfg1.mIndex[0]], tri1.GetVertex()[cfg1.mIndex[1]]);
			}
			else // cfg1.mMap == m3
			{
				// uedge-vface intersection
				GetEdgeFaceIntersection(tri0.GetVertex()[cfg0.mIndex[1]], tri0.GetVertex()[cfg0.mIndex[2]],tri1);
			}
		}
		else // cfg0.mMap == M3
		{
			if (cfg1.mMap == M21)
			{
				// face0-edge1 intersection
				GetEdgeFaceIntersection(tri1.GetVertex()[cfg1.mIndex[0]], tri1.GetVertex()[cfg1.mIndex[1]],	tri0);
			} 
			else // cfg1.mMap == M3
			{
				// face0-face1 intersection
				Plane3 plane0{ tri0.GetVertex()[0], tri0.GetVertex()[1], tri0.GetVertex()[2] };
				GetCoplanarIntersection(plane0, tri0, tri1);
			}
		}
	}
	else if (side == CS_LEFT) // tri1 to the left of tri0
	{
		if (cfg1.mMap == M21 || cfg1.mMap == M111)
		{
			// tri1 touching tri0 at a single point
			this->SetIntersectionType(IntersectionType::Point);
			mQuantity = 1;
			mPoint[0] = tri1.GetVertex()[cfg1.mIndex[2]];
		}
		else if (cfg0.mMap == M12 || cfg0.mMap == M111)
		{
			// tri0 touching tri1 at a single point
			this->SetIntersectionType(IntersectionType::Point);
			mQuantity = 1;
			mPoint[0] = tri0.GetVertex()[cfg0.mIndex[0]];
		}
		else if (cfg1.mMap == M12)
		{
			if (cfg0.mMap == M21)
			{
				// edge0-edge1 intersection
				GetEdgeEdgeIntersection(tri0.GetVertex()[cfg0.mIndex[0]], tri0.GetVertex()[cfg0.mIndex[1]],	tri1.GetVertex()[cfg1.mIndex[1]], tri1.GetVertex()[cfg1.mIndex[2]]);
			}
			else // cfg0.mMap == M3
			{
				// edge1-face0 intersection
				GetEdgeFaceIntersection(tri1.GetVertex()[cfg1.mIndex[1]], tri1.GetVertex()[cfg1.mIndex[2]],tri0);
			}
		}
		else // cfg1.mMap == M3
		{
			if (cfg0.mMap == M21)
			{
				// edge0-face1 intersection
				GetEdgeFaceIntersection(tri0.GetVertex()[cfg0.mIndex[0]], tri0.GetVertex()[cfg0.mIndex[1]],tri1);
			} 
			else // cfg0.mMap == M
			{
				// face0-face1 intersection
				Plane3 plane0{ tri0.GetVertex()[0], tri0.GetVertex()[1], tri0.GetVertex()[2] };
				GetCoplanarIntersection(plane0, tri0, tri1);
			}
		}
	}
	else // side == CS_NONE
	{
		// Triangles are already intersecting tranversely.
		StaticFindIntersectorTriangle3Triangle3<Real> calc{ tri0, tri1 };
		auto result = calc.IsIntersection();
		MATHEMATICS_ASSERTION_0(result, "Intersection must exist\n");
		result;
		mQuantity = calc.GetQuantity();
		this->SetIntersectionType( calc.GetIntersectionType());
		for (auto i = 0; i < mQuantity; ++i)
		{
			mPoint[i] = calc.GetPoint(i);
		}
	}
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::GetEdgeEdgeIntersection (const Vector3D& U0, const Vector3D& U1,const Vector3D& V0, const Vector3D& V1)
{
	// Compute a normal to the plane of the two edges.
	auto edge0 = U1 - U0;
	auto edge1 = V1 - V0;
	auto normal = Vector3DTools::CrossProduct(edge0,edge1);

	// Solve U0 + s*(U1 - U0) = V0 + t*(V1 - V0).  We know the edges
	// intersect, so s in [0,1] and t in [0,1].  Thus, just solve for s.
	// Note that s*E0 = D + t*E1, where D = V0 - U0. So s*N = s*E0xE1 = DxE1
	// and s = N*DxE1/N*N.
	auto delta = V0 - U0;
	auto s = Vector3DTools::DotProduct(normal,(Vector3DTools::CrossProduct(delta,edge1)/Vector3DTools::VectorMagnitudeSquared( normal)));
	if (s < Real{})
	{
		MATHEMATICS_ASSERTION_0(s >= -Math::sm_ZeroTolerance,"Unexpected s value.\n");
		s = Real{};
	}
	else if (s > (Real)1)
	{
		MATHEMATICS_ASSERTION_0(s <= (Real)1 + Math::sm_ZeroTolerance,"Unexpected s value.\n");
		s = (Real)1;
	}

	this->SetIntersectionType(IntersectionType::Point);
	mQuantity = 1;
	mPoint[0] = U0 + s*edge0;

	// TODO:  What if the edges are parallel?
}

template <typename Real>
void Mathematics::StaticFindIntersectorTriangle3Triangle3<Real>
	::GetEdgeFaceIntersection (const Vector3D& U0, const Vector3D& U1,const Triangle3& tri)
{
	// Compute a plane of the triangle.
	auto point = tri.GetVertex()[0];
	auto edge0 = tri.GetVertex()[1] - point;
	auto edge1 = tri.GetVertex()[2] - point;
	auto normal =Vector3DTools::UnitCrossProduct(edge0,edge1);
	Vector3D dir0, dir1;
	auto vector3DOrthonormalBasis =	Vector3DTools::GenerateComplementBasis( normal);
	dir0 = vector3DOrthonormalBasis.GetUVector();
	dir1 = vector3DOrthonormalBasis.GetVVector();

	// Project the edge endpoints onto the plane.
	Vector2D<Real> projU0, projU1;
	Vector3D diff;
	diff = U0 - point;
	projU0[0] = Vector3DTools::DotProduct(dir0,diff);
	projU0[1]= Vector3DTools::DotProduct( dir1,diff);
	diff = U1 - point;
	projU1[0] = Vector3DTools::DotProduct(dir0,diff);
	projU1[1] = Vector3DTools::DotProduct(dir1,diff);
	Segment2<Real> projSeg{ projU0, projU1 };

	// Compute the plane coordinates of the triangle.
	Vector2D<Real> projTriV[3];
	projTriV[0] = Vector2D<Real>::sm_Zero;
	projTriV[1] = Vector2D<Real>(Vector2DTools<Real>::DotProduct(dir0,edge0), Vector2DTools<Real>::DotProduct(dir1,edge0));
	projTriV[2] = Vector2D<Real>(Vector2DTools<Real>::DotProduct(dir0,edge1), Vector2DTools<Real>::DotProduct(dir1,edge1));
	Triangle2<Real> projTri{ projTriV[0],projTriV[1],projTriV[2] };
	// Compute the intersection.
	StaticFindIntersectorSegment2Triangle2<Real> calc{ projSeg, projTri };
	if (calc.IsIntersection())
	{
		mQuantity = calc.GetQuantity();
		for (auto i = 0; i < mQuantity; ++i)
		{
			auto proj = calc.GetPoint(i);
			mPoint[i] = point + proj[0]*dir0 + proj[1]*dir1;
		}
	}
	else
	{
		// There must be an intersection.  Most likely numerical
		// round-off errors have led to a failure to find it.  Use a slower
		// 3D distance calculator for robustness.
		Segment3<Real> seg{ U0, U1 };
		DistSegment3Triangle3<Real> dcalc{ seg, tri };

		// We do not need the distance, but we do need the side effect
		// of locating the closest points.
		//Real distance = dcalc.Get();
		//WM5_UNUSED(distance);
		auto parameter = dcalc.GetSegmentParameter();
		mQuantity = 1;
		mPoint[0] = seg.GetCenterPoint() + parameter*seg.GetDirection();
	}

	this->SetIntersectionType ( (mQuantity == 2 ? IntersectionType::Segment : IntersectionType::Point));
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H
 
    