///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/18 17:26)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_ROTATION_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_ROTATION_H

#include "Mathematics/MathematicsDll.h"

#include "AxisAngle.h"
#include "EulerAngles.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Matrix/Matrix.h"
#include "Mathematics/Algebra/Quaternion.h"

namespace Mathematics::Algebra
{
    /// 旋转的各种表示之间的转换。
    /// N的值必须为3或4。
    /// 后一种情况支持仿射代数，
    /// 当您使用4元组向量（w分量对于点是1，对于向量是0）和4x4矩阵进行仿射变换时。
    /// 旋转轴必须为单位长度。
    /// 角度以弧度为单位。
    /// 欧拉角在世界坐标系中；我们还没有添加对身体坐标的支持。
    template <int N, typename Real>
    requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    class Rotation
    {
    public:
        using ClassType = Rotation<N, Real>;

        using Matrix = Matrix<N, N, Real>;
        using Quaternion = Quaternion<Real>;
        using AxisAngle = AxisAngle<N, Real>;
        using EulerAngles = EulerAngles<Real>;

        using Math = Math<Real>;

    public:
        /// 从各种表示创建旋转。
        explicit Rotation(const Matrix& matrix) noexcept;
        explicit Rotation(const Quaternion& quaternion) noexcept;
        explicit Rotation(const AxisAngle& axisAngle) noexcept;
        explicit Rotation(const EulerAngles& eulerAngles) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 将一种表达转换为另一种表达。
        NODISCARD explicit operator Matrix();
        NODISCARD explicit operator Quaternion();
        NODISCARD explicit operator AxisAngle();
        NODISCARD EulerAngles operator()(int axis0, int axis1, int axis2);

    private:
        /// 将旋转矩阵转换为四元数。
        ///
        /// x^2 = (+r00 - r11 - r22 + 1)/4
        /// y^2 = (-r00 + r11 - r22 + 1)/4
        /// z^2 = (-r00 - r11 + r22 + 1)/4
        /// w^2 = (+r00 + r11 + r22 + 1)/4
        /// x^2 + y^2 = (1 - r22)/2
        /// z^2 + w^2 = (1 + r22)/2
        /// y^2 - x^2 = (r11 - r00)/2
        /// w^2 - z^2 = (r11 + r00)/2
        /// x*y = (r01 + r10)/4
        /// x*z = (r02 + r20)/4
        /// y*z = (r12 + r21)/4
        /// [MATHEMATICS_USE_MATRIX_VECTOR]
        ///   x*w = (r21 - r12)/4
        ///   y*w = (r02 - r20)/4
        ///   z*w = (r10 - r01)/4
        /// [MATHEMATICS_USE_VECTOR_MATRIX]
        ///   x*w = (r12 - r21)/4
        ///   y*w = (r20 - r02)/4
        ///   z*w = (r01 - r10)/4
        ///
        /// 如果Q是4x1列矢量 (x,y,z,w)，则前面的方程给出了
        ///         +-                  -+
        ///         | x*x  x*y  x*z  x*w |
        /// Q*Q^T = | y*x  y*y  y*z  y*w |
        ///         | z*x  z*y  z*z  z*w |
        ///         | w*x  w*y  w*z  w*w |
        ///         +-                  -+
        /// 代码提取最大长度的行，对其进行归一化以获得结果q。
        static void Convert(const Matrix& matrix, Quaternion& quaternion);

        /// 将四元数q = x*i + y*j + z*k + w转换为旋转矩阵。
        /// [MATHEMATICS_USE_MATRIX_VECTOR]
        ///     +-           -+   +-                                     -+
        /// R = | r00 r01 r02 | = | 1-2y^2-2z^2  2(xy-zw)     2(xz+yw)    |
        ///     | r10 r11 r12 |   | 2(xy+zw)     1-2x^2-2z^2  2(yz-xw)    |
        ///     | r20 r21 r22 |   | 2(xz-yw)     2(yz+xw)     1-2x^2-2y^2 |
        ///     +-           -+   +-                                     -+
        /// [MATHEMATICS_USE_VECTOR_MATRIX]
        ///     +-           -+   +-                                     -+
        /// R = | r00 r01 r02 | = | 1-2y^2-2z^2  2(xy+zw)     2(xz-yw)    |
        ///     | r10 r11 r12 |   | 2(xy-zw)     1-2x^2-2z^2  2(yz+xw)    |
        ///     | r20 r21 r22 |   | 2(xz+yw)     2(yz-xw)     1-2x^2-2y^2 |
        ///     +-           -+   +-                                     -+
        static void Convert(const Quaternion& quaternion, Matrix& matrix);

        /// 将旋转矩阵转换为轴角度对。
        /// 设(x0,x1,x2)为轴，设t为旋转角度。
        /// 旋转矩阵为
        /// [MATHEMATICS_USE_MATRIX_VECTOR]
        ///   R = I + sin(t)*S + (1-cos(t))*S^2
        /// 或者
        /// [MATHEMATICS_USE_VECTOR_MATRIX]
        ///   R = I - sin(t)*S + (1-cos(t))*S^2
        ///   其中I是恒等式，S = {{0,-x2,x1},{x2,0,-x0},{-x1,x0,0}}，
        ///   其中内括号三元组是矩阵的行。
        ///   如果t > 0，R表示逆时针旋转；
        ///   请参见构造函数Matrix3x3(axis,angle)的注释。
        ///   可以看出，cos(t) = (trace(R)-1)/2和R - Transpose(R) = 2*sin(t)*S。
        ///   只要sin(t)不为零，我们就可以在第二方程中求解S，这产生轴方向U = (S21,S02,S10)。
        ///   当t = 0时，旋转是单位，在这种情况下，任何轴方向都是有效的；我们选择(1,0,0)。
        ///   当t = pi时，必须是R - Transpose(R) = 0，这阻止了我们提取轴。
        ///   相反，请注意(R+I)/2 = I+S^2 = U*U^T，其中U是单位长度轴方向。
        static void Convert(const Matrix& matrix, AxisAngle& axisAngle);

        /// 将轴角对转换为旋转矩阵。
        /// 假设(x0,x1,x2)是一个右手世界（x0向右，x1向上，x2在页面平面外），
        /// 从观察者的角度来看，正角度对应于逆时针旋转，观察方向为轴方向的负方向。
        /// 坐标轴旋转如下，其中unit(0) = (1,0,0)，unit(1) = (0,1,0)，unit(2) = (0,0,1)，
        /// [MATHEMATICS_USE_MATRIX_VECTOR]
        ///   R(unit(0),t) = {{ 1, 0, 0}, { 0, c,-s}, { 0, s, c}}
        ///   R(unit(1),t) = {{ c, 0, s}, { 0, 1, 0}, {-s, 0, c}}
        ///   R(unit(2),t) = {{ c,-s, 0}, { s, c, 0}, { 0, 0, 1}}
        /// 或者
        /// [MATHEMATICS_USE_VECTOR_MATRIX]
        ///   R(unit(0),t) = {{ 1, 0, 0}, { 0, c, s}, { 0,-s, c}}
        ///   R(unit(1),t) = {{ c, 0,-s}, { 0, 1, 0}, { s, 0, c}}
        ///   R(unit(2),t) = {{ c, s, 0}, {-s, c, 0}, { 0, 0, 1}}
        /// 其中c = cos(t), s = sin(t)和内括号三元组是矩阵的行。
        /// 一般矩阵为
        /// [MATHEMATICS_USE_MATRIX_VECTOR]
        ///      +-                                                          -+
        ///  R = | (1-c)*x0^2  + c     (1-c)*x0*x1 - s*x2  (1-c)*x0*x2 + s*x1 |
        ///      | (1-c)*x0*x1 + s*x2  (1-c)*x1^2  + c     (1-c)*x1*x2 - s*x0 |
        ///      | (1-c)*x0*x2 - s*x1  (1-c)*x1*x2 + s*x0  (1-c)*x2^2  + c    |
        ///      +-                                                          -+
        /// [MATHEMATICS_USE_VECTOR_MATRIX]
        ///      +-                                                          -+
        ///  R = | (1-c)*x0^2  + c     (1-c)*x0*x1 + s*x2  (1-c)*x0*x2 - s*x1 |
        ///      | (1-c)*x0*x1 - s*x2  (1-c)*x1^2  + c     (1-c)*x1*x2 + s*x0 |
        ///      | (1-c)*x0*x2 + s*x1  (1-c)*x1*x2 - s*x0  (1-c)*x2^2  + c    |
        ///      +-                                                          -+
        static void Convert(const AxisAngle& axisAngle, Matrix& matrix);

        /// 将旋转矩阵转换为Euler角度。
        /// 欧拉角的因子分解不一定是唯一的。如果结果为NotUniqueSum，则会出现多个解，因为angleN2+angleN0是常数。
        /// 如果结果为NotUniqueDifference，则会出现多个解，因为angleN2-angleN0是常数。
        /// 在任何一种类型的非唯一性中，函数都返回angleN0=0。
        static void Convert(const Matrix& matrix, EulerAngles& eulerAngles);

        /// 将欧拉角转换为旋转矩阵。
        /// 三个整数输入以{0,1,2} 为单位，
        /// 对应于世界方向unit(0) = (1,0,0), unit(1) = (0,1,0)或unit(2) = (0,0,1)。
        /// 三元组(N0,N1,N2)必须在以下集合中，
        ///   {(0,1,2),(0,2,1),(1,0,2),(1,2,0),(2,0,1),(2,1,0),
        ///    (0,1,0),(0,2,0),(1,0,1),(1,2,1),(2,0,2),(2,1,2)}
        /// 旋转矩阵为
        ///   [MATHEMATICS_USE_MATRIX_VECTOR]
        ///     R(unit(N2),angleN2)*R(unit(N1),angleN1)*R(unit(N0),angleN0)
        /// or
        ///   [MATHEMATICS_USE_VECTOR_MATRIX]
        ///     R(unit(N0),angleN0)*R(unit(N1),angleN1)*R(unit(N2),angleN2)
        /// 构造函数Matrix3(axis,angle)的约定也适用于此。
        ///
        /// 注：选择顺序反转，以便使用一个乘法约定构建的旋转矩阵是使用另一个乘法惯例构建的旋转基质的转置。因此
        /// [MATHEMATICS_USE_MATRIX_VECTOR]
        ///   Matrix3x3<Real> R_mvConvention(N0,N1,N2,angleN0,angleN1,angleN2);
        ///   Vector3Type<Real> V(...);
        ///   Vector3Type<Real> U = R_mvConvention*V;  // (u0,u1,u2) = R2*R1*R0*V
        /// [MATHEMATICS_USE_VECTOR_MATRIX]
        ///   Matrix3x3<Real> R_vmConvention(N0,N1,N2,angleN0,angleN1,angleN2);
        ///   Vector3Type<Real> V(...);
        ///   Vector3Type<Real> U = R_mvConvention*V;  // (u0,u1,u2) = V*R0*R1*R2
        /// 在任一约定中，都会得到相同的三元组U。
        static void Convert(const EulerAngles& eulerAngles, Matrix& matrix);

        /// 将四元数转换为轴角度对，其中
        ///   q = sin(angle/2)*(axis[0]*i+axis[1]*j+axis[2]*k)+cos(angle/2)
        static void Convert(const Quaternion& quaternion, AxisAngle& axisAngle);

        /// 将轴角度对转换为四元数，其中
        ///   q = sin(angle/2)*(axis[0]*i+axis[1]*j+axis[2]*k)+cos(angle/2)
        static void Convert(const AxisAngle& axisAngle, Quaternion& quaternion);

        /// 将四元数转换为欧拉角。
        /// 四元数被转换为矩阵，然后矩阵被转换为欧拉角。
        static void Convert(const Quaternion& quaternion, EulerAngles& eulerAngles);

        /// 将欧拉角转换为四元数。
        /// 欧拉角被转换为矩阵，然后矩阵被转换为四元数。
        static void Convert(const EulerAngles& eulerAngles, Quaternion& quaternion);

        /// 将轴角度对转换为欧拉角。
        /// 轴角度对被转换为四元数，然后四元数被转换为欧拉角。
        static void Convert(const AxisAngle& axisAngle, EulerAngles& eulerAngles);

        /// 将欧拉角转换为轴角度对。
        /// 欧拉角被转换为四元数，然后四元数被转换为轴角对。
        static void Convert(const EulerAngles& eulerAngles, AxisAngle& axisAngle);

    private:
        RotationType rotationType;
        Matrix matrix;
        Quaternion quaternion;
        AxisAngle axisAngle;
        EulerAngles eulerAngles;
    };
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_ROTATION_H
