//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.1 (2020/09/03 14:25)

#ifndef MATHEMATICS_ALGEBRA_MATRIX_H
#define MATHEMATICS_ALGEBRA_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "APoint.h"
#include "AVector.h"
#include "HomogeneousPoint.h"
#include "Matrix3.h"
#include "Vector4D.h"
#include "Flags/MatrixFlags.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <array>
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Matrix : private boost::additive<Matrix<Real>, boost::multiplicative<Matrix<Real>, Real, boost::totally_ordered<Matrix<Real>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Matrix<Real>;
        using Math = Math<Real>;
        using APoint = APoint<Real>;
        using AVector = AVector<Real>;
        using Matrix3 = Matrix3<Real>;
        using Vector4D = Vector4D<Real>;
        using HomogeneousPoint = HomogeneousPoint<Real>;

        constexpr static auto sm_RowSize = 4;
        constexpr static auto sm_ColumnSize = 4;
        constexpr static auto sm_EntrySize = sm_RowSize * sm_ColumnSize;

        using ContainerType = std::vector<Real>;
        using EntryType = std::array<Real, sm_EntrySize>;
        using EntryTypeConstIter = typename EntryType::const_iterator;

    public:
        // �����־ΪMatrixFlagsZero����������󣬷��򴴽���λ����
        explicit constexpr Matrix(MatrixInitType flag = MatrixInitType::Zero) noexcept
            : m_Entry{ Create(flag) }
        {
        }

        // �����������r����c
        constexpr Matrix(Real member00, Real member01, Real member02, Real member03,
                         Real member10, Real member11, Real member12, Real member13,
                         Real member20, Real member21, Real member22, Real member23,
                         Real member30, Real member31, Real member32, Real member33) noexcept
            : m_Entry{ Create(member00, member01, member02, member03,
                              member10, member11, member12, member13,
                              member20, member21, member22, member23,
                              member30, member31, member32, member33,
                              MatrixMajorFlags::Row) }
        {
        }

        // ����һ���ԽǾ���,
        constexpr Matrix(Real member00, Real member11, Real member22) noexcept
            : m_Entry{ Create(member00, Math::GetValue(0), Math::GetValue(0), Math::GetValue(0),
                              Math::GetValue(0), member11, Math::GetValue(0), Math::GetValue(0),
                              Math::GetValue(0), Math::GetValue(0), member22, Math::GetValue(0),
                              Math::GetValue(0), Math::GetValue(0), Math::GetValue(0), Math::GetValue(1),
                              MatrixMajorFlags::Row) }
        {
        }

        explicit Matrix(const Matrix3& rhs);

        // �������������������֡�
        // ���������ǻ���MatrixTypeFlags������Ľ���
        // MatrixTypeFlagsRow:
        // entry[0..15] = { m00,m01,m02,m03,m10,m11,m12,m13,m20,m21,m22,m23,m30,m31,m32,m33 } [row major]
        // MatrixTypeFlagsColumn:
        // entry[0..15] = { m00,m10,m20,m30,m01,m11,m21,m31,m02,m12,m22,m32,m03,m13,m23,m33 } [col major]
        Matrix(const ContainerType& entry, MatrixMajorFlags majorFlag);

        // ������������ʸ���ľ���MatrixMajorFlags����Ϊ
        // MatrixTypeFlagsRow�������Ǿ������
        // MatrixTypeFlagsColumn�������Ǿ������
        Matrix(const Vector4D& vector0, const Vector4D& vector1, const Vector4D& vector2, const Vector4D& vector3, MatrixMajorFlags majorFlag);
        Matrix(const AVector& vector0, const AVector& vector1, const AVector& vector2, const APoint& point, MatrixMajorFlags majorFlag);

        // ����һ����ת���󣨽Ƕ�Ϊ��->��ʱ�뷽�򣩡�angle����Ϊ���ȣ����ǽǶȡ�
        Matrix(const AVector& axis, Real angle);

        Matrix& operator=(const Matrix3& rhs);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] EntryTypeConstIter begin() const noexcept;
        [[nodiscard]] EntryTypeConstIter end() const noexcept;

        // Matrix����3x3�Ŀ鸴�Ƶ�Matrix3����
        [[nodiscard]] const Matrix3 GetMatrix3() const noexcept;

        // �������
        [[nodiscard]] EntryType GetData() const noexcept;
        [[nodiscard]] const Real& operator()(int row, int column) const;
        [[nodiscard]] Real& operator()(int row, int column);
        void SetRow(int row, const HomogeneousPoint& point);
        [[nodiscard]] const HomogeneousPoint GetRow(int row) const;
        void SetColumn(int column, const HomogeneousPoint& point);
        [[nodiscard]] const HomogeneousPoint GetColumn(int column) const;

        template <int Index>
        [[nodiscard]] constexpr Real GetValue() const noexcept
        {
            static_assert(0 <= Index && Index < sm_EntrySize);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            return m_Entry[Index];
#include STSTEM_WARNING_POP
        }

        template <int Index>
        constexpr void SetValue(Real value) noexcept
        {
            static_assert(0 <= Index && Index < sm_EntrySize);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            m_Entry[Index] = value;
#include STSTEM_WARNING_POP
        }

        template <int Index>
        constexpr void Plus(Real value) noexcept
        {
            static_assert(0 <= Index && Index < sm_EntrySize);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            m_Entry[Index] += value;
#include STSTEM_WARNING_POP
        }

        template <int Index>
        constexpr void Minus(Real value) noexcept
        {
            static_assert(0 <= Index && Index < sm_EntrySize);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            m_Entry[Index] -= value;
#include STSTEM_WARNING_POP
        }

        template <int Index>
        constexpr void Multiply(Real value) noexcept
        {
            static_assert(0 <= Index && Index < sm_EntrySize);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            m_Entry[Index] *= value;
#include STSTEM_WARNING_POP
        }

        template <int Index>
        constexpr void Divide(Real value) noexcept
        {
            static_assert(0 <= Index && Index < sm_EntrySize);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            m_Entry[Index] /= value;
#include STSTEM_WARNING_POP
        }

        // ����洢Ϊ�����򡣽����Ǵ洢��ָ����������������У���������16��Ԫ�ء�
        [[nodiscard]] const ContainerType GetColumnMajor() const;

        // ��������
        const Matrix operator-() const noexcept;
        Matrix& operator+=(const Matrix& rhs);
        Matrix& operator-=(const Matrix& rhs);
        Matrix& operator*=(Real scalar) noexcept;
        Matrix& operator/=(Real scalar);

        // �������
        void MakeZero();  // Z
        void MakeIdentity() noexcept;  // I
        void MakeDiagonal(Real member00, Real member11, Real member22) noexcept;  // D
        void MakeRotation(const AVector& axis, Real angle);  // Real

        [[nodiscard]] const Matrix Transpose() const noexcept;  // M^T
        [[nodiscard]] const Matrix Adjoint() const noexcept;  // M^{adj}
        [[nodiscard]] const Matrix Inverse(const Real epsilon = Math::GetZeroTolerance()) const;  // M^{-1}
        [[nodiscard]] const Matrix Invert3x3(const Real epsilon = Math::GetZeroTolerance()) const;

        [[nodiscard]] Real Determinant() const noexcept;  // det(M)

        Matrix& operator*=(const Matrix& rhs) noexcept;

        // ֻ�����Ͻ�3x3�����������
        [[nodiscard]] const Matrix TimesDiagonal(const APoint& diagonal) const noexcept;  // M * D
        [[nodiscard]] const Matrix DiagonalTimes(const APoint& diagonal) const noexcept;  // D * M

        // ����������3x3�Ŀ�
        void Orthonormalize() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // ����һ�������͡�
        // p0^T * M * p1
        [[nodiscard]] Real QuadraticForm(const HomogeneousPoint& point0, const HomogeneousPoint& point1) const noexcept;

        // ͶӰ����һ��ָ����ƽ�棬���ƽ�������ԭ�㡱�͵�λ���ȵġ���������
        void MakeObliqueProjection(const APoint& origin, const AVector& normal, const AVector& direction);

        // ����͸��ͶӰ����ָ����ƽ���ϣ����ƽ����һ����origin���͵�λ���ȵġ�normal������eye����ͶӰ��ԭ�㡣
        void MakePerspectiveProjection(const APoint& origin, const AVector& normal, const APoint& eye);

        // �������һ��ָ����ƽ�棬���ƽ�������ԭ�㡱�͵�λ���ȵġ���������
        void MakeReflection(const APoint& origin, const AVector& normal);

        [[nodiscard]] Real GetNorm() const noexcept;

    private:
        [[nodiscard]] static constexpr EntryType Create(Real member00, Real member01, Real member02, Real member03,
                                                        Real member10, Real member11, Real member12, Real member13,
                                                        Real member20, Real member21, Real member22, Real member23,
                                                        Real member30, Real member31, Real member32, Real member33,
                                                        MatrixMajorFlags majorFlag)
        {
            if (majorFlag == MatrixMajorFlags::Row)
            {
                return EntryType{ member00, member01, member02, member03,
                                  member10, member11, member12, member13,
                                  member20, member21, member22, member23,
                                  member30, member31, member32, member33 };
            }
            else
            {
                return EntryType{ member00, member10, member20, member30,
                                  member01, member11, member21, member31,
                                  member02, member12, member22, member32,
                                  member03, member13, member23, member33 };
            }
        }

        [[nodiscard]] static constexpr EntryType Create(MatrixInitType flag)
        {
            if (flag == MatrixInitType::Zero)
            {
                return EntryType{};
            }
            else
            {
                return EntryType{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0),
                                  Math::GetValue(0), Math::GetValue(1), Math::GetValue(0), Math::GetValue(0),
                                  Math::GetValue(0), Math::GetValue(0), Math::GetValue(1), Math::GetValue(0),
                                  Math::GetValue(0), Math::GetValue(0), Math::GetValue(0), Math::GetValue(1) };
            }
        }

        [[nodiscard]] static EntryType Create(const ContainerType& entry, MatrixMajorFlags majorFlag);

    private:
        // ����洢Ϊ������
        EntryType m_Entry{};
    };

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Matrix<Real>& matrix);

    // �Ƚϣ���ʹ����STL������
    template <typename Real>
    [[nodiscard]] bool operator==(const Matrix<Real>& lhs, const Matrix<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool operator<(const Matrix<Real>& lhs, const Matrix<Real>& rhs);

    template <typename Real>
    [[nodiscard]] const Matrix<Real> operator*(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept;  // M * mat

    template <typename Real>
    [[nodiscard]] const Matrix<Real> TransposeTimes(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept;  // M^T * mat

    template <typename Real>
    [[nodiscard]] const Matrix<Real> TimesTranspose(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept;  // M * mat^T

    template <typename Real>
    [[nodiscard]] const Matrix<Real> TransposeTimesTranspose(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept;  // M^T * mat^T

    // �������ε�֮������㡣M��pΪ��ζ���M������Ҫ���Ƿ���ģ�pҲ��Ҫ����w = 1����
    // M * p
    template <typename Real>
    [[nodiscard]] const HomogeneousPoint<Real> operator*(const Matrix<Real>& matrix, const HomogeneousPoint<Real>& point) noexcept;

    // p * M
    template <typename Real>
    [[nodiscard]] const HomogeneousPoint<Real> operator*(const HomogeneousPoint<Real>& point, const Matrix<Real>& matrix) noexcept;

    // M * p[0], ..., M * p[n-1]
    template <typename Real>
    [[nodiscard]] const typename HomogeneousPoint<Real>::ContainerType BatchMultiply(const Matrix<Real>& matrix, const typename HomogeneousPoint<Real>::ContainerType& inputPoints);

    // �������ͷ����֮��Ĳ�����
    // M * p
    template <typename Real>
    [[nodiscard]] const APoint<Real> operator*(const Matrix<Real>& matrix, const APoint<Real>& point) noexcept;

    // M * p[0], ..., M * p[n-1]
    template <typename Real>
    [[nodiscard]] const typename APoint<Real>::ContainerType BatchMultiply(const Matrix<Real>& matrix, const typename APoint<Real>::ContainerType& inputPoints);

    // �������ͷ�������֮��Ĳ�����
    // M * v
    template <typename Real>
    [[nodiscard]] const AVector<Real> operator*(const Matrix<Real>& matrix, const AVector<Real>& point) noexcept;

    // M * v[0], ..., M * v[n-1]
    template <typename Real>
    [[nodiscard]] const typename AVector<Real>::ContainerType BatchMultiply(const Matrix<Real>& matrix, const typename AVector<Real>::ContainerType& inputPoints);

    template <typename Real>
    [[nodiscard]] bool Approximate(const Matrix<Real>& lhs, const Matrix<Real>& rhs, const Real epsilon = Math<Real>::GetZeroTolerance());

    using FloatMatrix = Matrix<float>;
    using DoubleMatrix = Matrix<double>;

    // �������
    namespace Float
    {
        constexpr FloatMatrix g_ZeroMatrix{};
        constexpr FloatMatrix g_IdentityMatrix{ MatrixInitType::Identity };
    }

    namespace Double
    {
        constexpr DoubleMatrix g_ZeroMatrix{};
        constexpr DoubleMatrix g_IdentityMatrix{ MatrixInitType::Identity };
    }
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX_H
