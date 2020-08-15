// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 16:54)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_AXIS_DETAIL_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_AXIS_DETAIL_H

#include "IntersectorAxis.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_INTERSECTOR_AXIS_DETAIL) 
#include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26481)
    #include SYSTEM_WARNING_DISABLE(26485)
    #include SYSTEM_WARNING_DISABLE(26429)
    #include "IntersectorConfigurationDetail.h"
#include "Mathematics/Objects3D/Box3Detail.h"
#include "System/Helper/PragmaWarning.h" 

// IntrAxis<Real>

template <typename Real>
bool Mathematics::IntersectorAxis<Real>
	::Test(const Vector3D<Real>& axis, const Vector3D<Real> segment[2], const Triangle3<Real>& triangle, const Vector3D<Real>& velocity, Real tmax, Real& tfirst, Real& tlast)
{
	auto min0 = Math<Real>::sm_Zero;
	auto max0 = Math<Real>::sm_Zero;
	GetProjection(axis, segment, min0, max0);

	auto min1 = Math<Real>::sm_Zero;
	auto max1 = Math<Real>::sm_Zero;
	GetProjection(axis, triangle, min1, max1);

	return Test(axis, velocity, min0, max0, min1, max1, tmax, tfirst, tlast);
}

template <typename Real>
bool Mathematics::IntersectorAxis<Real>
	::Test(const Vector3D<Real>& axis, const Vector3D<Real> segment[2], const Box3<Real>& box,
		   const Vector3D<Real>& velocity, Real tmax, Real& tfirst, Real& tlast)
{
	auto min0 = Math<Real>::sm_Zero;
	auto max0 = Math<Real>::sm_Zero;
	GetProjection(axis, segment, min0, max0);

	auto min1 = Math<Real>::sm_Zero;
	auto max1 = Math<Real>::sm_Zero;
	GetProjection(axis, box, min1, max1);

	return Test(axis, velocity, min0, max0, min1, max1, tmax, tfirst, tlast);
}

template <typename Real>
bool Mathematics::IntersectorAxis<Real>
	::Test(const Vector3D<Real>& axis, const Triangle3<Real>& triangle, const Box3<Real>& box, const Vector3D<Real>& velocity, Real tmax, Real& tfirst, Real& tlast)
{
	auto min0 = Math<Real>::sm_Zero;
	auto max0 = Math<Real>::sm_Zero;
	GetProjection(axis, triangle, min0, max0);

	auto min1 = Math<Real>::sm_Zero;
	auto max1 = Math<Real>::sm_Zero;
	GetProjection(axis, box, min1, max1);

	return Test(axis, velocity, min0, max0, min1, max1, tmax, tfirst, tlast);
}

template <typename Real>
bool Mathematics::IntersectorAxis<Real>
	::Test(const Vector3D<Real>& axis, const Box3<Real>& box0, const Box3<Real>& box1, const Vector3D<Real>& velocity, Real tmax, Real& tfirst, Real& tlast)
{
	auto min0 = Math<Real>::sm_Zero;
	auto max0 = Math<Real>::sm_Zero;
	GetProjection(axis, box0, min0, max0);

	auto min1 = Math<Real>::sm_Zero;
	auto max1 = Math<Real>::sm_Zero;
	GetProjection(axis, box1, min1, max1);

	return Test(axis, velocity, min0, max0, min1, max1, tmax, tfirst, tlast);
}

template <typename Real>
bool Mathematics::IntersectorAxis<Real>
	::Find(const Vector3D<Real>& axis, const Vector3D<Real> segment[2], const Triangle3<Real>& triangle, const Vector3D<Real>& velocity, Real tmax,
		   Real& tfirst, Real& tlast, int& side, IntersectorConfiguration<Real>& segCfgFinal, IntersectorConfiguration<Real>& triCfgFinal)
{
	IntersectorConfiguration<Real> segCfgStart;
	GetConfiguration(axis, segment, segCfgStart);

	IntersectorConfiguration<Real> triCfgStart;
	GetConfiguration(axis, triangle, triCfgStart);

	return Find(axis, velocity, segCfgStart, triCfgStart, tmax, side, segCfgFinal, triCfgFinal, tfirst, tlast);
}

