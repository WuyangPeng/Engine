/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/20 09:15)

#ifndef MATHEMATICS_ALGEBRA_TRANSFORM_H
#define MATHEMATICS_ALGEBRA_TRANSFORM_H

#include "Mathematics/MathematicsDll.h"

#include "Matrix/Matrix3x3.h"
#include "Matrix/Matrix4x4.h"
#include "Detail/AffineMatrix.h"
#include "Detail/TransformMatrix.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"

/// 在预处理器符号中定义MATHEMATICS_USE_MATRIX_VECTOR时进行转换。
/// 转换为 Y = M * X + T，其中M是3x3的矩阵，T是3x1的平移向量。
/// 在大多数情况下，M = R，一个旋转矩阵，或者M = S * R，这里R是一个旋转矩阵和S是一个对角矩阵，其对角元素是正的缩放。
/// 为了支持允许通用仿射变换的建模软件包，M可以是任意可逆的3x3的矩阵。
/// 向量X是在“正”方向下转换为Y，“逆”方向转换Y为X，即在一般情况下X = (Y - T) * M^{-1}。
/// 在特殊情况M = S * R，逆方向是X = S^{-1} * R^t * (Y - T)，这里S^{-1}是对角矩阵，对角元素是S的倒数，和R^t是R的转置。
/// 支持SIMD矩阵与向量和矩阵与矩阵的乘法，此类储存一个齐次矩阵H = {{M,T},{0,1}}。
/// 正转换是{Y,1} = H * {X,1}和逆转换是 {X,1} = H^{-1} * {Y,1}。
///
/// 在预处理器符号中没有定义MATHEMATICS_USE_MATRIX_VECTOR时进行转换。
/// 转换为 Y = T + X * M，其中M是3x3的矩阵，T是1x3的平移向量。
/// 在大多数情况下，M = R，一个旋转矩阵，或者M = R * S，这里R是一个旋转矩阵和S是一个对角矩阵，其对角元素是正的缩放。
/// 为了支持允许通用仿射变换的建模软件包，M可以是任意可逆的3x3的矩阵。
/// 向量X是在“正”方向下转换为Y，“逆”方向转换Y为X，即在一般情况下X = M^{-1} * (Y - T)。
/// 在特殊情况M = R * S，逆方向是X = (Y - T) * R^t * S^{-1}，这里S^{-1}是对角矩阵，对角元素是S的倒数，和R^t是R的转置。
/// 支持SIMD矩阵与向量和矩阵与矩阵的乘法，此类储存一个齐次矩阵H = {{M,0},{T,1}}。
/// 正转换是{Y,1} = {X,1} * H 和逆转换是 {X,1} = {Y,1} * H^{-1}。

/// 对于乘法约定，矩阵M = R * S（MATHEMATICS_USE_MATRIX_VECTOR）或矩阵M = S * R（!MATHEMATICS_USE_MATRIX_VECTOR）被称为“RS矩阵”。
/// 该类未提供成员函数来计算变换的逆：“Transform GetInverse() const”。
/// 如果要添加此项，请注意RS矩阵的逆通常不是RS矩阵；
/// 也就是说，R*S 是 S^{-1}*R^t ，它不能总是被分解为 S^{-1} * R^t = R' * S'。
/// 您需要使用S^{-1}*R^t作为输入来设置矩阵。

namespace Mathematics
{
    template <typename Real>
    requires std::is_floating_point_v<Real>
    class Transform
    {
    public:
        using ClassType = Transform<Real>;

        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;

        using MathType = Math<Real>;
        using MatrixType = Matrix<Real>;
        using APointType = APoint<Real>;
        using AVectorType = AVector<Real>;
        using Vector3Type = Vector3<Real>;
        using Vector4Type = Vector4<Real>;
        using Matrix3Type = Matrix3<Real>;
        using AQuaternionType = AQuaternion<Real>;
        using QuaternionType = Quaternion<Real>;
        using EulerType = Euler<Real>;
        using AxisAngleType = AxisAngle<Real>;
        using Matrix3x3 = Algebra::Matrix3x3<Real>;
        using Matrix4x4 = Algebra::Matrix4x4<Real>;
        using AlgebraVector3 = Algebra::Vector3<Real>;
        using AlgebraVector4 = Algebra::Vector4<Real>;
        using AlgebraAxisAngle3 = Algebra::AxisAngle<3, Real>;
        using AlgebraAxisAngle4 = Algebra::AxisAngle<4, Real>;
        using EulerAngles = Algebra::EulerAngles<Real>;

    public:
        /// 默认构造函数产生单位转换。
        Transform() noexcept;
        explicit Transform(Real scale) noexcept;
        Transform(Real s0, Real s1, Real s2) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD explicit operator Matrix4x4() const;

