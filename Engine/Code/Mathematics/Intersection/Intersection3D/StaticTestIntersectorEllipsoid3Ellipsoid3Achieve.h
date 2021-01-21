///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 15:55)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_ACHIEVE_H

#include "StaticTestIntersectorEllipsoid3Ellipsoid3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::StaticTestIntersectorEllipsoid3Ellipsoid3(const Ellipsoid3& ellipsoid0, const Ellipsoid3& ellipsoid1, const Real epsilon)
    : ParentType{ epsilon }, m_Ellipsoid0{ ellipsoid0 }, m_Ellipsoid1{ ellipsoid1 }, m_Classification{ Classification::EllipsoidsSeparated }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::GetEllipsoid0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ellipsoid0;
}

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::GetEllipsoid1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ellipsoid1;
}

template <typename Real>
typename Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::Classification Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::GetClassification() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Classification;
}

template <typename Real>
void Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::Test()
{
    // 获取椭球体0的参数。
    auto center0 = m_Ellipsoid0.GetCenter();
    Matrix3<Real> rotationMatrix0{ m_Ellipsoid0.GetAxis0(), m_Ellipsoid0.GetAxis1(), m_Ellipsoid0.GetAxis2(), MatrixMajorFlags::Row };
    Matrix3<Real> extentMatrix0{ (Math::GetValue(1)) / (m_Ellipsoid0.GetExtent0() * m_Ellipsoid0.GetExtent0()),
                                 (Math::GetValue(1)) / (m_Ellipsoid0.GetExtent1() * m_Ellipsoid0.GetExtent1()),
                                 (Math::GetValue(1)) / (m_Ellipsoid0.GetExtent2() * m_Ellipsoid0.GetExtent2()) };

    // 获取椭球体1的参数。
    auto center1 = m_Ellipsoid1.GetCenter();
    Matrix3<Real> rotationMatrix1{ m_Ellipsoid1.GetAxis0(), m_Ellipsoid1.GetAxis1(), m_Ellipsoid1.GetAxis2(), MatrixMajorFlags::Row };
    Matrix3<Real> extentMatrix1{ (Math::GetValue(1)) / (m_Ellipsoid1.GetExtent0() * m_Ellipsoid1.GetExtent0()),
                                 (Math::GetValue(1)) / (m_Ellipsoid1.GetExtent1() * m_Ellipsoid1.GetExtent1()),
                                 (Math::GetValue(1)) / (m_Ellipsoid1.GetExtent2() * m_Ellipsoid1.GetExtent2()) };

    // 计算 K2.
    Matrix3<Real> extent0NegHalf{ m_Ellipsoid0.GetExtent0(), m_Ellipsoid0.GetExtent1(), m_Ellipsoid0.GetExtent2() };
    Matrix3<Real> extent0Half{ (Math::GetValue(1)) / m_Ellipsoid0.GetExtent0(), (Math::GetValue(1)) / m_Ellipsoid0.GetExtent1(), (Math::GetValue(1)) / m_Ellipsoid0.GetExtent2() };
    auto k2 = extent0Half * ((center1 - center0) * rotationMatrix0);

    // 计算 M2.
    auto value0 = TransposeTimes(rotationMatrix1, rotationMatrix0 * extent0NegHalf);
    auto m2 = TransposeTimes(value0, (extentMatrix1)*value0);

    // 因子 M2 = R*D*R^T.

    auto matrix3EigenDecomposition = m2.EigenDecomposition();
    auto rotatio = matrix3EigenDecomposition.GetRotation();
    auto diagonal = matrix3EigenDecomposition.GetDiagonal();

    // 计算 K = Real^T*K2.
    auto k = k2 * rotatio;

    // 变换后的椭球0为Z^T*Z = 1，而变换后的椭球1为(Z-K)^T*D*(Z-K) = 0。

    // 从变换的椭球1上的点的原点开始的最小和最大平方距离用于确定椭球是否相交，分隔或一个包含另一个。
    auto minSqrDistance = Math::sm_MaxReal;
    auto maxSqrDistance = Math::GetValue(0);

    if (Vector3DTools::Approximate(k, Vector3D::GetZero()))
    {
        // 共同中心的特殊情况必须分开处理。 椭圆体不可能分开。
        for (auto i = 0; i < 3; ++i)
        {
            auto invDiagonal = (Math::GetValue(1)) / diagonal[i][i];
            if (invDiagonal < minSqrDistance)
            {
                minSqrDistance = invDiagonal;
            }
            if (maxSqrDistance < invDiagonal)
            {
                maxSqrDistance = invDiagonal;
            }
        }

        if (maxSqrDistance < Math::GetValue(1))
        {
            m_Classification = Classification::Ellipsoid0ContainsEllipsoid1;
            return;
        }
        else if (Math::GetValue(1) < minSqrDistance)
        {
            m_Classification = Classification::Ellipsoid1ContainsEllipsoid0;
            return;
        }
        else
        {
            m_Classification = Classification::EllipsoidsIntersecting;
            return;
        }
    }

    /// 对于某些以函数f(s)为根的标量s0和s1，
    /// 最接近的点P0和最远的点P1是s0*D*(P0 - K) = P0和s1*D*(P1 - K) = P1的
    /// f(s) = d0*k0^2/(d0*s-1)^2+d1*k1^2/(d1*s-1)^2+d2*k2^2/(d2*s-1)^2-1
    /// 其中D = diagonal(d0,d1,d2) 和K = (k0,k1,k2)。
    auto d0 = diagonal[0][0];
    auto d1 = diagonal[1][1];
    auto d2 = diagonal[2][2];
    auto c0 = k[0] * k[0];
    auto c1 = k[1] * k[1];
    auto c2 = k[2] * k[2];

    // 对值进行排序，以使d0 >= d1 >= d2。 这使我们可以绑定f(s)的根，f(s)的根最多为6。
    using ParamType = std::pair<Real, Real>;
    using ParamContainer = std::vector<ParamType>;
    ParamContainer param{ std::make_pair(d0, c0), std::make_pair(d1, c1), std::make_pair(d2, c2) };

    std::sort(param.begin(), param.end(), std::greater<ParamType>());

    ParamContainer valid{};
    valid.reserve(3);
    if (param[1].first < param[0].first)
    {
        if (param[2].first < param[1].first)
        {
            // d0 > d1 > d2
            for (auto i = 0; i < 3; ++i)
            {
                if (Math::GetValue(0) < param[i].second)
                {
                    valid.emplace_back(param[i]);
                }
            }
        }
        else
        {
            // d0 > d1 = d2
            if (Math::GetValue(0) < param[0].second)
            {
                valid.emplace_back(param[0]);
            }
            param[1].second += param[0].second;
            if (Math::GetValue(0) < param[1].second)
            {
                valid.emplace_back(param[1]);
            }
        }
    }
    else
    {
        if (param[2].first < param[1].first)
        {
            // d0 = d1 > d2
            param[0].second += param[1].second;
            if (Math::GetValue(0) < param[0].second)
            {
                valid.emplace_back(param[0]);
            }
            if (Math::GetValue(0) < param[2].second)
            {
                valid.emplace_back(param[2]);
            }
        }
        else
        {
            // d0 = d1 = d2
            param[0].second += param[1].second + param[2].second;
            if (Math::GetValue(0) < param[0].second)
            {
                valid.emplace_back(param[0]);
            }
        }
    }

    auto numValid = valid.size();

    RootsType roots{};
    if (numValid == 3)
    {
        roots = GetRoots(valid[0].first, valid[1].first, valid[2].first, valid[0].second, valid[1].second, valid[2].second);
    }
    else if (numValid == 2)
    {
        roots = GetRoots(valid[0].first, valid[1].first, valid[0].second, valid[1].second);
    }
    else if (numValid == 1)
    {
        roots = GetRoots(valid[0].first, valid[0].second);
    }
    else
    {
        // numValid不能为零，因为我们已经处理了情况K = 0
        MATHEMATICS_ASSERTION_0(false, "意外状况.\n");
        m_Classification = Classification::EllipsoidsIntersecting;
        return;
    }

    for (auto i = 0u; i < roots.size(); ++i)
    {
        auto s = roots[i];
        auto p0 = d0 * k[0] * s / (d0 * s - Math::GetValue(1));
        auto p1 = d1 * k[1] * s / (d1 * s - Math::GetValue(1));
        auto p2 = d2 * k[2] * s / (d2 * s - Math::GetValue(1));
        auto sqrDistance = p0 * p0 + p1 * p1 + p2 * p2;
        if (sqrDistance < minSqrDistance)
        {
            minSqrDistance = sqrDistance;
        }
        if (maxSqrDistance < sqrDistance)
        {
            maxSqrDistance = sqrDistance;
        }
    }

    if (maxSqrDistance < Math::GetValue(1))
    {
        m_Classification = Classification::Ellipsoid0ContainsEllipsoid1;
        return;
    }

    if (minSqrDistance > Math::GetValue(1))
    {
        if (d0 * c0 + d1 * c1 + d2 * c2 > Math::GetValue(1))
        {
            m_Classification = Classification::EllipsoidsSeparated;
            return;
        }
        else
        {
            m_Classification = Classification::Ellipsoid1ContainsEllipsoid0;
            return;
        }
    }

    m_Classification = Classification::EllipsoidsIntersecting;
}

