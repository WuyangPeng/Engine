///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 16:11)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_DETAIL_H
#define MATHEMATICS_ALGEBRA_MATRIX2_DETAIL_H

#include "Matrix2.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATRIX2_ACHIEVE)

    #include "Matrix2Achieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATRIX2_ACHIEVE)

template <typename Real>
template <int Row, int Column>
Real Mathematics::Matrix2<Real>::GetValue() const noexcept
{
    static_assert(0 <= Row && Row < vectorSize);
    static_assert(0 <= Column && Column < Vector2::pointSize);

    const auto& vector = GetVector<Row>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)

    const auto function = GetVectorGetFunction<Column>();

#include STSTEM_WARNING_POP

    return (vector.*function)();
}

template <typename Real>
template <int Row, int Column>
void Mathematics::Matrix2<Real>::SetValue(Real value) noexcept
{
    static_assert(0 <= Row && Row < vectorSize);
    static_assert(0 <= Column && Column < Vector2::pointSize);

    auto& vector = GetVector<Row>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)

    const auto function = GetVectorSetFunction<Column>();

#include STSTEM_WARNING_POP

    (vector.*function)(value);
}

template <typename Real>
template <int Row>
const Mathematics::Vector2<Real>& Mathematics::Matrix2<Real>::GetVector() const noexcept
{
    static_assert(0 <= Row && Row < vectorSize);

    if constexpr (Row == xIndex)
        return m_X;
    else
        return m_Y;
}

template <typename Real>
template <int Row>
Mathematics::Vector2<Real>& Mathematics::Matrix2<Real>::GetVector() noexcept
{
    static_assert(0 <= Row && Row < vectorSize);

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(Vector2&, GetVector<Row>);
}

template <typename Real>
template <int Column>
typename Mathematics::Vector2<Real>::GetCoordinateFunction Mathematics::Matrix2<Real>::GetVectorGetFunction() const noexcept
{
    static_assert(0 <= Column && Column < Vector2::pointSize);

    if constexpr (Column == Vector2::xIndex)
        return &Vector2::GetX;
    else
        return &Vector2::GetY;
}

template <typename Real>
template <int Column>
typename Mathematics::Vector2<Real>::SetCoordinateFunction Mathematics::Matrix2<Real>::GetVectorSetFunction() const noexcept
{
    static_assert(0 <= Column && Column < Vector2::pointSize);

    if constexpr (Column == Vector2::xIndex)
        return &Vector2::SetX;
    else
        return &Vector2::SetY;
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::operator*(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept
{
    // A * B
    return Matrix2<Real>{ lhs.GetValue<0, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<0, 1>() * rhs.GetValue<1, 0>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<0, 1>() + lhs.GetValue<0, 1>() * rhs.GetValue<1, 1>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 0>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<0, 1>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 1>() };
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::operator*(const Matrix2<Real>& matrix, const Vector2<Real>& vector) noexcept
{
    return Vector2<Real>{ matrix.GetValue<0, 0>() * vector.GetX() + matrix.GetValue<0, 1>() * vector.GetY(), matrix.GetValue<1, 0>() * vector.GetX() + matrix.GetValue<1, 1>() * vector.GetY() };
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::operator*(const Vector2<Real>& vector, const Matrix2<Real>& matrix) noexcept
{
    return Vector2<Real>{ vector.GetX() * matrix.GetValue<0, 0>() + vector.GetY() * matrix.GetValue<1, 0>(), vector.GetX() * matrix.GetValue<0, 1>() + vector.GetY() * matrix.GetValue<1, 1>() };
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::TransposeTimes(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept
{
    // lhs^T * rhs
    return Matrix2<Real>{ lhs.GetValue<0, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 0>() * rhs.GetValue<1, 0>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<0, 1>() + lhs.GetValue<1, 0>() * rhs.GetValue<1, 1>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 0>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<0, 1>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 1>() };
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::TimesTranspose(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept
{
    // lhs * rhs^T
    return Matrix2<Real>{ lhs.GetValue<0, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<0, 1>() * rhs.GetValue<0, 1>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<1, 0>() + lhs.GetValue<0, 1>() * rhs.GetValue<1, 1>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<0, 1>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<1, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 1>() };
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::TransposeTimesTranspose(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept
{
    // lhs^T * rhs^T

    return Matrix2<Real>{ lhs.GetValue<0, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 0>() * rhs.GetValue<0, 1>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<1, 0>() + lhs.GetValue<1, 0>() * rhs.GetValue<1, 1>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<0, 1>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<1, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 1>() };
}

template <typename Real>
bool Mathematics::Approximate(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs, const Real epsilon) noexcept
{
    return Math<Real>::FAbs(lhs.GetValue<0, 0>() - rhs.GetValue<0, 0>()) <= epsilon &&
           Math<Real>::FAbs(lhs.GetValue<0, 1>() - rhs.GetValue<0, 1>()) <= epsilon &&
           Math<Real>::FAbs(lhs.GetValue<1, 0>() - rhs.GetValue<1, 0>()) <= epsilon &&
           Math<Real>::FAbs(lhs.GetValue<1, 1>() - rhs.GetValue<1, 1>()) <= epsilon;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX2_DETAIL_H