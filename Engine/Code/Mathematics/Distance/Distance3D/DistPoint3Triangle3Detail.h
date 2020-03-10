// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 13:53)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_TRIANGLE3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_POINT3_TRIANGLE3_DETAIL_H

#include "DistPoint3Triangle3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"    

template <typename Real>
Mathematics::DistPoint3Triangle3<Real>
	::DistPoint3Triangle3(const Vector3D& point,  const Triangle3& triangle)
	:ParentType{}, mPoint{ point }, mTriangle{ triangle }
{
}

template <typename Real>
const Mathematics::Vector3D<Real>& Mathematics::DistPoint3Triangle3<Real>
	::GetPoint() const
{
    return mPoint;
}

template <typename Real>
const Mathematics::Triangle3<Real>& Mathematics::DistPoint3Triangle3<Real>
	::GetTriangle() const
{
    return mTriangle;
}

template <typename Real>
typename const Mathematics::DistPoint3Triangle3<Real>::DistanceResult Mathematics::DistPoint3Triangle3<Real>
	::GetSquared() const
{
	Vector3D mClosestPoint0;
	Vector3D mClosestPoint1;

	auto diff = mTriangle.GetVertex(0) - mPoint;
	auto edge0 = mTriangle.GetVertex(1) - mTriangle.GetVertex(0);
	auto edge1 = mTriangle.GetVertex(2) - mTriangle.GetVertex(0);
	auto a00 = Vector3DTools::VectorMagnitudeSquared(edge0);
	auto a01 = Vector3DTools::DotProduct(edge0,edge1);
	auto a11 = Vector3DTools::VectorMagnitudeSquared(edge1);
	auto b0 = Vector3DTools::DotProduct(diff,edge0);
	auto b1 = Vector3DTools::DotProduct(diff,edge1);
	auto c = Vector3DTools::VectorMagnitudeSquared(diff);
	auto det = Math<Real>::FAbs(a00*a11 - a01*a01);
	auto s = a01*b1 - a11*b0;
	auto t = a01*b0 - a00*b1;
    Real sqrDistance;

    if (s + t <= det)
    {
        if (s < Real{})
        {
            if (t < Real{})  // region 4
            {
                if (b0 < Real{})
                {
                    t = Real{};
                    if (-b0 >= a00)
                    {
                        s = (Real)1;
                        sqrDistance = a00 + ((Real)2)*b0 + c;
                    }
                    else
                    {
                        s = -b0/a00;
                        sqrDistance = b0*s + c;
                    }
                }
                else
                {
                    s = Real{};
                    if (b1 >= Real{})
                    {
                        t = Real{};
                        sqrDistance = c;
                    }
                    else if (-b1 >= a11)
                    {
                        t = (Real)1;
                        sqrDistance = a11 + ((Real)2)*b1 + c;
                    }
                    else
                    {
                        t = -b1/a11;
                        sqrDistance = b1*t + c;
                    }
                }
            }
            else  // region 3
            {
                s = Real{};
                if (b1 >= Real{})
                {
                    t = Real{};
                    sqrDistance = c;
                }
                else if (-b1 >= a11)
                {
                    t = (Real)1;
                    sqrDistance = a11 + ((Real)2)*b1 + c;
                }
                else
                {
                    t = -b1/a11;
                    sqrDistance = b1*t + c;
                }
            }
        }
        else if (t < Real{})  // region 5
        {
            t = Real{};
            if (b0 >= Real{})
            {
                s = Real{};
                sqrDistance = c;
            }
            else if (-b0 >= a00)
            {
                s = (Real)1;
                sqrDistance = a00 + ((Real)2)*b0 + c;
            }
            else
            {
                s = -b0/a00;
                sqrDistance = b0*s + c;
            }
        }
        else  // region 0
        {
            // minimum at interior point
            Real invDet = ((Real)1)/det;
            s *= invDet;
            t *= invDet;
            sqrDistance = s*(a00*s + a01*t + ((Real)2)*b0) + t*(a01*s + a11*t + ((Real)2)*b1) + c;
        }
    }
    else
    {
        Real tmp0, tmp1, numer, denom;

        if (s < Real{})  // region 2
        {
            tmp0 = a01 + b0;
            tmp1 = a11 + b1;
            if (tmp1 > tmp0)
            {
                numer = tmp1 - tmp0;
                denom = a00 - ((Real)2)*a01 + a11;
                if (numer >= denom)
                {
                    s = (Real)1;
                    t = Real{};
                    sqrDistance = a00 + ((Real)2)*b0 + c;
                }
                else
                {
                    s = numer/denom;
                    t = (Real)1 - s;
                    sqrDistance = s*(a00*s + a01*t + ((Real)2)*b0) +  t*(a01*s + a11*t + ((Real)2)*b1) + c;
                }
            }
            else
            {
                s = Real{};
                if (tmp1 <= Real{})
                {
                    t = (Real)1;
                    sqrDistance = a11 + ((Real)2)*b1 + c;
                }
                else if (b1 >= Real{})
                {
                    t = Real{};
                    sqrDistance = c;
                }
                else
                {
                    t = -b1/a11;
                    sqrDistance = b1*t + c;
                }
            }
        }
        else if (t < Real{})  // region 6
        {
            tmp0 = a01 + b1;
            tmp1 = a00 + b0;
            if (tmp1 > tmp0)
            {
                numer = tmp1 - tmp0;
                denom = a00 - ((Real)2)*a01 + a11;
                if (numer >= denom)
                {
                    t = (Real)1;
                    s = Real{};
                    sqrDistance = a11 + ((Real)2)*b1 + c;
                }
                else
                {
                    t = numer/denom;
                    s = (Real)1 - t;
                    sqrDistance = s*(a00*s + a01*t + ((Real)2)*b0) +  t*(a01*s + a11*t + ((Real)2)*b1) + c;
                }
            }
            else
            {
                t = Real{};
                if (tmp1 <= Real{})
                {
                    s = (Real)1;
                    sqrDistance = a00 + ((Real)2)*b0 + c;
                }
                else if (b0 >= Real{})
                {
                    s = Real{};
                    sqrDistance = c;
                }
                else
                {
                    s = -b0/a00;
                    sqrDistance = b0*s + c;
                }
            }
        }
        else  // region 1
        {
            numer = a11 + b1 - a01 - b0;
            if (numer <= Real{})
            {
                s = Real{};
                t = (Real)1;
                sqrDistance = a11 + ((Real)2)*b1 + c;
            }
            else
            {
                denom = a00 - ((Real)2)*a01 + a11;
                if (numer >= denom)
                {
                    s = (Real)1;
                    t = Real{};
                    sqrDistance = a00 + ((Real)2)*b0 + c;
                }
                else
                {
                    s = numer/denom;
                    t = (Real)1 - s;
                    sqrDistance = s*(a00*s + a01*t + ((Real)2)*b0) + t*(a01*s + a11*t + ((Real)2)*b1) + c;
                }
            }
        }
    }

    // Account for numerical round-off error.
    if (sqrDistance < Real{})
    {
        sqrDistance = Real{};
    }

    mClosestPoint0 = mPoint;
    mClosestPoint1 = mTriangle.GetVertex(0) + s*edge0 + t*edge1;
    mTriangleBary[1] = s;
    mTriangleBary[2] = t;
    mTriangleBary[0] = (Real)1 - s - t;

	return DistanceResult{ sqrDistance, Real{}, mClosestPoint0, mClosestPoint1 };   
}
 
template <typename Real>
typename const Mathematics::DistPoint3Triangle3<Real>::DistanceResult Mathematics::DistPoint3Triangle3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedPoint = mPoint + t*lhsVelocity;
	auto movedV0 = mTriangle.GetVertex(0) + t*rhsVelocity;
	auto movedV1 = mTriangle.GetVertex(1) + t*rhsVelocity;
	auto movedV2 = mTriangle.GetVertex(2) + t*rhsVelocity;
	Triangle3 movedTriangle{ movedV0, movedV1, movedV2 };
	return DistPoint3Triangle3<Real>{ movedPoint, movedTriangle }.GetSquared();
}

template <typename Real>
Real Mathematics::DistPoint3Triangle3<Real>
	::GetTriangleBary(int i) const
{
    return mTriangleBary[i];
}

#endif // MATHEMATICS_DISTANCE_DIST_POINT3_TRIANGLE3_DETAIL_H