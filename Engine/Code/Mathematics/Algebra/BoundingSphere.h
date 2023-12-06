/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/05 10:27)

#ifndef MATHEMATICS_ALGEBRA_BOUNDING_SPHERE_H
#define MATHEMATICS_ALGEBRA_BOUNDING_SPHERE_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Base/SpanIterator.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Plane.h"
#include "Mathematics/Algebra/Transform.h"
#include "Mathematics/Algebra/Vector3.h"

#include <type_traits>

namespace Mathematics
{
    template <typename T>
    requires std::is_floating_point_v<T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BoundingSphere
    {
    public:
        using ClassType = BoundingSphere<T>;

        using Transform = Transform<T>;
        using Math = Math<T>;
        using Plane = Plane<T>;
        using APoint = APoint<T>;
        using AVector = AVector<T>;
        using Vector3 = Vector3<T>;

        using PixelType = std::vector<char>;
        using PixelTypeConstIter = PixelType::const_iterator;
        using SpanConstIterator = CoreTools::SpanIterator<PixelTypeConstIter>;

        using APointContainer = std::vector<APoint>;
        using Vector3Container = std::vector<Vector3>;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        // 默认构造函数将中心设置为原点(0,0,0)，将半径设置为0。半径为0表示边界无效。
        constexpr BoundingSphere() noexcept
            : center{}, radius{}
        {
        }

        // 边界指定为一个指定中心和半径的球体。
        BoundingSphere(const APoint& center, T radius);

        CLASS_INVARIANT_DECLARE;

        // 任何边界必须定义一个中心和一个半径，半径必须是非负的。
        void SetCenter(const APoint& aCenter) noexcept;
        void SetRadius(T aRadius);
        NODISCARD APoint GetCenter() const noexcept;
        NODISCARD T GetRadius() const noexcept;

        /// 边界上的操作。

        /// 平面的“正面”是平面法线指向的半空间。“反面”是另一半空间。
        /// 当球体完全位于正侧时，函数返回NumericalValueSymbol::Positive，
        /// 当球体完全处于负侧时返回NumericalValueSymbol::Negative，
        /// 当球体被平面横向切割时返回NumericalValueSymbol::Zero（平面两侧的球体体积均为正）。
        /// epsilon为偏向完全切割的误差，如果要偏向正反面，epsilon传入负数。
        NODISCARD NumericalValueSymbol WhichSide(const Plane& plane, T epsilon = Math::GetZeroTolerance()) const noexcept;

        /// 增加 'this' 以包含输入球体。
        void GrowToContain(const BoundingSphere& bound, T epsilon = Math::GetZeroTolerance());

        /// 变换球体。如果变换具有不均匀缩放，则生成的对象为椭球体。将生成一个包含椭球体的球体。
        NODISCARD BoundingSphere TransformBy(const Transform& transform) const;

        /// 此函数仅适用于3通道点 (x,y,z)或4通道矢量 (x,y,z,0)或4通道点(x,y,z,1)。
        /// 在所有情况下，函数都只访问(x,y,z) 个值。stride允许您传入顶点缓冲区数据。
        /// 当点在内存中连续时，将stride设置为零。“data”指针必须指向第一个点（偏移量0）。
        void ComputeFromData(int numElements, int stride, SpanConstIterator data);
        void ComputeFromData(const APointContainer& data);
        void ComputeFromData(const Vector3Container& data);

        // 测试线性分量和边界是否相交（不计算交战）。线性分量通过P + t * D进行参数化，
        // 这里P是一个分量上的点（原点），D是一个单位长度向量。间隔[tMin,tMax]是
        // line: tMin = -MathF::maxReal, tMax = MathF::maxReal
        // ray: tMin = 0.0f, tMax = MathF::maxReal
        // segment: tMin >= 0.0f, tMax > tMin
        NODISCARD bool TestIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const;

        NODISCARD int GetStreamingSize() const noexcept;
        void ReadAggregate(BufferSource& source);
        void WriteAggregate(BufferTarget& target) const;

    private:
        NODISCARD bool TestLineIntersection(const APoint& origin, const AVector& direction, T tMax) const noexcept(gAssert < 2 || gMathematicsAssert < 2);
        NODISCARD bool TestRayIntersection(const APoint& origin, const AVector& direction, T tMin) const noexcept(gAssert < 2 || gMathematicsAssert < 2);
        NODISCARD bool TestSegmentIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const;

    private:
        APoint center{};
        T radius{};
    };

    /// 测试两个固定的边界是否相交。
    /// epsilon为相交的误差，如果要偏向不相交，epsilon传入负数。
    template <typename T>
    NODISCARD bool TestIntersection(const BoundingSphere<T>& lhsBound, const BoundingSphere<T>& rhsBound, T epsilon = Math<T>::GetZeroTolerance()) noexcept;

    // 测试两个运动的边界是否相交。 lhsVelocity是lhsBound的速度，而rhsVelocity是rhsBound的速度。
    template <typename T>
    NODISCARD bool TestIntersection(const BoundingSphere<T>& lhsBound, const AVector<T>& lhsVelocity, const BoundingSphere<T>& rhsBound, const AVector<T>& rhsVelocity, T tMax);

    template <typename T>
    NODISCARD bool Approximate(const BoundingSphere<T>& lhs, const BoundingSphere<T>& rhs, T epsilon = Math<T>::GetZeroTolerance());

    using BoundingSphereF = BoundingSphere<float>;
    using BoundingSphereD = BoundingSphere<double>;
}

#endif  // MATHEMATICS_ALGEBRA_BOUNDING_SPHERE_H
