///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:45)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_H
#define MATHEMATICS_ALGEBRA_MATRIX3_H

#include "Mathematics/MathematicsDll.h"

/// (x,y,z)坐标系统被假定为右手坐标系。坐标轴的旋转矩阵的形式为
///   RX =    1       0       0
///           0     cos(t) -sin(t)
///           0     sin(t)  cos(t)
/// 其中t > 0表示在yz平面内的逆时针旋转
///   RY =  cos(t)    0     sin(t)
///           0       1       0
///        -sin(t)    0     cos(t)
/// 其中t > 0表示在zx平面内的逆时针旋转
///   RZ =  cos(t) -sin(t)    0
///         sin(t)  cos(t)    0
///           0       0       1
/// 其中t > 0表示在xy平面内的逆时针旋转

#include "AlgebraFwd.h"
#include "AxisAngle.h"
#include "Euler.h"
#include "Matrix3EigenDecomposition.h"
#include "Vector3.h"
#include "Flags/MatrixFlags.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3 final : private boost::additive<Matrix3<Real>, boost::multiplicative<Matrix3<Real>, Real>>
    {
    public:
        using ClassType = Matrix3<Real>;

        using Vector3Type = Vector3<Real>;
        using VectorIndex = typename Vector3Type::PointIndex;
        static constexpr auto xIndex = Vector3Type::xIndex;
        static constexpr auto yIndex = Vector3Type::yIndex;
        static constexpr auto zIndex = Vector3Type::zIndex;
        static constexpr auto vectorSize = Vector3Type::pointSize;
        static constexpr auto matrixSize = vectorSize * Vector3Type::pointSize;

        using MathType = Math<Real>;
        using EulerType = Euler<Real>;
        using Matrix2Type = Matrix2<Real>;
        using Matrix4Type = Matrix4<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using Matrix3Extract = AxisAngle<Real>;
        using Matrix3EigenDecompositionType = Matrix3EigenDecomposition<Real>;
        using ArrayType = std::array<Real, matrixSize>;
        using ContainerType = std::vector<Real>;
        using Vector3ContainerType = std::vector<Vector3Type>;

    public:
        // 如果标志为MatrixFlagsZero，创建零矩阵，
        // 否则创建单位矩阵。
        constexpr explicit Matrix3(MatrixInitType flag = MatrixInitType::Zero) noexcept
            : x{ Create(flag, VectorIndex::X) }, y{ Create(flag, VectorIndex::Y) }, z{ Create(flag, VectorIndex::Z) }
        {
        }

        // 输入矩阵在行r和列c
        constexpr Matrix3(Real member00,
                          Real member01,
                          Real member02,
                          Real member10,
                          Real member11,
                          Real member12,
                          Real member20,
                          Real member21,
                          Real member22) noexcept
            : x{ member00, member01, member02 }, y{ member10, member11, member12 }, z{ member20, member21, member22 }
        {
        }

        /// 创建矩阵来自数组数字。
        /// 输入数组是基于MatrixTypeFlags的输入的解释
        /// MatrixTypeFlagsRow:
        /// entry[0..8]={ m00,m01,m02,m10,m11,m12,m20,m21,m22 }  [row major]
        /// MatrixTypeFlagsColumn:
        /// entry[0..8]={ m00,m10,m20,m01,m11,m21,m02,m12,m22 }  [column major]
        Matrix3(const ContainerType& entry, MatrixMajorFlags majorFlag);

        // 创建基于输入矢量的矩阵。MatrixMajorFlags解释为
        // MatrixTypeFlagsRow：向量是矩阵的行
        // MatrixTypeFlagsColumn：向量是矩阵的列
        Matrix3(const Vector3Type& vector0, const Vector3Type& vector1, const Vector3Type& vector2, MatrixMajorFlags majorFlag);
        Matrix3(const Vector3ContainerType& vectors, MatrixMajorFlags majorFlag);

        // 创建一个对角矩阵,
        // member01 = member10 = member02 = member20 = member12 = member21 = 0
        constexpr Matrix3(Real member00, Real member11, Real member22) noexcept
            : x{ member00, MathType::GetValue(0), MathType::GetValue(0) },
              y{ MathType::GetValue(0), member11, MathType::GetValue(0) },
              z{ MathType::GetValue(0), MathType::GetValue(0), member22 }
        {
        }

        // 创建一个旋转矩阵（角度为正->逆时针方向）
        // angle必须为弧度，不是角度。
        Matrix3(const Vector3Type& axis, Real angle) noexcept;
        Matrix3(MatrixRotationAxis axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 创建一个张量积 U * V^T
        Matrix3(const Vector3Type& vector0, const Vector3Type& vector1) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 创建各种矩阵。
        void MakeZero() noexcept;
        void MakeIdentity() noexcept;
        void MakeDiagonal(Real member00, Real member11, Real member22) noexcept;
        void MakeRotation(const Vector3Type& axis, Real angle) noexcept;
        void MakeRotation(MatrixRotationAxis axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeTensorProduct(const Vector3Type& vector0, const Vector3Type& vector1) noexcept;

        NODISCARD const Vector3Type& operator[](int row) const;
        NODISCARD Vector3Type& operator[](int row);
        NODISCARD const Real& operator()(int row, int column) const;
        NODISCARD Real& operator()(int row, int column);

        template <int Row, int Column>
        NODISCARD Real GetValue() const noexcept;

        template <int Row, int Column>
        void SetValue(Real value) noexcept;

        NODISCARD Matrix3 operator-() const noexcept;
        Matrix3& operator+=(const Matrix3& rhs) noexcept;
        Matrix3& operator-=(const Matrix3& rhs) noexcept;
        Matrix3& operator*=(Real scalar) noexcept;
        Matrix3& operator/=(Real scalar) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // lhs^T * M * rhs
        NODISCARD Real QuadraticForm(const Vector3Type& lhs, const Vector3Type& rhs) const noexcept;

        // M^T
        NODISCARD Matrix3 Transpose() const noexcept;

        // M * rhs
        Matrix3& operator*=(const Matrix3& rhs) noexcept;

        // 其它运算
        NODISCARD Matrix3 TimesDiagonal(const Vector3Type& diagonal) const noexcept;  // M * D
        NODISCARD Matrix3 DiagonalTimes(const Vector3Type& diagonal) const noexcept;  // D * M
        NODISCARD Matrix3 Inverse(const Real epsilon = MathType::GetZeroTolerance()) const;
        NODISCARD Matrix3 Adjoint() const noexcept;
        NODISCARD Real Determinant() const noexcept;

        NODISCARD Matrix3 GaussianEliminationInverse(Real epsilon = MathType::GetZeroTolerance()) const;
        NODISCARD Real GaussianEliminationDeterminant(Real epsilon = MathType::GetZeroTolerance()) const;

        // 矩阵必须是一个旋转矩阵，下面函数才有效。
        // Orthonormalize函数使用Gram-Schmidt正交化施加到所述旋转矩阵。
        // 角度必须为弧度，而不是度数。
        NODISCARD Real ExtractAngle() const noexcept;
        NODISCARD Vector3Type ExtractAxis() const noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD Matrix3Extract ExtractAngleAxis() const noexcept(gAssert < 3 || gMathematicsAssert < 3);
        void Orthonormalize();

        // 矩阵必须是对称矩阵。
        // 系数M = Real * D * Real^T ，其中Real = [u0|u1|u2] 是
        // 一个列为u0、u1和u2的旋转矩阵且
        // D = diag(d0,d1,d2)是一个对角矩阵，这里对角线项为d0、d1和d2。
        // 特征向量u[i]对应的特征向量d[i]。特征值排序为d0 <= d1 <= d2。
        // 返回值的第一部分为rotation，第二部分为diagonal。
        NODISCARD Matrix3EigenDecompositionType EigenDecomposition(Real epsilon = MathType::GetZeroTolerance()) const;

        // 从欧拉角创建旋转矩阵
        void MakeEulerXYZ(Real xAngle, Real yAngle, Real zAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerXZY(Real xAngle, Real zAngle, Real yAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerYXZ(Real yAngle, Real xAngle, Real zAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerYZX(Real yAngle, Real zAngle, Real xAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerZXY(Real zAngle, Real xAngle, Real yAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerZYX(Real zAngle, Real yAngle, Real xAngle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerXYX(Real x0Angle, Real yAngle, Real x1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerXZX(Real x0Angle, Real zAngle, Real x1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerYXY(Real y0Angle, Real xAngle, Real y1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerYZY(Real y0Angle, Real zAngle, Real y1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerZXZ(Real z0Angle, Real xAngle, Real z1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        void MakeEulerZYZ(Real z0Angle, Real yAngle, Real z1Angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        void MakeEuler(const EulerType& euler) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        NODISCARD EulerType ExtractEuler(ExtractEulerResultOrder euler) const noexcept;

        /// 返回值顺序为xAngle、yAngle、zAngle
        /// 且在指定的范围内：
        /// xAngle在[-pi,pi]，yAngle在[-pi/2,pi/2]，zAngle在[-pi,pi]
        /// 当解决方案不是唯一，返回zAngle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：zAngle + xAngle= c
        /// ExtractEulerResultType::Difference：zAngle - xAngle= c
        /// 对一些角度c。
        NODISCARD EulerType ExtractEulerXYZ() const noexcept;

        /// 返回值顺序为xAngle、zAngle、yAngle
        /// 且在指定的范围内：
        /// xAngle在[-pi,pi]，zAngle在[-pi/2,pi/2]，yAngle在[-pi,pi]
        /// 当解决方案不是唯一，返回yAngle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：yAngle + xAngle = c
        /// ExtractEulerResultType::Difference：yAngle - xAngle = c
        /// 对一些角度c。
        NODISCARD EulerType ExtractEulerXZY() const noexcept;

        /// 返回值顺序为yAngle、xAngle、zAngle
        /// 且在指定的范围内：
        /// yAngle在[-pi,pi]，xAngle在[-pi/2,pi/2]，zAngle在[-pi,pi]
        /// 当解决方案不是唯一，返回zAngle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：zAngle + yAngle = c
        /// ExtractEulerResultType::Difference：zAngle - yAngle = c
        /// 对一些角度c。
        NODISCARD EulerType ExtractEulerYXZ() const noexcept;

        /// 返回值顺序为yAngle、zAngle、xAngle
        /// 且在指定的范围内：
        /// yAngle在[-pi,pi]，zAngle在[-pi/2,pi/2]，xAngle在[-pi,pi]
        /// 当解决方案不是唯一，返回xAngle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：xAngle + yAngle = c
        /// ExtractEulerResultType::Difference：xAngle - yAngle = c
        /// 对一些角度c。
        NODISCARD EulerType ExtractEulerYZX() const noexcept;

        /// 返回值顺序为zAngle、xAngle、yAngle
        /// 且在指定的范围内：
        /// zAngle在[-pi,pi]，xAngle在[-pi/2,pi/2]，yAngle在[-pi,pi]
        /// 当解决方案不是唯一，返回yAngle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：yAngle + zAngle = c
        /// ExtractEulerResultType::Difference：yAngle - zAngle = c
        /// 对一些角度c。
        NODISCARD EulerType ExtractEulerZXY() const noexcept;

        /// 返回值顺序为zAngle、yAngle、xAngle
        /// 且在指定的范围内：
        /// zAngle在[-pi,pi]，yAngle在[-pi/2,pi/2]，xAngle在[-pi,pi]
        /// 当解决方案不是唯一，返回xAngle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：xAngle + zAngle = c
        /// ExtractEulerResultType::Difference：xAngle - zAngle = c
        /// 对一些角度c。
        NODISCARD EulerType ExtractEulerZYX() const noexcept;

        /// 返回值顺序为x0Angle、yAngle、x1Angle
        /// 且在指定的范围内：
        /// x0Angle在[-pi,pi]，yAngle在[0,pi]，x1Angle在[-pi,pi]
        /// 当解决方案不是唯一，返回x1Angle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：x1Angle + x0Angle = c
        /// ExtractEulerResultType::Difference： x1Angle - x0Angle = c
        /// 对一些角度c。
        NODISCARD EulerType ExtractEulerXYX() const noexcept;

        /// 返回值顺序为x0Angle、zAngle、x1Angle
        /// 且在指定的范围内：
        /// x0Angle在[-pi,pi]，zAngle在[0,pi]，x1Angle在[-pi,pi]
        /// 当解决方案不是唯一，返回x1Angle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：x1Angle + x0Angle = c
        /// ExtractEulerResultType::Difference： x1Angle - x0Angle = c
        /// 对一些角度c。
        NODISCARD EulerType ExtractEulerXZX() const noexcept;

        /// 返回值顺序为y0Angle、xAngle、y1Angle
        /// 且在指定的范围内：
        /// y0Angle在[-pi,pi]，xAngle在[0,pi]，y1Angle在[-pi,pi]
        /// 当解决方案不是唯一，返回y1Angle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：y1Angle + y0Angle = c
        /// ExtractEulerResultType::Difference： y1Angle - y0Angle = c
        /// 对一些角度c。
        NODISCARD EulerType ExtractEulerYXY() const noexcept;

        /// 返回值顺序为y0Angle、zAngle、y1Angle
        /// 且在指定的范围内：
        /// y0Angle在[-pi,pi]，zAngle在[0,pi]，y1Angle在[-pi,pi]
        /// 当解决方案不是唯一，返回y1Angle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：y1Angle + y0Angle = c
        /// ExtractEulerResultType::Difference： y1Angle - y0Angle = c
        /// 对一些角度c。
        NODISCARD EulerType ExtractEulerYZY() const noexcept;

        /// 返回值顺序为z0Angle、xAngle、z1Angle
        /// 且在指定的范围内：
        /// x0Angle在[-pi,pi]，xAngle在[0,pi]，x1Angle在[-pi,pi]
        /// 当解决方案不是唯一，返回z1Angle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：z1Angle + z0Angle = c
        /// ExtractEulerResultType::Difference： z1Angle - z0Angle = c
        /// 对一些角度c。
        NODISCARD EulerType ExtractEulerZXZ() const noexcept;

        /// 返回值顺序为z0Angle、yAngle、z1Angle
        /// 且在指定的范围内：
        /// x0Angle在[-pi,pi]，yAngle在[0,pi]，x1Angle在[-pi,pi]
        /// 当解决方案不是唯一，返回z1Angle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：z1Angle + z0Angle = c
        /// ExtractEulerResultType::Difference： z1Angle - z0Angle = c
        /// 对一些角度c。
        NODISCARD EulerType ExtractEulerZYZ() const noexcept;

        /// SLERP（球面线性插值）而不使用四元数。
        /// 计算 Real(t) = R0*(Transpose(R0)*R1)^t
        /// 如果Q是一个旋转矩阵使用单位长度轴U和角A，
        /// 则Q^ t是一个旋转矩阵使用单位长度轴U和旋转角度t*A。
        void Slerp(Real t, const Matrix3& rot0, const Matrix3& rot1) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate);

        NODISCARD ContainerType GetContainer() const;

        // 特殊矩阵。
        NODISCARD static constexpr Matrix3 GetZero()
        {
            return Matrix3{ MatrixInitType::Zero };
        }

        NODISCARD static constexpr Matrix3 GetIdentity()
        {
            return Matrix3{ MatrixInitType::Identity };
        }

        NODISCARD Matrix4Type Lift() const;
        NODISCARD Matrix2Type Project() const;

        NODISCARD Real Trace() const noexcept;

    private:
        NODISCARD static constexpr Vector3Type Create(MatrixInitType flag, VectorIndex vectorIndex)
        {
            if (flag == MatrixInitType::Zero)
            {
                return Vector3Type{};
            }
            else if (vectorIndex == VectorIndex::X)
            {
                return Vector3Type::GetUnitX();
            }
            else if (vectorIndex == VectorIndex::Y)
            {
                return Vector3Type::GetUnitY();
            }
            else
            {
                return Vector3Type::GetUnitZ();
            }
        }

        template <int Row>
        NODISCARD const Vector3Type& GetVector() const noexcept;

        template <int Row>
        NODISCARD Vector3Type& GetVector() noexcept;

        template <int Column>
        NODISCARD typename Vector3Type::GetCoordinateFunction GetVectorGetFunction() const noexcept;

        template <int Column>
        NODISCARD typename Vector3Type::SetCoordinateFunction GetVectorSetFunction() const noexcept;

    private:
        // 存储为行主序。
        Vector3Type x;
        Vector3Type y;
        Vector3Type z;
    };

    // vec^T * M
    template <typename Real>
    NODISCARD Vector3<Real> operator*(const Vector3<Real>& vector, const Matrix3<Real>& matrix) noexcept;

    // M * vec
    template <typename Real>
    NODISCARD Vector3<Real> operator*(const Matrix3<Real>& matrix, const Vector3<Real>& vector) noexcept;

    // M * mat
    template <typename Real>
    NODISCARD Matrix3<Real> operator*(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    // lhs^T * rhs
    template <typename Real>
    NODISCARD Matrix3<Real> TransposeTimes(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    // lhs * rhs^T
    template <typename Real>
    NODISCARD Matrix3<Real> TimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    // lhs^T * rhs^T
    template <typename Real>
    NODISCARD Matrix3<Real> TransposeTimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD bool Approximate(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance());

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Matrix3<Real>& matrix);

    using Matrix3F = Matrix3<float>;
    using Matrix3D = Matrix3<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_H
