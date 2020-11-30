///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/24 12:58)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_IMPL_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_IMPL_DETAIL_H

#include "EigenDecompositionImpl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::EigenDecompositionImpl<Real>::EigenDecompositionImpl(int size)
    : m_Size{ size },
      m_Matrix{ m_Size, m_Size },
      m_SolveMatrix{ m_Size, m_Size },
      m_Diagonal(m_Size),
      m_Subdiagonal(m_Size),
      m_IsRotation{ false },
      m_Solve{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecompositionImpl<Real>::EigenDecompositionImpl(const Matrix2& rhs)
    : m_Size{ Matrix2::sm_VectorSize },
      m_Matrix{ rhs },
      m_SolveMatrix{ rhs },
      m_Diagonal(m_Size),
      m_Subdiagonal(m_Size),
      m_IsRotation{ false },
      m_Solve{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecompositionImpl<Real>::EigenDecompositionImpl(const Matrix3& rhs)
    : m_Size{ Matrix3::sm_VectorSize },
      m_Matrix{ rhs },
      m_SolveMatrix{ rhs },
      m_Diagonal(m_Size),
      m_Subdiagonal(m_Size),
      m_IsRotation{ false },
      m_Solve{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecompositionImpl<Real>::EigenDecompositionImpl(const VariableMatrix& rhs)
    : m_Size{ rhs.GetRowsNumber() },
      m_Matrix{ rhs },
      m_SolveMatrix{ rhs },
      m_Diagonal(m_Size),
      m_Subdiagonal(m_Size),
      m_IsRotation{ false },
      m_Solve{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecompositionImpl<Real>& Mathematics::EigenDecompositionImpl<Real>::operator=(const Matrix2& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    EigenDecompositionImpl result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
Mathematics::EigenDecompositionImpl<Real>& Mathematics::EigenDecompositionImpl<Real>::operator=(const Matrix3& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    EigenDecompositionImpl result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
Mathematics::EigenDecompositionImpl<Real>& Mathematics::EigenDecompositionImpl<Real>::operator=(const VariableMatrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    EigenDecompositionImpl result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::Swap(EigenDecompositionImpl& rhs) noexcept
{
    std::swap(m_Size, rhs.m_Size);
    std::swap(m_Matrix, rhs.m_Matrix);
    std::swap(m_SolveMatrix, rhs.m_SolveMatrix);
    std::swap(m_Diagonal, rhs.m_Diagonal);
    std::swap(m_Subdiagonal, rhs.m_Subdiagonal);
    std::swap(m_IsRotation, rhs.m_IsRotation);
    std::swap(m_Solve, rhs.m_Solve);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::EigenDecompositionImpl<Real>::IsValid() const noexcept
{
    try
    {
        if (Matrix2::sm_VectorSize <= m_Size && m_Matrix.GetColumnsNumber() == m_Matrix.GetRowsNumber() &&
            m_SolveMatrix.GetColumnsNumber() == m_SolveMatrix.GetRowsNumber() &&
            m_Matrix.GetColumnsNumber() == m_SolveMatrix.GetColumnsNumber())
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
int Mathematics::EigenDecompositionImpl<Real>::GetSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Size;
}

template <typename Real>
const Real& Mathematics::EigenDecompositionImpl<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= row && row < m_Size && 0 <= column && column < m_Size, "索引错误！");

    return m_Matrix(row, column);
}

template <typename Real>
Real& Mathematics::EigenDecompositionImpl<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_0(0 <= row && row < m_Size && 0 <= column && column < m_Size, "索引错误！");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)
    return const_cast<Real&>(static_cast<const EigenDecompositionImpl&>(*this)(row, column));
#include STSTEM_WARNING_POP
}

template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::Solve(bool increasingSort)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Solve = false;

    switch (m_Size)
    {
        case Matrix2::sm_VectorSize:
            Tridiagonal2();
            break;
        case Matrix3::sm_VectorSize:
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

    m_Solve = true;
}

// private
template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::Tridiagonal2()
{
    // 该矩阵是已经是三对角矩阵。
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    m_Diagonal[0] = m_Matrix(0, 0);
    m_Diagonal[1] = m_Matrix(1, 1);
    m_Subdiagonal[0] = m_Matrix(0, 1);
    m_Subdiagonal[1] = Math::GetValue(0);
#include STSTEM_WARNING_POP

    m_SolveMatrix.SetIdentity();

    m_IsRotation = true;
}

// private
template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::Tridiagonal3()
{
    auto m00 = m_Matrix(0, 0);
    auto m01 = m_Matrix(0, 1);
    auto m02 = m_Matrix(0, 2);
    auto m11 = m_Matrix(1, 1);
    auto m12 = m_Matrix(1, 2);
    auto m22 = m_Matrix(2, 2);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    m_Diagonal[0] = m00;
    m_Subdiagonal[2] = Math::GetValue(0);
    if (Math::GetZeroTolerance() < Math::FAbs(m02))
    {
        auto length = Math::Sqrt(m01 * m01 + m02 * m02);
        m01 /= length;
        m02 /= length;
        Real q = Math::GetValue(2) * m01 * m12 + m02 * (m22 - m11);
        m_Diagonal[1] = m11 + m02 * q;
        m_Diagonal[2] = m22 - m02 * q;
        m_Subdiagonal[0] = length;
        m_Subdiagonal[1] = m12 - m01 * q;
        m_SolveMatrix(0, 0) = Math::GetValue(1);
        m_SolveMatrix(0, 1) = Math::GetValue(0);
        m_SolveMatrix(0, 2) = Math::GetValue(0);
        m_SolveMatrix(1, 0) = Math::GetValue(0);
        m_SolveMatrix(1, 1) = m01;
        m_SolveMatrix(1, 2) = m02;
        m_SolveMatrix(2, 0) = Math::GetValue(0);
        m_SolveMatrix(2, 1) = m02;
        m_SolveMatrix(2, 2) = -m01;

        m_IsRotation = false;
    }
    else
    {
        m_Diagonal[1] = m11;
        m_Diagonal[2] = m22;
        m_Subdiagonal[0] = m01;
        m_Subdiagonal[1] = m12;
        m_SolveMatrix.SetIdentity();

        m_IsRotation = true;
    }

#include STSTEM_WARNING_POP
}
// private
template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::TridiagonalN()
{
    m_SolveMatrix = m_Matrix;

    Step1();
    Step2();
    Step3();

    m_IsRotation = ((m_Size % 2) == 0);
}

// private
template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::Step1()
{
    for (auto index = m_Size - 1; 1 <= index; --index)
    {
        if (1 < index)
        {
            TridiagonalNInLoop(index);
        }
        else
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            m_Subdiagonal[index] = m_SolveMatrix(index, index - 1);
            m_Diagonal[index] = Math::GetValue(0);
#include STSTEM_WARNING_POP
        }
    }
}

// private
template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::TridiagonalNInLoop(int index)
{
    auto scale = GetScale(index);

    if (Math::FAbs(scale) <= Math::GetZeroTolerance())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_Subdiagonal[index] = m_SolveMatrix(index, index - 1);
        m_Diagonal[index] = Math::GetValue(0);
#include STSTEM_WARNING_POP
    }
    else
    {
        CalculateDiagonal(index, scale);
        CalculateSubdiagonal(index);
    }
}

template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::CalculateDiagonal(int index, Real scale)
{
    auto diagonaValue = Math::GetValue(0);

    for (auto diagonaIndex = 0; diagonaIndex <= index - 1; ++diagonaIndex)
    {
        m_SolveMatrix(index, diagonaIndex) /= scale;
        diagonaValue += m_SolveMatrix(index, diagonaIndex) * m_SolveMatrix(index, diagonaIndex);
    }

    auto solveMatrixValue = m_SolveMatrix(index, index - 1);
    auto diagonaValueSqrt = Math::Sqrt(diagonaValue);
    if (Math::GetValue(0) < solveMatrixValue)
    {
        diagonaValueSqrt = -diagonaValueSqrt;
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    m_Subdiagonal[index] = scale * diagonaValueSqrt;
    diagonaValue -= solveMatrixValue * diagonaValueSqrt;
    m_SolveMatrix(index, index - 1) = solveMatrixValue - diagonaValueSqrt;

    m_Diagonal[index] = diagonaValue;

#include STSTEM_WARNING_POP
}

template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::CalculateSubdiagonal(int index)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto diagonaValue = m_Diagonal[index];
    auto subdiagonalProduct = Math::GetValue(0);

    for (int outerIndex = 0; outerIndex <= index - 1; ++outerIndex)
    {
        m_SolveMatrix(outerIndex, index) = m_SolveMatrix(index, outerIndex) / diagonaValue;
        auto solveMatrixProduct = Math::GetValue(0);
        for (auto innerIndex = 0; innerIndex <= outerIndex; ++innerIndex)
        {
            solveMatrixProduct += m_SolveMatrix(outerIndex, innerIndex) * m_SolveMatrix(index, innerIndex);
        }

        for (auto innerIndex = outerIndex + 1; innerIndex <= index - 1; ++innerIndex)
        {
            solveMatrixProduct += m_SolveMatrix(innerIndex, outerIndex) * m_SolveMatrix(index, innerIndex);
        }

        m_Subdiagonal[outerIndex] = solveMatrixProduct / diagonaValue;
        subdiagonalProduct += m_Subdiagonal[outerIndex] * m_SolveMatrix(index, outerIndex);
    }

    auto value = Math::GetRational(1, 2) * subdiagonalProduct / diagonaValue;
    for (auto outerIndex = 0; outerIndex <= index - 1; ++outerIndex)
    {
        auto solveMatrixValue = m_SolveMatrix(index, outerIndex);
        auto subdiagonalValue = m_Subdiagonal[outerIndex] - value * solveMatrixValue;
        m_Subdiagonal[outerIndex] = subdiagonalValue;
        for (auto innerIndex = 0; innerIndex <= outerIndex; innerIndex++)
        {
            m_SolveMatrix(outerIndex, innerIndex) -= solveMatrixValue * m_Subdiagonal[innerIndex] + subdiagonalValue * m_SolveMatrix(index, innerIndex);
        }
    }

#include STSTEM_WARNING_POP
}

// private
template <typename Real>
Real Mathematics::EigenDecompositionImpl<Real>::GetScale(int index) const
{
    auto scale = Math::GetValue(0);

    for (auto scaleIndex = 0; scaleIndex <= index - 1; ++scaleIndex)
    {
        scale += Math::FAbs(m_SolveMatrix(index, scaleIndex));
    }

    return scale;
}

// private
template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::Step2()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    m_Diagonal[0] = Math::GetValue(0);
    m_Subdiagonal[0] = Math::GetValue(0);
    for (auto index = 0; index <= m_Size - 1; ++index)
    {
        if (Math::GetZeroTolerance() < Math::FAbs(m_Diagonal[index]))
        {
            for (auto outerIndex = 0; outerIndex <= index - 1; ++outerIndex)
            {
                auto sum = Math::GetValue(0);

                for (auto innerIndex = 0; innerIndex <= index - 1; ++innerIndex)
                {
                    sum += m_SolveMatrix(index, innerIndex) * m_SolveMatrix(innerIndex, outerIndex);
                }
                for (auto innerIndex = 0; innerIndex <= index - 1; ++innerIndex)
                {
                    m_SolveMatrix(innerIndex, outerIndex) -= sum * m_SolveMatrix(innerIndex, index);
                }
            }
        }
        m_Diagonal[index] = m_SolveMatrix[index][index];
        m_SolveMatrix[index][index] = Math::GetValue(1);
        for (auto innerIndex = 0; innerIndex <= index - 1; ++innerIndex)
        {
            m_SolveMatrix(innerIndex, index) = Math::GetValue(0);
            m_SolveMatrix(index, innerIndex) = Math::GetValue(0);
        }
    }

#include STSTEM_WARNING_POP
}

// private
template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::Step3() noexcept
{
    // 重新排序需要在EigenDecomposition::QLAlgorithm。
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    for (auto index = 1; index < m_Size; ++index)
    {
        const auto indexMinus1 = index - 1;
        m_Subdiagonal[indexMinus1] = m_Subdiagonal[index];
    }
    const auto sizeMinus1 = m_Size - 1;
    m_Subdiagonal[sizeMinus1] = Math::GetValue(0);

#include STSTEM_WARNING_POP
}

// private
template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::QLAlgorithm()
{
    for (auto index = 0; index < m_Size; ++index)
    {
        QLAlgorithm(index);
    }
}

// private
template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::QLAlgorithm(int index)
{
    const auto loopTime = QLAlgorithmWithLoopTime(index);

    if (sm_MaxIter <= loopTime)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("循环超出次数。"s));
    }
}

