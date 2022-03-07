///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/07 19:03)

#ifndef MATHEMATICS_ALGEBRA_MATRIX_DETAIL_H
#define MATHEMATICS_ALGEBRA_MATRIX_DETAIL_H

#include "APointDetail.h"
#include "AVectorDetail.h"
#include "Matrix.h"
#include "Matrix3Detail.h"
#include "Vector4Detail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/util>
#include <iostream>

template <typename Real>
Mathematics::Matrix<Real>::Matrix(const Matrix3& rhs)
    : m_Entry{ rhs(0, 0),
               rhs(0, 1),
               rhs(0, 2),
               Math::GetValue(0),
               rhs(1, 0),
               rhs(1, 1),
               rhs(1, 2),
               Math::GetValue(0),
               rhs(2, 0),
               rhs(2, 1),
               rhs(2, 2),
               Math::GetValue(0),
               Math::GetValue(0),
               Math::GetValue(0),
               Math::GetValue(0),
               Math::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
typename Mathematics::Matrix<Real>::EntryType Mathematics::Matrix<Real>::Create(const ContainerType& entry, MatrixMajorFlags majorFlag)
{
    if (entry.size() != entrySize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ݴ�С����"s));
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return Create(entry[0],
                  entry[1],
                  entry[2],
                  entry[3],
                  entry[4],
                  entry[5],
                  entry[6],
                  entry[7],
                  entry[8],
                  entry[9],
                  entry[10],
                  entry[11],
                  entry[12],
                  entry[13],
                  entry[14],
                  entry[15],
                  majorFlag);

#include STSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Matrix<Real>::Matrix(const ContainerType& entry, MatrixMajorFlags majorFlag)
    : m_Entry{ Create(entry, majorFlag) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix<Real>::Matrix(const Vector4& vector0, const Vector4& vector1, const Vector4& vector2, const Vector4& vector3, MatrixMajorFlags majorFlag)
    : m_Entry{ Create(vector0.GetX(),
                      vector0.GetY(),
                      vector0.GetZ(),
                      vector0.GetW(),
                      vector1.GetX(),
                      vector1.GetY(),
                      vector1.GetZ(),
                      vector1.GetW(),
                      vector2.GetX(),
                      vector2.GetY(),
                      vector2.GetZ(),
                      vector2.GetW(),
                      vector3.GetX(),
                      vector3.GetY(),
                      vector3.GetZ(),
                      vector3.GetW(),
                      majorFlag) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix<Real>::Matrix(const AVector& vector0, const AVector& vector1, const AVector& vector2, const APoint& point, MatrixMajorFlags majorFlag)
    : m_Entry{ Create(vector0.GetX(),
                      vector0.GetY(),
                      vector0.GetZ(),
                      Math::GetValue(0),
                      vector1.GetX(),
                      vector1.GetY(),
                      vector1.GetZ(),
                      Math::GetValue(0),
                      vector2.GetX(),
                      vector2.GetY(),
                      vector2.GetZ(),
                      Math::GetValue(0),
                      point.GetX(),
                      point.GetY(),
                      point.GetZ(),
                      Math::GetValue(1),
                      majorFlag) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix<Real>::Matrix(const AVector& axis, Real angle)
    : m_Entry{}
{
    MakeRotation(axis, angle);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real>
Mathematics::Matrix<Real>& Mathematics::Matrix<Real>::operator=(const Matrix3& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix matrix{ rhs };

    *this = matrix;

    return *this;
}

#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Matrix<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
template <int Index>
void Mathematics::Matrix<Real>::Divide(Real value)
{
    static_assert(0 <= Index && Index < entrySize);

    if (Math::GetZeroTolerance() < Math::FAbs(value))
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        m_Entry[Index] /= value;

#include STSTEM_WARNING_POP
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�������"s));
    }
}

template <typename Real>
typename Mathematics::Matrix<Real>::EntryTypeConstIter Mathematics::Matrix<Real>::begin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Entry.begin();
}

template <typename Real>
typename Mathematics::Matrix<Real>::EntryTypeConstIter Mathematics::Matrix<Real>::end() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Entry.end();
}

template <typename Real>
typename Mathematics::Matrix<Real>::Matrix3 Mathematics::Matrix<Real>::GetMatrix3() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix3{ GetValue<0>(),
                    GetValue<1>(),
                    GetValue<2>(),
                    GetValue<4>(),
                    GetValue<5>(),
                    GetValue<6>(),
                    GetValue<8>(),
                    GetValue<9>(),
                    GetValue<10>() };
}

template <typename Real>
typename Mathematics::Matrix<Real>::EntryType Mathematics::Matrix<Real>::GetData() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Entry;
}

template <typename Real>
const Real& Mathematics::Matrix<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto index = column + columnSize * row;
    return m_Entry.at(index);
}

template <typename Real>
Real& Mathematics::Matrix<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include STSTEM_WARNING_POP
}

template <typename Real>
void Mathematics::Matrix<Real>::SetRow(int row, const HomogeneousPoint& point)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 <= row && row < rowSize)
    {
        for (auto i = 0; i < columnSize; ++i)
        {
            const auto index = rowSize * row + i;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            m_Entry[index] = point[i];

#include STSTEM_WARNING_POP
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��������"s));
    }
}

