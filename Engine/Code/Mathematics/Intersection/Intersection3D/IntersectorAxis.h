// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 10:29)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_AXIS_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_AXIS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"  
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
	template <typename Real>
	class IntersectorConfiguration;

	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE IntersectorAxis
	{
	public:
		// Test-query for intersection of projected intervals.  The velocity
		// input is the difference objectVelocity1 - objectVelocity0.  The
		// first and last times of contact are computed.
		static bool Test (const Vector3D<Real>& axis,const Vector3D<Real> segment[2], const Triangle3<Real>& triangle,const Vector3D<Real>& velocity, Real tmax, Real& tfirst, Real& tlast);
		
		static bool Test (const Vector3D<Real>& axis,const Vector3D<Real> segment[2], const Box3<Real>& box,const Vector3D<Real>& velocity, Real tmax, Real& tfirst, Real& tlast);
		
		static bool Test (const Vector3D<Real>& axis,const Triangle3<Real>& triangle, const Box3<Real>& box,const Vector3D<Real>& velocity, Real tmax, Real& tfirst, Real& tlast);
		
		static bool Test (const Vector3D<Real>& axis,const Box3<Real>& box0, const Box3<Real>& box1,const Vector3D<Real>& velocity, Real tmax, Real& tfirst, Real& tlast);
		
		// Find-query for intersection of projected intervals.  The velocity
		// input is the difference objectVelocity1 - objectVelocity0.  The
		// first and last times of contact are computed, as is information about
		// the contact configuration and the ordering of the projections (the
		// contact side).
		static bool Find (const Vector3D<Real>& axis,const Vector3D<Real> segment[2], const Triangle3<Real>& triangle,const Vector3D<Real>& velocity, Real tmax, 
						  Real& tfirst, Real& tlast,int& side, IntersectorConfiguration<Real>& segCfgFinal,IntersectorConfiguration<Real>& triCfgFinal);
		
		static bool Find (const Vector3D<Real>& axis,const Vector3D<Real> segment[2], const Box3<Real>& box,const Vector3D<Real>& velocity, Real tmax, 
						  Real& tfirst, Real& tlast,int& side, IntersectorConfiguration<Real>& segCfgFinal,IntersectorConfiguration<Real>& boxCfgFinal);
		
		static bool Find (const Vector3D<Real>& axis,const Triangle3<Real>& triangle, const Box3<Real>& box,const Vector3D<Real>& velocity, Real tmax, 
						  Real& tfirst, Real& tlast,int& side, IntersectorConfiguration<Real>& triCfgFinal,IntersectorConfiguration<Real>& boxCfgFinal);
		
		static bool Find (const Vector3D<Real>& axis,const Box3<Real>& box0, const Box3<Real>& box1,const Vector3D<Real>& velocity, Real tmax,
						  Real& tfirst, Real& tlast,int& side, IntersectorConfiguration<Real>& box0CfgFinal,IntersectorConfiguration<Real>& box1CfgFinal);
		
		// Projections.
		static void GetProjection (const Vector3D<Real>& axis,const Vector3D<Real> segment[2], Real& imin, Real& imax);
		
		static void GetProjection (const Vector3D<Real>& axis,const Triangle3<Real>& triangle, Real& imin, Real& imax);
		
		static void GetProjection (const Vector3D<Real>& axis,const Box3<Real>& box, Real& imin, Real& imax);
		
		// Configurations.
		static void GetConfiguration (const Vector3D<Real>& axis, const Vector3D<Real> segment[2], IntersectorConfiguration<Real>& cfg);
    
		static void GetConfiguration (const Vector3D<Real>& axis, const Triangle3<Real>& triangle, IntersectorConfiguration<Real>& cfg);
		
		static void GetConfiguration (const Vector3D<Real>& axis, const Box3<Real>& box, IntersectorConfiguration<Real>& cfg);
		
		// Low-level test-query for projections.
		static bool Test (const Vector3D<Real>& axis,const Vector3D<Real>& velocity, Real min0, Real max0, Real min1,Real max1, Real tmax, Real& tfirst, Real& tlast);
		
		// Low-level find-query for projections.
		static bool Find (const Vector3D<Real>& axis,const Vector3D<Real>& velocity,const IntersectorConfiguration<Real>& cfg0Start,const IntersectorConfiguration<Real>& cfg1Start,
						  Real tmax, int& side,IntersectorConfiguration<Real>& cfg0Final,IntersectorConfiguration<Real>& cfg1Final, Real& tfirst, Real& tlast);
	};
}

#endif // MATHEMATICS_INTERSECTION_INTERSECTOR_AXIS_H