template <typename Real>
bool Mathematics::IntersectorAxis<Real>
	::Find(const Vector3D<Real>& axis, const Vector3D<Real> segment[2], const Box3<Real>& box, const Vector3D<Real>& velocity, Real tmax, Real& tfirst,
		   Real& tlast, int& side, IntersectorConfiguration<Real>& segCfgFinal, IntersectorConfiguration<Real>& boxCfgFinal)
{
	IntersectorConfiguration<Real> segCfgStart;
	GetConfiguration(axis, segment, segCfgStart);

	IntersectorConfiguration<Real> boxCfgStart;
	GetConfiguration(axis, box, boxCfgStart);

	return Find(axis, velocity, segCfgStart, boxCfgStart, tmax, side, segCfgFinal, boxCfgFinal, tfirst, tlast);
}

template <typename Real>
bool Mathematics::IntersectorAxis<Real>
	::Find(const Vector3D<Real>& axis, const Triangle3<Real>& triangle, const Box3<Real>& box, const Vector3D<Real>& velocity, Real tmax,
		   Real& tfirst, Real& tlast, int& side, IntersectorConfiguration<Real>& segCfgFinal, IntersectorConfiguration<Real>& boxCfgFinal)
{
	IntersectorConfiguration<Real> triCfgStart;
	GetConfiguration(axis, triangle, triCfgStart);

	IntersectorConfiguration<Real> boxCfgStart;
	GetConfiguration(axis, box, boxCfgStart);

	return Find(axis, velocity, triCfgStart, boxCfgStart, tmax, side, segCfgFinal, boxCfgFinal, tfirst, tlast);
}

template <typename Real>
bool Mathematics::IntersectorAxis<Real>
	::Find(const Vector3D<Real>& axis, const Box3<Real>& box0, const Box3<Real>& box1, const Vector3D<Real>& velocity, Real tmax,
		   Real& tfirst, Real& tlast, int& side, IntersectorConfiguration<Real>& box0CfgFinal, IntersectorConfiguration<Real>& box1CfgFinal)
{
	IntersectorConfiguration<Real> box0CfgStart;
	GetConfiguration(axis, box0, box0CfgStart);

	IntersectorConfiguration<Real> box1CfgStart;
	GetConfiguration(axis, box1, box1CfgStart);

	return Find(axis, velocity, box0CfgStart, box1CfgStart, tmax, side, box0CfgFinal, box1CfgFinal, tfirst, tlast);
}

template <typename Real>
void Mathematics::IntersectorAxis<Real>
	::GetProjection(const Vector3D<Real>& axis, const Vector3D<Real> segment[2], Real& imin, Real& imax)
{
	Real dot[2]{ Vector3DTools<Real>::DotProduct(axis,segment[0]),Vector3DTools<Real>::DotProduct(axis,segment[1]) };

	imin = dot[0];
	imax = imin;

	if (dot[1] < imin)
	{
		imin = dot[1];
	}
	else if (dot[1] > imax)
	{
		imax = dot[1];
	}
}

template <typename Real>
void Mathematics::IntersectorAxis<Real>
	::GetProjection(const Vector3D<Real>& axis, const Triangle3<Real>& triangle, Real& imin, Real& imax)
{
	Real dot[3]{ Vector3DTools<Real>::DotProduct(axis,triangle.GetVertex(0)),
				  Vector3DTools<Real>::DotProduct(axis,triangle.GetVertex(1)),
				  Vector3DTools<Real>::DotProduct(axis,triangle.GetVertex(2)) };

	imin = dot[0];
	imax = imin;

	if (dot[1] < imin)
	{
		imin = dot[1];
	}
	else if (dot[1] > imax)
	{
		imax = dot[1];
	}

	if (dot[2] < imin)
	{
		imin = dot[2];
	}
	else if (dot[2] > imax)
	{
		imax = dot[2];
	}
}