template <typename Real>
typename Mathematics::Matrix<Real>::HomogeneousPoint Mathematics::Matrix<Real>::GetRow(int row) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (0 <= row && row < rowSize)
    {
        const auto index = gsl::narrow_cast<size_t>(rowSize) * gsl::narrow_cast<size_t>(row);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return HomogeneousPoint{ m_Entry[index], m_Entry[index + 1], m_Entry[index + 2], m_Entry[index + 3] };

#include STSTEM_WARNING_POP
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��������"s));
    }
}

template <typename Real>
void Mathematics::Matrix<Real>::SetColumn(int column, const HomogeneousPoint& point)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 <= column && column < columnSize)
    {
        for (int i = 0; i < rowSize; ++i)
        {
            const auto index = columnSize * i + column;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

            m_Entry[index] = point[i];

#include STSTEM_WARNING_POP
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��������"s));
    }
}

template <typename Real>
typename Mathematics::Matrix<Real>::HomogeneousPoint Mathematics::Matrix<Real>::GetColumn(int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (0 <= column && column < columnSize)
    {
        const auto index = gsl::narrow_cast<size_t>(column);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        return HomogeneousPoint{ m_Entry[index], m_Entry[columnSize + index], m_Entry[columnSize * 2 + index], m_Entry[columnSize * 3 + index] };

#include STSTEM_WARNING_POP
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��������"s));
    }
}

template <typename Real>
typename Mathematics::Matrix<Real>::ContainerType Mathematics::Matrix<Real>::GetColumnMajor() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    ContainerType columnMatrix{ GetValue<0>(),
                                GetValue<4>(),
                                GetValue<8>(),
                                GetValue<12>(),
                                GetValue<1>(),
                                GetValue<5>(),
                                GetValue<9>(),
                                GetValue<13>(),
                                GetValue<2>(),
                                GetValue<6>(),
                                GetValue<10>(),
                                GetValue<14>(),
                                GetValue<3>(),
                                GetValue<7>(),
                                GetValue<11>(),
                                GetValue<15>() };

    MATHEMATICS_ASSERTION_0(columnMatrix.size() == entrySize, "���ݴ�С����");

    return columnMatrix;
}

template <typename Real>
typename Mathematics::Matrix<Real>::EntryType Mathematics::Matrix<Real>::GetRowMajor() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    EntryType rowMatrix{ GetValue<0>(),
                         GetValue<1>(),
                         GetValue<2>(),
                         GetValue<3>(),
                         GetValue<4>(),
                         GetValue<5>(),
                         GetValue<6>(),
                         GetValue<7>(),
                         GetValue<8>(),
                         GetValue<9>(),
                         GetValue<10>(),
                         GetValue<11>(),
                         GetValue<12>(),
                         GetValue<13>(),
                         GetValue<14>(),
                         GetValue<15>() };

    return rowMatrix;
}

template <typename Real>
void Mathematics::Matrix<Real>::Set(const EntryType& rowMajor) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry = rowMajor;
}

template <typename Real>
Mathematics::Matrix<Real> Mathematics::Matrix<Real>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix{ -GetValue<0>(),
                   -GetValue<1>(),
                   -GetValue<2>(),
                   -GetValue<3>(),
                   -GetValue<4>(),
                   -GetValue<5>(),
                   -GetValue<6>(),
                   -GetValue<7>(),
                   -GetValue<8>(),
                   -GetValue<9>(),
                   -GetValue<10>(),
                   -GetValue<11>(),
                   -GetValue<12>(),
                   -GetValue<13>(),
                   -GetValue<14>(),
                   -GetValue<15>() };
}

template <typename Real>
Mathematics::Matrix<Real>& Mathematics::Matrix<Real>::operator+=(const Matrix& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0u; i < entrySize; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        m_Entry[i] += rhs.m_Entry[i];

#include STSTEM_WARNING_POP
    }

    return *this;
}

template <typename Real>
Mathematics::Matrix<Real>& Mathematics::Matrix<Real>::operator-=(const Matrix& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0u; i < entrySize; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        m_Entry[i] -= rhs.m_Entry[i];

#include STSTEM_WARNING_POP
    }

    return *this;
}

template <typename Real>
Mathematics::Matrix<Real>& Mathematics::Matrix<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto& value : m_Entry)
    {
        value *= scalar;
    }

    return *this;
}

template <typename Real>
Mathematics::Matrix<Real>& Mathematics::Matrix<Real>::operator/=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (Math::GetZeroTolerance() < Math::FAbs(scalar))
    {
        for (auto& value : m_Entry)
        {
            value /= scalar;
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�������"s));
    }

    return *this;
}

template <typename Real>
void Mathematics::Matrix<Real>::MakeZero()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry.fill(Math::GetValue(0));
}

template <typename Real>
void Mathematics::Matrix<Real>::MakeIdentity() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0; i < entrySize; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        if ((i / rowSize) == (i % rowSize))
        {
            m_Entry[i] = Math::GetValue(1);
        }
        else
        {
            m_Entry[i] = Math::GetValue(0);
        }

#include STSTEM_WARNING_POP
    }
}

