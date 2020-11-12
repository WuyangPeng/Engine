///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/11 9:57)

#ifndef MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_ACHIEVE_H

#include "Tridiagonalize.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Tridiagonalize<Real>::Tridiagonalize(const Matrix3& matrix)
    : m_InputMatrix{ matrix }, m_OutputMatrix{ MatrixInitType::Identity }, m_Reflection{ false }, m_Diagonal{}, m_Subdiagonal{}
{
    MATHEMATICS_ASSERTION_1(Math::FAbs(m_InputMatrix.GetValue<0, 1>() - m_InputMatrix.GetValue<1, 0>()) <= Math::GetZeroTolerance(), "��������ǶԳƾ���");
    MATHEMATICS_ASSERTION_1(Math::FAbs(m_InputMatrix.GetValue<0, 2>() - m_InputMatrix.GetValue<2, 0>()) <= Math::GetZeroTolerance(), "��������ǶԳƾ���");
    MATHEMATICS_ASSERTION_1(Math::FAbs(m_InputMatrix.GetValue<1, 2>() - m_InputMatrix.GetValue<2, 1>()) <= Math::GetZeroTolerance(), "��������ǶԳƾ���");

    Init();

    if (!QLAlgorithm())
    {
        MATHEMATICS_ASSERTION_1(false, "QLAlgorithm��������");
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
    //     m_InputMatrix, �Գ� 3x3 ���� M
    //   ���:
    //     m_OutputMatrix, �������� Q (����)
    //     m_Diagonal, T�ĶԽ��� T
    //     m_Subdiagonal,T�ĴζԽ��� T (T �ǶԳƵ�)

    auto m00 = m_InputMatrix.GetValue<0, 0>();
    auto m01 = m_InputMatrix.GetValue<0, 1>();
    auto m02 = m_InputMatrix.GetValue<0, 2>();
    auto m11 = m_InputMatrix.GetValue<1, 1>();
    auto m12 = m_InputMatrix.GetValue<1, 2>();
    auto m22 = m_InputMatrix.GetValue<2, 2>();

    m_Diagonal = Vector3D{ m00, Math::GetValue(0), Math::GetValue(0) };

    m_Subdiagonal = Vector2D::GetZero();

    if (Math::GetZeroTolerance() <= Math::FAbs(m02))
    {
        m_Subdiagonal.SetX(Math::Sqrt(m01 * m01 + m02 * m02));
        auto invLength = Math::GetValue(1) / m_Subdiagonal.GetX();
        m01 *= invLength;
        m02 *= invLength;
        auto temp = Math::GetValue(2) * m01 * m12 + m02 * (m22 - m11);
        m_Diagonal.SetY(m11 + m02 * temp);
        m_Diagonal.SetZ(m22 - m02 * temp);
        m_Subdiagonal.SetY(m12 - m01 * temp);

        m_OutputMatrix = Matrix3{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0),
                                  Math::GetValue(0), m01, m02,
                                  Math::GetValue(0), m02, -m01 };

        m_Reflection = true;
    }
    else
    {
        m_Diagonal.SetY(m11);
        m_Diagonal.SetZ(m22);
        m_Subdiagonal = Vector2D{ m01, m01 };

        m_OutputMatrix.MakeIdentity();

        m_Reflection = false;
    }
}

template <typename Real>
bool Mathematics::Tridiagonalize<Real>::IsValueNear(Real subdiagonal, Real lhsDiagonal, Real rhsDiagonal) noexcept
{
    auto sum = Math::FAbs(lhsDiagonal) + Math::FAbs(rhsDiagonal);

    if (Math::FAbs(Math::FAbs(subdiagonal) + sum - sum) <= Math::sm_Epsilon)
        return true;
    else
        return false;
}

template <typename Real>
void Mathematics::Tridiagonalize<Real>::UpdateDiagonal(int lhsIndex, int rhsIndex)
{
    // ��������ֵ��һԪ���η��̵ĸ���
    auto sum = m_Diagonal[lhsIndex] + m_Diagonal[rhsIndex];
    auto difference = m_Diagonal[lhsIndex] - m_Diagonal[rhsIndex];
    auto discr = Math::Sqrt(difference * difference + (Math::GetValue(4) * m_Subdiagonal[lhsIndex] * m_Subdiagonal[lhsIndex]));
    auto eigenvalue0 = Math::GetRational(1, 2) * (sum - discr);
    auto eigenvalue1 = Math::GetRational(1, 2) * (sum + discr);

    auto cosValue = Math::GetValue(0);
    auto sinValue = Math::GetValue(0);

    // ����Givens��ת��
    if (Math::GetValue(0) <= difference)
    {
        cosValue = m_Subdiagonal[lhsIndex];
        sinValue = m_Diagonal[lhsIndex] - eigenvalue0;
    }
    else
    {
        cosValue = m_Diagonal[rhsIndex] - eigenvalue0;
        sinValue = m_Subdiagonal[lhsIndex];
    }

    auto invSqrt = Math::InvSqrt(cosValue * cosValue + sinValue * sinValue);

    cosValue *= invSqrt;
    sinValue *= invSqrt;

    // �ҳ˵�ǰ��������ʹ��Givens��ת
    GivensRotation(lhsIndex, rhsIndex, cosValue, sinValue);

    // �������Ǿ���
    m_Diagonal[lhsIndex] = eigenvalue0;
    m_Diagonal[rhsIndex] = eigenvalue1;
    m_Subdiagonal = Vector2D::GetZero();
}

