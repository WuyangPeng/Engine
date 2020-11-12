///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/02 10:09)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_STREAM_SIZE_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_STREAM_SIZE_H

#include "APoint.h"
#include "AQuaternion.h"
#include "AVector.h"
#include "BandedMatrix.h"
#include "BandedMatrixSolve.h"
#include "HomogeneousPoint.h"
#include "Matrix.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Plane.h"
#include "Polynomial.h"
#include "Quaternion.h"
#include "VariableLengthVector.h"
#include "VariableMatrix.h"
#include "Vector2D.h"
#include "Vector3D.h"
#include "Vector4D.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Base/Float.h"

template <typename Real>
struct CoreTools::StreamSize<Mathematics::HomogeneousPoint<Real>>
{
    using HomogeneousPoint = Mathematics::HomogeneousPoint<Real>;

    constexpr static int GetStreamSize([[maybe_unused]] const HomogeneousPoint& value) noexcept
    {
        return GetStreamSize();
    }

    constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * HomogeneousPoint::GetPointSize();
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Vector2D<Real>>
{
    using Vector2D = Mathematics::Vector2D<Real>;

    constexpr static int GetStreamSize([[maybe_unused]] const Vector2D& value) noexcept
    {
        return GetStreamSize();
    }

    constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * Vector2D::sm_PointSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Vector3D<Real>>
{
    using Vector3D = Mathematics::Vector3D<Real>;

    constexpr static int GetStreamSize([[maybe_unused]] const Vector3D& value) noexcept
    {
        return GetStreamSize();
    }

    constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * Vector3D::sm_PointSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Vector4D<Real>>
{
    using Vector4D = Mathematics::Vector4D<Real>;

    constexpr static int GetStreamSize([[maybe_unused]] const Vector4D& value) noexcept
    {
        return GetStreamSize();
    }

    constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * Vector4D::sm_PointSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::AVector<Real>>
{
    using AVector = Mathematics::AVector<Real>;

    constexpr static int GetStreamSize([[maybe_unused]] const AVector& value) noexcept
    {
        return GetStreamSize();
    }

    constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * AVector::sm_AVectorSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::APoint<Real>>
{
    using APoint = Mathematics::APoint<Real>;

    constexpr static int GetStreamSize([[maybe_unused]] const APoint& value) noexcept
    {
        return GetStreamSize();
    }

    constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * APoint::sm_APointSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::VariableLengthVector<Real>>
{
    using VariableLengthVector = Mathematics::VariableLengthVector<Real>;

    static int GetStreamSize(const VariableLengthVector& value)
    {
        return StreamSize<Real>::GetStreamSize() * value.GetSize() + StreamSize<int32_t>::GetStreamSize();
    }

    static int GetStreamSize()
    {
        return GetStreamSize(VariableLengthVector{});
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Plane<Real>>
{
    using Plane = Mathematics::Plane<Real>;

    constexpr static int GetStreamSize([[maybe_unused]] const Plane& value) noexcept
    {
        return GetStreamSize();
    }

    constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * Plane::sm_PlaneSize + StreamSize<Real>::GetStreamSize();
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Polynomial<Real>>
{
    using Polynomial = Mathematics::Polynomial<Real>;

    static int GetStreamSize(const Polynomial& value)
    {
        return StreamSize<Real>::GetStreamSize() * (value.GetDegree() + 1) + StreamSize<int32_t>::GetStreamSize();
    }

    static int GetStreamSize()
    {
        return GetStreamSize(Polynomial{});
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Matrix2<Real>>
{
    using Matrix2 = Mathematics::Matrix2<Real>;

    constexpr static int GetStreamSize([[maybe_unused]] const Matrix2& value)
    {
        return GetStreamSize();
    }

    constexpr static int GetStreamSize()
    {
        return StreamSize<Real>::GetStreamSize() * Matrix2::sm_MatrixSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Matrix3<Real>>
{
    using Matrix3 = Mathematics::Matrix3<Real>;

    constexpr static int GetStreamSize([[maybe_unused]] const Matrix3& value)
    {
        return GetStreamSize();
    }

    constexpr static int GetStreamSize()
    {
        return StreamSize<Real>::GetStreamSize() * Matrix3::sm_MatrixSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Matrix4<Real>>
{
    using Matrix4 = Mathematics::Matrix4<Real>;

    constexpr static int GetStreamSize([[maybe_unused]] const Matrix4& value)
    {
        return GetStreamSize();
    }

    constexpr static int GetStreamSize()
    {
        return StreamSize<Real>::GetStreamSize() * Matrix4::sm_MatrixSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Matrix<Real>>
{
    using Matrix = Mathematics::Matrix<Real>;

    constexpr static int GetStreamSize([[maybe_unused]] const Matrix& value) noexcept
    {
        return GetStreamSize();
    }

    constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * Matrix::sm_EntrySize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::VariableMatrix<Real>>
{
    using VariableMatrix = Mathematics::VariableMatrix<Real>;

    static int GetStreamSize(const VariableMatrix& value) noexcept
    {
        return StreamSize<Real>::GetStreamSize() * value.GetElementsNumber() + StreamSize<int32_t>::GetStreamSize() * 2;
    }

    static int GetStreamSize()
    {
        return GetStreamSize(VariableMatrix{});
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::BandedMatrix<Real>>
{
    using BandedMatrix = Mathematics::BandedMatrix<Real>;

    static int GetStreamSize(const BandedMatrix& value) noexcept
    {
        return value.GetStreamSize();
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::BandedMatrixSolve<Real>>
{
    using BandedMatrixSolve = Mathematics::BandedMatrixSolve<Real>;

    static int GetStreamSize(const BandedMatrixSolve& value)
    {
        return value.GetStreamSize();
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Quaternion<Real>>
{
    using Quaternion = Mathematics::Quaternion<Real>;

    constexpr static int GetStreamSize([[maybe_unused]] const Quaternion& value) noexcept
    {
        return GetStreamSize();
    }

    constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * Quaternion::sm_EntrySize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::AQuaternion<Real>>
{
    using AQuaternion = Mathematics::AQuaternion<Real>;

    constexpr static int GetStreamSize([[maybe_unused]] const AQuaternion& value) noexcept
    {
        return GetStreamSize();
    }

    constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * AQuaternion::sm_EntrySize;
    }
};

template <>
struct CoreTools::StreamSize<Mathematics::Float1>
{
    constexpr static int GetStreamSize([[maybe_unused]] const Mathematics::Float1& value) noexcept
    {
        return StreamSize<float>::GetStreamSize();
    }
};

template <>
struct CoreTools::StreamSize<Mathematics::Float2>
{
    constexpr static int GetStreamSize([[maybe_unused]] const Mathematics::Float2& value) noexcept
    {
        return StreamSize<float>::GetStreamSize() * 2;
    }
};

template <>
struct CoreTools::StreamSize<Mathematics::Float3>
{
    constexpr static int GetStreamSize([[maybe_unused]] const Mathematics::Float3& value) noexcept
    {
        return StreamSize<float>::GetStreamSize() * 3;
    }
};

template <>
struct CoreTools::StreamSize<Mathematics::Float4>
{
    constexpr static int GetStreamSize([[maybe_unused]] const Mathematics::Float4& value) noexcept
    {
        return StreamSize<float>::GetStreamSize() * 4;
    }
};

namespace Mathematics
{
    template <typename T>
    int GetStreamSize(T value) noexcept(noexcept(CoreTools::StreamSize<T>::GetStreamSize(value)))
    {
        return CoreTools::StreamSize<T>::GetStreamSize(value);
    }
}

// MATHEMATICS_STREAM_SIZE宏被流系统使用。
#define MATHEMATICS_STREAM_SIZE(value) Mathematics::GetStreamSize(value)

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_STREAM_SIZE_H
