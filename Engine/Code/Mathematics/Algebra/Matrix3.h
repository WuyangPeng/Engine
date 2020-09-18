// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/19 10:12)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_H
#define MATHEMATICS_ALGEBRA_MATRIX3_H

#include "Mathematics/MathematicsDll.h"

// (x,y,z)坐标系统被假定为右手坐标系。坐标轴的旋转矩阵的形式为
//   RX =    1       0       0
//           0     cos(t) -sin(t)
//           0     sin(t)  cos(t)
// 其中t > 0表示在yz平面内的逆时针旋转
//   RY =  cos(t)    0     sin(t)
//           0       1       0
//        -sin(t)    0     cos(t)
// 其中t > 0表示在zx平面内的逆时针旋转
//   RZ =  cos(t) -sin(t)    0
//         sin(t)  cos(t)    0
//           0       0       1
// 其中t > 0表示在xy平面内的逆时针旋转

#include "AlgebraFwd.h"
#include "Euler.h"
#include "Matrix3EigenDecompositionDetail.h"
#include "Matrix3Extract.h"
#include "Flags/ExtractEulerResultType.h"
#include "Flags/MatrixFlags.h"
#include "CoreTools/DataTypes/TableDetail.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Matrix3 : private boost::additive<Matrix3<Real>, boost::multiplicative<Matrix3<Real>, Real>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Matrix3<Real>;
        using Table3 = CoreTools::Table<3, 3, Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;
        using Euler = Euler<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using AlgebraTraits = AlgebraTraits<Real>;
        using Matrix3Extract = Matrix3Extract<Real>;
        using Matrix3EigenDecomposition = Matrix3EigenDecomposition<Real>;

        static constexpr auto sm_MatrixSize = 9;
        using ArrayType = std::array<Real, sm_MatrixSize>;

    public:
        // 如果标志为MatrixFlagsZero，创建零矩阵，
        // 否则创建单位矩阵。
        explicit Matrix3(MatrixInitType flag = MatrixInitType::Zero);

        // 输入矩阵在行r和列c
        Matrix3(Real member00, Real member01, Real member02,
                Real member10, Real member11, Real member12,
                Real member20, Real member21, Real member22) noexcept;

        // 创建矩阵来自数组数字。
        // 输入数组是基于MatrixTypeFlags的输入的解释
        // MatrixTypeFlagsRow:
        // entry[0..8]={m00,m01,m02,m10,m11,m12,m20,m21,m22}  [row major]
        // MatrixTypeFlagsColumn:
        // entry[0..8]={m00,m10,m20,m01,m11,m21,m02,m12,m22}  [column major]
        Matrix3(const std::vector<Real>& entry, MatrixMajorFlags majorFlag);

        // 创建基于输入矢量的矩阵。MatrixMajorFlags解释为
        // MatrixTypeFlagsRow：向量是矩阵的行
        // MatrixTypeFlagsColumn：向量是矩阵的列
        Matrix3(const Vector3D& firstVector, const Vector3D& secondVector,
                const Vector3D& thirdVector, MatrixMajorFlags majorFlag);
        Matrix3(const std::vector<Vector3D>& vectors, MatrixMajorFlags majorFlag);

        // 创建一个对角矩阵,
        // member01 = member10 = member02 = member20 = member12 = member21 = 0
        Matrix3(Real member00, Real member11, Real member22);

        // 创建一个旋转矩阵（角度为正 ->逆时针方向）
        // angle必须为弧度，不是角度。
        Matrix3(const Vector3D& axis, Real angle);
        Matrix3(MatrixRotationAxis axis, Real angle);

        // 创建一个张量积 U * V^T
        Matrix3(const Vector3D& firstVector, const Vector3D& secondVector);

        CLASS_INVARIANT_DECLARE;

        // 创建各种矩阵。
        void MakeZero();
        void MakeIdentity();
        void MakeDiagonal(Real member00, Real member11, Real member22);
        void MakeRotation(const Vector3D& axis, Real angle);
        void MakeRotation(MatrixRotationAxis axis, Real angle);
        void MakeTensorProduct(const Vector3D& firstVector, const Vector3D& secondVector);

        const Real* operator[](int row) const;
        Real* operator[](int row);
        const Real& operator()(int row, int column) const;
        Real& operator()(int row, int column);

        const Matrix3 operator-() const;
        Matrix3& operator+=(const Matrix3& rhs);
        Matrix3& operator-=(const Matrix3& rhs);
        Matrix3& operator*=(Real scalar);
        Matrix3& operator/=(Real scalar);

        // lhs^T * M * rhs
        Real QuadraticForm(const Vector3D& lhs, const Vector3D& rhs) const;

        // M^T
        const Matrix3 Transpose() const;

        // M * rhs
        Matrix3& operator*=(const Matrix3& rhs);

        // 其它运算
        const Matrix3 TimesDiagonal(const Vector3D& diagonal) const;  // M * D
        const Matrix3 DiagonalTimes(const Vector3D& diagonal) const;  // D * M
        const Matrix3 Inverse(const Real epsilon = Math::GetZeroTolerance()) const;
        const Matrix3 Adjoint() const;
        Real Determinant() const;

        // 矩阵必须是一个旋转矩阵，下面函数才有效。
        // Orthonormalize函数使用Gram-Schmidt正交化施加到所述旋转矩阵。
        // 角度必须为弧度，而不是度数。
        Real ExtractAngle() const;
        const Vector3D ExtractAxis() const;
        const Matrix3Extract ExtractAngleAxis() const;
        void Orthonormalize();

        // 矩阵必须是对称矩阵。
        // 系数M = Real * D * Real^T ，其中Real = [u0|u1|u2] 是
        // 一个列为u0、u1和u2的旋转矩阵且
        // D = diag(d0,d1,d2)是一个对角矩阵，这里对角线项为d0、d1和d2。
        // 特征向量u[i]对应的特征向量d[i]。特征值排序为d0 <= d1 <= d2。
        // 返回值的第一部分为rotation，第二部分为diagonal。
        const Matrix3EigenDecomposition EigenDecomposition(const Real epsilon = Math::GetZeroTolerance()) const;

        // 从欧拉角创建旋转矩阵
        void MakeEulerXYZ(Real xAngle, Real yAngle, Real zAngle);
        void MakeEulerXZY(Real xAngle, Real zAngle, Real yAngle);
        void MakeEulerYXZ(Real yAngle, Real xAngle, Real zAngle);
        void MakeEulerYZX(Real yAngle, Real zAngle, Real xAngle);
        void MakeEulerZXY(Real zAngle, Real xAngle, Real yAngle);
        void MakeEulerZYX(Real zAngle, Real yAngle, Real xAngle);
        void MakeEulerXYX(Real x0Angle, Real yAngle, Real x1Angle);
        void MakeEulerXZX(Real x0Angle, Real zAngle, Real x1Angle);
        void MakeEulerYXY(Real y0Angle, Real xAngle, Real y1Angle);
        void MakeEulerYZY(Real y0Angle, Real zAngle, Real y1Angle);
        void MakeEulerZXZ(Real z0Angle, Real xAngle, Real z1Angle);
        void MakeEulerZYZ(Real z0Angle, Real yAngle, Real z1Angle);

        void MakeEuler(const Euler& euler);

        // 返回值顺序为xAngle、yAngle、zAngle
        // 且在指定的范围内：
        // xAngle在[-pi,pi]，yAngle在[-pi/2,pi/2]，zAngle在[-pi,pi]
        // 当解决方案不是唯一，返回zAngle = 0。
        // 一般情况下，一整套解决方案是
        // ExtractEulerResultType::Sum：zAngle + xAngle= c
        // ExtractEulerResultType::Difference：zAngle - xAngle= c
        // 对一些角度c。
        const Euler ExtractEulerXYZ() const;

        // 返回值顺序为xAngle、zAngle、yAngle
        // 且在指定的范围内：
        // xAngle在[-pi,pi]，zAngle在[-pi/2,pi/2]，yAngle在[-pi,pi]
        // 当解决方案不是唯一，返回yAngle = 0。
        // 一般情况下，一整套解决方案是
        // ExtractEulerResultType::Sum：yAngle + xAngle = c
        // ExtractEulerResultType::Difference：yAngle - xAngle = c
        // 对一些角度c。
        const Euler ExtractEulerXZY() const;

        // 返回值顺序为yAngle、xAngle、zAngle
        // 且在指定的范围内：
        // yAngle在[-pi,pi]，xAngle在[-pi/2,pi/2]，zAngle在[-pi,pi]
        // 当解决方案不是唯一，返回zAngle = 0。
        // 一般情况下，一整套解决方案是
        // ExtractEulerResultType::Sum：zAngle + yAngle = c
        // ExtractEulerResultType::Difference：zAngle - yAngle = c
        // 对一些角度c。
        const Euler ExtractEulerYXZ() const;

        // 返回值顺序为yAngle、zAngle、xAngle
        // 且在指定的范围内：
        // yAngle在[-pi,pi]，zAngle在[-pi/2,pi/2]，xAngle在[-pi,pi]
        // 当解决方案不是唯一，返回xAngle = 0。
        // 一般情况下，一整套解决方案是
        // ExtractEulerResultType::Sum：xAngle + yAngle = c
        // ExtractEulerResultType::Difference：xAngle - yAngle = c
        // 对一些角度c。
        const Euler ExtractEulerYZX() const;

        // 返回值顺序为zAngle、xAngle、yAngle
        // 且在指定的范围内：
        // zAngle在[-pi,pi]，xAngle在[-pi/2,pi/2]，yAngle在[-pi,pi]
        // 当解决方案不是唯一，返回yAngle = 0。
        // 一般情况下，一整套解决方案是
        // ExtractEulerResultType::Sum：yAngle + zAngle = c
        // ExtractEulerResultType::Difference：yAngle - zAngle = c
        // 对一些角度c。
        const Euler ExtractEulerZXY() const;

        // 返回值顺序为zAngle、yAngle、xAngle
        // 且在指定的范围内：
        // zAngle在[-pi,pi]，yAngle在[-pi/2,pi/2]，xAngle在[-pi,pi]
        // 当解决方案不是唯一，返回xAngle = 0。
        // 一般情况下，一整套解决方案是
        // ExtractEulerResultType::Sum：xAngle + zAngle = c
        // ExtractEulerResultType::Difference：xAngle - zAngle = c
        // 对一些角度c。
        const Euler ExtractEulerZYX() const noexcept;

        // 返回值顺序为x0Angle、yAngle、x1Angle
        // 且在指定的范围内：
        // x0Angle在[-pi,pi]，yAngle在[0,pi]，x1Angle在[-pi,pi]
        // 当解决方案不是唯一，返回x1Angle = 0。
        // 一般情况下，一整套解决方案是
        // ExtractEulerResultType::Sum：x1Angle + x0Angle = c
        // ExtractEulerResultType::Difference： x1Angle - x0Angle = c
        // 对一些角度c。
        const Euler ExtractEulerXYX() const;

        // 返回值顺序为x0Angle、zAngle、x1Angle
        // 且在指定的范围内：
        // x0Angle在[-pi,pi]，zAngle在[0,pi]，x1Angle在[-pi,pi]
        // 当解决方案不是唯一，返回x1Angle = 0。
        // 一般情况下，一整套解决方案是
        // ExtractEulerResultType::Sum：x1Angle + x0Angle = c
        // ExtractEulerResultType::Difference： x1Angle - x0Angle = c
        // 对一些角度c。
        const Euler ExtractEulerXZX() const;

        // 返回值顺序为y0Angle、xAngle、y1Angle
        // 且在指定的范围内：
        // y0Angle在[-pi,pi]，xAngle在[0,pi]，y1Angle在[-pi,pi]
        // 当解决方案不是唯一，返回y1Angle = 0。
        // 一般情况下，一整套解决方案是
        // ExtractEulerResultType::Sum：y1Angle + y0Angle = c
        // ExtractEulerResultType::Difference： y1Angle - y0Angle = c
        // 对一些角度c。
        const Euler ExtractEulerYXY() const;

        // 返回值顺序为y0Angle、zAngle、y1Angle
        // 且在指定的范围内：
        // y0Angle在[-pi,pi]，zAngle在[0,pi]，y1Angle在[-pi,pi]
        // 当解决方案不是唯一，返回y1Angle = 0。
        // 一般情况下，一整套解决方案是
        // ExtractEulerResultType::Sum：y1Angle + y0Angle = c
        // ExtractEulerResultType::Difference： y1Angle - y0Angle = c
        // 对一些角度c。
        const Euler ExtractEulerYZY() const;

        // 返回值顺序为z0Angle、xAngle、z1Angle
        // 且在指定的范围内：
        // x0Angle在[-pi,pi]，xAngle在[0,pi]，x1Angle在[-pi,pi]
        // 当解决方案不是唯一，返回z1Angle = 0。
        // 一般情况下，一整套解决方案是
        // ExtractEulerResultType::Sum：z1Angle + z0Angle = c
        // ExtractEulerResultType::Difference： z1Angle - z0Angle = c
        // 对一些角度c。
        const Euler ExtractEulerZXZ() const;

        // 返回值顺序为z0Angle、yAngle、z1Angle
        // 且在指定的范围内：
        // x0Angle在[-pi,pi]，yAngle在[0,pi]，x1Angle在[-pi,pi]
        // 当解决方案不是唯一，返回z1Angle = 0。
        // 一般情况下，一整套解决方案是
        // ExtractEulerResultType::Sum：z1Angle + z0Angle = c
        // ExtractEulerResultType::Difference： z1Angle - z0Angle = c
        // 对一些角度c。
        const Euler ExtractEulerZYZ() const;

        // SLERP（球面线性插值）而不使用四元数。
        // 计算 Real(t) = R0*(Transpose(R0)*R1)^t
        // 如果Q是一个旋转矩阵使用单位长度轴U和角A，
        // 则Q^ t是一个旋转矩阵使用单位长度轴U和旋转角度t*A。
        void Slerp(Real t, const Matrix3& firstRot, const Matrix3& secondRot);

        [[nodiscard]] const ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate) noexcept;

        // 特殊矩阵。
        static const Matrix3 sm_Zero;
        static const Matrix3 sm_Identity;

    private:
        // Table存储为行主序。
        Table3 m_Entry;
    };

    // vec^T * M
    template <typename Real>
    const Vector3D<Real> operator*(const Vector3D<Real>& vector, const Matrix3<Real>& matrix);

    // M * vec
    template <typename Real>
    const Vector3D<Real> operator*(const Matrix3<Real>& matrix, const Vector3D<Real>& vector);

    // M * mat
    template <typename Real>
    const Matrix3<Real> operator*(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs);

    // lhs^T * rhs
    template <typename Real>
    const Matrix3<Real> TransposeTimes(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs);

    // lhs * rhs^T
    template <typename Real>
    const Matrix3<Real> TimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs);

    // lhs^T * rhs^T
    template <typename Real>
    const Matrix3<Real> TransposeTimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs);

    template <typename Real>
    bool Approximate(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs, const Real epsilon);

    template <typename Real>
    bool Approximate(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs);

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Matrix3<Real>& matrix);

    using Matrix3f = Matrix3<float>;
    using Matrix3d = Matrix3<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_H