template <typename Real>
int Mathematics::EigenDecompositionImpl<Real>::QLAlgorithmWithLoopTime(int totalIndex)
{
    for (auto loopTime = 0; loopTime < sm_MaxIter; ++loopTime)
    {
        auto outerIndex = totalIndex;
        for (; outerIndex <= m_Size - 2; ++outerIndex)
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

    return sm_MaxIter;
}

// private
template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::QLAlgorithmLoop(int totalIndex, int outerIndex)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto subdiagonalValue = GetQLAlgorithmSubdiagonalValue(totalIndex, outerIndex);
    auto sine = Math::GetValue(1);
    auto cosine = Math::GetValue(1);
    auto diagonalDifferenceValue = Math::GetValue(0);

    for (auto innerIndex = outerIndex - 1; innerIndex >= totalIndex; --innerIndex)
    {
        auto subdiagonalSineValue = sine * m_Subdiagonal[innerIndex];
        auto subdiagonalCosineValue = cosine * m_Subdiagonal[innerIndex];

        if (Math::FAbs(subdiagonalValue) <= Math::FAbs(subdiagonalSineValue))
        {
            cosine = subdiagonalValue / subdiagonalSineValue;
            auto cosineAmend = Math::Sqrt(cosine * cosine + Math::GetValue(1));
            const auto innerNextIndex = innerIndex + 1;
            m_Subdiagonal[innerNextIndex] = subdiagonalSineValue * cosineAmend;
            sine = Math::GetValue(1) / cosineAmend;
            cosine *= sine;
        }
        else
        {
            sine = subdiagonalSineValue / subdiagonalValue;
            auto cosineAmend = Math::Sqrt(sine * sine + Math::GetValue(1));
            const auto innerNextIndex = innerIndex + 1;
            m_Subdiagonal[innerNextIndex] = subdiagonalValue * cosineAmend;
            cosine = Math::GetValue(1) / cosineAmend;
            sine *= cosine;
        }
        const auto innerNextIndex = innerIndex + 1;
        subdiagonalValue = m_Diagonal[innerNextIndex] - diagonalDifferenceValue;
        auto value = (m_Diagonal[innerIndex] - subdiagonalValue) * sine + Math::GetValue(2) * subdiagonalCosineValue * cosine;
        diagonalDifferenceValue = sine * value;
        m_Diagonal[innerNextIndex] = subdiagonalValue + diagonalDifferenceValue;
        subdiagonalValue = cosine * value - subdiagonalCosineValue;

        QLAlgorithmAmendSolveMatrix(innerIndex, sine, cosine);
    }

    m_Diagonal[totalIndex] -= diagonalDifferenceValue;
    m_Subdiagonal[totalIndex] = subdiagonalValue;
    m_Subdiagonal[outerIndex] = Math::GetValue(0);

#include STSTEM_WARNING_POP
}

