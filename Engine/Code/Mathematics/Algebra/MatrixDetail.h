//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/09/03 14:35)

#ifndef MATHEMATICS_ALGEBRA_MATRIX_DETAIL_H
#define MATHEMATICS_ALGEBRA_MATRIX_DETAIL_H

#include "MatrixAchieve.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <iostream>

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& out, const Matrix<Real>& matrix)
{
    for (auto row = 0; row < Matrix<Real>::sm_RowSize; ++row)
    {
        for (auto column = 0; column < Matrix<Real>::sm_ColumnSize; ++column)
        {
            out << "(" << row << "," << column << ")　=　" << matrix(row, column) << "　";
        }
    }

    return out;
}

template <typename Real>
bool Mathematics::operator==(const Matrix<Real>& lhs, const Matrix<Real>& rhs)
{
    return lhs.GetData() == rhs.GetData();
}

template <typename Real>
bool Mathematics::operator<(const Matrix<Real>& lhs, const Matrix<Real>& rhs)
{
    const auto iter = rhs.begin();
    for (auto value : lhs)
    {
        if (iter != rhs.end())
        {
            if (value < *iter)
                return true;
            else if (*iter < value)
                return false;
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("矩阵元素数量出现致使错误。"s));
        }

        ++iter;
    }

    return false;
}

