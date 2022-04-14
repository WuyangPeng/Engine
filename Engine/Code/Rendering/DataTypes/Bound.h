///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 16:18)

#ifndef RENDERING_DATA_TYPES_BOUND_H
#define RENDERING_DATA_TYPES_BOUND_H

#include "Rendering/RenderingDll.h"

#include "Transform.h"
#include "CoreTools/Base/SpanIterator.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Plane.h"
#include "Mathematics/Algebra/Vector3.h"

#include <type_traits>

namespace Rendering
{
    template <typename T>
    class RENDERING_TEMPLATE_DEFAULT_DECLARE Bound
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = Bound<T>;
        using Transform = Transform<T>;
        using Math = Mathematics::Math<T>;
        using Plane = Mathematics::Plane<T>;
        using APoint = Mathematics::APoint<T>;
        using AVector = Mathematics::AVector<T>;
        using Vector3D = Mathematics::Vector3<T>;
        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;

        using PixelType = std::vector<char>;
        using PixelTypeConstIter = PixelType::const_iterator;
        using SpanConstIterator = CoreTools::SpanIterator<PixelTypeConstIter>;

        using APointContainer = std::vector<APoint>;
        using Vector3DContainer = std::vector<Vector3D>;

    public:
        // 边界指定为一个指定中心和半径的球体。
        Bound(const APoint& center, T radius);

        constexpr Bound() noexcept
            : center{}, radius{}
        {
        }

        CLASS_INVARIANT_DECLARE;

        // 任何边界必须定义一个中心和一个半径。
        void SetCenter(const APoint& newCenter) noexcept;
        void SetRadius(T mewRadius);
        NODISCARD const APoint& GetCenter() const noexcept;
        NODISCARD T GetRadius() const noexcept;

        NODISCARD int GetStreamingSize() const noexcept;

        // 边界上的操作。
        NODISCARD NumericalValueSymbol WhichSide(const Plane& plane) const noexcept;
        void GrowToContain(const Bound& bound);
        NODISCARD const Bound TransformBy(const Transform& transform) const;
        void ComputeFromData(int numElements, int stride, SpanConstIterator data);
        void ComputeFromData(const APointContainer& data);
        void ComputeFromData(const Vector3DContainer& data);

        // 测试线性分量和边界是否相交（不计算交战）。线性分量通过P + t * D进行参数化，
        // 这里P是一个分量上的点（原点），D是一个单位长度向量。间隔[tmin,tmax]是
        // line: tmin = -Mathf::maxReal, tmax = Mathf::maxReal
        // ray: tmin = 0.0f, tmax = Mathf::maxReal
        // segment: tmin >= 0.0f, tmax > tmin
        NODISCARD bool TestIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const;

        void ReadAggregate(CoreTools::BufferSource& source);
        void WriteAggregate(CoreTools::BufferTarget& target) const;

    private:
        NODISCARD bool TestLineIntersection(const APoint& origin, const AVector& direction, T tMax) const noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        NODISCARD bool TestRayIntersection(const APoint& origin, const AVector& direction, T tMin) const noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        NODISCARD bool TestSegmentIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const;

    private:
        APoint center{};
        T radius{};
    };

    // 测试两个固定的边界是否相交。
    template <typename T>
    NODISCARD bool TestIntersection(const Bound<T>& lhsBound, const Bound<T>& rhsBound) noexcept;

    // 测试两个运动的边界是否相交。 lhsVelocity是lhsBound的速度，而rhsVelocity是rhsBound的速度。
    template <typename T>
    NODISCARD bool TestIntersection(const Bound<T>& lhsBound, const Mathematics::AVector<T>& lhsVelocity, const Bound<T>& rhsBound, const Mathematics::AVector<T>& rhsVelocity, float tMax);

    template <typename T>
    NODISCARD bool Approximate(const Bound<T>& lhs, const Bound<T>& rhs, const float epsilon = Mathematics::Math<T>::GetZeroTolerance()) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

    using BoundF = Bound<float>;
    using BoundD = Bound<double>;
}

#endif  // RENDERING_DATA_TYPES_BOUND_H
