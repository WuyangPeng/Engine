///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/31 16:00)

#ifndef MATHEMATICS_ALGEBRA_MATRIX_H
#define MATHEMATICS_ALGEBRA_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "APoint.h"
#include "AVector.h"
#include "HomogeneousPoint.h"
#include "Matrix3.h"
#include "Vector4.h"
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
    requires std::is_arithmetic_v<Real>
    class Matrix final : private boost::additive<Matrix<Real>, boost::multiplicative<Matrix<Real>, Real, boost::totally_ordered<Matrix<Real>>>>
    {
    public:
        using ClassType = Matrix<Real>;

        using Math = Math<Real>;
        using APoint = APoint<Real>;
        using AVector = AVector<Real>;
        using Matrix3 = Matrix3<Real>;
        using Vector4 = Vector4<Real>;
        using HomogeneousPoint = HomogeneousPoint<Real>;

        constexpr static auto rowSize = HomogeneousPoint::pointSize;
        constexpr static auto columnSize = HomogeneousPoint::pointSize;
        constexpr static auto entrySize = rowSize * columnSize;

        using ContainerType = std::vector<Real>;
        using EntryType = std::array<Real, entrySize>;
        using EntryTypeConstIter = typename EntryType::const_iterator;

    public:
        // �����־ΪMatrixFlagsZero����������󣬷��򴴽���λ����
        explicit constexpr Matrix(const MatrixInitType flag = MatrixInitType::Zero) noexcept
            : entry{ Create(flag) }
        {
        }

        // �����������r����c
        constexpr Matrix(Real member00,
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
            : entry{ Create(member00,
                            member01,
                            member02,
                            member03,
                            member10,
                            member11,
                            member12,
                            member13,
                            member20,
                            member21,
                            member22,
                            member23,
                            member30,
                            member31,
                            member32,
                            member33,
                            MatrixMajorFlags::Row) }
        {
        }

        // ����һ���ԽǾ���,
        constexpr Matrix(Real member00, Real member11, Real member22) noexcept
            : entry{ Create(member00,
                            Math::GetValue(0),
                            Math::GetValue(0),
                            Math::GetValue(0),
                            Math::GetValue(0),
                            member11,
                            Math::GetValue(0),
                            Math::GetValue(0),
                            Math::GetValue(0),
                            Math::GetValue(0),
                            member22,
                            Math::GetValue(0),
                            Math::GetValue(0),
                            Math::GetValue(0),
                            Math::GetValue(0),
                            Math::GetValue(1),
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
        Matrix(const Vector4& vector0, const Vector4& vector1, const Vector4& vector2, const Vector4& vector3, MatrixMajorFlags majorFlag);
        Matrix(const AVector& vector0, const AVector& vector1, const AVector& vector2, const APoint& point, MatrixMajorFlags majorFlag);

        // ����һ����ת���󣨽Ƕ�Ϊ��->��ʱ�뷽�򣩡�angle����Ϊ���ȣ����ǽǶȡ�
        Matrix(const AVector& axis, Real angle);

        Matrix& operator=(const Matrix3& rhs);

        CLASS_INVARIANT_DECLARE;

        NODISCARD EntryTypeConstIter begin() const noexcept;
        NODISCARD EntryTypeConstIter end() const noexcept;

        // Matrix����3x3�Ŀ鸴�Ƶ�Matrix3����
        NODISCARD Matrix3 GetMatrix3() const noexcept;

        // �������
        NODISCARD EntryType GetData() const noexcept;
        NODISCARD const Real& operator()(int row, int column) const;
        NODISCARD Real& operator()(int row, int column);
        void SetRow(int row, const HomogeneousPoint& point);
        NODISCARD HomogeneousPoint GetRow(int row) const;
        void SetColumn(int column, const HomogeneousPoint& point);
        NODISCARD HomogeneousPoint GetColumn(int column) const;

        template <int Index>
        NODISCARD constexpr Real GetValue() const noexcept
        {
            static_assert(0 <= Index && Index < entrySize);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            return entry[Index];

#include SYSTEM_WARNING_POP
        }

        template <int Index>
        constexpr void SetValue(Real value) noexcept
        {
            static_assert(0 <= Index && Index < entrySize);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            entry[Index] = value;

#include SYSTEM_WARNING_POP
        }

        template <int Index>
        constexpr void Plus(Real value) noexcept
        {
            static_assert(0 <= Index && Index < entrySize);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            entry[Index] += value;

#include SYSTEM_WARNING_POP
        }

        template <int Index>
        constexpr void Minus(Real value) noexcept
        {
            static_assert(0 <= Index && Index < entrySize);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            entry[Index] -= value;

#include SYSTEM_WARNING_POP
        }

        template <int Index>
        constexpr void Multiply(Real value) noexcept
        {
            static_assert(0 <= Index && Index < entrySize);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            entry[Index] *= value;

#include SYSTEM_WARNING_POP
        }

        template <int Index>
        void Divide(Real value);

        // ����洢Ϊ�����򡣽����Ǵ洢��ָ����������������У���������16��Ԫ�ء�
        NODISCARD ContainerType GetColumnMajor() const;

        NODISCARD EntryType GetRowMajor() const noexcept;
        void Set(const EntryType& rowMajor) noexcept;

        // ��������
        NODISCARD Matrix operator-() const noexcept;
        Matrix& operator+=(const Matrix& rhs) noexcept;
        Matrix& operator-=(const Matrix& rhs) noexcept;
        Matrix& operator*=(Real scalar) noexcept;
        Matrix& operator/=(Real scalar);

        // �������
        void MakeZero();  // Z
        void MakeIdentity() noexcept;  // I
        void MakeDiagonal(Real member00, Real member11, Real member22) noexcept;  // D
        void MakeRotation(const AVector& axis, Real angle);  // Real

        NODISCARD Matrix Transpose() const noexcept;  // M^T
        NODISCARD Matrix Adjoint() const noexcept;  // M^{adj}
        NODISCARD Matrix Inverse(const Real epsilon = Math::GetZeroTolerance()) const;  // M^{-1}
        NODISCARD Matrix Invert3x3(const Real epsilon = Math::GetZeroTolerance()) const;

        NODISCARD Real Determinant() const noexcept;  // det(M)

        Matrix& operator*=(const Matrix& rhs) noexcept;

        // ֻ�����Ͻ�3x3�����������
        NODISCARD Matrix TimesDiagonal(const APoint& diagonal) const noexcept;  // M * D
        NODISCARD Matrix DiagonalTimes(const APoint& diagonal) const noexcept;  // D * M

        // ����������3x3�Ŀ�
        void Orthonormalize() noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // ����һ�������͡�
        // p0^T * M * p1
        NODISCARD Real QuadraticForm(const HomogeneousPoint& point0, const HomogeneousPoint& point1) const noexcept;

        // ͶӰ����һ��ָ����ƽ�棬���ƽ�������ԭ�㡱�͵�λ���ȵġ���������
        void MakeObliqueProjection(const APoint& origin, const AVector& normal, const AVector& direction);

        // ����͸��ͶӰ����ָ����ƽ���ϣ����ƽ����һ����origin���͵�λ���ȵġ�normal������eye����ͶӰ��ԭ�㡣
        void MakePerspectiveProjection(const APoint& origin, const AVector& normal, const APoint& eye);

        // �������һ��ָ����ƽ�棬���ƽ�������ԭ�㡱�͵�λ���ȵġ���������
        void MakeReflection(const APoint& origin, const AVector& normal);

        NODISCARD Real GetNorm() const noexcept;

        // �������

        static constexpr Matrix GetZeroMatrix()
        {
            return Matrix{};
        }

        static constexpr Matrix GetIdentityMatrix()
        {
            return Matrix{ MatrixInitType::Identity };
        }

    private:
        NODISCARD static constexpr EntryType Create(Real member00,
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
                                                    Real member33,
                                                    MatrixMajorFlags majorFlag)
        {
            if (majorFlag == MatrixMajorFlags::Row)
            {
                return EntryType{ member00,
                                  member01,
                                  member02,
                                  member03,
                                  member10,
                                  member11,
                                  member12,
                                  member13,
                                  member20,
                                  member21,
                                  member22,
                                  member23,
                                  member30,
                                  member31,
                                  member32,
                                  member33 };
            }
            else
            {
                return EntryType{ member00,
                                  member10,
                                  member20,
                                  member30,
                                  member01,
                                  member11,
                                  member21,
                                  member31,
                                  member02,
                                  member12,
                                  member22,
                                  member32,
                                  member03,
                                  member13,
                                  member23,
                                  member33 };
            }
        }

        NODISCARD static constexpr EntryType Create(const MatrixInitType flag)
        {
            if (flag == MatrixInitType::Zero)
            {
                return EntryType{};
            }
            else
            {
                return EntryType{ Math::GetValue(1),
                                  Math::GetValue(0),
                                  Math::GetValue(0),
                                  Math::GetValue(0),
                                  Math::GetValue(0),
                                  Math::GetValue(1),
                                  Math::GetValue(0),
                                  Math::GetValue(0),
                                  Math::GetValue(0),
                                  Math::GetValue(0),
                                  Math::GetValue(1),
                                  Math::GetValue(0),
                                  Math::GetValue(0),
                                  Math::GetValue(0),
                                  Math::GetValue(0),
                                  Math::GetValue(1) };
            }
        }

        NODISCARD static EntryType Create(const ContainerType& entry, MatrixMajorFlags majorFlag);

    private:
        // ����洢Ϊ������
        EntryType entry{};
    };

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Matrix<Real>& matrix);

    // �Ƚϣ���ʹ����STL������
    template <typename Real>
    NODISCARD bool operator==(const Matrix<Real>& lhs, const Matrix<Real>& rhs);

    template <typename Real>
    NODISCARD bool operator<(const Matrix<Real>& lhs, const Matrix<Real>& rhs);

    template <typename Real>
    NODISCARD Matrix<Real> operator*(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept;  // M * mat

    template <typename Real>
    NODISCARD Matrix<Real> TransposeTimes(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept;  // M^T * mat

    template <typename Real>
    NODISCARD Matrix<Real> TimesTranspose(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept;  // M * mat^T

    template <typename Real>
    NODISCARD Matrix<Real> TransposeTimesTranspose(const Matrix<Real>& lhs, const Matrix<Real>& rhs) noexcept;  // M^T * mat^T

    // �������ε�֮������㡣M��pΪ��ζ���M������Ҫ���Ƿ���ģ�pҲ��Ҫ����w = 1����
    // M * p
    template <typename Real>
    NODISCARD HomogeneousPoint<Real> operator*(const Matrix<Real>& matrix, const HomogeneousPoint<Real>& point) noexcept;

    // p * M
    template <typename Real>
    NODISCARD HomogeneousPoint<Real> operator*(const HomogeneousPoint<Real>& point, const Matrix<Real>& matrix) noexcept;

    // M * p[0], ..., M * p[n-1]
    template <typename Real>
    NODISCARD typename HomogeneousPoint<Real>::ContainerType BatchMultiply(const Matrix<Real>& matrix, const typename HomogeneousPoint<Real>::ContainerType& inputPoints);

    // �������ͷ����֮��Ĳ�����
    // M * p
    template <typename Real>
    NODISCARD APoint<Real> operator*(const Matrix<Real>& matrix, const APoint<Real>& point) noexcept;

    // M * p[0], ..., M * p[n-1]
    template <typename Real>
    NODISCARD typename APoint<Real>::ContainerType BatchMultiply(const Matrix<Real>& matrix, const typename APoint<Real>::ContainerType& inputPoints);

    // �������ͷ�������֮��Ĳ�����
    // M * v
    template <typename Real>
    NODISCARD AVector<Real> operator*(const Matrix<Real>& matrix, const AVector<Real>& point) noexcept;

    // M * v[0], ..., M * v[n-1]
    template <typename Real>
    NODISCARD typename AVector<Real>::ContainerType BatchMultiply(const Matrix<Real>& matrix, const typename AVector<Real>::ContainerType& inputPoints);

    template <typename Real>
    NODISCARD bool Approximate(const Matrix<Real>& lhs, const Matrix<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance());

    using MatrixF = Matrix<float>;
    using MatrixD = Matrix<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX_H
