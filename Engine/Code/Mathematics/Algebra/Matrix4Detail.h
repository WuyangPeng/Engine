///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/09 11:13)

#ifndef MATHEMATICS_ALGEBRA_MATRIX4_DETAIL_H
#define MATHEMATICS_ALGEBRA_MATRIX4_DETAIL_H

#include "Matrix4.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATRIX4_ACHIEVE)

    #include "Matrix4Achieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATRIX4_ACHIEVE)

template <typename Real>
template <int Row, int Column>
Real Mathematics::Matrix4<Real>::GetValue() const noexcept
{
    static_assert(0 <= Row && Row < sm_VectorSize);
    static_assert(0 <= Column && Column < Vector4D::sm_PointSize);

    const auto& vector = GetVector<Row>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
    const auto function = GetVectorGetFunction<Column>();
#include STSTEM_WARNING_POP

    return (vector.*function)();
}

template <typename Real>
template <int Row, int Column>
void Mathematics::Matrix4<Real>::SetValue(Real value) noexcept
{
    static_assert(0 <= Row && Row < sm_VectorSize);
    static_assert(0 <= Column && Column < Vector4D::sm_PointSize);

    auto& vector = GetVector<Row>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
    const auto function = GetVectorSetFunction<Column>();
#include STSTEM_WARNING_POP

    (vector.*function)(value);
}

template <typename Real>
template <int Row>
const Mathematics::Vector4D<Real>& Mathematics::Matrix4<Real>::GetVector() const noexcept
{
    static_assert(0 <= Row && Row < sm_VectorSize);

    if constexpr (Row == sm_X)
        return m_X;
    else if constexpr (Row == sm_Y)
        return m_Y;
    else if constexpr (Row == sm_Z)
        return m_Z;
    else
        return m_W;
}

template <typename Real>
template <int Row>
Mathematics::Vector4D<Real>& Mathematics::Matrix4<Real>::GetVector() noexcept
{
    static_assert(0 <= Row && Row < sm_VectorSize);

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(Vector4D&, GetVector<Row>);
}

template <typename Real>
template <int Column>
typename Mathematics::Vector4D<Real>::GetCoordinateFunction Mathematics::Matrix4<Real>::GetVectorGetFunction() const noexcept
{
    static_assert(0 <= Column && Column < Vector4D::sm_PointSize);

    if constexpr (Column == Vector4D::sm_X)
        return &Vector4D::GetX;
    else if constexpr (Column == Vector4D::sm_Y)
        return &Vector4D::GetY;
    else if constexpr (Column == Vector4D::sm_Z)
        return &Vector4D::GetZ;
    else
        return &Vector4D::GetW;
}

template <typename Real>
template <int Column>
typename Mathematics::Vector4D<Real>::SetCoordinateFunction Mathematics::Matrix4<Real>::GetVectorSetFunction() const noexcept
{
    static_assert(0 <= Column && Column < Vector4D::sm_PointSize);

    if constexpr (Column == Vector4D::sm_X)
        return &Vector4D::SetX;
    else if constexpr (Column == Vector4D::sm_Y)
        return &Vector4D::SetY;
    else if constexpr (Column == Vector4D::sm_Z)
        return &Vector4D::SetZ;
    else
        return &Vector4D::SetW;
}

template <typename Real>
const Mathematics::Vector4D<Real> Mathematics::operator*(const Matrix4<Real>& matrix, const Vector4D<Real>& vector) noexcept
{
    return Vector4D<Real>{ matrix.GetValue<0, 0>() * vector.GetX() + matrix.GetValue<0, 1>() * vector.GetY() + matrix.GetValue<0, 2>() * vector.GetZ() + matrix.GetValue<0, 3>() * vector.GetW(),
                           matrix.GetValue<1, 0>() * vector.GetX() + matrix.GetValue<1, 1>() * vector.GetY() + matrix.GetValue<1, 2>() * vector.GetZ() + matrix.GetValue<1, 3>() * vector.GetW(),
                           matrix.GetValue<2, 0>() * vector.GetX() + matrix.GetValue<2, 1>() * vector.GetY() + matrix.GetValue<2, 2>() * vector.GetZ() + matrix.GetValue<2, 3>() * vector.GetW(),
                           matrix.GetValue<3, 0>() * vector.GetX() + matrix.GetValue<3, 1>() * vector.GetY() + matrix.GetValue<3, 2>() * vector.GetZ() + matrix.GetValue<3, 3>() * vector.GetW() };
}

