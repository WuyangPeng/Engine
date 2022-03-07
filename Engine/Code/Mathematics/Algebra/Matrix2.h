///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 16:06)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_H
#define MATHEMATICS_ALGEBRA_MATRIX2_H

#include "Mathematics/MathematicsDll.h"

// 旋转矩阵的形式为
//   Real = cos(t) -sin(t)
//          sin(t)  cos(t)
// 当t > 0表示在xy平面上逆时针旋转。

#include "AlgebraFwd.h"
#include "Matrix2EigenDecomposition.h"
#include "Vector2.h"
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
        using Vector2 = Vector2<Real>;
        using VectorIndex = typename Vector2::PointIndex;

        static constexpr auto xIndex = Vector2::xIndex;
        static constexpr auto yIndex = Vector2::yIndex;
        static constexpr auto vectorSize = Vector2::pointSize;
        static constexpr auto matrixSize = vectorSize * Vector2::pointSize;

        using Math = Math<Real>;
        using Matrix3 = Matrix3<Real>;
        using Matrix2EigenDecomposition = Matrix2EigenDecomposition<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using ContainerType = std::vector<Real>;
        using ArrayType = std::array<Real, matrixSize>;
        using Vector2ContainerType = std::vector<Vector2>;

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

        /// 创建矩阵来自数组数字。
        /// 输入数组是基于MatrixTypeFlags的输入的解释
        /// MatrixTypeFlagsRow:  entry[0..3] = { m00,m01,m10,m11 }  [row major]
        /// MatrixTypeFlagsColumn: entry[0..3] = { m00,m10,m01,m11 }  [column major]
        Matrix2(const ContainerType& entry, MatrixMajorFlags majorFlag);

        /// 创建基于输入矢量的矩阵。MatrixMajorFlags解释为
        /// MatrixTypeFlagsRow：向量是矩阵的行
        /// MatrixTypeFlagsColumn：向量是矩阵的列
        Matrix2(const Vector2& vector0, const Vector2& vector1, MatrixMajorFlags majorFlag);
        explicit Matrix2(const Vector2ContainerType& vectors, MatrixMajorFlags majorFlag = MatrixMajorFlags::Column);

        // 创建一个对角矩阵, member01 = member10 = 0.
        constexpr Matrix2(Real member00, Real member11) noexcept
            : m_X{ member00, Math::GetValue(0) }, m_Y{ Math::GetValue(0), member11 }
        {
        }

        // 创建一个旋转矩阵（角度为正 ->逆时针方向）.
        explicit Matrix2(Real angle) noexcept;

        // 创建一个张量积 U * V^T
        Matrix2(const Vector2& vector0, const Vector2& vector1) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 创建各种矩阵。
        void MakeZero() noexcept;
        void MakeIdentity() noexcept;
        void MakeDiagonal(Real member00, Real member11) noexcept;
        void MakeRotation(Real angle) noexcept;
        void MakeTensorProduct(const Vector2& lhs, const Vector2& rhs) noexcept;

        NODISCARD const Vector2& operator[](int row) const;
        NODISCARD Vector2& operator[](int row);
        NODISCARD const Real& operator()(int row, int column) const;
        NODISCARD Real& operator()(int row, int column);

        template <int Row, int Column>
        NODISCARD Real GetValue() const noexcept;

        template <int Row, int Column>
        void SetValue(Real value) noexcept;

        NODISCARD Matrix2 operator-() const noexcept;
        Matrix2& operator+=(const Matrix2& rhs) noexcept;
        Matrix2& operator-=(const Matrix2& rhs) noexcept;
        Matrix2& operator*=(Real scalar) noexcept;
        Matrix2& operator/=(Real scalar) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // lhs^T * M * rhs
        NODISCARD Real QuadraticForm(const Vector2& lhs, const Vector2& rhs) const noexcept;

        // M^T
        NODISCARD Matrix2 Transpose() const noexcept;

        // M * rhs
        Matrix2& operator*=(const Matrix2& rhs) noexcept;

        // 其它运算
        NODISCARD Matrix2 Inverse(const Real epsilon = Math::GetZeroTolerance()) const;
        NODISCARD Matrix2 Adjoint() const noexcept;
        NODISCARD Real Determinant() const noexcept;

        NODISCARD Matrix2 GaussianEliminationInverse(const Real epsilon = Math::GetZeroTolerance()) const;
        NODISCARD Real GaussianEliminationDeterminant(const Real epsilon = Math::GetZeroTolerance()) const;

        // 矩阵必须是一个旋转矩阵，下面函数才有效。
        // Orthonormalize函数使用Gram-Schmidt正交化施加到所述旋转矩阵。
        // 角度必须为弧度，而不是度数。
        NODISCARD Real ExtractAngle() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void Orthonormalize();

        // 矩阵必须是对称矩阵。
        // 系数M = Real * D * Real^T ，其中Real = [u0|u1] 是一个列为u0和u1的旋转矩阵且
        // D = diag(d0,d1)是一个对角矩阵，这里对角线项为d0和d1。
        // 特征向量u[i]对应的特征向量d[i]。特征值排序为d0 <= d1。
        // 返回值的第一部分为rotation，第二部分为diagonal。
        NODISCARD Matrix2EigenDecomposition EigenDecomposition(const Real epsilon = Math::GetZeroTolerance()) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 特殊矩阵。
        NODISCARD static constexpr Matrix2 GetZero()
        {
            return Matrix2{ MatrixInitType::Zero };
        }

        NODISCARD static constexpr Matrix2 GetIdentity()
        {
            return Matrix2{ MatrixInitType::Identity };
        }

        NODISCARD ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate);

        NODISCARD ContainerType GetContainer() const;

        NODISCARD Matrix3 Lift() const;
        NODISCARD Real Trace() const noexcept;

    private:
        NODISCARD static constexpr Vector2 Create(MatrixInitType flag, VectorIndex vectorIndex)
        {
            if (flag == MatrixInitType::Zero)
            {
                return Vector2{};
            }
            else if (vectorIndex == VectorIndex::X)
            {
                return Vector2::GetUnitX();
            }
            else
            {
                return Vector2::GetUnitY();
            }
        }

        template <int Row>
        NODISCARD const Vector2& GetVector() const noexcept;

        template <int Row>
        NODISCARD Vector2& GetVector() noexcept;

        template <int Column>
        NODISCARD typename Vector2::GetCoordinateFunction GetVectorGetFunction() const noexcept;

        template <int Column>
        NODISCARD typename Vector2::SetCoordinateFunction GetVectorSetFunction() const noexcept;

    private:
        // 存储为行主序。
        Vector2 m_X;
        Vector2 m_Y;
    };

    // mat * mat
    template <typename Real>
    NODISCARD Matrix2<Real> operator*(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept;

    // mat * vec
    template <typename Real>
    NODISCARD Vector2<Real> operator*(const Matrix2<Real>& matrix, const Vector2<Real>& vector) noexcept;

    // vec^T * mat
    template <typename Real>
    NODISCARD Vector2<Real> operator*(const Vector2<Real>& vector, const Matrix2<Real>& matrix) noexcept;

    // lhs^T * rhs
    template <typename Real>
    NODISCARD Matrix2<Real> TransposeTimes(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept;

    // lhs * rhs^T
    template <typename Real>
    NODISCARD Matrix2<Real> TimesTranspose(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept;

    // lhs^T * rhs^T
    template <typename Real>
    NODISCARD Matrix2<Real> TransposeTimesTranspose(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD bool Approximate(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs, const Real epsilon = Math<Real>::GetZeroTolerance()) noexcept;

    using Matrix2F = Matrix2<float>;
    using Matrix2D = Matrix2<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX2_H
