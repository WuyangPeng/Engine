/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 14:03)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_DETAIL_H

#include "PolynomialRoots.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/PolynomialDivideDetail.h"

#include <gsl/util>

template <typename Real>
Mathematics::PolynomialRoots<Real>::PolynomialRoots(Real epsilon)
    : count{ 0 },
      maxRoot{ 4 },  // 默认支持维度 <= 4
      root(maxRoot),
      epsilon{ epsilon },
      maxIterations{ 128 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::IsValid() const noexcept
{
    if (MathType::GetValue(0) <= epsilon && 0 <= count && root.size() == gsl::narrow_cast<size_t>(maxRoot) && 0 <= maxIterations)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::PolynomialRoots<Real>::SetMaxIterations(int newMaxIterations) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    maxIterations = newMaxIterations;
}

template <typename Real>
int Mathematics::PolynomialRoots<Real>::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return count;
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::GetRoot(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return root.at(index);
}

template <typename Real>
typename Mathematics::PolynomialRoots<Real>::ContainerConstIter Mathematics::PolynomialRoots<Real>::GetBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return root.begin();
}

template <typename Real>
typename Mathematics::PolynomialRoots<Real>::ContainerConstIter Mathematics::PolynomialRoots<Real>::GetEnd() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (count <= boost::numeric_cast<int>(root.size()))
    {
        return root.begin() + count;
    }
    else
    {
        return root.end();
    }
}

template <typename Real>
void Mathematics::PolynomialRoots<Real>::SetRoot(int index, Real value)
{
    root.at(index) = value;
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindAlgebraic(Real constant, Real once)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (epsilon <= MathType::FAbs(once))
    {
        SetRoot(0, -constant / once);
        count = 1;

        return true;
    }
    else
    {
        count = 0;
        return false;
    }
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::GetBound(Real constant, Real once)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (MathType::FAbs(once) <= epsilon)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("多项式是恒定的，约束是无效的"s));
    }

    auto maxValue = MathType::FAbs(constant) / once;

    return MathType::GetValue(1) + maxValue;
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindAlgebraic(Real constant, Real once, Real secondary)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (MathType::FAbs(secondary) <= epsilon)
    {
        // 方程是一次的
        return FindAlgebraic(constant, once);
    }

    auto discriminant = once * once - MathType::GetValue(4) * constant * secondary;
    if (MathType::FAbs(discriminant) <= epsilon)
    {
        discriminant = MathType::GetValue(0);
    }

    if (discriminant < MathType::GetValue(0))
    {
        count = 0;
        return false;
    }

    auto lhs = MathType::GetRational(1, 2) / secondary;

    if (MathType::GetValue(0) < discriminant)
    {
        discriminant = MathType::Sqrt(discriminant);

        SetRoot(0, lhs * (-once - discriminant));
        SetRoot(1, lhs * (-once + discriminant));
        count = 2;
    }
    else
    {
        SetRoot(0, -lhs * once);
        count = 1;
    }

    return true;
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::GetBound(Real constant, Real once, Real secondary)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (MathType::FAbs(secondary) <= epsilon)
    {
        // 方程是一次的
        if (FindAlgebraic(constant, once))
        {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            return root[0];

#include SYSTEM_WARNING_POP
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("约束是无效的。"s));
        }
    }

    const auto value0 = MathType::FAbs(constant) / secondary;
    const auto value1 = MathType::FAbs(once) / secondary;
    const auto maxValue = (value1 <= value0 ? value0 : value1);

    return MathType::GetValue(1) + maxValue;
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindAlgebraic(Real constant, Real once, Real secondary, Real thrice)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (MathType::FAbs(thrice) <= epsilon)
    {
        // 方程是二次的
        return FindAlgebraic(constant, once, secondary);
    }

    // 确保多项式首一, x^3 + secondary * x^2 + once * x + constant = 0.
    constant /= thrice;
    once /= thrice;
    secondary /= thrice;

    // 转换为y^3 + a * y + b = 0 ，由x = y - c2 / 3。
    constexpr auto third = MathType::GetRational(1, 3);
    constexpr auto twentySeventh = MathType::GetRational(1, 27);
    const auto offset = third * secondary;
    const auto a = once - secondary * offset;
    const auto b = constant + secondary * (MathType::GetValue(2) * secondary * secondary - MathType::GetValue(9) * once) * twentySeventh;

    const auto halfB = (MathType::GetRational(1, 2))*b;

    auto discriminant = halfB * halfB + a * a * a * twentySeventh;

    if (MathType::FAbs(discriminant) <= epsilon)
    {
        discriminant = MathType::GetValue(0);

        const auto halfBPowThird = MathType::CubeRoot(halfB);

        SetRoot(0, MathType::GetValue(2) * halfBPowThird - offset);
        SetRoot(1, -halfBPowThird - offset);
        count = 2;
    }
    else if (MathType::GetValue(0) < discriminant)  // 1实,2虚根
    {
        discriminant = MathType::Sqrt(discriminant);
        const auto discriminantMinusHalfB = -halfB + discriminant;
        auto cubeRoot = MathType::CubeRoot(discriminantMinusHalfB);

        const auto negativeDiscriminantMinusHalfB = -halfB - discriminant;
        cubeRoot += MathType::CubeRoot(negativeDiscriminantMinusHalfB);
        cubeRoot -= offset;
        SetRoot(0, cubeRoot);
        count = 1;
    }
    else  // if (discr <  MathType::sm_Zero)
    {
        const auto dist = MathType::Sqrt(-third * a);
        const auto angle = third * MathType::ATan2(MathType::Sqrt(-discriminant), -halfB);
        const auto cosValue = MathType::Cos(angle);
        const auto sinValue = MathType::Sin(angle);
        SetRoot(0, MathType::GetValue(2) * dist * cosValue - offset);
        SetRoot(1, -dist * (cosValue + MathType::GetSqrt3() * sinValue) - offset);
        SetRoot(2, -dist * (cosValue - MathType::GetSqrt3() * sinValue) - offset);
        count = 3;
    }

    return true;
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindEigenvalues(Real constant, Real once, Real secondary, Real thrice, bool doBalancing, Real tolerance, bool isUseCompanion)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (MathType::FAbs(thrice) <= epsilon)
    {
        // 方程是二次的
        return FindAlgebraic(constant, once, secondary);
    }

    // 确保多项式首一, x^3 + secondary * x^2 + once * x + constant = 0
    constant /= thrice;
    once /= thrice;
    secondary /= thrice;

    // 构造3×3协同矩阵。
    VariableMatrixType matrix{ 3, 3 };  // 初始化为0。
    matrix(1, 0) = MathType::GetValue(1);
    matrix(2, 1) = MathType::GetValue(1);
    matrix(0, 2) = -constant;
    matrix(1, 2) = -once;
    matrix(2, 2) = -secondary;

    if (doBalancing)
    {
        if (isUseCompanion)
        {
            BalanceCompanion3(matrix, tolerance);
        }
        else
        {
            Balance3(matrix, tolerance);
        }
    }

    return QRIteration3(matrix);
}

