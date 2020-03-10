// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:27)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SPHERE3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_SPHERE3_DETAIL_H

#include "ContSphere3.h"

template <typename Real>
Mathematics::Sphere3<Real> Mathematics
	::ContSphereOfAABB(const std::vector<Vector3D<Real> >& points)
{    
	auto aabb = Vector3DTools<Real>::ComputeExtremes(points);
	auto minExtreme = aabb.GetMinPoint();
	auto maxExtreme = aabb.GetMaxPoint();

	auto halfDiagonal = (Real{0.5})*(maxExtreme - minExtreme);
	Sphere3<Real> sphere{ (Real{0.5})*(maxExtreme + minExtreme), Vector3DTools<Real>::VectorMagnitude(halfDiagonal) };
    
    return sphere;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics
	::ContSphereAverage(int numPoints, const Vector3D<Real>* points)
{
	auto center = points[0];
    int i;
    for (i = 1; i < numPoints; ++i)
    {
		center += points[i];
    }
	center /= (Real)numPoints;

	Real radius { };
    for (i = 0; i < numPoints; ++i)
    {
		auto diff = points[i] - center;
		auto radiusSqr = Vector3DTools<Real>::VectorMagnitudeSquared(diff);
		if (radiusSqr > radius)
        {
			radius = radiusSqr;
        }
    }
	radius = Math<Real>::Sqrt(radius);
	Sphere3<Real> sphere{ center, radius };
	
    return sphere;
}

template <typename Real>
bool Mathematics
	::InSphere(const Vector3D<Real>& point, const Sphere3<Real>& sphere)
{
	auto diff = point - sphere.GetCenter();
	return Vector3DTools<Real>::VectorMagnitude(diff) <= sphere.GetRadius();
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics
	::MergeSpheres(const Sphere3<Real>& sphere0, const Sphere3<Real>& sphere1)
{
	auto cenDiff = sphere1.GetCenter() - sphere0.GetCenter();
	auto lenSqr = Vector3DTools<Real>::VectorMagnitudeSquared(cenDiff);
	auto rDiff = sphere1.GetRadius() - sphere0.GetRadius();
	auto rDiffSqr = rDiff*rDiff;

    if (rDiffSqr >= lenSqr)
    {
        return (rDiff >= Real{} ? sphere1 : sphere0);
    }

	auto length = Math<Real>::Sqrt(lenSqr);
   
	Vector3D<Real> center;
    if (length > Math<Real>::sm_ZeroTolerance)
    {
        Real coeff = (length + rDiff)/(((Real)2)*length);
		center = sphere0.GetCenter() + coeff*cenDiff;
    }
    else
    {
		center = sphere0.GetCenter();
    }

	auto radius = (Real{0.5})*(length + sphere0.GetRadius() + sphere1.GetRadius());
	Sphere3<Real> sphere{ center,radius };
    return sphere;
}


#endif // MATHEMATICS_CONTAINMENT_CONT_SPHERE3_DETAIL_H