        /// 设置转换为单位矩阵。
        void MakeIdentity() noexcept;

        /// 设置转换的缩放值为1。
        void MakeUnitScale();

        /// 转换结构的提示。

        /// M = I
        NODISCARD bool IsIdentity() const noexcept;

        /// R * S（已定义MATHEMATICS_USE_MATRIX_VECTOR）或S * R（未定义MATHEMATICS_USE_MATRIX_VECTOR）
        NODISCARD bool IsRotationOrScaleMatrix() const noexcept;

        /// R * S，S = c * I
        NODISCARD bool IsUniformScale() const noexcept;

        /// 成员访问
        /// (1) Set* 函数设置IsIdentity提示为false。
        /// (2) SetRotate 函数设置IsRotationOrScaleMatrix提示为true。
        ///     如果这个提示是false，GetRotate可能会产生一个断言。
        /// (3) SetMatrix函数设置IsRotationOrScaleMatrix和IsUniformScale提示为false。
        /// (4) SetScale函数设置IsUniformScale提示为false。
        ///     SetUniformScale函数设置IsUniformScale提示为true。
        ///     如果这个提示是false, GetUniformScale可能会产生一个断言。
        /// (5) 所有Set*函数设置inverseNeedsUpdate为true。
        ///     当GetInverseMatrix被调用，这种情况逆矩阵必须被重新计算，并设置inverseNeedsUpdate为false。

        /// {{R,0},{0,1}}
        void SetRotate(const MatrixType& rotate) noexcept;
        void SetRotate(const Matrix4x4& rotate);

        /// {{M,0},{0,1}}
        void SetMatrix(const MatrixType& matrix) noexcept;
        void SetMatrix(const Matrix4x4& matrix);

        void SetTranslate(const APointType& translate) noexcept;
        void SetTranslate(Real x0, Real x1, Real x2) noexcept;
        void SetTranslate(const Vector3Type& translate) noexcept;
        void SetTranslate(const Vector4Type& translate) noexcept;
        void SetTranslate(const AlgebraVector3& translate);
        void SetTranslate(const AlgebraVector4& translate);
        void SetScale(const APointType& scale);
        void SetScale(Real s0, Real s1, Real s2);
        void SetScale(const Vector3Type& scale);
        void SetScale(const Vector4Type& scale);
        void SetScale(const AlgebraVector3& scale);
        void SetScale(const AlgebraVector4& scale);
        void SetUniformScale(Real scale);

        /// {{R,0},{0,1}}
        NODISCARD MatrixType GetRotate() const;
        NODISCARD Matrix4x4 GetAlgebraRotate() const;

        /// {{M,0},{0,1}}
        NODISCARD MatrixType GetMatrix() const noexcept;
        NODISCARD Matrix4x4 GetAlgebraMatrix() const;

        /// (x,y,z)
        NODISCARD APointType GetTranslate() const noexcept;
        NODISCARD Vector4Type GetTranslationW0() const noexcept;
        NODISCARD Vector4Type GetTranslationW1() const noexcept;
        NODISCARD AlgebraVector3 GetAlgebraTranslate() const noexcept;
        NODISCARD AlgebraVector4 GetAlgebraTranslationW0() const noexcept;
        NODISCARD AlgebraVector4 GetAlgebraTranslationW1() const noexcept;

        /// (s0,s1,s2)
        NODISCARD APointType GetScale() const;
        NODISCARD Vector4Type GetScaleW1() const noexcept;
        NODISCARD AlgebraVector3 GetAlgebraScale() const;
        NODISCARD AlgebraVector4 GetAlgebraScaleW1() const noexcept;

        NODISCARD Real GetUniformScale() const;

        /// 用于设置/获取旋转的备用表示。

        /// 从3x3矩阵中设置/获取。
        void SetRotation(const Matrix3Type& rotate);
        NODISCARD Matrix3Type GetRotationMatrix3() const;
        void SetRotation(const Matrix3x3& rotate);
        NODISCARD Matrix3x3 GetRotationMatrix3x3() const;

        /// 四元数是单位长度。
        void SetRotation(const AQuaternionType& quaternion) noexcept;
        NODISCARD AQuaternionType GetRotationAQuaternion() const;
        void SetRotation(const QuaternionType& quaternion);
        NODISCARD QuaternionType GetRotationQuaternion() const;

        /// 轴为单位长度，角度以弧度为单位。
        void SetRotation(const AxisAngleType& axisAngle);
        NODISCARD AxisAngleType GetRotationAxisAngle() const;
        void SetRotation(const AlgebraAxisAngle3& axisAngle);
        NODISCARD AlgebraAxisAngle3 GetRotationAlgebraAxisAngle3() const;
        void SetRotation(const AlgebraAxisAngle4& axisAngle);
        NODISCARD AlgebraAxisAngle4 GetRotationAlgebraAxisAngle4() const;

