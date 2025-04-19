/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 17:02)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_NI_SYMMETRIC_EIGENSOLVER_3X3_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_NI_SYMMETRIC_EIGENSOLVER_3X3_DETAIL_H

#include "NISymmetricEigensolver3x3.h"
#include "SortEigenstuff.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::NISymmetricEigensolver3x3<Real>::NISymmetricEigensolver3x3() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::NISymmetricEigensolver3x3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::NISymmetricEigensolver3x3<Real>::operator()(Real a00, Real a01, Real a02, Real a11, Real a12, Real a22, int sortType, std::array<Real, 3>& eval, std::array<std::array<Real, 3>, 3>& evec) const
{
    /// 通过分解出分量的最大绝对值来预处理矩阵。
    /// 这可以防止在计算特征值时出现浮点溢出。
    const auto max0 = std::max(std::fabs(a00), std::fabs(a01));
    const auto max1 = std::max(std::fabs(a02), std::fabs(a11));
    const auto max2 = std::max(std::fabs(a12), std::fabs(a22));
    const auto maxAbsElement = std::max(std::max(max0, max1), max2);
    if (MathType::Approximate(maxAbsElement, Real{}))
    {
        /// A 是零矩阵。
        eval.at(0) = Real{};
        eval.at(1) = Real{};
        eval.at(2) = Real{};
        evec.at(0) = { MathType::GetValue(1), Real{}, Real{} };
        evec.at(1) = { Real{}, MathType::GetValue(1), Real{} };
        evec.at(2) = { Real{}, Real{}, MathType::GetValue(1) };
        return;
    }

    Real invMaxAbsElement = MathType::GetValue(1) / maxAbsElement;
    a00 *= invMaxAbsElement;
    a01 *= invMaxAbsElement;
    a02 *= invMaxAbsElement;
    a11 *= invMaxAbsElement;
    a12 *= invMaxAbsElement;
    a22 *= invMaxAbsElement;

    const auto norm = a01 * a01 + a02 * a02 + a12 * a12;
    if (norm > Real{})
    {
        /// 计算A的特征值。

        /// 在前面提到的PDF中，B = (A - q*I)/p，
        /// 其中q = tr(A)/3，其中tr(A)是A的迹（A的对角线项的和），
        /// 其中p = sqrt(tr((A - q*I)^2)/6)。
        const auto q = (a00 + a11 + a22) / MathType::GetValue(3);

        /// 矩阵A - q*I由以下表示，其中b00、b11和b22是在这些注释之后计算的，
        ///   +-           -+
        ///   | b00 a01 a02 |
        ///   | a01 b11 a12 |
        ///   | a02 a12 b22 |
        ///   +-           -+
        const auto b00 = a00 - q;
        const auto b11 = a11 - q;
        const auto b22 = a22 - q;

        /// 是PDF中提到的变量p。
        const auto p = std::sqrt((b00 * b00 + b11 * b11 + b22 * b22 + norm * MathType::GetValue(2)) / MathType::GetValue(6));

        /// 我们需要det(B) = det((A - q*I)/p) = det(A - q*I)/p^3。
        /// 值det(A - q*I) 是使用A - q*I。
        /// 第一行的辅因子展开来计算的。辅因子是c00、c01和c02，
        /// 行列式是b00*c00 - a01*c01 + a02*c02。
        /// 然后通过用p^3进行除法来最终计算det（B）。
        const auto c00 = b11 * b22 - a12 * a12;
        const auto c01 = a01 * b22 - a12 * a02;
        const auto c02 = a01 * a12 - b11 * a02;
        const auto det = (b00 * c00 - a01 * c01 + a02 * c02) / (p * p * p);

        /// halfDet值是PDF中提到的(3*theta)。
        /// acos(z)函数需要|z| <= 1，但如果输入的大小大于1，则会无声地失败并返回NaN。
        /// 为了避免由于舍入误差引起的此问题，将halfDet值箝位为[-1,1]。
        auto halfDet = det * MathType::GetRational(1, 2);
        halfDet = std::min(std::max(halfDet, MathType::GetValue(-1)), MathType::GetValue(1));

        /// B的特征值排序为beta0 <= beta1 <= beta2。
        /// 选择两个ThirdsPi中的位数，以便无论是浮点还是双精度，浮点数都最接近理论上的2*pi/3。
        const auto angle = std::acos(halfDet) / MathType::GetValue(3);
        constexpr auto twoThirdsPi = MathType::GetValue(2.09439510239319549);
        auto beta2 = std::cos(angle) * MathType::GetValue(2);
        auto beta0 = std::cos(angle + twoThirdsPi) * MathType::GetValue(2);
        auto beta1 = -(beta0 + beta2);

        /// A的特征值被排序为alpha0 <= alpha1 <= alpha2。
        eval.at(0) = q + p * beta0;
        eval.at(1) = q + p * beta1;
        eval.at(2) = q + p * beta2;

        /// 计算特征向量，使集合{evec.at(0), evec.at(1), evec.at(2)} 是右手的和正交的。
        if (halfDet >= Real{})
        {
            ComputeEigenvector0(a00, a01, a02, a11, a12, a22, eval.at(2), evec.at(2));
            ComputeEigenvector1(a00, a01, a02, a11, a12, a22, evec.at(2), eval.at(1), evec.at(1));
            evec.at(0) = Cross(evec.at(1), evec.at(2));
        }
        else
        {
            ComputeEigenvector0(a00, a01, a02, a11, a12, a22, eval.at(0), evec.at(0));
            ComputeEigenvector1(a00, a01, a02, a11, a12, a22, evec.at(0), eval.at(1), evec.at(1));
            evec.at(2) = Cross(evec.at(0), evec.at(1));
        }
    }
    else
    {
        /// 矩阵是对角的。
        eval.at(0) = a00;
        eval.at(1) = a11;
        eval.at(2) = a22;
        evec.at(0) = { MathType::GetValue(1), Real{}, Real{} };
        evec.at(1) = { Real{}, MathType::GetValue(1), Real{} };
        evec.at(2) = { Real{}, Real{}, MathType::GetValue(1) };
    }

    /// 预处理缩放了矩阵A，矩阵A缩放了本征值。恢复缩放。
    eval.at(0) *= maxAbsElement;
    eval.at(1) *= maxAbsElement;
    eval.at(2) *= maxAbsElement;

    SortEigenstuff<Real>()(sortType, true, eval, evec);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
std::array<Real, 3> Mathematics::NISymmetricEigensolver3x3<Real>::Multiply(Real s, const std::array<Real, 3>& u)
{
    const std::array<Real, 3> product{ s * u.at(0), s * u.at(1), s * u.at(2) };

    return product;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
std::array<Real, 3> Mathematics::NISymmetricEigensolver3x3<Real>::Subtract(const std::array<Real, 3>& u, const std::array<Real, 3>& v)
{
    const std::array<Real, 3> difference{ u.at(0) - v.at(0), u.at(1) - v.at(1), u.at(2) - v.at(2) };

    return difference;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
std::array<Real, 3> Mathematics::NISymmetricEigensolver3x3<Real>::Divide(const std::array<Real, 3>& u, Real s)
{
    const auto invS = MathType::GetValue(1) / s;
    const std::array<Real, 3> division{ u.at(0) * invS, u.at(1) * invS, u.at(2) * invS };

    return division;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::NISymmetricEigensolver3x3<Real>::Dot(const std::array<Real, 3>& u, const std::array<Real, 3>& v)
{
    const auto dot = u.at(0) * v.at(0) + u.at(1) * v.at(1) + u.at(2) * v.at(2);

    return dot;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
std::array<Real, 3> Mathematics::NISymmetricEigensolver3x3<Real>::Cross(const std::array<Real, 3>& u, const std::array<Real, 3>& v)
{
    const std::array<Real, 3> cross{ u.at(1) * v.at(2) - u.at(2) * v.at(1),
                                     u.at(2) * v.at(0) - u.at(0) * v.at(2),
                                     u.at(0) * v.at(1) - u.at(1) * v.at(0) };
    return cross;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::NISymmetricEigensolver3x3<Real>::ComputeOrthogonalComplement(const std::array<Real, 3>& w, std::array<Real, 3>& u, std::array<Real, 3>& v) const
{
    /// 鲁棒地计算一个右手正交集{ u, v, w }。
    /// 向量w保证为单位长度，在这种情况下，在计算invLength时无需担心被零除。
    Real invLength{};
    if (std::fabs(w.at(0)) > std::fabs(w.at(1)))
    {
        /// 最大绝对值的分量是w.at(0)或w.at(2)。
        invLength = MathType::GetValue(1) / std::sqrt(w.at(0) * w.at(0) + w.at(2) * w.at(2));
        u = { -w.at(2) * invLength, Real{}, +w.at(0) * invLength };
    }
    else
    {
        /// 最大绝对值的分量是w.at(1)或w.at(2)。
        invLength = MathType::GetValue(1) / std::sqrt(w.at(1) * w.at(1) + w.at(2) * w.at(2));
        u = { Real{}, +w.at(2) * invLength, -w.at(1) * invLength };
    }
    v = Cross(w, u);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::NISymmetricEigensolver3x3<Real>::ComputeEigenvector0(Real a00, Real a01, Real a02, Real a11, Real a12, Real a22, Real eval0, std::array<Real, 3>& evec0) const
{
    /// 计算特征值[i0]的单位长度特征向量。
    /// 矩阵的秩为2，因此其中两行是线性独立的。
    /// 对于特征向量的稳健计算，选择其叉积在所有行对中长度最大的两行。
    const std::array<Real, 3> row0{ a00 - eval0, a01, a02 };
    const std::array<Real, 3> row1{ a01, a11 - eval0, a12 };
    const std::array<Real, 3> row2{ a02, a12, a22 - eval0 };
    const auto r0Xr1 = Cross(row0, row1);
    const auto r0Xr2 = Cross(row0, row2);
    const auto r1Xr2 = Cross(row1, row2);
    auto d0 = Dot(r0Xr1, r0Xr1);
    auto d1 = Dot(r0Xr2, r0Xr2);
    auto d2 = Dot(r1Xr2, r1Xr2);

    auto dMax = d0;
    auto iMax = 0;
    if (d1 > dMax)
    {
        dMax = d1;
        iMax = 1;
    }
    if (d2 > dMax)
    {
        iMax = 2;
    }

    if (iMax == 0)
    {
        evec0 = Divide(r0Xr1, std::sqrt(d0));
    }
    else if (iMax == 1)
    {
        evec0 = Divide(r0Xr2, std::sqrt(d1));
    }
    else
    {
        evec0 = Divide(r1Xr2, std::sqrt(d2));
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::NISymmetricEigensolver3x3<Real>::ComputeEigenvector1(Real a00, Real a01, Real a02, Real a11, Real a12, Real a22, const std::array<Real, 3>& evec0, Real eval1, std::array<Real, 3>& evec1) const
{
    /// 鲁棒计算右手正交正规集
    /// { U, V, evec0 }.
    std::array<Real, 3> u{};
    std::array<Real, 3> v{};
    ComputeOrthogonalComplement(evec0, u, v);

    /// 设e为eval1，设e为对应的特征向量，它是线性系统(A - e*I)*E = 0的解。
    /// 矩阵(A - e*I)是3x3，不可逆（因此有无限多个解），
    /// 当eval1和eval不同时，矩阵的秩为2。
    /// 当eval1和eval2相等时，它的排名为1。
    /// 从数字上讲，很难稳健地计算矩阵的秩。
    /// 相反，将3x3线性系统简化为2x2系统，如下所示。
    /// 定义3x2矩阵J = [U V]，其列为之前计算的U和V。
    /// 定义2x1向量X = J*E。
    /// 2x2系统是0 = M * X = (J^Real * (A - e*I) * J) * X，
    /// 其中J^Real是J的转置，M = J^Real * (A - e*I) * J是2x2矩阵。
    /// 系统可以写成
    ///     +-                        -++-  -+       +-  -+
    ///     | U^Real*A*U - e  U^Real*A*V     || x0 | = e * | x0 |
    ///     | V^Real*A*U      V^Real*A*V - e || x1 |       | x1 |
    ///     +-                        -++   -+       +-  -+
    /// 其中X具有行条目x0和x1。

    std::array<Real, 3> au{ a00 * u.at(0) + a01 * u.at(1) + a02 * u.at(2),
                            a01 * u.at(0) + a11 * u.at(1) + a12 * u.at(2),
                            a02 * u.at(0) + a12 * u.at(1) + a22 * u.at(2) };

    std::array<Real, 3> av{ a00 * v.at(0) + a01 * v.at(1) + a02 * v.at(2),
                            a01 * v.at(0) + a11 * v.at(1) + a12 * v.at(2),
                            a02 * v.at(0) + a12 * v.at(1) + a22 * v.at(2) };

    auto m00 = u.at(0) * au.at(0) + u.at(1) * au.at(1) + u.at(2) * au.at(2) - eval1;
    auto m01 = u.at(0) * av.at(0) + u.at(1) * av.at(1) + u.at(2) * av.at(2);
    auto m11 = v.at(0) * av.at(0) + v.at(1) * av.at(1) + v.at(2) * av.at(2) - eval1;

    /// 为了鲁棒性，选择M的最大长度行来计算特征向量。
    /// 在eigenvector.at(1)的赋值中，U和V的系数的二元组位于一个圆上，
    /// U和V是单位长度且垂直，因此eigenvector.at(1)是单位长度（在数值公差范围内）。
    const auto absM00 = std::fabs(m00);
    const auto absM01 = std::fabs(m01);
    const auto absM11 = std::fabs(m11);
    Real maxAbsComp{};
    if (absM00 >= absM11)
    {
        maxAbsComp = std::max(absM00, absM01);
        if (maxAbsComp > Real{})
        {
            if (absM00 >= absM01)
            {
                m01 /= m00;
                m00 = MathType::GetValue(1) / std::sqrt(MathType::GetValue(1) + m01 * m01);
                m01 *= m00;
            }
            else
            {
                m00 /= m01;
                m01 = MathType::GetValue(1) / std::sqrt(MathType::GetValue(1) + m00 * m00);
                m00 *= m01;
            }
            evec1 = Subtract(Multiply(m01, u), Multiply(m00, v));
        }
        else
        {
            evec1 = u;
        }
    }
    else
    {
        maxAbsComp = std::max(absM11, absM01);
        if (maxAbsComp > Real{})
        {
            if (absM11 >= absM01)
            {
                m01 /= m11;
                m11 = MathType::GetValue(1) / std::sqrt(MathType::GetValue(1) + m01 * m01);
                m01 *= m11;
            }
            else
            {
                m11 /= m01;
                m01 = MathType::GetValue(1) / std::sqrt(MathType::GetValue(1) + m11 * m11);
                m11 *= m01;
            }
            evec1 = Subtract(Multiply(m11, u), Multiply(m01, v));
        }
        else
        {
            evec1 = u;
        }
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_NI_SYMMETRIC_EIGENSOLVER_3X3_DETAIL_H