template <typename Real>
const Mathematics::Matrix<Real> Mathematics::operator*(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept
{
    return Matrix<Real>{ lhs.GetValue<0>() * rhs.GetValue<0>() + lhs.GetValue<1>() * rhs.GetValue<4>() + lhs.GetValue<2>() * rhs.GetValue<8>() + lhs.GetValue<3>() * rhs.GetValue<12>(),
                         lhs.GetValue<0>() * rhs.GetValue<1>() + lhs.GetValue<1>() * rhs.GetValue<5>() + lhs.GetValue<2>() * rhs.GetValue<9>() + lhs.GetValue<3>() * rhs.GetValue<13>(),
                         lhs.GetValue<0>() * rhs.GetValue<2>() + lhs.GetValue<1>() * rhs.GetValue<6>() + lhs.GetValue<2>() * rhs.GetValue<10>() + lhs.GetValue<3>() * rhs.GetValue<14>(),
                         lhs.GetValue<0>() * rhs.GetValue<3>() + lhs.GetValue<1>() * rhs.GetValue<7>() + lhs.GetValue<2>() * rhs.GetValue<11>() + lhs.GetValue<3>() * rhs.GetValue<15>(),
                         lhs.GetValue<4>() * rhs.GetValue<0>() + lhs.GetValue<5>() * rhs.GetValue<4>() + lhs.GetValue<6>() * rhs.GetValue<8>() + lhs.GetValue<7>() * rhs.GetValue<12>(),
                         lhs.GetValue<4>() * rhs.GetValue<1>() + lhs.GetValue<5>() * rhs.GetValue<5>() + lhs.GetValue<6>() * rhs.GetValue<9>() + lhs.GetValue<7>() * rhs.GetValue<13>(),
                         lhs.GetValue<4>() * rhs.GetValue<2>() + lhs.GetValue<5>() * rhs.GetValue<6>() + lhs.GetValue<6>() * rhs.GetValue<10>() + lhs.GetValue<7>() * rhs.GetValue<14>(),
                         lhs.GetValue<4>() * rhs.GetValue<3>() + lhs.GetValue<5>() * rhs.GetValue<7>() + lhs.GetValue<6>() * rhs.GetValue<11>() + lhs.GetValue<7>() * rhs.GetValue<15>(),
                         lhs.GetValue<8>() * rhs.GetValue<0>() + lhs.GetValue<9>() * rhs.GetValue<4>() + lhs.GetValue<10>() * rhs.GetValue<8>() + lhs.GetValue<11>() * rhs.GetValue<12>(),
                         lhs.GetValue<8>() * rhs.GetValue<1>() + lhs.GetValue<9>() * rhs.GetValue<5>() + lhs.GetValue<10>() * rhs.GetValue<9>() + lhs.GetValue<11>() * rhs.GetValue<13>(),
                         lhs.GetValue<8>() * rhs.GetValue<2>() + lhs.GetValue<9>() * rhs.GetValue<6>() + lhs.GetValue<10>() * rhs.GetValue<10>() + lhs.GetValue<11>() * rhs.GetValue<14>(),
                         lhs.GetValue<8>() * rhs.GetValue<3>() + lhs.GetValue<9>() * rhs.GetValue<7>() + lhs.GetValue<10>() * rhs.GetValue<11>() + lhs.GetValue<11>() * rhs.GetValue<15>(),
                         lhs.GetValue<12>() * rhs.GetValue<0>() + lhs.GetValue<13>() * rhs.GetValue<4>() + lhs.GetValue<14>() * rhs.GetValue<8>() + lhs.GetValue<15>() * rhs.GetValue<12>(),
                         lhs.GetValue<12>() * rhs.GetValue<1>() + lhs.GetValue<13>() * rhs.GetValue<5>() + lhs.GetValue<14>() * rhs.GetValue<9>() + lhs.GetValue<15>() * rhs.GetValue<13>(),
                         lhs.GetValue<12>() * rhs.GetValue<2>() + lhs.GetValue<13>() * rhs.GetValue<6>() + lhs.GetValue<14>() * rhs.GetValue<10>() + lhs.GetValue<15>() * rhs.GetValue<14>(),
                         lhs.GetValue<12>() * rhs.GetValue<3>() + lhs.GetValue<13>() * rhs.GetValue<7>() + lhs.GetValue<14>() * rhs.GetValue<11>() + lhs.GetValue<15>() * rhs.GetValue<15>() };
}

template <typename Real>
const Mathematics::Matrix<Real> Mathematics::TransposeTimes(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept
{
    return Matrix<Real>{ lhs.GetValue<0>() * rhs.GetValue<0>() + lhs.GetValue<4>() * rhs.GetValue<4>() + lhs.GetValue<8>() * rhs.GetValue<8>() + lhs.GetValue<12>() * rhs.GetValue<12>(),
                         lhs.GetValue<0>() * rhs.GetValue<1>() + lhs.GetValue<4>() * rhs.GetValue<5>() + lhs.GetValue<8>() * rhs.GetValue<9>() + lhs.GetValue<12>() * rhs.GetValue<13>(),
                         lhs.GetValue<0>() * rhs.GetValue<2>() + lhs.GetValue<4>() * rhs.GetValue<6>() + lhs.GetValue<8>() * rhs.GetValue<10>() + lhs.GetValue<12>() * rhs.GetValue<14>(),
                         lhs.GetValue<0>() * rhs.GetValue<3>() + lhs.GetValue<4>() * rhs.GetValue<7>() + lhs.GetValue<8>() * rhs.GetValue<11>() + lhs.GetValue<12>() * rhs.GetValue<15>(),
                         lhs.GetValue<1>() * rhs.GetValue<0>() + lhs.GetValue<5>() * rhs.GetValue<4>() + lhs.GetValue<9>() * rhs.GetValue<8>() + lhs.GetValue<13>() * rhs.GetValue<12>(),
                         lhs.GetValue<1>() * rhs.GetValue<1>() + lhs.GetValue<5>() * rhs.GetValue<5>() + lhs.GetValue<9>() * rhs.GetValue<9>() + lhs.GetValue<13>() * rhs.GetValue<13>(),
                         lhs.GetValue<1>() * rhs.GetValue<2>() + lhs.GetValue<5>() * rhs.GetValue<6>() + lhs.GetValue<9>() * rhs.GetValue<10>() + lhs.GetValue<13>() * rhs.GetValue<14>(),
                         lhs.GetValue<1>() * rhs.GetValue<3>() + lhs.GetValue<5>() * rhs.GetValue<7>() + lhs.GetValue<9>() * rhs.GetValue<11>() + lhs.GetValue<13>() * rhs.GetValue<15>(),
                         lhs.GetValue<2>() * rhs.GetValue<0>() + lhs.GetValue<6>() * rhs.GetValue<4>() + lhs.GetValue<10>() * rhs.GetValue<8>() + lhs.GetValue<14>() * rhs.GetValue<12>(),
                         lhs.GetValue<2>() * rhs.GetValue<1>() + lhs.GetValue<6>() * rhs.GetValue<5>() + lhs.GetValue<10>() * rhs.GetValue<9>() + lhs.GetValue<14>() * rhs.GetValue<13>(),
                         lhs.GetValue<2>() * rhs.GetValue<2>() + lhs.GetValue<6>() * rhs.GetValue<6>() + lhs.GetValue<10>() * rhs.GetValue<10>() + lhs.GetValue<14>() * rhs.GetValue<14>(),
                         lhs.GetValue<2>() * rhs.GetValue<3>() + lhs.GetValue<6>() * rhs.GetValue<7>() + lhs.GetValue<10>() * rhs.GetValue<11>() + lhs.GetValue<14>() * rhs.GetValue<15>(),
                         lhs.GetValue<3>() * rhs.GetValue<0>() + lhs.GetValue<7>() * rhs.GetValue<4>() + lhs.GetValue<11>() * rhs.GetValue<8>() + lhs.GetValue<15>() * rhs.GetValue<12>(),
                         lhs.GetValue<3>() * rhs.GetValue<1>() + lhs.GetValue<7>() * rhs.GetValue<5>() + lhs.GetValue<11>() * rhs.GetValue<9>() + lhs.GetValue<15>() * rhs.GetValue<13>(),
                         lhs.GetValue<3>() * rhs.GetValue<2>() + lhs.GetValue<7>() * rhs.GetValue<6>() + lhs.GetValue<11>() * rhs.GetValue<10>() + lhs.GetValue<15>() * rhs.GetValue<14>(),
                         lhs.GetValue<3>() * rhs.GetValue<3>() + lhs.GetValue<7>() * rhs.GetValue<7>() + lhs.GetValue<11>() * rhs.GetValue<11>() + lhs.GetValue<15>() * rhs.GetValue<15>() };
}

template <typename Real>
const Mathematics::Matrix<Real> Mathematics::TimesTranspose(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept
{
    return Matrix<Real>{ lhs.GetValue<0>() * rhs.GetValue<0>() + lhs.GetValue<1>() * rhs.GetValue<1>() + lhs.GetValue<2>() * rhs.GetValue<2>() + lhs.GetValue<3>() * rhs.GetValue<3>(),
                         lhs.GetValue<0>() * rhs.GetValue<4>() + lhs.GetValue<1>() * rhs.GetValue<5>() + lhs.GetValue<2>() * rhs.GetValue<6>() + lhs.GetValue<3>() * rhs.GetValue<7>(),
                         lhs.GetValue<0>() * rhs.GetValue<8>() + lhs.GetValue<1>() * rhs.GetValue<9>() + lhs.GetValue<2>() * rhs.GetValue<10>() + lhs.GetValue<3>() * rhs.GetValue<11>(),
                         lhs.GetValue<0>() * rhs.GetValue<12>() + lhs.GetValue<1>() * rhs.GetValue<13>() + lhs.GetValue<2>() * rhs.GetValue<14>() + lhs.GetValue<3>() * rhs.GetValue<15>(),
                         lhs.GetValue<4>() * rhs.GetValue<0>() + lhs.GetValue<5>() * rhs.GetValue<1>() + lhs.GetValue<6>() * rhs.GetValue<2>() + lhs.GetValue<7>() * rhs.GetValue<3>(),
                         lhs.GetValue<4>() * rhs.GetValue<4>() + lhs.GetValue<5>() * rhs.GetValue<5>() + lhs.GetValue<6>() * rhs.GetValue<6>() + lhs.GetValue<7>() * rhs.GetValue<7>(),
                         lhs.GetValue<4>() * rhs.GetValue<8>() + lhs.GetValue<5>() * rhs.GetValue<9>() + lhs.GetValue<6>() * rhs.GetValue<10>() + lhs.GetValue<7>() * rhs.GetValue<11>(),
                         lhs.GetValue<4>() * rhs.GetValue<12>() + lhs.GetValue<5>() * rhs.GetValue<13>() + lhs.GetValue<6>() * rhs.GetValue<14>() + lhs.GetValue<7>() * rhs.GetValue<15>(),
                         lhs.GetValue<8>() * rhs.GetValue<0>() + lhs.GetValue<9>() * rhs.GetValue<1>() + lhs.GetValue<10>() * rhs.GetValue<2>() + lhs.GetValue<11>() * rhs.GetValue<3>(),
                         lhs.GetValue<8>() * rhs.GetValue<4>() + lhs.GetValue<9>() * rhs.GetValue<5>() + lhs.GetValue<10>() * rhs.GetValue<6>() + lhs.GetValue<11>() * rhs.GetValue<7>(),
                         lhs.GetValue<8>() * rhs.GetValue<8>() + lhs.GetValue<9>() * rhs.GetValue<9>() + lhs.GetValue<10>() * rhs.GetValue<10>() + lhs.GetValue<11>() * rhs.GetValue<11>(),
                         lhs.GetValue<8>() * rhs.GetValue<12>() + lhs.GetValue<9>() * rhs.GetValue<13>() + lhs.GetValue<10>() * rhs.GetValue<14>() + lhs.GetValue<11>() * rhs.GetValue<15>(),
                         lhs.GetValue<12>() * rhs.GetValue<0>() + lhs.GetValue<13>() * rhs.GetValue<1>() + lhs.GetValue<14>() * rhs.GetValue<2>() + lhs.GetValue<15>() * rhs.GetValue<3>(),
                         lhs.GetValue<12>() * rhs.GetValue<4>() + lhs.GetValue<13>() * rhs.GetValue<5>() + lhs.GetValue<14>() * rhs.GetValue<6>() + lhs.GetValue<15>() * rhs.GetValue<7>(),
                         lhs.GetValue<12>() * rhs.GetValue<8>() + lhs.GetValue<13>() * rhs.GetValue<9>() + lhs.GetValue<14>() * rhs.GetValue<10>() + lhs.GetValue<15>() * rhs.GetValue<11>(),
                         lhs.GetValue<12>() * rhs.GetValue<12>() + lhs.GetValue<13>() * rhs.GetValue<13>() + lhs.GetValue<14>() * rhs.GetValue<14>() + lhs.GetValue<15>() * rhs.GetValue<15>() };
}

template <typename Real>
const Mathematics::Matrix<Real> Mathematics::TransposeTimesTranspose(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept
{
    // A^T * B^T
    return Matrix<Real>{ lhs.GetValue<0>() * rhs.GetValue<0>() + lhs.GetValue<4>() * rhs.GetValue<1>() + lhs.GetValue<8>() * rhs.GetValue<2>() + lhs.GetValue<12>() * rhs.GetValue<3>(),
                         lhs.GetValue<0>() * rhs.GetValue<4>() + lhs.GetValue<4>() * rhs.GetValue<5>() + lhs.GetValue<8>() * rhs.GetValue<6>() + lhs.GetValue<12>() * rhs.GetValue<7>(),
                         lhs.GetValue<0>() * rhs.GetValue<8>() + lhs.GetValue<4>() * rhs.GetValue<9>() + lhs.GetValue<8>() * rhs.GetValue<10>() + lhs.GetValue<12>() * rhs.GetValue<11>(),
                         lhs.GetValue<0>() * rhs.GetValue<12>() + lhs.GetValue<4>() * rhs.GetValue<13>() + lhs.GetValue<8>() * rhs.GetValue<14>() + lhs.GetValue<12>() * rhs.GetValue<15>(),
                         lhs.GetValue<1>() * rhs.GetValue<0>() + lhs.GetValue<5>() * rhs.GetValue<1>() + lhs.GetValue<9>() * rhs.GetValue<2>() + lhs.GetValue<13>() * rhs.GetValue<3>(),
                         lhs.GetValue<1>() * rhs.GetValue<4>() + lhs.GetValue<5>() * rhs.GetValue<5>() + lhs.GetValue<9>() * rhs.GetValue<6>() + lhs.GetValue<13>() * rhs.GetValue<7>(),
                         lhs.GetValue<1>() * rhs.GetValue<8>() + lhs.GetValue<5>() * rhs.GetValue<9>() + lhs.GetValue<9>() * rhs.GetValue<10>() + lhs.GetValue<13>() * rhs.GetValue<11>(),
                         lhs.GetValue<1>() * rhs.GetValue<12>() + lhs.GetValue<5>() * rhs.GetValue<13>() + lhs.GetValue<9>() * rhs.GetValue<14>() + lhs.GetValue<13>() * rhs.GetValue<15>(),
                         lhs.GetValue<2>() * rhs.GetValue<0>() + lhs.GetValue<6>() * rhs.GetValue<1>() + lhs.GetValue<10>() * rhs.GetValue<2>() + lhs.GetValue<14>() * rhs.GetValue<3>(),
                         lhs.GetValue<2>() * rhs.GetValue<4>() + lhs.GetValue<6>() * rhs.GetValue<5>() + lhs.GetValue<10>() * rhs.GetValue<6>() + lhs.GetValue<14>() * rhs.GetValue<7>(),
                         lhs.GetValue<2>() * rhs.GetValue<8>() + lhs.GetValue<6>() * rhs.GetValue<9>() + lhs.GetValue<10>() * rhs.GetValue<10>() + lhs.GetValue<14>() * rhs.GetValue<11>(),
                         lhs.GetValue<2>() * rhs.GetValue<12>() + lhs.GetValue<6>() * rhs.GetValue<13>() + lhs.GetValue<10>() * rhs.GetValue<14>() + lhs.GetValue<14>() * rhs.GetValue<15>(),
                         lhs.GetValue<3>() * rhs.GetValue<0>() + lhs.GetValue<7>() * rhs.GetValue<1>() + lhs.GetValue<11>() * rhs.GetValue<2>() + lhs.GetValue<15>() * rhs.GetValue<3>(),
                         lhs.GetValue<3>() * rhs.GetValue<4>() + lhs.GetValue<7>() * rhs.GetValue<5>() + lhs.GetValue<11>() * rhs.GetValue<6>() + lhs.GetValue<15>() * rhs.GetValue<7>(),
                         lhs.GetValue<3>() * rhs.GetValue<8>() + lhs.GetValue<7>() * rhs.GetValue<9>() + lhs.GetValue<11>() * rhs.GetValue<10>() + lhs.GetValue<15>() * rhs.GetValue<11>(),
                         lhs.GetValue<3>() * rhs.GetValue<12>() + lhs.GetValue<7>() * rhs.GetValue<13>() + lhs.GetValue<11>() * rhs.GetValue<14>() + lhs.GetValue<15>() * rhs.GetValue<15>() };
}

template <typename Real>
const Mathematics::HomogeneousPoint<Real> Mathematics::operator*(const Matrix<Real>& matrix, const HomogeneousPoint<Real>& point) noexcept
{
    return HomogeneousPoint<Real>{ matrix.GetValue<0>() * point.GetX() + matrix.GetValue<1>() * point.GetY() + matrix.GetValue<2>() * point.GetZ() + matrix.GetValue<3>() * point.GetW(),
                                   matrix.GetValue<4>() * point.GetX() + matrix.GetValue<5>() * point.GetY() + matrix.GetValue<6>() * point.GetZ() + matrix.GetValue<7>() * point.GetW(),
                                   matrix.GetValue<8>() * point.GetX() + matrix.GetValue<9>() * point.GetY() + matrix.GetValue<10>() * point.GetZ() + matrix.GetValue<11>() * point.GetW(),
                                   matrix.GetValue<12>() * point.GetX() + matrix.GetValue<13>() * point.GetY() + matrix.GetValue<14>() * point.GetZ() + matrix.GetValue<15>() * point.GetW() };
}

template <typename Real>
const Mathematics::HomogeneousPoint<Real> Mathematics::operator*(const HomogeneousPoint<Real>& point, const Matrix<Real>& matrix) noexcept
{
    return HomogeneousPoint<Real>{ point.GetX() * matrix.GetValue<0>() + point.GetY() * matrix.GetValue<4>() + point.GetZ() * matrix.GetValue<8>() + point.GetW() * matrix.GetValue<12>(),
                                   point.GetX() * matrix.GetValue<1>() + point.GetY() * matrix.GetValue<5>() + point.GetZ() * matrix.GetValue<9>() + point.GetW() * matrix.GetValue<13>(),
                                   point.GetX() * matrix.GetValue<2>() + point.GetY() * matrix.GetValue<6>() + point.GetZ() * matrix.GetValue<10>() + point.GetW() * matrix.GetValue<14>(),
                                   point.GetX() * matrix.GetValue<3>() + point.GetY() * matrix.GetValue<7>() + point.GetZ() * matrix.GetValue<11>() + point.GetW() * matrix.GetValue<15>() };
}

template <typename Real>
const typename Mathematics::HomogeneousPoint<Real>::ContainerType Mathematics::BatchMultiply(const Matrix<Real>& matrix, const typename HomogeneousPoint<Real>::ContainerType& inputPoints)
{
    typename HomogeneousPoint<Real>::ContainerType outputPoints{};

    for (const auto& point : inputPoints)
    {
        outputPoints.emplace_back(matrix * point);
    }

    MATHEMATICS_ASSERTION_2(outputPoints.size() == inputPoints.size(), "输入和输出数组大小不相等！");

    return outputPoints;
}

template <typename Real>
const Mathematics::APoint<Real> Mathematics::operator*(const Matrix<Real>& matrix, const APoint<Real>& point) noexcept
{
    return APoint<Real>{ matrix.GetValue<0>() * point.GetX() + matrix.GetValue<1>() * point.GetY() + matrix.GetValue<2>() * point.GetZ() + matrix.GetValue<3>(),
                         matrix.GetValue<4>() * point.GetX() + matrix.GetValue<5>() * point.GetY() + matrix.GetValue<6>() * point.GetZ() + matrix.GetValue<7>(),
                         matrix.GetValue<8>() * point.GetX() + matrix.GetValue<9>() * point.GetY() + matrix.GetValue<10>() * point.GetZ() + matrix.GetValue<11>() };
}

template <typename Real>
const typename Mathematics::APoint<Real>::ContainerType Mathematics::BatchMultiply(const Matrix<Real>& matrix, const typename APoint<Real>::ContainerType& inputPoints)
{
    typename APoint<Real>::ContainerType outputPoints{};

    for (const auto& point : inputPoints)
    {
        outputPoints.emplace_back(matrix * point);
    }

    MATHEMATICS_ASSERTION_1(outputPoints.size() == inputPoints.size(), "输入和输出数组大小不相等！");

    return outputPoints;
}

template <typename Real>
const Mathematics::AVector<Real> Mathematics::operator*(const Matrix<Real>& matrix, const AVector<Real>& point) noexcept
{
    return AVector<Real>{ matrix.GetValue<0>() * point.GetX() + matrix.GetValue<1>() * point.GetY() + matrix.GetValue<2>() * point.GetZ(),
                          matrix.GetValue<4>() * point.GetX() + matrix.GetValue<5>() * point.GetY() + matrix.GetValue<6>() * point.GetZ(),
                          matrix.GetValue<8>() * point.GetX() + matrix.GetValue<9>() * point.GetY() + matrix.GetValue<10>() * point.GetZ() };
}

template <typename Real>
const typename Mathematics::AVector<Real>::ContainerType Mathematics::BatchMultiply(const Matrix<Real>& matrix, const typename AVector<Real>::ContainerType& inputPoints)
{
    typename AVector<Real>::ContainerType outputPoints{};

    for (const auto& point : inputPoints)
    {
        outputPoints.emplace_back(matrix * point);
    }

    MATHEMATICS_ASSERTION_1(outputPoints.size() == inputPoints.size(), "输入和输出数组大小不相等！");

    return outputPoints;
}

template <typename Real>
bool Mathematics::Approximate(const Matrix<Real>& lhs, const Matrix<Real>& rhs, const Real epsilon)
{
    auto iter = rhs.begin();
    for (auto value : lhs)
    {
        if (iter != rhs.end())
        {
            if (epsilon < Math<Real>::FAbs(value - *iter))
            {
                return false;
            }
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("矩阵元素数量出现致使错误。"s));
        }

        ++iter;
    }

    return true;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX_DETAIL_H