// private
template <typename Real>
Real Mathematics::EigenDecompositionImpl<Real>::GetQLAlgorithmSubdiagonalValue(int totalIndex, int outerIndex) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    const auto totalIndexPlusOne = totalIndex + 1;
    auto value = (m_Diagonal[totalIndexPlusOne] - m_Diagonal[totalIndex]) / (Math::GetValue(2) * m_Subdiagonal[totalIndex]);

    auto amendValue = Math::Sqrt(value * value + Math::GetValue(1));
    if (value < Math::GetValue(0))
    {
        return m_Diagonal[outerIndex] - m_Diagonal[totalIndex] + m_Subdiagonal[totalIndex] / (value - amendValue);
    }
    else
    {
        return m_Diagonal[outerIndex] - m_Diagonal[totalIndex] + m_Subdiagonal[totalIndex] / (value + amendValue);
    }

#include STSTEM_WARNING_POP
}

// private
template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::QLAlgorithmAmendSolveMatrix(int innerIndex, Real sine, Real cosine)
{
    for (auto i = 0; i < m_Size; ++i)
    {
        auto value = m_SolveMatrix(i, innerIndex + 1);

        m_SolveMatrix(i, innerIndex + 1) = sine * m_SolveMatrix(i, innerIndex) + cosine * value;
        m_SolveMatrix(i, innerIndex) = cosine * m_SolveMatrix(i, innerIndex) - sine * value;
    }
}