template <typename Real>
void Mathematics::Matrix<Real>::MakeDiagonal(Real member00, Real member11, Real member22) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Entry = Create(member00,
                     Math::GetValue(0),
                     Math::GetValue(0),
                     Math::GetValue(0),
                     Math::GetValue(0),
                     member11,
                     Math::GetValue(0),
                     Math::GetValue(0),
                     Math::GetValue(0),
                     Math::GetValue(0),
                     member22,
                     Math::GetValue(0),
                     Math::GetValue(0),
                     Math::GetValue(0),
                     Math::GetValue(0),
                     Math::GetValue(1),
                     MatrixMajorFlags::Row);
}

template <typename Real>
void Mathematics::Matrix<Real>::MakeRotation(const AVector& axis, Real angle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto cosValue = Math::Cos(angle);
    const auto sinValue = Math::Sin(angle);
    const auto oneMinusCos = Math::GetValue(1) - cosValue;

    const auto xAxisSquare = axis.GetX() * axis.GetX();
    const auto yAxisSquare = axis.GetY() * axis.GetY();
    const auto zAxisSquare = axis.GetZ() * axis.GetZ();

    const auto xAxisSquareMultipliedOneMinusCos = xAxisSquare * oneMinusCos;
    const auto yAxisSquareMultipliedOneMinusCos = yAxisSquare * oneMinusCos;
    const auto zAxisSquareMultipliedOneMinusCos = zAxisSquare * oneMinusCos;

    const auto xym = axis.GetX() * axis.GetY() * oneMinusCos;
    const auto xzm = axis.GetX() * axis.GetZ() * oneMinusCos;
    const auto yzm = axis.GetY() * axis.GetZ() * oneMinusCos;

    const auto xSin = axis.GetX() * sinValue;
    const auto ySin = axis.GetY() * sinValue;
    const auto zSin = axis.GetZ() * sinValue;

    m_Entry = Create(xAxisSquareMultipliedOneMinusCos + cosValue,
                     xym - zSin,
                     xzm + ySin,
                     Math::GetValue(0),

                     xym + zSin,
                     yAxisSquareMultipliedOneMinusCos + cosValue,
                     yzm - xSin,
                     Math::GetValue(0),

                     xzm - ySin,
                     yzm + xSin,
                     zAxisSquareMultipliedOneMinusCos + cosValue,
                     Math::GetValue(0),

                     Math::GetValue(0),
                     Math::GetValue(0),
                     Math::GetValue(0),
                     Math::GetValue(1),

                     MatrixMajorFlags::Row);
}

template <typename Real>
Mathematics::Matrix<Real> Mathematics::Matrix<Real>::Transpose() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix{ GetValue<0>(),
                   GetValue<4>(),
                   GetValue<8>(),
                   GetValue<12>(),
                   GetValue<1>(),
                   GetValue<5>(),
                   GetValue<9>(),
                   GetValue<13>(),
                   GetValue<2>(),
                   GetValue<6>(),
                   GetValue<10>(),
                   GetValue<14>(),
                   GetValue<3>(),
                   GetValue<7>(),
                   GetValue<11>(),
                   GetValue<15>() };
}

template <typename Real>
Mathematics::Matrix<Real> Mathematics::Matrix<Real>::Inverse(const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto a0 = GetValue<0>() * GetValue<5>() - GetValue<1>() * GetValue<4>();
    const auto a1 = GetValue<0>() * GetValue<6>() - GetValue<2>() * GetValue<4>();
    const auto a2 = GetValue<0>() * GetValue<7>() - GetValue<3>() * GetValue<4>();
    const auto a3 = GetValue<1>() * GetValue<6>() - GetValue<2>() * GetValue<5>();
    const auto a4 = GetValue<1>() * GetValue<7>() - GetValue<3>() * GetValue<5>();
    const auto a5 = GetValue<2>() * GetValue<7>() - GetValue<3>() * GetValue<6>();
    const auto b0 = GetValue<8>() * GetValue<13>() - GetValue<9>() * GetValue<12>();
    const auto b1 = GetValue<8>() * GetValue<14>() - GetValue<10>() * GetValue<12>();
    const auto b2 = GetValue<8>() * GetValue<15>() - GetValue<11>() * GetValue<12>();
    const auto b3 = GetValue<9>() * GetValue<14>() - GetValue<10>() * GetValue<13>();
    const auto b4 = GetValue<9>() * GetValue<15>() - GetValue<11>() * GetValue<13>();
    const auto b5 = GetValue<10>() * GetValue<15>() - GetValue<11>() * GetValue<14>();

    const auto det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
    if (epsilon < Math::FAbs(det))
    {
        Matrix adjoint{ +GetValue<5>() * b5 - GetValue<6>() * b4 + GetValue<7>() * b3,
                        -GetValue<1>() * b5 + GetValue<2>() * b4 - GetValue<3>() * b3,
                        +GetValue<13>() * a5 - GetValue<14>() * a4 + GetValue<15>() * a3,
                        -GetValue<9>() * a5 + GetValue<10>() * a4 - GetValue<11>() * a3,
                        -GetValue<4>() * b5 + GetValue<6>() * b2 - GetValue<7>() * b1,
                        +GetValue<0>() * b5 - GetValue<2>() * b2 + GetValue<3>() * b1,
                        -GetValue<12>() * a5 + GetValue<14>() * a2 - GetValue<15>() * a1,
                        +GetValue<8>() * a5 - GetValue<10>() * a2 + GetValue<11>() * a1,
                        +GetValue<4>() * b4 - GetValue<5>() * b2 + GetValue<7>() * b0,
                        -GetValue<0>() * b4 + GetValue<1>() * b2 - GetValue<3>() * b0,
                        +GetValue<12>() * a4 - GetValue<13>() * a2 + GetValue<15>() * a0,
                        -GetValue<8>() * a4 + GetValue<9>() * a2 - GetValue<11>() * a0,
                        -GetValue<4>() * b3 + GetValue<5>() * b1 - GetValue<6>() * b0,
                        +GetValue<0>() * b3 - GetValue<1>() * b1 + GetValue<2>() * b0,
                        -GetValue<12>() * a3 + GetValue<13>() * a1 - GetValue<14>() * a0,
                        +GetValue<8>() * a3 - GetValue<9>() * a1 + GetValue<10>() * a0 };

        adjoint /= det;

        return adjoint;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�þ��󲻴��������"s));
    }
}