template <typename Real>
void Mathematics::PolynomialRoots<Real>::BalanceCompanion3(VariableMatrixType& matrix, Real tolerance)
{
    auto a10 = MathType::FAbs(matrix(1, 0));
    auto a21 = MathType::FAbs(matrix(2, 1));
    auto a02 = MathType::FAbs(matrix(0, 2));
    auto a12 = MathType::FAbs(matrix(1, 2));
    auto a22 = MathType::FAbs(matrix(2, 2));

    for (auto i = 0; i < balanceCompanionIterationMax; ++i)
    {
        // 抵销 行/列 0
        auto rowNorm = a02;
        auto columnNorm = a10;
        auto scale = MathType::Sqrt(columnNorm / rowNorm);
        a02 *= scale;
        a10 = a02;

        // 抵销 行/列 1
        rowNorm = (a12 <= a10 ? a10 : a12);
        columnNorm = a21;
        scale = MathType::Sqrt(columnNorm / rowNorm);
        a10 *= scale;
        a12 *= scale;
        a21 /= scale;

        // 抵销 行/列 2
        rowNorm = (a22 <= a21 ? a21 : a22);
        columnNorm = (a12 <= a02 ? a02 : a12);
        if (columnNorm < a22)
        {
            columnNorm = a22;
        }
        scale = MathType::Sqrt(columnNorm / rowNorm);

        a21 *= scale;
        a02 /= scale;
        a12 /= scale;

        if (IsBalancedCompanion3(a10, a21, a02, a12, a22, tolerance))
        {
            break;
        }

        MATHEMATICS_ASSERTION_1(i != balanceCompanionIterationMax - 1, "超出最大迭代。\n");
    }

    matrix(1, 0) = (MathType::GetValue(0) <= matrix(1, 0) ? a10 : -a10);
    matrix(2, 1) = (MathType::GetValue(0) <= matrix(2, 1) ? a21 : -a21);
    matrix(0, 2) = (MathType::GetValue(0) <= matrix(0, 2) ? a02 : -a02);
    matrix(1, 2) = (MathType::GetValue(0) <= matrix(1, 2) ? a12 : -a12);
    matrix(2, 2) = (MathType::GetValue(0) <= matrix(2, 2) ? a22 : -a22);
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::IsBalancedCompanion3(Real a10, Real a21, Real a02, Real a12, Real a22, Real tolerance) noexcept
{
    // 行/列 0
    auto rowNorm = a02;
    auto columnNorm = a10;
    auto test = MathType::FAbs(MathType::GetValue(1) - columnNorm / rowNorm);
    if (tolerance < test)
    {
        return false;
    }

    // 行/列 1
    rowNorm = (a12 <= a10 ? a10 : a12);
    columnNorm = a21;
    test = MathType::FAbs(MathType::GetValue(1) - columnNorm / rowNorm);
    if (tolerance < test)
    {
        return false;
    }

    // 行/列 2
    rowNorm = (a22 <= a21 ? a21 : a22);
    columnNorm = (a12 <= a02 ? a02 : a12);
    if (columnNorm < a22)
    {
        columnNorm = a22;
    }
    test = MathType::FAbs(MathType::GetValue(1) - columnNorm / rowNorm);

    return test <= tolerance;
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::QRIteration3(VariableMatrixType& matrix)
{
    VariableLengthVectorType variableLengthVector{ 3 };

    for (auto i = 0; i < maxIterations; ++i)
    {
        auto rhs = epsilon * (MathType::FAbs(matrix(0, 0)) + MathType::FAbs(matrix(1, 1)));

        if (MathType::FAbs(matrix(1, 0)) <= rhs)
        {
            // mat(0,0)是一个根，解子矩阵的二次方程。
            const auto trace = matrix(1, 1) + matrix(2, 2);
            const auto det = matrix(1, 1) * matrix(2, 2) - matrix(1, 2) * matrix(2, 1);

            MAYBE_UNUSED const auto result = FindAlgebraic(det, -trace, MathType::GetValue(1));

            SetRoot(count, matrix(0, 0));
            ++count;

            return true;
        }

        rhs = epsilon * (MathType::FAbs(matrix(1, 1)) + MathType::FAbs(matrix(2, 2)));

        if (MathType::FAbs(matrix(2, 1)) <= rhs)
        {
            // mat(2,2)是一个根，解了子矩阵的二次方程。
            const auto trace = matrix(0, 0) + matrix(1, 1);
            const auto det = matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0);
            MAYBE_UNUSED const auto result = FindAlgebraic(det, -trace, MathType::GetValue(1));

            SetRoot(count, matrix(2, 2));
            ++count;

            return true;
        }

        FrancisQRStep(matrix, variableLengthVector);
    }

    // 从理论上讲，三次多项式总是有一个实数根，但如果超过最大迭代次数，怎么办？
    // 一些实验表明，当多项式近具有一个双根，算法的收敛速度慢。
    // 也许一个随机扰动“kick”系统中的一个位可能会奏效？

    MATHEMATICS_ASSERTION_4(false, "超出最大迭代\n");

    // 现在，清零最小的次对角项去分离矩阵。
    if (MathType::FAbs(matrix(1, 0)) <= MathType::FAbs(matrix(2, 1)))
    {
        // mat(0,0)是一个根，解了子矩阵的二次方程。
        const auto trace = matrix(1, 1) + matrix(2, 2);
        const auto det = matrix(1, 1) * matrix(2, 2) - matrix(1, 2) * matrix(2, 1);
        MAYBE_UNUSED const auto result = FindAlgebraic(det, -trace, MathType::GetValue(1));

        SetRoot(count, matrix(0, 0));
        ++count;
    }
    else
    {
        // mat(2,2)是一个根，解了子矩阵的二次方程。
        const auto trace = matrix(0, 0) + matrix(1, 1);
        const auto det = matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0);
        MAYBE_UNUSED const auto result = FindAlgebraic(det, -trace, MathType::GetValue(1));

        SetRoot(count, matrix(2, 2));
        ++count;
    }

    return true;
}