template <typename Real>
void Mathematics::Tridiagonalize<Real>::GivensRotation(int lhsIndex, int rhsIndex, Real cosValue, Real sinValue)
{
    for (auto row = 0; row < Vector3D::sm_PointSize; ++row)
    {
        auto value = m_OutputMatrix(row, rhsIndex);
        m_OutputMatrix(row, rhsIndex) = sinValue * m_OutputMatrix(row, lhsIndex) + cosValue * value;
        m_OutputMatrix(row, lhsIndex) = cosValue * m_OutputMatrix(row, lhsIndex) - sinValue * value;
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
        if (IsValueNear(m_Subdiagonal.GetX(), m_Diagonal.GetX(), m_Diagonal.GetY()))
        {
            // �þ�������Ч��
            //       +-        -+
            //   M = | d0  0  0 |
            //       | 0  d1 s1 |
            //       | 0  s1 d2 |
            //       +-        -+
            // Init�����������ʼ��Ϊ������ʽ����������������߼������漰��

            // ����M�Ƿ��ǶԽ��߾��������������룩��
            if (IsValueNear(m_Subdiagonal.GetY(), m_Diagonal.GetY(), m_Diagonal.GetY()))
            {
                return true;
            }

            UpdateDiagonal(1, 2);

            return true;
        }

        if (IsValueNear(m_Subdiagonal.GetY(), m_Diagonal.GetY(), m_Diagonal.GetY()))
        {
            // �þ�������Ч
            //       +-         -+
            //   M = | d0  s0  0 |
            //       | s0  d1  0 |
            //       | 0   0  d2 |
            //       +-         -+

            // ����M�Ƿ��ǶԽ��߾��������������룩��
            if (IsValueNear(m_Subdiagonal.GetX(), m_Diagonal.GetX(), m_Diagonal.GetY()))
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
        auto ratio = (m_Diagonal.GetY() - m_Diagonal.GetX()) / (Math::GetValue(2) * m_Subdiagonal.GetX());
        auto root = Math::Sqrt(Math::GetValue(1) + ratio * ratio);
        auto b = m_Subdiagonal.GetY();
        auto a = m_Diagonal.GetZ() - m_Diagonal.GetX();
        if (Math::GetValue(0) <= ratio)
        {
            a += m_Subdiagonal.GetX() / (ratio + root);
        }
        else
        {
            a += m_Subdiagonal.GetX() / (ratio - root);
        }

        auto cosValue = Math::GetValue(0);
        auto sinValue = Math::GetValue(0);

        // ����Givens��ת�ĵ�һ�顣
        if (Math::FAbs(a) <= Math::FAbs(b))
        {
            ratio = a / b;
            sinValue = Math::InvSqrt((Math::GetValue(1) + ratio * ratio));
            cosValue = ratio * sinValue;
        }
        else
        {
            ratio = b / a;
            cosValue = Math::InvSqrt(Math::GetValue(1) + ratio * ratio);
            sinValue = ratio * cosValue;
        }

        // �ҳ˵�ǰ��������ʹ��Givens��ת
        GivensRotation(1, 2, cosValue, sinValue);

        // ���ò���ΪQL����ĵڶ�����
        // ֵtmp0��tmp1��Ҫ�ڵڶ��׶ν���ʱ������ȫ��������ԽǾ���
        auto tmp0 = (m_Diagonal.GetY() - m_Diagonal.GetZ()) * sinValue + Math::GetValue(2) * m_Subdiagonal.GetY() * cosValue;
        auto tmp1 = cosValue * m_Subdiagonal.GetX();
        b = sinValue * m_Subdiagonal.GetX();
        a = cosValue * tmp0 - m_Subdiagonal.GetY();
        tmp0 *= sinValue;

        // ����Givens��ת�ĵڶ��顣m_Subdiagonal����S[1]�����ԽǾ��󣬴�ʱ�����¡�
        if (Math::FAbs(a) <= Math::FAbs(b))
        {
            ratio = a / b;
            root = Math::Sqrt(Math::GetValue(1) + ratio * ratio);
            m_Subdiagonal.SetY(b * root);
            sinValue = Math::GetValue(1) / root;
            cosValue = ratio * sinValue;
        }
        else
        {
            ratio = b / a;
            root = Math::Sqrt(Math::GetValue(1) + ratio * ratio);
            m_Subdiagonal.SetY(a * root);
            cosValue = Math::GetValue(1) / root;
            sinValue = ratio * cosValue;
        }

        // �ҳ˵�ǰ��������ʹ��Givens��ת
        GivensRotation(0, 1, cosValue, sinValue);

        // ������ԽǾ���ĸ��¡�
        auto tmp2 = m_Diagonal.GetY() - tmp0;
        m_Diagonal[2] += tmp0;
        tmp0 = (m_Diagonal.GetX() - tmp2) * sinValue + Math::GetValue(2) * tmp1 * cosValue;
        m_Subdiagonal.SetX(cosValue * tmp0 - tmp1);
        tmp0 *= sinValue;
        m_Diagonal.SetY(tmp2 + tmp0);
        m_Diagonal[0] -= tmp0;
    }

    return false;
}

template <typename Real>
bool Mathematics::Tridiagonalize<Real>::IsReflection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Reflection;
}

template <typename Real>
typename const Mathematics::Tridiagonalize<Real>::Matrix3 Mathematics::Tridiagonalize<Real>::GetRotation() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_OutputMatrix;
}

template <typename Real>
typename const Mathematics::Tridiagonalize<Real>::Vector3D Mathematics::Tridiagonalize<Real>::GetDiagonal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Diagonal;
}

#endif  // MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_ACHIEVE_H