// private
template <typename Real>
bool Mathematics::EigenDecompositionImpl<Real>::IsQLAlgorithmQuit(int outerIndex) const noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    const auto outerNextIndex = outerIndex + 1;
    auto diagonalSum = Math::FAbs(m_Diagonal[outerIndex]) + Math::FAbs(m_Diagonal[outerNextIndex]);

    if (Math::FAbs(Math::FAbs(m_Subdiagonal[outerIndex]) + diagonalSum - diagonalSum) <= Math::GetZeroTolerance())
    {
        return true;
    }
    else
    {
        return false;
    }

#include STSTEM_WARNING_POP
}

// private
template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::DecreasingSort()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 排序特征值按递减顺序，e[0] >= ... >= e[mSize-1]
    for (auto outerIndex = 0; outerIndex <= m_Size - 2; ++outerIndex)
    {
        // 找到最大特征值。
        auto minIndex = outerIndex;
        auto maxValue = m_Diagonal[minIndex];

        for (auto innerIndex = outerIndex + 1; innerIndex < m_Size; ++innerIndex)
        {
            if (maxValue < m_Diagonal[innerIndex])
            {
                minIndex = innerIndex;
                maxValue = m_Diagonal[minIndex];
            }
        }

        if (minIndex != outerIndex)
        {
            // 交换的特征值。
            m_Diagonal[minIndex] = m_Diagonal[outerIndex];
            m_Diagonal[outerIndex] = maxValue;

            // 交换对应于特征值的特征向量。
            for (auto innerIndex = 0; innerIndex < m_Size; ++innerIndex)
            {
                std::swap(m_SolveMatrix(innerIndex, outerIndex), m_SolveMatrix(innerIndex, minIndex));

                m_IsRotation = !m_IsRotation;
            }
        }
    }

