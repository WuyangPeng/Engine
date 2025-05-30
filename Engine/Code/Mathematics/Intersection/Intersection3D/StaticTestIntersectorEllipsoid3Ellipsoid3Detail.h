///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:22)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_DETAIL_H

#include "StaticTestIntersectorEllipsoid3Ellipsoid3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::StaticTestIntersectorEllipsoid3Ellipsoid3(const Ellipsoid3Type& ellipsoid0, const Ellipsoid3Type& ellipsoid1, const Real epsilon)
    : ParentType{ epsilon }, ellipsoid0{ ellipsoid0 }, ellipsoid1{ ellipsoid1 }, classification{ Classification::EllipsoidsSeparated }
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
Mathematics::Ellipsoid3<Real> Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::GetEllipsoid0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ellipsoid0;
}

template <typename Real>
Mathematics::Ellipsoid3<Real> Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::GetEllipsoid1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ellipsoid1;
}

template <typename Real>
typename Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::Classification Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::GetClassification() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return classification;
}

template <typename Real>
void Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::Test()
{
    // 获取椭球体0的参数。
    const auto center0 = ellipsoid0.GetCenter();
    const Matrix3<Real> rotationMatrix0{ ellipsoid0.GetAxis0(), ellipsoid0.GetAxis1(), ellipsoid0.GetAxis2(), MatrixMajorFlags::Row };
    const Matrix3<Real> extentMatrix0{ (MathType::GetValue(1)) / (ellipsoid0.GetExtent0() * ellipsoid0.GetExtent0()),
                                       (MathType::GetValue(1)) / (ellipsoid0.GetExtent1() * ellipsoid0.GetExtent1()),
                                       (MathType::GetValue(1)) / (ellipsoid0.GetExtent2() * ellipsoid0.GetExtent2()) };

    // 获取椭球体1的参数。
    const auto center1 = ellipsoid1.GetCenter();
    const Matrix3<Real> rotationMatrix1{ ellipsoid1.GetAxis0(), ellipsoid1.GetAxis1(), ellipsoid1.GetAxis2(), MatrixMajorFlags::Row };
    const Matrix3<Real> extentMatrix1{ (MathType::GetValue(1)) / (ellipsoid1.GetExtent0() * ellipsoid1.GetExtent0()),
                                       (MathType::GetValue(1)) / (ellipsoid1.GetExtent1() * ellipsoid1.GetExtent1()),
                                       (MathType::GetValue(1)) / (ellipsoid1.GetExtent2() * ellipsoid1.GetExtent2()) };

    // 计算 K2.
    const Matrix3<Real> extent0NegHalf{ ellipsoid0.GetExtent0(), ellipsoid0.GetExtent1(), ellipsoid0.GetExtent2() };
    const Matrix3<Real> extent0Half{ (MathType::GetValue(1)) / ellipsoid0.GetExtent0(),
                                     (MathType::GetValue(1)) / ellipsoid0.GetExtent1(),
                                     (MathType::GetValue(1)) / ellipsoid0.GetExtent2() };
    const auto k2 = extent0Half * ((center1 - center0) * rotationMatrix0);

    // 计算 M2.
    const auto value0 = TransposeTimes(rotationMatrix1, rotationMatrix0 * extent0NegHalf);
    const auto m2 = TransposeTimes(value0, (extentMatrix1)*value0);

    // 因子 M2 = R*D*R^T.

    const auto matrix3EigenDecomposition = m2.EigenDecomposition();
    const auto rotatio = matrix3EigenDecomposition.GetRotation();
    auto diagonal = matrix3EigenDecomposition.GetDiagonal();

    // 计算 K = Real^T*K2.
    auto k = k2 * rotatio;

    // 变换后的椭球0为Z^T*Z = 1，而变换后的椭球1为(Z-K)^T*D*(Z-K) = 0。

    // 从变换的椭球1上的点的原点开始的最小和最大平方距离用于确定椭球是否相交，分隔或一个包含另一个。
    auto minSqrDistance = MathType::maxReal;
    auto maxSqrDistance = MathType::GetValue(0);

    if (Vector3ToolsType::Approximate(k, Vector3Type::GetZero()))
    {
        // 共同中心的特殊情况必须分开处理。 椭圆体不可能分开。
        for (auto i = 0; i < 3; ++i)
        {
            auto invDiagonal = (MathType::GetValue(1)) / diagonal[i][i];
            if (invDiagonal < minSqrDistance)
            {
                minSqrDistance = invDiagonal;
            }
            if (maxSqrDistance < invDiagonal)
            {
                maxSqrDistance = invDiagonal;
            }
        }

        if (maxSqrDistance < MathType::GetValue(1))
        {
            classification = Classification::Ellipsoid0ContainsEllipsoid1;
            return;
        }
        else if (MathType::GetValue(1) < minSqrDistance)
        {
            classification = Classification::Ellipsoid1ContainsEllipsoid0;
            return;
        }
        else
        {
            classification = Classification::EllipsoidsIntersecting;
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
    if (param.at(1).first < param.at(0).first)
    {
        if (param.at(2).first < param.at(1).first)
        {
            // d0 > d1 > d2
            for (auto i = 0; i < 3; ++i)
            {
                if (MathType::GetValue(0) < param.at(i).second)
                {
                    valid.emplace_back(param.at(i));
                }
            }
        }
        else
        {
            // d0 > d1 = d2
            if (MathType::GetValue(0) < param.at(0).second)
            {
                valid.emplace_back(param.at(0));
            }
            param.at(1).second += param.at(0).second;
            if (MathType::GetValue(0) < param.at(1).second)
            {
                valid.emplace_back(param.at(1));
            }
        }
    }
    else
    {
        if (param.at(2).first < param.at(1).first)
        {
            // d0 = d1 > d2
            param.at(0).second += param.at(1).second;
            if (MathType::GetValue(0) < param.at(0).second)
            {
                valid.emplace_back(param.at(0));
            }
            if (MathType::GetValue(0) < param.at(2).second)
            {
                valid.emplace_back(param.at(2));
            }
        }
        else
        {
            // d0 = d1 = d2
            param.at(0).second += param.at(1).second + param.at(2).second;
            if (MathType::GetValue(0) < param.at(0).second)
            {
                valid.emplace_back(param.at(0));
            }
        }
    }

    const auto numValid = valid.size();

    RootsType roots{};
    if (numValid == 3)
    {
        roots = GetRoots(valid.at(0).first, valid.at(1).first, valid.at(2).first, valid.at(0).second, valid.at(1).second, valid.at(2).second);
    }
    else if (numValid == 2)
    {
        roots = GetRoots(valid.at(0).first, valid.at(1).first, valid.at(0).second, valid.at(1).second);
    }
    else if (numValid == 1)
    {
        roots = GetRoots(valid.at(0).first, valid.at(0).second);
    }
    else
    {
        // numValid不能为零，因为我们已经处理了情况K = 0
        MATHEMATICS_ASSERTION_0(false, "意外状况.\n");
        classification = Classification::EllipsoidsIntersecting;
        return;
    }

    for (auto i = 0u; i < roots.size(); ++i)
    {
        auto s = roots.at(i);
        auto p0 = d0 * k[0] * s / (d0 * s - MathType::GetValue(1));
        auto p1 = d1 * k[1] * s / (d1 * s - MathType::GetValue(1));
        auto p2 = d2 * k[2] * s / (d2 * s - MathType::GetValue(1));
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

    if (maxSqrDistance < MathType::GetValue(1))
    {
        classification = Classification::Ellipsoid0ContainsEllipsoid1;
        return;
    }

    if (minSqrDistance > MathType::GetValue(1))
    {
        if (d0 * c0 + d1 * c1 + d2 * c2 > MathType::GetValue(1))
        {
            classification = Classification::EllipsoidsSeparated;
            return;
        }
        else
        {
            classification = Classification::Ellipsoid1ContainsEllipsoid0;
            return;
        }
    }

    classification = Classification::EllipsoidsIntersecting;
}

template <typename Real>
typename Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::ResultType Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::BisectF(Real d0, Real d1, Real d2, Real d0c0, Real d1c1, Real d2c2, Real smin, Real fmin, Real smax, Real fmax) noexcept
{
    ResultType resultType{};

    const auto increasing = (fmin < MathType::GetValue(0));

    constexpr auto maxIterations = 256;
    for (auto i = 0; i < maxIterations; ++i)
    {
        resultType.s = MathType::GetRational(1, 2) * (smin + smax);
        if (smin < resultType.s)
        {
            if (resultType.s < smax)
            {
                auto invN0 = (MathType::GetValue(1)) / (d0 * resultType.s - MathType::GetValue(1));
                auto invN1 = (MathType::GetValue(1)) / (d1 * resultType.s - MathType::GetValue(1));
                auto invN2 = (MathType::GetValue(1)) / (d2 * resultType.s - MathType::GetValue(1));
                auto invN0Sqr = invN0 * invN0;
                auto invN1Sqr = invN1 * invN1;
                auto invN2Sqr = invN2 * invN2;
                resultType.f = d0c0 * invN0Sqr + d1c1 * invN1Sqr + d2c2 * invN2Sqr - MathType::GetValue(1);
                if (resultType.f < MathType::GetValue(0))
                {
                    if (increasing)
                    {
                        smin = resultType.s;
                        fmin = resultType.f;
                    }
                    else
                    {
                        smax = resultType.s;
                        fmax = resultType.f;
                    }
                }
                else if (MathType::GetValue(0) < resultType.f)
                {
                    if (increasing)
                    {
                        smax = resultType.s;
                        fmax = resultType.f;
                    }
                    else
                    {
                        smin = resultType.s;
                        fmin = resultType.f;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                resultType.f = fmax;
                break;
            }
        }
        else
        {
            resultType.f = fmin;
            break;
        }
    }

    return resultType;
}

template <typename Real>
typename Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::ResultType Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::BisectDF(Real d0, Real d1, Real d2, Real d0c0, Real d1c1, Real d2c2, Real smin, Real dfmin, Real smax, Real dfmax) noexcept
{
    ResultType resultType{};

    constexpr auto maxIterations = 256;
    for (auto i = 0; i < maxIterations; ++i)
    {
        resultType.s = MathType::GetRational(1, 2) * (smin + smax);
        if (smin < resultType.s)
        {
            if (resultType.s < smax)
            {
                auto invN0 = (MathType::GetValue(1)) / (d0 * resultType.s - MathType::GetValue(1));
                auto invN1 = (MathType::GetValue(1)) / (d1 * resultType.s - MathType::GetValue(1));
                auto invN2 = (MathType::GetValue(1)) / (d2 * resultType.s - MathType::GetValue(1));
                auto invN0Cub = invN0 * invN0 * invN0;
                auto invN1Cub = invN1 * invN1 * invN1;
                auto invN2Cub = invN2 * invN2 * invN2;
                resultType.f = (MathType::GetValue(-2)) * (d0 * d0c0 * invN0Cub + d1 * d1c1 * invN1Cub + d2 * d2c2 * invN2Cub);
                if (resultType.f < MathType::GetValue(0))
                {
                    smin = resultType.s;
                    dfmin = resultType.f;
                }
                else if (MathType::GetValue(0) < resultType.f)
                {
                    smax = resultType.s;
                    dfmax = resultType.f;
                }
                else
                {
                    break;
                }
            }
            else
            {
                resultType.f = dfmax;
                break;
            }
        }
        else
        {
            resultType.f = dfmin;
            break;
        }
    }

    return resultType;
}

template <typename Real>
typename Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::RootsType Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::GetRoots(Real d0, Real d1, Real d2, Real c0, Real c1, Real c2)
{
    RootsType roots{};

    // f(s) = d0*c0/(d0*s-1)^2 + d1*c1/(d1*s-1)^2 + d2*c2/(d2*s-1)^2 - 1
    // 其中 d0 > d1 > d2

    // f(s) = d0*c0/(d0*s-1)^2 + d1*c1/(d1*s-1)^2 - 1
    // 其中 d0 > d1
    auto epsilon = static_cast<Real>(0.001);

    auto multiplier0 = MathType::Sqrt(MathType::GetValue(3)) / (MathType::GetValue(1) - epsilon);
    auto multiplier1 = MathType::Sqrt(MathType::GetValue(1)) / (MathType::GetValue(1) + epsilon);
    auto d0c0 = d0 * c0;
    auto d1c1 = d1 * c1;
    auto d2c2 = d2 * c2;
    auto sqrtd0c0 = MathType::Sqrt(d0c0);
    auto sqrtd1c1 = MathType::Sqrt(d1c1);
    auto sqrtd2c2 = MathType::Sqrt(d2c2);
    auto invD0 = (MathType::GetValue(1)) / d0;
    auto invD1 = (MathType::GetValue(1)) / d1;
    auto invD2 = (MathType::GetValue(1)) / d2;

    // 计算（-infinity,1/d0）中的根（如果有）。
    auto temp0 = (MathType::GetValue(1) - multiplier0 * sqrtd0c0) * invD0;
    auto temp1 = (MathType::GetValue(1) - multiplier0 * sqrtd1c1) * invD1;
    auto temp2 = (MathType::GetValue(1) - multiplier0 * sqrtd2c2) * invD2;
    auto sMin = (temp0 < temp1 ? temp0 : temp1);
    sMin = (temp2 < sMin ? temp2 : sMin);
    auto invN0 = (MathType::GetValue(1)) / (d0 * sMin - MathType::GetValue(1));
    auto invN1 = (MathType::GetValue(1)) / (d1 * sMin - MathType::GetValue(1));
    auto invN2 = (MathType::GetValue(1)) / (d2 * sMin - MathType::GetValue(1));
    auto invN0Sqr = invN0 * invN0;
    auto invN1Sqr = invN1 * invN1;
    auto invN2Sqr = invN2 * invN2;
    auto fMin = d0c0 * invN0Sqr + d1c1 * invN1Sqr + d2c2 * invN2Sqr - MathType::GetValue(1);
    MATHEMATICS_ASSERTION_0(fMin < MathType::GetValue(0), "意外情况.\n");

    auto sMax = (MathType::GetValue(1) - multiplier1 * sqrtd0c0) * invD0;
    invN0 = (MathType::GetValue(1)) / (d0 * sMax - MathType::GetValue(1));
    invN1 = (MathType::GetValue(1)) / (d1 * sMax - MathType::GetValue(1));
    invN2 = (MathType::GetValue(1)) / (d2 * sMax - MathType::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    invN2Sqr = invN2 * invN2;
    auto fMax = d0c0 * invN0Sqr + d1c1 * invN1Sqr + d2c2 * invN2Sqr - MathType::GetValue(1);
    MATHEMATICS_ASSERTION_0(MathType::GetValue(0) < fMax, "意外情况.\n");

    auto result = BisectF(d0, d1, d2, d0c0, d1c1, d2c2, sMin, fMin, sMax, fMax);
    roots.emplace_back(result.s);

    // 计算根在 (1 / d0,1 / d1).

    result = BisectDF(d0, d1, d2, d0c0, d1c1, d2c2, invD0, -MathType::maxReal, invD1, MathType::maxReal);
    auto sMid = result.s;
    auto df = result.f;
    invN0 = (MathType::GetValue(1)) / (d0 * sMid - MathType::GetValue(1));
    invN1 = (MathType::GetValue(1)) / (d1 * sMid - MathType::GetValue(1));
    invN2 = (MathType::GetValue(1)) / (d2 * sMid - MathType::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    invN2Sqr = invN2 * invN2;
    auto fMid = d0c0 * invN0Sqr + d1c1 * invN1Sqr + d2c2 * invN2Sqr - MathType::GetValue(1);
    if (fMid < MathType::GetValue(0))
    {
        auto resultType = BisectF(d0, d1, d2, d0c0, d1c1, d2c2, invD0, MathType::maxReal, sMid, fMid);
        auto s = resultType.s;
        auto f = resultType.f;
        roots.emplace_back(s);
        resultType = BisectF(d0, d1, d2, d0c0, d1c1, d2c2, sMid, fMid, invD1, MathType::maxReal);
        s = resultType.s;
        f = resultType.f;
        roots.emplace_back(s);
    }

    // 计算根在 (1 / d1,1 / d2).
    result = BisectDF(d0, d1, d2, d0c0, d1c1, d2c2, invD1, -MathType::maxReal, invD2, MathType::maxReal);
    sMid = result.s;
    df = result.f;
    invN0 = (MathType::GetValue(1)) / (d0 * sMid - MathType::GetValue(1));
    invN1 = (MathType::GetValue(1)) / (d1 * sMid - MathType::GetValue(1));
    invN2 = (MathType::GetValue(1)) / (d2 * sMid - MathType::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    invN2Sqr = invN2 * invN2;
    fMid = d0c0 * invN0Sqr + d1c1 * invN1Sqr + d2c2 * invN2Sqr - MathType::GetValue(1);
    if (fMid < MathType::GetValue(0))
    {
        auto resultType = BisectF(d0, d1, d2, d0c0, d1c1, d2c2, invD1, MathType::maxReal, sMid, fMid);
        auto s = resultType.s;
        auto f = resultType.f;
        roots.emplace_back(s);
        resultType = BisectF(d0, d1, d2, d0c0, d1c1, d2c2, sMid, fMid, invD2, MathType::maxReal);
        s = resultType.s;
        f = resultType.f;
        roots.emplace_back(s);
    }

    // 计算根在 (1 / d2,+infinity).
    temp0 = (MathType::GetValue(1) + multiplier0 * sqrtd0c0) * invD0;
    temp1 = (MathType::GetValue(1) + multiplier0 * sqrtd1c1) * invD1;
    temp2 = (MathType::GetValue(1) + multiplier0 * sqrtd2c2) * invD2;
    sMax = (temp0 > temp1 ? temp0 : temp1);
    sMax = (temp2 > sMax ? temp2 : sMax);
    invN0 = (MathType::GetValue(1)) / (d0 * sMax - MathType::GetValue(1));
    invN1 = (MathType::GetValue(1)) / (d1 * sMax - MathType::GetValue(1));
    invN2 = (MathType::GetValue(1)) / (d2 * sMax - MathType::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    invN2Sqr = invN2 * invN2;
    fMax = d0c0 * invN0Sqr + d1c1 * invN1Sqr + d2c2 * invN2Sqr - MathType::GetValue(1);
    MATHEMATICS_ASSERTION_0(fMax < MathType::GetValue(0), "Unexpected condition.\n");
    sMin = (MathType::GetValue(1) + multiplier1 * sqrtd2c2) * invD2;
    invN0 = (MathType::GetValue(1)) / (d0 * sMin - MathType::GetValue(1));
    invN1 = (MathType::GetValue(1)) / (d1 * sMin - MathType::GetValue(1));
    invN2 = (MathType::GetValue(1)) / (d2 * sMin - MathType::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    invN2Sqr = invN2 * invN2;
    fMin = d0c0 * invN0Sqr + d1c1 * invN1Sqr + d2c2 * invN2Sqr - MathType::GetValue(1);
    MATHEMATICS_ASSERTION_0(fMin > MathType::GetValue(0), "Unexpected condition.\n");
    auto resultType = BisectF(d0, d1, d2, d0c0, d1c1, d2c2, sMin, fMin, sMax, fMax);
    roots.emplace_back(resultType.s);

    return roots;
}

template <typename Real>
typename Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::ResultType Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::BisectF(Real d0, Real d1, Real d0c0, Real d1c1, Real smin, Real fmin, Real smax, Real fmax) noexcept
{
    Real s{};
    Real f{};
    const auto increasing = (fmin < MathType::GetValue(0));

    constexpr auto maxIterations = 256;
    for (auto i = 0; i < maxIterations; ++i)
    {
        s = MathType::GetRational(1, 2) * (smin + smax);
        if (smin < s)
        {
            if (s < smax)
            {
                auto invN0 = (MathType::GetValue(1)) / (d0 * s - MathType::GetValue(1));
                auto invN1 = (MathType::GetValue(1)) / (d1 * s - MathType::GetValue(1));
                auto invN0Sqr = invN0 * invN0;
                auto invN1Sqr = invN1 * invN1;
                f = d0c0 * invN0Sqr + d1c1 * invN1Sqr - MathType::GetValue(1);
                if (f < MathType::GetValue(0))
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
                else if (f > MathType::GetValue(0))
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

    return ResultType{ s, f };
}

template <typename Real>
typename Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::ResultType Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::BisectDF(Real d0, Real d1, Real d0c0, Real d1c1, Real smin, Real dfmin, Real smax, Real dfmax) noexcept
{
    Real s{};
    Real df{};
    constexpr auto maxIterations = 256;
    for (auto i = 0; i < maxIterations; ++i)
    {
        s = MathType::GetRational(1, 2) * (smin + smax);
        if (smin < s)
        {
            if (s < smax)
            {
                auto invN0 = (MathType::GetValue(1)) / (d0 * s - MathType::GetValue(1));
                auto invN1 = (MathType::GetValue(1)) / (d1 * s - MathType::GetValue(1));
                auto invN0Cub = invN0 * invN0 * invN0;
                auto invN1Cub = invN1 * invN1 * invN1;
                df = (MathType::GetValue(-2)) * (d0 * d0c0 * invN0Cub + d1 * d1c1 * invN1Cub);
                if (df < MathType::GetValue(0))
                {
                    smin = s;
                    dfmin = df;
                }
                else if (df > MathType::GetValue(0))
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
    return ResultType{ s, df };
}

template <typename Real>
typename Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::RootsType Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::GetRoots(Real d0, Real d1, Real c0, Real c1)
{
    RootsType roots{};

    // f(s) = d0*c0/(d0*s-1)^2 + d1*c1/(d1*s-1)^2 - 1
    // 其中 d0 > d1

    auto epsilon = Real{ 0.001 };
    auto multiplier0 = MathType::Sqrt((MathType::GetValue(2)) / (MathType::GetValue(1) - epsilon));
    auto multiplier1 = MathType::Sqrt((MathType::GetValue(1)) / (MathType::GetValue(1) + epsilon));
    auto d0c0 = d0 * c0;
    auto d1c1 = d1 * c1;
    auto sqrtd0c0 = MathType::Sqrt(d0c0);
    auto sqrtd1c1 = MathType::Sqrt(d1c1);
    auto invD0 = (MathType::GetValue(1)) / d0;
    auto invD1 = (MathType::GetValue(1)) / d1;

    // 计算根在 (-infinity,1 / d0).
    auto temp0 = (MathType::GetValue(1) - multiplier0 * sqrtd0c0) * invD0;
    auto temp1 = (MathType::GetValue(1) - multiplier0 * sqrtd1c1) * invD1;
    auto sMin = (temp0 < temp1 ? temp0 : temp1);
    auto invN0 = (MathType::GetValue(1)) / (d0 * sMin - MathType::GetValue(1));
    auto invN1 = (MathType::GetValue(1)) / (d1 * sMin - MathType::GetValue(1));
    auto invN0Sqr = invN0 * invN0;
    auto invN1Sqr = invN1 * invN1;
    auto fMin = d0c0 * invN0Sqr + d1c1 * invN1Sqr - MathType::GetValue(1);
    MATHEMATICS_ASSERTION_0(fMin < MathType::GetValue(0), "Unexpected condition.\n");
    auto sMax = (MathType::GetValue(1) - multiplier1 * sqrtd0c0) * invD0;
    invN0 = (MathType::GetValue(1)) / (d0 * sMax - MathType::GetValue(1));
    invN1 = (MathType::GetValue(1)) / (d1 * sMax - MathType::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    auto fMax = d0c0 * invN0Sqr + d1c1 * invN1Sqr - MathType::GetValue(1);
    MATHEMATICS_ASSERTION_0(fMax > MathType::GetValue(0), "Unexpected condition.\n");
    auto result = BisectF(d0, d1, d0c0, d1c1, sMin, fMin, sMax, fMax);
    auto s = result.s;
    auto f = result.f;
    roots.emplace_back(s);

    // 计算根在 (1 / d0,1 / d1).

    result = BisectDF(d0, d1, d0c0, d1c1, invD0, -MathType::maxReal, invD1, MathType::maxReal);
    auto sMid = result.s;

    invN0 = (MathType::GetValue(1)) / (d0 * sMid - MathType::GetValue(1));
    invN1 = (MathType::GetValue(1)) / (d1 * sMid - MathType::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    auto fMid = d0c0 * invN0Sqr + d1c1 * invN1Sqr - MathType::GetValue(1);
    if (fMid < MathType::GetValue(0))
    {
        result = BisectF(d0, d1, d0c0, d1c1, invD0, MathType::maxReal, sMid, fMid);
        s = result.s;
        f = result.f;
        roots.emplace_back(s);
        result = BisectF(d0, d1, d0c0, d1c1, sMid, fMid, invD1, MathType::maxReal);
        s = result.s;
        f = result.f;
        roots.emplace_back(s);
    }

    // 计算根在 (1 / d1,+infinity).
    temp0 = (MathType::GetValue(1) + multiplier0 * sqrtd0c0) * invD0;
    temp1 = (MathType::GetValue(1) + multiplier0 * sqrtd1c1) * invD1;
    sMax = (temp0 > temp1 ? temp0 : temp1);
    invN0 = (MathType::GetValue(1)) / (d0 * sMax - MathType::GetValue(1));
    invN1 = (MathType::GetValue(1)) / (d1 * sMax - MathType::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    fMax = d0c0 * invN0Sqr + d1c1 * invN1Sqr - MathType::GetValue(1);
    MATHEMATICS_ASSERTION_0(fMax < MathType::GetValue(0), "Unexpected condition.\n");
    sMin = (MathType::GetValue(1) + multiplier1 * sqrtd1c1) * invD1;
    invN0 = (MathType::GetValue(1)) / (d0 * sMin - MathType::GetValue(1));
    invN1 = (MathType::GetValue(1)) / (d1 * sMin - MathType::GetValue(1));
    invN0Sqr = invN0 * invN0;
    invN1Sqr = invN1 * invN1;
    fMin = d0c0 * invN0Sqr + d1c1 * invN1Sqr - MathType::GetValue(1);
    MATHEMATICS_ASSERTION_0(fMin > MathType::GetValue(0), "Unexpected condition.\n");
    result = BisectF(d0, d1, d0c0, d1c1, sMin, fMin, sMax, fMax);
    s = result.s;
    f = result.f;
    roots.emplace_back(s);

    return roots;
}

template <typename Real>
typename Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::RootsType Mathematics::StaticTestIntersectorEllipsoid3Ellipsoid3<Real>::GetRoots(Real d0, Real c0)
{
    RootsType roots{};

    // f(s) = d0 * c0/(d0 * s - 1)^2 - 1
    auto temp = MathType::Sqrt(d0 * c0);
    auto inv = (MathType::GetValue(1)) / d0;

    roots.emplace_back((MathType::GetValue(1) - temp) * inv);
    roots.emplace_back((MathType::GetValue(1) + temp) * inv);

    return roots;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_DETAIL_H