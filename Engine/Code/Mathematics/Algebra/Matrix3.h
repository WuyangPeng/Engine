///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/06 14:38)

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
#include "Euler.h"
#include "Matrix3EigenDecomposition.h"
#include "Matrix3Extract.h"
#include "Vector3D.h"
#include "Flags/ExtractEulerResultType.h"
#include "Flags/MatrixFlags.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3 final : private boost::additive<Matrix3<Real>, boost::multiplicative<Matrix3<Real>, Real>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Matrix3<Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;
        using Euler = Euler<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Matrix3Extract = Matrix3Extract<Real>;
        using Matrix3EigenDecomposition = Matrix3EigenDecomposition<Real>;

        enum class VectorIndex
        {
            X = 0,
            Y,
            Z,
            Size
        };

        static constexpr auto sm_X = System::EnumCastUnderlying(VectorIndex::X);
        static constexpr auto sm_Y = System::EnumCastUnderlying(VectorIndex::Y);
        static constexpr auto sm_Z = System::EnumCastUnderlying(VectorIndex::Z);
        static constexpr auto sm_VectorSize = System::EnumCastUnderlying(VectorIndex::Size);
        static constexpr auto sm_MatrixSize = sm_VectorSize * Vector3D::sm_PointSize;
        using ArrayType = std::array<Real, sm_MatrixSize>;
        using ContainerType = std::vector<Real>;
        using Vector3DContainerType = std::vector<Vector3D>;

    public:
        // 如果标志为MatrixFlagsZero，创建零矩阵，
        // 否则创建单位矩阵。
        constexpr explicit Matrix3(MatrixInitType flag = MatrixInitType::Zero) noexcept
            : m_X{ Create(flag, VectorIndex::X) }, m_Y{ Create(flag, VectorIndex::Y) }, m_Z{ Create(flag, VectorIndex::Z) }
        {
        }

        // 输入矩阵在行r和列c
        constexpr Matrix3(Real member00, Real member01, Real member02,
                          Real member10, Real member11, Real member12,
                          Real member20, Real member21, Real member22) noexcept
            : m_X{ member00, member01, member02 }, m_Y{ member10, member11, member12 }, m_Z{ member20, member21, member22 }
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
        Matrix3(const Vector3D& vector0, const Vector3D& vector1, const Vector3D& vector2, MatrixMajorFlags majorFlag);
        Matrix3(const Vector3DContainerType& vectors, MatrixMajorFlags majorFlag);

        // 创建一个对角矩阵,
        // member01 = member10 = member02 = member20 = member12 = member21 = 0
        constexpr Matrix3(Real member00, Real member11, Real member22) noexcept
            : m_X{ member00, Math::GetValue(0), Math::GetValue(0) },
              m_Y{ Math::GetValue(0), member11, Math::GetValue(0) },
              m_Z{ Math::GetValue(0), Math::GetValue(0), member22 }
        {
        }

        // 创建一个旋转矩阵（角度为正->逆时针方向）
        // angle必须为弧度，不是角度。
        Matrix3(const Vector3D& axis, Real angle) noexcept;
        Matrix3(MatrixRotationAxis axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 创建一个张量积 U * V^T
        Matrix3(const Vector3D& vector0, const Vector3D& vector1) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 创建各种矩阵。
        void MakeZero() noexcept;
        void MakeIdentity() noexcept;
        void MakeDiagonal(Real member00, Real member11, Real member22) noexcept;
        void MakeRotation(const Vector3D& axis, Real angle) noexcept;
        void MakeRotation(MatrixRotationAxis axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeTensorProduct(const Vector3D& vector0, const Vector3D& vector1) noexcept;

        [[nodiscard]] const Vector3D& operator[](int row) const;
        [[nodiscard]] Vector3D& operator[](int row);
        [[nodiscard]] const Real& operator()(int row, int column) const;
        [[nodiscard]] Real& operator()(int row, int column);

        template <int Row, int Column>
        [[nodiscard]] Real GetValue() const noexcept;

        template <int Row, int Column>
        void SetValue(Real value) noexcept;

        [[nodiscard]] const Matrix3 operator-() const noexcept;
        Matrix3& operator+=(const Matrix3& rhs) noexcept;
        Matrix3& operator-=(const Matrix3& rhs) noexcept;
        Matrix3& operator*=(Real scalar) noexcept;
        Matrix3& operator/=(Real scalar) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // lhs^T * M * rhs
        [[nodiscard]] Real QuadraticForm(const Vector3D& lhs, const Vector3D& rhs) const noexcept;

        // M^T
        [[nodiscard]] const Matrix3 Transpose() const noexcept;

        // M * rhs
        [[nodiscard]] Matrix3& operator*=(const Matrix3& rhs) noexcept;

        // 其它运算
        [[nodiscard]] const Matrix3 TimesDiagonal(const Vector3D& diagonal) const noexcept;  // M * D
        [[nodiscard]] const Matrix3 DiagonalTimes(const Vector3D& diagonal) const noexcept;  // D * M
        [[nodiscard]] const Matrix3 Inverse(const Real epsilon = Math::GetZeroTolerance()) const;
        [[nodiscard]] const Matrix3 Adjoint() const noexcept;
        [[nodiscard]] Real Determinant() const noexcept;

        // 矩阵必须是一个旋转矩阵，下面函数才有效。
        // Orthonormalize函数使用Gram-Schmidt正交化施加到所述旋转矩阵。
        // 角度必须为弧度，而不是度数。
        [[nodiscard]] Real ExtractAngle() const noexcept;
        [[nodiscard]] const Vector3D ExtractAxis() const;
        [[nodiscard]] const Matrix3Extract ExtractAngleAxis() const;
        void Orthonormalize();

        // 矩阵必须是对称矩阵。
        // 系数M = Real * D * Real^T ，其中Real = [u0|u1|u2] 是
        // 一个列为u0、u1和u2的旋转矩阵且
        // D = diag(d0,d1,d2)是一个对角矩阵，这里对角线项为d0、d1和d2。
        // 特征向量u[i]对应的特征向量d[i]。特征值排序为d0 <= d1 <= d2。
        // 返回值的第一部分为rotation，第二部分为diagonal。
        [[nodiscard]] const Matrix3EigenDecomposition EigenDecomposition(const Real epsilon = Math::GetZeroTolerance()) const;

        // 从欧拉角创建旋转矩阵
        void MakeEulerXYZ(Real xAngle, Real yAngle, Real zAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerXZY(Real xAngle, Real zAngle, Real yAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerYXZ(Real yAngle, Real xAngle, Real zAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerYZX(Real yAngle, Real zAngle, Real xAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerZXY(Real zAngle, Real xAngle, Real yAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerZYX(Real zAngle, Real yAngle, Real xAngle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerXYX(Real x0Angle, Real yAngle, Real x1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerXZX(Real x0Angle, Real zAngle, Real x1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerYXY(Real y0Angle, Real xAngle, Real y1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerYZY(Real y0Angle, Real zAngle, Real y1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerZXZ(Real z0Angle, Real xAngle, Real z1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void MakeEulerZYZ(Real z0Angle, Real yAngle, Real z1Angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        void MakeEuler(const Euler& euler) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        /// 返回值顺序为xAngle、yAngle、zAngle
        /// 且在指定的范围内：
        /// xAngle在[-pi,pi]，yAngle在[-pi/2,pi/2]，zAngle在[-pi,pi]
        /// 当解决方案不是唯一，返回zAngle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：zAngle + xAngle= c
        /// ExtractEulerResultType::Difference：zAngle - xAngle= c
        /// 对一些角度c。
        [[nodiscard]] const Euler ExtractEulerXYZ() const noexcept;

        /// 返回值顺序为xAngle、zAngle、yAngle
        /// 且在指定的范围内：
        /// xAngle在[-pi,pi]，zAngle在[-pi/2,pi/2]，yAngle在[-pi,pi]
        /// 当解决方案不是唯一，返回yAngle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：yAngle + xAngle = c
        /// ExtractEulerResultType::Difference：yAngle - xAngle = c
        /// 对一些角度c。
        [[nodiscard]] const Euler ExtractEulerXZY() const noexcept;

        /// 返回值顺序为yAngle、xAngle、zAngle
        /// 且在指定的范围内：
        /// yAngle在[-pi,pi]，xAngle在[-pi/2,pi/2]，zAngle在[-pi,pi]
        /// 当解决方案不是唯一，返回zAngle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：zAngle + yAngle = c
        /// ExtractEulerResultType::Difference：zAngle - yAngle = c
        /// 对一些角度c。
        [[nodiscard]] const Euler ExtractEulerYXZ() const noexcept;

        /// 返回值顺序为yAngle、zAngle、xAngle
        /// 且在指定的范围内：
        /// yAngle在[-pi,pi]，zAngle在[-pi/2,pi/2]，xAngle在[-pi,pi]
        /// 当解决方案不是唯一，返回xAngle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：xAngle + yAngle = c
        /// ExtractEulerResultType::Difference：xAngle - yAngle = c
        /// 对一些角度c。
        [[nodiscard]] const Euler ExtractEulerYZX() const noexcept;

        /// 返回值顺序为zAngle、xAngle、yAngle
        /// 且在指定的范围内：
        /// zAngle在[-pi,pi]，xAngle在[-pi/2,pi/2]，yAngle在[-pi,pi]
        /// 当解决方案不是唯一，返回yAngle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：yAngle + zAngle = c
        /// ExtractEulerResultType::Difference：yAngle - zAngle = c
        /// 对一些角度c。
        [[nodiscard]] const Euler ExtractEulerZXY() const noexcept;

        /// 返回值顺序为zAngle、yAngle、xAngle
        /// 且在指定的范围内：
        /// zAngle在[-pi,pi]，yAngle在[-pi/2,pi/2]，xAngle在[-pi,pi]
        /// 当解决方案不是唯一，返回xAngle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：xAngle + zAngle = c
        /// ExtractEulerResultType::Difference：xAngle - zAngle = c
        /// 对一些角度c。
        [[nodiscard]] const Euler ExtractEulerZYX() const noexcept;

        /// 返回值顺序为x0Angle、yAngle、x1Angle
        /// 且在指定的范围内：
        /// x0Angle在[-pi,pi]，yAngle在[0,pi]，x1Angle在[-pi,pi]
        /// 当解决方案不是唯一，返回x1Angle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：x1Angle + x0Angle = c
        /// ExtractEulerResultType::Difference： x1Angle - x0Angle = c
        /// 对一些角度c。
        [[nodiscard]] const Euler ExtractEulerXYX() const noexcept;

        /// 返回值顺序为x0Angle、zAngle、x1Angle
        /// 且在指定的范围内：
        /// x0Angle在[-pi,pi]，zAngle在[0,pi]，x1Angle在[-pi,pi]
        /// 当解决方案不是唯一，返回x1Angle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：x1Angle + x0Angle = c
        /// ExtractEulerResultType::Difference： x1Angle - x0Angle = c
        /// 对一些角度c。
        [[nodiscard]] const Euler ExtractEulerXZX() const noexcept;

        /// 返回值顺序为y0Angle、xAngle、y1Angle
        /// 且在指定的范围内：
        /// y0Angle在[-pi,pi]，xAngle在[0,pi]，y1Angle在[-pi,pi]
        /// 当解决方案不是唯一，返回y1Angle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：y1Angle + y0Angle = c
        /// ExtractEulerResultType::Difference： y1Angle - y0Angle = c
        /// 对一些角度c。
        [[nodiscard]] const Euler ExtractEulerYXY() const noexcept;

        /// 返回值顺序为y0Angle、zAngle、y1Angle
        /// 且在指定的范围内：
        /// y0Angle在[-pi,pi]，zAngle在[0,pi]，y1Angle在[-pi,pi]
        /// 当解决方案不是唯一，返回y1Angle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：y1Angle + y0Angle = c
        /// ExtractEulerResultType::Difference： y1Angle - y0Angle = c
        /// 对一些角度c。
        [[nodiscard]] const Euler ExtractEulerYZY() const noexcept;

        /// 返回值顺序为z0Angle、xAngle、z1Angle
        /// 且在指定的范围内：
        /// x0Angle在[-pi,pi]，xAngle在[0,pi]，x1Angle在[-pi,pi]
        /// 当解决方案不是唯一，返回z1Angle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：z1Angle + z0Angle = c
        /// ExtractEulerResultType::Difference： z1Angle - z0Angle = c
        /// 对一些角度c。
        [[nodiscard]] const Euler ExtractEulerZXZ() const noexcept;

        /// 返回值顺序为z0Angle、yAngle、z1Angle
        /// 且在指定的范围内：
        /// x0Angle在[-pi,pi]，yAngle在[0,pi]，x1Angle在[-pi,pi]
        /// 当解决方案不是唯一，返回z1Angle = 0。
        /// 一般情况下，一整套解决方案是
        /// ExtractEulerResultType::Sum：z1Angle + z0Angle = c
        /// ExtractEulerResultType::Difference： z1Angle - z0Angle = c
        /// 对一些角度c。
        [[nodiscard]] const Euler ExtractEulerZYZ() const noexcept;

        /// SLERP（球面线性插值）而不使用四元数。
        /// 计算 Real(t) = R0*(Transpose(R0)*R1)^t
        /// 如果Q是一个旋转矩阵使用单位长度轴U和角A，
        /// 则Q^ t是一个旋转矩阵使用单位长度轴U和旋转角度t*A。
        void Slerp(Real t, const Matrix3& rot0, const Matrix3& rot1);

        [[nodiscard]] const ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate);

        // 特殊矩阵。
        [[nodiscard]] static constexpr Matrix3 GetZero()
        {
            return Matrix3{ MatrixInitType::Zero };
        }

        [[nodiscard]] static constexpr Matrix3 GetIdentity()
        {
            return Matrix3{ MatrixInitType::Identity };
        }

    private:
        [[nodiscard]] static constexpr Vector3D Create(MatrixInitType flag, VectorIndex vectorIndex)
        {
            if (flag == MatrixInitType::Zero)
            {
                return Vector3D{};
            }
            else if (vectorIndex == VectorIndex::X)
            {
                return Vector3D::GetUnitX();
            }
            else if (vectorIndex == VectorIndex::Y)
            {
                return Vector3D::GetUnitY();
            }
            else
            {
                return Vector3D::GetUnitZ();
            }
        }

        template <int Row>
        [[nodiscard]] const Vector3D& GetVector() const noexcept;

        template <int Row>
        [[nodiscard]] Vector3D& GetVector() noexcept;

        template <int Column>
        [[nodiscard]] typename Vector3D::GetCoordinateFunction GetVectorGetFunction() const noexcept;

        template <int Column>
        [[nodiscard]] typename Vector3D::SetCoordinateFunction GetVectorSetFunction() const noexcept;

    private:
        // 存储为行主序。
        Vector3D m_X;
        Vector3D m_Y;
        Vector3D m_Z;
    };

    // vec^T * M
    template <typename Real>
    [[nodiscard]] const Vector3D<Real> operator*(const Vector3D<Real>& vector, const Matrix3<Real>& matrix) noexcept;

    // M * vec
    template <typename Real>
    [[nodiscard]] const Vector3D<Real> operator*(const Matrix3<Real>& matrix, const Vector3D<Real>& vector) noexcept;

    // M * mat
    template <typename Real>
    [[nodiscard]] const Matrix3<Real> operator*(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    // lhs^T * rhs
    template <typename Real>
    [[nodiscard]] const Matrix3<Real> TransposeTimes(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    // lhs * rhs^T
    template <typename Real>
    [[nodiscard]] const Matrix3<Real> TimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    // lhs^T * rhs^T
    template <typename Real>
    [[nodiscard]] const Matrix3<Real> TransposeTimesTranspose(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs) noexcept;

    template <typename Real>
    [[nodiscard]] bool Approximate(const Matrix3<Real>& lhs, const Matrix3<Real>& rhs, const Real epsilon = Math<Real>::GetZeroTolerance());

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Matrix3<Real>& matrix);

    using FloatMatrix3 = Matrix3<float>;
    using DoubleMatrix3 = Matrix3<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_H
