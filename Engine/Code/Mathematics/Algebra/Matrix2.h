///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/06 10:13)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_H
#define MATHEMATICS_ALGEBRA_MATRIX2_H

#include "Mathematics/MathematicsDll.h"

// 旋转矩阵的形式为
//   Real = cos(t) -sin(t)
//          sin(t)  cos(t)
// 当t > 0表示在xy平面上逆时针旋转。

#include "AlgebraFwd.h"
#include "Matrix2EigenDecomposition.h"
#include "Vector2D.h"
#include "Flags/MatrixFlags.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix2 final : private boost::additive<Matrix2<Real>, boost::multiplicative<Matrix2<Real>, Real>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Matrix2<Real>;
        using Vector2D = Vector2D<Real>;
        using Math = Math<Real>;
        using Matrix2EigenDecomposition = Matrix2EigenDecomposition<Real>;
        using Vector2DTools = Vector2DTools<Real>;

        enum class VectorIndex
        {
            X = 0,
            Y,
            Size
        };

        static constexpr auto sm_X = System::EnumCastUnderlying(VectorIndex::X);
        static constexpr auto sm_Y = System::EnumCastUnderlying(VectorIndex::Y);
        static constexpr auto sm_VectorSize = System::EnumCastUnderlying(VectorIndex::Size);
        static constexpr auto sm_MatrixSize = sm_VectorSize * Vector2D::sm_PointSize;
        using ArrayType = std::array<Real, sm_MatrixSize>;
        using ContainerType = std::vector<Real>;
        using Vector2DContainerType = std::vector<Vector2D>;

    public:
        // 如果标志为MatrixFlagsZero，创建零矩阵，否则创建单位矩阵。
        constexpr explicit Matrix2(MatrixInitType flag = MatrixInitType::Zero) noexcept
            : m_X{ Create(flag, VectorIndex::X) }, m_Y{ Create(flag, VectorIndex::Y) }
        {
        }

        // 输入矩阵在行r和列c
        constexpr Matrix2(Real member00, Real member01, Real member10, Real member11) noexcept
            : m_X{ member00, member01 }, m_Y{ member10, member11 }
        {
        }

        // 创建矩阵来自数组数字。
        // 输入数组是基于MatrixTypeFlags的输入的解释
        // MatrixTypeFlagsRow:  entry[0..3] = { m00,m01,m10,m11 }  [row major]
        // MatrixTypeFlagsColumn: entry[0..3] = { m00,m10,m01,m11 }  [column major]
        Matrix2(const ContainerType& entry, MatrixMajorFlags majorFlag);

        // 创建基于输入矢量的矩阵。MatrixMajorFlags解释为
        // MatrixTypeFlagsRow：向量是矩阵的行
        // MatrixTypeFlagsColumn：向量是矩阵的列
        Matrix2(const Vector2D& vector0, const Vector2D& vector1, MatrixMajorFlags majorFlag);
        explicit Matrix2(const Vector2DContainerType& vectors, MatrixMajorFlags majorFlag = MatrixMajorFlags::Column);

        // 创建一个对角矩阵, member01 = member10 = 0.
        constexpr Matrix2(Real member00, Real member11) noexcept
            : m_X{ member00, Math::GetValue(0) }, m_Y{ Math::GetValue(0), member11 }
        {
        }

        // 创建一个旋转矩阵（角度为正 ->逆时针方向）.
        explicit Matrix2(Real angle) noexcept;

        // 创建一个张量积 U * V^T
        Matrix2(const Vector2D& vector0, const Vector2D& vector1) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 创建各种矩阵。
        void MakeZero() noexcept;
        void MakeIdentity() noexcept;
        void MakeDiagonal(Real member00, Real member11) noexcept;
        void MakeRotation(Real angle) noexcept;
        void MakeTensorProduct(const Vector2D& lhs, const Vector2D& rhs) noexcept;

        [[nodiscard]] const Vector2D& operator[](int row) const;
        [[nodiscard]] Vector2D& operator[](int row);
        [[nodiscard]] const Real& operator()(int row, int column) const;
        [[nodiscard]] Real& operator()(int row, int column);

        template <int Row, int Column>
        [[nodiscard]] Real GetValue() const noexcept;

        template <int Row, int Column>
        void SetValue(Real value) noexcept;

        [[nodiscard]] const Matrix2 operator-() const noexcept;
        Matrix2& operator+=(const Matrix2& rhs) noexcept;
        Matrix2& operator-=(const Matrix2& rhs) noexcept;
        Matrix2& operator*=(Real scalar) noexcept;
        Matrix2& operator/=(Real scalar) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // lhs^T * M * rhs
        [[nodiscard]] Real QuadraticForm(const Vector2D& lhs, const Vector2D& rhs) const noexcept;

        // M^T
        [[nodiscard]] const Matrix2 Transpose() const noexcept;

        // M * rhs
        Matrix2& operator*=(const Matrix2& rhs) noexcept;

        // 其它运算
        [[nodiscard]] const Matrix2 Inverse(const Real epsilon = Math::GetZeroTolerance()) const;
        [[nodiscard]] const Matrix2 Adjoint() const noexcept;
        [[nodiscard]] Real Determinant() const noexcept;

        // 矩阵必须是一个旋转矩阵，下面函数才有效。
        // Orthonormalize函数使用Gram-Schmidt正交化施加到所述旋转矩阵。
        // 角度必须为弧度，而不是度数。
        [[nodiscard]] Real ExtractAngle() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void Orthonormalize();

        // 矩阵必须是对称矩阵。
        // 系数M = Real * D * Real^T ，其中Real = [u0|u1] 是一个列为u0和u1的旋转矩阵且
        // D = diag(d0,d1)是一个对角矩阵，这里对角线项为d0和d1。
        // 特征向量u[i]对应的特征向量d[i]。特征值排序为d0 <= d1。
        // 返回值的第一部分为rotation，第二部分为diagonal。
        [[nodiscard]] const Matrix2EigenDecomposition EigenDecomposition(const Real epsilon = Math::GetZeroTolerance()) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 特殊矩阵。
        [[nodiscard]] static constexpr Matrix2 GetZero()
        {
            return Matrix2{ MatrixInitType::Zero };
        }

        [[nodiscard]] static constexpr Matrix2 GetIdentity()
        {
            return Matrix2{ MatrixInitType::Identity };
        }

        [[nodiscard]] const ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate);

    private:
        [[nodiscard]] static constexpr Vector2D Create(MatrixInitType flag, VectorIndex vectorIndex)
        {
            if (flag == MatrixInitType::Zero)
            {
                return Vector2D{};
            }
            else if (vectorIndex == VectorIndex::X)
            {
                return Vector2D::GetUnitX();
            }
            else
            {
                return Vector2D::GetUnitY();
            }
        }

        template <int Row>
        [[nodiscard]] const Vector2D& GetVector() const noexcept;

        template <int Row>
        [[nodiscard]] Vector2D& GetVector() noexcept;

        template <int Column>
        [[nodiscard]] typename Vector2D::GetCoordinateFunction GetVectorGetFunction() const noexcept;

        template <int Column>
        [[nodiscard]] typename Vector2D::SetCoordinateFunction GetVectorSetFunction() const noexcept;

    private:
        // 存储为行主序。
        Vector2D m_X;
        Vector2D m_Y;
    };

    // mat * mat
    template <typename Real>
    [[nodiscard]] const Matrix2<Real> operator*(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept;

    // mat * vec
    template <typename Real>
    [[nodiscard]] const Vector2D<Real> operator*(const Matrix2<Real>& matrix, const Vector2D<Real>& vector) noexcept;

    // vec^T * mat
    template <typename Real>
    [[nodiscard]] const Vector2D<Real> operator*(const Vector2D<Real>& vector, const Matrix2<Real>& matrix) noexcept;

    // lhs^T * rhs
    template <typename Real>
    [[nodiscard]] const Matrix2<Real> TransposeTimes(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept;

    // lhs * rhs^T
    template <typename Real>
    [[nodiscard]] const Matrix2<Real> TimesTranspose(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept;

    // lhs^T * rhs^T
    template <typename Real>
    [[nodiscard]] const Matrix2<Real> TransposeTimesTranspose(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept;

    template <typename Real>
    [[nodiscard]] bool Approximate(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs, const Real epsilon = Math<Real>::GetZeroTolerance()) noexcept;

    using FloatMatrix2 = Matrix2<float>;
    using DoubleMatrix2 = Matrix2<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX2_H