template <typename Real>
const Mathematics::Vector4D<Real> Mathematics::operator*(const Vector4D<Real>& vector, const Matrix4<Real>& matrix) noexcept
{
    return Vector4D<Real>{ vector.GetX() * matrix.GetValue<0, 0>() + vector.GetY() * matrix.GetValue<1, 0>() + vector.GetZ() * matrix.GetValue<2, 0>() + vector.GetW() * matrix.GetValue<3, 0>(),
                           vector.GetX() * matrix.GetValue<0, 1>() + vector.GetY() * matrix.GetValue<1, 1>() + vector.GetZ() * matrix.GetValue<2, 1>() + vector.GetW() * matrix.GetValue<3, 1>(),
                           vector.GetX() * matrix.GetValue<0, 2>() + vector.GetY() * matrix.GetValue<1, 2>() + vector.GetZ() * matrix.GetValue<2, 2>() + vector.GetW() * matrix.GetValue<3, 2>(),
                           vector.GetX() * matrix.GetValue<0, 3>() + vector.GetY() * matrix.GetValue<1, 3>() + vector.GetZ() * matrix.GetValue<2, 3>() + vector.GetW() * matrix.GetValue<3, 3>() };
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics::operator*(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs) noexcept
{
    // A * B
    return Matrix4<Real>{ lhs.GetValue<0, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<0, 1>() * rhs.GetValue<1, 0>() + lhs.GetValue<0, 2>() * rhs.GetValue<2, 0>() + lhs.GetValue<0, 3>() * rhs.GetValue<3, 0>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<0, 1>() + lhs.GetValue<0, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<0, 2>() * rhs.GetValue<2, 1>() + lhs.GetValue<0, 3>() * rhs.GetValue<3, 1>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<0, 2>() + lhs.GetValue<0, 1>() * rhs.GetValue<1, 2>() + lhs.GetValue<0, 2>() * rhs.GetValue<2, 2>() + lhs.GetValue<0, 3>() * rhs.GetValue<3, 2>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<0, 3>() + lhs.GetValue<0, 1>() * rhs.GetValue<1, 3>() + lhs.GetValue<0, 2>() * rhs.GetValue<2, 3>() + lhs.GetValue<0, 3>() * rhs.GetValue<3, 3>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 0>() + lhs.GetValue<1, 2>() * rhs.GetValue<2, 0>() + lhs.GetValue<1, 3>() * rhs.GetValue<3, 0>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<0, 1>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<1, 2>() * rhs.GetValue<2, 1>() + lhs.GetValue<1, 3>() * rhs.GetValue<3, 1>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<0, 2>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 2>() + lhs.GetValue<1, 2>() * rhs.GetValue<2, 2>() + lhs.GetValue<1, 3>() * rhs.GetValue<3, 2>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<0, 3>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 3>() + lhs.GetValue<1, 2>() * rhs.GetValue<2, 3>() + lhs.GetValue<1, 3>() * rhs.GetValue<3, 3>(),
                          lhs.GetValue<2, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<2, 1>() * rhs.GetValue<1, 0>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 0>() + lhs.GetValue<2, 3>() * rhs.GetValue<3, 0>(),
                          lhs.GetValue<2, 0>() * rhs.GetValue<0, 1>() + lhs.GetValue<2, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 1>() + lhs.GetValue<2, 3>() * rhs.GetValue<3, 1>(),
                          lhs.GetValue<2, 0>() * rhs.GetValue<0, 2>() + lhs.GetValue<2, 1>() * rhs.GetValue<1, 2>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 2>() + lhs.GetValue<2, 3>() * rhs.GetValue<3, 2>(),
                          lhs.GetValue<2, 0>() * rhs.GetValue<0, 3>() + lhs.GetValue<2, 1>() * rhs.GetValue<1, 3>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 3>() + lhs.GetValue<2, 3>() * rhs.GetValue<3, 3>(),
                          lhs.GetValue<3, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<3, 1>() * rhs.GetValue<1, 0>() + lhs.GetValue<3, 2>() * rhs.GetValue<2, 0>() + lhs.GetValue<3, 3>() * rhs.GetValue<3, 0>(),
                          lhs.GetValue<3, 0>() * rhs.GetValue<0, 1>() + lhs.GetValue<3, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<3, 2>() * rhs.GetValue<2, 1>() + lhs.GetValue<3, 3>() * rhs.GetValue<3, 1>(),
                          lhs.GetValue<3, 0>() * rhs.GetValue<0, 2>() + lhs.GetValue<3, 1>() * rhs.GetValue<1, 2>() + lhs.GetValue<3, 2>() * rhs.GetValue<2, 2>() + lhs.GetValue<3, 3>() * rhs.GetValue<3, 2>(),
                          lhs.GetValue<3, 0>() * rhs.GetValue<0, 3>() + lhs.GetValue<3, 1>() * rhs.GetValue<1, 3>() + lhs.GetValue<3, 2>() * rhs.GetValue<2, 3>() + lhs.GetValue<3, 3>() * rhs.GetValue<3, 3>() };
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics::TransposeTimes(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs) noexcept
{
    // A^T * B
    return Matrix4<Real>{ lhs.GetValue<0, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 0>() * rhs.GetValue<1, 0>() + lhs.GetValue<2, 0>() * rhs.GetValue<2, 0>() + lhs.GetValue<3, 0>() * rhs.GetValue<3, 0>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<0, 1>() + lhs.GetValue<1, 0>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 0>() * rhs.GetValue<2, 1>() + lhs.GetValue<3, 0>() * rhs.GetValue<3, 1>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<0, 2>() + lhs.GetValue<1, 0>() * rhs.GetValue<1, 2>() + lhs.GetValue<2, 0>() * rhs.GetValue<2, 2>() + lhs.GetValue<3, 0>() * rhs.GetValue<3, 2>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<0, 3>() + lhs.GetValue<1, 0>() * rhs.GetValue<1, 3>() + lhs.GetValue<2, 0>() * rhs.GetValue<2, 3>() + lhs.GetValue<3, 0>() * rhs.GetValue<3, 3>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 0>() + lhs.GetValue<2, 1>() * rhs.GetValue<2, 0>() + lhs.GetValue<3, 1>() * rhs.GetValue<3, 0>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<0, 1>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 1>() * rhs.GetValue<2, 1>() + lhs.GetValue<3, 1>() * rhs.GetValue<3, 1>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<0, 2>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 2>() + lhs.GetValue<2, 1>() * rhs.GetValue<2, 2>() + lhs.GetValue<3, 1>() * rhs.GetValue<3, 2>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<0, 3>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 3>() + lhs.GetValue<2, 1>() * rhs.GetValue<2, 3>() + lhs.GetValue<3, 1>() * rhs.GetValue<3, 3>(),
                          lhs.GetValue<0, 2>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 2>() * rhs.GetValue<1, 0>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 0>() + lhs.GetValue<3, 2>() * rhs.GetValue<3, 0>(),
                          lhs.GetValue<0, 2>() * rhs.GetValue<0, 1>() + lhs.GetValue<1, 2>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 1>() + lhs.GetValue<3, 2>() * rhs.GetValue<3, 1>(),
                          lhs.GetValue<0, 2>() * rhs.GetValue<0, 2>() + lhs.GetValue<1, 2>() * rhs.GetValue<1, 2>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 2>() + lhs.GetValue<3, 2>() * rhs.GetValue<3, 2>(),
                          lhs.GetValue<0, 2>() * rhs.GetValue<0, 3>() + lhs.GetValue<1, 2>() * rhs.GetValue<1, 3>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 3>() + lhs.GetValue<3, 2>() * rhs.GetValue<3, 3>(),
                          lhs.GetValue<0, 3>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 3>() * rhs.GetValue<1, 0>() + lhs.GetValue<2, 3>() * rhs.GetValue<2, 0>() + lhs.GetValue<3, 3>() * rhs.GetValue<3, 0>(),
                          lhs.GetValue<0, 3>() * rhs.GetValue<0, 1>() + lhs.GetValue<1, 3>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 3>() * rhs.GetValue<2, 1>() + lhs.GetValue<3, 3>() * rhs.GetValue<3, 1>(),
                          lhs.GetValue<0, 3>() * rhs.GetValue<0, 2>() + lhs.GetValue<1, 3>() * rhs.GetValue<1, 2>() + lhs.GetValue<2, 3>() * rhs.GetValue<2, 2>() + lhs.GetValue<3, 3>() * rhs.GetValue<3, 2>(),
                          lhs.GetValue<0, 3>() * rhs.GetValue<0, 3>() + lhs.GetValue<1, 3>() * rhs.GetValue<1, 3>() + lhs.GetValue<2, 3>() * rhs.GetValue<2, 3>() + lhs.GetValue<3, 3>() * rhs.GetValue<3, 3>() };
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics::TimesTranspose(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs) noexcept
{
    // A * B^T
    return Matrix4<Real>{ lhs.GetValue<0, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<0, 1>() * rhs.GetValue<0, 1>() + lhs.GetValue<0, 2>() * rhs.GetValue<0, 2>() + lhs.GetValue<0, 3>() * rhs.GetValue<0, 3>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<1, 0>() + lhs.GetValue<0, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<0, 2>() * rhs.GetValue<1, 2>() + lhs.GetValue<0, 3>() * rhs.GetValue<1, 3>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<2, 0>() + lhs.GetValue<0, 1>() * rhs.GetValue<2, 1>() + lhs.GetValue<0, 2>() * rhs.GetValue<2, 2>() + lhs.GetValue<0, 3>() * rhs.GetValue<2, 3>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<3, 0>() + lhs.GetValue<0, 1>() * rhs.GetValue<3, 1>() + lhs.GetValue<0, 2>() * rhs.GetValue<3, 2>() + lhs.GetValue<0, 3>() * rhs.GetValue<3, 3>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<0, 1>() + lhs.GetValue<1, 2>() * rhs.GetValue<0, 2>() + lhs.GetValue<1, 3>() * rhs.GetValue<0, 3>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<1, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<1, 2>() * rhs.GetValue<1, 2>() + lhs.GetValue<1, 3>() * rhs.GetValue<1, 3>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<2, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<2, 1>() + lhs.GetValue<1, 2>() * rhs.GetValue<2, 2>() + lhs.GetValue<1, 3>() * rhs.GetValue<2, 3>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<3, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<3, 1>() + lhs.GetValue<1, 2>() * rhs.GetValue<3, 2>() + lhs.GetValue<1, 3>() * rhs.GetValue<3, 3>(),
                          lhs.GetValue<2, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<2, 1>() * rhs.GetValue<0, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<0, 2>() + lhs.GetValue<2, 3>() * rhs.GetValue<0, 3>(),
                          lhs.GetValue<2, 0>() * rhs.GetValue<1, 0>() + lhs.GetValue<2, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<1, 2>() + lhs.GetValue<2, 3>() * rhs.GetValue<1, 3>(),
                          lhs.GetValue<2, 0>() * rhs.GetValue<2, 0>() + lhs.GetValue<2, 1>() * rhs.GetValue<2, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 2>() + lhs.GetValue<2, 3>() * rhs.GetValue<2, 3>(),
                          lhs.GetValue<2, 0>() * rhs.GetValue<3, 0>() + lhs.GetValue<2, 1>() * rhs.GetValue<3, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<3, 2>() + lhs.GetValue<2, 3>() * rhs.GetValue<3, 3>(),
                          lhs.GetValue<3, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<3, 1>() * rhs.GetValue<0, 1>() + lhs.GetValue<3, 2>() * rhs.GetValue<0, 2>() + lhs.GetValue<3, 3>() * rhs.GetValue<0, 3>(),
                          lhs.GetValue<3, 0>() * rhs.GetValue<1, 0>() + lhs.GetValue<3, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<3, 2>() * rhs.GetValue<1, 2>() + lhs.GetValue<3, 3>() * rhs.GetValue<1, 3>(),
                          lhs.GetValue<3, 0>() * rhs.GetValue<2, 0>() + lhs.GetValue<3, 1>() * rhs.GetValue<2, 1>() + lhs.GetValue<3, 2>() * rhs.GetValue<2, 2>() + lhs.GetValue<3, 3>() * rhs.GetValue<2, 3>(),
                          lhs.GetValue<3, 0>() * rhs.GetValue<3, 0>() + lhs.GetValue<3, 1>() * rhs.GetValue<3, 1>() + lhs.GetValue<3, 2>() * rhs.GetValue<3, 2>() + lhs.GetValue<3, 3>() * rhs.GetValue<3, 3>() };
}

template <typename Real>
const Mathematics::Matrix4<Real> Mathematics::TransposeTimesTranspose(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs) noexcept
{
    // A^T * B^T
    return Matrix4<Real>{ lhs.GetValue<0, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 0>() * rhs.GetValue<0, 1>() + lhs.GetValue<2, 0>() * rhs.GetValue<0, 2>() + lhs.GetValue<3, 0>() * rhs.GetValue<0, 3>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<1, 0>() + lhs.GetValue<1, 0>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 0>() * rhs.GetValue<1, 2>() + lhs.GetValue<3, 0>() * rhs.GetValue<1, 3>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<2, 0>() + lhs.GetValue<1, 0>() * rhs.GetValue<2, 1>() + lhs.GetValue<2, 0>() * rhs.GetValue<2, 2>() + lhs.GetValue<3, 0>() * rhs.GetValue<2, 3>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<3, 0>() + lhs.GetValue<1, 0>() * rhs.GetValue<3, 1>() + lhs.GetValue<2, 0>() * rhs.GetValue<3, 2>() + lhs.GetValue<3, 0>() * rhs.GetValue<3, 3>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<0, 1>() + lhs.GetValue<2, 1>() * rhs.GetValue<0, 2>() + lhs.GetValue<3, 1>() * rhs.GetValue<0, 3>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<1, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 1>() * rhs.GetValue<1, 2>() + lhs.GetValue<3, 1>() * rhs.GetValue<1, 3>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<2, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<2, 1>() + lhs.GetValue<2, 1>() * rhs.GetValue<2, 2>() + lhs.GetValue<3, 1>() * rhs.GetValue<2, 3>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<3, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<3, 1>() + lhs.GetValue<2, 1>() * rhs.GetValue<3, 2>() + lhs.GetValue<3, 1>() * rhs.GetValue<3, 3>(),
                          lhs.GetValue<0, 2>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 2>() * rhs.GetValue<0, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<0, 2>() + lhs.GetValue<3, 2>() * rhs.GetValue<0, 3>(),
                          lhs.GetValue<0, 2>() * rhs.GetValue<1, 0>() + lhs.GetValue<1, 2>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<1, 2>() + lhs.GetValue<3, 2>() * rhs.GetValue<1, 3>(),
                          lhs.GetValue<0, 2>() * rhs.GetValue<2, 0>() + lhs.GetValue<1, 2>() * rhs.GetValue<2, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 2>() + lhs.GetValue<3, 2>() * rhs.GetValue<2, 3>(),
                          lhs.GetValue<0, 2>() * rhs.GetValue<3, 0>() + lhs.GetValue<1, 2>() * rhs.GetValue<3, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<3, 2>() + lhs.GetValue<3, 2>() * rhs.GetValue<3, 3>(),
                          lhs.GetValue<0, 3>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 3>() * rhs.GetValue<0, 1>() + lhs.GetValue<2, 3>() * rhs.GetValue<0, 2>() + lhs.GetValue<3, 3>() * rhs.GetValue<0, 3>(),
                          lhs.GetValue<0, 3>() * rhs.GetValue<1, 0>() + lhs.GetValue<1, 3>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 3>() * rhs.GetValue<1, 2>() + lhs.GetValue<3, 3>() * rhs.GetValue<1, 3>(),
                          lhs.GetValue<0, 3>() * rhs.GetValue<2, 0>() + lhs.GetValue<1, 3>() * rhs.GetValue<2, 1>() + lhs.GetValue<2, 3>() * rhs.GetValue<2, 2>() + lhs.GetValue<3, 3>() * rhs.GetValue<2, 3>(),
                          lhs.GetValue<0, 3>() * rhs.GetValue<3, 0>() + lhs.GetValue<1, 3>() * rhs.GetValue<3, 1>() + lhs.GetValue<2, 3>() * rhs.GetValue<3, 2>() + lhs.GetValue<3, 3>() * rhs.GetValue<3, 3>() };
}

template <typename Real>
bool Mathematics::Approximate(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs, const Real epsilon)
{
    for (auto row = 0; row < Matrix4<Real>::sm_VectorSize; ++row)
    {
        for (auto column = 0; column < Vector4D<Real>::sm_PointSize; ++column)
        {
            if (epsilon < Math<Real>::FAbs(lhs(row, column) - rhs(row, column)))
            {
                return false;
            }
        }
    }

    return true;
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Matrix4<Real>& matrix)
{
    for (auto row = 0; row < Matrix4<Real>::sm_VectorSize; ++row)
    {
        for (auto column = 0; column < Vector4D<Real>::sm_PointSize; ++column)
        {
            outFile << matrix(row, column) << "　";
        }
    }

    return outFile;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX4_DETAIL_H