template <typename Real>
Mathematics::Matrix<Real> Mathematics::Matrix<Real>::Adjoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto a0 = GetValue<0>() * GetValue<5>() - GetValue<1>() * GetValue<4>();
    const auto a1 = GetValue<0>() * GetValue<6>() - GetValue<2>() * GetValue<4>();
    const auto a2 = GetValue<0>() * GetValue<7>() - GetValue<3>() * GetValue<4>();
    const auto a3 = GetValue<1>() * GetValue<6>() - GetValue<2>() * GetValue<5>();
    const auto a4 = GetValue<1>() * GetValue<7>() - GetValue<3>() * GetValue<5>();
    const auto a5 = GetValue<2>() * GetValue<7>() - GetValue<3>() * GetValue<6>();
    const auto b0 = GetValue<8>() * GetValue<13>() - GetValue<9>() * GetValue<12>();
    const auto b1 = GetValue<8>() * GetValue<14>() - GetValue<10>() * GetValue<12>();
    const auto b2 = GetValue<8>() * GetValue<15>() - GetValue<11>() * GetValue<12>();
    const auto b3 = GetValue<9>() * GetValue<14>() - GetValue<10>() * GetValue<13>();
    const auto b4 = GetValue<9>() * GetValue<15>() - GetValue<11>() * GetValue<13>();
    const auto b5 = GetValue<10>() * GetValue<15>() - GetValue<11>() * GetValue<14>();

    return Matrix{ +GetValue<5>() * b5 - GetValue<6>() * b4 + GetValue<7>() * b3,
                   -GetValue<1>() * b5 + GetValue<2>() * b4 - GetValue<3>() * b3,
                   +GetValue<13>() * a5 - GetValue<14>() * a4 + GetValue<15>() * a3,
                   -GetValue<9>() * a5 + GetValue<10>() * a4 - GetValue<11>() * a3,
                   -GetValue<4>() * b5 + GetValue<6>() * b2 - GetValue<7>() * b1,
                   +GetValue<0>() * b5 - GetValue<2>() * b2 + GetValue<3>() * b1,
                   -GetValue<12>() * a5 + GetValue<14>() * a2 - GetValue<15>() * a1,
                   +GetValue<8>() * a5 - GetValue<10>() * a2 + GetValue<11>() * a1,
                   +GetValue<4>() * b4 - GetValue<5>() * b2 + GetValue<7>() * b0,
                   -GetValue<0>() * b4 + GetValue<1>() * b2 - GetValue<3>() * b0,
                   +GetValue<12>() * a4 - GetValue<13>() * a2 + GetValue<15>() * a0,
                   -GetValue<8>() * a4 + GetValue<9>() * a2 - GetValue<11>() * a0,
                   -GetValue<4>() * b3 + GetValue<5>() * b1 - GetValue<6>() * b0,
                   +GetValue<0>() * b3 - GetValue<1>() * b1 + GetValue<2>() * b0,
                   -GetValue<12>() * a3 + GetValue<13>() * a1 - GetValue<14>() * a0,
                   +GetValue<8>() * a3 - GetValue<9>() * a1 + GetValue<10>() * a0 };
}

template <typename Real>
Mathematics::Matrix<Real> Mathematics::Matrix<Real>::Invert3x3(const Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    // ����M (3x3)�İ������
    Matrix adjoint{ GetValue<5>() * GetValue<10>() - GetValue<6>() * GetValue<9>(),
                    GetValue<2>() * GetValue<9>() - GetValue<1>() * GetValue<10>(),
                    GetValue<1>() * GetValue<6>() - GetValue<2>() * GetValue<5>(),
                    GetValue<3>(),
                    GetValue<6>() * GetValue<8>() - GetValue<4>() * GetValue<10>(),
                    GetValue<0>() * GetValue<10>() - GetValue<2>() * GetValue<8>(),
                    GetValue<2>() * GetValue<4>() - GetValue<0>() * GetValue<6>(),
                    GetValue<7>(),
                    GetValue<4>() * GetValue<9>() - GetValue<5>() * GetValue<8>(),
                    GetValue<1>() * GetValue<8>() - GetValue<0>() * GetValue<9>(),
                    GetValue<0>() * GetValue<5>() - GetValue<1>() * GetValue<4>(),
                    GetValue<11>(),
                    GetValue<12>(),
                    GetValue<13>(),
                    GetValue<14>(),
                    GetValue<15>() };

    // ����M������ʽ��
    const auto det = GetValue<0>() * adjoint.GetValue<0>() + GetValue<1>() * adjoint.GetValue<4>() + GetValue<2>() * adjoint.GetValue<8>();

    if (epsilon < Math::FAbs(det))
    {
        // inverse(M) = adjoint(M) / determinant(M).
        adjoint.Divide<0>(det);
        adjoint.Divide<1>(det);
        adjoint.Divide<2>(det);

        adjoint.Divide<4>(det);
        adjoint.Divide<5>(det);
        adjoint.Divide<6>(det);

        adjoint.Divide<8>(det);
        adjoint.Divide<9>(det);
        adjoint.Divide<10>(det);

        return adjoint;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�þ��󲻴��������"s));
    }
}

