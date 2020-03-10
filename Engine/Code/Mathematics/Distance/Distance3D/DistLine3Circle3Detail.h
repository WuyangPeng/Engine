// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 11:35)

#ifndef MATHEMATICS_DISTANCE_DIST_LINE3_CIRCLE3_DETAIL_H 
#define MATHEMATICS_DISTANCE_DIST_LINE3_CIRCLE3_DETAIL_H 

#include "DistLine3Circle3.h"
#include "DistPoint3Circle3.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/NumericalAnalysis/PolynomialRoots.h"

template <typename Real>
Mathematics::DistLine3Circle3<Real>
	::DistLine3Circle3(const Line3& rkLine,const Circle3& rkCircle)
	: ParentType{}, mLine{ rkLine }, mCircle{ rkCircle }, mNumClosestLine{ 0 }, mNumClosestCircle{ 0 }
{
}

template <typename Real>
const Mathematics::Line3<Real>& Mathematics::DistLine3Circle3<Real>
	::GetLine() const
{
    return mLine;
}

template <typename Real>
const Mathematics::Circle3<Real>& Mathematics::DistLine3Circle3<Real>
	::GetCircle() const
{
    return mCircle;
}
 
template <typename Real>
typename const Mathematics::DistLine3Circle3<Real>::DistanceResult Mathematics::DistLine3Circle3<Real>
	::GetSquared() const
{
    auto D = mLine.GetOrigin() - mCircle.GetCenter();
    Real s, sqrDistance, temp;

	auto MxN = Vector3DTools::CrossProduct(mLine.GetDirection(),mCircle.GetNormal());
	auto m0sqr = Vector3DTools::DotProduct(MxN,MxN);
    if (m0sqr > Real{})
    {
		auto m0 = sqrt(m0sqr);
		auto rm0 = mCircle.GetRadius()*m0;
		auto DxN = Vector3DTools::CrossProduct(D,mCircle.GetNormal());
		auto lambda = Vector3DTools::DotProduct(- MxN,DxN) / m0sqr;
        D += lambda*mLine.GetDirection();
        DxN += lambda*MxN;
		auto m2b2 = Vector3DTools::DotProduct(mLine.GetDirection(),D);
		auto b1sqr = Vector3DTools::DotProduct(DxN,DxN);
        if (b1sqr > Real{})
        {
			auto b1 = sqrt(b1sqr);
			auto rm0sqr = mCircle.GetRadius()*m0sqr;
            if (rm0sqr > b1)
            {
                const auto twoThirds = (Real)2/(Real)3;
				auto sHat = sqrt(pow(rm0sqr*b1sqr, twoThirds) - b1sqr)/m0;
				auto gHat = rm0sqr*sHat/sqrt(m0sqr*sHat*sHat + b1sqr);
				auto cutoff = gHat - sHat;
                if (m2b2 <= -cutoff)
                {
                    s = BisectF(m2b2, rm0sqr, m0sqr, b1sqr, -m2b2, -m2b2 + rm0);
                    mNumClosestLine = 1;
                    mClosestLine[0] = mLine.GetOrigin() + (s + lambda)*mLine.GetDirection();
                    sqrDistance = SqrDistancePointCircle(0);
                    if (m2b2 == -cutoff)
                    {
                        mClosestLine[1] =  mLine.GetOrigin() + (-sHat + lambda)*mLine.GetDirection();
                        temp = SqrDistancePointCircle(1);
                        if (temp < sqrDistance)
                        {
                            sqrDistance = temp;
                            std::swap(mClosestLine[0], mClosestLine[1]);
                            std::swap(mClosestCircle[0], mClosestCircle[1]);
                        }
                        else if (temp == sqrDistance)
                        {
                            mNumClosestLine = 2;
                            mNumClosestCircle = 2;
                        }
                    }
                }
                else if (m2b2 >= cutoff)
                {
                    s = BisectF(m2b2, rm0sqr, m0sqr, b1sqr, -m2b2 - rm0, -m2b2);
                    mNumClosestLine = 1;
                    mClosestLine[0] = mLine.GetOrigin() + (s + lambda)*mLine.GetDirection();
                    sqrDistance = SqrDistancePointCircle(0);
                    if (m2b2 == cutoff)
                    {
                        mClosestLine[1] = mLine.GetOrigin() + (+sHat + lambda)*mLine.GetDirection();
                        temp = SqrDistancePointCircle(1);
                        if (temp < sqrDistance)
                        {
                            sqrDistance = temp;
                            std::swap(mClosestLine[0], mClosestLine[1]);
                            std::swap(mClosestCircle[0], mClosestCircle[1]);
                        }
                        else if (temp == sqrDistance)
                        {
                            mNumClosestLine = 2;
                            mNumClosestCircle = 2;
                        }
                    }
                }
                else
                {
                    if (m2b2 <= Real{})
                    {
                        s = BisectF(m2b2, rm0sqr, m0sqr, b1sqr, -m2b2, -m2b2 + rm0);
                        mNumClosestLine = 1;
                        mClosestLine[0] =  mLine.GetOrigin() + (s + lambda)*mLine.GetDirection();
                        sqrDistance = SqrDistancePointCircle(0);
                        s = BisectF(m2b2, rm0sqr, m0sqr, b1sqr, -m2b2 - rm0, -sHat);
                        mClosestLine[1] = mLine.GetOrigin() + (s + lambda)*mLine.GetDirection();
                        temp = SqrDistancePointCircle(1);
                        if (temp < sqrDistance)
                        {
                            sqrDistance = temp;
                            std::swap(mClosestLine[0], mClosestLine[1]);
                            std::swap(mClosestCircle[0], mClosestCircle[1]);
                        }
                        else if (temp == sqrDistance)
                        {
                            mNumClosestLine = 2;
                            mNumClosestCircle = 2;
                        }
                    }
                    else
                    {
                        s = BisectF(m2b2, rm0sqr, m0sqr, b1sqr, -m2b2 - rm0, -m2b2);
                        mNumClosestLine = 1;
                        mClosestLine[0] = mLine.GetOrigin() + (s + lambda)*mLine.GetDirection();
                        sqrDistance = SqrDistancePointCircle(0);
                        s = BisectF(m2b2, rm0sqr, m0sqr, b1sqr, sHat, -m2b2 + rm0);
                        mClosestLine[1] =  mLine.GetOrigin() + (s + lambda)*mLine.GetDirection();
                        temp = SqrDistancePointCircle(1);
                        if (temp < sqrDistance)
                        {
                            sqrDistance = temp;
                            std::swap(mClosestLine[0], mClosestLine[1]);
                            std::swap(mClosestCircle[0], mClosestCircle[1]);
                        }
                        else if (temp == sqrDistance)
                        {
                            mNumClosestLine = 2;
                            mNumClosestCircle = 2;
                        }
                    }
                }
            }
            else
            {
                if (m2b2 < Real{})
                {
                    s = BisectF(m2b2, rm0sqr, m0sqr, b1sqr, -m2b2, -m2b2 + rm0);
                    mNumClosestLine = 1;
                    mClosestLine[0] =  mLine.GetOrigin() + (s + lambda)*mLine.GetDirection();
                    sqrDistance = SqrDistancePointCircle(0);
                }
                else if (m2b2 > Real{})
                {
                    s = BisectF(m2b2, rm0sqr, m0sqr, b1sqr, -m2b2 - rm0, -m2b2);
                    mNumClosestLine = 1;
                    mClosestLine[0] = mLine.GetOrigin() + (s + lambda)*mLine.GetDirection();
                    sqrDistance = SqrDistancePointCircle(0);
                }
                else
                {
                    mNumClosestLine = 1;
                    mClosestLine[0] = mLine.GetOrigin() + lambda*mLine.GetDirection();
                    sqrDistance = SqrDistancePointCircle(0);
                }
            }
        }
        else
        {
            if (m2b2 < Real{})
            {
                s = -m2b2 + rm0;
                mNumClosestLine = 1;
                mClosestLine[0] =  mLine.GetOrigin() + (s + lambda)*mLine.GetDirection();
                sqrDistance = SqrDistancePointCircle(0);
            }
            else if (m2b2 > Real{})
            {
                s = -m2b2 - rm0;
                mNumClosestLine = 1;
                mClosestLine[0] = mLine.GetOrigin() + (s + lambda)*mLine.GetDirection();
                sqrDistance = SqrDistancePointCircle(0);
            }
            else
            {
                s = -m2b2 + rm0;
                mClosestLine[0] =  mLine.GetOrigin() + (s + lambda)*mLine.GetDirection();
                sqrDistance = SqrDistancePointCircle(0);
                s = -m2b2 - rm0;
                mClosestLine[1] = mLine.GetOrigin() + (s + lambda)*mLine.GetDirection();
                sqrDistance = SqrDistancePointCircle(1);
                mNumClosestLine = 2;
                mNumClosestCircle = 2;
            }
        }
    }
    else
    {
        mNumClosestLine = 1;
        mClosestLine[0] = mLine.GetOrigin() - Vector3DTools::DotProduct(mCircle.GetNormal(),D)*mCircle.GetNormal();
        sqrDistance = SqrDistancePointCircle(0);
    }

	typename DistanceResult::ClosestPoints mClosestPoint0;
	typename DistanceResult::ClosestPoints mClosestPoint1; 

	for (int i = 0; i < mNumClosestLine;++i)
	{
		mClosestPoint0.push_back(mClosestLine[i]);
	}

	for (int i = 0; i < mNumClosestCircle; ++i)
	{
		mClosestPoint1.push_back(mClosestCircle[i]);
	} 

	return DistanceResult(sqrDistance, Real{}, mClosestPoint0, mClosestPoint1); 
}
 
