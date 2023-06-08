///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:52)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_DETAIL_H

#include "EigenDecomposition.h"
#include "SingularValueDecomposition.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

template <typename Real>
Mathematics::SingularValueDecomposition<Real>::SingularValueDecomposition(const VariableMatrix& matrix)
    : left{ matrix.GetRowsNumber(), matrix.GetRowsNumber() },
      diagonal{ matrix.GetRowsNumber(), matrix.GetColumnsNumber() },
      rightTranspose{ matrix.GetColumnsNumber(), matrix.GetColumnsNumber() }
{
    Calculate(matrix);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::SingularValueDecomposition<Real>::Calculate(const VariableMatrix& matrix)
{
    // 从“矩阵计算”实现其他QR分解和奇异值分解代码，然后给用户指定这里使用哪些方法的能力。

    const auto transposeTimesMatrix = TransposeTimes(matrix, matrix);
    EigenDecomposition<Real> eigenDecomposition{ transposeTimesMatrix };
    eigenDecomposition.Solve(false);
    const auto eigenvectors = eigenDecomposition.GetEigenvectors();

    diagonal = matrix * eigenvectors;
    HouseholderQR();
    rightTranspose = eigenvectors.Transpose();
}

template <typename Real>
void Mathematics::SingularValueDecomposition<Real>::HouseholderQR()
{
    using namespace System;

    // 矩阵Real是A的副本，然后在算法中用正确项重写上三角。
    const auto numRows = diagonal.GetRowsNumber();
    const auto numColumns = diagonal.GetColumnsNumber();
    MATHEMATICS_ASSERTION_3(numColumns <= numRows, "太多的列（使用转置矩阵）\n");

    std::vector<VariableLengthVector> saveVector{};
    for (auto column = 0; column < numColumns; ++column)
    {
        VariableLengthVector vector{ numRows };

        // 创建Householder向量对A的部分列
        for (auto row = 0; row < column; ++row)
        {
            vector[row] = Math::GetValue(0);
        }
        auto length = Math::GetValue(0);
        for (auto row = column; row < numRows; ++row)
        {
            vector[row] = diagonal[row][column];
            length += vector[row] * vector[row];
        }
        length = Math::Sqrt(length);
        auto beta = vector[column] + length * System::EnumCastUnderlying(Math::Sign(vector[column]));
        if (Math::GetZeroTolerance() < Math::FAbs(beta))
        {
            for (int i = column + 1; i < numRows; ++i)
            {
                vector[i] /= beta;
            }
        }
        vector[column] = Math::GetValue(1);

        // 由V-反射矩阵预乘A。
        HouseholderPremultiply(vector, diagonal);

        // 保存Householder向量
        saveVector.emplace_back(vector);
    }

    // 首先，使Q为identity。第二，提取Householder向量和以V-反射矩阵预乘Q。
    left.SetIdentity();

    for (auto column = numColumns - 1; 0 <= column; --column)
    {
        // 获取Householder向量

        auto vector = saveVector.at(column);

        // 由V-反射矩阵预乘Q。
        HouseholderPremultiply(vector, left);
    }
}

// static
template <typename Real>
typename Mathematics::SingularValueDecomposition<Real>::VariableLengthVector Mathematics::SingularValueDecomposition<Real>::HouseholderVector(const VariableLengthVector& vector)
{
    using namespace System;
    using System::operator*;

    auto householderVector = vector;
    auto length = householderVector.Length();
    auto beta = vector[0] + length * Math::Sign(vector[0]);
    if (Math::GetZeroTolerance() < Math::FAbs(beta))
    {
        for (auto i = 1; i < householderVector.GetSize(); ++i)
        {
            householderVector[i] /= beta;
        }
    }

    householderVector[0] = Math::GetValue(1);

    return householderVector;
}

// static
template <typename Real>
void Mathematics::SingularValueDecomposition<Real>::HouseholderPremultiply(const VariableLengthVector& vector, VariableMatrix& matrix)
{
    const auto transitionVector = vector * matrix;
    const auto wVector = (Math::GetValue(-2) / vector.SquaredLength()) * transitionVector;
    const auto numRows = matrix.GetRowsNumber();
    const auto numColumns = matrix.GetColumnsNumber();
    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numColumns; ++col)
        {
            matrix[row][col] += vector[row] * wVector[col];
        }
    }
}

// static
template <typename Real>
void Mathematics::SingularValueDecomposition<Real>::HouseholderPostmultiply(const VariableLengthVector& vector, VariableMatrix& matrix)
{
    const auto transitionVector = (Math::GetValue(-2) / vector.SquaredLength()) * (matrix * vector);
    const auto numRows = matrix.GetRowsNumber();
    const auto numColumns = matrix.GetColumnsNumber();
    for (auto row = 0; row < numRows; ++row)
    {
        for (auto col = 0; col < numColumns; ++col)
        {
            (matrix)[row][col] += transitionVector[row] * vector[col];
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::SingularValueDecomposition<Real>::IsValid() const noexcept
{
    try
    {
        if (diagonal.GetColumnsNumber() <= diagonal.GetRowsNumber())
            return true;
        else
            return false;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::SingularValueDecomposition<Real>::VariableMatrix Mathematics::SingularValueDecomposition<Real>::GetLeftMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return left;
}

template <typename Real>
typename Mathematics::SingularValueDecomposition<Real>::VariableMatrix Mathematics::SingularValueDecomposition<Real>::GetDiagonalMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return diagonal;
}

template <typename Real>
typename Mathematics::SingularValueDecomposition<Real>::VariableMatrix Mathematics::SingularValueDecomposition<Real>::GetRightTransposeMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rightTranspose;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_DETAIL_H
