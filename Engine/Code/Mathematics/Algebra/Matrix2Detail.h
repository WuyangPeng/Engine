///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 10:28)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_DETAIL_H
#define MATHEMATICS_ALGEBRA_MATRIX2_DETAIL_H

#include "Matrix2.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATRIX2_ACHIEVE)

    #include "Matrix2Achieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATRIX2_ACHIEVE)

template <typename Real>
requires std::is_arithmetic_v<Real>
template <int Row, int Column>
Real Mathematics::Matrix2<Real>::GetValue() const noexcept
{
    static_assert(0 <= Row && Row < vectorSize);
    static_assert(0 <= Column && Column < Vector2::pointSize);

    const auto& vector = GetVector<Row>();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)

    const auto function = GetVectorGetFunction<Column>();

#include SYSTEM_WARNING_POP

    return (vector.*function)();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
template <int Row, int Column>
void Mathematics::Matrix2<Real>::SetValue(Real value) noexcept
{
    static_assert(0 <= Row && Row < vectorSize);
    static_assert(0 <= Column && Column < Vector2::pointSize);

    auto& vector = GetVector<Row>();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)

    const auto function = GetVectorSetFunction<Column>();

#include SYSTEM_WARNING_POP

    (vector.*function)(value);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
template <int Row>
const Mathematics::Vector2<Real>& Mathematics::Matrix2<Real>::GetVector() const noexcept
{
    static_assert(0 <= Row && Row < vectorSize);

    if constexpr (Row == xIndex)
        return x;
    else
        return y;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
template <int Row>
Mathematics::Vector2<Real>& Mathematics::Matrix2<Real>::GetVector() noexcept
{
    static_assert(0 <= Row && Row < vectorSize);

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(Vector2&, GetVector<Row>);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
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
requires std::is_arithmetic_v<Real>
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
    return Matrix2<Real>{ lhs.template GetValue<0, 0>() * rhs.template GetValue<0, 0>() + lhs.template GetValue<0, 1>() * rhs.template GetValue<1, 0>(),
                          lhs.template GetValue<0, 0>() * rhs.template GetValue<0, 1>() + lhs.template GetValue<0, 1>() * rhs.template GetValue<1, 1>(),
                          lhs.template GetValue<1, 0>() * rhs.template GetValue<0, 0>() + lhs.template GetValue<1, 1>() * rhs.template GetValue<1, 0>(),
                          lhs.template GetValue<1, 0>() * rhs.template GetValue<0, 1>() + lhs.template GetValue<1, 1>() * rhs.template GetValue<1, 1>() };
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::operator*(const Matrix2<Real>& matrix, const Vector2<Real>& vector) noexcept
{
    return Vector2<Real>{ matrix.template GetValue<0, 0>() * vector.GetX() + matrix.template GetValue<0, 1>() * vector.GetY(), matrix.template GetValue<1, 0>() * vector.GetX() + matrix.template GetValue<1, 1>() * vector.GetY() };
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::operator*(const Vector2<Real>& vector, const Matrix2<Real>& matrix) noexcept
{
    return Vector2<Real>{ vector.GetX() * matrix.template GetValue<0, 0>() + vector.GetY() * matrix.template GetValue<1, 0>(), vector.GetX() * matrix.template GetValue<0, 1>() + vector.GetY() * matrix.template GetValue<1, 1>() };
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::TransposeTimes(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept
{
    // lhs^T * rhs
    return Matrix2<Real>{ lhs.template GetValue<0, 0>() * rhs.template GetValue<0, 0>() + lhs.template GetValue<1, 0>() * rhs.template GetValue<1, 0>(),
                          lhs.template GetValue<0, 0>() * rhs.template GetValue<0, 1>() + lhs.template GetValue<1, 0>() * rhs.template GetValue<1, 1>(),
                          lhs.template GetValue<0, 1>() * rhs.template GetValue<0, 0>() + lhs.template GetValue<1, 1>() * rhs.template GetValue<1, 0>(),
                          lhs.template GetValue<0, 1>() * rhs.template GetValue<0, 1>() + lhs.template GetValue<1, 1>() * rhs.template GetValue<1, 1>() };
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::TimesTranspose(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept
{
    // lhs * rhs^T
    return Matrix2<Real>{ lhs.template GetValue<0, 0>() * rhs.template GetValue<0, 0>() + lhs.template GetValue<0, 1>() * rhs.template GetValue<0, 1>(),
                          lhs.template GetValue<0, 0>() * rhs.template GetValue<1, 0>() + lhs.template GetValue<0, 1>() * rhs.template GetValue<1, 1>(),
                          lhs.template GetValue<1, 0>() * rhs.template GetValue<0, 0>() + lhs.template GetValue<1, 1>() * rhs.template GetValue<0, 1>(),
                          lhs.template GetValue<1, 0>() * rhs.template GetValue<1, 0>() + lhs.template GetValue<1, 1>() * rhs.template GetValue<1, 1>() };
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::TransposeTimesTranspose(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept
{
    // lhs^T * rhs^T

    return Matrix2<Real>{ lhs.template GetValue<0, 0>() * rhs.template GetValue<0, 0>() + lhs.template GetValue<1, 0>() * rhs.template GetValue<0, 1>(),
                          lhs.template GetValue<0, 0>() * rhs.template GetValue<1, 0>() + lhs.template GetValue<1, 0>() * rhs.template GetValue<1, 1>(),
                          lhs.template GetValue<0, 1>() * rhs.template GetValue<0, 0>() + lhs.template GetValue<1, 1>() * rhs.template GetValue<0, 1>(),
                          lhs.template GetValue<0, 1>() * rhs.template GetValue<1, 0>() + lhs.template GetValue<1, 1>() * rhs.template GetValue<1, 1>() };
}

template <typename Real>
bool Mathematics::Approximate(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs, Real epsilon) noexcept
{
    return Math<Real>::FAbs(lhs.template GetValue<0, 0>() - rhs.template GetValue<0, 0>()) <= epsilon &&
           Math<Real>::FAbs(lhs.template GetValue<0, 1>() - rhs.template GetValue<0, 1>()) <= epsilon &&
           Math<Real>::FAbs(lhs.template GetValue<1, 0>() - rhs.template GetValue<1, 0>()) <= epsilon &&
           Math<Real>::FAbs(lhs.template GetValue<1, 1>() - rhs.template GetValue<1, 1>()) <= epsilon;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX2_DETAIL_H