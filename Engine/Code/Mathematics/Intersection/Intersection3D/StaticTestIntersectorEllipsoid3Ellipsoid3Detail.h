// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 11:13)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_DETAIL_H

#include "StaticTestIntersectorEllipsoid3Ellipsoid3.h" 
#include "Mathematics/Algebra/Matrix3.h"

template <typename Real>
Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>
	::StaticTestIntersectorEllipsoid3Ellipsoid3 (const Ellipsoid3& ellipsoid0, const Ellipsoid3& ellipsoid1)
	: mEllipsoid0{ ellipsoid0 }, mEllipsoid1{ ellipsoid1 }, m_Classification{ EC_ELLIPSOIDS_SEPARATED }
{
	Test();
}

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>
	::GetEllipsoid0 () const
{
    return mEllipsoid0;
}

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>
	::GetEllipsoid1 () const
{
    return mEllipsoid1;
}

template <typename Real>
typename Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::Classification
	Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>
	::GetClassification () const
{
	return m_Classification;
}


template <typename Real>
void Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>
	::Test()
{
    // Get the parameters of ellipsoid0.
	auto K0 = mEllipsoid0.GetCenter();
	Matrix3<Real> R0{ mEllipsoid0.GetAxis0(),mEllipsoid0.GetAxis1(),mEllipsoid0.GetAxis2(), MatrixMajorFlags::Row };
	Matrix3<Real> D0{ ((Real)1) / (mEllipsoid0.GetExtent0()*mEllipsoid0.GetExtent0()),
					  ((Real)1) / (mEllipsoid0.GetExtent1()*mEllipsoid0.GetExtent1()),
					  ((Real)1) / (mEllipsoid0.GetExtent2()*mEllipsoid0.GetExtent2()) };

    // Get the parameters of ellipsoid1.
	auto K1 = mEllipsoid1.GetCenter();
	Matrix3<Real> R1{ mEllipsoid1.GetAxis0(),mEllipsoid1.GetAxis1(),mEllipsoid1.GetAxis2(), MatrixMajorFlags::Row };
	Matrix3<Real> D1{ ((Real)1) / (mEllipsoid1.GetExtent0()*mEllipsoid1.GetExtent0()),
					  ((Real)1) / (mEllipsoid1.GetExtent1()*mEllipsoid1.GetExtent1()),
					  ((Real)1) / (mEllipsoid1.GetExtent2()*mEllipsoid1.GetExtent2()) };

    // Compute K2.
	Matrix3<Real> D0NegHalf{ mEllipsoid0.GetExtent0(),mEllipsoid0.GetExtent1(),mEllipsoid0.GetExtent2() };
	Matrix3<Real> D0Half{((Real)1) / mEllipsoid0.GetExtent0(),((Real)1) / mEllipsoid0.GetExtent1(),	((Real)1) / mEllipsoid0.GetExtent2() };
	auto K2 = D0Half*((K1 - K0)*R0);

    // Compute M2.
	auto R1TR0D0NegHalf = TransposeTimes(R1,R0*D0NegHalf);
	auto M2 =TransposeTimes(R1TR0D0NegHalf,(D1)*R1TR0D0NegHalf);

    // Factor M2 = Real*D*Real^T.
 
	auto matrix3EigenDecomposition =  M2.EigenDecomposition();
	auto R = matrix3EigenDecomposition.GetRotation();
	auto D = matrix3EigenDecomposition.GetDiagonal();

    // Compute K = Real^T*K2.
	auto K = K2*R;

    // Transformed ellipsoid0 is Z^T*Z = 1 and transformed ellipsoid1 is
    // (Z-K)^T*D*(Z-K) = 0.

    // The minimum and maximum squared distances from the origin of points on
    // transformed ellipsoid1 are used to determine whether the ellipsoids
    // intersect, are separated, or one contains the other.
	auto minSqrDistance = Math::sm_MaxReal;
	auto maxSqrDistance = Real{};
    int i;

    if (K == Vector3D::sm_Zero)
    {
        // The special case of common centers must be handled separately.  It
        // is not possible for the ellipsoids to be separated.
        for (i = 0; i < 3; ++i)
        {
			auto invD = ((Real)1)/D[i][i];
            if (invD < minSqrDistance)
            {
                minSqrDistance = invD;
            }
            if (invD > maxSqrDistance)
            {
                maxSqrDistance = invD;
            }
        }

        if (maxSqrDistance < (Real)1)
        {
            m_Classification = EC_ELLIPSOID0_CONTAINS_ELLIPSOID1;
			return;
        }
        else if (minSqrDistance > (Real)1)
        {
            m_Classification =  EC_ELLIPSOID1_CONTAINS_ELLIPSOID0;
			return;
        }
        else
        {
            m_Classification =  EC_ELLIPSOIDS_INTERSECTING;
			return;
        }
    }

    // The closest point P0 and farthest point P1 are solutions to
    // s0*D*(P0 - K) = P0 and s1*D*(P1 - K) = P1 for some scalars s0 and s1
    // that are roots to the function
    //   f(s) = d0*k0^2/(d0*s-1)^2+d1*k1^2/(d1*s-1)^2+d2*k2^2/(d2*s-1)^2-1
    // where D = diagonal(d0,d1,d2) and K = (k0,k1,k2).
	auto d0 = D[0][0], d1 = D[1][1], d2 = D[2][2];
	auto c0 = K[0]*K[0], c1 = K[1]*K[1], c2 = K[2]*K[2];

    // Sort the values so that d0 >= d1 >= d2.  This allows us to bound the
    // roots of f(s), of which there are at most 6.
    std::vector<std::pair<Real,Real> > param(3);
    param[0] = std::make_pair(d0, c0);
    param[1] = std::make_pair(d1, c1);
    param[2] = std::make_pair(d2, c2);
    std::sort(param.begin(), param.end(),std::greater<std::pair<Real,Real> >());

    std::vector<std::pair<Real,Real> > valid;
    valid.reserve(3);
    if (param[0].first > param[1].first)
    {
        if (param[1].first > param[2].first)
        {
            // d0 > d1 > d2
            for (i = 0; i < 3; ++i)
            {
                if (param[i].second > Real{})
                {
                    valid.push_back(param[i]);
                }
            }
        }
        else
        {
            // d0 > d1 = d2
            if (param[0].second > Real{})
            {
                valid.push_back(param[0]);
            }
            param[1].second += param[0].second;
            if (param[1].second > Real{})
            {
                valid.push_back(param[1]);
            }
        }
    }
    else
    {
        if (param[1].first > param[2].first)
        {
            // d0 = d1 > d2
            param[0].second += param[1].second;
            if (param[0].second > Real{})
            {
                valid.push_back(param[0]);
            }
            if (param[2].second > Real{})
            {
                valid.push_back(param[2]);
            }
        }
        else
        {
            // d0 = d1 = d2
            param[0].second += param[1].second + param[2].second;
            if (param[0].second > Real{})
            {
                valid.push_back(param[0]);
            }
        }
    }

	auto numValid = valid.size();
    int numRoots;
    Real roots[6];
    if (numValid == 3)
    {
        GetRoots(valid[0].first, valid[1].first, valid[2].first, valid[0].second, valid[1].second, valid[2].second, numRoots, roots);
    }
    else if (numValid == 2)
    {
        GetRoots(valid[0].first, valid[1].first, valid[0].second, valid[1].second, numRoots, roots);
    }
    else if (numValid == 1)
    {
        GetRoots(valid[0].first,valid[0].second, numRoots, roots);
    }
    else
    {
        // numValid cannot be zero because we already handled case K = 0
        MATHEMATICS_ASSERTION_0(false, "Unexpected condition.\n");
        m_Classification =  EC_ELLIPSOIDS_INTERSECTING;
		return;
    }

    for (i = 0; i < numRoots; ++i)
    {
		auto s = roots[i];
		auto p0 = d0*K[0]*s/(d0*s - (Real)1);
		auto p1 = d1*K[1]*s/(d1*s - (Real)1);
		auto p2 = d2*K[2]*s/(d2*s - (Real)1);
		auto sqrDistance = p0*p0 + p1*p1 + p2*p2;
        if (sqrDistance < minSqrDistance)
        {
            minSqrDistance = sqrDistance;
        }
        if (sqrDistance > maxSqrDistance)
        {
            maxSqrDistance = sqrDistance;
        }
    }

    if (maxSqrDistance < (Real)1)
    {
        m_Classification =  EC_ELLIPSOID0_CONTAINS_ELLIPSOID1;
		return;
    }

    if (minSqrDistance > (Real)1)
    {
        if (d0*c0 + d1*c1 + d2*c2 > (Real)1)
        {
            m_Classification =  EC_ELLIPSOIDS_SEPARATED;
			return;
        }
        else
        {
            m_Classification =  EC_ELLIPSOID1_CONTAINS_ELLIPSOID0;
			return;
        }
    }

    m_Classification =  EC_ELLIPSOIDS_INTERSECTING;
}