#include STSTEM_WARNING_POP
}

// private
template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::IncreasingSort()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 排序特征值按递增顺序， e[0] <= ... <= e[mSize-1]
    for (auto outerIndex = 0; outerIndex <= m_Size - 2; ++outerIndex)
    {
        // 找到最小特征值。
        auto minIndex = outerIndex;
        auto minValue = m_Diagonal[minIndex];

        for (auto innerIndex = outerIndex + 1; innerIndex < m_Size; ++innerIndex)
        {
            if (m_Diagonal[innerIndex] < minValue)
            {
                minIndex = innerIndex;
                minValue = m_Diagonal[minIndex];
            }
        }

        if (minIndex != outerIndex)
        {
            // 交换特征值。
            m_Diagonal[minIndex] = m_Diagonal[outerIndex];
            m_Diagonal[outerIndex] = minValue;

            // 交换对应于特征值的特征向量。
            for (auto innerIndex = 0; innerIndex < m_Size; ++innerIndex)
            {
                std::swap(m_SolveMatrix(innerIndex, outerIndex), m_SolveMatrix(innerIndex, minIndex));

                m_IsRotation = !m_IsRotation;
            }
        }
    }

#include STSTEM_WARNING_POP
}

// private
template <typename Real>
void Mathematics::EigenDecompositionImpl<Real>::GuaranteeRotation()
{
    if (!m_IsRotation)
    {
        // 改变符号在第一列中。
        for (auto row = 0; row < m_Size; ++row)
        {
            m_SolveMatrix(row, 0) = -m_SolveMatrix(row, 0);
        }
    }
}