template <typename Real>
Real Mathematics::Matrix<Real>::Determinant() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto a0 = GetValue<0>() * GetValue<5>() - GetValue<1>() * GetValue<4>();
    const auto a1 = GetValue<0>() * GetValue<6>() - GetValue<2>() * GetValue<4>();
    const auto a2 = GetValue<0>() * GetValue<7>() - GetValue<3>() * GetValue<4>();
    const auto a3 = GetValue<1>() * GetValue<6>() - GetValue<2>() * GetValue<5>();
    const auto a4 = GetValue<1>() * GetValue<7>() - GetValue<3>() * GetValue<5>();
    const auto a5 = GetValue<2>() * GetValue<7>() - GetValue<3>() * GetValue<6>();
    const auto b0 = GetValue<8>() * GetValue<13>() - GetValue<9>() * GetValue<12>();
    const auto b1 = GetValue<8>() * GetValue<14>() - GetValue<10>() * GetValue<12>();
    const auto b2 = GetValue<8>() * GetValue<15>() - GetValue<11>() * GetValue<12>();
    const auto b3 = GetValue<9>() * GetValue<14>() - GetValue<10>() * GetValue<13>();
    const auto b4 = GetValue<9>() * GetValue<15>() - GetValue<11>() * GetValue<13>();
    const auto b5 = GetValue<10>() * GetValue<15>() - GetValue<11>() * GetValue<14>();

    const auto det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

    return det;
}

template <typename Real>
Mathematics::Matrix<Real>& Mathematics::Matrix<Real>::operator*=(const Matrix& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = *this * rhs;

    return *this;
}

template <typename Real>
Mathematics::Matrix<Real> Mathematics::Matrix<Real>::TimesDiagonal(const APoint& diagonal) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix{ GetValue<0>() * diagonal.GetX(),
                   GetValue<1>() * diagonal.GetY(),
                   GetValue<2>() * diagonal.GetZ(),
                   GetValue<3>(),

                   GetValue<4>() * diagonal.GetX(),
                   GetValue<5>() * diagonal.GetY(),
                   GetValue<6>() * diagonal.GetZ(),
                   GetValue<7>(),

                   GetValue<8>() * diagonal.GetX(),
                   GetValue<9>() * diagonal.GetY(),
                   GetValue<10>() * diagonal.GetZ(),
                   GetValue<11>(),

                   GetValue<12>() * diagonal.GetX(),
                   GetValue<13>() * diagonal.GetY(),
                   GetValue<14>() * diagonal.GetZ(),
                   GetValue<15>() };
}

template <typename Real>
Mathematics::Matrix<Real> Mathematics::Matrix<Real>::DiagonalTimes(const APoint& diagonal) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Matrix{ diagonal.GetX() * GetValue<0>(),
                   diagonal.GetX() * GetValue<1>(),
                   diagonal.GetX() * GetValue<2>(),
                   GetValue<3>(),

                   diagonal.GetY() * GetValue<4>(),
                   diagonal.GetY() * GetValue<5>(),
                   diagonal.GetY() * GetValue<6>(),
                   GetValue<7>(),

                   diagonal.GetZ() * GetValue<8>(),
                   diagonal.GetZ() * GetValue<9>(),
                   diagonal.GetZ() * GetValue<10>(),
                   GetValue<11>(),

                   GetValue<12>(),
                   GetValue<13>(),
                   GetValue<14>(),
                   GetValue<15>() };
}