template <typename Real>
void Mathematics::PolynomialRoots<Real>::FrancisQRStep(VariableMatrixType& hessenbergMatrix, VariableLengthVectorType& vector)
{
    // 给定一个n乘n未还原的上Hessenberg矩阵H其尾部2×2主子阵具有特征值a1和a2，
    // 覆盖 H以Z^T * H * Z其中Z = P(1) * ... * P(n-2)是Householder矩阵和
    // Z^T*(H-a1*I)*(H-a2*I)是上三角。
    // assert:  H是未还原的上Hessenberg和 n >= 3

    // 计算(H - a1 * I) * (H - a2 * I)的第一列。
    const auto rowsNumber = hessenbergMatrix.GetRowsNumber();
    auto trace = hessenbergMatrix(rowsNumber - 2, rowsNumber - 2) + hessenbergMatrix(rowsNumber - 1, rowsNumber - 1);
    auto det = hessenbergMatrix(rowsNumber - 2, rowsNumber - 2) * hessenbergMatrix(rowsNumber - 1, rowsNumber - 1) -
               hessenbergMatrix(rowsNumber - 2, rowsNumber - 1) * hessenbergMatrix(rowsNumber - 1, rowsNumber - 2);
    Vector3Type uVector{ hessenbergMatrix(0, 0) * hessenbergMatrix(1, 1) + hessenbergMatrix(0, 1) * hessenbergMatrix(1, 0) - trace * hessenbergMatrix(0, 0) + det,
                     hessenbergMatrix(1, 0) * (hessenbergMatrix(0, 0) + hessenbergMatrix(1, 1) - trace),
                     hessenbergMatrix(1, 0) * hessenbergMatrix(2, 1) };

    // 覆盖H 使用 P(0) * H * P(0)^T.
    auto vVector = GetHouseholderVector(3, uVector);
    PremultiplyHouseholder(hessenbergMatrix, vector, 0, 2, 0, rowsNumber - 1, 3, vVector);
    PostmultiplyHouseholder(hessenbergMatrix, vector, 0, rowsNumber - 1, 0, 2, 3, vVector);

    for (auto i = 1; i <= rowsNumber - 3; ++i)
    {
        // 覆盖H 使用 P(i) * H * P(i)^T.
        uVector[0] = hessenbergMatrix(i, i - 1);
        uVector[1] = hessenbergMatrix(i + 1, i - 1);
        uVector[2] = hessenbergMatrix(i + 2, i - 1);
        vVector = GetHouseholderVector(3, uVector);

        // 列范围不需要为0 至 n - 1，因为零的图案发生在矩阵H
        PremultiplyHouseholder(hessenbergMatrix, vector, i, i + 2, i - 1, rowsNumber - 1, 3, vVector);

        // 行范围不需要为0 至 n - 1，因为零的图案发生在矩阵H
        auto rMax = i + 3;
        if (rowsNumber <= rMax)
        {
            rMax = rowsNumber - 1;
        }
        PostmultiplyHouseholder(hessenbergMatrix, vector, 0, rMax, i, i + 2, 3, vVector);
    }

    // 覆盖H 使用P(n-2)*H*P(n-2)^T.
    uVector[0] = hessenbergMatrix(rowsNumber - 2, rowsNumber - 3);
    uVector[1] = hessenbergMatrix(rowsNumber - 1, rowsNumber - 3);
    vVector = GetHouseholderVector(2, uVector);

    // 列范围不需要为0 至 n - 1，因为零的图案发生在矩阵H
    PremultiplyHouseholder(hessenbergMatrix, vector, rowsNumber - 2, rowsNumber - 1, rowsNumber - 3, rowsNumber - 1, 2, vVector);
    PostmultiplyHouseholder(hessenbergMatrix, vector, 0, rowsNumber - 1, rowsNumber - 2, rowsNumber - 1, 2, vVector);
}

template <typename Real>
typename Mathematics::PolynomialRoots<Real>::Vector3Type Mathematics::PolynomialRoots<Real>::GetHouseholderVector(int size, const Vector3Type& uVector)
{
    Vector3Type vVector{};

    // Householder向量V：
    // 给定一个向量的U，计算矢量V像这样
    // 使V[0] = 1 和 (I - 2 * V * V^T / |V|^2) * U 是除第一组分部分外都是零。
    // 矩阵P = I - 2 * V * V^T /| V|^2 是一个Householder变换，一个反射矩阵。

    auto length = MathType::GetValue(0);

    for (auto i = 0; i < size; ++i)
    {
        length += uVector[i] * uVector[i];
    }
    length = MathType::Sqrt(length);

    using namespace System;
    using System::operator*;

    if (epsilon < length)
    {
        auto inv = MathType::GetValue(1) / (uVector[0] + length * MathType::Sign(uVector[0]));
        vVector[0] = MathType::GetValue(1);
        for (auto i = 1; i < size; ++i)
        {
            vVector[i] = inv * uVector[i];
        }
    }
    else
    {
        // uVector是零向量，任何向量都可以
        vVector[0] = MathType::GetValue(1);
        for (int i = 1; i < size; ++i)
        {
            vVector[i] = MathType::GetValue(0);
        }
    }

    return vVector;
}

template <typename Real>
void Mathematics::PolynomialRoots<Real>::PremultiplyHouseholder(VariableMatrixType& matrix, VariableLengthVectorType& variableLengthVector, int rowMin, int rowMax, int columnMin, int columnMax, int vSize, const Vector3Type& vVector)
{
    // Householder预乘：给定的矩阵A和m×1矢量V采用V[0]= 1，
    // 令S是A的子矩阵m行的rmin <= r <= m + rmin - 1和列的子cmin <= c <= cmax。
    // 以P * S覆盖S其中 P = I - 2 * V * V^T / |V|^2。

    const auto subRows = rowMax - rowMin + 1;
    const auto subColunms = columnMax - columnMin + 1;

    auto sqrLen = MathType::GetValue(0);
    for (auto i = 0; i < vSize; ++i)
    {
        sqrLen += vVector[i] * vVector[i];
    }

    const auto beta = MathType::GetValue(-2) / sqrLen;
    for (auto column = 0; column < subColunms; ++column)
    {
        variableLengthVector[column] = MathType::GetValue(0);
        for (auto row = 0; row < subRows; ++row)
        {
            variableLengthVector[column] += vVector[row] * matrix(rowMin + row, columnMin + column);
        }
        variableLengthVector[column] *= beta;
    }

    for (auto row = 0; row < subRows; ++row)
    {
        for (auto column = 0; column < subColunms; ++column)
        {
            matrix(rowMin + row, columnMin + column) += vVector[row] * variableLengthVector[column];
        }
    }
}

template <typename Real>
void Mathematics::PolynomialRoots<Real>::PostmultiplyHouseholder(VariableMatrixType& matrix,
                                                                 VariableLengthVectorType& variableLengthVector,
                                                                 int rowMin,
                                                                 int rowMax,
                                                                 int columnMin,
                                                                 int columnMax,
                                                                 int vSize,
                                                                 const Vector3Type& vVector)
{
    // Householder预乘：给定的矩阵A和m×1矢量V采用V[0]= 1，
    // 令S是A的子矩阵m行的rmin <= r <= m + rmin - 1和列的子cmin <= c <= cmax。
    // 以P * S覆盖S其中 P = I - 2 * V * V^T / |V|^2。

    const auto subRows = rowMax - rowMin + 1;
    const auto subColumns = columnMax - columnMin + 1;

    auto sqrLen = MathType::GetValue(0);
    for (auto i = 0; i < vSize; ++i)
    {
        sqrLen += vVector[i] * vVector[i];
    }

    auto beta = MathType::GetValue(-2) / sqrLen;
    for (auto row = 0; row < subRows; ++row)
    {
        variableLengthVector[row] = MathType::GetValue(0);
        for (auto column = 0; column < subColumns; ++column)
        {
            variableLengthVector[row] += matrix(rowMin + row, columnMin + column) * vVector[column];
        }
        variableLengthVector[row] *= beta;
    }

    for (auto row = 0; row < subRows; ++row)
    {
        for (auto column = 0; column < subColumns; ++column)
        {
            matrix(rowMin + row, columnMin + column) += variableLengthVector[row] * vVector[column];
        }
    }
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::GetBound(Real constant, Real once, Real secondary, Real thrice)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (MathType::FAbs(thrice) <= epsilon)
    {
        // 多项式是二次。
        return GetBound(constant, once, secondary);
    }

    const auto invThrice = MathType::GetValue(1) / thrice;
    auto maxValue = MathType::FAbs(constant) * invThrice;

    const auto onceProduct = MathType::FAbs(once) * invThrice;
    if (maxValue < onceProduct)
    {
        maxValue = onceProduct;
    }

    const auto secondaryProduct = MathType::FAbs(secondary) * invThrice;
    if (maxValue < secondaryProduct)
    {
        maxValue = secondaryProduct;
    }

    return MathType::GetValue(1) + maxValue;
}

