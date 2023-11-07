///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 10:04)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_ACHIEVE_H

#include "BandedMatrixInvertDetail.h"
#include "LinearSystem.h"
#include "SparseMatrixDetail.h"
#include "Detail/LinearSystemInverseDetail.h"
#include "Detail/SolveBandedDetail.h"
#include "Detail/SolveSymmetricConjugateGradientDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::LinearSystem<Real>::LinearSystem(Real zeroTolerance) noexcept
    : zeroTolerance{ zeroTolerance }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::LinearSystem<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= zeroTolerance)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::LinearSystem<Real>::SetZeroTolerance(Real newZeroTolerance) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    zeroTolerance = newZeroTolerance;
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::Vector2 Mathematics::LinearSystem<Real>::Solve2(const Matrix2& matrix, const Vector2& vector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    auto det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    if (Math::FAbs(det) <= zeroTolerance)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Solve2 失败！det为0。"s));
    }

    return Vector2{ (matrix[1][1] * vector[0] - matrix[0][1] * vector[1]) / det,
                    (matrix[0][0] * vector[1] - matrix[1][0] * vector[0]) / det };

#include SYSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::Vector3 Mathematics::LinearSystem<Real>::Solve3(const Matrix3& matrix, const Vector3& vector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    Matrix3 invMatrix{ Vector3{ matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1],
                                matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2],
                                matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1] },

                       Vector3{ matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2],
                                matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0],
                                matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2] },

                       Vector3{ matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0],
                                matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1],
                                matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0] } };

    auto det = matrix[0][0] * invMatrix[0][0] + matrix[0][1] * invMatrix[1][0] + matrix[0][2] * invMatrix[2][0];

#include SYSTEM_WARNING_POP

    if (Math::FAbs(det) <= zeroTolerance)
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

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return Vector3{ invMatrix[0][0] * vector[0] + invMatrix[0][1] * vector[1] + invMatrix[0][2] * vector[2],
                    invMatrix[1][0] * vector[0] + invMatrix[1][1] * vector[1] + invMatrix[1][2] * vector[2],
                    invMatrix[2][0] * vector[0] + invMatrix[2][1] * vector[1] + invMatrix[2][2] * vector[2] };

#include SYSTEM_WARNING_POP
}

template <typename Real>
Mathematics::VariableMatrix<Real> Mathematics::LinearSystem<Real>::Inverse(const VariableMatrix& matrix) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(matrix.GetRowsNumber() == matrix.GetColumnsNumber(), "矩阵必须是方阵\n");

    LinearSystemInverse<Real> inverse{ matrix, zeroTolerance };

    return inverse.GetInverse();
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::RealContainer Mathematics::LinearSystem<Real>::Solve(const VariableMatrix& matrix, const RealContainer& vector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    LinearSystemInverse<Real> inverse{ matrix, vector, zeroTolerance };

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

    if (Math::FAbs(mainDdiagonal.at(0)) <= zeroTolerance)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("求解失败！"s));
    }

    RealContainer output(size);

    RealContainer upperAmend(upperAmendSize);

    auto mainAmend = mainDdiagonal.at(0);

    output.at(0) = right.at(0) / mainAmend;

    for (auto i = 0; i < size - 1; ++i)
    {
        upperAmend.at(i) = upper.at(i) / mainAmend;
        const auto next = i + 1;
        mainAmend = mainDdiagonal.at(next) - lower.at(i) * upperAmend.at(i);
        if (Math::FAbs(mainAmend) <= zeroTolerance)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("求解失败！"s));
        }

        output.at(next) = (right.at(next) - lower.at(i) * output.at(i)) / mainAmend;
    }

    for (auto i = size - 1; 1 <= i; --i)
    {
        const auto next = i - 1;
        output.at(next) -= upperAmend.at(next) * output.at(i);
    }

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

    if (Math::FAbs(mainDdiagonal) <= zeroTolerance)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("求解失败！"s));
    }

    RealContainer output(size);

    const auto upperAmendSize = size - 1;
    RealContainer upperAmend(upperAmendSize);
    auto mainAmend = mainDdiagonal;

    output.at(0) = right.at(0) / mainAmend;

    for (auto i = 0; i < size - 1; ++i)
    {
        upperAmend.at(i) = upper / mainAmend;
        mainAmend = mainDdiagonal - lower * upperAmend.at(i);
        if (Math::FAbs(mainAmend) <= zeroTolerance)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("求解失败！"s));
        }

        const auto next = i + 1;

        output.at(next) = (right.at(next) - lower * output.at(i)) / mainAmend;
    }

    for (auto i = size - 1; 1 <= i; --i)
    {
        const auto next = i - 1;
        output.at(next) -= upperAmend.at(next) * output.at(i);
    }

    return output;
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::RealContainer Mathematics::LinearSystem<Real>::SolveSymmetricConjugateGradient(const VariableMatrix& matrix, const RealContainer& vector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 基于由Golum和Van Loan的“矩阵计算”算法。
    MATHEMATICS_ASSERTION_1(matrix.GetRowsNumber() == matrix.GetColumnsNumber(), "矩阵必须是方阵\n");

    Mathematics::SolveSymmetricConjugateGradient<Real, Mathematics::VariableMatrix> solve{ matrix, vector, zeroTolerance };

    return solve.GetResult();
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::RealContainer Mathematics::LinearSystem<Real>::SolveSymmetricConjugateGradient(const SparseMatrix& matrix, const RealContainer& vector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 基于由Golum和Van Loan的“矩阵计算”算法。
    MATHEMATICS_ASSERTION_1(matrix.GetRowsNumber() == matrix.GetColumnsNumber(), "矩阵必须是方阵\n");

    Mathematics::SolveSymmetricConjugateGradient<Real, Mathematics::SparseMatrix> solve{ matrix, vector, zeroTolerance };

    return solve.GetResult();
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::RealContainer Mathematics::LinearSystem<Real>::SolveBanded(const BandedMatrix& matrix, const RealContainer& vector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Mathematics::SolveBanded<Real> solve{ matrix, vector, zeroTolerance };

    return solve.GetResult();
}

template <typename Real>
typename Mathematics::LinearSystem<Real>::VariableMatrix Mathematics::LinearSystem<Real>::Invert(const BandedMatrix& matrix) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Mathematics::BandedMatrixInvert<Real> invert{ matrix, zeroTolerance };

    return invert.GetInvert();
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_ACHIEVE_H
