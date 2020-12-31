///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/26 17:22)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_IMPL_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_IMPL_DETAIL_H

#include "NoniterativeEigen3x3Impl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::NoniterativeEigen3x3Impl<Real>::NoniterativeEigen3x3Impl(const Matrix3& matrix)
    : m_Eigenvalue{}, m_Eigenvector{}
{
    Compute(matrix);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
Real Mathematics::NoniterativeEigen3x3Impl<Real>::GetMaxValue(const Matrix3& matrix) const
{
    Container maxValue{ Math::FAbs(matrix.GetValue<0, 0>()),
                        Math::FAbs(matrix.GetValue<0, 1>()),
                        Math::FAbs(matrix.GetValue<0, 2>()),
                        Math::FAbs(matrix.GetValue<1, 1>()),
                        Math::FAbs(matrix.GetValue<1, 2>()),
                        Math::FAbs(matrix.GetValue<2, 2>()) };

    const auto iter = max_element(maxValue.begin(), maxValue.end());
    if (iter != maxValue.end())
    {
        return *iter;
    }
    else
    {
        return *maxValue.begin();
    }
}

// private
template <typename Real>
void Mathematics::NoniterativeEigen3x3Impl<Real>::Compute(const Matrix3& matrix)
{
    // ���ž�����������Ŀ����[-1,1]��
    // ����Ӧ���ڵ�����һ��������Ŀ���д�С����1��

    Matrix3 scaledEntry{ matrix };
    auto maxValue = GetMaxValue(scaledEntry);

    if (Math::GetValue(1) < maxValue)
    {
        scaledEntry /= maxValue;
    }

    // ��������ֵ����˫�������㡣
    ComputeRoots(scaledEntry);

    EigenValueType maxEntry{};
    EigenVectorType maxRow{};
    for (auto i = 0; i < sm_EigenMax; ++i)
    {
        Matrix3 computeMatrix{ scaledEntry };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
        computeMatrix(0, 0) -= m_Eigenvalue[i];
        computeMatrix(1, 1) -= m_Eigenvalue[i];
        computeMatrix(2, 1) -= m_Eigenvalue[i];
        if (!PositiveRank(computeMatrix, maxEntry[i], maxRow[i]))
        {
            // �������Ż�ԭ���Ĵ�С��
            RescaleBack(maxValue);

            m_Eigenvector = EigenVectorType{ Vector3D::GetUnitX(), Vector3D::GetUnitY(), Vector3D::GetUnitZ() };
            return;
        }
#include STSTEM_WARNING_POP
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto totalMax = maxEntry[0];
    auto maxIndex = 0;
    if (totalMax < maxEntry[1])
    {
        totalMax = maxEntry[1];
        maxIndex = 1;
    }
    if (totalMax < maxEntry[2])
    {
        maxIndex = 2;
    }

    maxRow[maxIndex].Normalize();
    ComputeVectors(scaledEntry, maxRow[maxIndex], (maxIndex + 1) % 3, (maxIndex + 2) % 3, maxIndex);

#include STSTEM_WARNING_POP

    // �������Ż�ԭ���Ĵ�С��
    RescaleBack(maxValue);
}

template <typename Real>
void Mathematics::NoniterativeEigen3x3Impl<Real>::RescaleBack(Real maxValue) noexcept
{
    if (Math::GetValue(1) < maxValue)
    {
        for (auto& value : m_Eigenvalue)
        {
            value *= maxValue;
        }
    }
}

// private
template <typename Real>
void Mathematics::NoniterativeEigen3x3Impl<Real>::ComputeRoots(const Matrix3& matrix)
{
    static const auto s_Sqrt3 = Math::Sqrt(Math::GetValue(3));

    // ת����Ψһ�ľ���Ԫ��Ϊ˫����
    const auto a00 = matrix(0, 0);
    const auto a01 = matrix(0, 1);
    const auto a02 = matrix(0, 2);
    const auto a11 = matrix(1, 1);
    const auto a12 = matrix(1, 2);
    const auto a22 = matrix(2, 2);

    // ��������Ϊx^3 - c2 * x^2 + c1 * x - c0 = 0��
    // ����ֵ��������̵ĸ�����֤����ʵ��ֵ����Ϊ�����ǶԳƵġ�
    const auto c0 = a00 * a11 * a22 + Math::GetValue(2) * a01 * a02 * a12 -
                    a00 * a12 * a12 - a11 * a02 * a02 -
                    a22 * a01 * a01;

    const auto c1 = a00 * a11 - a01 * a01 +
                    a00 * a22 - a02 * a02 +
                    a11 * a22 - a12 * a12;

    const auto c2 = a00 + a11 + a22;

    // �������ʹ���ڷ��̵ĸ����з��࣬���Ապ���ʽ����������⡣
    const auto c2Divided3 = c2 * Math::GetRational(1, 3);
    auto aDivided3 = (c1 - c2 * c2Divided3) * Math::GetRational(1, 3);

    if (Math::GetValue(0) < aDivided3)
    {
        aDivided3 = Math::GetValue(0);
    }

    const auto halfMB = Math::GetRational(1, 1) * (c0 + c2Divided3 * (Math::GetValue(2) * c2Divided3 * c2Divided3 - c1));

    auto q = halfMB * halfMB + aDivided3 * aDivided3 * aDivided3;
    if (Math::GetValue(0) < q)
    {
        q = Math::GetValue(0);
    }

    // ͨ�����ö���ʽ�ĸ�����������ֵ��
    auto magnitude = Math::Sqrt(-aDivided3);
    auto angle = Math::ATan2(Math::Sqrt(-q), halfMB) * Math::GetRational(1, 3);
    auto cosValue = Math::Cos(angle);
    auto sinValue = Math::Sin(angle);
    auto root0 = c2Divided3 + Math::GetValue(2) * magnitude * cosValue;
    auto root1 = c2Divided3 - magnitude * (cosValue + s_Sqrt3 * sinValue);
    auto root2 = c2Divided3 - magnitude * (cosValue - s_Sqrt3 * sinValue);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    // �����������С�
    if (root0 <= root1)
    {
        m_Eigenvalue[0] = root0;
        m_Eigenvalue[1] = root1;
    }
    else
    {
        m_Eigenvalue[0] = root1;
        m_Eigenvalue[1] = root0;
    }

    if (m_Eigenvalue[1] <= root2)
    {
        m_Eigenvalue[2] = root2;
    }
    else
    {
        m_Eigenvalue[2] = m_Eigenvalue[1];
        if (m_Eigenvalue[0] <= root2)
        {
            m_Eigenvalue[1] = root2;
        }
        else
        {
            m_Eigenvalue[1] = m_Eigenvalue[0];
            m_Eigenvalue[0] = root2;
        }
    }
#include STSTEM_WARNING_POP
}

template <typename Real>
bool Mathematics::NoniterativeEigen3x3Impl<Real>::PositiveRank(Matrix3& matrix, Real& maxEntry, Vector3D& maxRow) const
{
    // �ҵ��������������Ŀ��
    maxEntry = Math::GetValue(-1);

    auto maxRowIndex = -1;
    for (auto row = 0; row < sm_EigenMax; ++row)
    {
        for (auto column = row; column < sm_EigenMax; ++column)
        {
            auto absValue = Math::FAbs(matrix(row, column));
            if (maxEntry < absValue)
            {
                maxEntry = absValue;
                maxRowIndex = row;
            }
        }
    }

    // ���ذ������ֵ���У�Ҫ���������������졣
    maxRow = Vector3D{ matrix(maxRowIndex, 0), matrix(maxRowIndex, 1), matrix(maxRowIndex, 2) };

    return Math::GetZeroTolerance() <= maxEntry;
}

template <typename Real>
void Mathematics::NoniterativeEigen3x3Impl<Real>::ComputeVectors(const Matrix3& matrix, const Vector3D& vector, int index0, int index1, int index2)
{
    const auto basis = Vector3DTools::GenerateComplementBasis(vector);
    auto uVector = basis.GetUVector();
    auto vVector = basis.GetVVector();
    auto wVector = basis.GetWVector();

    // V[i2] = c0 * U0 + c1 * U1,  c0^2 + c1^2 = 1
    // e2 * V[i2] = c0 * A * U0 + c1 * A * U1
    // e2 * c0 = c0 * U0.Dot(A * U0) + c1 * U0.Dot(A * U1) = d00 * c0 + d01 * c1
    // e2 * c1 = c0 * U1.Dot(A * U0) + c1 * U1.Dot(A * U1) = d01 * c0 + d11 * c1
    const auto uVectorTransition = matrix * uVector;
    const auto vVectorTransition = matrix * vVector;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
    auto p00 = m_Eigenvalue[index2] - Vector3DTools::DotProduct(uVector, uVectorTransition);
    auto p01 = Vector3DTools::DotProduct(vVector, uVectorTransition);
    auto p11 = m_Eigenvalue[index2] - Vector3DTools::DotProduct(vVector, vVectorTransition);
#include STSTEM_WARNING_POP

    auto maxValue = Math::FAbs(p00);
    auto row = 0;
    auto absValue = Math::FAbs(p01);
    if (maxValue < absValue)
    {
        maxValue = absValue;
    }
    absValue = Math::FAbs(p11);
    if (maxValue < absValue)
    {
        maxValue = absValue;
        row = 1;
    }

    if (Math::GetZeroTolerance() <= maxValue)
    {
        if (row == 0)
        {
            auto invLength = Math::InvSqrt(p00 * p00 + p01 * p01);
            p00 *= invLength;
            p01 *= invLength;
            m_Eigenvector[index2] = p01 * uVector + p00 * vVector;
        }
        else
        {
            auto invLength = Math::InvSqrt(p11 * p11 + p01 * p01);
            p11 *= invLength;
            p01 *= invLength;
            m_Eigenvector[index2] = p11 * uVector + p01 * vVector;
        }
    }
    else
    {
        if (row == 0)
        {
            m_Eigenvector[index2] = vVector;
        }
        else
        {
            m_Eigenvector[index2] = uVector;
        }
    }

    // V[i0] = c0 * U2 + c1 * Cross(U2,V[i2]) = c0 * Real + c1 * S
    // e0 * V[i0] = c0 * A * Real + c1 * A * S
    // e0 * c0 = c0 * Real.Dot(A * Real) + c1 * Real.Dot(A * S) = d00 * c0 + d01 * c1
    // e0 * c1 = c0 * S.Dot(A * Real) + c1 * S.Dot(A * S) = d01 * c0 + d11 * c1
    auto wVectorCross = Vector3DTools::CrossProduct(wVector, m_Eigenvector[index2]);
    const auto wVectorTransition = matrix * wVector;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26482)
    p00 = m_Eigenvalue[index0] - Vector3DTools::DotProduct(wVector, wVectorTransition);
    p01 = Vector3DTools::DotProduct(wVectorCross, wVectorTransition);
    p11 = m_Eigenvalue[index0] - Vector3DTools::DotProduct(wVectorCross, matrix * wVectorCross);
#include STSTEM_WARNING_POP

    maxValue = Math::FAbs(p00);
    row = 0;
    absValue = Math::FAbs(p01);
    if (maxValue < absValue)
    {
        maxValue = absValue;
    }
    absValue = Math::FAbs(p11);
    if (maxValue < absValue)
    {
        maxValue = absValue;
        row = 1;
    }

    if (Math::GetZeroTolerance() <= maxValue)
    {
        if (row == 0)
        {
            auto invLength = Math::InvSqrt(p00 * p00 + p01 * p01);
            p00 *= invLength;
            p01 *= invLength;
            m_Eigenvector[index0] = p01 * wVector + p00 * wVectorCross;
        }
        else
        {
            auto invLength = Math::InvSqrt(p11 * p11 + p01 * p01);
            p11 *= invLength;
            p01 *= invLength;
            m_Eigenvector[index0] = p11 * wVector + p01 * wVectorCross;
        }
    }
    else
    {
        if (row == 0)
        {
            m_Eigenvector[index0] = wVectorCross;
        }
        else
        {
            m_Eigenvector[index0] = wVector;
        }
    }

    // V[i1] = Cross(V[i2],V[i0])
    m_Eigenvector[index1] = Vector3DTools::CrossProduct(m_Eigenvector[index2], m_Eigenvector[index0]);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::NoniterativeEigen3x3Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::NoniterativeEigen3x3Impl<Real>::GetEigenvalue(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Eigenvalue.at(index);
}

template <typename Real>
typename const Mathematics::NoniterativeEigen3x3Impl<Real>::Vector3D Mathematics::NoniterativeEigen3x3Impl<Real>::GetEigenvector(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Eigenvector.at(index);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_IMPL_DETAIL_H
