///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/25 12:51)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_ACHIEVE_H

#include "BandedMatrixInvertDetail.h"
#include "LinearSystem.h"
#include "Detail/LinearSystemInverseDetail.h"
#include "Detail/SolveBandedDetail.h"
#include "Detail/SolveSymmetricConjugateGradientDetail.h"
#include "SparseMatrixDetail.h" 
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::LinearSystem<Real>::LinearSystem(Real zeroTolerance) noexcept
    : m_ZeroTolerance{ zeroTolerance }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::LinearSystem<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= m_ZeroTolerance)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::LinearSystem<Real>::SetZeroTolerance(Real zeroTolerance) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_ZeroTolerance = zeroTolerance;
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::Vector2 Mathematics::LinearSystem<Real>::Solve2(const Matrix2& matrix, const Vector2& vector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    auto det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    if (Math::FAbs(det) <= m_ZeroTolerance)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Solve2 失败！det为0。"s));
    }

    return Vector2{ (matrix[1][1] * vector[0] - matrix[0][1] * vector[1]) / det,
                    (matrix[0][0] * vector[1] - matrix[1][0] * vector[0]) / det };

#include STSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::Vector3 Mathematics::LinearSystem<Real>::Solve3(const Matrix3& matrix, const Vector3& vector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Matrix3 invMatrix{ Vector3{ matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1],
                                matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2],
                                matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1] },

                       Vector3{ matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2],
                                matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0],
                                matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2] },

                       Vector3{ matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0],
                                matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1],
                                matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0] } };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto det = matrix[0][0] * invMatrix[0][0] + matrix[0][1] * invMatrix[1][0] + matrix[0][2] * invMatrix[2][0];

    if (Math::FAbs(det) <= m_ZeroTolerance)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Solve3 失败！det为0。"s));
    }

    for (auto& invVector : invMatrix)
    {
        for (auto& value : invVector)
        {
            value /= det;
        }
    }

    return Vector3{ invMatrix[0][0] * vector[0] + invMatrix[0][1] * vector[1] + invMatrix[0][2] * vector[2],
                    invMatrix[1][0] * vector[0] + invMatrix[1][1] * vector[1] + invMatrix[1][2] * vector[2],
                    invMatrix[2][0] * vector[0] + invMatrix[2][1] * vector[1] + invMatrix[2][2] * vector[2] };

#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::VariableMatrix<Real> Mathematics::LinearSystem<Real>::Inverse(const VariableMatrix& matrix) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(matrix.GetRowsNumber() == matrix.GetColumnsNumber(), "矩阵必须是方阵\n");

    LinearSystemInverse<Real> inverse{ matrix, m_ZeroTolerance };

    return inverse.GetInverse();
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::RealContainer Mathematics::LinearSystem<Real>::Solve(const VariableMatrix& matrix, const RealContainer& vector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    LinearSystemInverse<Real> inverse{ matrix, vector, m_ZeroTolerance };

    return inverse.GetResult();
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::RealContainer Mathematics::LinearSystem<Real>::SolveTridiagonal(int size, const RealContainer& lower, const RealContainer& mainDdiagonal, const RealContainer& upper, const RealContainer& right) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 < size, "传入的大小为零或负数！");

    const auto upperAmendSize = size - 1;

    if (boost::numeric_cast<int>(lower.size()) != upperAmendSize ||
        boost::numeric_cast<int>(upper.size()) != upperAmendSize ||
        boost::numeric_cast<int>(mainDdiagonal.size()) != size ||
        boost::numeric_cast<int>(right.size()) != size)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数组大小错误！"s));
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (Math::FAbs(mainDdiagonal[0]) <= m_ZeroTolerance)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("求解失败！"s));
    }

    RealContainer output(size);

    RealContainer upperAmend(upperAmendSize);

    auto mainAmend = mainDdiagonal[0];

    output[0] = right[0] / mainAmend;

    for (auto i = 0; i < size - 1; ++i)
    {
        upperAmend[i] = upper[i] / mainAmend;
        const auto next = i + 1;
        mainAmend = mainDdiagonal[next] - lower[i] * upperAmend[i];
        if (Math::FAbs(mainAmend) <= m_ZeroTolerance)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("求解失败！"s));
        }

        output[next] = (right[next] - lower[i] * output[i]) / mainAmend;
    }

    for (auto i = size - 1; 1 <= i; --i)
    {
        const auto next = i - 1;
        output[next] -= upperAmend[next] * output[i];
    }

#include STSTEM_WARNING_POP

    return output;
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::RealContainer Mathematics::LinearSystem<Real>::SolveConstTridiagonal(int size, Real lower, Real mainDdiagonal, Real upper, const RealContainer& right) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (boost::numeric_cast<int>(right.size()) != size)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数组大小错误！"s));
    }

    if (Math::FAbs(mainDdiagonal) <= m_ZeroTolerance)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("求解失败！"s));
    }

    RealContainer output(size);

    const auto upperAmendSize = size - 1;
    RealContainer upperAmend(upperAmendSize);
    auto mainAmend = mainDdiagonal;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    output[0] = right[0] / mainAmend;

    for (auto i = 0; i < size - 1; ++i)
    {
        upperAmend[i] = upper / mainAmend;
        mainAmend = mainDdiagonal - lower * upperAmend[i];
        if (Math::FAbs(mainAmend) <= m_ZeroTolerance)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("求解失败！"s));
        }

        const auto next = i + 1;

        output[next] = (right[next] - lower * output[i]) / mainAmend;
    }

    for (auto i = size - 1; 1 <= i; --i)
    {
        const auto next = i - 1;
        output[next] -= upperAmend[next] * output[i];
    }

#include STSTEM_WARNING_POP

    return output;
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::RealContainer Mathematics::LinearSystem<Real>::SolveSymmetricConjugateGradient(const VariableMatrix& matrix, const RealContainer& vector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 基于由Golum和Van Loan的“矩阵计算”算法。
    MATHEMATICS_ASSERTION_1(matrix.GetRowsNumber() == matrix.GetColumnsNumber(), "矩阵必须是方阵\n");

    Mathematics::SolveSymmetricConjugateGradient<Real, Mathematics::VariableMatrix> solve{ matrix, vector, m_ZeroTolerance };

    return solve.GetResult();
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::RealContainer Mathematics::LinearSystem<Real>::SolveSymmetricConjugateGradient(const SparseMatrix& matrix, const RealContainer& vector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 基于由Golum和Van Loan的“矩阵计算”算法。
    MATHEMATICS_ASSERTION_1(matrix.GetRowsNumber() == matrix.GetColumnsNumber(), "矩阵必须是方阵\n");

    Mathematics::SolveSymmetricConjugateGradient<Real, Mathematics::SparseMatrix> solve{ matrix, vector, m_ZeroTolerance };

    return solve.GetResult();
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::RealContainer Mathematics::LinearSystem<Real>::SolveBanded(const BandedMatrix& matrix, const RealContainer& vector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Mathematics::SolveBanded<Real> solve{ matrix, vector, m_ZeroTolerance };

    return solve.GetResult();
}

template <typename Real>
typename const Mathematics::LinearSystem<Real>::VariableMatrix Mathematics::LinearSystem<Real>::Invert(const BandedMatrix& matrix) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Mathematics::BandedMatrixInvert<Real> invert{ matrix, m_ZeroTolerance };

    return invert.GetInvert();
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_ACHIEVE_H
