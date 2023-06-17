///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:08)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM_DETAIL_H

#include "IntpBSplineUniform.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::IntpBSplineUniform<Real>::IntpBSplineUniform(int dims, int degree, const std::vector<int>& dim, const std::vector<Real>& data)
    : dims{ dims },
      degree{ degree },
      dp1{ degree + 1 },
      dp1ToN{ 1 },
      dp1To2N{},
      dim{ dim },
      data{ data },
      domMin(dims),
      domMax(dims),
      gridMin(dims),
      gridMax(dims),
      base(dims),
      oldBase(dims),
      matrix{ BlendMatrix(degree) },
      cache{},
      inter{},
      poly{ dims, dp1 },
      coeff{ dp1, dp1 },
      product{},
      skip{},
      evaluateCallback{ nullptr }
{
    MATHEMATICS_ASSERTION_0(dims > 0 && degree > 0, "无效输入。\n");

    for (auto i = 0; i < dims; ++i)
    {
        MATHEMATICS_ASSERTION_0(dim.at(i) > degree + 1, "无效输入。\n");
    }

    for (auto i = 0; i < dims; ++i)
    {
        dp1ToN *= dp1;
    }
    dp1To2N = dp1ToN * dp1ToN;

    for (auto i = 0; i < dims; ++i)
    {
        auto domSup = Math<Real>::GetValue(dim.at(i) - degree + 1);
        auto next = (Math<Real>::GetRational(1, 2)) * (Math<Real>::GetValue(1) + domSup);
        do
        {
            domMax.at(i) = next;
            next = (Math<Real>::GetRational(1, 2)) * (next + domSup);
        } while (next < domSup);
        domMin.at(i) = Math<Real>::GetValue(1);
    }

    for (auto i = 0; i < dims; ++i)
    {
        gridMin.at(i) = -1;
        gridMax.at(i) = -1;
    }

    for (auto i = 0; i < dims; ++i)
    {
        oldBase.at(i) = -1;
    }

    cache.resize(dp1ToN);
    inter.resize(dp1ToN);

    for (auto row = 0; row <= degree; ++row)
    {
        for (auto col = row; col <= degree; ++col)
        {
            coeff[row][col] = Math<Real>::GetValue(1);
            for (auto i = 0; i <= row - 1; ++i)
            {
                coeff[row][col] *= Math<Real>::GetValue(col - i);
            }
        }
    }

    product.resize(dp1To2N);
    skip.resize(dp1To2N);
    const auto coordSize = 2 * dims;
    std::vector<int> coord(coordSize);

    for (auto j = 0; j < dp1To2N; ++j)
    {
        auto temp = j;
        for (auto i = 0; i < 2 * dims; ++i)
        {
            coord.at(i) = temp % dp1;
            temp /= dp1;
        }

        product.at(j) = Math<Real>::GetValue(1);
        for (auto i = 0; i < dims; ++i)
        {
            const auto nextIndex = i + dims;
            product.at(j) *= matrix[coord.at(i)][coord.at(nextIndex)];
        }

        skip.at(j) = 1;
    }

    for (auto i = 0; i < dp1To2N;)
    {
        auto j = i + 1;
        for (; j < dp1To2N && product.at(j) == Math<Real>::GetValue(0); ++j)
        {
            ++skip.at(i);
        }
        i = j;
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntpBSplineUniform<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIAN

template <typename Real>
int Mathematics::IntpBSplineUniform<Real>::GetDimension() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return dims;
}

template <typename Real>
int Mathematics::IntpBSplineUniform<Real>::GetDegree() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return degree;
}

template <typename Real>
Real Mathematics::IntpBSplineUniform<Real>::GetDomainMin(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return domMin.at(i);
}

template <typename Real>
Real Mathematics::IntpBSplineUniform<Real>::GetDomainMax(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return domMax.at(i);
}

template <typename Real>
int Mathematics::IntpBSplineUniform<Real>::GetGridMin(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return gridMin.at(i);
}

template <typename Real>
int Mathematics::IntpBSplineUniform<Real>::GetGridMax(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return gridMax.at(i);
}

template <typename Real>
void Mathematics::IntpBSplineUniform<Real>::SetPolynomial(int order, Real diff, VariableLengthVector<Real>& polynomial)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto diffPower = Math<Real>::GetValue(1);
    for (auto i = order; i <= degree; ++i)
    {
        polynomial[i] = coeff[order][i] * diffPower;
        diffPower *= diff;
    }
}

template <typename Real>
int Mathematics::IntpBSplineUniform<Real>::Choose(int n, int k) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (n <= 1 || k >= n)
    {
        return 1;
    }

    auto result = 1;

    for (auto i = 0; i < k; ++i)
    {
        result *= n - i;
    }
    for (auto i = 1; i <= k; ++i)
    {
        result /= i;
    }

    return result;
}

