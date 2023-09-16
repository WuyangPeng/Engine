///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_DETAIL_H

#include "EigenDecomposition.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

template <typename Real>
Mathematics::EigenDecomposition<Real>::EigenDecomposition(int size)
    : size{ size },
      matrix{ size, size },
      solveMatrix{ size, size },
      diagonal(size),
      subdiagonal(size),
      isRotation{ false },
      solve{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>::EigenDecomposition(const Matrix2& rhs)
    : size{ Matrix2::vectorSize },
      matrix{ rhs },
      solveMatrix{ rhs },
      diagonal(size),
      subdiagonal(size),
      isRotation{ false },
      solve{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>::EigenDecomposition(const Matrix3& rhs)
    : size{ Matrix3::vectorSize },
      matrix{ rhs },
      solveMatrix{ rhs },
      diagonal(size),
      subdiagonal(size),
      isRotation{ false },
      solve{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>::EigenDecomposition(const VariableMatrix& rhs)
    : size{ rhs.GetRowsNumber() },
      matrix{ rhs },
      solveMatrix{ rhs },
      diagonal(size),
      subdiagonal(size),
      isRotation{ false },
      solve{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::Swap(EigenDecomposition& rhs) noexcept
{
    std::swap(size, rhs.size);
    std::swap(matrix, rhs.matrix);
    std::swap(solveMatrix, rhs.solveMatrix);
    std::swap(diagonal, rhs.diagonal);
    std::swap(subdiagonal, rhs.subdiagonal);
    std::swap(isRotation, rhs.isRotation);
    std::swap(solve, rhs.solve);
}

template <typename Real>
Mathematics::EigenDecomposition<Real>& Mathematics::EigenDecomposition<Real>::operator=(const Matrix2& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    EigenDecomposition result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>& Mathematics::EigenDecomposition<Real>::operator=(const Matrix3& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    EigenDecomposition result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>& Mathematics::EigenDecomposition<Real>::operator=(const VariableMatrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    EigenDecomposition result{ rhs };

    Swap(result);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::EigenDecomposition<Real>::IsValid() const noexcept
{
    try
    {
        if (Matrix2::vectorSize <= size &&
            matrix.GetColumnsNumber() == matrix.GetRowsNumber() &&
            solveMatrix.GetColumnsNumber() == solveMatrix.GetRowsNumber() &&
            matrix.GetColumnsNumber() == solveMatrix.GetColumnsNumber())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::EigenDecomposition<Real>::GetSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return size;
}

template <typename Real>
const Real& Mathematics::EigenDecomposition<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return matrix(row, column);
}

template <typename Real>
Real& Mathematics::EigenDecomposition<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const EigenDecomposition&>(*this)(row, column));

#include SYSTEM_WARNING_POP
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::Solve(bool increasingSort)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    solve = false;

    switch (size)
    {
        case Matrix2::vectorSize:
            Tridiagonal2();
            break;
        case Matrix3::vectorSize:
            Tridiagonal3();
            break;
        default:
            TridiagonalN();
            break;
    }

    QLAlgorithm();

    if (increasingSort)
    {
        IncreasingSort();
    }
    else
    {
        DecreasingSort();
    }

    GuaranteeRotation();

    solve = true;
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>::Tridiagonal2()
{
    // 该矩阵是已经是三对角矩阵。

    diagonal.at(0) = matrix(0, 0);
    diagonal.at(1) = matrix(1, 1);
    subdiagonal.at(0) = matrix(0, 1);
    subdiagonal.at(1) = Math::GetValue(0);

    solveMatrix.SetIdentity();

    isRotation = true;
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>::Tridiagonal3()
{
    auto m00 = matrix(0, 0);
    auto m01 = matrix(0, 1);
    auto m02 = matrix(0, 2);
    auto m11 = matrix(1, 1);
    auto m12 = matrix(1, 2);
    auto m22 = matrix(2, 2);

    diagonal.at(0) = m00;
    subdiagonal.at(2) = Math::GetValue(0);
    if (Math::GetZeroTolerance() < Math::FAbs(m02))
    {
        const auto length = Math::Sqrt(m01 * m01 + m02 * m02);
        m01 /= length;
        m02 /= length;
        const auto q = Math::GetValue(2) * m01 * m12 + m02 * (m22 - m11);
        diagonal.at(1) = m11 + m02 * q;
        diagonal.at(2) = m22 - m02 * q;
        subdiagonal.at(0) = length;
        subdiagonal.at(1) = m12 - m01 * q;
        solveMatrix(0, 0) = Math::GetValue(1);
        solveMatrix(0, 1) = Math::GetValue(0);
        solveMatrix(0, 2) = Math::GetValue(0);
        solveMatrix(1, 0) = Math::GetValue(0);
        solveMatrix(1, 1) = m01;
        solveMatrix(1, 2) = m02;
        solveMatrix(2, 0) = Math::GetValue(0);
        solveMatrix(2, 1) = m02;
        solveMatrix(2, 2) = -m01;

        isRotation = false;
    }
    else
    {
        diagonal.at(1) = m11;
        diagonal.at(2) = m22;
        subdiagonal.at(0) = m01;
        subdiagonal.at(1) = m12;
        solveMatrix.SetIdentity();

        isRotation = true;
    }
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>::TridiagonalN()
{
    solveMatrix = matrix;

    Step1();
    Step2();
    Step3();

    isRotation = ((size % 2) == 0);
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>::Step1()
{
    for (auto index = size - 1; 1 <= index; --index)
    {
        if (1 < index)
        {
            TridiagonalNInLoop(index);
        }
        else
        {
            subdiagonal.at(index) = solveMatrix(index, index - 1);
            diagonal.at(index) = Math::GetValue(0);
        }
    }
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>::TridiagonalNInLoop(int index)
{
    auto scale = GetScale(index);

    if (Math::FAbs(scale) <= Math::GetZeroTolerance())
    {
        subdiagonal.at(index) = solveMatrix(index, index - 1);
        diagonal.at(index) = Math::GetValue(0);
    }
    else
    {
        CalculateDiagonal(index, scale);
        CalculateSubdiagonal(index);
    }
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::CalculateDiagonal(int index, Real scale)
{
    Real diagonaValue{};

    for (auto diagonaIndex = 0; diagonaIndex <= index - 1; ++diagonaIndex)
    {
        solveMatrix(index, diagonaIndex) /= scale;
        diagonaValue += solveMatrix(index, diagonaIndex) * solveMatrix(index, diagonaIndex);
    }

    auto solveMatrixValue = solveMatrix(index, index - 1);
    auto diagonaValueSqrt = Math::Sqrt(diagonaValue);
    if (Math::GetValue(0) < solveMatrixValue)
    {
        diagonaValueSqrt = -diagonaValueSqrt;
    }

    subdiagonal.at(index) = scale * diagonaValueSqrt;
    diagonaValue -= solveMatrixValue * diagonaValueSqrt;
    solveMatrix(index, index - 1) = solveMatrixValue - diagonaValueSqrt;

    diagonal.at(index) = diagonaValue;
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::CalculateSubdiagonal(int index)
{
    const auto diagonaValue = diagonal.at(index);
    Real subdiagonalProduct{};

    for (int outerIndex = 0; outerIndex <= index - 1; ++outerIndex)
    {
        solveMatrix(outerIndex, index) = solveMatrix(index, outerIndex) / diagonaValue;
        Real solveMatrixProduct{};
        for (auto innerIndex = 0; innerIndex <= outerIndex; ++innerIndex)
        {
            solveMatrixProduct += solveMatrix(outerIndex, innerIndex) * solveMatrix(index, innerIndex);
        }

        for (auto innerIndex = outerIndex + 1; innerIndex <= index - 1; ++innerIndex)
        {
            solveMatrixProduct += solveMatrix(innerIndex, outerIndex) * solveMatrix(index, innerIndex);
        }

        subdiagonal.at(outerIndex) = solveMatrixProduct / diagonaValue;
        subdiagonalProduct += subdiagonal.at(outerIndex) * solveMatrix(index, outerIndex);
    }

    const auto value = Math::GetRational(1, 2) * subdiagonalProduct / diagonaValue;
    for (auto outerIndex = 0; outerIndex <= index - 1; ++outerIndex)
    {
        const auto solveMatrixValue = solveMatrix(index, outerIndex);
        const auto subdiagonalValue = subdiagonal.at(outerIndex) - value * solveMatrixValue;
        subdiagonal.at(outerIndex) = subdiagonalValue;
        for (auto innerIndex = 0; innerIndex <= outerIndex; innerIndex++)
        {
            solveMatrix(outerIndex, innerIndex) -= solveMatrixValue * subdiagonal.at(innerIndex) + subdiagonalValue * solveMatrix(index, innerIndex);
        }
    }
}

// private
template <typename Real>
Real Mathematics::EigenDecomposition<Real>::GetScale(int index) const
{
    Real scale{};

    for (auto scaleIndex = 0; scaleIndex <= index - 1; ++scaleIndex)
    {
        scale += Math::FAbs(solveMatrix(index, scaleIndex));
    }

    return scale;
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>::Step2()
{
    diagonal.at(0) = Math::GetValue(0);
    subdiagonal.at(0) = Math::GetValue(0);
    for (auto index = 0; index <= size - 1; ++index)
    {
        if (Math::GetZeroTolerance() < Math::FAbs(diagonal.at(index)))
        {
            for (auto outerIndex = 0; outerIndex <= index - 1; ++outerIndex)
            {
                Real sum{};

                for (auto innerIndex = 0; innerIndex <= index - 1; ++innerIndex)
                {
                    sum += solveMatrix(index, innerIndex) * solveMatrix(innerIndex, outerIndex);
                }
                for (auto innerIndex = 0; innerIndex <= index - 1; ++innerIndex)
                {
                    solveMatrix(innerIndex, outerIndex) -= sum * solveMatrix(innerIndex, index);
                }
            }
        }
        diagonal.at(index) = solveMatrix[index][index];
        solveMatrix[index][index] = Math::GetValue(1);
        for (auto innerIndex = 0; innerIndex <= index - 1; ++innerIndex)
        {
            solveMatrix(innerIndex, index) = Math::GetValue(0);
            solveMatrix(index, innerIndex) = Math::GetValue(0);
        }
    }
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>::Step3()
{
    // 重新排序需要在EigenDecomposition::QLAlgorithm。

    for (auto index = 1; index < size; ++index)
    {
        const auto indexMinus1 = index - 1;
        subdiagonal.at(indexMinus1) = subdiagonal.at(index);
    }
    const auto sizeMinus1 = size - 1;
    subdiagonal.at(sizeMinus1) = Math::GetValue(0);
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>::QLAlgorithm()
{
    for (auto index = 0; index < size; ++index)
    {
        QLAlgorithm(index);
    }
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>::QLAlgorithm(int index)
{
    const auto loopTime = QLAlgorithmWithLoopTime(index);

    if (maxIter <= loopTime)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("循环超出次数。"s));
    }
}

template <typename Real>
int Mathematics::EigenDecomposition<Real>::QLAlgorithmWithLoopTime(int totalIndex)
{
    for (auto loopTime = 0; loopTime < maxIter; ++loopTime)
    {
        auto outerIndex = totalIndex;
        for (; outerIndex <= size - 2; ++outerIndex)
        {
            if (IsQLAlgorithmQuit(outerIndex))
            {
                break;
            }
        }
        if (outerIndex == totalIndex)
        {
            return loopTime;
        }

        QLAlgorithmLoop(totalIndex, outerIndex);
    }

    return maxIter;
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>::QLAlgorithmLoop(int totalIndex, int outerIndex)
{
    auto subdiagonalValue = GetQLAlgorithmSubdiagonalValue(totalIndex, outerIndex);
    auto sine = Math::GetValue(1);
    auto cosine = Math::GetValue(1);
    auto diagonalDifferenceValue = Math::GetValue(0);

    for (auto innerIndex = outerIndex - 1; innerIndex >= totalIndex; --innerIndex)
    {
        auto subdiagonalSineValue = sine * subdiagonal.at(innerIndex);
        auto subdiagonalCosineValue = cosine * subdiagonal.at(innerIndex);

        if (Math::FAbs(subdiagonalValue) <= Math::FAbs(subdiagonalSineValue))
        {
            cosine = subdiagonalValue / subdiagonalSineValue;
            const auto cosineAmend = Math::Sqrt(cosine * cosine + Math::GetValue(1));
            const auto innerNextIndex = innerIndex + 1;
            subdiagonal.at(innerNextIndex) = subdiagonalSineValue * cosineAmend;
            sine = Math::GetValue(1) / cosineAmend;
            cosine *= sine;
        }
        else
        {
            sine = subdiagonalSineValue / subdiagonalValue;
            const auto cosineAmend = Math::Sqrt(sine * sine + Math::GetValue(1));
            const auto innerNextIndex = innerIndex + 1;
            subdiagonal.at(innerNextIndex) = subdiagonalValue * cosineAmend;
            cosine = Math::GetValue(1) / cosineAmend;
            sine *= cosine;
        }
        const auto innerNextIndex = innerIndex + 1;
        subdiagonalValue = diagonal.at(innerNextIndex) - diagonalDifferenceValue;
        const auto value = (diagonal.at(innerIndex) - subdiagonalValue) * sine + Math::GetValue(2) * subdiagonalCosineValue * cosine;
        diagonalDifferenceValue = sine * value;
        diagonal.at(innerNextIndex) = subdiagonalValue + diagonalDifferenceValue;
        subdiagonalValue = cosine * value - subdiagonalCosineValue;

        QLAlgorithmAmendSolveMatrix(innerIndex, sine, cosine);
    }

    diagonal.at(totalIndex) -= diagonalDifferenceValue;
    subdiagonal.at(totalIndex) = subdiagonalValue;
    subdiagonal.at(outerIndex) = Math::GetValue(0);
}

// private
template <typename Real>
Real Mathematics::EigenDecomposition<Real>::GetQLAlgorithmSubdiagonalValue(int totalIndex, int outerIndex) const
{
    const auto totalIndexPlusOne = totalIndex + 1;
    const auto value = (diagonal.at(totalIndexPlusOne) - diagonal.at(totalIndex)) / (Math::GetValue(2) * subdiagonal.at(totalIndex));

    const auto amendValue = Math::Sqrt(value * value + Math::GetValue(1));
    if (value < Math::GetValue(0))
    {
        return diagonal.at(outerIndex) - diagonal.at(totalIndex) + subdiagonal.at(totalIndex) / (value - amendValue);
    }
    else
    {
        return diagonal.at(outerIndex) - diagonal.at(totalIndex) + subdiagonal.at(totalIndex) / (value + amendValue);
    }
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>::QLAlgorithmAmendSolveMatrix(int innerIndex, Real sine, Real cosine)
{
    for (auto i = 0; i < size; ++i)
    {
        const auto value = solveMatrix(i, innerIndex + 1);

        solveMatrix(i, innerIndex + 1) = sine * solveMatrix(i, innerIndex) + cosine * value;
        solveMatrix(i, innerIndex) = cosine * solveMatrix(i, innerIndex) - sine * value;
    }
}

// private
template <typename Real>
bool Mathematics::EigenDecomposition<Real>::IsQLAlgorithmQuit(int outerIndex) const
{
    const auto outerNextIndex = outerIndex + 1;
    const auto diagonalSum = Math::FAbs(diagonal.at(outerIndex)) + Math::FAbs(diagonal.at(outerNextIndex));

    if (Math::FAbs(Math::FAbs(subdiagonal.at(outerIndex)) + diagonalSum - diagonalSum) <= Math::GetZeroTolerance())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>::DecreasingSort()
{
    // 排序特征值按递减顺序，e[0] >= ... >= e[mSize-1]
    for (auto outerIndex = 0; outerIndex <= size - 2; ++outerIndex)
    {
        // 找到最大特征值。
        auto minIndex = outerIndex;
        auto maxValue = diagonal.at(minIndex);

        for (auto innerIndex = outerIndex + 1; innerIndex < size; ++innerIndex)
        {
            if (maxValue < diagonal.at(innerIndex))
            {
                minIndex = innerIndex;
                maxValue = diagonal.at(minIndex);
            }
        }

        if (minIndex != outerIndex)
        {
            // 交换的特征值。
            diagonal.at(minIndex) = diagonal.at(outerIndex);
            diagonal.at(outerIndex) = maxValue;

            // 交换对应于特征值的特征向量。
            for (auto innerIndex = 0; innerIndex < size; ++innerIndex)
            {
                std::swap(solveMatrix(innerIndex, outerIndex), solveMatrix(innerIndex, minIndex));

                isRotation = !isRotation;
            }
        }
    }
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>::IncreasingSort()
{
    // 排序特征值按递增顺序， e[0] <= ... <= e[mSize-1]
    for (auto outerIndex = 0; outerIndex <= size - 2; ++outerIndex)
    {  // 找到最小特征值。
        auto minIndex = outerIndex;
        auto minValue = diagonal.at(minIndex);

        for (auto innerIndex = outerIndex + 1; innerIndex < size; ++innerIndex)
        {
            if (diagonal.at(innerIndex) < minValue)
            {
                minIndex = innerIndex;
                minValue = diagonal.at(minIndex);
            }
        }

        if (minIndex != outerIndex)
        {
            // 交换特征值。
            diagonal.at(minIndex) = diagonal.at(outerIndex);
            diagonal.at(outerIndex) = minValue;

            // 交换对应于特征值的特征向量。
            for (auto innerIndex = 0; innerIndex < size; ++innerIndex)
            {
                std::swap(solveMatrix(innerIndex, outerIndex), solveMatrix(innerIndex, minIndex));

                isRotation = !isRotation;
            }
        }
    }
}

// private
template <typename Real>
void Mathematics::EigenDecomposition<Real>::GuaranteeRotation()
{
    if (!isRotation)
    {
        // 改变符号在第一列中。
        for (auto row = 0; row < size; ++row)
        {
            solveMatrix(row, 0) = -solveMatrix(row, 0);
        }
    }
}

template <typename Real>
Real Mathematics::EigenDecomposition<Real>::GetEigenvalue(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(solve, "未解析！");

    return diagonal.at(index);
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::EigenDecomposition<Real>::GetEigenvector2(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(solve, "未解析！");
    MATHEMATICS_ASSERTION_1(0 <= index && index < size, "无效索引在GetEigenvector2\n");
    MATHEMATICS_ASSERTION_1(size == Matrix2::vectorSize, "维度不匹配在GetEigenvector2\n");

    Vector2 eigenvector{};
    for (auto row = 0; row < size; ++row)
    {
        eigenvector[row] = solveMatrix(row, index);
    }

    return eigenvector;
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::EigenDecomposition<Real>::GetEigenvectors2() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(solve, "未解析！");
    MATHEMATICS_ASSERTION_1(size == Matrix2::vectorSize, "维度不匹配在GetEigenvector2\n");

    Matrix2 eigenvectors{};
    for (auto row = 0; row < Matrix2::vectorSize; ++row)
    {
        for (auto column = 0; column < Vector2::pointSize; ++column)
        {
            eigenvectors(row, column) = solveMatrix(row, column);
        }
    }

    return eigenvectors;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::EigenDecomposition<Real>::GetEigenvector3(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(solve, "未解析！");
    MATHEMATICS_ASSERTION_1(0 <= index && index < size, "无效索引在GetEigenvector3\n");
    MATHEMATICS_ASSERTION_1(size == Matrix3::vectorSize, "维度不匹配在GetEigenvector3\n");

    Vector3 eigenvector{};
    for (auto row = 0; row < size; ++row)
    {
        eigenvector[row] = solveMatrix(row, index);
    }

    return eigenvector;
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::EigenDecomposition<Real>::GetEigenvectors3() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(solve, "未解析！");
    MATHEMATICS_ASSERTION_1(size == Matrix3::vectorSize, "维度不匹配在GetEigenvector3\n");

    return solveMatrix.GetMatrix3();
}

template <typename Real>
Mathematics::VariableLengthVector<Real> Mathematics::EigenDecomposition<Real>::GetEigenvector(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(solve, "未解析！");
    MATHEMATICS_ASSERTION_1(0 <= index && index < size, "无效索引在GetEigenvector3\n");

    return solveMatrix.GetColumn(index);
}

template <typename Real>
Mathematics::VariableMatrix<Real> Mathematics::EigenDecomposition<Real>::GetEigenvectors() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(solve, "未解析！");

    return solveMatrix;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_DETAIL_H