template <typename Real>
void Mathematics::IntersectorAxis<Real>
	::GetProjection(const Vector3D<Real>& axis, const Box3<Real>& box, Real& imin, Real& imax)
{
	auto origin = Vector3DTools<Real>::DotProduct(axis, box.GetCenter());
	auto maximumExtent = Math<Real>::FAbs(box.GetExtent(0)*Vector3DTools<Real>::DotProduct(axis, box.GetAxis(0))) +
						 Math<Real>::FAbs(box.GetExtent(1)*Vector3DTools<Real>::DotProduct(axis, box.GetAxis(1))) +
						 Math<Real>::FAbs(box.GetExtent(2)*Vector3DTools<Real>::DotProduct(axis, box.GetAxis(2)));

	imin = origin - maximumExtent;
	imax = origin + maximumExtent;
}

template <typename Real>
void Mathematics::IntersectorAxis<Real>
	::GetConfiguration(const Vector3D<Real>& axis, const Vector3D<Real> segment[2], IntersectorConfiguration<Real>& cfg)
{
	Real dot[2]{ Vector3DTools<Real>::DotProduct(axis,segment[0]),Vector3DTools<Real>::DotProduct(axis,segment[1]) };

	if (Math<Real>::FAbs(dot[1] - dot[0]) < Math<Real>::sm_ZeroTolerance)
	{
		cfg.mMap = IntersectorConfiguration<Real>::m2;
	}
	else
	{
		cfg.mMap = IntersectorConfiguration<Real>::m11;
	}

	if (dot[0] < dot[1])
	{
		cfg.mMin = dot[0];
		cfg.mMax = dot[1];
		cfg.mIndex[0] = 0;
		cfg.mIndex[1] = 1;
	}
	else
	{
		cfg.mMin = dot[1];
		cfg.mMax = dot[0];
		cfg.mIndex[0] = 1;
		cfg.mIndex[1] = 0;
	}
}

