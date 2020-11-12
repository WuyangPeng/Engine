///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/06 14:46)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_DETAIL_H
#define MATHEMATICS_ALGEBRA_MATRIX3_DETAIL_H

#include "Matrix3.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATRIX3_ACHIEVE)

    #include "Matrix3Achieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATRIX3_ACHIEVE)

template <typename Real>
template <int Row, int Column>
Real Mathematics::Matrix3<Real>::GetValue() const noexcept
{
    static_assert(0 <= Row && Row < sm_VectorSize);
    static_assert(0 <= Column && Column < Vector3D::sm_PointSize);

    const auto& vector = GetVector<Row>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
    const auto function = GetVectorGetFunction<Column>();
#include STSTEM_WARNING_POP

    return (vector.*function)();
}

template <typename Real>
template <int Row, int Column>
void Mathematics::Matrix3<Real>::SetValue(Real value) noexcept
{
    static_assert(0 <= Row && Row < sm_VectorSize);
    static_assert(0 <= Column && Column < Vector3D::sm_PointSize);

    auto& vector = GetVector<Row>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
    const auto function = GetVectorSetFunction<Column>();
#include STSTEM_WARNING_POP

    (vector.*function)(value);
}

template <typename Real>
template <int Row>
const Mathematics::Vector3D<Real>& Mathematics::Matrix3<Real>::GetVector() const noexcept
{
    static_assert(0 <= Row && Row < sm_VectorSize);

    if constexpr (Row == sm_X)
        return m_X;
    else if constexpr (Row == sm_Y)
        return m_Y;
    else
        return m_Z;
}

template <typename Real>
template <int Row>
Mathematics::Vector3D<Real>& Mathematics::Matrix3<Real>::GetVector() noexcept
{
    static_assert(0 <= Row && Row < sm_VectorSize);

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(Vector3D&, GetVector<Row>);
}

template <typename Real>
template <int Column>
typename Mathematics::Vector3D<Real>::GetCoordinateFunction Mathematics::Matrix3<Real>::GetVectorGetFunction() const noexcept
{
    static_assert(0 <= Column && Column < Vector3D::sm_PointSize);

    if constexpr (Column == Vector3D::sm_X)
        return &Vector3D::GetX;
    else if constexpr (Column == Vector3D::sm_Y)
        return &Vector3D::GetY;
    else
        return &Vector3D::GetZ;
}