template <typename Real>
void Mathematics::Matrix<Real>::Orthonormalize() noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    // �㷨����Gram-Schmidt������
    // ���'this'���������3x3��M = [m0|m1|m2]��Ȼ�������������Q = [q0|q1|q2]
    //
    //   q0 = m0 / |m0|
    //   q1 = (m1 - (q0 * m1)q0) / |m1-(q0 * m1)q0|
    //   q2 = (m2 - (q0 * m2)q0 - (q1 * m2)q1) / |m2 - (q0 * m2)q0-(q1 * m2)q1|
    // ����|V|��ʾ����V�ĳ��Ⱥ�A * B��ʾ����A��B�ĵ��

    // ���� q0.
    auto invLength = Math::InvSqrt(GetValue<0>() * GetValue<0>() + GetValue<4>() * GetValue<4>() + GetValue<8>() * GetValue<8>());

    Multiply<0>(invLength);
    Multiply<4>(invLength);
    Multiply<8>(invLength);

    // ���� q1.
    auto dot0 = GetValue<0>() * GetValue<1>() + GetValue<4>() * GetValue<5>() + GetValue<8>() * GetValue<9>();

    Minus<1>(dot0 * GetValue<0>());
    Minus<5>(dot0 * GetValue<4>());
    Minus<9>(dot0 * GetValue<8>());

    invLength = Math::InvSqrt(GetValue<1>() * GetValue<1>() + GetValue<5>() * GetValue<5>() + GetValue<9>() * GetValue<9>());

    Multiply<1>(invLength);
    Multiply<5>(invLength);
    Multiply<9>(invLength);

    // ���� q2.
    auto dot1 = GetValue<1>() * GetValue<2>() + GetValue<5>() * GetValue<6>() + GetValue<9>() * GetValue<10>();

    dot0 = GetValue<0>() * GetValue<2>() + GetValue<4>() * GetValue<6>() + GetValue<8>() * GetValue<10>();

    Plus<2>(-dot0 * GetValue<0>() + dot1 * GetValue<1>());
    Plus<6>(-dot0 * GetValue<4>() + dot1 * GetValue<5>());
    Plus<10>(-dot0 * GetValue<8>() + dot1 * GetValue<9>());

    invLength = Math::InvSqrt(GetValue<2>() * GetValue<2>() + GetValue<6>() * GetValue<6>() + GetValue<10>() * GetValue<10>());

    Multiply<2>(invLength);
    Multiply<6>(invLength);
    Multiply<10>(invLength);
}

template <typename Real>
Real Mathematics::Matrix<Real>::QuadraticForm(const HomogeneousPoint& point0, const HomogeneousPoint& point1) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const HomogeneousPoint pointTransform{ GetValue<0>() * point1.GetX() + GetValue<1>() * point1.GetY() + GetValue<2>() * point1.GetZ() + GetValue<3>() * point1.GetW(),
                                           GetValue<4>() * point1.GetX() + GetValue<5>() * point1.GetY() + GetValue<6>() * point1.GetZ() + GetValue<7>() * point1.GetW(),
                                           GetValue<8>() * point1.GetX() + GetValue<9>() * point1.GetY() + GetValue<10>() * point1.GetZ() + GetValue<11>() * point1.GetW(),
                                           GetValue<12>() * point1.GetX() + GetValue<13>() * point1.GetY() + GetValue<14>() * point1.GetZ() + GetValue<15>() * point1.GetW() };

    const auto dot = point0.GetX() * pointTransform.GetX() + point0.GetY() * pointTransform.GetY() + point0.GetZ() * pointTransform.GetZ() + point0.GetW() * pointTransform.GetW();

    return dot;
}

template <typename Real>
void Mathematics::Matrix<Real>::MakeObliqueProjection(const APoint& origin, const AVector& normal, const AVector& direction)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(normal.IsNormalize() && direction.IsNormalize(), "normal��direction�����ǵ�λ������");

    // ͶӰƽ����Dot(N , X - P) = 0 ������N��һ��3��1����λ���ȵķ���������P��һ��3��1����ƽ�档ͶӰ��3��1����D�ķ�����б��ƽ�档
    // Ϊʹ��ͶӰ�����壬 Dot(N,D)һ�������㡣
    // ����һ��3��1��U�������� U + t * D��ƽ��Ľ����t = -Dot(N,U - P)/Dot(N,D)��
    // Ȼ��
    //
    //   projection(U) = P + [I - D * N^T / Dot(N,D)]*(U - P)
    //
    // һ��4��4����α任������
    //
    //       +-                                   -+
    //   M = | D * N^T - Dot(N,D) * I   -Dot(N,P)D |
    //       |           0^T            -Dot(N,D)  |
    //       +-                                   -+
    //
    // ����M������[U^T 1]^T Ϊ  M*[U^T 1]^T��
    // ѡ�����ʹ��ÿ��Dot(N,D) < 0ʱM[3][3] > 0��ͶӰ��ƽ���ϵġ����ࡱ����

    auto dotNormalDirection = Dot(normal, direction);
    auto dotNormalOrigin = Dot(origin, normal);

    m_Entry = Create(direction.GetX() * normal.GetX() - dotNormalDirection,
                     direction.GetX() * normal.GetY(),
                     direction.GetX() * normal.GetZ(),
                     -dotNormalOrigin * direction.GetX(),

                     direction.GetY() * normal.GetX(),
                     direction.GetY() * normal.GetY() - dotNormalDirection,
                     direction.GetY() * normal.GetZ(),
                     -dotNormalOrigin * direction.GetY(),

                     direction.GetZ() * normal.GetX(),
                     direction.GetZ() * normal.GetY(),
                     direction.GetZ() * normal.GetZ() - dotNormalDirection,
                     -dotNormalOrigin * direction.GetZ(),

                     Math::GetValue(0),
                     Math::GetValue(0),
                     Math::GetValue(0),
                     -dotNormalDirection,

                     MatrixMajorFlags::Row);
}

