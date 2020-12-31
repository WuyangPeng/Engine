//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/09/06 10:46)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_H
#define RENDERING_DATA_TYPES_TRANSFORM_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Rendering
{
    template <typename Real>
    class TransformImpl;

    template class RENDERING_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<TransformImpl<float>>;
    template class RENDERING_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<TransformImpl<double>>;

    template <typename Real>
    class RENDERING_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<TransformImpl<Real>>;
}

namespace Rendering
{
    template <typename Real>
    class RENDERING_TEMPLATE_DEFAULT_DECLARE Transform
    {
    public:
        using ClassType = Transform<Real>;
        using ImplType = TransformImpl<Real>;
        using ClassShareType = CoreTools::DelayCopyUnsharedClasses;

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
        Transform();

        CLASS_INVARIANT_DECLARE;

        // 设置转换为单位矩阵。
        void MakeIdentity();

        // 设置转换的缩放值为1。
        void MakeUnitScale();

        // 转换结构的提示。
        [[nodiscard]] bool IsIdentity() const noexcept;  // I
        [[nodiscard]] bool IsRotationOrScaleMatrix() const noexcept;  // R * S
        [[nodiscard]] bool IsUniformScale() const noexcept;  // R * S，S = c * I

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
        void SetRotate(const Matrix& rotate);
        void SetMatrix(const Matrix& matrix);
        void SetTranslate(const APoint& translate);
        void SetScale(const APoint& scale);
        void SetUniformScale(Real scale);
        [[nodiscard]] const Matrix GetRotate() const noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        [[nodiscard]] const Matrix GetMatrix() const noexcept;
        [[nodiscard]] const APoint GetTranslate() const noexcept;
        [[nodiscard]] const APoint GetScale() const noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        [[nodiscard]] Real GetUniformScale() const noexcept(g_Assert < 2 || g_RenderingAssert < 2);

        // 对于M = R * S，S的绝对值的最大值被返回。
        // 对于普通M，返回最大的row绝对值和，这是最大规模的转换的合理测量。
        [[nodiscard]] Real GetNorm() const noexcept;

        // 矩阵-点乘法, M * p。
        [[nodiscard]] APoint operator*(const APoint& point) const noexcept;

        // 矩阵-向量乘法, M * v。
        [[nodiscard]] AVector operator*(const AVector& vector) const noexcept;

        // 矩阵-矩阵乘法。
        Transform& operator*=(const Transform& transform);

        // 获取齐次矩阵。
        [[nodiscard]] const Matrix GetHomogeneousMatrix() const noexcept;

        // 获取齐次矩阵的逆，当需要时重新计算。
        // H = {{M,T},{0,1}}, 这里 H^{-1} = {{M^{-1},-M^{-1}*T},{0,1}}。
        [[nodiscard]] const Matrix GetInverseMatrix(float epsilon = Math::GetZeroTolerance()) const;

        // 获取Transform的逆。不执行测试来确保调用的转换是可逆的。
        [[nodiscard]] const Transform GetInverseTransform(float epsilon = Math::GetZeroTolerance()) const;

        // 流支持
        [[nodiscard]] int GetStreamingSize() const noexcept;

        void ReadAggregate(CoreTools::BufferSource& source);
        void WriteAggregate(CoreTools::BufferTarget& target) const;

    private:
        void Copy();

    private:
        IMPL_TYPE_DECLARE(Transform);
    };

    template <typename Real>
    const Transform<Real> operator*(const Transform<Real>& lhs, const Transform<Real>& rhs);

    template <typename Real>
    bool Approximate(const Transform<Real>& lhs, const Transform<Real>& rhs, const Real epsilon = Mathematics::Math<Real>::GetZeroTolerance());

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& out, const Transform<Real>& transform);

    using FloatTransform = Transform<float>;
    using DoubleTransform = Transform<double>;
}

#endif  // RENDERING_DATA_TYPES_TRANSFORM_H
