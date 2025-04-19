/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 14:41)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER3_X_3_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER3_X_3_DETAIL_H

#include "SortEigenstuff.h"
#include "SymmetricEigensolver3x3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::SymmetricEigensolver3x3<Real>::SymmetricEigensolver3x3() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::SymmetricEigensolver3x3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::SymmetricEigensolver3x3<Real>::operator()(const Real& a00, const Real& a01, const Real& a02, const Real& a11, const Real& a12, const Real& a22, bool aggressive, int sortType, std::array<Real, 3>& eval, std::array<std::array<Real, 3>, 3>& evec) const
{
    /// 计算Householder反射H0和B = H0*A*H0，
    /// 其中b02 = 0。H0 = {{c,s,0},{s,-c,0},{0,0,1}} ，其中每个内部三元组是H0的一行。
    constexpr Real zero{};
    constexpr auto one = MathType::GetValue(1);
    constexpr auto half = MathType::GetRational(1, 2);
    auto isRotation = false;
    auto c = zero;
    auto s = zero;
    GetCosSin(a12, -a02, c, s);
    auto term0 = c * a00 + s * a01;
    auto term1 = c * a01 + s * a11;
    auto term2 = s * a00 - c * a01;
    auto term3 = s * a01 - c * a11;
    auto b00 = c * term0 + s * term1;
    auto b01 = s * term0 - c * term1;
    // auto b02 = c * a02 + s * a12;  // 0
    auto b11 = s * term2 - c * term3;
    auto b12 = s * a02 - c * a12;
    auto b22 = a22;

    /// 将q保持为反射的乘积。最初，Q = H0。Givens反射G的更新是Q <- Q * G。最终Q的列是对特征向量的估计。
    std::array<std::array<Real, 3>, 3> q{ { { c, s, zero },
                                            { s, -c, zero },
                                            { zero, zero, one } } };

    /// 最小的次正规数是2^{-alpha}。alpha值对于 'float'为149，对于'double'为1074。
    constexpr auto alpha = std::numeric_limits<Real>::digits - std::numeric_limits<Real>::min_exponent;
    auto i = 0;
    auto imax = 0;
    auto power = 0;
    auto c2 = zero;
    auto s2 = zero;

    if (std::fabs(b12) <= std::fabs(b01))
    {
        /// 已知 |currentB12| < 2^{-i/2} * |initialB12|。
        /// 计算imax，使0是最接近2^{-imax/2} * |initialB12|的浮点数。
        std::ignore = std::frexp(b12, &power);
        imax = 2 * (power + alpha + 1);

        for (i = 0; i < imax; ++i)
        {
            /// 计算Givens反射G = {{c,0,-s},{s,0,c},{0,1,0}}，其中每个内三元组是G的一行。
            GetCosSin(half * (b00 - b11), b01, c2, s2);
            s = std::sqrt(half * (one - c2));
            c = half * s2 / s;

            // 更新 Q <- Q * G.
            for (auto r = 0; r < 3; ++r)
            {
                term0 = c * q.at(r).at(0) + s * q.at(r).at(1);
                term1 = q.at(r).at(2);
                term2 = c * q.at(r).at(1) - s * q.at(r).at(0);
                q.at(r).at(0) = term0;
                q.at(r).at(1) = term1;
                q.at(r).at(2) = term2;
            }
            isRotation = !isRotation;

            /// 更新B <- Q^Real * B * Q，确保b02为零并且|b12|已严格减小。
            term0 = c * b00 + s * b01;
            term1 = c * b01 + s * b11;
            term2 = s * b00 - c * b01;
            term3 = s * b01 - c * b11;
            // b02 = s * c * (b11 - b00) + (c * c - s * s) * b01; // 0
            b00 = c * term0 + s * term1;
            b01 = s * b12;
            b11 = b22;
            b12 = c * b12;
            b22 = s * term2 - c * term3;

            if (Converged(aggressive, b00, b11, b01))
            {
                /// 计算Householder反射H1 = {{c,s,0},{s,-c,0},{0,0,1}}，其中每个内部三元组是H1的一行。
                GetCosSin(half * (b00 - b11), b01, c2, s2);
                s = std::sqrt(half * (one - c2));
                c = half * s2 / s;

                /// 更新 Q <- Q * H1.
                for (auto r = 0; r < 3; ++r)
                {
                    term0 = c * q.at(r).at(0) + s * q.at(r).at(1);
                    term1 = s * q.at(r).at(0) - c * q.at(r).at(1);
                    q.at(r).at(0) = term0;
                    q.at(r).at(1) = term1;
                }
                isRotation = !isRotation;

                /// 计算对角线估计D = Q^Real * B * Q。
                term0 = c * b00 + s * b01;
                term1 = c * b01 + s * b11;
                term2 = s * b00 - c * b01;
                term3 = s * b01 - c * b11;
                b00 = c * term0 + s * term1;
                b11 = s * term2 - c * term3;
                break;
            }
        }
    }
    else
    {
        /// 已知 |currentB01| < 2^{-i/2} * |initialB01|。
        /// 计算imax，使0是最接近2^{-imax/2} * |initialB01|的浮点数。
        std::ignore = std::frexp(b01, &power);
        imax = 2 * (power + alpha + 1);

        for (i = 0; i < imax; ++i)
        {
            /// 计算Givens反射G = {{0,1,0},{c,0,-s},{s,0,c}} ，
            /// 其中每个内三元组是G的一行。
            GetCosSin(half * (b11 - b22), b12, c2, s2);
            s = std::sqrt(half * (one - c2));
            c = half * s2 / s;

            // 更新 Q <- Q * G.
            for (auto r = 0; r < 3; ++r)
            {
                term0 = c * q.at(r).at(1) + s * q.at(r).at(2);
                term1 = q.at(r).at(0);
                term2 = c * q.at(r).at(2) - s * q.at(r).at(1);
                q.at(r).at(0) = term0;
                q.at(r).at(1) = term1;
                q.at(r).at(2) = term2;
            }
            isRotation = !isRotation;

            /// 更新B <- Q^Real * B * Q，确保b02为零并且|b01|已严格减小。
            term0 = c * b11 + s * b12;
            term1 = c * b12 + s * b22;
            term2 = s * b11 - c * b12;
            term3 = s * b12 - c * b22;
            // b02 = s * c * (b22 - b11) + (c * c - s * s) * b12;  // 0
            b22 = s * term2 - c * term3;
            b12 = -s * b01;
            b11 = b00;
            b01 = c * b01;
            b00 = c * term0 + s * term1;

            if (Converged(aggressive, b11, b22, b12))
            {
                /// 计算Householder反射H1 = {{1,0,0},{0,c,s},{0,s,-c}}，其中每个内部三元组是H1的一行。
                GetCosSin(half * (b11 - b22), b12, c2, s2);
                s = std::sqrt(half * (one - c2));
                c = half * s2 / s;

                // 更新 Q <- Q * H1.
                for (auto r = 0; r < 3; ++r)
                {
                    term0 = c * q.at(r).at(1) + s * q.at(r).at(2);
                    term1 = s * q.at(r).at(1) - c * q.at(r).at(2);
                    q.at(r).at(1) = term0;
                    q.at(r).at(2) = term1;
                }
                isRotation = !isRotation;

                /// 计算对角线估计 D = Q^Real * B * Q.
                term0 = c * b11 + s * b12;
                term1 = c * b12 + s * b22;
                term2 = s * b11 - c * b12;
                term3 = s * b12 - c * b22;
                b11 = c * term0 + s * term1;
                b22 = s * term2 - c * term3;
                break;
            }
        }
    }

    eval = { b00, b11, b22 };
    for (auto row = 0; row < 3; ++row)
    {
        for (auto col = 0; col < 3; ++col)
        {
            evec.at(row).at(col) = q.at(col).at(row);
        }
    }

    SortEigenstuff<Real>()(sortType, isRotation, eval, evec);
    return i;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::SymmetricEigensolver3x3<Real>::GetCosSin(const Real& u, const Real& v, Real& c, Real& s) noexcept
{
    const auto length = std::sqrt(u * u + v * v);
    if (length > Real{})
    {
        c = u / length;
        s = v / length;
        if (c > Real{})
        {
            c = -c;
            s = -s;
        }
    }
    else
    {
        c = MathType::GetValue(-1);
        s = Real{};
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::SymmetricEigensolver3x3<Real>::Converged(bool aggressive, const Real& diagonal0, const Real& diagonal1, const Real& superDiagonal) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    if (aggressive)
    {
        /// 测试superDiagonal项是否为零。
        return MathType::Approximate(superDiagonal, Real{});
    }
    else
    {
        /// 测试超对角线项与其对角线邻居相比是否有效为零。
        const auto sum = std::fabs(diagonal0) + std::fabs(diagonal1);
        return MathType::Approximate(sum + std::fabs(superDiagonal), sum);
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER3_X_3_DETAIL_H
