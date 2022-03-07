///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/09 10:19)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_DETAIL_H

#include "GaussianElimination.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/LexicoArray2Detail.h"
#include "Mathematics/Base/MathDetail.h"

#include <gsl/util>

template <typename Real>
Mathematics::GaussianElimination<Real>::GaussianElimination(int numRows, const Container& matrix, bool wantInverse, const Container& b, int numCols, const Container& c, Real epsilon)
    : numRows{ numRows },
      matrix{ matrix },
      wantInverse{ wantInverse },
      b{ b },
      c{ c },
      epsilon{ epsilon },
      isInverse{ false },
      inverseMatrix{ numRows, numRows, matrix },
      determinant{ Math::GetValue(1) },
      x{ b },
      numCols{ numCols },
      y{ numRows, numCols, c }
{
    const auto numElement = numRows * numRows;
    if (matrix.empty() || numElement != boost::numeric_cast<int>(matrix.size()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵输入无效！"));
    }

    if (!b.empty() && b.size() != matrix.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("b无效输入！"));
    }

    const auto numCElement = numRows * numCols;
    if (!c.empty() && (boost::numeric_cast<int>(c.size()) != numCElement))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("c无效输入！"));
    }

    Init();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::GaussianElimination<Real>::GaussianElimination(int numRows, const Container& matrix, bool wantInverse, Real epsilon)
    : GaussianElimination{ numRows, matrix, wantInverse, Container{}, 0, Container{}, epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::GaussianElimination<Real>::Init()
{
    IndexContainer colIndex(numRows);
    IndexContainer rowIndex(numRows);
    IndexContainer pivoted(numRows);

    auto odd = false;

    auto row = 0;
    auto col = 0;
    for (auto i0 = 0; i0 < numRows; ++i0)
    {
        Real maxValue = Math::GetValue(0);
        for (auto i1 = 0; i1 < numRows; ++i1)
        {
            if (!pivoted.at(i1))
            {
                for (auto i2 = 0; i2 < numRows; ++i2)
                {
                    if (!pivoted.at(i2))
                    {
                        auto value = inverseMatrix(i1, i2);
                        auto absValue = Math::FAbs(value);
                        if (maxValue < absValue)
                        {
                            maxValue = absValue;
                            row = i1;
                            col = i2;
                        }
                    }
                }
            }
        }

        if (maxValue <= epsilon)
        {
            if (wantInverse)
            {
                inverseMatrix.Clear();
            }

            determinant = Math::GetValue(0);

            if (!b.empty())
            {
                fill(x.begin(), x.end(), Math::GetValue(0));
            }

            if (!c.empty())
            {
                y.Clear();
            }

            return;
        }

        pivoted.at(col) = true;

        if (row != col)
        {
            odd = !odd;
            for (auto i = 0; i < numRows; ++i)
            {
                std::swap(inverseMatrix(row, i), inverseMatrix(col, i));
            }

            if (!b.empty())
            {
                std::swap(x.at(row), x.at(col));
            }

            if (!c.empty())
            {
                for (auto i = 0; i < numCols; ++i)
                {
                    std::swap(y(row, i), y(col, i));
                }
            }
        }

        rowIndex.at(i0) = row;
        colIndex.at(i0) = col;

        auto diagonal = inverseMatrix(col, col);
        determinant *= diagonal;
        auto inv = Math::GetValue(1) / diagonal;
        inverseMatrix(col, col) = Math::GetValue(1);
        for (auto i2 = 0; i2 < numRows; ++i2)
        {
            inverseMatrix(col, i2) *= inv;
        }

        if (!b.empty())
        {
            x.at(col) *= inv;
        }

        if (!c.empty())
        {
            for (auto i2 = 0; i2 < numCols; ++i2)
            {
                y(col, i2) *= inv;
            }
        }

        for (auto i1 = 0; i1 < numRows; ++i1)
        {
            if (i1 != col)
            {
                auto save = inverseMatrix(i1, col);
                inverseMatrix(i1, col) = Math::GetValue(0);
                for (auto i2 = 0; i2 < numRows; ++i2)
                {
                    inverseMatrix(i1, i2) -= inverseMatrix(col, i2) * save;
                }

                if (!b.empty())
                {
                    x.at(i1) -= x.at(col) * save;
                }

                if (!c.empty())
                {
                    for (auto i2 = 0; i2 < numCols; ++i2)
                    {
                        y(i1, i2) -= y(col, i2) * save;
                    }
                }
            }
        }
    }

    if (wantInverse)
    {
        for (auto i1 = numRows - 1; i1 >= 0; --i1)
        {
            if (rowIndex.at(i1) != colIndex.at(i1))
            {
                for (auto i2 = 0; i2 < numRows; ++i2)
                {
                    std::swap(inverseMatrix(i2, rowIndex.at(i1)), inverseMatrix(i2, colIndex.at(i1)));
                }
            }
        }
    }

    if (odd)
    {
        determinant = -determinant;
    }

    isInverse = true;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::GaussianElimination<Real>::IsValid() const noexcept
{
    const auto numElement = numRows * numRows;
    if (matrix.empty() || gsl::narrow_cast<size_t>(numElement) != matrix.size())
    {
        return false;
    }

    if (!b.empty() && b.size() != matrix.size())
    {
        return false;
    }

    const auto numCElement = numRows * numCols;
    if (!c.empty() && (c.size() != gsl::narrow_cast<size_t>(numCElement)))
    {
        return false;
    }

    if (b.size() != x.size())
    {
        return false;
    }

    const auto numYElement = y.GetNumRows() * y.GetNumCols();
    if (c.size() != gsl::narrow_cast<size_t>(numYElement))
    {
        return false;
    }

    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::GaussianElimination<Real>::IsInverse() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return isInverse;
}

template <typename Real>
typename Mathematics::GaussianElimination<Real>::Container Mathematics::GaussianElimination<Real>::GetInverse() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return inverseMatrix.GetContainer();
}

template <typename Real>
typename Mathematics::GaussianElimination<Real>::Container Mathematics::GaussianElimination<Real>::GetX() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return x;
}

template <typename Real>
typename Mathematics::GaussianElimination<Real>::Container Mathematics::GaussianElimination<Real>::GetY() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return y.GetContainer();
}

template <typename Real>
Real Mathematics::GaussianElimination<Real>::GetDeterminant() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return determinant;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_DETAIL_H