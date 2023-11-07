///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:35)

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
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "System/Helper/Tools.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Base/Float.h"

template <typename Real>
struct CoreTools::StreamSize<Mathematics::HomogeneousPoint<Real>>
{
    using HomogeneousPoint = Mathematics::HomogeneousPoint<Real>;

    NODISCARD constexpr static int GetStreamSize(const HomogeneousPoint& value) noexcept
    {
        System::UnusedFunction(value);

        return GetStreamSize();
    }

    NODISCARD constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * HomogeneousPoint::GetPointSize();
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Vector2<Real>>
{
    using Vector2 = Mathematics::Vector2<Real>;

    NODISCARD constexpr static int GetStreamSize(const Vector2& value) noexcept
    {
        System::UnusedFunction(value);

        return GetStreamSize();
    }

    NODISCARD constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * Vector2::pointSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Vector3<Real>>
{
    using Vector3 = Mathematics::Vector3<Real>;

    NODISCARD constexpr static int GetStreamSize(const Vector3& value) noexcept
    {
        System::UnusedFunction(value);

        return GetStreamSize();
    }

    NODISCARD constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * Vector3::pointSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Vector4<Real>>
{
    using Vector4 = Mathematics::Vector4<Real>;

    NODISCARD constexpr static int GetStreamSize(const Vector4& value) noexcept
    {
        System::UnusedFunction(value);

        return GetStreamSize();
    }

    NODISCARD constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * Vector4::pointSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::AVector<Real>>
{
    using AVector = Mathematics::AVector<Real>;

    NODISCARD constexpr static int GetStreamSize(const AVector& value) noexcept
    {
        System::UnusedFunction(value);

        return GetStreamSize();
    }

    NODISCARD constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * AVector::vectorSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::APoint<Real>>
{
    using APoint = Mathematics::APoint<Real>;

    NODISCARD constexpr static int GetStreamSize(const APoint& value) noexcept
    {
        System::UnusedFunction(value);

        return GetStreamSize();
    }

    NODISCARD constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * APoint::pointSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::VariableLengthVector<Real>>
{
    using VariableLengthVector = Mathematics::VariableLengthVector<Real>;

    NODISCARD static int GetStreamSize(const VariableLengthVector& value)
    {
        return StreamSize<Real>::GetStreamSize() * value.GetSize() + StreamSize<int32_t>::GetStreamSize();
    }

    NODISCARD static int GetStreamSize()
    {
        return GetStreamSize(VariableLengthVector{});
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Plane<Real>>
{
    using Plane = Mathematics::Plane<Real>;

    NODISCARD constexpr static int GetStreamSize(const Plane& value) noexcept
    {
        System::UnusedFunction(value);

        return GetStreamSize();
    }

    NODISCARD constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * (Plane::planeSize + 1);
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Polynomial<Real>>
{
    using Polynomial = Mathematics::Polynomial<Real>;

    NODISCARD static int GetStreamSize(const Polynomial& value)
    {
        return StreamSize<Real>::GetStreamSize() * (value.GetDegree() + 1) + StreamSize<int32_t>::GetStreamSize();
    }

    NODISCARD static int GetStreamSize()
    {
        return GetStreamSize(Polynomial{});
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Matrix2<Real>>
{
    using Matrix2 = Mathematics::Matrix2<Real>;

    NODISCARD constexpr static int GetStreamSize(const Matrix2& value)
    {
        System::UnusedFunction(value);

        return GetStreamSize();
    }

    NODISCARD constexpr static int GetStreamSize()
    {
        return StreamSize<Real>::GetStreamSize() * Matrix2::matrixSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Matrix3<Real>>
{
    using Matrix3 = Mathematics::Matrix3<Real>;

    NODISCARD constexpr static int GetStreamSize(const Matrix3& value)
    {
        System::UnusedFunction(value);

        return GetStreamSize();
    }

    NODISCARD constexpr static int GetStreamSize()
    {
        return StreamSize<Real>::GetStreamSize() * Matrix3::matrixSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Matrix4<Real>>
{
    using Matrix4 = Mathematics::Matrix4<Real>;

    NODISCARD constexpr static int GetStreamSize(const Matrix4& value)
    {
        System::UnusedFunction(value);

        return GetStreamSize();
    }

    NODISCARD constexpr static int GetStreamSize()
    {
        return StreamSize<Real>::GetStreamSize() * Matrix4::matrixSize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Matrix<Real>>
{
    using Matrix = Mathematics::Matrix<Real>;

    NODISCARD constexpr static int GetStreamSize(const Matrix& value) noexcept
    {
        System::UnusedFunction(value);

        return GetStreamSize();
    }

    NODISCARD constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * Matrix::entrySize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::VariableMatrix<Real>>
{
    using VariableMatrix = Mathematics::VariableMatrix<Real>;

    NODISCARD static int GetStreamSize(const VariableMatrix& value)
    {
        return StreamSize<Real>::GetStreamSize() * value.GetElementsNumber() + StreamSize<int32_t>::GetStreamSize() * 2;
    }

    NODISCARD static int GetStreamSize()
    {
        return GetStreamSize(VariableMatrix{});
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::BandedMatrix<Real>>
{
    using BandedMatrix = Mathematics::BandedMatrix<Real>;

    NODISCARD static int GetStreamSize(const BandedMatrix& value)
    {
        return value.GetStreamSize();
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::BandedMatrixSolve<Real>>
{
    using BandedMatrixSolve = Mathematics::BandedMatrixSolve<Real>;

    NODISCARD static int GetStreamSize(const BandedMatrixSolve& value)
    {
        return value.GetStreamSize();
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::Quaternion<Real>>
{
    using Quaternion = Mathematics::Quaternion<Real>;

    NODISCARD constexpr static int GetStreamSize(const Quaternion& value) noexcept
    {
        System::UnusedFunction(value);

        return GetStreamSize();
    }

    NODISCARD constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * Quaternion::entrySize;
    }
};

template <typename Real>
struct CoreTools::StreamSize<Mathematics::AQuaternion<Real>>
{
    using AQuaternion = Mathematics::AQuaternion<Real>;

    NODISCARD constexpr static int GetStreamSize(const AQuaternion& value) noexcept
    {
        System::UnusedFunction(value);

        return GetStreamSize();
    }

    NODISCARD constexpr static int GetStreamSize() noexcept
    {
        return StreamSize<Real>::GetStreamSize() * AQuaternion::entrySize;
    }
};

template <>
struct CoreTools::StreamSize<Mathematics::Float1>
{
    NODISCARD constexpr static int GetStreamSize(const Mathematics::Float1& value) noexcept
    {
        System::UnusedFunction(value);

        return StreamSize<float>::GetStreamSize() * Mathematics::Float1::tupleDimension;
    }
};

template <>
struct CoreTools::StreamSize<Mathematics::Float2>
{
    NODISCARD constexpr static int GetStreamSize(const Mathematics::Float2& value) noexcept
    {
        System::UnusedFunction(value);

        return StreamSize<float>::GetStreamSize() * Mathematics::Float2::tupleDimension;
    }
};

template <>
struct CoreTools::StreamSize<Mathematics::Float3>
{
    NODISCARD constexpr static int GetStreamSize(const Mathematics::Float3& value) noexcept
    {
        System::UnusedFunction(value);

        return StreamSize<float>::GetStreamSize() * Mathematics::Float3::tupleDimension;
    }
};

template <>
struct CoreTools::StreamSize<Mathematics::Float4>
{
    NODISCARD constexpr static int GetStreamSize(const Mathematics::Float4& value) noexcept
    {
        System::UnusedFunction(value);

        return StreamSize<float>::GetStreamSize() * Mathematics::Float4::tupleDimension;
    }
};

namespace Mathematics
{
    template <typename T>
    NODISCARD int GetStreamSize(T value = T{}) noexcept(noexcept(CoreTools::StreamSize<T>::GetStreamSize(value)))
    {
        return CoreTools::StreamSize<T>::GetStreamSize(value);
    }
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_STREAM_SIZE_H