template <typename Real>
Mathematics::VariableMatrix<Real> Mathematics::IntpBSplineUniform<Real>::BlendMatrix(int degree)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto degP1 = degree + 1;

    std::vector<std::vector<std::vector<int>>> aMat(degP1, std::vector<std::vector<int>>(degP1, std::vector<int>(degP1)));
    std::vector<std::vector<std::vector<int>>> bMat(degP1, std::vector<std::vector<int>>(degP1, std::vector<int>(degP1)));

    aMat.at(0).at(0).at(0) = 1;
    bMat.at(0).at(0).at(0) = 1;

    for (auto k = 1; k <= degree; ++k)
    {
        for (auto row = 0; row <= k; ++row)
        {
            for (auto col = 0; col <= k; ++col)
            {
                const auto previousK = k - 1;
                const auto previousCol = col - 1;
                const auto previousRow = row - 1;
                aMat.at(k).at(row).at(col) = 0;
                if (col >= 1)
                {
                    aMat.at(k).at(row).at(col) += aMat.at(previousK).at(row).at(previousCol);
                    if (row >= 1)
                    {
                        aMat.at(k).at(row).at(col) -= bMat.at(previousK).at(previousRow).at(previousCol);
                    }
                }
                if (row >= 1)
                {
                    aMat.at(k).at(row).at(col) += (k + 1) * bMat.at(previousK).at(previousRow).at(col);
                }
            }
        }

        for (auto row = 0; row <= k; ++row)
        {
            for (auto col = 0; col <= k; ++col)
            {
                bMat.at(k).at(row).at(col) = 0;
                for (auto i = col; i <= k; ++i)
                {
                    if ((i - col) % 2)
                    {
                        bMat.at(k).at(row).at(col) -= Choose(i, col) * aMat.at(k).at(row).at(i);
                    }
                    else
                    {
                        bMat.at(k).at(row).at(col) += Choose(i, col) * aMat.at(k).at(row).at(i);
                    }
                }
            }
        }
    }

    VariableMatrix<Real> cMat{ degP1, degP1 };
    for (auto row = 0; row <= degree; ++row)
    {
        for (auto col = 0; col <= degree; ++col)
        {
            cMat[row][col] = 0;
            for (auto i = col; i <= degree; ++i)
            {
                auto prod = 1;
                for (auto j = 1; j <= i - col; ++j)
                {
                    prod *= degree - row;
                }
                const auto index = degree - row;
                cMat[row][col] += Math<Real>::GetValue(prod) * Choose(i, col) * aMat.at(degree).at(index).at(i);
            }
        }
    }

    auto factorial = Math<Real>::GetValue(1);
    for (auto k = 1; k <= degree; ++k)
    {
        factorial *= k;
    }
    auto invFactorial = (Math<Real>::GetValue(1)) / factorial;
    VariableMatrix<Real> matrix{ degP1, degP1 };
    for (auto row = 0; row <= degree; ++row)
    {
        for (auto col = 0; col <= degree; ++col)
        {
            matrix[row][col] = cMat[row][col] * invFactorial;
        }
    }

    return matrix;
}

template <typename Real>
void Mathematics::IntpBSplineUniform<Real>::SetBase(int index, int value)
{
    base.at(index) = value;
}

template <typename Real>
bool Mathematics::IntpBSplineUniform<Real>::IsBaseChange(int index) const
{
    if (oldBase.at(index) != base.at(index))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real>
void Mathematics::IntpBSplineUniform<Real>::SwitchToNewLocalGrid(int index)
{
    oldBase.at(index) = base.at(index);
    gridMin.at(index) = base.at(index) - 1;
    gridMax.at(index) = gridMin.at(index) + degree;
}

template <typename Real>
bool Mathematics::IntpBSplineUniform<Real>::HasEvaluateCallback() const noexcept
{
    return evaluateCallback != nullptr;
}

template <typename Real>
int Mathematics::IntpBSplineUniform<Real>::GetBase(int index) const
{
    return base.at(index);
}

template <typename Real>
Mathematics::VariableLengthVector<Real>& Mathematics::IntpBSplineUniform<Real>::GetPolynomial(int index)
{
    return poly[index];
}

template <typename Real>
Real Mathematics::IntpBSplineUniform<Real>::GetInter(int index) const
{
    return inter.at(index);
}

template <typename Real>
Real Mathematics::IntpBSplineUniform<Real>::GetData(int index) const
{
    return data.at(index);
}

template <typename Real>
void Mathematics::IntpBSplineUniform<Real>::SetData(int index)
{
    if (evaluateCallback != nullptr)
    {
        data.at(index) = evaluateCallback(index);
    }
}

template <typename Real>
void Mathematics::IntpBSplineUniform<Real>::SetInter(int index, Real value)
{
    inter.at(index) = value;
}

template <typename Real>
Real Mathematics::IntpBSplineUniform<Real>::GetMatrix(int row, int column) const
{
    return matrix[row][column];
}

template <typename Real>
int Mathematics::IntpBSplineUniform<Real>::GetDim(int index) const
{
    return dim.at(index);
}

template <typename Real>
int Mathematics::IntpBSplineUniform<Real>::GetDP1() const noexcept
{
    return dp1;
}

template <typename Real>
int Mathematics::IntpBSplineUniform<Real>::GetDP1ToN() const noexcept
{
    return dp1ToN;
}

template <typename Real>
void Mathematics::IntpBSplineUniform<Real>::SetCache(int index, Real value)
{
    cache.at(index) = value;
}

template <typename Real>
Real Mathematics::IntpBSplineUniform<Real>::GetCache(int index) const
{
    return cache.at(index);
}

template <typename Real>
int Mathematics::IntpBSplineUniform<Real>::GetSkip(int index) const
{
    return skip.at(index);
}

template <typename Real>
Real Mathematics::IntpBSplineUniform<Real>::GetProduct(int index) const
{
    return product.at(index);
}

#endif  // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM_DETAIL_H