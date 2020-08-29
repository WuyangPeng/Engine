// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:49)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H

#include "DynamicTestIntersectorTriangle3Triangle3.h"

template <typename Real>
Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::DynamicTestIntersectorTriangle3Triangle3(const Triangle3& triangle0, const Triangle3& triangle1, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
	:ParentType{ tmax,lhsVelocity,rhsVelocity,epsilon }, mTriangle0{ triangle0 }, mTriangle1{ triangle1 }
{
	mReportCoplanarIntersections = true;
	Test();
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::GetTriangle0() const
{
	return mTriangle0;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::GetTriangle1() const
{
	return mTriangle1;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::Test()
{
	auto tfirst = Math::GetValue(0);
	auto tlast = Math::sm_MaxReal;
	auto tmax = this->GetTMax();
	auto velocity0 = this->GetLhsVelocity();
	auto velocity1 = this->GetRhsVelocity();

	// Velocity relative to triangle0.
	auto relVelocity = velocity1 - velocity0;

	// Compute edge and normal directions for triangle0.
	Vector3D E[3]{ mTriangle0.GetVertex()[1] - mTriangle0.GetVertex()[0],
				   mTriangle0.GetVertex()[2] - mTriangle0.GetVertex()[1],
				   mTriangle0.GetVertex()[0] - mTriangle0.GetVertex()[2] };

	auto N = Vector3DTools::UnitCrossProduct(E[0], E[1]);
	if (!TestOverlap(N, tmax, relVelocity, tfirst, tlast))
	{
		this->SetIntersectionType(IntersectionType::Empty);
		return;
	}

	// Compute edge and normal directions for triangle1.
	Vector3D F[3]{ mTriangle1.GetVertex()[1] - mTriangle1.GetVertex()[0],
				   mTriangle1.GetVertex()[2] - mTriangle1.GetVertex()[1],
				   mTriangle1.GetVertex()[0] - mTriangle1.GetVertex()[2] };
	auto M = Vector3DTools::UnitCrossProduct(F[0], F[1]);

	Vector3D dir;
	auto i0 = 0;
	auto i1 = 0;

	if (Math::FAbs(Vector3DTools::DotProduct(N, M)) < static_cast<Real>(1) - Math::GetZeroTolerance())
	{
		// Triangles are not parallel.

		// Direction M.
		if (!TestOverlap(M, tmax, relVelocity, tfirst, tlast))
		{
			this->SetIntersectionType(IntersectionType::Empty);
			return;
		}

		// Directions E[i0]xF[i1].
		for (i1 = 0; i1 < 3; ++i1)
		{
			for (i0 = 0; i0 < 3; ++i0)
			{
				dir = Vector3DTools::UnitCrossProduct(E[i0], F[i1]);
				if (!TestOverlap(dir, tmax, relVelocity, tfirst, tlast))
				{
					this->SetIntersectionType(IntersectionType::Empty);
					return;
				}
			}
		}
		this->SetIntersectionType(IntersectionType::Other);
	}
	else  // Triangles are parallel (and, in fact, coplanar).
	{
		// Directions NxE[i0].
		for (i0 = 0; i0 < 3; ++i0)
		{
			dir = Vector3DTools::UnitCrossProduct(N, E[i0]);
			if (!TestOverlap(dir, tmax, relVelocity, tfirst, tlast))
			{
				this->SetIntersectionType(IntersectionType::Empty);
				return;
			}
		}

		// directions NxF[i1]
		for (i1 = 0; i1 < 3; ++i1)
		{
			dir = Vector3DTools::UnitCrossProduct(M, F[i1]);
			if (!TestOverlap(dir, tmax, relVelocity, tfirst, tlast))
			{
				this->SetIntersectionType(IntersectionType::Empty);
				return;
			}
		}
		this->SetIntersectionType(IntersectionType::Plane);
	}

	SetContactTime(tfirst);
	return;
} 

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::ProjectOntoAxis(const Triangle3& triangle, const Vector3D& axis, Real& fmin, Real& fmax)
{
	auto dot0 = Vector3DTools::DotProduct(axis, triangle.GetVertex()[0]);
	auto dot1 = Vector3DTools::DotProduct(axis, triangle.GetVertex()[1]);
	auto dot2 = Vector3DTools::DotProduct(axis, triangle.GetVertex()[2]);

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
void Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::TrianglePlaneRelations(const Triangle3& triangle, const Plane3& plane, Real distance[3], int sign[3], int& positive, int& negative, int& zero)
{
	// Compute the signed distances of triangle vertices to the plane.  Use
	// an epsilon-thick plane test.
	positive = 0;
	negative = 0;
	zero = 0;
	for (auto i = 0; i < 3; ++i)
	{
		distance[i] = plane.DistanceTo(triangle.GetVertex()[i]);
		if (distance[i] > Math::GetZeroTolerance())
		{
			sign[i] = 1;
			positive++;
		}
		else if (distance[i] < -Math::GetZeroTolerance())
		{
			sign[i] = -1;
			negative++;
		}
		else
		{
			distance[i] = Math::GetValue(0);
			sign[i] = 0;
			zero++;
		}
	}
}

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::GetInterval(const Triangle3& triangle, const Line3& line, const Real distance[3], const int sign[3], Real param[2])
{
	// Project triangle onto line.
	Real proj[3]{};
	auto i = 0;
	for (i = 0; i < 3; i++)
	{
		auto diff = triangle.GetVertex()[i] - line.GetOrigin();
		proj[i] = Vector3DTools::DotProduct(line.GetDirection(), diff);
	}

	// Compute transverse intersections of triangle edges with line.
	auto numer = Math::GetValue(0);
	auto denom = Math::GetValue(0);
	auto i0 = 0;
	auto i1 = 0;
	auto i2 = 0;
	auto quantity = 0;
	for (i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
	{
		if (sign[i0] * sign[i1] < 0)
		{
			MATHEMATICS_ASSERTION_0(quantity < 2, "Unexpected condition\n");
			numer = distance[i0] * proj[i1] - distance[i1] * proj[i0];
			denom = distance[i0] - distance[i1];
			param[quantity++] = numer / denom;
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
			auto save = param[0];
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
bool Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::ContainsPoint(const Triangle3& triangle, const Plane3& plane, const Vector3D& point)
{
	// Generate a coordinate system for the plane.  The incoming triangle has
	// vertices <V0,V1,V2>.  The incoming plane has unit-length normal N.
	// The incoming point is P.  V0 is chosen as the origin for the plane. The
	// coordinate axis directions are two unit-length vectors, U0 and U1,
	// constructed so that {U0,U1,N} is an orthonormal set.  Any point Q
	// in the plane may be written as Q = V0 + x0*U0 + x1*U1.  The coordinates
	// are computed as x0 = Dot(U0,Q-V0) and x1 = Dot(U1,Q-V0).
	Vector3D U0;
	Vector3D U1;
	auto vector3DOrthonormalBasis = Vector3DTools::GenerateComplementBasis(plane.GetNormal());
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
	ProjV.push_back(Vector2D<Real>(Vector3DTools::DotProduct(U0, V1mV0), Vector3DTools::DotProduct(U1, V1mV0)));
	ProjV.push_back(Vector2D<Real>(Vector3DTools::DotProduct(U0, V2mV0), Vector3DTools::DotProduct(U1, V2mV0))); 

	// Test whether P-V0 is in the triangle <0,V1-V0,V2-V0>.
	if (Query2<Real>(ProjV).ToTriangle(ProjP, 0, 1, 2) <= 0)
	{
		// Report the point of intersection to the caller.
		this->SetIntersectionType(IntersectionType::Point);
		return true;
	}

	return false;
}

template <typename Real>
bool Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::GetCoplanarIntersection(const Plane3& plane, const Triangle3& tri0, const Triangle3& tri1)
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

	auto i = 0;
	Vector2D<Real> projTri0V[3];
	Vector2D<Real> projTri1V[3];

	if (maxNormal == 0)
	{
		// Project onto yz-plane.
		for (i = 0; i < 3; ++i)
		{
			projTri0V[i][0] = tri0.GetVertex()[i].GetYCoordinate();
			projTri0V[i][1] = tri0.GetVertex()[i].GetZCoordinate();
			projTri1V[i][0] = tri1.GetVertex()[i].GetYCoordinate();
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
	if (Vector2DTools<Real>::DotPerp(edge0, edge1) < Math::GetValue(0))
	{
		// Triangle is clockwise, reorder it.
		projTri0 = Triangle2<Real>(projTri0V[0], projTri0V[2], projTri0V[1]);
	}

	edge0 = projTri1.GetVertex()[1] - projTri1.GetVertex()[0];
	edge1 = projTri1.GetVertex()[2] - projTri1.GetVertex()[0];
	if (Vector2DTools<Real>::DotPerp(edge0, edge1) < Math::GetValue(0))
	{
		// Triangle is clockwise, reorder it.
		projTri1 = Triangle2<Real>(projTri1V[0], projTri1V[2], projTri1V[1]);
	}

	StaticFindIntersectorTriangle2Triangle2<Real> intr(projTri0, projTri1);
	if (!intr.IsIntersection())
	{
		return false;
	} 

	this->SetIntersectionType(IntersectionType::Plane);
	return true;
}

template <typename Real>
bool Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::TestOverlap(Real tmax, Real speed, Real umin, Real umax, Real vmin, Real vmax, Real& tfirst, Real& tlast)
{
	// Constant velocity separating axis test.

	auto t = Math::GetValue(0);

	if (vmax < umin) // V on left of U
	{
		if (speed <= Math::GetValue(0)) // V moving away from U
		{
			return false;
		}

		// Find first time of contact on this axis.
		t = (umin - vmax) / speed;
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
		t = (umax - vmin) / speed;
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
		if (speed >= Math::GetValue(0)) // V moving away from U
		{
			return false;
		}

		// Find first time of contact on this axis.
		t = (umax - vmin) / speed;
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
		t = (umin - vmax) / speed;
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
		if (speed > Math::GetValue(0))
		{
			// Find last time of contact on this axis.
			t = (umax - vmin) / speed;
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
		else if (speed < Math::GetValue(0))
		{
			// Find last time of contact on this axis.
			t = (umin - vmax) / speed;
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
bool Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::FindOverlap(Real tmax, Real speed, const Configuration& UC, const Configuration& VC, ContactSide& side, Configuration& TUC, Configuration& TVC, Real& tfirst, Real& tlast)
{
	// Constant velocity separating axis test.  UC and VC are the new
	// potential configurations, and TUC and TVC are the best known
	// configurations.

	auto t = Math::GetValue(0);

	if (VC.mMax < UC.mMin) // V on left of U
	{
		if (speed <= Math::GetValue(0)) // V moving away from U
		{
			return false;
		}

		// Find first time of contact on this axis.
		t = (UC.mMin - VC.mMax) / speed;

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
		t = (UC.mMax - VC.mMin) / speed;
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
		if (speed >= Math::GetValue(0)) // V moving away from U
		{
			return false;
		}

		// Find first time of contact on this axis.
		t = (UC.mMax - VC.mMin) / speed;

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
		t = (UC.mMin - VC.mMax) / speed;
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
		if (speed > Math::GetValue(0))
		{
			// Find last time of contact on this axis.
			t = (UC.mMax - VC.mMin) / speed;
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
		else if (speed < Math::GetValue(0))
		{
			// Find last time of contact on this axis.
			t = (UC.mMin - VC.mMax) / speed;
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
bool Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::TestOverlap(const Vector3D& axis, Real tmax, const Vector3D& velocity, Real& tfirst, Real& tlast)
{
	auto min0 = Math::GetValue(0);
	auto max0 = Math::GetValue(0);
	auto min1 = Math::GetValue(0); 
	auto max1 = Math::GetValue(0);
	ProjectOntoAxis(mTriangle0, axis, min0, max0);
	ProjectOntoAxis(mTriangle1, axis, min1, max1);
	auto speed = Vector3DTools::DotProduct(velocity, axis);
	return TestOverlap(tmax, speed, min0, max0, min1, max1, tfirst, tlast);
}

template <typename Real>
bool Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::FindOverlap(const Vector3D& axis, Real tmax, const Vector3D& velocity, ContactSide& side, Configuration& tcfg0, Configuration& tcfg1, Real& tfirst, Real& tlast)
{
	Configuration cfg0;
	Configuration cfg1;
	ProjectOntoAxis(mTriangle0, axis, cfg0);
	ProjectOntoAxis(mTriangle1, axis, cfg1);
	auto speed = Vector3DTools::DotProduct(velocity, axis);
	return FindOverlap(tmax, speed, cfg0, cfg1, side, tcfg0, tcfg1, tfirst, tlast);
}

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::ProjectOntoAxis(const Triangle3& triangle, const Vector3D& axis, Configuration& cfg)
{
	// Find projections of vertices onto potential separating axis.
	auto d0 = Vector3DTools::DotProduct(axis, triangle.GetVertex()[0]);
	auto d1 = Vector3DTools::DotProduct(axis, triangle.GetVertex()[1]);
	auto d2 = Vector3DTools::DotProduct(axis, triangle.GetVertex()[2]);

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
void Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::FindContactSet(const Triangle3& tri0, const Triangle3& tri1, ContactSide& side, Configuration& cfg0, Configuration& cfg1)
{
	if (side == CS_RIGHT) // tri1 to the right of tri0
	{
		if (cfg0.mMap == M21 || cfg0.mMap == M111)
		{
			// tri0 touching tri1 at a single point
			this->SetIntersectionType(IntersectionType::Point);

		}
		else if (cfg1.mMap == M12 || cfg1.mMap == M111)
		{
			// tri1 touching tri0 at a single point
			this->SetIntersectionType(IntersectionType::Point);

		}
		else if (cfg0.mMap == M12)
		{
			if (cfg1.mMap == M21)
			{
				// edge0-edge1 intersection
				GetEdgeEdgeIntersection(tri0.GetVertex()[cfg0.mIndex[1]], tri0.GetVertex()[cfg0.mIndex[2]], tri1.GetVertex()[cfg1.mIndex[0]], tri1.GetVertex()[cfg1.mIndex[1]]);
			}
			else // cfg1.mMap == m3
			{
				// uedge-vface intersection
				GetEdgeFaceIntersection(tri0.GetVertex()[cfg0.mIndex[1]], tri0.GetVertex()[cfg0.mIndex[2]], tri1);
			}
		}
		else // cfg0.mMap == M3
		{
			if (cfg1.mMap == M21)
			{
				// face0-edge1 intersection
				GetEdgeFaceIntersection(tri1.GetVertex()[cfg1.mIndex[0]], tri1.GetVertex()[cfg1.mIndex[1]], tri0);
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

		}
		else if (cfg0.mMap == M12 || cfg0.mMap == M111)
		{
			// tri0 touching tri1 at a single point
			this->SetIntersectionType(IntersectionType::Point);

		}
		else if (cfg1.mMap == M12)
		{
			if (cfg0.mMap == M21)
			{
				// edge0-edge1 intersection
				GetEdgeEdgeIntersection(tri0.GetVertex()[cfg0.mIndex[0]], tri0.GetVertex()[cfg0.mIndex[1]],
										tri1.GetVertex()[cfg1.mIndex[1]], tri1.GetVertex()[cfg1.mIndex[2]]);
			}
			else // cfg0.mMap == M3
			{
				// edge1-face0 intersection
				GetEdgeFaceIntersection(tri1.GetVertex()[cfg1.mIndex[1]], tri1.GetVertex()[cfg1.mIndex[2]], tri0);
			}
		}
		else // cfg1.mMap == M3
		{
			if (cfg0.mMap == M21)
			{
				// edge0-face1 intersection
				GetEdgeFaceIntersection(tri0.GetVertex()[cfg0.mIndex[0]], tri0.GetVertex()[cfg0.mIndex[1]], tri1);
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

		this->SetIntersectionType(calc.GetIntersectionType());
	}
}

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::GetEdgeEdgeIntersection(const Vector3D& U0, const Vector3D& U1, const Vector3D& V0, const Vector3D& V1)
{
	// Compute a normal to the plane of the two edges.
	auto edge0 = U1 - U0;
	auto edge1 = V1 - V0;
	auto normal = Vector3DTools::CrossProduct(edge0, edge1);

	// Solve U0 + s*(U1 - U0) = V0 + t*(V1 - V0).  We know the edges
	// intersect, so s in [0,1] and t in [0,1].  Thus, just solve for s.
	// Note that s*E0 = D + t*E1, where D = V0 - U0. So s*N = s*E0xE1 = DxE1
	// and s = N*DxE1/N*N.
	auto delta = V0 - U0;
	auto s = Vector3DTools::DotProduct(normal, (Vector3DTools::CrossProduct(delta, edge1) / Vector3DTools::VectorMagnitudeSquared(normal)));
	if (s < Math::GetValue(0))
	{
		MATHEMATICS_ASSERTION_0(s >= -Math::GetZeroTolerance(), "Unexpected s value.\n");
		s = Math::GetValue(0);
	}
	else if (s > static_cast<Real>(1))
	{
		MATHEMATICS_ASSERTION_0(s <= static_cast<Real>(1) + Math::GetZeroTolerance(), "Unexpected s value.\n");
		s = static_cast<Real>(1);
	}

	this->SetIntersectionType(IntersectionType::Point);


	// TODO:  What if the edges are parallel?
}

template <typename Real>
void Mathematics::DynamicTestIntersectorTriangle3Triangle3<Real>
	::GetEdgeFaceIntersection(const Vector3D& U0, const Vector3D& U1, const Triangle3& tri)
{
	// Compute a plane of the triangle.
	auto point = tri.GetVertex()[0];
	auto edge0 = tri.GetVertex()[1] - point;
	auto edge1 = tri.GetVertex()[2] - point;
	auto normal = Vector3DTools::UnitCrossProduct(edge0, edge1);
	Vector3D dir0;
	Vector3D dir1;
	auto vector3DOrthonormalBasis = Vector3DTools::GenerateComplementBasis(normal);
	dir0 = vector3DOrthonormalBasis.GetUVector();
	dir1 = vector3DOrthonormalBasis.GetVVector();

	// Project the edge endpoints onto the plane.
	Vector2D<Real> projU0;
	Vector2D<Real> projU1;
	Vector3D diff;
	diff = U0 - point;
	projU0[0] = Vector3DTools::DotProduct(dir0, diff);
	projU0[1] = Vector3DTools::DotProduct(dir1, diff);
	diff = U1 - point;
	projU1[0] = Vector3DTools::DotProduct(dir0, diff);
	projU1[1] = Vector3DTools::DotProduct(dir1, diff);
	Segment2<Real> projSeg{ projU0, projU1 };

	// Compute the plane coordinates of the triangle.
	Vector2D<Real> projTriV[3];
	projTriV[0] = Vector2D<Real>::sm_Zero;
	projTriV[1] = Vector2D<Real>(Vector2DTools<Real>::DotProduct(dir0, edge0), Vector2DTools<Real>::DotProduct(dir1, edge0));
	projTriV[2] = Vector2D<Real>(Vector2DTools<Real>::DotProduct(dir0, edge1), Vector2DTools<Real>::DotProduct(dir1, edge1));
	Triangle2<Real> projTri{ projTriV[0],projTriV[1],projTriV[2] };
	// Compute the intersection.
	auto mQuantity = 0;
	StaticFindIntersectorSegment2Triangle2<Real> calc{ projSeg, projTri };
	if (calc.IsIntersection())
	{
		mQuantity = calc.GetQuantity();

	}
	else
	{
		mQuantity = 1;
	}

	this->SetIntersectionType((mQuantity == 2 ? IntersectionType::Segment : IntersectionType::Point));
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H