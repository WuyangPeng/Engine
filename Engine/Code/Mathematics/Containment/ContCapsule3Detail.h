// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:27)

#ifndef MATHEMATICS_CONTAINMENT_CONT_CAPSULE3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_CAPSULE3_DETAIL_H

#include "ContCapsule3.h"
#include "Mathematics/Approximation/OrthogonalLineFit3.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Line3.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Segment3Detail.h"

template <typename Real>
Mathematics::Capsule3<Real> Mathematics
	::ContCapsule(const std::vector<Vector3<Real> >& points)
{
	auto line = OrthogonalLineFit3<Real>(points).GetLine3();

	auto maxRadiusSqr = Math<Real>::GetValue(0);
     
	for (auto i = 0u; i < points.size(); ++i)
    {
		auto rSqr = DistancePoint3Line3<Real>(points[i], line).GetSquared();
        if (rSqr.GetDistance() > maxRadiusSqr)
        {
            maxRadiusSqr = rSqr.GetDistance();
        }
    }

	auto Vector3OrthonormalBasis =	Vector3Tools<Real>::GenerateComplementBasis(line.GetDirection());

	auto U = Vector3OrthonormalBasis.GetUVector();
	auto V = Vector3OrthonormalBasis.GetVVector();
	auto W = line.GetDirection();
 
	auto minValue = Math<Real>::maxReal;
	auto maxValue = -Math<Real>::maxReal;
	for (auto i = 0u; i < points.size(); ++i)
    {
		auto diff = points[i] - line.GetOrigin();
		auto uDotDiff = Vector3Tools<Real>::DotProduct(U,diff);
		auto vDotDiff = Vector3Tools<Real>::DotProduct(V,diff);
		auto wDotDiff = Vector3Tools<Real>::DotProduct(W,diff);
		auto discr = maxRadiusSqr - (uDotDiff*uDotDiff + vDotDiff*vDotDiff);
		auto radical = Math<Real>::Sqrt(Math<Real>::FAbs(discr));

		auto test = wDotDiff + radical;
        if (test < minValue)
        {
            minValue = test;
        }

        test = wDotDiff - radical;
        if (test > maxValue)
        {
            maxValue = test;
        }
    }


	Real extent { };
	if (maxValue > minValue)
	{
		// Container is a capsule.
		extent = (Real{0.5})*(maxValue - minValue);
	}
	else
	{
		// Container is a sphere.
		extent = Math<Real>::GetValue(0);
	}

	auto center = line.GetOrigin() + ((Real{0.5})*(minValue + maxValue))*line.GetDirection();
	auto direction = line.GetDirection();
	Segment3<Real> segment{ extent, center,direction };

	auto radius = Math<Real>::Sqrt(maxRadiusSqr);

	Capsule3<Real> capsule{ segment, radius };
   
    return capsule;
}

template <typename Real>
bool Mathematics
	::InCapsule(const Vector3<Real>& point, const Capsule3<Real>& capsule)
{
	auto distance = DistancePoint3Segment3<Real>(point, capsule.GetSegment()).Get();
    return distance.GetDistance() <= capsule.GetRadius();
}

template <typename Real>
bool Mathematics
	::InCapsule(const Sphere3<Real>& sphere, const Capsule3<Real>& capsule)
{
	auto rDiff = capsule.GetRadius() - sphere.GetRadius();
    if (rDiff >= Math<Real>::GetValue(0))
    {
		auto distance = DistancePoint3Segment3<Real>(sphere.GetCenter(), capsule.GetSegment()).Get();
        return distance.GetDistance() <= rDiff;
    }
    return false;
}

template <typename Real>
bool Mathematics
	::InCapsule(const Capsule3<Real>& testCapsule, const Capsule3<Real>& capsule)
{
	Sphere3<Real> spherePosEnd{ testCapsule.GetSegment().GetEndPoint(), testCapsule.GetRadius() };
	Sphere3<Real> sphereNegEnd{ testCapsule.GetSegment().GetBeginPoint(), testCapsule.GetRadius() };

    return InCapsule<Real>(spherePosEnd, capsule) && InCapsule<Real>(sphereNegEnd, capsule);
}

