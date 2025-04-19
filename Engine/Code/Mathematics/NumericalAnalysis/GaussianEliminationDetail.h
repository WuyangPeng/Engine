/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/01/30 15:40)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_DETAIL_H

#include "GaussianElimination.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MemoryTools/LexicoArray2Detail.h"
#include "Mathematics/Base/MathDetail.h"

#include <gsl/util>

template <typename Real>
Mathematics::GaussianElimination<Real>::GaussianElimination(int numRows, const Container& matrix, bool wantInverse, const Container& b, int numColumns, const Container& c, Real epsilon)
    : numRows{ numRows },
      matrix{ matrix },
      wantInverse{ wantInverse },
      b{ b },
      numColumns{ numColumns },
      c{ c },
      epsilon{ epsilon },
      isInverse{ false },
      inverseMatrix{ numRows, numRows, this->matrix.begin(), this->matrix.end() },
      determinant{ MathType::GetValue(1) },
      x{ b },
      y{ numRows, numColumns, this->c.begin(), this->c.end() }
{
    const auto numElement = numRows * numRows;
    if (matrix.empty() || numElement != boost::numeric_cast<int>(matrix.size()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����������Ч��"))
    }

    if (!b.empty() && b.size() != matrix.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("b��Ч���룡"))
    }

    const auto numCElement = numRows * numColumns;
    if (!c.empty() && (boost::numeric_cast<int>(c.size()) != numCElement))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("c��Ч���룡"))
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
Mathematics::GaussianElimination<Real>::GaussianElimination(int numRows, const Container& matrix, bool wantInverse, const Container& b, Real epsilon)
    : GaussianElimination{ numRows, matrix, wantInverse, b, 0, Container{}, epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::GaussianElimination<Real>::Init()
{
    IndexContainer columnIndex(numRows);
    IndexContainer rowIndex(numRows);
    IndexContainer pivoted(numRows);

    auto odd = false;

    /// ͨ����ȫ��ת������
    auto row = 0;
    auto column = 0;
    for (auto i0 = 0; i0 < numRows; ++i0)
    {
        /// �������󣨲�������ת�У��Ի�ȡ��������Ŀ��
        Real maxValue = MathType::GetValue(0);
        for (auto i1 = 0; i1 < numRows; ++i1)
        {
            if (!pivoted.at(i1))
            {
                for (auto i2 = 0; i2 < numRows; ++i2)
                {
                    if (!pivoted.at(i2))
                    {
                        auto value = inverseMatrix(i1, i2);
                        auto absValue = MathType::FAbs(value);
                        if (maxValue < absValue)
                        {
                            maxValue = absValue;
                            row = i1;
                            column = i2;
                        }
                    }
                }
            }
        }

        if (maxValue <= epsilon)
        {
            /// �����ǲ�����ġ�
            if (wantInverse)
            {
                inverseMatrix.FillZero();
            }

            determinant = MathType::GetValue(0);

            if (!b.empty())
            {
                fill(x.begin(), x.end(), MathType::GetValue(0));
            }

            if (!c.empty())
            {
                y.FillZero();
            }

            return;
        }

        pivoted.at(column) = true;

        /// �����У�ʹ��ת����Ŀλ�ڡ�col���С�
        if (row != column)
        {
            odd = !odd;
            for (auto i = 0; i < numRows; ++i)
            {
                std::swap(inverseMatrix(row, i), inverseMatrix(column, i));
            }

            if (!b.empty())
            {
                std::swap(x.at(row), x.at(column));
            }

            if (!c.empty())
            {
                for (auto i = 0; i < numColumns; ++i)
                {
                    std::swap(y(row, i), y(column, i));
                }
            }
        }

        /// �����е����С�
        rowIndex.at(i0) = row;
        columnIndex.at(i0) = column;

        /// �����У�ʹ��ת����ĿΪ1��
        auto diagonal = inverseMatrix(column, column);
        determinant *= diagonal;
        auto inverse = MathType::GetValue(1) / diagonal;
        inverseMatrix(column, column) = MathType::GetValue(1);
        for (auto i = 0; i < numRows; ++i)
        {
            inverseMatrix(column, i) *= inverse;
        }

        if (!b.empty())
        {
            x.at(column) *= inverse;
        }

        if (!c.empty())
        {
            for (auto i = 0; i < numColumns; ++i)
            {
                y(column, i) *= inverse;
            }
        }

        // ���������е���ת��λ�ù��㡣
        for (auto i1 = 0; i1 < numRows; ++i1)
        {
            if (i1 != column)
            {
                auto save = inverseMatrix(i1, column);
                inverseMatrix(i1, column) = MathType::GetValue(0);
                for (auto i2 = 0; i2 < numRows; ++i2)
                {
                    inverseMatrix(i1, i2) -= inverseMatrix(column, i2) * save;
                }

                if (!b.empty())
                {
                    x.at(i1) -= x.at(column) * save;
                }

                if (!c.empty())
                {
                    for (auto i2 = 0; i2 < numColumns; ++i2)
                    {
                        y(i1, i2) -= y(column, i2) * save;
                    }
                }
            }
        }
    }

    if (wantInverse)
    {
        /// �����������Գ�����˹�����е��κ����С�
        for (auto i1 = numRows - 1; i1 >= 0; --i1)
        {
            if (rowIndex.at(i1) != columnIndex.at(i1))
            {
                for (auto i2 = 0; i2 < numRows; ++i2)
                {
                    std::swap(inverseMatrix(i2, rowIndex.at(i1)), inverseMatrix(i2, columnIndex.at(i1)));
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
    if (const auto numElement = numRows * numRows;
        matrix.empty() || gsl::narrow_cast<size_t>(numElement) != matrix.size())
    {
        return false;
    }

    if (!b.empty() && b.size() != matrix.size())
    {
        return false;
    }

    if (const auto numCElement = numRows * numColumns;
        !c.empty() && (c.size() != gsl::narrow_cast<size_t>(numCElement)))
    {
        return false;
    }

    if (b.size() != x.size())
    {
        return false;
    }

    if (const auto numYElement = y.GetNumRows() * y.GetNumColumns();
        c.size() != gsl::narrow_cast<size_t>(numYElement))
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

    return inverseMatrix.template GetContainer<std::vector<Real>>();
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

    return y.template GetContainer<std::vector<Real>>();
}

template <typename Real>
Real Mathematics::GaussianElimination<Real>::GetDeterminant() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return determinant;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_DETAIL_H