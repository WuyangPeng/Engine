///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:04)

#ifndef MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_ACHIEVE_H

#include "Tridiagonalize.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Tridiagonalize<Real>::Tridiagonalize(const Matrix3& matrix)
    : inputMatrix{ matrix }, outputMatrix{ MatrixInitType::Identity }, reflection{ false }, diagonal{}, subDiagonal{}
{
    MATHEMATICS_ASSERTION_1(Math::FAbs(inputMatrix.template GetValue<0, 1>() - inputMatrix.template GetValue<1, 0>()) <= Math::GetZeroTolerance(), "矩阵必须是对称矩阵。");
    MATHEMATICS_ASSERTION_1(Math::FAbs(inputMatrix.template GetValue<0, 2>() - inputMatrix.template GetValue<2, 0>()) <= Math::GetZeroTolerance(), "矩阵必须是对称矩阵。");
    MATHEMATICS_ASSERTION_1(Math::FAbs(inputMatrix.template GetValue<1, 2>() - inputMatrix.template GetValue<2, 1>()) <= Math::GetZeroTolerance(), "矩阵必须是对称矩阵。");

    Init();

    if (!QLAlgorithm())
    {
        MATHEMATICS_ASSERTION_0(false, "QLAlgorithm不收敛！");
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Tridiagonalize<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Tridiagonalize<Real>::Init()
{
    // Householder reduction T = Q^t M Q
    //   输入:
    //     inputMatrix, 对称 3x3 矩阵 M
    //   输出:
    //     outputMatrix, 正交矩阵 Q (反射)
    //     diagonal, T的对角线 T
    //     subDiagonal,T的次对角项 T (T 是对称的)

    auto m00 = inputMatrix.template GetValue<0, 0>();
    auto m01 = inputMatrix.template GetValue<0, 1>();
    auto m02 = inputMatrix.template GetValue<0, 2>();
    auto m11 = inputMatrix.template GetValue<1, 1>();
    auto m12 = inputMatrix.template GetValue<1, 2>();
    auto m22 = inputMatrix.template GetValue<2, 2>();

    diagonal = Vector3{ m00, Math::GetValue(0), Math::GetValue(0) };

    subDiagonal = Vector2::GetZero();

    if (Math::GetZeroTolerance() <= Math::FAbs(m02))
    {
        subDiagonal.SetX(Math::Sqrt(m01 * m01 + m02 * m02));
        auto invLength = Math::GetValue(1) / subDiagonal.GetX();
        m01 *= invLength;
        m02 *= invLength;
        auto temp = Math::GetValue(2) * m01 * m12 + m02 * (m22 - m11);
        diagonal.SetY(m11 + m02 * temp);
        diagonal.SetZ(m22 - m02 * temp);
        subDiagonal.SetY(m12 - m01 * temp);

        outputMatrix = Matrix3{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0),
                                Math::GetValue(0), m01, m02,
                                Math::GetValue(0), m02, -m01 };

        reflection = true;
    }
    else
    {
        diagonal.SetY(m11);
        diagonal.SetZ(m22);
        subDiagonal = Vector2{ m01, m12 };

        outputMatrix.MakeIdentity();

        reflection = false;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Tridiagonalize<Real>::IsValueNear(Real subDiagonal, Real lhsDiagonal, Real rhsDiagonal) noexcept
{
    const auto sum = Math::FAbs(lhsDiagonal) + Math::FAbs(rhsDiagonal);

    if (Math::FAbs(Math::FAbs(subDiagonal) + sum - sum) <= Math::epsilon)
        return true;
    else
        return false;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Tridiagonalize<Real>::UpdateDiagonal(int lhsIndex, int rhsIndex)
{
    // 计算特征值的一元二次方程的根。
    const auto sum = diagonal[lhsIndex] + diagonal[rhsIndex];
    const auto difference = diagonal[lhsIndex] - diagonal[rhsIndex];
    const auto discr = Math::Sqrt(difference * difference + (Math::GetValue(4) * subDiagonal[lhsIndex] * subDiagonal[lhsIndex]));
    const auto eigenvalue0 = Math::GetRational(1, 2) * (sum - discr);
    const auto eigenvalue1 = Math::GetRational(1, 2) * (sum + discr);

    auto cosValue = Math::GetValue(0);
    auto sinValue = Math::GetValue(0);

    // 计算Givens旋转。
    if (Math::GetValue(0) <= difference)
    {
        cosValue = subDiagonal[lhsIndex];
        sinValue = diagonal[lhsIndex] - eigenvalue0;
    }
    else
    {
        cosValue = diagonal[rhsIndex] - eigenvalue0;
        sinValue = subDiagonal[lhsIndex];
    }

    const auto invSqrt = Math::InvSqrt(cosValue * cosValue + sinValue * sinValue);

    cosValue *= invSqrt;
    sinValue *= invSqrt;

    // 右乘当前正交矩阵使用Givens旋转
    GivensRotation(lhsIndex, rhsIndex, cosValue, sinValue);

    // 更新三角矩阵。
    diagonal[lhsIndex] = eigenvalue0;
    diagonal[rhsIndex] = eigenvalue1;
    subDiagonal = Vector2::GetZero();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::Tridiagonalize<Real>::GivensRotation(int lhsIndex, int rhsIndex, Real cosValue, Real sinValue)
{
    for (auto row = 0; row < Vector3::pointSize; ++row)
    {
        const auto value = outputMatrix(row, rhsIndex);
        outputMatrix(row, rhsIndex) = sinValue * outputMatrix(row, lhsIndex) + cosValue * value;
        outputMatrix(row, lhsIndex) = cosValue * outputMatrix(row, lhsIndex) - sinValue * value;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Tridiagonalize<Real>::QLAlgorithm()
{
    // 这是基于书“矩阵计算”第二版（Gene H. Golub 和 Charles F. Van Loan）
    // 实现的对称QR算法。该算法在8.2.3。
    // 实施有轻微的变化，以使之实际成为QL算法，
    // 并将其捕获任一次对角项S0或S1是零的情况下，直接降低为2×2的子块。

    constexpr auto indexMax = 32;
    for (auto i = 0; i < indexMax; ++i)
    {
        if (IsValueNear(subDiagonal.GetX(), diagonal.GetX(), diagonal.GetY()))
        {
            // 该矩阵是有效的
            //       +-        -+
            //   M = | d0  0  0 |
            //       | 0  d1 s1 |
            //       | 0  s1 d2 |
            //       +-        -+
            // Init函数将矩阵初始化为这种形式，所以下面的其他逻辑不会涉及。

            // 测试M是否是对角线矩阵（数字四舍五入）。
            if (IsValueNear(subDiagonal.GetY(), diagonal.GetY(), diagonal.GetY()))
            {
                return true;
            }

            UpdateDiagonal(1, 2);

            return true;
        }

        if (IsValueNear(subDiagonal.GetY(), diagonal.GetY(), diagonal.GetY()))
        {
            // 该矩阵是有效
            //       +-         -+
            //   M = | d0  s0  0 |
            //       | s0  d1  0 |
            //       | 0   0  d2 |
            //       +-         -+

            // 测试M是否是对角线矩阵（数字四舍五入）。
            if (IsValueNear(subDiagonal.GetX(), diagonal.GetX(), diagonal.GetY()))
            {
                return true;
            }

            UpdateDiagonal(0, 1);

            return true;
        }

        // 矩阵是
        //       +-        -+
        //   M = | d0 s0  0 |
        //       | s0 d1 s1 |
        //       | 0  s1 d2 |
        //       +-        -+

        // 设置参数为QL步骤的第一阶段中。
        // 对于A的值是在对角项D[2]和隐式移位的差由Wilkinson建议。
        auto ratio = (diagonal.GetY() - diagonal.GetX()) / (Math::GetValue(2) * subDiagonal.GetX());
        auto root = Math::Sqrt(Math::GetValue(1) + ratio * ratio);
        auto subDiagonalY = subDiagonal.GetY();
        auto a = diagonal.GetZ() - diagonal.GetX();
        if (Math::GetValue(0) <= ratio)
        {
            a += subDiagonal.GetX() / (ratio + root);
        }
        else
        {
            a += subDiagonal.GetX() / (ratio - root);
        }

        auto cosValue = Math::GetValue(0);
        auto sinValue = Math::GetValue(0);

        // 计算Givens旋转的第一遍。
        if (Math::FAbs(a) <= Math::FAbs(subDiagonalY))
        {
            ratio = a / subDiagonalY;
            sinValue = Math::InvSqrt((Math::GetValue(1) + ratio * ratio));
            cosValue = ratio * sinValue;
        }
        else
        {
            ratio = subDiagonalY / a;
            cosValue = Math::InvSqrt(Math::GetValue(1) + ratio * ratio);
            sinValue = ratio * cosValue;
        }

        // 右乘当前正交矩阵使用Givens旋转
        GivensRotation(1, 2, cosValue, sinValue);

        // 设置参数为QL步骤的第二步。
        // 值tmp0和tmp1需要在第二阶段结束时，才能全面更新三对角矩阵。
        auto value0 = (diagonal.GetY() - diagonal.GetZ()) * sinValue + Math::GetValue(2) * subDiagonal.GetY() * cosValue;
        auto value1 = cosValue * subDiagonal.GetX();
        subDiagonalY = sinValue * subDiagonal.GetX();
        a = cosValue * value0 - subDiagonal.GetY();
        value0 *= sinValue;

        // 计算Givens旋转的第二遍。m_Subdiagonal的项S[1]在三对角矩阵，此时被更新。
        if (Math::FAbs(a) <= Math::FAbs(subDiagonalY))
        {
            ratio = a / subDiagonalY;
            root = Math::Sqrt(Math::GetValue(1) + ratio * ratio);
            subDiagonal.SetY(subDiagonalY * root);
            sinValue = Math::GetValue(1) / root;
            cosValue = ratio * sinValue;
        }
        else
        {
            ratio = subDiagonalY / a;
            root = Math::Sqrt(Math::GetValue(1) + ratio * ratio);
            subDiagonal.SetY(a * root);
            cosValue = Math::GetValue(1) / root;
            sinValue = ratio * cosValue;
        }

        // 右乘当前正交矩阵使用Givens旋转
        GivensRotation(0, 1, cosValue, sinValue);

        // 完成三对角矩阵的更新。
        auto tmp2 = diagonal.GetY() - value0;
        diagonal[2] += value0;
        value0 = (diagonal.GetX() - tmp2) * sinValue + Math::GetValue(2) * value1 * cosValue;
        subDiagonal.SetX(cosValue * value0 - value1);
        value0 *= sinValue;
        diagonal.SetY(tmp2 + value0);
        diagonal[0] -= value0;
    }

    return false;
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::Tridiagonalize<Real>::IsReflection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return reflection;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Tridiagonalize<Real>::Matrix3 Mathematics::Tridiagonalize<Real>::GetRotation() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return outputMatrix;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Tridiagonalize<Real>::Vector3 Mathematics::Tridiagonalize<Real>::GetDiagonal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return diagonal;
}

#endif  // MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_ACHIEVE_H
