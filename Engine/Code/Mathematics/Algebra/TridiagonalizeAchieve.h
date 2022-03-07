///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/07 17:02)

#ifndef MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_ACHIEVE_H

#include "Tridiagonalize.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Tridiagonalize<Real>::Tridiagonalize(const Matrix3& matrix)
    : inputMatrix{ matrix }, outputMatrix{ MatrixInitType::Identity }, reflection{ false }, diagonal{}, subdiagonal{}
{
    MATHEMATICS_ASSERTION_1(Math::FAbs(inputMatrix.GetValue<0, 1>() - inputMatrix.GetValue<1, 0>()) <= Math::GetZeroTolerance(), "��������ǶԳƾ���");
    MATHEMATICS_ASSERTION_1(Math::FAbs(inputMatrix.GetValue<0, 2>() - inputMatrix.GetValue<2, 0>()) <= Math::GetZeroTolerance(), "��������ǶԳƾ���");
    MATHEMATICS_ASSERTION_1(Math::FAbs(inputMatrix.GetValue<1, 2>() - inputMatrix.GetValue<2, 1>()) <= Math::GetZeroTolerance(), "��������ǶԳƾ���");

    Init();

    if (!QLAlgorithm())
    {
        MATHEMATICS_ASSERTION_0(false, "QLAlgorithm��������");
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Tridiagonalize<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::Tridiagonalize<Real>::Init()
{
    // Householder reduction T = Q^t M Q
    //   ����:
    //     inputMatrix, �Գ� 3x3 ���� M
    //   ���:
    //     outputMatrix, �������� Q (����)
    //     diagonal, T�ĶԽ��� T
    //     subdiagonal,T�ĴζԽ��� T (T �ǶԳƵ�)

    auto m00 = inputMatrix.GetValue<0, 0>();
    auto m01 = inputMatrix.GetValue<0, 1>();
    auto m02 = inputMatrix.GetValue<0, 2>();
    auto m11 = inputMatrix.GetValue<1, 1>();
    auto m12 = inputMatrix.GetValue<1, 2>();
    auto m22 = inputMatrix.GetValue<2, 2>();

    diagonal = Vector3{ m00, Math::GetValue(0), Math::GetValue(0) };

    subdiagonal = Vector2::GetZero();

    if (Math::GetZeroTolerance() <= Math::FAbs(m02))
    {
        subdiagonal.SetX(Math::Sqrt(m01 * m01 + m02 * m02));
        auto invLength = Math::GetValue(1) / subdiagonal.GetX();
        m01 *= invLength;
        m02 *= invLength;
        auto temp = Math::GetValue(2) * m01 * m12 + m02 * (m22 - m11);
        diagonal.SetY(m11 + m02 * temp);
        diagonal.SetZ(m22 - m02 * temp);
        subdiagonal.SetY(m12 - m01 * temp);

        outputMatrix = Matrix3{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0),
                                Math::GetValue(0), m01, m02,
                                Math::GetValue(0), m02, -m01 };

        reflection = true;
    }
    else
    {
        diagonal.SetY(m11);
        diagonal.SetZ(m22);
        subdiagonal = Vector2{ m01, m12 };

        outputMatrix.MakeIdentity();

        reflection = false;
    }
}

template <typename Real>
bool Mathematics::Tridiagonalize<Real>::IsValueNear(Real subdiagonal, Real lhsDiagonal, Real rhsDiagonal) noexcept
{
    const auto sum = Math::FAbs(lhsDiagonal) + Math::FAbs(rhsDiagonal);

    if (Math::FAbs(Math::FAbs(subdiagonal) + sum - sum) <= Math::epsilon)
        return true;
    else
        return false;
}

template <typename Real>
void Mathematics::Tridiagonalize<Real>::UpdateDiagonal(int lhsIndex, int rhsIndex)
{
    // ��������ֵ��һԪ���η��̵ĸ���
    const auto sum = diagonal[lhsIndex] + diagonal[rhsIndex];
    const auto difference = diagonal[lhsIndex] - diagonal[rhsIndex];
    const auto discr = Math::Sqrt(difference * difference + (Math::GetValue(4) * subdiagonal[lhsIndex] * subdiagonal[lhsIndex]));
    const auto eigenvalue0 = Math::GetRational(1, 2) * (sum - discr);
    const auto eigenvalue1 = Math::GetRational(1, 2) * (sum + discr);

    auto cosValue = Math::GetValue(0);
    auto sinValue = Math::GetValue(0);

    // ����Givens��ת��
    if (Math::GetValue(0) <= difference)
    {
        cosValue = subdiagonal[lhsIndex];
        sinValue = diagonal[lhsIndex] - eigenvalue0;
    }
    else
    {
        cosValue = diagonal[rhsIndex] - eigenvalue0;
        sinValue = subdiagonal[lhsIndex];
    }

    const auto invSqrt = Math::InvSqrt(cosValue * cosValue + sinValue * sinValue);

    cosValue *= invSqrt;
    sinValue *= invSqrt;

    // �ҳ˵�ǰ��������ʹ��Givens��ת
    GivensRotation(lhsIndex, rhsIndex, cosValue, sinValue);

    // �������Ǿ���
    diagonal[lhsIndex] = eigenvalue0;
    diagonal[rhsIndex] = eigenvalue1;
    subdiagonal = Vector2::GetZero();
}

template <typename Real>
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
bool Mathematics::Tridiagonalize<Real>::QLAlgorithm()
{
    // ���ǻ����顰������㡱�ڶ��棨Gene H. Golub �� Charles F. Van Loan��
    // ʵ�ֵĶԳ�QR�㷨�����㷨��8.2.3��
    // ʵʩ����΢�ı仯����ʹ֮ʵ�ʳ�ΪQL�㷨��
    // �����䲶����һ�ζԽ���S0��S1���������£�ֱ�ӽ���Ϊ2��2���ӿ顣

    constexpr auto indexMax = 32;
    for (auto i = 0; i < indexMax; ++i)
    {
        if (IsValueNear(subdiagonal.GetX(), diagonal.GetX(), diagonal.GetY()))
        {
            // �þ�������Ч��
            //       +-        -+
            //   M = | d0  0  0 |
            //       | 0  d1 s1 |
            //       | 0  s1 d2 |
            //       +-        -+
            // Init�����������ʼ��Ϊ������ʽ����������������߼������漰��

            // ����M�Ƿ��ǶԽ��߾��������������룩��
            if (IsValueNear(subdiagonal.GetY(), diagonal.GetY(), diagonal.GetY()))
            {
                return true;
            }

            UpdateDiagonal(1, 2);

            return true;
        }

        if (IsValueNear(subdiagonal.GetY(), diagonal.GetY(), diagonal.GetY()))
        {
            // �þ�������Ч
            //       +-         -+
            //   M = | d0  s0  0 |
            //       | s0  d1  0 |
            //       | 0   0  d2 |
            //       +-         -+

            // ����M�Ƿ��ǶԽ��߾��������������룩��
            if (IsValueNear(subdiagonal.GetX(), diagonal.GetX(), diagonal.GetY()))
            {
                return true;
            }

            UpdateDiagonal(0, 1);

            return true;
        }

        // ������
        //       +-        -+
        //   M = | d0 s0  0 |
        //       | s0 d1 s1 |
        //       | 0  s1 d2 |
        //       +-        -+

        // ���ò���ΪQL����ĵ�һ�׶��С�
        // ����A��ֵ���ڶԽ���D[2]����ʽ��λ�Ĳ���Wilkinson���顣
        auto ratio = (diagonal.GetY() - diagonal.GetX()) / (Math::GetValue(2) * subdiagonal.GetX());
        auto root = Math::Sqrt(Math::GetValue(1) + ratio * ratio);
        auto subdiagonalY = subdiagonal.GetY();
        auto a = diagonal.GetZ() - diagonal.GetX();
        if (Math::GetValue(0) <= ratio)
        {
            a += subdiagonal.GetX() / (ratio + root);
        }
        else
        {
            a += subdiagonal.GetX() / (ratio - root);
        }

        auto cosValue = Math::GetValue(0);
        auto sinValue = Math::GetValue(0);

        // ����Givens��ת�ĵ�һ�顣
        if (Math::FAbs(a) <= Math::FAbs(subdiagonalY))
        {
            ratio = a / subdiagonalY;
            sinValue = Math::InvSqrt((Math::GetValue(1) + ratio * ratio));
            cosValue = ratio * sinValue;
        }
        else
        {
            ratio = subdiagonalY / a;
            cosValue = Math::InvSqrt(Math::GetValue(1) + ratio * ratio);
            sinValue = ratio * cosValue;
        }

        // �ҳ˵�ǰ��������ʹ��Givens��ת
        GivensRotation(1, 2, cosValue, sinValue);

        // ���ò���ΪQL����ĵڶ�����
        // ֵtmp0��tmp1��Ҫ�ڵڶ��׶ν���ʱ������ȫ��������ԽǾ���
        auto value0 = (diagonal.GetY() - diagonal.GetZ()) * sinValue + Math::GetValue(2) * subdiagonal.GetY() * cosValue;
        auto value1 = cosValue * subdiagonal.GetX();
        subdiagonalY = sinValue * subdiagonal.GetX();
        a = cosValue * value0 - subdiagonal.GetY();
        value0 *= sinValue;

        // ����Givens��ת�ĵڶ��顣m_Subdiagonal����S[1]�����ԽǾ��󣬴�ʱ�����¡�
        if (Math::FAbs(a) <= Math::FAbs(subdiagonalY))
        {
            ratio = a / subdiagonalY;
            root = Math::Sqrt(Math::GetValue(1) + ratio * ratio);
            subdiagonal.SetY(subdiagonalY * root);
            sinValue = Math::GetValue(1) / root;
            cosValue = ratio * sinValue;
        }
        else
        {
            ratio = subdiagonalY / a;
            root = Math::Sqrt(Math::GetValue(1) + ratio * ratio);
            subdiagonal.SetY(a * root);
            cosValue = Math::GetValue(1) / root;
            sinValue = ratio * cosValue;
        }

        // �ҳ˵�ǰ��������ʹ��Givens��ת
        GivensRotation(0, 1, cosValue, sinValue);

        // ������ԽǾ���ĸ��¡�
        auto tmp2 = diagonal.GetY() - value0;
        diagonal[2] += value0;
        value0 = (diagonal.GetX() - tmp2) * sinValue + Math::GetValue(2) * value1 * cosValue;
        subdiagonal.SetX(cosValue * value0 - value1);
        value0 *= sinValue;
        diagonal.SetY(tmp2 + value0);
        diagonal[0] -= value0;
    }

    return false;
}

template <typename Real>
bool Mathematics::Tridiagonalize<Real>::IsReflection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return reflection;
}

template <typename Real>
typename Mathematics::Tridiagonalize<Real>::Matrix3 Mathematics::Tridiagonalize<Real>::GetRotation() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return outputMatrix;
}

template <typename Real>
typename Mathematics::Tridiagonalize<Real>::Vector3 Mathematics::Tridiagonalize<Real>::GetDiagonal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return diagonal;
}

#endif  // MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_ACHIEVE_H