template <typename Real>
typename Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::ResultType Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::BisectF(Real d0, Real d1, Real d2, Real d0c0, Real d1c1, Real d2c2, Real smin, Real fmin, Real smax, Real fmax)
{
    ResultType resultType{};

    auto increasing = (fmin < Math::GetValue(0));

    constexpr auto maxIterations = 256;
    for (auto i = 0; i < maxIterations; ++i)
    {
        resultType.m_S = Math::GetRational(1, 2) * (smin + smax);
        if (smin < resultType.m_S)
        {
            if (resultType.m_S < smax)
            {
                auto invN0 = (Math::GetValue(1)) / (d0 * resultType.m_S - Math::GetValue(1));
                auto invN1 = (Math::GetValue(1)) / (d1 * resultType.m_S - Math::GetValue(1));
                auto invN2 = (Math::GetValue(1)) / (d2 * resultType.m_S - Math::GetValue(1));
                auto invN0Sqr = invN0 * invN0;
                auto invN1Sqr = invN1 * invN1;
                auto invN2Sqr = invN2 * invN2;
                resultType.m_F = d0c0 * invN0Sqr + d1c1 * invN1Sqr + d2c2 * invN2Sqr - Math::GetValue(1);
                if (resultType.m_F < Math::GetValue(0))
                {
                    if (increasing)
                    {
                        smin = resultType.m_S;
                        fmin = resultType.m_F;
                    }
                    else
                    {
                        smax = resultType.m_S;
                        fmax = resultType.m_F;
                    }
                }
                else if (Math::GetValue(0) < resultType.m_F)
                {
                    if (increasing)
                    {
                        smax = resultType.m_S;
                        fmax = resultType.m_F;
                    }
                    else
                    {
                        smin = resultType.m_S;
                        fmin = resultType.m_F;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                resultType.m_F = fmax;
                break;
            }
        }
        else
        {
            resultType.m_F = fmin;
            break;
        }
    }

    return resultType;
}

template <typename Real>
typename Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::ResultType Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::BisectDF(Real d0, Real d1, Real d2, Real d0c0, Real d1c1, Real d2c2, Real smin, Real dfmin, Real smax, Real dfmax)
{
    ResultType resultType{};

    constexpr auto maxIterations = 256;
    for (auto i = 0; i < maxIterations; ++i)
    {
        resultType.m_S = Math::GetRational(1, 2) * (smin + smax);
        if (smin < resultType.m_S)
        {
            if (resultType.m_S < smax)
            {
                auto invN0 = (Math::GetValue(1)) / (d0 * resultType.m_S - Math::GetValue(1));
                auto invN1 = (Math::GetValue(1)) / (d1 * resultType.m_S - Math::GetValue(1));
                auto invN2 = (Math::GetValue(1)) / (d2 * resultType.m_S - Math::GetValue(1));
                auto invN0Cub = invN0 * invN0 * invN0;
                auto invN1Cub = invN1 * invN1 * invN1;
                auto invN2Cub = invN2 * invN2 * invN2;
                resultType.m_F = ((Real)-2) * (d0 * d0c0 * invN0Cub + d1 * d1c1 * invN1Cub + d2 * d2c2 * invN2Cub);
                if (resultType.m_F < Math::GetValue(0))
                {
                    smin = resultType.m_S;
                    dfmin = resultType.m_F;
                }
                else if (Math::GetValue(0) < resultType.m_F)
                {
                    smax = resultType.m_S;
                    dfmax = resultType.m_F;
                }
                else
                {
                    break;
                }
            }
            else
            {
                resultType.m_F = dfmax;
                break;
            }
        }
        else
        {
            resultType.m_F = dfmin;
            break;
        }
    }

    return resultType;
}

/*
template <typename Real>
typename Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::RootsType Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::GetRoots(Real d0, Real d1, Real d2, Real c0, Real c1, Real c2)
{
    RootsType roots{};

    // f(s) = d0*c0/(d0*s-1)^2 + d1*c1/(d1*s-1)^2 + d2*c2/(d2*s-1)^2 - 1
    // 其中 d0 > d1 > d2

    // f(s) = d0*c0/(d0*s-1)^2 + d1*c1/(d1*s-1)^2 - 1
    // 其中 d0 > d1
    auto epsilon = static_cast<Real>(0.001);

    auto multiplier0 = Math::Sqrt(Math::GetValue(3)) / (Math::GetValue(1) - epsilon);
    auto multiplier1 = Math::Sqrt(Math::GetValue(1)) / (Math::GetValue(1) + epsilon);
    auto d0c0 = d0 * c0;
    auto d1c1 = d1 * c1;
    auto d2c2 = d2 * c2;
    auto sqrtd0c0 = Math::Sqrt(d0c0);
    auto sqrtd1c1 = Math::Sqrt(d1c1);
    auto sqrtd2c2 = Math::Sqrt(d2c2);
    auto invD0 = (Math::GetValue(1)) / d0;
    auto invD1 = (Math::GetValue(1)) / d1;
    auto invD2 = (Math::GetValue(1)) / d2;

    // 计算（-infinity,1/d0）中的根（如果有）。
    auto temp0 = (Math::GetValue(1) - multiplier0 * sqrtd0c0) * invD0;
    auto temp1 = (Math::GetValue(1) - multiplier0 * sqrtd1c1) * invD1;
    auto temp2 = (Math::GetValue(1) - multiplier0 * sqrtd2c2) * invD2;
    auto smin = (temp0 < temp1 ? temp0 : temp1);
    auto smin = (temp2 < smin ? temp2 : smin);
    auto invN0 = (Math::GetValue(1)) / (d0 * smin - Math::GetValue(1));
    auto invN1 = (Math::GetValue(1)) / (d1 * smin - Math::GetValue(1));
    auto invN2 = (Math::GetValue(1)) / (d2 * smin - Math::GetValue(1));
    auto invN0Sqr = invN0 * invN0;
    auto invN1Sqr = invN1 * invN1;
    auto invN2Sqr = invN2 * invN2;
    fmin = d0c0 * invN0Sqr + d1c1 * invN1Sqr + d2c2 * invN2Sqr - Math::GetValue(1);
    MATHEMATICS_ASSERTION_0(fmin < Math::GetValue(0), "意外情况.\n");

    auto smax = (Math::GetValue(1) - multiplier1 * sqrtd0c0) * invD0;
    auto invN0 = (Math::GetValue(1)) / (d0 * smax - Math::GetValue(1));
    auto invN1 = (Math::GetValue(1)) / (d1 * smax - Math::GetValue(1));
    auto invN2 = (Math::GetValue(1)) / (d2 * smax - Math::GetValue(1));
    auto invN0Sqr = invN0 * invN0;
    auto invN1Sqr = invN1 * invN1;
    auto invN2Sqr = invN2 * invN2;
    auto fmax = d0c0 * invN0Sqr + d1c1 * invN1Sqr + d2c2 * invN2Sqr - Math::GetValue(1);
    MATHEMATICS_ASSERTION_0(Math::GetValue(0) < fmax, "意外情况.\n");

    auto resultType = BisectF(d0, d1, d2, d0c0, d1c1, d2c2, smin, fmin, smax, fmax);
    roots.emplace_back(resultType.m_S);

    // Compute roots (if any) in (1/d0,1/d1).
    Real smid, fmid, df;
    BisectDF(d0, d1, d2, d0c0, d1c1, d2c2, invD0, -Math::sm_MaxReal, invD1, Math::sm_MaxReal, smid, df);
    invN0 = (Math::GetValue(1)) / (d0 * smid - Math::GetValue(1));
    invN1 = (Math::GetValue(1)) / (d1 * smid - Math::GetValue(1));
    invN2 = (Math::GetValue(1)) / (d2 * smid - Math::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    invN2Sqr = invN2 * invN2;
    fmid = d0c0 * invN0Sqr + d1c1 * invN1Sqr + d2c2 * invN2Sqr - Math::GetValue(1);
    if (fmid < Math<Real>::GetValue(0))
    {
        BisectF(d0, d1, d2, d0c0, d1c1, d2c2, invD0, Math::sm_MaxReal, smid, fmid, s, f);
        roots[numRoots++] = s;
        BisectF(d0, d1, d2, d0c0, d1c1, d2c2, smid, fmid, invD1, Math::sm_MaxReal, s, f);
        roots[numRoots++] = s;
    }

    // Compute roots (if any) in (1/d1,1/d2).
    BisectDF(d0, d1, d2, d0c0, d1c1, d2c2, invD1, -Math::sm_MaxReal, invD2, Math::sm_MaxReal, smid, df);
    invN0 = (Math::GetValue(1)) / (d0 * smid - Math::GetValue(1));
    invN1 = (Math::GetValue(1)) / (d1 * smid - Math::GetValue(1));
    invN2 = (Math::GetValue(1)) / (d2 * smid - Math::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    invN2Sqr = invN2 * invN2;
    fmid = d0c0 * invN0Sqr + d1c1 * invN1Sqr + d2c2 * invN2Sqr - Math::GetValue(1);
    if (fmid < Math<Real>::GetValue(0))
    {
        BisectF(d0, d1, d2, d0c0, d1c1, d2c2, invD1, Math::sm_MaxReal, smid, fmid, s, f);
        roots[numRoots++] = s;
        BisectF(d0, d1, d2, d0c0, d1c1, d2c2, smid, fmid, invD2, Math::sm_MaxReal, s, f);
        roots[numRoots++] = s;
    }

    // Compute root in (1/d2,+infinity).
    temp0 = (Math::GetValue(1) + multiplier0 * sqrtd0c0) * invD0;
    temp1 = (Math::GetValue(1) + multiplier0 * sqrtd1c1) * invD1;
    temp2 = (Math::GetValue(1) + multiplier0 * sqrtd2c2) * invD2;
    smax = (temp0 > temp1 ? temp0 : temp1);
    smax = (temp2 > smax ? temp2 : smax);
    invN0 = (Math::GetValue(1)) / (d0 * smax - Math::GetValue(1));
    invN1 = (Math::GetValue(1)) / (d1 * smax - Math::GetValue(1));
    invN2 = (Math::GetValue(1)) / (d2 * smax - Math::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    invN2Sqr = invN2 * invN2;
    fmax = d0c0 * invN0Sqr + d1c1 * invN1Sqr + d2c2 * invN2Sqr - Math::GetValue(1);
    MATHEMATICS_ASSERTION_0(fmax < Math<Real>::GetValue(0), "Unexpected condition.\n");
    smin = (Math::GetValue(1) + multiplier1 * sqrtd2c2) * invD2;
    invN0 = (Math::GetValue(1)) / (d0 * smin - Math::GetValue(1));
    invN1 = (Math::GetValue(1)) / (d1 * smin - Math::GetValue(1));
    invN2 = (Math::GetValue(1)) / (d2 * smin - Math::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    invN2Sqr = invN2 * invN2;
    fmin = d0c0 * invN0Sqr + d1c1 * invN1Sqr + d2c2 * invN2Sqr - Math::GetValue(1);
    MATHEMATICS_ASSERTION_0(fmin > Math<Real>::GetValue(0), "Unexpected condition.\n");
    BisectF(d0, d1, d2, d0c0, d1c1, d2c2, smin, fmin, smax, fmax, s, f);
    roots[numRoots++] = s;

    return roots;
}

template <typename Real>
void Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::BisectF(Real d0, Real d1, Real d0c0, Real d1c1, Real smin, Real fmin, Real smax, Real fmax, Real& s, Real& f)
{
    auto increasing = (fmin < Math<Real>::GetValue(0));

    constexpr auto maxIterations = 256;
    for (auto i = 0; i < maxIterations; ++i)
    {
        s = (Real{ 0.5 }) * (smin + smax);
        if (smin < s)
        {
            if (s < smax)
            {
                auto invN0 = (Math::GetValue(1)) / (d0 * s - Math::GetValue(1));
                auto invN1 = (Math::GetValue(1)) / (d1 * s - Math::GetValue(1));
                auto invN0Sqr = invN0 * invN0;
                auto invN1Sqr = invN1 * invN1;
                f = d0c0 * invN0Sqr + d1c1 * invN1Sqr - Math::GetValue(1);
                if (f < Math<Real>::GetValue(0))
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
                else if (f > Math<Real>::GetValue(0))
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
void Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::BisectDF(Real d0, Real d1, Real d0c0, Real d1c1, Real smin, Real dfmin, Real smax, Real dfmax, Real& s, Real& df)
{
    constexpr auto maxIterations = 256;
    for (auto i = 0; i < maxIterations; ++i)
    {
        s = (Real{ 0.5 }) * (smin + smax);
        if (smin < s)
        {
            if (s < smax)
            {
                auto invN0 = (Math::GetValue(1)) / (d0 * s - Math::GetValue(1));
                auto invN1 = (Math::GetValue(1)) / (d1 * s - Math::GetValue(1));
                auto invN0Cub = invN0 * invN0 * invN0;
                auto invN1Cub = invN1 * invN1 * invN1;
                df = ((Real)-2) * (d0 * d0c0 * invN0Cub + d1 * d1c1 * invN1Cub);
                if (df < Math<Real>::GetValue(0))
                {
                    smin = s;
                    dfmin = df;
                }
                else if (df > Math<Real>::GetValue(0))
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
void Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::GetRoots(Real d0, Real d1, Real c0, Real c1, int& numRoots, Real* roots)
{
    // f(s) = d0*c0/(d0*s-1)^2 + d1*c1/(d1*s-1)^2 - 1
    // with d0 > d1

    numRoots = 0;

    auto epsilon = Real{ 0.001 };
    auto multiplier0 = Math::Sqrt((Math::GetValue(2)) / (Math::GetValue(1) - epsilon));
    auto multiplier1 = Math::Sqrt((Math::GetValue(1)) / (Math::GetValue(1) + epsilon));
    auto d0c0 = d0 * c0;
    auto d1c1 = d1 * c1;
    auto sqrtd0c0 = Math::Sqrt(d0c0);
    auto sqrtd1c1 = Math::Sqrt(d1c1);
    auto invD0 = (Math::GetValue(1)) / d0;
    auto invD1 = (Math::GetValue(1)) / d1;
    Real temp0, temp1, smin, smax, s, fmin, fmax, f;
    Real invN0, invN1, invN0Sqr, invN1Sqr;

    // Compute root in (-infinity,1/d0).
    temp0 = (Math::GetValue(1) - multiplier0 * sqrtd0c0) * invD0;
    temp1 = (Math::GetValue(1) - multiplier0 * sqrtd1c1) * invD1;
    smin = (temp0 < temp1 ? temp0 : temp1);
    invN0 = (Math::GetValue(1)) / (d0 * smin - Math::GetValue(1));
    invN1 = (Math::GetValue(1)) / (d1 * smin - Math::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    fmin = d0c0 * invN0Sqr + d1c1 * invN1Sqr - Math::GetValue(1);
    MATHEMATICS_ASSERTION_0(fmin < Math<Real>::GetValue(0), "Unexpected condition.\n");
    smax = (Math::GetValue(1) - multiplier1 * sqrtd0c0) * invD0;
    invN0 = (Math::GetValue(1)) / (d0 * smax - Math::GetValue(1));
    invN1 = (Math::GetValue(1)) / (d1 * smax - Math::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    fmax = d0c0 * invN0Sqr + d1c1 * invN1Sqr - Math::GetValue(1);
    MATHEMATICS_ASSERTION_0(fmax > Math<Real>::GetValue(0), "Unexpected condition.\n");
    BisectF(d0, d1, d0c0, d1c1, smin, fmin, smax, fmax, s, f);
    roots[numRoots++] = s;

    // Compute roots (if any) in (1/d0,1/d1).
    Real smid, fmid, df;
    BisectDF(d0, d1, d0c0, d1c1, invD0, -Math::sm_MaxReal, invD1, Math::sm_MaxReal, smid, df);
    invN0 = (Math::GetValue(1)) / (d0 * smid - Math::GetValue(1));
    invN1 = (Math::GetValue(1)) / (d1 * smid - Math::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    fmid = d0c0 * invN0Sqr + d1c1 * invN1Sqr - Math::GetValue(1);
    if (fmid < Math<Real>::GetValue(0))
    {
        BisectF(d0, d1, d0c0, d1c1, invD0, Math::sm_MaxReal, smid, fmid, s, f);
        roots[numRoots++] = s;
        BisectF(d0, d1, d0c0, d1c1, smid, fmid, invD1, Math::sm_MaxReal, s, f);
        roots[numRoots++] = s;
    }

    // Compute root in (1/d1,+infinity).
    temp0 = (Math::GetValue(1) + multiplier0 * sqrtd0c0) * invD0;
    temp1 = (Math::GetValue(1) + multiplier0 * sqrtd1c1) * invD1;
    smax = (temp0 > temp1 ? temp0 : temp1);
    invN0 = (Math::GetValue(1)) / (d0 * smax - Math::GetValue(1));
    invN1 = (Math::GetValue(1)) / (d1 * smax - Math::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    fmax = d0c0 * invN0Sqr + d1c1 * invN1Sqr - Math::GetValue(1);
    MATHEMATICS_ASSERTION_0(fmax < Math<Real>::GetValue(0), "Unexpected condition.\n");
    smin = (Math::GetValue(1) + multiplier1 * sqrtd1c1) * invD1;
    invN0 = (Math::GetValue(1)) / (d0 * smin - Math::GetValue(1));
    invN1 = (Math::GetValue(1)) / (d1 * smin - Math::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    fmin = d0c0 * invN0Sqr + d1c1 * invN1Sqr - Math::GetValue(1);
    MATHEMATICS_ASSERTION_0(fmin > Math<Real>::GetValue(0), "Unexpected condition.\n");
    BisectF(d0, d1, d0c0, d1c1, smin, fmin, smax, fmax, s, f);
    roots[numRoots++] = s;
}

template <typename Real>
void Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::GetRoots(Real d0, Real c0, int& numRoots, Real* roots)
{
    // f(s) = d0*c0/(d0*s-1)^2 - 1
    auto temp = Math::Sqrt(d0 * c0);
    auto inv = (Math::GetValue(1)) / d0;
    numRoots = 2;
    roots[0] = (Math::GetValue(1) - temp) * inv;
    roots[1] = (Math::GetValue(1) + temp) * inv;
}
*/

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_ACHIEVE_H