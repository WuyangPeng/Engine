///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 16:36)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_H
#define RENDERING_DATA_TYPES_TRANSFORM_H

#include "Rendering/RenderingDll.h"

#include "TransformMatrix.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Rendering
{
    template <typename Real>
    class Transform
    {
    public:
        using ClassType = Transform<Real>;

        using Math = Mathematics::Math<Real>;
        using Matrix = Mathematics::Matrix<Real>;
        using APoint = Mathematics::APoint<Real>;
        using AVector = Mathematics::AVector<Real>;

    public:
        // Transform是 Y = M * X + T，这里M是3x3矩阵和T是一个平移向量。
        // 在大多数情况下，M = R，一个旋转矩阵，或者M = R * S，这里R是一个旋转矩阵和S是一个对角矩阵，其对角元素是正的缩放。
        // 为了支持允许通用仿射变换的建模软件包，M可以是任意可逆的3x3的矩阵。
        // 向量X是在“正”方向下转换为Y，“逆”方向转换Y为X，即在一般情况下X = M^{-1} * (Y - T)。
        // 在特殊情况M = R * S，逆方向是X = S^{-1} * R^t * (Y - T)，这里S^{-1}是对角矩阵，对角元素是S的倒数，和R^t是R的转置。
        // 支持SIMD矩阵与向量和矩阵与矩阵的乘法，此类储存一个齐次矩阵H = {{M,T},{0,1}}。
        // 正转换是{Y,1} = H * {X,1}和逆转换是 {X,1} = H^{-1} * {Y,1}。

        // 默认构造函数产生单位转换。
        Transform() noexcept;

        CLASS_INVARIANT_DECLARE;

        // 设置转换为单位矩阵。
        void MakeIdentity() noexcept;

        // 设置转换的缩放值为1。
        void MakeUnitScale() noexcept(gAssert < 2 || gRenderingAssert < 2);

        // 转换结构的提示。
        NODISCARD bool IsIdentity() const noexcept;  // I
        NODISCARD bool IsRotationOrScaleMatrix() const noexcept;  // R * S
        NODISCARD bool IsUniformScale() const noexcept;  // R * S，S = c * I

        // 成员访问
        // (1) Set* 函数设置IsIdentity提示为false。
        // (2) SetRotate 函数设置IsRotationOrScaleMatrix提示为true。
        //     如果这个提示是false，GetRotate可能会产生一个断言。
        // (3) SetMatrix函数设置IsRotationOrScaleMatrix和IsUniformScale提示为false。
        // (4) SetScale函数设置IsUniformScale提示为false。
        //     SetUniformScale函数设置IsUniformScale提示为true。
        //     如果这个提示是false, GetUniformScale可能会产生一个断言。
        // (5) 所有Set*函数设置m_InverseNeedsUpdate为true。
        //     当GetInverseMatrix被调用，这种情况逆矩阵必须被重新计算，并设置m_InverseNeedsUpdate为false。
        void SetRotate(const Matrix& rotate) noexcept;
        void SetMatrix(const Matrix& matrix) noexcept;
        void SetTranslate(const APoint& aTranslate) noexcept;
        void SetScale(const APoint& aScale) noexcept(gAssert < 2 || gRenderingAssert < 2);
        void SetUniformScale(Real aScale) noexcept(gAssert < 2 || gRenderingAssert < 2);
        NODISCARD Matrix GetRotate() const noexcept(gAssert < 2 || gRenderingAssert < 2);
        NODISCARD Matrix GetMatrix() const noexcept;
        NODISCARD APoint GetTranslate() const noexcept;
        NODISCARD APoint GetScale() const noexcept(gAssert < 2 || gRenderingAssert < 2);
        NODISCARD Real GetUniformScale() const noexcept(gAssert < 2 || gRenderingAssert < 2);

        // 对于M = R * S，S的绝对值的最大值被返回。
        // 对于普通M，返回最大的row绝对值和，这是最大规模的转换的合理测量。
        NODISCARD Real GetNorm() const;

        // 矩阵-点乘法, M * p。
        NODISCARD APoint operator*(const APoint& point) const noexcept;

        // 矩阵-向量乘法, M * v。
        NODISCARD AVector operator*(const AVector& vector) const noexcept;

        // 矩阵-矩阵乘法。
        Transform& operator*=(const Transform& transform);

        // 获取齐次矩阵。
        NODISCARD Matrix GetHomogeneousMatrix() const noexcept;

        // 获取齐次矩阵的逆，当需要时重新计算。
        // H = {{M,T},{0,1}}, 这里 H^{-1} = {{M^{-1},-M^{-1}*T},{0,1}}。
        NODISCARD Matrix GetInverseMatrix(float epsilon = Math::GetZeroTolerance()) const;

        // 获取Transform的逆。不执行测试来确保调用的转换是可逆的。
        NODISCARD Transform GetInverseTransform(float epsilon = Math::GetZeroTolerance()) const;

        // 流支持
        NODISCARD int GetStreamingSize() const noexcept;

        void ReadAggregate(CoreTools::BufferSource& source);
        void WriteAggregate(CoreTools::BufferTarget& target) const;

    private:
        // 完整的4x4齐次矩阵H = {{M,T},{0,1}}和它的逆矩阵为H^{-1} = {M^{-1},-M^{-1}*T},{0,1}}。 逆矩阵只在需要时计算。
        TransformMatrix<Real> transformMatrix;

        Matrix rotationOrGeneralMatrix;  // M (普通) or R (旋转)
        APoint translate;  // T
        APoint scale;  // S

        mutable Matrix inverseMatrix;
        mutable bool inverseNeedsUpdate;
    };

    template <typename Real>
    NODISCARD Transform<Real> operator*(const Transform<Real>& lhs, const Transform<Real>& rhs);

    template <typename Real>
    NODISCARD bool Approximate(const Transform<Real>& lhs, const Transform<Real>& rhs, const Real epsilon = Mathematics::Math<Real>::GetZeroTolerance());

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& out, const Transform<Real>& transform);

    using TransformF = Transform<float>;
    using TransformD = Transform<double>;
}

#endif  // RENDERING_DATA_TYPES_TRANSFORM_H
