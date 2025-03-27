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
#include "CoreTools/MemoryTools/LexicoArray2Detail.h"
#include "Mathematics/Algebra/Matrix/Matrix2x2Detail.h"
#include "Mathematics/Algebra/Matrix/Matrix3x3Detail.h"
#include "Mathematics/Algebra/Matrix/Matrix4x4Detail.h"
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
typename Mathematics::LinearSystem<Real>::Vector3Type Mathematics::LinearSystem<Real>::Solve3(const Matrix3& matrix, const Vector3Type& vector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    Matrix3 invMatrix{ Vector3Type{ matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1],
                                matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2],
                                matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1] },

                       Vector3Type{ matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2],
                                matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0],
                                matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2] },

                       Vector3Type{ matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0],
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

    return Vector3Type{ invMatrix[0][0] * vector[0] + invMatrix[0][1] * vector[1] + invMatrix[0][2] * vector[2],
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
typename Mathematics::LinearSystem<Real>::RealContainer Mathematics::LinearSystem<Real>::SolveTriDiagonal(int size, const RealContainer& lower, const RealContainer& mainDdiagonal, const RealContainer& upper, const RealContainer& right) const
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

template <typename Real>
bool Mathematics::LinearSystem<Real>::Solve(const Matrix2x2& a, const AlgebraVector2& b, AlgebraVector2& x)
{
    auto invertible = false;
    const auto inverseA = Algebra::Inverse(a, &invertible);
    if (invertible)
    {
        x = inverseA * b;
    }
    else
    {
        x = AlgebraVector2::GetZero();
    }

    return invertible;
}

template <typename Real>
bool Mathematics::LinearSystem<Real>::Solve(const Matrix3x3& a, const AlgebraVector3& b, AlgebraVector3& x)
{
    auto invertible = false;
    const auto inverseA = Algebra::Inverse(a, &invertible);
    if (invertible)
    {
        x = inverseA * b;
    }
    else
    {
        x = AlgebraVector3::GetZero();
    }

    return invertible;
}

template <typename Real>
bool Mathematics::LinearSystem<Real>::Solve(const Matrix4x4& a, const AlgebraVector4& b, AlgebraVector4& x)
{
    auto invertible = false;
    const auto inverseA = Algebra::Inverse(a, &invertible);
    if (invertible)
    {
        x = inverseA * b;
    }
    else
    {
        x = AlgebraVector4::GetZero();
    }

    return invertible;
}

template <typename Real>
bool Mathematics::LinearSystem<Real>::Solve(int n, const RealContainer& a, const RealContainer& b, RealContainer& x)
{
    if (GaussianElimination<Real> gaussianElimination{ n, a, false, b };
        gaussianElimination.IsInverse())
    {
        x = gaussianElimination.GetX();

        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real>
bool Mathematics::LinearSystem<Real>::Solve(int n, int m, const RealContainer& a, const RealContainer& b, RealContainer& x)
{
    if (GaussianElimination<Real> gaussianElimination{ n, a, false, typename GaussianElimination<Real>::Container{}, m, b };
        gaussianElimination.IsInverse())
    {
        x = gaussianElimination.GetY();

        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real>
bool Mathematics::LinearSystem<Real>::SolveTriDiagonal(int n, const RealContainer& subDiagonal, const RealContainer& diagonal, const RealContainer& superDiagonal, const RealContainer& b, RealContainer& x)
{
    if (Math::Approximate(diagonal.at(0), Real{}))
    {
        return false;
    }

    RealContainer tmp(boost::numeric_cast<size_t>(n) - 1);
    auto expr = diagonal.at(0);
    auto invExpr = Math::GetValue(1) / expr;
    x.at(0) = b.at(0) * invExpr;

    for (auto i0 = 0, i1 = 1; i1 < n; ++i0, ++i1)
    {
        tmp.at(i0) = superDiagonal.at(i0) * invExpr;
        expr = diagonal.at(i1) - subDiagonal.at(i0) * tmp.at(i0);
        if (Math::Approximate(expr, Real{}))
        {
            return false;
        }
        invExpr = Math::GetValue(1) / expr;
        x.at(i1) = (b.at(i1) - subDiagonal.at(i0) * x.at(i0)) * invExpr;
    }

    for (auto i0 = n - 1, i1 = n - 2; i1 >= 0; --i0, --i1)
    {
        x.at(i1) -= tmp.at(i1) * x.at(i0);
    }
    return true;
}

template <typename Real>
bool Mathematics::LinearSystem<Real>::SolveConstantTriDiagonal(int n, Real subDiagonal, Real diagonal, Real superDiagonal, const RealContainer& b, RealContainer& x)
{
    if (Math::Approximate(diagonal, Real{}))
    {
        return false;
    }

    RealContainer tmp(boost::numeric_cast<size_t>(n) - 1);
    auto expr = diagonal;
    auto invExpr = Math::GetValue(1) / expr;
    x.at(0) = b.at(0) * invExpr;

    for (auto i0 = 0, i1 = 1; i1 < n; ++i0, ++i1)
    {
        tmp.at(i0) = superDiagonal * invExpr;
        expr = diagonal - subDiagonal * tmp.at(i0);
        if (Math::Approximate(expr, Real{}))
        {
            return false;
        }
        invExpr = Math::GetValue(1) / expr;
        x.at(i1) = (b.at(i1) - subDiagonal * x.at(i0)) * invExpr;
    }

    for (auto i0 = n - 1, i1 = n - 2; i1 >= 0; --i0, --i1)
    {
        x.at(i1) -= tmp.at(i1) * x.at(i0);
    }
    return true;
}

template <typename Real>
int Mathematics::LinearSystem<Real>::SolveSymmetricConjugateGradient(int n, RealContainer& a, const RealContainer& b, RealContainer& x, int maxIterations, Real tolerance)
{
    /// 第一次迭代。
    RealContainer r(n);
    RealContainer p(n);
    RealContainer w(n);

    r = b;
    std::fill(x.begin(), x.end(), Real{});

    auto rho0 = Dot(n, r, r);
    p = r;
    Mul(n, a, p, w);
    auto alpha = rho0 / Dot(n, p, w);
    UpdateX(n, x, alpha, p);
    UpdateR(n, r, alpha, w);
    auto rho1 = Dot(n, r, r);

    /// 剩下的迭代。
    auto iteration = 1;
    for (; iteration <= maxIterations; ++iteration)
    {
        const auto root0 = std::sqrt(rho1);
        const auto norm = Dot(n, b, b);
        const auto root1 = std::sqrt(norm);
        if (root0 <= tolerance * root1)
        {
            break;
        }

        const auto beta = rho1 / rho0;
        UpdateP(n, p, beta, r);
        Mul(n, a, p, w);
        alpha = rho1 / Dot(n, p, w);
        UpdateX(n, x, alpha, p);
        UpdateR(n, r, alpha, w);
        rho0 = rho1;
        rho1 = Dot(n, r, r);
    }
    return iteration;
}

template <typename Real>
int Mathematics::LinearSystem<Real>::SolveSymmetricConjugateGradient(int n, AlgebraSparseMatrix const& a, const RealContainer& b, RealContainer& x, int maxIterations, Real tolerance)
{
    /// 第一次迭代。
    RealContainer r(n);
    RealContainer p(n);
    RealContainer w(n);

    r = b;
    std::fill(x.begin(), x.end(), Real{});
    auto rho0 = Dot(n, r, r);
    p = r;
    Mul(a, p, w);
    auto alpha = rho0 / Dot(n, p, w);
    UpdateX(n, x, alpha, p);
    UpdateR(n, r, alpha, w);
    auto rho1 = Dot(n, r, r);

    /// 剩下的迭代。
    auto iteration = 1;
    for (; iteration <= maxIterations; ++iteration)
    {
        const auto root0 = std::sqrt(rho1);
        auto norm = Dot(n, b, b);
        const auto root1 = std::sqrt(norm);
        if (root0 <= tolerance * root1)
        {
            break;
        }

        auto beta = rho1 / rho0;
        UpdateP(n, p, beta, r);
        Mul(a, p, w);
        alpha = rho1 / Dot(n, p, w);
        UpdateX(n, x, alpha, p);
        UpdateR(n, r, alpha, w);
        rho0 = rho1;
        rho1 = Dot(n, r, r);
    }
    return iteration;
}

template <typename Real>
Real Mathematics::LinearSystem<Real>::Dot(int n, const RealContainer& u, const RealContainer& v)
{
    Real dot{};
    for (auto i = 0; i < n; ++i)
    {
        dot += u.at(i) * v.at(i);
    }
    return dot;
}

template <typename Real>
void Mathematics::LinearSystem<Real>::Mul(int n, RealContainer& a, const RealContainer& x, RealContainer& p)
{
    LexicoArray2 matA{ n, n, a.begin(), a.end() };

    for (auto row = 0; row < n; ++row)
    {
        for (auto col = 0; col < n; ++col)
        {
            p.at(row) += matA(row, col) * x.at(col);
        }
    }
}

template <typename Real>
void Mathematics::LinearSystem<Real>::Mul(const AlgebraSparseMatrix& a, const RealContainer& x, RealContainer& p)
{
    std::fill(p.begin(), p.end(), Real{});
    for (const auto& element : a)
    {
        auto i = element.first.at(0);
        auto j = element.first.at(1);
        auto value = element.second;
        p.at(i) += value * x.at(j);
        if (i != j)
        {
            p.at(j) += value * x.at(i);
        }
    }
}

template <typename Real>
void Mathematics::LinearSystem<Real>::UpdateX(int n, RealContainer& x, Real alpha, const RealContainer& p)
{
    for (auto i = 0; i < n; ++i)
    {
        x.at(i) += alpha * p.at(i);
    }
}

template <typename Real>
void Mathematics::LinearSystem<Real>::UpdateR(int n, RealContainer& r, Real alpha, const RealContainer& w)
{
    for (auto i = 0; i < n; ++i)
    {
        r.at(i) -= alpha * w.at(i);
    }
}

template <typename Real>
void Mathematics::LinearSystem<Real>::UpdateP(int n, RealContainer& p, Real beta, const RealContainer& r)
{
    for (auto i = 0; i < n; ++i)
    {
        p.at(i) = r.at(i) + beta * p.at(i);
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_ACHIEVE_H
