///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/09 9:52)

#ifndef MATHEMATICS_ALGEBRA_MATRIX4_H
#define MATHEMATICS_ALGEBRA_MATRIX4_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector4D.h"
#include "Flags/MatrixFlags.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/BaseFwd.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix4 final : private boost::additive<Matrix4<Real>, boost::multiplicative<Matrix4<Real>, Real>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Matrix4<Real>;
        using Vector4D = Vector4D<Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Vector4DTools = Vector4DTools<Real>;

        enum class VectorIndex
        {
            X = 0,
            Y,
            Z,
            W,
            Size
        };

        static constexpr auto sm_X = System::EnumCastUnderlying(VectorIndex::X);
        static constexpr auto sm_Y = System::EnumCastUnderlying(VectorIndex::Y);
        static constexpr auto sm_Z = System::EnumCastUnderlying(VectorIndex::Z);
        static constexpr auto sm_W = System::EnumCastUnderlying(VectorIndex::W);
        static constexpr auto sm_VectorSize = System::EnumCastUnderlying(VectorIndex::Size);
        static constexpr auto sm_MatrixSize = sm_VectorSize * Vector4D::sm_PointSize;
        using ArrayType = std::array<Real, sm_MatrixSize>;
        using ContainerType = std::vector<Real>;

    public:
        // 如果标志为MatrixFlagsZero，创建零矩阵，否则创建单位矩阵。
        explicit Matrix4(MatrixInitType flag = MatrixInitType::Zero) noexcept
            : m_X{ Create(flag, VectorIndex::X) }, m_Y{ Create(flag, VectorIndex::Y) },
              m_Z{ Create(flag, VectorIndex::Z) }, m_W{ Create(flag, VectorIndex::W) }
        {
        }

        // 输入矩阵在行r和列c
        Matrix4(Real member00, Real member01, Real member02, Real member03,
                Real member10, Real member11, Real member12, Real member13,
                Real member20, Real member21, Real member22, Real member23,
                Real member30, Real member31, Real member32, Real member33) noexcept
            : m_X{ member00, member01, member02, member03 },
              m_Y{ member10, member11, member12, member13 },
              m_Z{ member20, member21, member22, member23 },
              m_W{ member30, member31, member32, member33 }
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

        [[nodiscard]] const Vector4D& operator[](int row) const;
        [[nodiscard]] Vector4D& operator[](int row);
        [[nodiscard]] const Real& operator()(int row, int column) const;
        [[nodiscard]] Real& operator()(int row, int column);

        template <int Row, int Column>
        [[nodiscard]] Real GetValue() const noexcept;

        template <int Row, int Column>
        void SetValue(Real value) noexcept;

        [[nodiscard]] const Matrix4 operator-() const noexcept;
        Matrix4& operator+=(const Matrix4& rhs) noexcept;
        Matrix4& operator-=(const Matrix4& rhs) noexcept;
        Matrix4& operator*=(Real scalar) noexcept;
        Matrix4& operator/=(Real scalar) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // lhs^T * M * rhs
        [[nodiscard]] Real QuadraticForm(const Vector4D& lhs, const Vector4D& rhs) const noexcept;

        // M^T
        [[nodiscard]] const Matrix4 Transpose() const noexcept;

        // M * rhs
        Matrix4& operator*=(const Matrix4& rhs) noexcept;

        // 其它运算
        [[nodiscard]] const Matrix4 Inverse(const Real epsilon = Math::GetZeroTolerance()) const;
        [[nodiscard]] const Matrix4 Adjoint() const noexcept;
        [[nodiscard]] Real Determinant() const noexcept;

        // 投影矩阵到一个指定的平面
        // （包含“原点”和单位长度的“向量”）。
        void MakeObliqueProjection(const Vector3D& normal, const Vector3D& origin, const Vector3D& direction) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        void MakePerspectiveProjection(const Vector3D& normal, const Vector3D& origin, const Vector3D& eye);

        // 通过指定的平面反射矩阵。
        void MakeReflection(const Vector3D& normal, const Vector3D& origin) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        void MakeFrustumMatrix44(Real left, Real right, Real bottom, Real top, Real nearDistance, Real farDistance) noexcept;
        void MakePerspectiveMatrix44(Real fieldOfViewY, Real aspect, Real nearDistance, Real farDistance) noexcept;
        void MakeOrthoMatrix44(Real left, Real right, Real bottom, Real top, Real nearDistance, Real farDistance) noexcept;
        void MakeOrthoNormalMatrix44(const Vector3D& xDirection, const Vector3D& yDirection, const Vector3D& zDirection) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        [[nodiscard]] const ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate);

        // 特殊矩阵。
        [[nodiscard]] static constexpr Matrix4 GetZero()
        {
            return Matrix4{ MatrixInitType::Zero };
        }

        [[nodiscard]] static constexpr Matrix4 GetIdentity()
        {
            return Matrix4{ MatrixInitType::Identity };
        }

    private:
        [[nodiscard]] static constexpr Vector4D Create(MatrixInitType flag, VectorIndex vectorIndex)
        {
            if (flag == MatrixInitType::Zero)
            {
                return Vector4D{};
            }
            else if (vectorIndex == VectorIndex::X)
            {
                return Vector4D::GetUnitX();
            }
            else if (vectorIndex == VectorIndex::Y)
            {
                return Vector4D::GetUnitY();
            }
            else if (vectorIndex == VectorIndex::Z)
            {
                return Vector4D::GetUnitZ();
            }
            else
            {
                return Vector4D::GetUnitW();
            }
        }

        template <int Row>
        [[nodiscard]] const Vector4D& GetVector() const noexcept;

        template <int Row>
        [[nodiscard]] Vector4D& GetVector() noexcept;

        template <int Column>
        [[nodiscard]] typename Vector4D::GetCoordinateFunction GetVectorGetFunction() const noexcept;

        template <int Column>
        [[nodiscard]] typename Vector4D::SetCoordinateFunction GetVectorSetFunction() const noexcept;

    private:
        // 存储为行主序。
        Vector4D m_X;
        Vector4D m_Y;
        Vector4D m_Z;
        Vector4D m_W;
    };

    // M * vec
    template <typename Real>
    [[nodiscard]] const Vector4D<Real> operator*(const Matrix4<Real>& matrix, const Vector4D<Real>& vector) noexcept;
    // v^T * M
    template <typename Real>
    [[nodiscard]] const Vector4D<Real> operator*(const Vector4D<Real>& vector, const Matrix4<Real>& matrix) noexcept;

    // M * mat
    template <typename Real>
    [[nodiscard]] const Matrix4<Real> operator*(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs) noexcept;

    // M^T * mat
    template <typename Real>
    [[nodiscard]] const Matrix4<Real> TransposeTimes(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs) noexcept;

    // M * mat^T
    template <typename Real>
    [[nodiscard]] const Matrix4<Real> TimesTranspose(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs) noexcept;

    // M^T * mat^T
    template <typename Real>
    [[nodiscard]] const Matrix4<Real> TransposeTimesTranspose(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs) noexcept;

    template <typename Real>
    [[nodiscard]] bool Approximate(const Matrix4<Real>& lhs, const Matrix4<Real>& rhs, const Real epsilon = Math<Real>::GetZeroTolerance());

      // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Matrix4<Real>& matrix);

    using FloatMatrix4 = Matrix4<float>;
    using DoubleMatrix4 = Matrix4<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX4_H