template <typename Real>
void Mathematics::Matrix<Real>::MakePerspectiveProjection(const APoint& origin, const AVector& normal, const APoint& eye)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(normal.IsNormalize(), "normal�����ǵ�λ������");

    //     +-                                                               -+
    // M = | Dot(N,E - P) * I - E * N^T    -(Dot(N,E - P) * I - E * N^T) * E |
    //     |         -N^t                          Dot(N,E)                  |
    //     +-                                                               -+
    //
    // ����EΪ�۵㣬PΪƽ���ϵ�һ���㣬��N�ǵ�λ���ȵ�ƽ�淨�ߡ�

    auto dotNormalDirection = Dot(normal, eye - origin);

    m_Entry = Create(dotNormalDirection - eye.GetX() * normal.GetX(),
                     -eye.GetX() * normal.GetY(),
                     -eye.GetX() * normal.GetY(),
                     -(GetValue<0>() * eye.GetX() + GetValue<1>() * eye.GetY() + GetValue<2>() * eye.GetY()),

                     -eye.GetY() * normal.GetX(),
                     dotNormalDirection - eye.GetY() * normal.GetY(),
                     -eye.GetY() * normal.GetY(),
                     -(GetValue<4>() * eye.GetX() + GetValue<5>() * eye.GetY() + GetValue<6>() * eye.GetY()),

                     -eye.GetZ() * normal.GetX(),
                     -eye.GetZ() * normal.GetY(),
                     dotNormalDirection - eye.GetY() * normal.GetY(),
                     -(GetValue<8>() * eye.GetX() + GetValue<9>() * eye.GetX() + GetValue<10>() * eye.GetY()),

                     -normal.GetX(),
                     -normal.GetY(),
                     -normal.GetZ(),
                     Dot(eye, normal),

                     MatrixMajorFlags::Row);
}

template <typename Real>
void Mathematics::Matrix<Real>::MakeReflection(const APoint& origin, const AVector& normal)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(normal.IsNormalize(), "normal�����ǵ�λ������");

    //     +-                                   -+
    // M = | I - 2 * N * N^T    2 * Dot(N,P) * N |
    //     |     0^T                      1      |
    //     +-                                   -+
    //
    // ����P��ƽ���ϵĵ㣬N��һ����λ���ȵ�ƽ�淨�ߡ�

    const auto twoDotNormalOrigin = Math::GetValue(2) * Dot(origin, normal);

    m_Entry = Create(Math::GetValue(1) - Math::GetValue(2) * normal.GetX() * normal.GetX(),
                     -Math::GetValue(2) * normal.GetX() * normal.GetY(),
                     -Math::GetValue(2) * normal.GetX() * normal.GetZ(),
                     twoDotNormalOrigin * normal.GetX(),

                     -Math::GetValue(2) * normal.GetY() * normal.GetX(),
                     Math::GetValue(1) - Math::GetValue(2) * normal.GetY() * normal.GetY(),
                     -Math::GetValue(2) * normal.GetY() * normal.GetZ(),
                     twoDotNormalOrigin * normal.GetY(),

                     -Math::GetValue(2) * normal.GetZ() * normal.GetX(),
                     -Math::GetValue(2) * normal.GetZ() * normal.GetY(),
                     Math::GetValue(1) - Math::GetValue(2) * normal.GetZ() * normal.GetZ(),
                     twoDotNormalOrigin * normal.GetZ(),

                     Math::GetValue(0),
                     Math::GetValue(0),
                     Math::GetValue(0),
                     Math::GetValue(1),

                     MatrixMajorFlags::Row);
}