template <typename Real>
typename const Mathematics::DistLine3Circle3<Real>::DistanceResult Mathematics::DistLine3Circle3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	auto movedOrigin = mLine.GetOrigin() + t*lhsVelocity;
	auto movedCenter = mCircle.GetCenter() + t*rhsVelocity;
	Line3 movedLine{ movedOrigin, mLine.GetDirection() };
	Circle3 movedCircle{ movedCenter, mCircle.GetDirection0(), mCircle.GetDirection1(), mCircle.GetNormal(), mCircle.GetRadius() };

	return DistLine3Circle3<Real>{ movedLine, movedCircle }.GetSquared();
}

template <typename Real>
Real Mathematics::DistLine3Circle3<Real>
	::SqrDistancePointCircle(int i) const
{
	auto PmC = mClosestLine[i] - mCircle.GetCenter();
	auto QmC = PmC - Vector3DTools::DotProduct(mCircle.GetNormal(), PmC)*mCircle.GetNormal();
	auto lengthQmC = Vector3DTools::VectorMagnitude(QmC);
    if (lengthQmC > Real{})
    {
        mNumClosestCircle = 1;
        mClosestCircle[i] = mCircle.GetCenter() + mCircle.GetRadius()*QmC/lengthQmC;  
    }
    else
    {
        // All circle points are equidistant from P.  Return one of them.
        mNumClosestCircle = INT_MAX;
        mClosestCircle[i] = mCircle.GetCenter() + mCircle.GetRadius()*mCircle.GetDirection0();
    }
	auto diff = mClosestLine[i] - mClosestCircle[i];
	return Vector3DTools::DotProduct(diff,diff);
}

template <typename Real>
Real Mathematics::DistLine3Circle3<Real>
	::BisectF(Real m2b2, Real rm0sqr, Real m0sqr, Real b1sqr, Real smin, Real smax)
{
	Real s{}; 
	Real f{};
    for (auto i = 0; i < 1024; ++i)
    {
        s = (Real{0.5})*(smin + smax);
        f = s + m2b2 - rm0sqr*s/sqrt(m0sqr*s*s + b1sqr);
        if (f == Real{} || s == smin || s == smax)
        {
            return s;
        }
        if (f > Real{})
        {
            smax = s;
        }
        else
        {
            smin = s;
        }
    }

    MATHEMATICS_ASSERTION_0(false, "Exceeded maximum iterations.");
    return s;
}

#endif // MATHEMATICS_DISTANCE_DIST_LINE3_CIRCLE3_DETAIL_H