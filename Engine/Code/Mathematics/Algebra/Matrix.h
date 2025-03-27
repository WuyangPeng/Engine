///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:44)

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
#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Matrix final : private boost::additive<Matrix<Real>, boost::multiplicative<Matrix<Real>, Real, boost::totally_ordered<Matrix<Real>>>>
    {
    public:
        using ClassType = Matrix<Real>;

        using MathType = Math<Real>;
        using APointType = APoint<Real>;
        using AVectorType = AVector<Real>;
        using Matrix3Type = Matrix3<Real>;
        using Vector4Type = Vector4<Real>;
        using Matrix4Type = Matrix4<Real>;
        using HomogeneousPointType = HomogeneousPoint<Real>;

        constexpr static auto rowSize = HomogeneousPointType::pointSize;
        constexpr static auto columnSize = HomogeneousPointType::pointSize;
        constexpr static auto entrySize = rowSize * columnSize;

        using ContainerType = std::vector<Real>;
        using EntryType = std::array<Real, entrySize>;
        using EntryTypeConstIter = typename EntryType::const_iterator;

    public:
        // 如果标志为MatrixFlagsZero，创建零矩阵，否则创建单位矩阵。
        explicit constexpr Matrix(const MatrixInitType flag = MatrixInitType::Zero) noexcept
            : entry{ Create(flag) }
        {
        }

        // 输入矩阵在行r和列c
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

        // 创建一个对角矩阵,
        constexpr Matrix(Real member00, Real member11, Real member22) noexcept
            : entry{ Create(member00,
                            MathType::GetValue(0),
                            MathType::GetValue(0),
                            MathType::GetValue(0),
                            MathType::GetValue(0),
                            member11,
                            MathType::GetValue(0),
                            MathType::GetValue(0),
                            MathType::GetValue(0),
                            MathType::GetValue(0),
                            member22,
                            MathType::GetValue(0),
                            MathType::GetValue(0),
                            MathType::GetValue(0),
                            MathType::GetValue(0),
                            MathType::GetValue(1),
                            MatrixMajorFlags::Row) }
        {
        }

        explicit Matrix(const Matrix3Type& rhs);

        // 创建矩阵来自数组数字。
        // 输入数组是基于MatrixTypeFlags的输入的解释
        // MatrixTypeFlagsRow:
        // entry[0..15] = { m00,m01,m02,m03,m10,m11,m12,m13,m20,m21,m22,m23,m30,m31,m32,m33 } [row major]
        // MatrixTypeFlagsColumn:
        // entry[0..15] = { m00,m10,m20,m30,m01,m11,m21,m31,m02,m12,m22,m32,m03,m13,m23,m33 } [col major]
        Matrix(const ContainerType& entry, MatrixMajorFlags majorFlag);

        // 创建基于输入矢量的矩阵。MatrixMajorFlags解释为
        // MatrixTypeFlagsRow：向量是矩阵的行
        // MatrixTypeFlagsColumn：向量是矩阵的列
        Matrix(const Vector4Type& vector0, const Vector4Type& vector1, const Vector4Type& vector2, const Vector4Type& vector3, MatrixMajorFlags majorFlag);
        Matrix(const AVectorType& vector0, const AVectorType& vector1, const AVectorType& vector2, const APointType& point, MatrixMajorFlags majorFlag);

        // 创建一个旋转矩阵（角度为正->逆时针方向）。angle必须为弧度，不是角度。
        Matrix(const AVectorType& axis, Real angle);

        Matrix& operator=(const Matrix3Type& rhs);

        CLASS_INVARIANT_DECLARE;

        NODISCARD EntryTypeConstIter begin() const noexcept;
        NODISCARD EntryTypeConstIter end() const noexcept;

        // Matrix的上3x3的块复制到Matrix3对象。
        NODISCARD Matrix3Type GetMatrix3() const noexcept;

        NODISCARD Matrix4Type GetMatrix4() const noexcept;

        // 坐标访问
        NODISCARD EntryType GetData() const noexcept;
        NODISCARD const Real& operator()(int row, int column) const;
        NODISCARD Real& operator()(int row, int column);
        void SetRow(int row, const HomogeneousPointType& point);
        NODISCARD HomogeneousPointType GetRow(int row) const;
        void SetColumn(int column, const HomogeneousPointType& point);
        NODISCARD HomogeneousPointType GetColumn(int column) const;

        template <int Index>
        NODISCARD constexpr Real GetValue() const noexcept
        {
            static_assert(0 <= Index && Index < entrySize);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            return entry[Index];

#include SYSTEM_WARNING_POP
        }

        template <int RowIndex, int ColumnIndex>
        NODISCARD constexpr Real GetValue() const noexcept
        {
            return GetValue<RowIndex * columnSize + ColumnIndex>();
        }

        template <int RowIndex, int ColumnIndex>
        constexpr void SetValue(Real value) noexcept
        {
            SetValue<RowIndex * columnSize + ColumnIndex>(value);
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

        template <int RowIndex, int ColumnIndex>
        constexpr void Plus(Real value) noexcept
        {
            Plus<RowIndex * columnSize + ColumnIndex>(value);
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

        template <int RowIndex, int ColumnIndex>
        void Divide(Real value);

        // 矩阵存储为行主序。将它们存储在指定的列主序的数组中，该数组有16个元素。
        NODISCARD ContainerType GetColumnMajor() const;

        NODISCARD EntryType GetRowMajor() const noexcept;
        void Set(const EntryType& rowMajor) noexcept;

        // 算术运算
        NODISCARD Matrix operator-() const noexcept;
        Matrix& operator+=(const Matrix& rhs) noexcept;
        Matrix& operator-=(const Matrix& rhs) noexcept;
        Matrix& operator*=(Real scalar) noexcept;
        Matrix& operator/=(Real scalar);

        // 矩阵操作
        void MakeZero();  // Z
        void MakeIdentity() noexcept;  // I
        void MakeDiagonal(Real member00, Real member11, Real member22) noexcept;  // D
        void MakeRotation(const AVectorType& axis, Real angle);  // Real

        NODISCARD Matrix Transpose() const noexcept;  // M^T
        NODISCARD Matrix Adjoint() const noexcept;  // M^{adj}
        NODISCARD Matrix Inverse(const Real epsilon = MathType::GetZeroTolerance()) const;  // M^{-1}

        /// 反转输入矩阵的左上角3x3块。
        NODISCARD Matrix Invert3x3(const Real epsilon = MathType::GetZeroTolerance()) const;

        NODISCARD Real Determinant() const noexcept;  // det(M)

        Matrix& operator*=(const Matrix& rhs) noexcept;

        // 只对左上角3x3矩阵进行运算
        NODISCARD Matrix TimesDiagonal(const APointType& diagonal) const noexcept;  // M * D
        NODISCARD Matrix DiagonalTimes(const APointType& diagonal) const noexcept;  // D * M

        // 适用于左上3x3的块
        void Orthonormalize() noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 计算一个二次型。
        // p0^T * M * p1
        NODISCARD Real QuadraticForm(const HomogeneousPointType& point0, const HomogeneousPointType& point1) const noexcept;

        // 投影矩阵到一个指定的平面，这个平面包含“原点”和单位长度的“向量”。
        void MakeObliqueProjection(const APointType& origin, const AVectorType& normal, const AVectorType& direction);

        // 设置透视投影矩阵到指定的平面上，这个平面有一个“origin”和单位长度的“normal”，“eye”是投影的原点。
        void MakePerspectiveProjection(const APointType& origin, const AVectorType& normal, const APointType& eye);

        // 反射矩阵到一个指定的平面，这个平面包含“原点”和单位长度的“向量”。
        void MakeReflection(const APointType& origin, const AVectorType& normal);

        NODISCARD Real GetNorm() const;

        // 特殊矩阵。
        NODISCARD static constexpr Matrix GetZeroMatrix() noexcept
        {
            return Matrix{};
        }

        NODISCARD static constexpr Matrix GetIdentityMatrix() noexcept
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
                return EntryType{ MathType::GetValue(1),
                                  MathType::GetValue(0),
                                  MathType::GetValue(0),
                                  MathType::GetValue(0),
                                  MathType::GetValue(0),
                                  MathType::GetValue(1),
                                  MathType::GetValue(0),
                                  MathType::GetValue(0),
                                  MathType::GetValue(0),
                                  MathType::GetValue(0),
                                  MathType::GetValue(1),
                                  MathType::GetValue(0),
                                  MathType::GetValue(0),
                                  MathType::GetValue(0),
                                  MathType::GetValue(0),
                                  MathType::GetValue(1) };
            }
        }

        NODISCARD static EntryType Create(const ContainerType& entry, MatrixMajorFlags majorFlag);

    private:
        // 矩阵存储为行主序
        EntryType entry{};
    };

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Matrix<Real>& matrix);

    // 比较（仅使用于STL容器）
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

    // 矩阵和齐次点之间的运算。M和p为齐次对象（M并不被要求是仿射的，p也不要求有w = 1）。
    // M * p
    template <typename Real>
    NODISCARD HomogeneousPoint<Real> operator*(const Matrix<Real>& matrix, const HomogeneousPoint<Real>& point) noexcept;

    // p * M
    template <typename Real>
    NODISCARD HomogeneousPoint<Real> operator*(const HomogeneousPoint<Real>& point, const Matrix<Real>& matrix) noexcept;

    // M * p[0], ..., M * p[n-1]
    template <typename Real>
    NODISCARD typename HomogeneousPoint<Real>::ContainerType BatchMultiply(const Matrix<Real>& matrix, const typename HomogeneousPoint<Real>::ContainerType& inputPoints);

    // 仿射矩阵和仿射点之间的操作。
    // M * p
    template <typename Real>
    NODISCARD APoint<Real> operator*(const Matrix<Real>& matrix, const APoint<Real>& point) noexcept;

    // M * p[0], ..., M * p[n-1]
    template <typename Real>
    NODISCARD typename APoint<Real>::ContainerType BatchMultiply(const Matrix<Real>& matrix, const typename APoint<Real>::ContainerType& inputPoints);

    // 仿射矩阵和仿射向量之间的操作。
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