template <typename Real>
template <int Column>
typename Mathematics::Vector3D<Real>::SetCoordinateFunction Mathematics::Matrix3<Real>::GetVectorSetFunction() const noexcept
{
    static_assert(0 <= Column && Column < Vector3D::sm_PointSize);

    if constexpr (Column == Vector3D::sm_X)
        return &Vector3D::SetX;
    else if constexpr (Column == Vector3D::sm_Y)
        return &Vector3D::SetY;
    else
        return &Vector3D::SetZ;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::operator*(const Vector3D<Real>& vector, const Matrix3<Real>& matrix) noexcept
{
    return Vector3D<Real>{ vector.GetX() * matrix.GetValue<0, 0>() + vector.GetY() * matrix.GetValue<1, 0>() + vector.GetZ() * matrix.GetValue<2, 0>(),
                           vector.GetX() * matrix.GetValue<0, 1>() + vector.GetY() * matrix.GetValue<1, 1>() + vector.GetZ() * matrix.GetValue<2, 1>(),
                           vector.GetX() * matrix.GetValue<0, 2>() + vector.GetY() * matrix.GetValue<1, 2>() + vector.GetZ() * matrix.GetValue<2, 2>() };
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::operator*(const Matrix3<Real>& matrix, const Vector3D<Real>& vector) noexcept
{
    return Vector3D<Real>{ matrix.GetValue<0, 0>() * vector.GetX() + matrix.GetValue<0, 1>() * vector.GetY() + matrix.GetValue<0, 2>() * vector.GetZ(),
                           matrix.GetValue<1, 0>() * vector.GetX() + matrix.GetValue<1, 1>() * vector.GetY() + matrix.GetValue<1, 2>() * vector.GetZ(),
                           matrix.GetValue<2, 0>() * vector.GetX() + matrix.GetValue<2, 1>() * vector.GetY() + matrix.GetValue<2, 2>() * vector.GetZ() };
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::operator*(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept
{
    // A * B
    return Matrix3<Real>{ lhs.GetValue<0, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<0, 1>() * rhs.GetValue<1, 0>() + lhs.GetValue<0, 2>() * rhs.GetValue<2, 0>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<0, 1>() + lhs.GetValue<0, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<0, 2>() * rhs.GetValue<2, 1>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<0, 2>() + lhs.GetValue<0, 1>() * rhs.GetValue<1, 2>() + lhs.GetValue<0, 2>() * rhs.GetValue<2, 2>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 0>() + lhs.GetValue<1, 2>() * rhs.GetValue<2, 0>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<0, 1>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<1, 2>() * rhs.GetValue<2, 1>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<0, 2>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 2>() + lhs.GetValue<1, 2>() * rhs.GetValue<2, 2>(),
                          lhs.GetValue<2, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<2, 1>() * rhs.GetValue<1, 0>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 0>(),
                          lhs.GetValue<2, 0>() * rhs.GetValue<0, 1>() + lhs.GetValue<2, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 1>(),
                          lhs.GetValue<2, 0>() * rhs.GetValue<0, 2>() + lhs.GetValue<2, 1>() * rhs.GetValue<1, 2>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 2>() };
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::TransposeTimes(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept
{
    // A^T * B
    return Matrix3<Real>{ lhs.GetValue<0, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 0>() * rhs.GetValue<1, 0>() + lhs.GetValue<2, 0>() * rhs.GetValue<2, 0>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<0, 1>() + lhs.GetValue<1, 0>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 0>() * rhs.GetValue<2, 1>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<0, 2>() + lhs.GetValue<1, 0>() * rhs.GetValue<1, 2>() + lhs.GetValue<2, 0>() * rhs.GetValue<2, 2>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 0>() + lhs.GetValue<2, 1>() * rhs.GetValue<2, 0>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<0, 1>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 1>() * rhs.GetValue<2, 1>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<0, 2>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 2>() + lhs.GetValue<2, 1>() * rhs.GetValue<2, 2>(),
                          lhs.GetValue<0, 2>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 2>() * rhs.GetValue<1, 0>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 0>(),
                          lhs.GetValue<0, 2>() * rhs.GetValue<0, 1>() + lhs.GetValue<1, 2>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 1>(),
                          lhs.GetValue<0, 2>() * rhs.GetValue<0, 2>() + lhs.GetValue<1, 2>() * rhs.GetValue<1, 2>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 2>() };
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::TimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept
{
    // A * B^T
    return Matrix3<Real>{ lhs.GetValue<0, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<0, 1>() * rhs.GetValue<0, 1>() + lhs.GetValue<0, 2>() * rhs.GetValue<0, 2>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<1, 0>() + lhs.GetValue<0, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<0, 2>() * rhs.GetValue<1, 2>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<2, 0>() + lhs.GetValue<0, 1>() * rhs.GetValue<2, 1>() + lhs.GetValue<0, 2>() * rhs.GetValue<2, 2>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<0, 1>() + lhs.GetValue<1, 2>() * rhs.GetValue<0, 2>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<1, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<1, 2>() * rhs.GetValue<1, 2>(),
                          lhs.GetValue<1, 0>() * rhs.GetValue<2, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<2, 1>() + lhs.GetValue<1, 2>() * rhs.GetValue<2, 2>(),
                          lhs.GetValue<2, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<2, 1>() * rhs.GetValue<0, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<0, 2>(),
                          lhs.GetValue<2, 0>() * rhs.GetValue<1, 0>() + lhs.GetValue<2, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<1, 2>(),
                          lhs.GetValue<2, 0>() * rhs.GetValue<2, 0>() + lhs.GetValue<2, 1>() * rhs.GetValue<2, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 2>() };
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::TransposeTimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept
{
    // A^T * B^T
    return Matrix3<Real>{ lhs.GetValue<0, 0>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 0>() * rhs.GetValue<0, 1>() + lhs.GetValue<2, 0>() * rhs.GetValue<0, 2>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<1, 0>() + lhs.GetValue<1, 0>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 0>() * rhs.GetValue<1, 2>(),
                          lhs.GetValue<0, 0>() * rhs.GetValue<2, 0>() + lhs.GetValue<1, 0>() * rhs.GetValue<2, 1>() + lhs.GetValue<2, 0>() * rhs.GetValue<2, 2>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<0, 1>() + lhs.GetValue<2, 1>() * rhs.GetValue<0, 2>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<1, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 1>() * rhs.GetValue<1, 2>(),
                          lhs.GetValue<0, 1>() * rhs.GetValue<2, 0>() + lhs.GetValue<1, 1>() * rhs.GetValue<2, 1>() + lhs.GetValue<2, 1>() * rhs.GetValue<2, 2>(),
                          lhs.GetValue<0, 2>() * rhs.GetValue<0, 0>() + lhs.GetValue<1, 2>() * rhs.GetValue<0, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<0, 2>(),
                          lhs.GetValue<0, 2>() * rhs.GetValue<1, 0>() + lhs.GetValue<1, 2>() * rhs.GetValue<1, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<1, 2>(),
                          lhs.GetValue<0, 2>() * rhs.GetValue<2, 0>() + lhs.GetValue<1, 2>() * rhs.GetValue<2, 1>() + lhs.GetValue<2, 2>() * rhs.GetValue<2, 2>() };
}

template <typename Real>
bool Mathematics::Approximate(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs, const Real epsilon)
{
    for (auto row = 0; row < Matrix3<Real>::sm_VectorSize; ++row)
    {
        for (auto column = 0; column < Vector3D<Real>::sm_PointSize; ++column)
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
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Matrix3<Real>& matrix)
{
    for (auto row = 0; row < Matrix3<Real>::sm_VectorSize; ++row)
    {
        for (auto column = 0; column < Vector3D<Real>::sm_PointSize; ++column)
        {
            outFile << matrix(row, column) << "　";
        }
    }

    return outFile;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_DETAIL_H