template <typename Real>
void Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>
	::BisectF (Real d0, Real d1, Real d2,Real d0c0, Real d1c1, Real d2c2, Real smin, Real fmin, Real smax,Real fmax, Real& s, Real& f)
{
	auto increasing = (fmin < Real{});

    constexpr auto maxIterations = 256;
    for (auto i = 0; i < maxIterations; ++i)
    {
        s = (Real{0.5})*(smin + smax);
        if (smin < s)
        {
            if (s < smax)
            {
				auto invN0 = ((Real)1)/(d0*s - (Real)1);
				auto invN1 = ((Real)1)/(d1*s - (Real)1);
				auto invN2 = ((Real)1)/(d2*s - (Real)1);
				auto invN0Sqr = invN0*invN0;
				auto invN1Sqr = invN1*invN1;
				auto invN2Sqr = invN2*invN2;
                f = d0c0*invN0Sqr + d1c1*invN1Sqr + d2c2*invN2Sqr - (Real)1;
                if (f < Real{})
                {
                    if (increasing)
                    {
                        smin = s;
                        fmin = f;
                    }
                    else
                    {
                        smax = s;
                        fmax = f;
                    }
                }
                else if (f > Real{})
                {
                    if (increasing)
                    {
                        smax = s;
                        fmax = f;
                    }
                    else
                    {
                        smin = s;
                        fmin = f;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                f = fmax;
                break;
            }
        }
        else
        {
            f = fmin;
            break;
        }
    }
}

template <typename Real>
void Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>
	::BisectDF (Real d0, Real d1, Real d2,Real d0c0, Real d1c1, Real d2c2, Real smin, Real dfmin, Real smax,Real dfmax, Real& s, Real& df)
{
    constexpr auto maxIterations = 256;
    for (auto i = 0; i < maxIterations; ++i)
    {
        s = (Real{0.5})*(smin + smax);
        if (smin < s)
        {
            if (s < smax)
            {
				auto invN0 = ((Real)1)/(d0*s - (Real)1);
				auto invN1 = ((Real)1)/(d1*s - (Real)1);
				auto invN2 = ((Real)1)/(d2*s - (Real)1);
				auto invN0Cub = invN0*invN0*invN0;
				auto invN1Cub = invN1*invN1*invN1;
				auto invN2Cub = invN2*invN2*invN2;
                df = ((Real)-2)*(d0*d0c0*invN0Cub + d1*d1c1*invN1Cub +  d2*d2c2*invN2Cub);
                if (df < Real{})
                {
                    smin = s;
                    dfmin = df;
                }
                else if (df > Real{})
                {
                    smax = s;
                    dfmax = df;
                }
                else
                {
                    break;
                }
            }
            else
            {
                df = dfmax;
                break;
            }
        }
        else
        {
            df = dfmin;
            break;
        }
    }
}

template <typename Real>
void Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>
	::GetRoots (Real d0, Real d1, Real d2,Real c0, Real c1, Real c2, int& numRoots, Real* roots)
{
    // f(s) = d0*c0/(d0*s-1)^2 + d1*c1/(d1*s-1)^2 + d2*c2/(d2*s-1)^2 - 1
    // with d0 > d1 > d2

    numRoots = 0;

    // f(s) = d0*c0/(d0*s-1)^2 + d1*c1/(d1*s-1)^2 - 1
    // with d0 > d1
	auto epsilon = Real{0.001};
	auto multiplier0 = Math::Sqrt(((Real)3)/((Real)1 - epsilon));
	auto multiplier1 = Math::Sqrt(((Real)1)/((Real)1 + epsilon));
	auto d0c0 = d0*c0;
	auto d1c1 = d1*c1;
	auto d2c2 = d2*c2;
	auto sqrtd0c0 = Math::Sqrt(d0c0);
	auto sqrtd1c1 = Math::Sqrt(d1c1);
	auto sqrtd2c2 = Math::Sqrt(d2c2);
	auto invD0 = ((Real)1)/d0;
	auto invD1 = ((Real)1)/d1;
	auto invD2 = ((Real)1)/d2;
    Real temp0, temp1, temp2, smin, smax, s, fmin, fmax, f;
    Real invN0, invN1, invN2, invN0Sqr, invN1Sqr, invN2Sqr;

    // Compute root in (-infinity,1/d0).
    temp0 = ((Real)1 - multiplier0*sqrtd0c0)*invD0;
    temp1 = ((Real)1 - multiplier0*sqrtd1c1)*invD1;
    temp2 = ((Real)1 - multiplier0*sqrtd2c2)*invD2;
    smin = (temp0 < temp1 ? temp0 : temp1);
    smin = (temp2 < smin ? temp2 : smin);
    invN0 = ((Real)1)/(d0*smin - (Real)1);
    invN1 = ((Real)1)/(d1*smin - (Real)1);
    invN2 = ((Real)1)/(d2*smin - (Real)1);
    invN0Sqr = invN0*invN0;
    invN1Sqr = invN1*invN1;
    invN2Sqr = invN2*invN2;
    fmin = d0c0*invN0Sqr + d1c1*invN1Sqr + d2c2*invN2Sqr - (Real)1;
    MATHEMATICS_ASSERTION_0(fmin < Real{}, "Unexpected condition.\n");
    smax = ((Real)1 - multiplier1*sqrtd0c0)*invD0;
    invN0 = ((Real)1)/(d0*smax - (Real)1);
    invN1 = ((Real)1)/(d1*smax - (Real)1);
    invN2 = ((Real)1)/(d2*smax - (Real)1);
    invN0Sqr = invN0*invN0;
    invN1Sqr = invN1*invN1;
    invN2Sqr = invN2*invN2;
    fmax = d0c0*invN0Sqr + d1c1*invN1Sqr + d2c2*invN2Sqr - (Real)1;
    MATHEMATICS_ASSERTION_0(fmax > Real{}, "Unexpected condition.\n");
    BisectF(d0, d1, d2, d0c0, d1c1, d2c2, smin, fmin, smax, fmax, s, f);
    roots[numRoots++] = s;

    // Compute roots (if any) in (1/d0,1/d1).
    Real smid, fmid, df;
    BisectDF(d0, d1, d2, d0c0, d1c1, d2c2, invD0, -Math::sm_MaxReal, invD1, Math::sm_MaxReal, smid, df);
    invN0 = ((Real)1)/(d0*smid - (Real)1);
    invN1 = ((Real)1)/(d1*smid - (Real)1);
    invN2 = ((Real)1)/(d2*smid - (Real)1);
    invN0Sqr = invN0*invN0;
    invN1Sqr = invN1*invN1;
    invN2Sqr = invN2*invN2;
    fmid = d0c0*invN0Sqr + d1c1*invN1Sqr + d2c2*invN2Sqr - (Real)1;
    if (fmid < Real{})
    {
        BisectF(d0, d1, d2, d0c0, d1c1, d2c2, invD0, Math::sm_MaxReal, smid, fmid, s, f);
        roots[numRoots++] = s;
        BisectF(d0, d1, d2, d0c0, d1c1, d2c2, smid, fmid, invD1,   Math::sm_MaxReal, s, f);
        roots[numRoots++] = s;
    }

    // Compute roots (if any) in (1/d1,1/d2).
    BisectDF(d0, d1, d2, d0c0, d1c1, d2c2, invD1, -Math::sm_MaxReal, invD2, Math::sm_MaxReal, smid, df);
    invN0 = ((Real)1)/(d0*smid - (Real)1);
    invN1 = ((Real)1)/(d1*smid - (Real)1);
    invN2 = ((Real)1)/(d2*smid - (Real)1);
    invN0Sqr = invN0*invN0;
    invN1Sqr = invN1*invN1;
    invN2Sqr = invN2*invN2;
    fmid = d0c0*invN0Sqr + d1c1*invN1Sqr + d2c2*invN2Sqr - (Real)1;
    if (fmid < Real{})
    {
        BisectF(d0, d1, d2, d0c0, d1c1, d2c2, invD1, Math::sm_MaxReal, smid, fmid, s, f);
        roots[numRoots++] = s;
        BisectF(d0, d1, d2, d0c0, d1c1, d2c2, smid, fmid, invD2,  Math::sm_MaxReal, s, f);
        roots[numRoots++] = s;
    }

    // Compute root in (1/d2,+infinity).
    temp0 = ((Real)1 + multiplier0*sqrtd0c0)*invD0;
    temp1 = ((Real)1 + multiplier0*sqrtd1c1)*invD1;
    temp2 = ((Real)1 + multiplier0*sqrtd2c2)*invD2;
    smax = (temp0 > temp1 ? temp0 : temp1);
    smax = (temp2 > smax ? temp2 : smax);
    invN0 = ((Real)1)/(d0*smax - (Real)1);
    invN1 = ((Real)1)/(d1*smax - (Real)1);
    invN2 = ((Real)1)/(d2*smax - (Real)1);
    invN0Sqr = invN0*invN0;
    invN1Sqr = invN1*invN1;
    invN2Sqr = invN2*invN2;
    fmax = d0c0*invN0Sqr + d1c1*invN1Sqr + d2c2*invN2Sqr - (Real)1;
    MATHEMATICS_ASSERTION_0(fmax < Real{}, "Unexpected condition.\n");
    smin = ((Real)1 + multiplier1*sqrtd2c2)*invD2;
    invN0 = ((Real)1)/(d0*smin - (Real)1);
    invN1 = ((Real)1)/(d1*smin - (Real)1);
    invN2 = ((Real)1)/(d2*smin - (Real)1);
    invN0Sqr = invN0*invN0;
    invN1Sqr = invN1*invN1;
    invN2Sqr = invN2*invN2;
    fmin = d0c0*invN0Sqr + d1c1*invN1Sqr + d2c2*invN2Sqr - (Real)1;
    MATHEMATICS_ASSERTION_0(fmin > Real{}, "Unexpected condition.\n");
    BisectF(d0, d1, d2, d0c0, d1c1, d2c2, smin, fmin, smax, fmax, s, f);
    roots[numRoots++] = s;
}

template <typename Real>
void Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>
	::BisectF (Real d0, Real d1, Real d0c0, Real d1c1, Real smin, Real fmin, Real smax, Real fmax, Real& s, Real& f)
{
	auto increasing = (fmin < Real{});

    constexpr auto maxIterations = 256;
    for (auto i = 0; i < maxIterations; ++i)
    {
        s = (Real{0.5})*(smin + smax);
        if (smin < s)
        {
            if (s < smax)
            {
				auto invN0 = ((Real)1)/(d0*s - (Real)1);
				auto invN1 = ((Real)1)/(d1*s - (Real)1);
				auto invN0Sqr = invN0*invN0;
				auto invN1Sqr = invN1*invN1;
                f = d0c0*invN0Sqr + d1c1*invN1Sqr - (Real)1;
                if (f < Real{})
                {
                    if (increasing)
                    {
                        smin = s;
                        fmin = f;
                    }
                    else
                    {
                        smax = s;
                        fmax = f;
                    }
                }
                else if (f > Real{})
                {
                    if (increasing)
                    {
                        smax = s;
                        fmax = f;
                    }
                    else
                    {
                        smin = s;
                        fmin = f;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                f = fmax;
                break;
            }
        }
        else
        {
            f = fmin;
            break;
        }
    }
}

template <typename Real>
void Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>
	::BisectDF (Real d0, Real d1, Real d0c0, Real d1c1, Real smin, Real dfmin, Real smax, Real dfmax, Real& s, Real& df)
{
    constexpr auto maxIterations = 256;
    for (auto i = 0; i < maxIterations; ++i)
    {
        s = (Real{0.5})*(smin + smax);
        if (smin < s)
        {
            if (s < smax)
            {
				auto invN0 = ((Real)1)/(d0*s - (Real)1);
				auto invN1 = ((Real)1)/(d1*s - (Real)1);
				auto invN0Cub = invN0*invN0*invN0;
				auto invN1Cub = invN1*invN1*invN1;
                df = ((Real)-2)*(d0*d0c0*invN0Cub + d1*d1c1*invN1Cub);
                if (df < Real{})
                {
                    smin = s;
                    dfmin = df;
                }
                else if (df > Real{})
                {
                    smax = s;
                    dfmax = df;
                }
                else
                {
                    break;
                }
            }
            else
            {
                df = dfmax;
                break;
            }
        }
        else
        {
            df = dfmin;
            break;
        }
    }
}

template <typename Real>
void Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>
	::GetRoots (Real d0, Real d1, Real c0, Real c1, int& numRoots, Real* roots)
{
    // f(s) = d0*c0/(d0*s-1)^2 + d1*c1/(d1*s-1)^2 - 1
    // with d0 > d1

    numRoots = 0;

	auto epsilon = Real{0.001};
	auto multiplier0 = Math::Sqrt(((Real)2)/((Real)1 - epsilon));
	auto multiplier1 = Math::Sqrt(((Real)1)/((Real)1 + epsilon));
	auto d0c0 = d0*c0;
	auto d1c1 = d1*c1;
	auto sqrtd0c0 = Math::Sqrt(d0c0);
	auto sqrtd1c1 = Math::Sqrt(d1c1);
	auto invD0 = ((Real)1)/d0;
	auto invD1 = ((Real)1)/d1;
    Real temp0, temp1, smin, smax, s, fmin, fmax, f;
    Real invN0, invN1, invN0Sqr, invN1Sqr;

    // Compute root in (-infinity,1/d0).
    temp0 = ((Real)1 - multiplier0*sqrtd0c0)*invD0;
    temp1 = ((Real)1 - multiplier0*sqrtd1c1)*invD1;
    smin = (temp0 < temp1 ? temp0 : temp1);
    invN0 = ((Real)1)/(d0*smin - (Real)1);
    invN1 = ((Real)1)/(d1*smin - (Real)1);
    invN0Sqr = invN0*invN0;
    invN1Sqr = invN1*invN1;
    fmin = d0c0*invN0Sqr + d1c1*invN1Sqr - (Real)1;
    MATHEMATICS_ASSERTION_0(fmin < Real{}, "Unexpected condition.\n");
    smax = ((Real)1 - multiplier1*sqrtd0c0)*invD0;
    invN0 = ((Real)1)/(d0*smax - (Real)1);
    invN1 = ((Real)1)/(d1*smax - (Real)1);
    invN0Sqr = invN0*invN0;
    invN1Sqr = invN1*invN1;
    fmax = d0c0*invN0Sqr + d1c1*invN1Sqr - (Real)1;
    MATHEMATICS_ASSERTION_0(fmax > Real{}, "Unexpected condition.\n");
    BisectF(d0, d1, d0c0, d1c1, smin, fmin, smax, fmax, s, f);
    roots[numRoots++] = s;

    // Compute roots (if any) in (1/d0,1/d1).
    Real smid, fmid, df;
    BisectDF(d0, d1, d0c0, d1c1, invD0, -Math::sm_MaxReal, invD1, Math::sm_MaxReal, smid, df);
    invN0 = ((Real)1)/(d0*smid - (Real)1);
    invN1 = ((Real)1)/(d1*smid - (Real)1);
    invN0Sqr = invN0*invN0;
    invN1Sqr = invN1*invN1;
    fmid = d0c0*invN0Sqr + d1c1*invN1Sqr - (Real)1;
    if (fmid < Real{})
    {
        BisectF(d0, d1, d0c0, d1c1, invD0, Math::sm_MaxReal, smid, fmid, s, f);
        roots[numRoots++] = s;
        BisectF(d0, d1, d0c0, d1c1, smid, fmid, invD1, Math::sm_MaxReal,  s, f);
        roots[numRoots++] = s;
    }

    // Compute root in (1/d1,+infinity).
    temp0 = ((Real)1 + multiplier0*sqrtd0c0)*invD0;
    temp1 = ((Real)1 + multiplier0*sqrtd1c1)*invD1;
    smax = (temp0 > temp1 ? temp0 : temp1);
    invN0 = ((Real)1)/(d0*smax - (Real)1);
    invN1 = ((Real)1)/(d1*smax - (Real)1);
    invN0Sqr = invN0*invN0;
    invN1Sqr = invN1*invN1;
    fmax = d0c0*invN0Sqr + d1c1*invN1Sqr - (Real)1;
    MATHEMATICS_ASSERTION_0(fmax < Real{}, "Unexpected condition.\n");
    smin = ((Real)1 + multiplier1*sqrtd1c1)*invD1;
    invN0 = ((Real)1)/(d0*smin - (Real)1);
    invN1 = ((Real)1)/(d1*smin - (Real)1);
    invN0Sqr = invN0*invN0;
    invN1Sqr = invN1*invN1;
    fmin = d0c0*invN0Sqr + d1c1*invN1Sqr - (Real)1;
    MATHEMATICS_ASSERTION_0(fmin > Real{}, "Unexpected condition.\n");
    BisectF(d0, d1, d0c0, d1c1, smin, fmin, smax, fmax, s, f);
    roots[numRoots++] = s;
}

template <typename Real>
void Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>
	::GetRoots (Real d0, Real c0,int& numRoots, Real* roots)
{
    // f(s) = d0*c0/(d0*s-1)^2 - 1
	auto temp = Math::Sqrt(d0*c0);
	auto inv = ((Real)1)/d0;
    numRoots = 2;
    roots[0] = ((Real)1 - temp)*inv;
    roots[1] = ((Real)1 + temp)*inv;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_DETAIL_H