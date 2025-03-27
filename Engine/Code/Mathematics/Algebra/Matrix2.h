///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 14:44)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_H
#define MATHEMATICS_ALGEBRA_MATRIX2_H

#include "Mathematics/MathematicsDll.h"

// ��ת�������ʽΪ
//   Real = cos(t) -sin(t)
//          sin(t)  cos(t)
// ��t > 0��ʾ��xyƽ������ʱ����ת��

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
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix2 final : private boost::additive<Matrix2<Real>, boost::multiplicative<Matrix2<Real>, Real>>
    {
    public:
        using ClassType = Matrix2<Real>;

        using Vector2Type = Vector2<Real>;
        using VectorIndex = typename Vector2Type::PointIndex;

        static constexpr auto xIndex = Vector2Type::xIndex;
        static constexpr auto yIndex = Vector2Type::yIndex;
        static constexpr auto vectorSize = Vector2Type::pointSize;
        static constexpr auto matrixSize = vectorSize * Vector2Type::pointSize;

        using MathType = Math<Real>;
        using Matrix3Type = Matrix3<Real>;
        using Matrix2EigenDecompositionType = Matrix2EigenDecomposition<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;
        using ContainerType = std::vector<Real>;
        using ArrayType = std::array<Real, matrixSize>;
        using Vector2ContainerType = std::vector<Vector2Type>;

    public:
        // �����־ΪMatrixFlagsZero����������󣬷��򴴽���λ����
        constexpr explicit Matrix2(MatrixInitType flag = MatrixInitType::Zero) noexcept
            : x{ Create(flag, VectorIndex::X) }, y{ Create(flag, VectorIndex::Y) }
        {
        }

        // �����������r����c
        constexpr Matrix2(Real member00, Real member01, Real member10, Real member11) noexcept
            : x{ member00, member01 }, y{ member10, member11 }
        {
        }

        /// �������������������֡�
        /// ���������ǻ���MatrixTypeFlags������Ľ���
        /// MatrixTypeFlagsRow:  entry[0..3] = { m00,m01,m10,m11 }  [row major]
        /// MatrixTypeFlagsColumn: entry[0..3] = { m00,m10,m01,m11 }  [column major]
        Matrix2(const ContainerType& entry, MatrixMajorFlags majorFlag);

        /// ������������ʸ���ľ���MatrixMajorFlags����Ϊ
        /// MatrixTypeFlagsRow�������Ǿ������
        /// MatrixTypeFlagsColumn�������Ǿ������
        Matrix2(const Vector2Type& vector0, const Vector2Type& vector1, MatrixMajorFlags majorFlag);
        explicit Matrix2(const Vector2ContainerType& vectors, MatrixMajorFlags majorFlag = MatrixMajorFlags::Column);

        // ����һ���ԽǾ���, member01 = member10 = 0.
        constexpr Matrix2(Real member00, Real member11) noexcept
            : x{ member00, MathType::GetValue(0) }, y{ MathType::GetValue(0), member11 }
        {
        }

        // ����һ����ת���󣨽Ƕ�Ϊ�� ->��ʱ�뷽��.
        explicit Matrix2(Real angle) noexcept;

        // ����һ�������� U * V^T
        Matrix2(const Vector2Type& vector0, const Vector2Type& vector1) noexcept;

        CLASS_INVARIANT_DECLARE;

        // �������־���
        void MakeZero() noexcept;
        void MakeIdentity() noexcept;
        void MakeDiagonal(Real member00, Real member11) noexcept;
        void MakeRotation(Real angle) noexcept;
        void MakeTensorProduct(const Vector2Type& lhs, const Vector2Type& rhs) noexcept;

        NODISCARD const Vector2Type& operator[](int row) const;
        NODISCARD Vector2Type& operator[](int row);
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
        Matrix2& operator/=(Real scalar) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // lhs^T * M * rhs
        NODISCARD Real QuadraticForm(const Vector2Type& lhs, const Vector2Type& rhs) const noexcept;

        // M^T
        NODISCARD Matrix2 Transpose() const noexcept;

        // M * rhs
        Matrix2& operator*=(const Matrix2& rhs) noexcept;

        // ��������
        NODISCARD Matrix2 Inverse(Real epsilon = MathType::GetZeroTolerance()) const;
        NODISCARD Matrix2 Adjoint() const noexcept;
        NODISCARD Real Determinant() const noexcept;

        NODISCARD Matrix2 GaussianEliminationInverse(Real epsilon = MathType::GetZeroTolerance()) const;
        NODISCARD Real GaussianEliminationDeterminant(Real epsilon = MathType::GetZeroTolerance()) const;

        // ���������һ����ת�������溯������Ч��
        // Orthonormalize����ʹ��Gram-Schmidt������ʩ�ӵ�������ת����
        // �Ƕȱ���Ϊ���ȣ������Ƕ�����
        NODISCARD Real ExtractAngle() const noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void Orthonormalize();

        // ��������ǶԳƾ���
        // ϵ��M = Real * D * Real^T ������Real = [u0|u1] ��һ����Ϊu0��u1����ת������
        // D = diag(d0,d1)��һ���ԽǾ�������Խ�����Ϊd0��d1��
        // ��������u[i]��Ӧ����������d[i]������ֵ����Ϊd0 <= d1��
        // ����ֵ�ĵ�һ����Ϊrotation���ڶ�����Ϊdiagonal��
        NODISCARD Matrix2EigenDecompositionType EigenDecomposition(Real epsilon = MathType::GetZeroTolerance()) const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // �������
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

        NODISCARD Matrix3Type Lift() const;
        NODISCARD Real Trace() const noexcept;

    private:
        NODISCARD static constexpr Vector2Type Create(MatrixInitType flag, VectorIndex vectorIndex)
        {
            if (flag == MatrixInitType::Zero)
            {
                return Vector2Type{};
            }
            else if (vectorIndex == VectorIndex::X)
            {
                return Vector2Type::GetUnitX();
            }
            else
            {
                return Vector2Type::GetUnitY();
            }
        }

        template <int Row>
        NODISCARD const Vector2Type& GetVector() const noexcept;

        template <int Row>
        NODISCARD Vector2Type& GetVector() noexcept;

        template <int Column>
        NODISCARD typename Vector2Type::GetCoordinateFunction GetVectorGetFunction() const noexcept;

        template <int Column>
        NODISCARD typename Vector2Type::SetCoordinateFunction GetVectorSetFunction() const noexcept;

    private:
        // �洢Ϊ������
        Vector2Type x;
        Vector2Type y;
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
    NODISCARD bool Approximate(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance()) noexcept;

    using Matrix2F = Matrix2<float>;
    using Matrix2D = Matrix2<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX2_H
