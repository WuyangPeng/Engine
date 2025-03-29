///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 10:20)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_DETAIL_H

#include "NoniterativeEigen3x3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::NoniterativeEigen3x3<Real>::NoniterativeEigen3x3(const Matrix3Type& matrix)
    : eigenvalue{}, eigenvector{}
{
    Compute(matrix);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Real Mathematics::NoniterativeEigen3x3<Real>::GetMaxValue(const Matrix3Type& matrix) const
{
    Container maxValue{ MathType::FAbs(matrix.template GetValue<0, 0>()),
                        MathType::FAbs(matrix.template GetValue<0, 1>()),
                        MathType::FAbs(matrix.template GetValue<0, 2>()),
                        MathType::FAbs(matrix.template GetValue<1, 1>()),
                        MathType::FAbs(matrix.template GetValue<1, 2>()),
                        MathType::FAbs(matrix.template GetValue<2, 2>()) };

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

template <typename Real>
void Mathematics::NoniterativeEigen3x3<Real>::Compute(const Matrix3Type& matrix)
{
    // 缩放矩阵，让它的条目都在[-1,1]。
    // 缩放应用于当至少一个矩阵条目具有大小大于1。

    Matrix3Type scaledEntry{ matrix };
    const auto maxValue = GetMaxValue(scaledEntry);

    if (MathType::GetValue(1) < maxValue)
    {
        scaledEntry /= maxValue;
    }

    // 计算特征值采用双精度运算。
    ComputeRoots(scaledEntry);

    EigenValueType maxEntry{};
    EigenVectorType maxRow{};
    for (auto i = 0; i < eigenMax; ++i)
    {
        Matrix3Type computeMatrix{ scaledEntry };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        computeMatrix(0, 0) -= eigenvalue[i];
        computeMatrix(1, 1) -= eigenvalue[i];
        computeMatrix(2, 2) -= eigenvalue[i];
        if (!PositiveRank(computeMatrix, maxEntry[i], maxRow[i]))

#include SYSTEM_WARNING_POP
        {
            // 重新缩放回原来的大小。
            RescaleBack(maxValue);

            eigenvector = EigenVectorType{ Vector3Type::GetUnitX(), Vector3Type::GetUnitY(), Vector3Type::GetUnitZ() };
            return;
        }
    }

#include SYSTEM_WARNING_PUSH
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

#include SYSTEM_WARNING_POP

    // 重新缩放回原来的大小。
    RescaleBack(maxValue);
}

template <typename Real>
void Mathematics::NoniterativeEigen3x3<Real>::RescaleBack(Real maxValue) noexcept
{
    if (MathType::GetValue(1) < maxValue)
    {
        for (auto& value : eigenvalue)
        {
            value *= maxValue;
        }
    }
}

template <typename Real>
void Mathematics::NoniterativeEigen3x3<Real>::ComputeRoots(const Matrix3Type& matrix)
{
    static const auto sqrt3Value = MathType::Sqrt(MathType::GetValue(3));

    // 转换的唯一的矩阵元素为双精度
    const auto a00 = matrix(0, 0);
    const auto a01 = matrix(0, 1);
    const auto a02 = matrix(0, 2);
    const auto a11 = matrix(1, 1);
    const auto a12 = matrix(1, 2);
    const auto a22 = matrix(2, 2);

    // 特征方程为x^3 - c2 * x^2 + c1 * x - c0 = 0。
    // 特征值是这个方程的根，保证都是实数值，因为矩阵是对称的。
    const auto c0 = a00 * a11 * a22 +
                    MathType::GetValue(2) * a01 * a02 * a12 -
                    a00 * a12 * a12 -
                    a11 * a02 * a02 -
                    a22 * a01 * a01;

    const auto c1 = a00 * a11 -
                    a01 * a01 +
                    a00 * a22 -
                    a02 * a02 +
                    a11 * a22 -
                    a12 * a12;

    const auto c2 = a00 + a11 + a22;

    // 构造参数使用在方程的根进行分类，并以闭合形式根部方程求解。
    const auto c2Divided3 = c2 * MathType::GetRational(1, 3);
    auto aDivided3 = (c1 - c2 * c2Divided3) * MathType::GetRational(1, 3);

    if (MathType::GetValue(0) < aDivided3)
    {
        aDivided3 = MathType::GetValue(0);
    }

    const auto halfMB = MathType::GetRational(1, 2) * (c0 + c2Divided3 * (MathType::GetValue(2) * c2Divided3 * c2Divided3 - c1));

    auto q = halfMB * halfMB + aDivided3 * aDivided3 * aDivided3;
    if (MathType::GetValue(0) < q)
    {
        q = MathType::GetValue(0);
    }

    // 通过求解该多项式的根，计算特征值。
    const auto magnitude = MathType::Sqrt(-aDivided3);
    const auto angle = MathType::ATan2(MathType::Sqrt(-q), halfMB) * MathType::GetRational(1, 3);
    const auto cosValue = MathType::Cos(angle);
    const auto sinValue = MathType::Sin(angle);
    const auto root0 = c2Divided3 + MathType::GetValue(2) * magnitude * cosValue;
    const auto root1 = c2Divided3 - magnitude * (cosValue + sqrt3Value * sinValue);
    const auto root2 = c2Divided3 - magnitude * (cosValue - sqrt3Value * sinValue);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 排序按升序排列。
    if (root0 <= root1)
    {
        eigenvalue[0] = root0;
        eigenvalue[1] = root1;
    }
    else
    {
        eigenvalue[0] = root1;
        eigenvalue[1] = root0;
    }

    if (eigenvalue[1] <= root2)
    {
        eigenvalue[2] = root2;
    }
    else
    {
        eigenvalue[2] = eigenvalue[1];
        if (eigenvalue[0] <= root2)
        {
            eigenvalue[1] = root2;
        }
        else
        {
            eigenvalue[1] = eigenvalue[0];
            eigenvalue[0] = root2;
        }
    }

#include SYSTEM_WARNING_POP
}

template <typename Real>
bool Mathematics::NoniterativeEigen3x3<Real>::PositiveRank(Matrix3Type& matrix, Real& maxEntry, Vector3Type& maxRow) const
{
    // 找到矩阵的最大幅度条目。
    maxEntry = MathType::GetValue(-1);

    auto maxRowIndex = -1;
    for (auto row = 0; row < eigenMax; ++row)
    {
        for (auto column = row; column < eigenMax; ++column)
        {
            auto absValue = MathType::FAbs(matrix(row, column));
            if (maxEntry < absValue)
            {
                maxEntry = absValue;
                maxRowIndex = row;
            }
        }
    }

    // 返回包含最大值的行，要用于特征向量构造。
    maxRow = Vector3{ matrix(maxRowIndex, 0), matrix(maxRowIndex, 1), matrix(maxRowIndex, 2) };

    return MathType::GetZeroTolerance() <= maxEntry;
}

template <typename Real>
void Mathematics::NoniterativeEigen3x3<Real>::ComputeVectors(const Matrix3Type& matrix, const Vector3Type& vector, int index0, int index1, int index2)
{
    const auto basis = Vector3ToolsType::GenerateComplementBasis(vector);
    const auto uVector = basis.GetUVector();
    const auto vVector = basis.GetVVector();
    const auto wVector = basis.GetWVector();

    // V[i2] = c0 * U0 + c1 * U1,  c0^2 + c1^2 = 1
    // e2 * V[i2] = c0 * A * U0 + c1 * A * U1
    // e2 * c0 = c0 * U0.Dot(A * U0) + c1 * U0.Dot(A * U1) = d00 * c0 + d01 * c1
    // e2 * c1 = c0 * U1.Dot(A * U0) + c1 * U1.Dot(A * U1) = d01 * c0 + d11 * c1
    const auto uVectorTransition = matrix * uVector;
    const auto vVectorTransition = matrix * vVector;

    auto p00 = eigenvalue.at(index2) - Vector3ToolsType::DotProduct(uVector, uVectorTransition);
    auto p01 = Vector3ToolsType::DotProduct(vVector, uVectorTransition);
    auto p11 = eigenvalue.at(index2) - Vector3ToolsType::DotProduct(vVector, vVectorTransition);

    auto maxValue = MathType::FAbs(p00);
    auto row = 0;
    auto absValue = MathType::FAbs(p01);
    if (maxValue < absValue)
    {
        maxValue = absValue;
    }
    absValue = MathType::FAbs(p11);
    if (maxValue < absValue)
    {
        maxValue = absValue;
        row = 1;
    }

    if (MathType::GetZeroTolerance() <= maxValue)
    {
        if (row == 0)
        {
            const auto invLength = MathType::InvSqrt(p00 * p00 + p01 * p01);
            p00 *= invLength;
            p01 *= invLength;
            eigenvector.at(index2) = p01 * uVector + p00 * vVector;
        }
        else
        {
            const auto invLength = MathType::InvSqrt(p11 * p11 + p01 * p01);
            p11 *= invLength;
            p01 *= invLength;
            eigenvector.at(index2) = p11 * uVector + p01 * vVector;
        }
    }
    else
    {
        if (row == 0)
        {
            eigenvector.at(index2) = vVector;
        }
        else
        {
            eigenvector.at(index2) = uVector;
        }
    }

    // V[i0] = c0 * U2 + c1 * Cross(U2,V[i2]) = c0 * Real + c1 * S
    // e0 * V[i0] = c0 * A * Real + c1 * A * S
    // e0 * c0 = c0 * Real.Dot(A * Real) + c1 * Real.Dot(A * S) = d00 * c0 + d01 * c1
    // e0 * c1 = c0 * S.Dot(A * Real) + c1 * S.Dot(A * S) = d01 * c0 + d11 * c1
    const auto wVectorCross = Vector3ToolsType::CrossProduct(wVector, eigenvector.at(index2));
    const auto wVectorTransition = matrix * wVector;

    p00 = eigenvalue.at(index0) - Vector3ToolsType::DotProduct(wVector, wVectorTransition);
    p01 = Vector3ToolsType::DotProduct(wVectorCross, wVectorTransition);
    p11 = eigenvalue.at(index0) - Vector3ToolsType::DotProduct(wVectorCross, matrix * wVectorCross);

    maxValue = MathType::FAbs(p00);
    row = 0;
    absValue = MathType::FAbs(p01);
    if (maxValue < absValue)
    {
        maxValue = absValue;
    }
    absValue = MathType::FAbs(p11);
    if (maxValue < absValue)
    {
        maxValue = absValue;
        row = 1;
    }

    if (MathType::GetZeroTolerance() <= maxValue)
    {
        if (row == 0)
        {
            const auto invLength = MathType::InvSqrt(p00 * p00 + p01 * p01);
            p00 *= invLength;
            p01 *= invLength;
            eigenvector.at(index0) = p01 * wVector + p00 * wVectorCross;
        }
        else
        {
            const auto invLength = MathType::InvSqrt(p11 * p11 + p01 * p01);
            p11 *= invLength;
            p01 *= invLength;
            eigenvector.at(index0) = p11 * wVector + p01 * wVectorCross;
        }
    }
    else
    {
        if (row == 0)
        {
            eigenvector.at(index0) = wVectorCross;
        }
        else
        {
            eigenvector.at(index0) = wVector;
        }
    }

    // V[i1] = Cross(V[i2],V[i0])
    eigenvector.at(index1) = Vector3ToolsType::CrossProduct(eigenvector.at(index2), eigenvector.at(index0));
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::NoniterativeEigen3x3<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::NoniterativeEigen3x3<Real>::GetEigenvalue(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return eigenvalue.at(index);
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::NoniterativeEigen3x3<Real>::GetEigenvector(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return eigenvector.at(index);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_DETAIL_H
