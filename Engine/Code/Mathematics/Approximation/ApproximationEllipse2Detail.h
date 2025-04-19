/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 16:08)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_ELLIPSE2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_ELLIPSE2_DETAIL_H

#include "ApproximationEllipse2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix/Matrix2x2Detail.h"
#include "Mathematics/Algebra/Matrix/MatrixDetail.h"
#include "Mathematics/Containment/ContOrientedBox2.h"
#include "Mathematics/NumericalAnalysis/RootsPolynomialDetail.h"
#include "Mathematics/NumericalAnalysis/SymmetricEigensolver2x2Detail.h"
#include "Mathematics/Primitives/OrientedBox.h"

#include <map>

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::ApproximationEllipse2<Real>::ApproximationEllipse2() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationEllipse2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::ApproximationEllipse2<Real>::operator()(const Vector2Container& points, int numIterations, bool useEllipseForInitialGuess, Ellipse2& ellipse)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Vector2 c{};
    Matrix2x2 m{};
    if (useEllipseForInitialGuess)
    {
        c = ellipse.GetCenter();
        for (auto i = 0; i < 2; ++i)
        {
            const auto product = OuterProduct(ellipse.GetAxis(i), ellipse.GetAxis(i));
            m += product / (ellipse.GetExtent(i) * ellipse.GetExtent(i));
        }
    }
    else
    {
        Algebra::OrientedBox2<Real> box{};
        std::ignore = ContOrientedBox2<Real>::GetContainer(points, box);
        c = box.GetCenter();
        for (auto i = 0; i < 2; ++i)
        {
            const auto product = OuterProduct(box.GetAxis(i), box.GetAxis(i));
            m += product / (box.GetExtent(i) * box.GetExtent(i));
        }
    }

    auto error = ErrorFunction(points, c, m);
    for (auto i = 0; i < numIterations; ++i)
    {
        error = UpdateMatrix(points, c, m);
        error = UpdateCenter(points, m, c);
    }

    /// 提取椭圆轴和范围。
    const SymmetricEigensolver2x2<Real> solver{};
    std::array<Real, 2> eval{};
    std::array<std::array<Real, 2>, 2> evec{};
    solver(m(0, 0), m(0, 1), m(1, 1), +1, eval, evec);

    ellipse.SetCenter(c);
    for (auto i = 0; i < 2; ++i)
    {
        ellipse.SetAxis(i, { evec.at(i).at(0), evec.at(i).at(1) });
        ellipse.SetExtent(i, MathType::GetValue(1) / std::sqrt(eval.at(i)));
    }

    return error;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::ApproximationEllipse2<Real>::UpdateCenter(const Vector2Container& points, const Matrix2x2& m, Vector2& c)
{
    constexpr Real zero = MathType::GetValue(0);
    constexpr Real one = MathType::GetValue(1);
    constexpr Real two = MathType::GetValue(2);
    constexpr Real three = MathType::GetValue(3);
    constexpr Real four = MathType::GetValue(4);
    constexpr Real epsilon = MathType::GetValue(1e-06);

    Vector2Container mDelta(points.size());
    std::vector<Real> a(points.size());
    auto invQuantity = one / boost::numeric_cast<Real>(points.size());
    Vector2 negDfDc{};
    auto aMean = zero;
    auto aaMean = zero;
    for (auto i = 0u; i < points.size(); ++i)
    {
        const auto delta = points.at(i) - c;
        mDelta.at(i) = m * delta;
        a.at(i) = Dot(delta, mDelta.at(i)) - one;
        aMean += a.at(i);
        aaMean += a.at(i) * a.at(i);
        negDfDc += a.at(i) * mDelta.at(i);
    }
    aMean *= invQuantity;
    aaMean *= invQuantity;
    if (Normalize(negDfDc) < epsilon)
    {
        return aaMean;
    }

    auto bMean = zero;
    auto abMean = zero;
    auto bbMean = zero;
    auto c0 = Dot(negDfDc, m * negDfDc);
    for (auto i = 0u; i < points.size(); ++i)
    {
        auto b = Dot(negDfDc, mDelta.at(i));
        bMean += b;
        abMean += a.at(i) * b;
        bbMean += b * b;
    }
    bMean *= invQuantity;
    abMean *= invQuantity;
    bbMean *= invQuantity;

    /// 计算四次多项式q(t)的系数，该系数表示梯度下降最小化中给定线上的误差函数。
    std::array<Real, 5> q{ aaMean, -four * abMean, four * bbMean + two * c0 * aMean, -four * c0 * bMean, c0 * c0 };

    /// 计算q'(t)的系数。
    std::array<Real, 4> dq{ q.at(1), two * q.at(2), three * q.at(3), four * q.at(4) };

    /// 计算q'(t)的根。
    std::map<Real, int> rmMap{};
    RootsPolynomial<Real>::SolveCubic(dq.at(0), dq.at(1), dq.at(2), dq.at(3), rmMap);

    /// 选择沿着梯度下降线通向最小值的根，并将中心更新到该点。
    auto minError = aaMean;
    auto minRoot = zero;
    for (const auto& rm : rmMap)
    {
        auto root = rm.first;
        if (root > zero)
        {
            auto error = q.at(0) + root * (q.at(1) + root * (q.at(2) + root * (q.at(3) + root * q.at(4))));
            if (error < minError)
            {
                minError = error;
                minRoot = root;
            }
        }
    }

    if (minRoot > zero)
    {
        c += minRoot * negDfDc;
        return minError;
    }
    return aaMean;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::ApproximationEllipse2<Real>::UpdateMatrix(const Vector2Container& points, const Vector2& c, Matrix2x2& m)
{
    constexpr Real zero = MathType::GetValue(0);
    constexpr Real one = MathType::GetValue(1);
    constexpr Real two = MathType::GetValue(2);
    constexpr Real epsilon = MathType::GetValue(1e-06);

    Vector2Container delta(points.size());
    std::vector<Real> a(points.size());
    auto invQuantity = one / boost::numeric_cast<Real>(points.size());
    /// 零矩阵，对称
    Matrix2x2 negDfDm{};

    auto aaMean = zero;
    for (auto i = 0u; i < points.size(); ++i)
    {
        delta.at(i) = points.at(i) - c;
        a.at(i) = Dot(delta.at(i), m * delta.at(i)) - one;
        auto twoA = two * a.at(i);
        negDfDm(0, 0) -= a.at(i) * delta.at(i)[0] * delta.at(i)[0];
        negDfDm(0, 1) -= twoA * delta.at(i)[0] * delta.at(i)[1];
        negDfDm(1, 1) -= a.at(i) * delta.at(i)[1] * delta.at(i)[1];
        aaMean += a.at(i) * a.at(i);
    }
    aaMean *= invQuantity;

    /// 将矩阵标准化，就好像它是一个数字向量一样。
    const auto length = std::sqrt(negDfDm(0, 0) * negDfDm(0, 0) +
                                  negDfDm(0, 1) * negDfDm(0, 1) +
                                  negDfDm(1, 1) * negDfDm(1, 1));
    if (length < epsilon)
    {
        return aaMean;
    }
    auto invLength = one / length;
    negDfDm(0, 0) *= invLength;
    negDfDm(0, 1) *= invLength;
    negDfDm(1, 1) *= invLength;

    /// 填充下三角部分，因为negGradM是对称矩阵。
    negDfDm(1, 0) = negDfDm(0, 1);

    auto abMean = zero, bbMean = zero;
    for (auto i = 0u; i < points.size(); ++i)
    {
        auto b = Dot(delta.at(i), negDfDm * delta.at(i));
        abMean += a.at(i) * b;
        bbMean += b * b;
    }
    abMean *= invQuantity;
    bbMean *= invQuantity;

    /// 计算表示梯度下降最小化中给定线上的误差函数的二次多项式 q(t)的系数。
    std::array<Real, 3> q{ aaMean, two * abMean, bbMean };

    /// 计算q'(t)的系数。
    std::array<Real, 2> dq{ q.at(1), two * q.at(2) };

    /// 计算根，只要它是正的，并且M + root * negGradM是正定矩阵。
    auto root = -dq.at(0) / dq.at(1);
    if (root > zero)
    {
        /// 使用Sylvester的标准来检验正定性。
        /// for(;;) 循环终止于浮点运算，但不终止于有理(BSRational<UInteger>) 运算。
        /// 限制迭代次数，使循环在有理算术时终止，但在浮点算术时出现'return' 。
        for (auto k = 0u; k < 2048; ++k)
        {
            auto nextM = m + root * negDfDm;
            if (nextM(0, 0) > zero)
            {
                auto det = Determinant(nextM);
                if (det > zero)
                {
                    m = nextM;
                    auto minError = q.at(0) + root * (q.at(1) + root * q.at(2));
                    return minError;
                }
            }
            root *= MathType::GetRational(1, 2);
        }
    }
    return aaMean;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::ApproximationEllipse2<Real>::ErrorFunction(const Vector2Container& points, const Vector2& c, const Matrix2x2& m) const
{
    Real error{};
    for (const auto& p : points)
    {
        const auto delta = p - c;
        auto a = Dot(delta, m * delta) - MathType::GetValue(1);
        error += a * a;
    }
    error /= boost::numeric_cast<Real>(points.size());
    return error;
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_ELLIPSE2_DETAIL_H