template <typename Real>
Mathematics::Capsule3<Real> Mathematics
	::MergeCapsules(const Capsule3<Real>& capsule0, const Capsule3<Real>& capsule1)
{
    if (InCapsule<Real>(capsule0, capsule1))
    {
        return capsule1;
    }

    if (InCapsule<Real>(capsule1, capsule0))
    {
        return capsule0;
    }

	const auto& P0 = capsule0.GetSegment().GetCenterPoint();
	const auto& P1 = capsule1.GetSegment().GetCenterPoint();
	const auto& D0 = capsule0.GetSegment().GetDirection();
	const auto& D1 = capsule1.GetSegment().GetDirection();

	// Axis center is average of input axis centers.
	auto origin = (Real{0.5})*(P0 + P1);
	Vector3<Real> direction;

	// Axis unit direction is average of input axis unit directions.
	if (Vector3Tools<Real>::DotProduct(D0,D1) >= Math<Real>::GetValue(0))
	{
		direction = D0 + D1;
	}
	else
	{
		direction = D0 - D1;
	}
	direction.Normalize();

    // Axis of final capsule.
	Line3<Real> line{ origin, direction };

    // Cylinder with axis 'line' must contain the spheres centered at the
    // endpoints of the input capsules.
	auto posEnd0 = capsule0.GetSegment().GetEndPoint();
	auto radius = DistancePoint3Line3<Real>(posEnd0, line).Get().GetDistance() +  capsule0.GetRadius();

	auto negEnd0 = capsule0.GetSegment().GetBeginPoint();
	auto tmp = DistancePoint3Line3<Real>(negEnd0, line).Get().GetDistance() + capsule0.GetRadius();
    if (tmp > radius)
    {
        radius = tmp;
    }

	auto posEnd1 = capsule1.GetSegment().GetEndPoint();
	tmp = DistancePoint3Line3<Real>(posEnd1, line).Get().GetDistance() + capsule1.GetRadius();
    if (tmp > radius)
    {
        radius = tmp;
    }

	auto negEnd1 = capsule1.GetSegment().GetBeginPoint();
	tmp = DistancePoint3Line3<Real>(negEnd1, line).Get().GetDistance() + capsule1.GetRadius();
    if (tmp > radius)
    {
        radius = tmp;
    }

    // Process sphere <posEnd0,r0>.
	auto rDiff = radius - capsule0.GetRadius();
	auto rDiffSqr = rDiff*rDiff;
	auto diff = line.GetOrigin() - posEnd0;
	auto k0 = Vector3Tools<Real>::GetLengthSquared(diff)  - rDiffSqr;
	auto k1 = Vector3Tools<Real>::DotProduct(diff,line.GetDirection());
	auto discr = k1*k1 - k0;  // assert:  k1*k1-k0 >= 0
	auto root = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
	auto tPos = -k1 - root;
	auto tNeg = -k1 + root;

    // Process sphere <negEnd0,r0>.
    diff = line.GetOrigin() - negEnd0;
	k0 = Vector3Tools<Real>::GetLengthSquared(diff) - rDiffSqr;
	k1 = Vector3Tools<Real>::DotProduct(diff,line.GetDirection());
    discr = k1*k1 - k0;  // assert:  k1*k1-k0 >= 0
    root = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
    tmp = -k1 - root;
    if (tmp > tPos)
    {
        tPos = tmp;
    }
    tmp = -k1 + root;
    if (tmp < tNeg)
    {
        tNeg = tmp;
    }

    // Process sphere <posEnd1,r1>.
    rDiff = radius - capsule1.GetRadius();
    rDiffSqr = rDiff*rDiff;
	diff = line.GetOrigin() - posEnd1;
	k0 = Vector3Tools<Real>::GetLengthSquared(diff) - rDiffSqr;
	k1 = Vector3Tools<Real>::DotProduct(diff,line.GetDirection());
    discr = k1*k1 - k0;  // assert:  k1*k1-k0 >= 0
    root = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
    tmp = -k1 - root;
    if (tmp > tPos)
    {
        tPos = tmp;
    }
    tmp = -k1 + root;
    if (tmp < tNeg)
    {
        tNeg = tmp;
    }

    // Process sphere <negEnd1,r1>.
    diff = line.GetOrigin() - negEnd1;
	k0 = Vector3Tools<Real>::GetLengthSquared(diff) - rDiffSqr;
	k1 = Vector3Tools<Real>::DotProduct(diff,line.GetDirection());
    discr = k1*k1 - k0;  // assert:  K1*K1-K0 >= 0
    root = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
    tmp = -k1 - root;
    if (tmp > tPos)
    {
        tPos = tmp;
    }
    tmp = -k1 + root;
    if (tmp < tNeg)
    {
        tNeg = tmp;
    }

	auto center = line.GetOrigin() + (Real{0.5})*(tPos + tNeg)*line.GetDirection();
	 direction = line.GetDirection();

	Real extent { };
	if (tPos > tNeg)
	{
		// Container is a capsule.
		extent = (Real{0.5})*(tPos - tNeg);
	}
	else
	{
		// Container is a sphere.
		extent = Math<Real>::GetValue(0);
	}

	Segment3<Real> segment{ extent, center, direction };

	Capsule3<Real> capsule{ segment,radius };
    
    return capsule;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_CAPSULE3_DETAIL_H