template <typename Real>
Real Mathematics::EigenDecompositionImpl<Real>::GetEigenvalue(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(m_Solve, "未解析！");

    return m_Diagonal.at(index);
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::EigenDecompositionImpl<Real>::GetEigenvector2(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(m_Solve, "未解析！");
    MATHEMATICS_ASSERTION_0(0 <= index && index < m_Size, "无效索引在GetEigenvector2\n");
    MATHEMATICS_ASSERTION_1(m_Size == Matrix2::sm_VectorSize, "维度不匹配在GetEigenvector2\n");

    Vector2D eigenvector{};
    for (auto row = 0; row < m_Size; ++row)
    {
        eigenvector[row] = m_SolveMatrix(row, index);
    }

    return eigenvector;
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::EigenDecompositionImpl<Real>::GetEigenvectors2() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(m_Solve, "未解析！");
    MATHEMATICS_ASSERTION_1(m_Size == Matrix2::sm_VectorSize, "维度不匹配在GetEigenvector2\n");

    Matrix2 eigenvectors{};
    for (auto row = 0; row < Matrix2::sm_VectorSize; ++row)
    {
        for (auto column = 0; column < Vector2D::sm_PointSize; ++column)
        {
            eigenvectors(row, column) = m_SolveMatrix(row, column);
        }
    }

    return eigenvectors;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::EigenDecompositionImpl<Real>::GetEigenvector3(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(m_Solve, "未解析！");
    MATHEMATICS_ASSERTION_0(0 <= index && index < m_Size, "无效索引在GetEigenvector3\n");
    MATHEMATICS_ASSERTION_1(m_Size == Matrix3::sm_VectorSize, "维度不匹配在GetEigenvector3\n");

    Vector3D eigenvector{};
    for (auto row = 0; row < m_Size; ++row)
    {
        eigenvector[row] = m_SolveMatrix(row, index);
    }

    return eigenvector;
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::EigenDecompositionImpl<Real>::GetEigenvectors3() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(m_Solve, "未解析！");
    MATHEMATICS_ASSERTION_1(m_Size == Matrix3::sm_VectorSize, "维度不匹配在GetEigenvector3\n");

    return m_SolveMatrix.GetMatrix3();
}

template <typename Real>
const Mathematics::VariableLengthVector<Real> Mathematics::EigenDecompositionImpl<Real>::GetEigenvector(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(m_Solve, "未解析！");
    MATHEMATICS_ASSERTION_0(0 <= index && index < m_Size, "无效索引在GetEigenvector3\n");

    return m_SolveMatrix.GetColumn(index);
}

template <typename Real>
const Mathematics::VariableMatrix<Real> Mathematics::EigenDecompositionImpl<Real>::GetEigenvectors() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(m_Solve, "未解析！");

    return m_SolveMatrix;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_IMPL_DETAIL_H