        /// Euler角度以弧度为单位。GetEulerAngles函数要求将order值设置为所需的轴顺序。
        void SetRotation(const EulerType& eulerAngles);
        NODISCARD EulerType GetRotationEuler(ExtractEulerResultOrder order) const;

        /// Euler角度以弧度为单位。GetEulerAngles函数要求根据axis值设置为所需的轴顺序。
        void SetRotation(const EulerAngles& eulerAngles);
        NODISCARD EulerAngles GetEulerAngles(int axis0, int axis1, int axis2) const;

        /// 对于M = R * S或M = S * R，返回绝对值中S的最大值。
        /// 对于一般的M，当定义MATHEMATICS_USE_MATRIX_VECTOR时返回最大的行绝对值和，
        /// 或者当未定义MATHEMATICS_USE_MATRIX_VECTOR时最大的列绝对值和，这是变换最大规模的合理度量。
        NODISCARD Real GetNorm() const;

        /// 矩阵-点乘法, M * p。
        NODISCARD APointType operator*(const APointType& point) const noexcept;

        /// 矩阵-向量乘法, M * v。
        NODISCARD AVectorType operator*(const AVectorType& vector) const noexcept;

        /// 矩阵-矩阵乘法。
        Transform& operator*=(const Transform& transform);

        /// 获取齐次矩阵。
        NODISCARD MatrixType GetHomogeneousMatrix() const noexcept;
        NODISCARD Matrix4x4 GetMatrix4x4() const;

        /// 获取齐次矩阵的逆，当需要时重新计算。
        /// 定义MATHEMATICS_USE_MATRIX_VECTOR
        /// H = {{M,T},{0,1}}, 这里 H^{-1} = {{M^{-1},-M^{-1}*T},{0,1}}。
        /// 未定义MATHEMATICS_USE_MATRIX_VECTOR
        /// H = {{M,0},{T,1}}, 这里 H^{-1} = {{M^{-1},0},{-M^{-1}*T,1}}
        NODISCARD MatrixType GetInverseMatrix(Real epsilon = MathType::GetZeroTolerance()) const;

        /// 获取Transform的逆。不执行测试来确保调用的转换是可逆的。
        /// Transform逆。如果可能，通道已正确分配。
        /// 例如，如果输入的IsRotationOrScaleMatrix等于 'true'，则逆矩阵的IsRotationOrScaleMatrix也等于'true'，
        /// 并且逆矩阵的旋转矩阵，scale也相应地设置。
        NODISCARD Transform GetInverseTransform(Real epsilon = MathType::GetZeroTolerance()) const;

        /// 流支持
        NODISCARD int GetStreamingSize() const noexcept;
        void ReadAggregate(BufferSource& source);
        void WriteAggregate(BufferTarget& target) const;

        /// 单位转换
        static constexpr Transform GetIdentityTransform() noexcept
        {
            return Transform{};
        }

    private:
        using TransformMatrixType = TransformMatrix<Real>;
        using AffineMatrixType = AffineMatrix<Real>;

    private:
        AffineMatrixType affineMatrix;

        /// 完整的4x4齐次矩阵H = {{M,T},{0,1}}和它的逆矩阵为H^{-1} = {M^{-1},-M^{-1}*T},{0,1}}。 逆矩阵只在需要时计算。
        TransformMatrixType transformMatrix;

        mutable MatrixType inverseMatrix;
        mutable bool inverseNeedsUpdate;
    };

    /// 计算 M*V.
    template <typename Real>
    NODISCARD Vector4<Real> operator*(const Transform<Real>& transform, const Vector4<Real>& vector);

    ///  计算V^T*M.
    template <typename Real>
    NODISCARD Vector4<Real> operator*(const Vector4<Real>& vector, const Transform<Real>& transform);

    template <typename Real>
    NODISCARD Transform<Real> operator*(const Transform<Real>& lhs, const Transform<Real>& rhs);

    template <typename Real>
    NODISCARD Algebra::Matrix4x4<Real> operator*(const Algebra::Matrix4x4<Real>& matrix, const Transform<Real>& transform);

    template <typename Real>
    NODISCARD Algebra::Matrix4x4<Real> operator*(const Transform<Real>& transform, const Algebra::Matrix4x4<Real>& matrix);

    template <typename Real>
    NODISCARD bool Approximate(const Transform<Real>& lhs, const Transform<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance());

    /// 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& stream, const Transform<Real>& transform);

    using TransformF = Transform<float>;
    using TransformD = Transform<double>;
}

#endif  // MATHEMATICS_ALGEBRA_TRANSFORM_H
