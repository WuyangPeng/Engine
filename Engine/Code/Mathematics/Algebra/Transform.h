/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/29 15:45)

#ifndef MATHEMATICS_ALGEBRA_TRANSFORM_H
#define MATHEMATICS_ALGEBRA_TRANSFORM_H

#include "Mathematics/MathematicsDll.h"

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

        using Math = Math<Real>;
        using Matrix = Matrix<Real>;
        using APoint = APoint<Real>;
        using AVector = AVector<Real>;
        using Vector3 = Vector3<Real>;
        using Vector4 = Vector4<Real>;
        using Matrix3 = Matrix3<Real>;
        using AQuaternion = AQuaternion<Real>;
        using Euler = Euler<Real>;
        using AxisAngle = AxisAngle<Real>;

    public:
        // 默认构造函数产生单位转换。
        Transform() noexcept;
        explicit Transform(Real scale) noexcept;
        Transform(Real s0, Real s1, Real s2) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 设置转换为单位矩阵。
        void MakeIdentity() noexcept;

        // 设置转换的缩放值为1。
        void MakeUnitScale();

        // 转换结构的提示。
        NODISCARD bool IsIdentity() const noexcept;  // I
        NODISCARD bool IsRotationOrScaleMatrix() const noexcept;  // R * S（已定义MATHEMATICS_USE_MATRIX_VECTOR）或S * R（未定义MATHEMATICS_USE_MATRIX_VECTOR）
        NODISCARD bool IsUniformScale() const noexcept;  // R * S，S = c * I

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

        // {{R,0},{0,1}}
        void SetRotate(const Matrix& rotate) noexcept;

        // {{M,0},{0,1}}
        void SetMatrix(const Matrix& matrix) noexcept;

        void SetTranslate(const APoint& translate) noexcept;
        void SetTranslate(Real x0, Real x1, Real x2) noexcept;
        void SetTranslate(const Vector3& translate) noexcept;
        void SetTranslate(const Vector4& translate) noexcept;
        void SetScale(const APoint& scale);
        void SetScale(Real s0, Real s1, Real s2);
        void SetScale(const Vector3& scale);
        void SetScale(const Vector4& scale);
        void SetUniformScale(Real scale);

        // {{R,0},{0,1}}
        NODISCARD Matrix GetRotate() const;

        // {{M,0},{0,1}}
        NODISCARD Matrix GetMatrix() const noexcept;

        // (x,y,z)
        NODISCARD APoint GetTranslate() const noexcept;
        NODISCARD Vector4 GetTranslationW0() const noexcept;
        NODISCARD Vector4 GetTranslationW1() const noexcept;

        // (s0,s1,s2)
        NODISCARD APoint GetScale() const;
        NODISCARD Vector4 GetScaleW1() const noexcept;

        NODISCARD Real GetUniformScale() const;

        // 用于设置/获取旋转的备用表示。

        // 从3x3矩阵中设置/获取。
        void SetRotation(const Matrix3& rotate);
        NODISCARD Matrix3 GetRotationMatrix3() const;

        // 四元数是单位长度。
        void SetRotation(const AQuaternion& quaternion) noexcept;
        NODISCARD AQuaternion GetRotationQuaternion() const;

        void SetRotation(const AxisAngle& axisAngle);
        NODISCARD AxisAngle GetRotationAxisAngle() const;

        // Euler角度以弧度为单位。GetEulerAngles函数要求将order值设置为所需的轴顺序。
        void SetRotation(const Euler& eulerAngles);
        NODISCARD Euler GetRotationEuler(ExtractEulerResultOrder order) const;

        /// 对于M = R * S或M = S * R，返回绝对值中S的最大值。
        /// 对于一般的M，当定义MATHEMATICS_USE_MATRIX_VECTOR时返回最大的行绝对值和，
        /// 或者当未定义MATHEMATICS_USE_MATRIX_VECTOR时最大的列绝对值和，这是变换最大规模的合理度量。
        NODISCARD Real GetNorm() const;

        // 矩阵-点乘法, M * p。
        NODISCARD APoint operator*(const APoint& point) const noexcept;

        // 矩阵-向量乘法, M * v。
        NODISCARD AVector operator*(const AVector& vector) const noexcept;

        // 矩阵-矩阵乘法。
        Transform& operator*=(const Transform& transform);

        // 获取齐次矩阵。
        NODISCARD Matrix GetHomogeneousMatrix() const noexcept;

        /// 获取齐次矩阵的逆，当需要时重新计算。
        /// 定义MATHEMATICS_USE_MATRIX_VECTOR
        /// H = {{M,T},{0,1}}, 这里 H^{-1} = {{M^{-1},-M^{-1}*T},{0,1}}。
        /// 未定义MATHEMATICS_USE_MATRIX_VECTOR
        /// H = {{M,0},{T,1}}, 这里 H^{-1} = {{M^{-1},0},{-M^{-1}*T,1}}
        NODISCARD Matrix GetInverseMatrix(Real epsilon = Math::GetZeroTolerance()) const;

        /// 获取Transform的逆。不执行测试来确保调用的转换是可逆的。
        /// Transform逆。如果可能，通道已正确分配。
        /// 例如，如果输入的IsRotationOrScaleMatrix等于 'true'，则逆矩阵的IsRotationOrScaleMatrix也等于'true'，
        /// 并且逆矩阵的旋转矩阵，scale也相应地设置。
        NODISCARD Transform GetInverseTransform(Real epsilon = Math::GetZeroTolerance()) const;

        // 流支持
        NODISCARD int GetStreamingSize() const noexcept;
        void ReadAggregate(BufferSource& source);
        void WriteAggregate(BufferTarget& target) const;

        static constexpr Transform GetIdentityTransform() noexcept
        {
            return Transform{};
        }

    private:
        using TransformMatrix = TransformMatrix<Real>;
        using AffineMatrix = AffineMatrix<Real>;

    private:
        AffineMatrix affineMatrix;
        // 完整的4x4齐次矩阵H = {{M,T},{0,1}}和它的逆矩阵为H^{-1} = {M^{-1},-M^{-1}*T},{0,1}}。 逆矩阵只在需要时计算。
        TransformMatrix transformMatrix;

        mutable Matrix inverseMatrix;
        mutable bool inverseNeedsUpdate;
    };

    template <typename Real>
    NODISCARD Transform<Real> operator*(const Transform<Real>& lhs, const Transform<Real>& rhs);

    template <typename Real>
    NODISCARD bool Approximate(const Transform<Real>& lhs, const Transform<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance());

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& out, const Transform<Real>& transform);

    using TransformF = Transform<float>;
    using TransformD = Transform<double>;
}

#endif  // MATHEMATICS_ALGEBRA_TRANSFORM_H