template <typename Real>
void Mathematics::PolynomialRoots<Real>::Balance3(VariableMatrixType& matrix, Real tolerance)
{
    for (auto loop = 0; loop < balanceIterationMax; ++loop)
    {
        for (auto index = 0; index < 3; ++index)
        {
            const auto rowNorm = GetRowNorm(index, matrix);
            const auto columnNorm = GetColumnNorm(index, matrix);
            const auto scale = MathType::Sqrt(columnNorm / rowNorm);
            const auto invScale = MathType::GetValue(1) / scale;
            ScaleRow(index, scale, matrix);
            ScaleColumn(index, invScale, matrix);
        }

        if (IsBalanced3(matrix, tolerance))
        {
            break;
        }

        MATHEMATICS_ASSERTION_1(loop != balanceIterationMax - 1, "超过最大迭代\n");
    }
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::IsBalanced3(VariableMatrixType& matrix, Real tolerance)
{
    for (auto i = 0; i < 3; ++i)
    {
        const auto rowNorm = GetRowNorm(i, matrix);
        const auto columnNorm = GetColumnNorm(i, matrix);
        const auto test = MathType::FAbs(MathType::GetValue(1) - columnNorm / rowNorm);
        if (tolerance < test)
        {
            return false;
        }
    }
    return true;
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::GetRowNorm(int row, VariableMatrixType& matrix)
{
    auto norm = MathType::GetValue(0);
    for (auto column = 0; column < matrix.GetColumnsNumber(); ++column)
    {
        const auto absValue = MathType::FAbs(matrix(row, column));
        if (norm < absValue)
        {
            norm = absValue;
        }
    }
    return norm;
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::GetColumnNorm(int column, VariableMatrixType& matrix)
{
    auto norm = MathType::GetValue(0);
    for (auto row = 0; row < matrix.GetRowsNumber(); ++row)
    {
        const auto absValue = MathType::FAbs(matrix(row, column));
        if (norm < absValue)
        {
            norm = absValue;
        }
    }
    return norm;
}

template <typename Real>
void Mathematics::PolynomialRoots<Real>::ScaleRow(int row, Real scale, VariableMatrixType& matrix)
{
    for (auto column = 0; column < matrix.GetColumnsNumber(); ++column)
    {
        matrix(row, column) *= scale;
    }
}

template <typename Real>
void Mathematics::PolynomialRoots<Real>::ScaleColumn(int column, Real scale, VariableMatrixType& matrix)
{
    for (auto row = 0; row < matrix.GetRowsNumber(); ++row)
    {
        matrix(row, column) *= scale;
    }
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::SpecialCubic(Real thrice, Real once, Real constant) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    // 解 thrice * r^3 + once * r = constant ，其中thrice > 0和once > 0，
    //
    // 让 r = D * sinh(u) 这里 D = sqrt(4 * once/(3 * thrice))
    // sinh(3 * u) = 4 * [sinh(u)]^3 + 3 * sinh(u) = E 这里 E = 4 * C / (A * D^3).
    // sinh(3 * u) = E 有解 u = (1 / 3)*log(E + sqrt(E^2 + 1))
    // 这导致 sinh(u) = ((E + sqrt(E^2 + 1))^{1 / 3} - (E + sqrt(E^2 + 1))^{-1 / 3}) / 2.
    // 因此,  r = D*((E + sqrt(E^2 + 1))^{1 / 3} - (E + sqrt(E^2 + 1))^{-1 / 3}) / 2

    const auto sqrt = MathType::Sqrt(MathType::GetValue(4) * once / (MathType::GetValue(3) * thrice));
    const auto value = MathType::GetValue(4) * constant / (thrice * sqrt * sqrt * sqrt);
    const auto pow = MathType::CubeRoot(value + MathType::Sqrt(value * value + MathType::GetValue(1)));
    const auto specialCubic = (MathType::GetRational(1, 2) * sqrt * (pow - (MathType::GetValue(1) / pow)));

    return specialCubic;
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindAlgebraic(Real constant, Real once, Real secondary, Real thrice, Real quartic)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (MathType::FAbs(quartic) <= epsilon)
    {
        // 多项式是三次的
        return FindAlgebraic(constant, once, secondary, thrice);
    }

    // 使多项式首一, x^4 + thrice * x^3 + secondary * x^2 + once * x + constant.
    constant /= quartic;
    once /= quartic;
    secondary /= quartic;
    thrice /= quartic;

    // 减至解三次多项式 y^3 + newSecondary * y^2 + newOnce * y + newConstant = 0.
    const auto newConstant = -thrice * thrice * constant + MathType::GetValue(4) * secondary * constant - once * once;
    const auto newOnce = thrice * once - MathType::GetValue(4) * constant;
    const auto newSecondary = -secondary;
    // 总是至少产生一个根
    if (!FindAlgebraic(newConstant, newOnce, newSecondary, MathType::GetValue(1)))
    {
        return false;
    }

    auto thriceRoot = root.at(0);

    count = 0;

    auto discriminant = MathType::GetRational(1, 4) * thrice * thrice - secondary + thriceRoot;
    if (MathType::FAbs(discriminant) <= epsilon)
    {
        discriminant = MathType::GetValue(0);
    }

    if (MathType::GetValue(0) < discriminant)
    {
        auto discriminantSqrt = MathType::Sqrt(discriminant);
        auto t1 = MathType::GetRational(3, 4) * thrice * thrice - discriminantSqrt * discriminantSqrt - MathType::GetValue(2) * secondary;
        auto t2 = (MathType::GetValue(4) * thrice * secondary - MathType::GetValue(8) * once - thrice * thrice * thrice) /
                  (MathType::GetValue(4) * discriminantSqrt);

        auto tPlus = t1 + t2;
        auto tMinus = t1 - t2;
        if (MathType::FAbs(tPlus) <= epsilon)
        {
            tPlus = MathType::GetValue(0);
        }
        if (MathType::FAbs(tMinus) <= epsilon)
        {
            tMinus = MathType::GetValue(0);
        }

        if (MathType::GetValue(0) <= tPlus)
        {
            auto tPlusSqrt = MathType::Sqrt(tPlus);
            SetRoot(count, MathType::GetRational(-1, 4) * thrice + (MathType::GetRational(1, 2) * (discriminantSqrt + tPlusSqrt)));
            ++count;
            SetRoot(count, MathType::GetRational(-1, 4) * thrice + (MathType::GetRational(1, 2) * (discriminantSqrt - tPlusSqrt)));
            ++count;
        }
        if (MathType::GetValue(0) <= tMinus)
        {
            auto e = MathType::Sqrt(tMinus);
            SetRoot(count, MathType::GetRational(-1, 4) * thrice + (MathType::GetRational(1, 2) * (e - discriminantSqrt)));
            ++count;
            SetRoot(count, MathType::GetRational(-1, 4) * thrice - (MathType::GetRational(1, 2) * (e + discriminantSqrt)));
            ++count;
        }
    }
    else if (discriminant < MathType::GetValue(0))
    {
        count = 0;
    }
    else
    {
        auto t2 = thriceRoot * thriceRoot - MathType::GetValue(4) * constant;
        if (-epsilon <= t2)
        {
            // 取整为零
            if (t2 < MathType::GetValue(0))
            {
                t2 = MathType::GetValue(0);
            }

            t2 = MathType::GetValue(2) * MathType::Sqrt(t2);
            auto t1 = MathType::GetRational(3, 4) * thrice * thrice - MathType::GetValue(2) * secondary;
            auto tPlus = t1 + t2;
            if (epsilon <= tPlus)
            {
                auto tPlusSqrt = MathType::Sqrt(tPlus);
                SetRoot(count, MathType::GetRational(-1, 4) * thrice + MathType::GetRational(1, 2) * tPlusSqrt);
                ++count;
                SetRoot(count, MathType::GetRational(-1, 4) * thrice - MathType::GetRational(1, 2) * tPlusSqrt);
                ++count;
            }
            auto tMinus = t1 - t2;
            if (epsilon <= tMinus)
            {
                auto tMinusSqrt = MathType::Sqrt(tMinus);
                SetRoot(count, MathType::GetRational(-1, 4) * thrice + MathType::GetRational(1, 2) * tMinusSqrt);
                ++count;
                SetRoot(count, MathType::GetRational(-1, 4) * thrice - MathType::GetRational(1, 2) * tMinusSqrt);
                ++count;
            }
        }
    }

    return 0 < count;
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindEigenvalues(Real constant, Real once, Real secondary, Real thrice, Real quartic, bool doBalancing, Real tolerance)
{
    if (MathType::FAbs(quartic) <= epsilon)
    {
        // 多项式是三次。
        return FindAlgebraic(constant, once, secondary, thrice);
    }

    // 使多项式首一, x^4 + thrice * x^3 + secondary * x^2 + once * x + constant.
    constant /= quartic;
    once /= quartic;
    secondary /= quartic;
    thrice /= quartic;

    // 构建4×4的同伴矩阵。初始化为零
    VariableMatrixType matrix{ 4, 4 };
    matrix(1, 0) = MathType::GetValue(1);
    matrix(2, 1) = MathType::GetValue(1);
    matrix(3, 2) = MathType::GetValue(1);
    matrix(0, 3) = -constant;
    matrix(1, 3) = -once;
    matrix(2, 3) = -secondary;
    matrix(3, 3) = -thrice;

    if (doBalancing)
    {
        BalanceCompanion4(matrix, tolerance);
    }

    return QRIteration4(matrix);
}

template <typename Real>
void Mathematics::PolynomialRoots<Real>::BalanceCompanion4(VariableMatrixType& matrix, Real tolerance)
{
    auto a10 = MathType::FAbs(matrix(1, 0));
    auto a21 = MathType::FAbs(matrix(2, 1));
    auto a32 = MathType::FAbs(matrix(3, 2));
    auto a03 = MathType::FAbs(matrix(0, 3));
    auto a13 = MathType::FAbs(matrix(1, 3));
    auto a23 = MathType::FAbs(matrix(2, 3));
    auto a33 = MathType::FAbs(matrix(3, 3));

    for (auto i = 0; i < balanceCompanionIterationMax; ++i)
    {
        // 平衡 行/列 0
        auto rowNorm = a03;
        auto columnNorm = a10;
        auto scale = MathType::Sqrt(columnNorm / rowNorm);
        a03 *= scale;
        a10 = a03;

        // 平衡 行/列 1
        rowNorm = (a13 <= a10 ? a10 : a13);
        columnNorm = a21;
        scale = MathType::Sqrt(columnNorm / rowNorm);
        a10 *= scale;
        a13 *= scale;
        a21 /= scale;

        // 平衡 行/列 2
        rowNorm = (a21 >= a23 ? a21 : a23);
        columnNorm = a32;
        scale = MathType::Sqrt(columnNorm / rowNorm);
        a21 *= scale;
        a23 *= scale;
        a32 /= scale;

        // 平衡 行/列 3
        rowNorm = (a33 <= a32 ? a32 : a33);
        columnNorm = (a13 <= a03 ? a03 : a13);
        if (columnNorm < a23)
        {
            columnNorm = a23;
        }
        if (columnNorm < a33)
        {
            columnNorm = a33;
        }
        scale = MathType::Sqrt(columnNorm / rowNorm);
        a32 *= scale;
        a03 /= scale;
        a13 /= scale;
        a23 /= scale;

        if (IsBalancedCompanion4(a10, a21, a32, a03, a13, a23, a33, tolerance))
        {
            break;
        }

        MATHEMATICS_ASSERTION_1(i != balanceCompanionIterationMax - 1, "超过最大迭代\n");
    }

    matrix(1, 0) = (MathType::GetValue(0) <= matrix(1, 0) ? a10 : -a10);
    matrix(2, 1) = (MathType::GetValue(0) <= matrix(2, 1) ? a21 : -a21);
    matrix(3, 2) = (MathType::GetValue(0) <= matrix(3, 2) ? a32 : -a32);
    matrix(0, 3) = (MathType::GetValue(0) <= matrix(0, 3) ? a03 : -a03);
    matrix(1, 3) = (MathType::GetValue(0) <= matrix(1, 3) ? a13 : -a13);
    matrix(2, 3) = (MathType::GetValue(0) <= matrix(2, 3) ? a23 : -a23);
    matrix(3, 3) = (MathType::GetValue(0) <= matrix(3, 3) ? a33 : -a33);
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::IsBalancedCompanion4(Real a10, Real a21, Real a32, Real a03, Real a13, Real a23, Real a33, Real tolerance) noexcept
{
    // 行/列 0
    auto rowNorm = a03;
    auto columnNorm = a10;
    auto test = MathType::FAbs(MathType::GetValue(1) - columnNorm / rowNorm);
    if (tolerance < test)
    {
        return false;
    }

    // 行/列 1
    rowNorm = (a13 <= a10 ? a10 : a13);
    columnNorm = a21;
    test = MathType::FAbs(MathType::GetValue(1) - columnNorm / rowNorm);
    if (tolerance < test)
    {
        return false;
    }

    // 行/列 2
    rowNorm = (a23 <= a21 ? a21 : a23);
    columnNorm = a32;
    test = MathType::FAbs(MathType::GetValue(1) - columnNorm / rowNorm);
    if (tolerance < test)
    {
        return false;
    }

    // 行/列 3
    rowNorm = (a33 <= a32 ? a32 : a33);
    columnNorm = (a13 <= a03 ? a03 : a13);
    if (columnNorm < a23)
    {
        columnNorm = a23;
    }
    if (columnNorm < a33)
    {
        columnNorm = a33;
    }
    test = MathType::FAbs(MathType::GetValue(1) - columnNorm / rowNorm);

    return test <= tolerance;
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::QRIteration4(VariableMatrixType& matrix)
{
    VariableLengthVectorType vector{ 4 };

    for (auto i = 0; i < maxIterations; ++i)
    {
        auto rhs = epsilon * (MathType::FAbs(matrix(0, 0)) + MathType::FAbs(matrix(1, 1)));

        if (MathType::FAbs(matrix(1, 0)) <= rhs)
        {
            // matrix(0,0)是一个根，减少3×3子矩阵
            // 避免拷贝，并通过行/列偏移量的FrancisQR方法。
            VariableMatrixType matrixMS{ 3, 3 };

            matrixMS(0, 0) = matrix(1, 1);
            matrixMS(0, 1) = matrix(1, 2);
            matrixMS(0, 2) = matrix(1, 3);
            matrixMS(1, 0) = matrix(2, 1);
            matrixMS(1, 1) = matrix(2, 2);
            matrixMS(1, 2) = matrix(2, 3);
            matrixMS(2, 0) = matrix(3, 1);
            matrixMS(2, 1) = matrix(3, 2);
            matrixMS(2, 2) = matrix(3, 3);
            if (!QRIteration3(matrixMS))
            {
                return false;
            }
            root.at(count++) = matrix(0, 0);

            return true;
        }

        rhs = epsilon * (MathType::FAbs(matrix(1, 1)) + MathType::FAbs(matrix(2, 2)));

        if (MathType::FAbs(matrix(2, 1)) <= rhs)
        {
            // 该矩阵被分解成两个2×2块。解这些块的二次方程式。
            auto trace = matrix(0, 0) + matrix(1, 1);
            auto det = matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0);
            if (!FindAlgebraic(det, -trace, MathType::GetValue(1)))
            {
                return false;
            }
            const auto saveCount = count;
            constexpr auto saveRootSize = 2;
            std::array<Real, saveRootSize> saveRoot{};
            for (auto j = 0; j < saveCount && j < saveRootSize; ++j)
            {
                saveRoot.at(j) = root.at(j);
            }

            trace = matrix(2, 2) + matrix(3, 3);
            det = matrix(2, 2) * matrix(3, 3) - matrix(2, 3) * matrix(3, 2);
            if (!FindAlgebraic(det, -trace, MathType::GetValue(1)))
            {
                return false;
            }
            for (auto j = 0; j < saveCount && j < saveRootSize; ++j)
            {
                root.at(count++) = saveRoot.at(j);
            }

            return 0 < count;
        }

        rhs = epsilon * (MathType::FAbs(matrix(2, 2)) + MathType::FAbs(matrix(3, 3)));

        if (MathType::FAbs(matrix(3, 2)) <= rhs)
        {
            // matrix(3,3)是一个根，减少3×3子矩阵
            // 避免拷贝，并通过行/列偏移量的FrancisQR方法。
            VariableMatrixType matrixMS{ 3, 3 };

            matrixMS(0, 0) = matrix(0, 0);
            matrixMS(0, 1) = matrix(0, 1);
            matrixMS(0, 2) = matrix(0, 2);
            matrixMS(1, 0) = matrix(1, 0);
            matrixMS(1, 1) = matrix(1, 1);
            matrixMS(1, 2) = matrix(1, 2);
            matrixMS(2, 0) = matrix(2, 0);
            matrixMS(2, 1) = matrix(2, 1);
            matrixMS(2, 2) = matrix(2, 2);

            if (!QRIteration3(matrixMS))
            {
                return false;
            }
            root.at(count++) = matrix(3, 3);

            return true;
        }

        FrancisQRStep(matrix, vector);
    }

    // 如果超过最大迭代次数，怎么办？
    // 也许一个随机扰动“kick”系统中的一个位可能会奏效？

    MATHEMATICS_ASSERTION_4(false, "超出最大迭代\n");

    // 现在，分离最小次对角项矩阵。
    auto i = 0;
    auto minValue = MathType::FAbs(matrix(1, 0));
    auto absValue = MathType::FAbs(matrix(2, 1));
    if (absValue < minValue)
    {
        minValue = absValue;
        i = 1;
    }
    absValue = MathType::FAbs(matrix(3, 2));
    if (absValue < minValue)
    {
        minValue = absValue;
        i = 2;
    }

    if (i == 0)
    {
        // matrix(0,0)是一个根，减少3×3子矩阵
        // 避免拷贝，并通过行/列偏移量的FrancisQR方法。
        VariableMatrixType matrixMS{ 3, 3 };

        matrixMS(0, 0) = matrix(1, 1);
        matrixMS(0, 1) = matrix(1, 2);
        matrixMS(0, 2) = matrix(1, 3);
        matrixMS(1, 0) = matrix(2, 1);
        matrixMS(1, 1) = matrix(2, 2);
        matrixMS(1, 2) = matrix(2, 3);
        matrixMS(2, 0) = matrix(3, 1);
        matrixMS(2, 1) = matrix(3, 2);
        matrixMS(2, 2) = matrix(3, 3);
        if (!QRIteration3(matrixMS))
        {
            return false;
        }
        root.at(count++) = matrix(0, 0);
    }
    else if (i == 1)
    {
        // 该矩阵被分解成两个2×2块。解这些块的二次方程式。
        auto trace = matrix(0, 0) + matrix(1, 1);
        auto det = matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0);
        if (!FindAlgebraic(det, -trace, MathType::GetValue(1)))
        {
            return false;
        }
        const auto saveCount = count;
        std::array<Real, 2> saveRoot{};
        for (auto j = 0; j < saveCount; ++j)
        {
            saveRoot.at(j) = root.at(j);
        }

        trace = matrix(2, 2) + matrix(3, 3);
        det = matrix(2, 2) * matrix(3, 3) - matrix(2, 3) * matrix(3, 2);
        if (!FindAlgebraic(det, -trace, MathType::GetValue(1)))
        {
            return false;
        }
        for (auto j = 0; j < saveCount; ++j)
        {
            root.at(count++) = saveRoot.at(j);
        }
    }
    else  // i == 2
    {
        // matrix(3,3)是一个根，减少3×3子矩阵
        // 避免拷贝，并通过行/列偏移量的FrancisQR方法。
        VariableMatrixType matrixMS{ 3, 3 };

        matrixMS(0, 0) = matrix(0, 0);
        matrixMS(0, 1) = matrix(0, 1);
        matrixMS(0, 2) = matrix(0, 2);
        matrixMS(1, 0) = matrix(1, 0);
        matrixMS(1, 1) = matrix(1, 1);
        matrixMS(1, 2) = matrix(1, 2);
        matrixMS(2, 0) = matrix(2, 0);
        matrixMS(2, 1) = matrix(2, 1);
        matrixMS(2, 2) = matrix(2, 2);
        if (!QRIteration3(matrixMS))
        {
            return false;
        }
        root.at(count++) = matrix(3, 3);
    }

    return 0 < count;
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::GetBound(Real constant, Real once, Real secondary, Real thrice, Real quartic)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (MathType::FAbs(quartic) <= epsilon)
    {
        // 多项式是三次的
        return GetBound(constant, once, secondary, thrice);
    }

    auto maxValue = MathType::FAbs(constant) / quartic;

    auto value = MathType::FAbs(once) / quartic;
    if (maxValue < value)
    {
        maxValue = value;
    }

    value = MathType::FAbs(secondary) / quartic;
    if (maxValue < value)
    {
        maxValue = value;
    }

    value = MathType::FAbs(thrice) / quartic;
    if (maxValue < value)
    {
        maxValue = value;
    }

    return MathType::GetValue(1) + maxValue;
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindBisection(const PolynomialType& polynomial, int digits)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    auto bound = GetBound(polynomial);

    if (MathType::GetValue(0) <= bound)
        return FindBisection(polynomial, -bound, bound, digits);
    else
        return false;
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::GetBound(const PolynomialType& polynomial)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    auto copyPolynomial = polynomial;
    copyPolynomial.MakeCompress(epsilon);
    const auto degree = copyPolynomial.GetDegree();
    if (degree < 1)
    {
        // 多项式是常数，返回无效边界。
        return MathType::GetValue(-1);
    }

    auto invCopyDegree = MathType::GetValue(1) / copyPolynomial[degree];
    auto maxValue = MathType::GetValue(0);
    for (auto i = 0; i < degree; ++i)
    {
        auto value = MathType::FAbs(copyPolynomial[i]) * invCopyDegree;
        if (maxValue < value)
        {
            maxValue = value;
        }
    }

    return MathType::GetValue(1) + maxValue;
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindBisection(const PolynomialType& polynomial, Real xMin, Real xMax, int digits)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    // 如果需要重新分配数组。
    if (maxRoot < polynomial.GetDegree())
    {
        maxRoot = polynomial.GetDegree();
        root.resize(maxRoot);
    }

    auto bisection = MathType::GetValue(0);
    if (polynomial.GetDegree() == 1)
    {
        if (Bisection(polynomial, xMin, xMax, digits, bisection))
        {
            count = 1;

            root.at(0) = bisection;

            return true;
        }
        count = 0;

        return false;
    }

    // 获取导数多项式的根。
    auto derivative = polynomial.GetDerivative();
    if (!FindBisection(derivative, xMin, xMax, digits))
    {
        return false;
    }

    auto newCount = 0;
    const auto newRootCount = count + 1;
    Container newRoot(newRootCount);

    if (0 < count)
    {
        // 查找根在[xmin,root[0]].
        if (Bisection(polynomial, xMin, root.at(0), digits, bisection))
        {
            newRoot.at(newCount++) = bisection;
        }

        // 查找根在[root[i],root[i + 1]] 对 0 <= i <= count - 2.
        for (auto i = 0; i <= count - 2; ++i)
        {
            const auto nextRootIndex = i + 1;
            if (Bisection(polynomial, root.at(i), root.at(nextRootIndex), digits, bisection))
            {
                newRoot.at(newCount++) = bisection;
            }
        }

        // 查找根在 [root[count - 1],xmax].
        const auto rootIndex = count - 1;
        if (Bisection(polynomial, root.at(rootIndex), xMax, digits, bisection))
        {
            newRoot.at(newCount++) = bisection;
        }
    }
    else
    {
        // 多项式是在[xmin,xmax]单调，最多有一个根。
        if (Bisection(polynomial, xMin, xMax, digits, bisection))
        {
            newRoot.at(newCount++) = bisection;
        }
    }

    // 复制到旧缓冲区。
    if (0 < newCount)
    {
        count = 1;
        root.at(0) = newRoot.at(0);
        for (auto i = 1; i < newCount; ++i)
        {
            const auto beforeRootIndex = i - 1;

            if (auto rootDifference = newRoot.at(i) - newRoot.at(beforeRootIndex);
                epsilon < MathType::FAbs(rootDifference))
            {
                root.at(count++) = newRoot.at(i);
            }
        }
    }
    else
    {
        count = 0;
    }

    return 0 < count;
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::Bisection(const PolynomialType& polynomial, Real xMin, Real xMax, int digits, Real& result) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    auto xMinPolynomial = polynomial(xMin);
    if (MathType::FAbs(xMinPolynomial) <= MathType::GetZeroTolerance())
    {
        result = xMin;
        return true;
    }

    auto xMaxPolynomial = polynomial(xMax);
    if (MathType::FAbs(xMaxPolynomial) <= MathType::GetZeroTolerance())
    {
        result = xMax;
        return true;
    }

    if (MathType::GetValue(0) < xMinPolynomial * xMaxPolynomial)
    {
        return false;
    }

    // 确定迭代次数来获得'digits'的准确性..
    auto differenceLog = MathType::Log(xMax - xMin);
    auto digitsProductLN10 = static_cast<Real>(digits) * MathType::GetLN10();
    auto arg = (differenceLog + digitsProductLN10) / MathType::GetLN2();
    const auto maxIter = static_cast<int>(arg + MathType::GetRational(1, 2));

    for (auto i = 0; i < maxIter; ++i)
    {
        result = MathType::GetRational(1, 2) * (xMin + xMax);
        auto rootPolynomial = polynomial(result);
        auto product = rootPolynomial * xMinPolynomial;
        if (product < MathType::GetValue(0))
        {
            xMax = result;
            xMaxPolynomial = rootPolynomial;
        }
        else if (MathType::GetValue(0) < product)
        {
            xMin = result;
            xMinPolynomial = rootPolynomial;
        }
        else
        {
            break;
        }
    }

    return true;
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::AllRealPartsNegative(const PolynomialType& polynomial)
{
    // 使用系数的一个副本，以后调用将改变副本。
    const auto degree = polynomial.GetDegree();
    Container coeff{};
    for (auto i = 0; i < degree + 1; ++i)
    {
        coeff.emplace_back(polynomial[i]);
    }

    // 使多项式首一。

    if (epsilon < MathType::FAbs(coeff.at(degree) - MathType::GetValue(1)))
    {
        for (auto i = 0; i < degree; ++i)
        {
            coeff.at(i) /= coeff.at(degree);
        }

        coeff.at(degree) = MathType::GetValue(1);
    }

    return AllRealPartsNegative(degree, coeff);
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::AllRealPartsPositive(const PolynomialType& polynomial)
{
    // 使用系数的一个副本，以后调用将改变副本。
    const auto degree = polynomial.GetDegree();
    Container coeff{};
    for (auto i = 0; i < degree + 1; ++i)
    {
        coeff.emplace_back(polynomial[i]);
    }

    // 使多项式首一。
    if (epsilon < MathType::FAbs(coeff.at(degree) - MathType::GetValue(1)))
    {
        for (auto i = 0; i < degree; ++i)
        {
            coeff.at(i) /= coeff.at(degree);
        }

        coeff.at(degree) = MathType::GetValue(1);
    }

    // 反射 z -> -z.
    auto sign = -1;
    for (auto i = degree - 1; 0 <= i; --i)
    {
        coeff.at(i) *= sign;
        sign = -sign;
    }

    return AllRealPartsNegative(degree, coeff);
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::AllRealPartsNegative(int degree, Container& coeff)
{
    MATHEMATICS_ASSERTION_1(MathType::FAbs(coeff.at(degree) - MathType::GetValue(1)) <= epsilon, "多项式首1\n");

    const auto degreeMinus1 = degree - 1;
    if (coeff.at(degreeMinus1) <= MathType::GetValue(0))
    {
        return false;
    }

    if (degree == 1)
    {
        return true;
    }

    Container tmpCoeff(degree);

    tmpCoeff.at(0) = MathType::GetValue(2) * coeff.at(0) * coeff.at(degreeMinus1);

    for (auto i = 1; i <= degree - 2; ++i)
    {
        tmpCoeff.at(i) = coeff.at(degreeMinus1) * coeff.at(i);
        if (((degree - i) % 2) == 0)
        {
            const auto next = i - 1;
            tmpCoeff.at(i) -= coeff.at(next);
        }
        tmpCoeff.at(i) *= MathType::GetValue(2);
    }

    tmpCoeff.at(degreeMinus1) = MathType::GetValue(2) * coeff.at(degreeMinus1) * coeff.at(degreeMinus1);

    auto nextDegree = 0;
    for (nextDegree = degree - 1; 0 <= nextDegree; --nextDegree)
    {
        if (epsilon < MathType::FAbs(tmpCoeff.at(nextDegree)))
        {
            break;
        }
    }
    for (auto i = 0; i <= nextDegree - 1; ++i)
    {
        coeff.at(i) = tmpCoeff.at(i) / tmpCoeff.at(nextDegree);
    }

    if (0 <= nextDegree)
    {
        coeff.at(nextDegree) = MathType::GetValue(1);

        return AllRealPartsNegative(nextDegree, coeff);
    }
    else
    {
        return false;
    }
}

template <typename Real>
int Mathematics::PolynomialRoots<Real>::GetRootCount(const PolynomialType& polynomial, Real begin, Real end)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    const auto degree = polynomial.GetDegree();
    auto coeff = polynomial.GetCoefficients();

    if (degree == 0)
    {
        // 多项式是在区间恒定。
        if (MathType::FAbs(coeff.at(0)) <= epsilon)
        {
            return 0;
        }
        else
        {
            // 表示“无穷大”
            return -1;
        }
    }

    // 生成Sturm序列。
    std::vector<PolynomialType> sturm{ PolynomialType{ polynomial }, polynomial.GetDerivative() };
    auto beginPolynomialIndex = 0;
    auto endPolynomialIndex = 1;
    auto currentIndex = sturm.size() - 1;

    while (0 < sturm.at(endPolynomialIndex).GetDegree())
    {
        auto divide = sturm.at(beginPolynomialIndex).Divide(sturm.at(endPolynomialIndex), epsilon);
        auto quot = divide.GetQuotient();
        auto remainder = -divide.GetRemainder();

        sturm.emplace_back(remainder);

        currentIndex = sturm.size() - 1;
        beginPolynomialIndex = endPolynomialIndex;
        endPolynomialIndex = boost::numeric_cast<int>(currentIndex);
    }

    const auto numSturm = boost::numeric_cast<int>(sturm.size());

    // 计数在begin的符号改变。
    auto signChanges0 = 0;
    if (MathType::FAbs(begin + MathType::maxReal) <= epsilon)
    {
        Real value0{};

        if (sturm.at(0).GetDegree() & 1)
        {
            value0 = -sturm.at(0).GetEnd();
        }
        else
        {
            value0 = sturm.at(0).GetEnd();
        }

        if (MathType::FAbs(value0) < epsilon)
        {
            value0 = MathType::GetValue(0);
        }

        for (auto i = 1; i < numSturm; ++i)
        {
            Real value1{};

            if (sturm.at(i).GetDegree() & 1)
            {
                value1 = -sturm.at(i).GetEnd();
            }
            else
            {
                value1 = sturm.at(i).GetEnd();
            }

            if (MathType::FAbs(value1) < epsilon)
            {
                value1 = MathType::GetValue(0);
            }

            if (value0 * value1 < MathType::GetValue(0) || MathType::FAbs(value0) < epsilon)
            {
                ++signChanges0;
            }

            value0 = value1;
        }
    }
    else
    {
        Real value0{};

        value0 = sturm.at(0)(begin);
        if (MathType::FAbs(value0) < epsilon)
        {
            value0 = MathType::GetValue(0);
        }

        for (auto i = 1; i < numSturm; ++i)
        {
            Real value1{};

            value1 = sturm.at(0)(begin);
            if (MathType::FAbs(value1) < epsilon)
            {
                value1 = MathType::GetValue(0);
            }

            if (value0 * value1 < MathType::GetValue(0) || MathType::FAbs(value0) < epsilon)
            {
                ++signChanges0;
            }

            value0 = value1;
        }
    }

    // 计数在end的符号改变。
    auto signChanges1 = 0;
    if (MathType::FAbs(end - MathType::maxReal) <= epsilon)
    {
        auto value0 = sturm.at(0).GetEnd();
        if (MathType::FAbs(value0) < epsilon)
        {
            value0 = MathType::GetValue(0);
        }

        for (auto i = 1; i < numSturm; ++i)
        {
            auto value1 = sturm.at(0).GetEnd();
            if (MathType::FAbs(value1) < epsilon)
            {
                value1 = MathType::GetValue(0);
            }

            if (value0 * value1 < MathType::GetValue(0) || MathType::FAbs(value0) < epsilon)
            {
                ++signChanges1;
            }

            value0 = value1;
        }
    }
    else
    {
        auto value0 = sturm.at(0)(end);
        if (MathType::FAbs(value0) < epsilon)
        {
            value0 = MathType::GetValue(0);
        }

        for (auto i = 1; i < numSturm; ++i)
        {
            auto value1 = sturm.at(i)(end);
            if (MathType::FAbs(value1) < epsilon)
            {
                value1 = MathType::GetValue(0);
            }

            if (value0 * value1 < MathType::GetValue(0) || MathType::FAbs(value0) < epsilon)
            {
                ++signChanges1;
            }

            value0 = value1;
        }
    }

    if (signChanges1 <= signChanges0)
    {
        return signChanges0 - signChanges1;
    }

    // 理论上我们不应该到达这里。
    MATHEMATICS_ASSERTION_1(false, "意外的情况\n");

    return 0;
}
#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_DETAIL_H
