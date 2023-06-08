///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 16:52)

#ifndef MATHEMATICS_ALGEBRA_MATRIX4_H
#define MATHEMATICS_ALGEBRA_MATRIX4_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector4.h"
#include "Flags/MatrixFlags.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/BaseFwd.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix4 final : private boost::additive<Matrix4<Real>, boost::multiplicative<Matrix4<Real>, Real>>
    {
    public:
        using ClassType = Matrix4<Real>;

        using Vector4 = Vector4<Real>;
        using VectorIndex = typename Vector4::PointIndex;
        static constexpr auto xIndex = Vector4::xIndex;
        static constexpr auto yIndex = Vector4::yIndex;
        static constexpr auto zIndex = Vector4::zIndex;
        static constexpr auto wIndex = Vector4::wIndex;
        static constexpr auto vectorSize = System::EnumCastUnderlying(VectorIndex::Size);
        static constexpr auto matrixSize = vectorSize * Vector4::pointSize;

        using Math = Math<Real>;
        using Matrix3 = Matrix3<Real>;
        using Vector3 = Vector3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Vector4Tools = Vector4Tools<Real>;
        using ArrayType = std::array<Real, matrixSize>;
        using ContainerType = std::vector<Real>;

    public:
        // 如果标志为MatrixFlagsZero，创建零矩阵，否则创建单位矩阵。
        explicit Matrix4(MatrixInitType flag = MatrixInitType::Zero) noexcept
            : x{ Create(flag, VectorIndex::X) },
              y{ Create(flag, VectorIndex::Y) },
              z{ Create(flag, VectorIndex::Z) },
              w{ Create(flag, VectorIndex::W) }
        {
        }

        // 输入矩阵在行r和列c
        Matrix4(Real member00,
                Real member01,
                Real member02,
                Real member03,
                Real member10,
                Real member11,
                Real member12,
                Real member13,
                Real member20,
                Real member21,
                Real member22,
                Real member23,
                Real member30,
                Real member31,
                Real member32,
                Real member33) noexcept
            : x{ member00, member01, member02, member03 },
              y{ member10, member11, member12, member13 },
              z{ member20, member21, member22, member23 },
              w{ member30, member31, member32, member33 }
        {
        }

        // 创建矩阵来自数组数字。
        // 输入数组是基于MatrixTypeFlags的输入的解释
        // MatrixTypeFlagsRow:
        // entry[0..15]={ m00,m01,m02,m03,m10,m11,m12,m13,m20,m21,m22,m23,m30,m31,m32,m33 } [row major]
        // MatrixTypeFlagsColumn:
        // entry[0..15]={ m00,m10,m20,m30,m01,m11,m21,m31,m02,m12,m22,m32,m03,m13,m23,m33 } [col major]
        Matrix4(const ContainerType& entry, MatrixMajorFlags majorFlag);

        CLASS_INVARIANT_DECLARE;

        // 创建各种矩阵。
        void MakeZero() noexcept;
        void MakeIdentity() noexcept;

        NODISCARD const Vector4& operator[](int row) const;
        NODISCARD Vector4& operator[](int row);
        NODISCARD const Real& operator()(int row, int column) const;
        NODISCARD Real& operator()(int row, int column);

        template <int Row, int Column>
        NODISCARD Real GetValue() const noexcept;

        template <int Row, int Column>
        void SetValue(Real value) noexcept;

        NODISCARD Matrix4 operator-() const noexcept;
        Matrix4& operator+=(const Matrix4& rhs) noexcept;
        Matrix4& operator-=(const Matrix4& rhs) noexcept;
        Matrix4& operator*=(Real scalar) noexcept;
        Matrix4& operator/=(Real scalar) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // lhs^T * M * rhs
        NODISCARD Real QuadraticForm(const Vector4& lhs, const Vector4& rhs) const noexcept;

        // M^T
        NODISCARD Matrix4 Transpose() const noexcept;

        // M * rhs
        Matrix4& operator*=(const Matrix4& rhs) noexcept;

        // 其它运算
        NODISCARD Matrix4 Inverse(Real epsilon = Math::GetZeroTolerance()) const;
        NODISCARD Matrix4 Adjoint() const noexcept;
        NODISCARD Real Determinant() const noexcept;

        NODISCARD Matrix4 GaussianEliminationInverse(Real epsilon = Math::GetZeroTolerance()) const;
        NODISCARD Real GaussianEliminationDeterminant(Real epsilon = Math::GetZeroTolerance()) const;

        // 投影矩阵到一个指定的平面
        // （包含“原点”和单位长度的“向量”）。
        void MakeObliqueProjection(const Vector3& normal, const Vector3& origin, const Vector3& direction) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        void MakePerspectiveProjection(const Vector3& normal, const Vector3& origin, const Vector3& eye);

        // 通过指定的平面反射矩阵。
        void MakeReflection(const Vector3& normal, const Vector3& origin) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        void MakeFrustumMatrix44(Real left, Real right, Real bottom, Real top, Real nearDistance, Real farDistance) noexcept;
        void MakePerspectiveMatrix44(Real fieldOfViewY, Real aspect, Real nearDistance, Real farDistance) noexcept;
        void MakeOrthoMatrix44(Real left, Real right, Real bottom, Real top, Real nearDistance, Real farDistance) noexcept;
        void MakeOrthoNormalMatrix44(const Vector3& xDirection, const Vector3& yDirection, const Vector3& zDirection) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD const ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate);

        NODISCARD ContainerType GetContainer() const;

        // 特殊矩阵。
        NODISCARD static constexpr Matrix4 GetZero()
        {
            return Matrix4{ MatrixInitType::Zero };
        }

        NODISCARD static constexpr Matrix4 GetIdentity()
        {
            return Matrix4{ MatrixInitType::Identity };
        }

        NODISCARD Matrix3 Project() const;

        NODISCARD Real Trace() const noexcept;

    private:
        NODISCARD static constexpr Vector4 Create(MatrixInitType flag, VectorIndex vectorIndex)
        {
            if (flag == MatrixInitType::Zero)
            {
                return Vector4{};
            }
            else if (vectorIndex == VectorIndex::X)
            {
                return Vector4::GetUnitX();
            }
            else if (vectorIndex == VectorIndex::Y)
            {
                return Vector4::GetUnitY();
            }
            else if (vectorIndex == VectorIndex::Z)
            {
                return Vector4::GetUnitZ();
            }
            else
            {
                return Vector4::GetUnitW();
            }
        }

        template <int Row>
        NODISCARD const Vector4& GetVector() const noexcept;

        template <int Row>
        NODISCARD Vector4& GetVector() noexcept;

        template <int Column>
        NODISCARD typename Vector4::GetCoordinateFunction GetVectorGetFunction() const noexcept;

        template <int Column>
        NODISCARD typename Vector4::SetCoordinateFunction GetVectorSetFunction() const noexcept;

    private:
        // 存储为行主序。
        Vector4 x;
        Vector4 y;
        Vector4 z;
        Vector4 w;
    };

    // M * vec
    template <typename Real>
    NODISCARD Vector4<Real> operator*(const Matrix4<Real>& matrix, const Vector4<Real>& vector) noexcept;
    // v^T * M
    template <typename Real>
    NODISCARD Vector4<Real> operator*(const Vector4<Real>& vector, const Matrix4<Real>& matrix) noexcept;

    // M * mat
    template <typename Real>
    NODISCARD Matrix4<Real> operator*(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs) noexcept;

    // M^T * mat
    template <typename Real>
    NODISCARD Matrix4<Real> TransposeTimes(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs) noexcept;

    // M * mat^T
    template <typename Real>
    NODISCARD Matrix4<Real> TimesTranspose(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs) noexcept;

    // M^T * mat^T
    template <typename Real>
    NODISCARD Matrix4<Real> TransposeTimesTranspose(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD bool Approximate(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance());

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Matrix4<Real>& matrix);

    using Matrix4F = Matrix4<float>;
    using Matrix4D = Matrix4<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX4_H
