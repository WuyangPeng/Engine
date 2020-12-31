//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/08/30 14:22)

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
#include "Mathematics/Algebra/Vector3D.h"

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
        using Vector3D = Mathematics::Vector3D<T>;
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
            : m_Center{}, m_Radius{}
        {
        }

        CLASS_INVARIANT_DECLARE;

        // 任何边界必须定义一个中心和一个半径。
        void SetCenter(const APoint& center) noexcept;
        void SetRadius(T radius);
        [[nodiscard]] const APoint& GetCenter() const noexcept;
        [[nodiscard]] T GetRadius() const noexcept;

        [[nodiscard]] int GetStreamingSize() const noexcept;

        // 边界上的操作。
        [[nodiscard]] NumericalValueSymbol WhichSide(const Plane& plane) const noexcept;
        void GrowToContain(const Bound& bound);
        [[nodiscard]] const Bound TransformBy(const Transform& transform) const;
        void ComputeFromData(int numElements, int stride, SpanConstIterator data);
        void ComputeFromData(const APointContainer& data);
        void ComputeFromData(const Vector3DContainer& data);

        // 测试线性分量和边界是否相交（不计算交战）。线性分量通过P + t * D进行参数化，
        // 这里P是一个分量上的点（原点），D是一个单位长度向量。间隔[tmin,tmax]是
        // line: tmin = -Mathf::sm_MaxReal, tmax = Mathf::sm_MaxReal
        // ray: tmin = 0.0f, tmax = Mathf::sm_MaxReal
        // segment: tmin >= 0.0f, tmax > tmin
        [[nodiscard]] bool TestIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const;

        void ReadAggregate(CoreTools::BufferSource& source);
        void WriteAggregate(CoreTools::BufferTarget& target) const;

    private:
        [[nodiscard]] bool TestLineIntersection(const APoint& origin, const AVector& direction, T tMax) const noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        [[nodiscard]] bool TestRayIntersection(const APoint& origin, const AVector& direction, T tMin) const noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        [[nodiscard]] bool TestSegmentIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const;

    private:
        APoint m_Center{};
        T m_Radius{};
    };

    // 测试两个固定的边界是否相交。
    template <typename T>
    [[nodiscard]] bool TestIntersection(const Bound<T>& lhsBound, const Bound<T>& rhsBound) noexcept;

    // 测试两个运动的边界是否相交。 lhsVelocity是lhsBound的速度，而rhsVelocity是rhsBound的速度。
    template <typename T>
    [[nodiscard]] bool TestIntersection(const Bound<T>& lhsBound, const Mathematics::AVector<T>& lhsVelocity, const Bound<T>& rhsBound, const Mathematics::AVector<T>& rhsVelocity, float tMax);

    template <typename T>
    [[nodiscard]] bool Approximate(const Bound<T>& lhs, const Bound<T>& rhs, const float epsilon = Mathematics::Math<T>::GetZeroTolerance()) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

    using FloatBound = Bound<float>;
    using DoubleBound = Bound<double>;
}

#endif  // RENDERING_DATA_TYPES_BOUND_H