template <typename Real>
void Mathematics::IntersectorAxis<Real>
	::GetConfiguration(const Vector3D<Real>& axis, const Triangle3<Real>& triangle, IntersectorConfiguration<Real>& cfg)
{
	// Find projections of vertices onto potential separating axis.
	auto d0 = Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(0));
	auto d1 = Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(1));
	auto d2 = Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(2));

	// Explicit sort of vertices to construct a IntersectorConfiguration.
	if (d0 <= d1)
	{
		if (d1 <= d2) // D0 <= D1 <= D2
		{
			if (d0 != d1)
			{
				if (d1 != d2)
				{
					cfg.mMap = IntersectorConfiguration<Real>::m111;
				}
				else
				{
					cfg.mMap = IntersectorConfiguration<Real>::m12;
				}
			}
			else // ( D0 == D1 )
			{
				if (d1 != d2)
				{
					cfg.mMap = IntersectorConfiguration<Real>::m21;
				}
				else
				{
					cfg.mMap = IntersectorConfiguration<Real>::m3;
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
				cfg.mMap = IntersectorConfiguration<Real>::m111;
				cfg.mIndex[0] = 0;
				cfg.mIndex[1] = 2;
				cfg.mIndex[2] = 1;
			}
			else
			{
				cfg.mMap = IntersectorConfiguration<Real>::m21;
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
				cfg.mMap = IntersectorConfiguration<Real>::m111;
			}
			else
			{
				cfg.mMap = IntersectorConfiguration<Real>::m12;
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
			cfg.mMap = IntersectorConfiguration<Real>::m111;
			cfg.mIndex[0] = 2;
			cfg.mIndex[1] = 1;
			cfg.mIndex[2] = 0;
		}
		else
		{
			cfg.mMap = IntersectorConfiguration<Real>::m21;
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
			cfg.mMap = IntersectorConfiguration<Real>::m111;
		}
		else
		{
			cfg.mMap = IntersectorConfiguration<Real>::m12;
		}

		cfg.mIndex[0] = 1;
		cfg.mIndex[1] = 2;
		cfg.mIndex[2] = 0;
		cfg.mMin = d1;
		cfg.mMax = d0;
	}
	else // D1 < D0 < D2
	{
		cfg.mMap = IntersectorConfiguration<Real>::m111;
		cfg.mIndex[0] = 1;
		cfg.mIndex[1] = 0;
		cfg.mIndex[2] = 2;
		cfg.mMin = d1;
		cfg.mMax = d2;
	}
}

template <typename Real>
void Mathematics::IntersectorAxis<Real>
	::GetConfiguration(const Vector3D<Real>& axis, const Box3<Real>& box, IntersectorConfiguration<Real>& cfg)
{
	// Description of coordinate ordering scheme for IntersectorConfiguration.mIndex.
	//
	// Vertex number (up/down) vs. sign of extent (only matters in mapping
	// back)
	//   012
	// 0 ---
	// 1 +--
	// 2 -+-
	// 3 ++-
	// 4 --+
	// 5 +-+
	// 6 -++
	// 7 +++
	//
	// When it returns an ordering in the IntersectorConfiguration, it is also
	// guarenteed to be in-order (if 4 vertices, then they are guarenteed in
	// an order that will create a box, e.g. 0,1,3,2).

	Real axes[3]{ Vector3DTools<Real>::DotProduct(axis,box.GetAxis(0)),Vector3DTools<Real>::DotProduct(axis,box.GetAxis(1)),Vector3DTools<Real>::DotProduct(axis,box.GetAxis(2)) };

	Real absAxes[3]{ Math<Real>::FAbs(axes[0]),Math<Real>::FAbs(axes[1]),Math<Real>::FAbs(axes[2]) };

	Real maxProjectedExtent = Math<Real>::sm_Zero;

	if (absAxes[0] < Math<Real>::sm_ZeroTolerance)
	{
		if (absAxes[1] < Math<Real>::sm_ZeroTolerance)
		{
			// face-face
			cfg.mMap = IntersectorConfiguration<Real>::m44;

			maxProjectedExtent = absAxes[2] * box.GetExtent(2);

			// faces have normals along axis[2]
			if (axes[2] > Math<Real>::sm_Zero)
			{
				cfg.mIndex[0] = 0;
				cfg.mIndex[1] = 1;
				cfg.mIndex[2] = 3;
				cfg.mIndex[3] = 2;

				cfg.mIndex[4] = 6;
				cfg.mIndex[5] = 7;
				cfg.mIndex[6] = 5;
				cfg.mIndex[7] = 4;
			}
			else
			{
				cfg.mIndex[0] = 6;
				cfg.mIndex[1] = 7;
				cfg.mIndex[2] = 5;
				cfg.mIndex[3] = 4;

				cfg.mIndex[4] = 0;
				cfg.mIndex[5] = 1;
				cfg.mIndex[6] = 3;
				cfg.mIndex[7] = 2;
			}
		}
		else if (absAxes[2] < Math<Real>::sm_ZeroTolerance)
		{
			// face-face
			cfg.mMap = IntersectorConfiguration<Real>::m44;

			maxProjectedExtent = absAxes[1] * box.GetExtent(1);

			// faces have normals along axis[1]
			if (axes[1] > Math<Real>::sm_Zero)
			{
				cfg.mIndex[0] = 4;
				cfg.mIndex[1] = 5;
				cfg.mIndex[2] = 1;
				cfg.mIndex[3] = 0;

				cfg.mIndex[4] = 2;
				cfg.mIndex[5] = 3;
				cfg.mIndex[6] = 7;
				cfg.mIndex[7] = 6;
			}
			else
			{
				cfg.mIndex[0] = 2;
				cfg.mIndex[1] = 3;
				cfg.mIndex[2] = 7;
				cfg.mIndex[3] = 6;

				cfg.mIndex[4] = 4;
				cfg.mIndex[5] = 5;
				cfg.mIndex[6] = 1;
				cfg.mIndex[7] = 0;
			}
		}
		else // only axes[0] is equal to 0
		{
			// seg-seg
			cfg.mMap = IntersectorConfiguration<Real>::m2_2;

			maxProjectedExtent = absAxes[1] * box.GetExtent(1) + absAxes[2] * box.GetExtent(2);

			// axis 0 is perpendicular to axis
			if (axes[1] > Math<Real>::sm_Zero)
			{
				if (axes[2] > Math<Real>::sm_Zero)
				{
					cfg.mIndex[0] = 0;
					cfg.mIndex[1] = 1;

					cfg.mIndex[6] = 6;
					cfg.mIndex[7] = 7;
				}
				else
				{
					cfg.mIndex[0] = 4;
					cfg.mIndex[1] = 5;

					cfg.mIndex[6] = 2;
					cfg.mIndex[7] = 3;
				}
			}
			else // axes[1] < 0
			{
				if (axes[2] > Math<Real>::sm_Zero)
				{
					cfg.mIndex[0] = 2;
					cfg.mIndex[1] = 3;

					cfg.mIndex[6] = 4;
					cfg.mIndex[7] = 5;
				}
				else
				{
					cfg.mIndex[0] = 6;
					cfg.mIndex[1] = 7;

					cfg.mIndex[6] = 0;
					cfg.mIndex[7] = 1;
				}
			}
		}
	}
	else if (absAxes[1] < Math<Real>::sm_ZeroTolerance)
	{
		if (absAxes[2] < Math<Real>::sm_ZeroTolerance)
		{
			// face-face
			cfg.mMap = IntersectorConfiguration<Real>::m44;

			maxProjectedExtent = absAxes[0] * box.GetExtent(0);

			// faces have normals along axis[0]
			if (axes[0] > Math<Real>::sm_Zero)
			{
				cfg.mIndex[0] = 0;
				cfg.mIndex[1] = 2;
				cfg.mIndex[2] = 6;
				cfg.mIndex[3] = 4;

				cfg.mIndex[4] = 5;
				cfg.mIndex[5] = 7;
				cfg.mIndex[6] = 3;
				cfg.mIndex[7] = 1;
			}
			else
			{
				cfg.mIndex[4] = 0;
				cfg.mIndex[5] = 2;
				cfg.mIndex[6] = 6;
				cfg.mIndex[7] = 4;

				cfg.mIndex[0] = 5;
				cfg.mIndex[1] = 7;
				cfg.mIndex[2] = 3;
				cfg.mIndex[3] = 1;
			}

		}
		else // only axes[1] is equal to 0
		{
			// seg-seg
			cfg.mMap = IntersectorConfiguration<Real>::m2_2;

			maxProjectedExtent = absAxes[0] * box.GetExtent(0) + absAxes[2] * box.GetExtent(2);

			// axis 1 is perpendicular to axis
			if (axes[0] > Math<Real>::sm_Zero)
			{
				if (axes[2] > Math<Real>::sm_Zero)
				{
					cfg.mIndex[0] = 0;
					cfg.mIndex[1] = 2;

					cfg.mIndex[6] = 5;
					cfg.mIndex[7] = 7;
				}
				else
				{
					cfg.mIndex[0] = 4;
					cfg.mIndex[1] = 6;

					cfg.mIndex[6] = 1;
					cfg.mIndex[7] = 3;
				}
			}
			else // axes[0] < 0
			{
				if (axes[2] > Math<Real>::sm_Zero)
				{
					cfg.mIndex[0] = 1;
					cfg.mIndex[1] = 3;

					cfg.mIndex[6] = 4;
					cfg.mIndex[7] = 6;
				}
				else
				{
					cfg.mIndex[0] = 5;
					cfg.mIndex[1] = 7;

					cfg.mIndex[6] = 0;
					cfg.mIndex[7] = 2;
				}
			}
		}
	}

	else if (absAxes[2] < Math<Real>::sm_ZeroTolerance)
	{
		// only axis2 less than zero
		// seg-seg
		cfg.mMap = IntersectorConfiguration<Real>::m2_2;

		maxProjectedExtent = absAxes[0] * box.GetExtent(0) + absAxes[1] * box.GetExtent(1);

		// axis 2 is perpendicular to axis
		if (axes[0] > Math<Real>::sm_Zero)
		{
			if (axes[1] > Math<Real>::sm_Zero)
			{
				cfg.mIndex[0] = 0;
				cfg.mIndex[1] = 4;

				cfg.mIndex[6] = 3;
				cfg.mIndex[7] = 7;
			}
			else
			{
				cfg.mIndex[0] = 2;
				cfg.mIndex[1] = 6;

				cfg.mIndex[6] = 1;
				cfg.mIndex[7] = 5;
			}
		}
		else // axes[0] < 0
		{
			if (axes[1] > Math<Real>::sm_Zero)
			{
				cfg.mIndex[0] = 1;
				cfg.mIndex[1] = 5;

				cfg.mIndex[6] = 2;
				cfg.mIndex[7] = 6;
			}
			else
			{
				cfg.mIndex[0] = 3;
				cfg.mIndex[1] = 7;

				cfg.mIndex[6] = 0;
				cfg.mIndex[7] = 4;
			}
		}
	}

	else // no axis is equal to zero
	{
		// point-point (unique maximal and minimal vertex)
		cfg.mMap = IntersectorConfiguration<Real>::m1_1;

		maxProjectedExtent = absAxes[0] * box.GetExtent(0) + absAxes[1] * box.GetExtent(1) + absAxes[2] * box.GetExtent(2);

		// only these two vertices matter, the rest are irrelevant
		cfg.mIndex[0] = (axes[0] > Math<Real>::sm_Zero ? 0 : 1) + (axes[1] > Math<Real>::sm_Zero ? 0 : 2) + (axes[2] > Math<Real>::sm_Zero ? 0 : 4);
		// by ordering the vertices this way, opposite corners add up to 7
		cfg.mIndex[7] = 7 - cfg.mIndex[0];
	}

	// Find projections onto line
	auto origin = Vector3DTools<Real>::DotProduct(axis, box.GetCenter());
	cfg.mMin = origin - maxProjectedExtent;
	cfg.mMax = origin + maxProjectedExtent;
}

template <typename Real>
bool Mathematics::IntersectorAxis<Real>
	::Test(const Vector3D<Real>& axis, const Vector3D<Real>& velocity, Real min0, Real max0, Real min1, Real max1, Real tmax, Real& tfirst, Real& tlast)
{
	// Static separating axis test.  Returns false iff object0 and object1
	// do not intersect in the interval [0,TMax] on any separating axis
	// ( TFirst > TLast || TFirst > TMax ) during the time interval, that is,
	// a quick out.  Returns true otherwise.
	//
	// min0, max0, min1, and max1 are the minimal and maximal points of
	// whatever object object0 and object1 are projected onto the test axis.
	//
	// velocity is Velocity1 - Velocity0

	auto t = Math<Real>::sm_Zero;
	auto speed = Vector3DTools<Real>::DotProduct(axis, velocity);

	if (max1 < min0) // object1 on left of object0
	{
		if (speed <= Math<Real>::sm_Zero) // object1 moving away from object0
		{
			return false;
		}

		// find first time of contact on this axis
		t = (min0 - max1) / speed;
		if (t > tfirst)
		{
			tfirst = t;
		}

		// quick out: intersection after desired interval
		if (tfirst > tmax)
		{
			return false;
		}

		// find last time of contact on this axis
		t = (max0 - min1) / speed;
		if (t < tlast)
		{
			tlast = t;
		}

		// quick out: intersection before desired interval
		if (tfirst > tlast)
		{
			return false;
		}
	}
	else if (max0 < min1)   // object1 on right of object0
	{
		if (speed >= Math<Real>::sm_Zero) // object1 moving away from object0
		{
			return false;
		}

		// find first time of contact on this axis
		t = (max0 - min1) / speed;
		if (t > tfirst)
		{
			tfirst = t;
		}

		// quick out: intersection after desired interval
		if (tfirst > tmax)
		{
			return false;
		}

		// find last time of contact on this axis
		t = (min0 - max1) / speed;
		if (t < tlast)
		{
			tlast = t;
		}

		// quick out: intersection before desired interval
		if (tfirst > tlast)
		{
			return false;
		}

	}
	else // object1 and object0 on overlapping interval
	{
		if (speed > Math<Real>::sm_Zero)
		{
			// find last time of contact on this axis
			t = (max0 - min1) / speed;
			if (t < tlast)
			{
				tlast = t;
			}

			// quick out: intersection before desired interval
			if (tfirst > tlast)
			{
				return false;
			}
		}
		else if (speed < Math<Real>::sm_Zero)
		{
			// find last time of contact on this axis
			t = (min0 - max1) / speed;
			if (t < tlast)
			{
				tlast = t;
			}

			// quick out: intersection before desired interval
			if (tfirst > tlast)
			{
				return false;
			}
		}
	}
	return true;
}

template <typename Real>
bool Mathematics::IntersectorAxis<Real>
	::Find(const Vector3D<Real>& axis, const Vector3D<Real>& velocity, const IntersectorConfiguration<Real>& cfg0Start, const IntersectorConfiguration<Real>& cfg1Start, Real tmax,
		   int& side, IntersectorConfiguration<Real>& cfg0Final, IntersectorConfiguration<Real>& cfg1Final, Real& tfirst, Real& tlast)
{
	// Constant velocity separating axis test.  The configurations cfg0Start
	// and cfg1Start are the current potential configurations for contact,
	// and cfg0Final and cfg1Final are improved configurations.

	auto t = Math<Real>::sm_Zero;
	auto speed = Vector3DTools<Real>::DotProduct(axis, velocity);

	if (cfg1Start.mMax < cfg0Start.mMin) // object1 left of object0
	{
		if (speed <= Math<Real>::sm_Zero) // object1 moving away from object0
		{
			return false;
		}

		// find first time of contact on this axis
		t = (cfg0Start.mMin - cfg1Start.mMax) / speed;

		// If this is the new maximum first time of contact, set side and
		// configuration.
		if (t > tfirst)
		{
			tfirst = t;
			side = IntersectorConfiguration<Real>::LEFT;
			cfg0Final = cfg0Start;
			cfg1Final = cfg1Start;
		}

		// quick out: intersection after desired interval
		if (tfirst > tmax)
		{
			return false;
		}

		// find last time of contact on this axis
		t = (cfg0Start.mMax - cfg1Start.mMin) / speed;
		if (t < tlast)
		{
			tlast = t;
		}

		// quick out: intersection before desired interval
		if (tfirst > tlast)
		{
			return false;
		}
	}
	else if (cfg0Start.mMax < cfg1Start.mMin)  // obj1 right of obj0
	{
		if (speed >= Math<Real>::sm_Zero) // object1 moving away from object0
		{
			return false;
		}

		// find first time of contact on this axis
		t = (cfg0Start.mMax - cfg1Start.mMin) / speed;

		// If this is the new maximum first time of contact,  set side and
		// configuration.
		if (t > tfirst)
		{
			tfirst = t;
			side = IntersectorConfiguration<Real>::RIGHT;
			cfg0Final = cfg0Start;
			cfg1Final = cfg1Start;
		}

		// quick out: intersection after desired interval
		if (tfirst > tmax)
		{
			return false;
		}

		// find last time of contact on this axis
		t = (cfg0Start.mMin - cfg1Start.mMax) / speed;
		if (t < tlast)
		{
			tlast = t;
		}

		// quick out: intersection before desired interval
		if (tfirst > tlast)
		{
			return false;
		}
	}
	else // object1 and object0 on overlapping interval
	{
		if (speed > Math<Real>::sm_Zero)
		{
			// find last time of contact on this axis
			t = (cfg0Start.mMax - cfg1Start.mMin) / speed;
			if (t < tlast)
			{
				tlast = t;
			}

			// quick out: intersection before desired interval
			if (tfirst > tlast)
			{
				return false;
			}
		}
		else if (speed < Math<Real>::sm_Zero)
		{
			// find last time of contact on this axis
			t = (cfg0Start.mMin - cfg1Start.mMax) / speed;
			if (t < tlast)
			{
				tlast = t;
			}

			// quick out: intersection before desired interval
			if (tfirst > tlast)
			{
				return false;
			}
		}
	}
	return true;
}
#include STSTEM_WARNING_POP
#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_INTERSECTOR_AXIS_DETAIL)

#endif // MATHEMATICS_INTERSECTION_INTERSECTOR_AXIS_DETAIL_H