template <typename Real>
Real Mathematics::Matrix<Real>::GetNorm() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto maxRowSum = Math::FAbs(GetValue<0>()) + Math::FAbs(GetValue<1>()) + Math::FAbs(GetValue<2>());

    auto rowSum = Math::FAbs(GetValue<4>()) + Math::FAbs(GetValue<5>()) + Math::FAbs(GetValue<6>());

    if (maxRowSum < rowSum)
    {
        maxRowSum = rowSum;
    }

    rowSum = Math::FAbs(GetValue<8>()) + Math::FAbs(GetValue<9>()) + Math::FAbs(GetValue<10>());

    if (maxRowSum < rowSum)
    {
        maxRowSum = rowSum;
    }

    return maxRowSum;
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& out, const Matrix<Real>& matrix)
{
    for (auto row = 0; row < Matrix<Real>::rowSize; ++row)
    {
        for (auto column = 0; column < Matrix<Real>::columnSize; ++column)
        {
            out << "(" << row << "," << column << ")��=��" << matrix(row, column) << "��";
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
    return lhs.GetData() < rhs.GetData();
}

template <typename Real>
Mathematics::Matrix<Real> Mathematics::operator*(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept
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
Mathematics::Matrix<Real> Mathematics::TransposeTimes(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept
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
Mathematics::Matrix<Real> Mathematics::TimesTranspose(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept
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
Mathematics::Matrix<Real> Mathematics::TransposeTimesTranspose(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept
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
Mathematics::HomogeneousPoint<Real> Mathematics::operator*(const Matrix<Real>& matrix, const HomogeneousPoint<Real>& point) noexcept
{
    return HomogeneousPoint<Real>{ matrix.GetValue<0>() * point.GetX() + matrix.GetValue<1>() * point.GetY() + matrix.GetValue<2>() * point.GetZ() + matrix.GetValue<3>() * point.GetW(),
                                   matrix.GetValue<4>() * point.GetX() + matrix.GetValue<5>() * point.GetY() + matrix.GetValue<6>() * point.GetZ() + matrix.GetValue<7>() * point.GetW(),
                                   matrix.GetValue<8>() * point.GetX() + matrix.GetValue<9>() * point.GetY() + matrix.GetValue<10>() * point.GetZ() + matrix.GetValue<11>() * point.GetW(),
                                   matrix.GetValue<12>() * point.GetX() + matrix.GetValue<13>() * point.GetY() + matrix.GetValue<14>() * point.GetZ() + matrix.GetValue<15>() * point.GetW() };
}

template <typename Real>
Mathematics::HomogeneousPoint<Real> Mathematics::operator*(const HomogeneousPoint<Real>& point, const Matrix<Real>& matrix) noexcept
{
    return HomogeneousPoint<Real>{ point.GetX() * matrix.GetValue<0>() + point.GetY() * matrix.GetValue<4>() + point.GetZ() * matrix.GetValue<8>() + point.GetW() * matrix.GetValue<12>(),
                                   point.GetX() * matrix.GetValue<1>() + point.GetY() * matrix.GetValue<5>() + point.GetZ() * matrix.GetValue<9>() + point.GetW() * matrix.GetValue<13>(),
                                   point.GetX() * matrix.GetValue<2>() + point.GetY() * matrix.GetValue<6>() + point.GetZ() * matrix.GetValue<10>() + point.GetW() * matrix.GetValue<14>(),
                                   point.GetX() * matrix.GetValue<3>() + point.GetY() * matrix.GetValue<7>() + point.GetZ() * matrix.GetValue<11>() + point.GetW() * matrix.GetValue<15>() };
}

template <typename Real>
typename Mathematics::HomogeneousPoint<Real>::ContainerType Mathematics::BatchMultiply(const Matrix<Real>& matrix, const typename HomogeneousPoint<Real>::ContainerType& inputPoints)
{
    typename HomogeneousPoint<Real>::ContainerType outputPoints{};

    for (const auto& point : inputPoints)
    {
        outputPoints.emplace_back(matrix * point);
    }

    MATHEMATICS_ASSERTION_2(outputPoints.size() == inputPoints.size(), "�������������С����ȣ�");

    return outputPoints;
}

template <typename Real>
Mathematics::APoint<Real> Mathematics::operator*(const Matrix<Real>& matrix, const APoint<Real>& point) noexcept
{
    return APoint<Real>{ matrix.GetValue<0>() * point.GetX() + matrix.GetValue<1>() * point.GetY() + matrix.GetValue<2>() * point.GetZ() + matrix.GetValue<3>(),
                         matrix.GetValue<4>() * point.GetX() + matrix.GetValue<5>() * point.GetY() + matrix.GetValue<6>() * point.GetZ() + matrix.GetValue<7>(),
                         matrix.GetValue<8>() * point.GetX() + matrix.GetValue<9>() * point.GetY() + matrix.GetValue<10>() * point.GetZ() + matrix.GetValue<11>() };
}

template <typename Real>
typename Mathematics::APoint<Real>::ContainerType Mathematics::BatchMultiply(const Matrix<Real>& matrix, const typename APoint<Real>::ContainerType& inputPoints)
{
    typename APoint<Real>::ContainerType outputPoints{};

    for (const auto& point : inputPoints)
    {
        outputPoints.emplace_back(matrix * point);
    }

    MATHEMATICS_ASSERTION_1(outputPoints.size() == inputPoints.size(), "�������������С����ȣ�");

    return outputPoints;
}

template <typename Real>
Mathematics::AVector<Real> Mathematics::operator*(const Matrix<Real>& matrix, const AVector<Real>& point) noexcept
{
    return AVector<Real>{ matrix.GetValue<0>() * point.GetX() + matrix.GetValue<1>() * point.GetY() + matrix.GetValue<2>() * point.GetZ(),
                          matrix.GetValue<4>() * point.GetX() + matrix.GetValue<5>() * point.GetY() + matrix.GetValue<6>() * point.GetZ(),
                          matrix.GetValue<8>() * point.GetX() + matrix.GetValue<9>() * point.GetY() + matrix.GetValue<10>() * point.GetZ() };
}

template <typename Real>
typename Mathematics::AVector<Real>::ContainerType Mathematics::BatchMultiply(const Matrix<Real>& matrix, const typename AVector<Real>::ContainerType& inputPoints)
{
    typename AVector<Real>::ContainerType outputPoints{};

    for (const auto& point : inputPoints)
    {
        outputPoints.emplace_back(matrix * point);
    }

    MATHEMATICS_ASSERTION_1(outputPoints.size() == inputPoints.size(), "�������������С����ȣ�");

    return outputPoints;
}

template <typename Real>
bool Mathematics::Approximate(const Matrix<Real>& lhs, const Matrix<Real>& rhs, const Real epsilon)
{
    for (auto row = 0u; row < Matrix<Real>::rowSize; ++row)
    {
        for (auto column = 0u; column < Matrix<Real>::columnSize; ++column)
        {
            if (epsilon < Math<Real>::FAbs(lhs(row, column) - rhs(row, column)))
            {
                return false;
            }
        }
    }

    return true;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX_DETAIL_H
