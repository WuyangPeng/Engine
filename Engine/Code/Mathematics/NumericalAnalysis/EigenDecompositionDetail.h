///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 09:54)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_DETAIL_H

#include "EigenDecomposition.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
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
Mathematics::EigenDecomposition<Real>::EigenDecomposition(const Matrix2Type& rhs)
    : size{ Matrix2Type::vectorSize },
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
Mathematics::EigenDecomposition<Real>::EigenDecomposition(const Matrix3Type& rhs)
    : size{ Matrix3Type::vectorSize },
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
Mathematics::EigenDecomposition<Real>::EigenDecomposition(const VariableMatrixType& rhs)
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
Mathematics::EigenDecomposition<Real>& Mathematics::EigenDecomposition<Real>::operator=(const Matrix2Type& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    EigenDecomposition result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>& Mathematics::EigenDecomposition<Real>::operator=(const Matrix3Type& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    EigenDecomposition result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>& Mathematics::EigenDecomposition<Real>::operator=(const VariableMatrixType& rhs)
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
        if (Matrix2Type::vectorSize <= size &&
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
        case Matrix2Type::vectorSize:
            Tridiagonal2();
            break;
        case Matrix3Type::vectorSize:
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

template <typename Real>
void Mathematics::EigenDecomposition<Real>::Tridiagonal2()
{
    // �þ������Ѿ������ԽǾ���

    diagonal.at(0) = matrix(0, 0);
    diagonal.at(1) = matrix(1, 1);
    subdiagonal.at(0) = matrix(0, 1);
    subdiagonal.at(1) = MathType::GetValue(0);

    solveMatrix.MakeIdentity();

    isRotation = true;
}

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
    subdiagonal.at(2) = MathType::GetValue(0);
    if (MathType::GetZeroTolerance() < MathType::FAbs(m02))
    {
        const auto length = MathType::Sqrt(m01 * m01 + m02 * m02);
        m01 /= length;
        m02 /= length;
        const auto q = MathType::GetValue(2) * m01 * m12 + m02 * (m22 - m11);
        diagonal.at(1) = m11 + m02 * q;
        diagonal.at(2) = m22 - m02 * q;
        subdiagonal.at(0) = length;
        subdiagonal.at(1) = m12 - m01 * q;
        solveMatrix(0, 0) = MathType::GetValue(1);
        solveMatrix(0, 1) = MathType::GetValue(0);
        solveMatrix(0, 2) = MathType::GetValue(0);
        solveMatrix(1, 0) = MathType::GetValue(0);
        solveMatrix(1, 1) = m01;
        solveMatrix(1, 2) = m02;
        solveMatrix(2, 0) = MathType::GetValue(0);
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
        solveMatrix.MakeIdentity();

        isRotation = true;
    }
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::TridiagonalN()
{
    solveMatrix = matrix;

    Step1();
    Step2();
    Step3();

    isRotation = ((size % 2) == 0);
}

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
            diagonal.at(index) = MathType::GetValue(0);
        }
    }
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::TridiagonalNInLoop(int index)
{
    auto scale = GetScale(index);

    if (MathType::FAbs(scale) <= MathType::GetZeroTolerance())
    {
        subdiagonal.at(index) = solveMatrix(index, index - 1);
        diagonal.at(index) = MathType::GetValue(0);
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
    Real diagonalValue{};

    for (auto diagonalIndex = 0; diagonalIndex <= index - 1; ++diagonalIndex)
    {
        solveMatrix(index, diagonalIndex) /= scale;
        diagonalValue += solveMatrix(index, diagonalIndex) * solveMatrix(index, diagonalIndex);
    }

    auto solveMatrixValue = solveMatrix(index, index - 1);
    auto diagonalValueSqrt = MathType::Sqrt(diagonalValue);
    if (MathType::GetValue(0) < solveMatrixValue)
    {
        diagonalValueSqrt = -diagonalValueSqrt;
    }

    subdiagonal.at(index) = scale * diagonalValueSqrt;
    diagonalValue -= solveMatrixValue * diagonalValueSqrt;
    solveMatrix(index, index - 1) = solveMatrixValue - diagonalValueSqrt;

    diagonal.at(index) = diagonalValue;
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::CalculateSubdiagonal(int index)
{
    const auto diagonalValue = diagonal.at(index);
    Real subDiagonalProduct{};

    for (int outerIndex = 0; outerIndex <= index - 1; ++outerIndex)
    {
        solveMatrix(outerIndex, index) = solveMatrix(index, outerIndex) / diagonalValue;
        Real solveMatrixProduct{};
        for (auto innerIndex = 0; innerIndex <= outerIndex; ++innerIndex)
        {
            solveMatrixProduct += solveMatrix(outerIndex, innerIndex) * solveMatrix(index, innerIndex);
        }

        for (auto innerIndex = outerIndex + 1; innerIndex <= index - 1; ++innerIndex)
        {
            solveMatrixProduct += solveMatrix(innerIndex, outerIndex) * solveMatrix(index, innerIndex);
        }

        subdiagonal.at(outerIndex) = solveMatrixProduct / diagonalValue;
        subDiagonalProduct += subdiagonal.at(outerIndex) * solveMatrix(index, outerIndex);
    }

    const auto value = MathType::GetRational(1, 2) * subDiagonalProduct / diagonalValue;
    for (auto outerIndex = 0; outerIndex <= index - 1; ++outerIndex)
    {
        const auto solveMatrixValue = solveMatrix(index, outerIndex);
        const auto subDiagonalValue = subdiagonal.at(outerIndex) - value * solveMatrixValue;
        subdiagonal.at(outerIndex) = subDiagonalValue;
        for (auto innerIndex = 0; innerIndex <= outerIndex; innerIndex++)
        {
            solveMatrix(outerIndex, innerIndex) -= solveMatrixValue * subdiagonal.at(innerIndex) + subDiagonalValue * solveMatrix(index, innerIndex);
        }
    }
}

template <typename Real>
Real Mathematics::EigenDecomposition<Real>::GetScale(int index) const
{
    Real scale{};

    for (auto scaleIndex = 0; scaleIndex <= index - 1; ++scaleIndex)
    {
        scale += MathType::FAbs(solveMatrix(index, scaleIndex));
    }

    return scale;
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::Step2()
{
    diagonal.at(0) = MathType::GetValue(0);
    subdiagonal.at(0) = MathType::GetValue(0);
    for (auto index = 0; index <= size - 1; ++index)
    {
        if (MathType::GetZeroTolerance() < MathType::FAbs(diagonal.at(index)))
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
        diagonal.at(index) = solveMatrix(index, index);
        solveMatrix(index, index) = MathType::GetValue(1);
        for (auto innerIndex = 0; innerIndex <= index - 1; ++innerIndex)
        {
            solveMatrix(innerIndex, index) = MathType::GetValue(0);
            solveMatrix(index, innerIndex) = MathType::GetValue(0);
        }
    }
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::Step3()
{
    // ����������Ҫ��EigenDecomposition::QLAlgorithm��

    for (auto index = 1; index < size; ++index)
    {
        const auto indexMinus1 = index - 1;
        subdiagonal.at(indexMinus1) = subdiagonal.at(index);
    }
    const auto sizeMinus1 = size - 1;
    subdiagonal.at(sizeMinus1) = MathType::GetValue(0);
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::QLAlgorithm()
{
    for (auto index = 0; index < size; ++index)
    {
        QLAlgorithm(index);
    }
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::QLAlgorithm(int index)
{
    if (const auto loopTime = QLAlgorithmWithLoopTime(index);
        maxIter <= loopTime)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("ѭ������������"s));
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

template <typename Real>
void Mathematics::EigenDecomposition<Real>::QLAlgorithmLoop(int totalIndex, int outerIndex)
{
    auto subDiagonalValue = GetQLAlgorithmSubDiagonalValue(totalIndex, outerIndex);
    auto sine = MathType::GetValue(1);
    auto cosine = MathType::GetValue(1);
    auto diagonalDifferenceValue = MathType::GetValue(0);

    for (auto innerIndex = outerIndex - 1; innerIndex >= totalIndex; --innerIndex)
    {
        auto subDiagonalSineValue = sine * subdiagonal.at(innerIndex);
        auto subDiagonalCosineValue = cosine * subdiagonal.at(innerIndex);

        if (MathType::FAbs(subDiagonalValue) <= MathType::FAbs(subDiagonalSineValue))
        {
            cosine = subDiagonalValue / subDiagonalSineValue;
            const auto cosineAmend = MathType::Sqrt(cosine * cosine + MathType::GetValue(1));
            const auto innerNextIndex = innerIndex + 1;
            subdiagonal.at(innerNextIndex) = subDiagonalSineValue * cosineAmend;
            sine = MathType::GetValue(1) / cosineAmend;
            cosine *= sine;
        }
        else
        {
            sine = subDiagonalSineValue / subDiagonalValue;
            const auto cosineAmend = MathType::Sqrt(sine * sine + MathType::GetValue(1));
            const auto innerNextIndex = innerIndex + 1;
            subdiagonal.at(innerNextIndex) = subDiagonalValue * cosineAmend;
            cosine = MathType::GetValue(1) / cosineAmend;
            sine *= cosine;
        }
        const auto innerNextIndex = innerIndex + 1;
        subDiagonalValue = diagonal.at(innerNextIndex) - diagonalDifferenceValue;
        const auto value = (diagonal.at(innerIndex) - subDiagonalValue) * sine + MathType::GetValue(2) * subDiagonalCosineValue * cosine;
        diagonalDifferenceValue = sine * value;
        diagonal.at(innerNextIndex) = subDiagonalValue + diagonalDifferenceValue;
        subDiagonalValue = cosine * value - subDiagonalCosineValue;

        QLAlgorithmAmendSolveMatrix(innerIndex, sine, cosine);
    }

    diagonal.at(totalIndex) -= diagonalDifferenceValue;
    subdiagonal.at(totalIndex) = subDiagonalValue;
    subdiagonal.at(outerIndex) = MathType::GetValue(0);
}

template <typename Real>
Real Mathematics::EigenDecomposition<Real>::GetQLAlgorithmSubDiagonalValue(int totalIndex, int outerIndex) const
{
    const auto totalIndexPlusOne = totalIndex + 1;
    const auto value = (diagonal.at(totalIndexPlusOne) - diagonal.at(totalIndex)) / (MathType::GetValue(2) * subdiagonal.at(totalIndex));

    const auto amendValue = MathType::Sqrt(value * value + MathType::GetValue(1));
    if (value < MathType::GetValue(0))
    {
        return diagonal.at(outerIndex) - diagonal.at(totalIndex) + subdiagonal.at(totalIndex) / (value - amendValue);
    }
    else
    {
        return diagonal.at(outerIndex) - diagonal.at(totalIndex) + subdiagonal.at(totalIndex) / (value + amendValue);
    }
}

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

template <typename Real>
bool Mathematics::EigenDecomposition<Real>::IsQLAlgorithmQuit(int outerIndex) const
{
    const auto outerNextIndex = outerIndex + 1;
    const auto diagonalSum = MathType::FAbs(diagonal.at(outerIndex)) + MathType::FAbs(diagonal.at(outerNextIndex));

    if (MathType::FAbs(MathType::FAbs(subdiagonal.at(outerIndex)) + diagonalSum - diagonalSum) <= MathType::GetZeroTolerance())
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::DecreasingSort()
{
    // ��������ֵ���ݼ�˳��e[0] >= ... >= e[mSize-1]
    for (auto outerIndex = 0; outerIndex <= size - 2; ++outerIndex)
    {
        // �ҵ��������ֵ��
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
            // ����������ֵ��
            diagonal.at(minIndex) = diagonal.at(outerIndex);
            diagonal.at(outerIndex) = maxValue;

            // ������Ӧ������ֵ������������
            for (auto innerIndex = 0; innerIndex < size; ++innerIndex)
            {
                std::swap(solveMatrix(innerIndex, outerIndex), solveMatrix(innerIndex, minIndex));

                isRotation = !isRotation;
            }
        }
    }
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::IncreasingSort()
{
    // ��������ֵ������˳�� e[0] <= ... <= e[mSize-1]
    for (auto outerIndex = 0; outerIndex <= size - 2; ++outerIndex)
    {  // �ҵ���С����ֵ��
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
            // ��������ֵ��
            diagonal.at(minIndex) = diagonal.at(outerIndex);
            diagonal.at(outerIndex) = minValue;

            // ������Ӧ������ֵ������������
            for (auto innerIndex = 0; innerIndex < size; ++innerIndex)
            {
                std::swap(solveMatrix(innerIndex, outerIndex), solveMatrix(innerIndex, minIndex));

                isRotation = !isRotation;
            }
        }
    }
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::GuaranteeRotation()
{
    if (!isRotation)
    {
        // �ı�����ڵ�һ���С�
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
    MATHEMATICS_ASSERTION_0(solve, "δ������");

    return diagonal.at(index);
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::EigenDecomposition<Real>::GetEigenvector2(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(solve, "δ������");
    MATHEMATICS_ASSERTION_1(0 <= index && index < size, "��Ч������GetEigenvector2\n");
    MATHEMATICS_ASSERTION_1(size == Matrix2Type::vectorSize, "ά�Ȳ�ƥ����GetEigenvector2\n");

    Vector2Type eigenVector{};
    for (auto row = 0; row < size; ++row)
    {
        eigenVector[row] = solveMatrix(row, index);
    }

    return eigenVector;
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::EigenDecomposition<Real>::GetEigenvectors2() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(solve, "δ������");
    MATHEMATICS_ASSERTION_1(size == Matrix2Type::vectorSize, "ά�Ȳ�ƥ����GetEigenvector2\n");

    Matrix2Type eigenVectors{};
    for (auto row = 0; row < Matrix2Type::vectorSize; ++row)
    {
        for (auto column = 0; column < Vector2Type::pointSize; ++column)
        {
            eigenVectors(row, column) = solveMatrix(row, column);
        }
    }

    return eigenVectors;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::EigenDecomposition<Real>::GetEigenvector3(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(solve, "δ������");
    MATHEMATICS_ASSERTION_1(0 <= index && index < size, "��Ч������GetEigenvector3\n");
    MATHEMATICS_ASSERTION_1(size == Matrix3Type::vectorSize, "ά�Ȳ�ƥ����GetEigenvector3\n");

    Vector3Type eigenVector{};
    for (auto row = 0; row < size; ++row)
    {
        eigenVector[row] = solveMatrix(row, index);
    }

    return eigenVector;
}

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::EigenDecomposition<Real>::GetEigenvectors3() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(solve, "δ������");
    MATHEMATICS_ASSERTION_1(size == Matrix3Type::vectorSize, "ά�Ȳ�ƥ����GetEigenvector3\n");

    return solveMatrix.GetMatrix3();
}

template <typename Real>
Mathematics::VariableLengthVector<Real> Mathematics::EigenDecomposition<Real>::GetEigenvector(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(solve, "δ������");
    MATHEMATICS_ASSERTION_1(0 <= index && index < size, "��Ч������GetEigenvector3\n");

    return solveMatrix.GetColumn(index);
}

template <typename Real>
Mathematics::VariableMatrix<Real> Mathematics::EigenDecomposition<Real>::GetEigenvectors() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(solve, "δ������");

    return solveMatrix;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_DETAIL_H
