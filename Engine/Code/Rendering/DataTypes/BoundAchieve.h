///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 16:21)

#ifndef RENDERING_DATA_TYPES_BOUND_ACHIEVE_H
#define RENDERING_DATA_TYPES_BOUND_ACHIEVE_H

#include "Bound.h"
#include "TransformDetail.h"
#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T>
Rendering::Bound<T>::Bound(const APoint& center, T radius)
    : center{ center }, radius{ radius }
{
    // 半径必须为正数。零半径表示边界无效。
    if (radius < Math::GetValue(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("半径必须为正数"s));
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Rendering::Bound<T>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= radius)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
void Rendering::Bound<T>::SetCenter(const APoint& newCenter) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    center = newCenter;
}

template <typename T>
void Rendering::Bound<T>::SetRadius(T mewRadius)
{
    RENDERING_CLASS_IS_VALID_1;

    if (mewRadius < Math::GetValue(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("半径必须为正数"s));
    }

    radius = mewRadius;
}

template <typename T>
const typename Rendering::Bound<T>::APoint& Rendering::Bound<T>::GetCenter() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename T>
T Rendering::Bound<T>::GetRadius() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return radius;
}

template <typename T>
int Rendering::Bound<T>::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Mathematics::GetStreamSize(center) + CoreTools::GetStreamSize(radius);
}

template <typename T>
typename Rendering::Bound<T>::NumericalValueSymbol Rendering::Bound<T>::WhichSide(const Plane& plane) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto signedDistance = plane.DistanceTo(center);
    const auto difference = signedDistance - radius;

    if (difference < -Math::GetZeroTolerance())
    {
        return Mathematics::NumericalValueSymbol::Negative;
    }
    else if (Math::GetZeroTolerance() < difference)
    {
        return Mathematics::NumericalValueSymbol::Positive;
    }
    else
    {
        return Mathematics::NumericalValueSymbol::Zero;
    }
}

template <typename T>
void Rendering::Bound<T>::GrowToContain(const Bound<T>& bound)
{
    RENDERING_CLASS_IS_VALID_1;

    if (bound.radius <= Math::GetZeroTolerance())
    {
        // 输入边界是无效的，不影响增长
        return;
    }

    if (radius <= Math::GetZeroTolerance())
    {
        // 当前边界是无效的，所以只赋值输入边界
        *this = bound;
        return;
    }

    const auto centerDifference = bound.center - center;
    const auto lengthSqruared = centerDifference.SquaredLength();
    const auto radiusDifference = bound.radius - radius;
    const auto radiusDifferenceSqruared = radiusDifference * radiusDifference;

    if (lengthSqruared <= radiusDifferenceSqruared)
    {
        if (Math::GetValue(0) <= radiusDifference)
        {
            center = bound.center;
            radius = bound.radius;
        }

        return;
    }

    const auto length = Math::Sqrt(lengthSqruared);
    if (Math::GetZeroTolerance() < length)
    {
        const auto coefficient = (length + radiusDifference) / (Math::GetValue(2) * length);
        center += coefficient * centerDifference;
    }

    radius = Math::GetRational(1, 2) * (length + radius + bound.radius);
}

template <typename T>
const Rendering::Bound<T> Rendering::Bound<T>::TransformBy(const Transform& transform) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    Bound<T> bound{ transform * center, transform.GetNorm() * radius };

    return bound;
}

template <typename T>
void Rendering::Bound<T>::ComputeFromData(int numElements, int stride, SpanConstIterator data)
{
    RENDERING_CLASS_IS_VALID_1;

    std::vector<APoint> aPoint{};

    const auto difference = stride - CoreTools::GetStreamSize(radius) * APoint::pointSize;

    if (difference < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("步幅值错误。"s));
    }

    for (auto i = 0; i < numElements; ++i)
    {
        // 假设位置偏移0，它们应该为顶点缓冲区数据。
        auto x = data.Increase<T>();
        auto y = data.Increase<T>();
        auto z = data.Increase<T>();

        aPoint.emplace_back(x, y, z);

        data += difference;
    }

    ComputeFromData(aPoint);
}

template <typename T>
void Rendering::Bound<T>::ComputeFromData(const Vector3DContainer& data)
{
    RENDERING_CLASS_IS_VALID_1;

    std::vector<APoint> aPoint{};

    for (const auto& value : data)
    {
        aPoint.emplace_back(value);
    }

    ComputeFromData(aPoint);
}

template <typename T>
void Rendering::Bound<T>::ComputeFromData(const APointContainer& data)
{
    RENDERING_CLASS_IS_VALID_1;

    // 中点是位置的平均值
    APoint sum{};
    for (const auto& position : data)
    {
        sum += position;
    }

    center = sum / boost::numeric_cast<T>(data.size());

    // 半径是位置到中心的最大距离
    auto maxRadiusSquared = Math::GetValue(0);
    for (const auto& position : data)
    {
        const auto difference = position - center;

        auto radiusSquared = difference.SquaredLength();

        if (maxRadiusSquared < radiusSquared)
        {
            maxRadiusSquared = radiusSquared;
        }
    }

    radius = Math::Sqrt(maxRadiusSquared);
}

template <typename T>
bool Rendering::Bound<T>::TestIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (radius <= Math::GetZeroTolerance())
    {
        // 边界是无效的，不相交。
        return false;
    }

    if (Math::Approximate(tMin, -Math::maxReal))
    {
        return TestLineIntersection(origin, direction, tMax);
    }

    if (Math::Approximate(tMax, Math::maxReal))
    {
        return TestRayIntersection(origin, direction, tMin);
    }

    return TestSegmentIntersection(origin, direction, tMin, tMax);
}

// private
template <typename T>
bool Rendering::Bound<T>::TestLineIntersection(const APoint& origin, const AVector& direction, [[maybe_unused]] T tMax) const noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    RENDERING_ASSERTION_2(Math::Approximate(tMax, Math::maxReal), "tmax对线必须是无穷大。\n");

    // 测试球——直线相交
    const auto pointDifference = origin - center;
    const auto difference = pointDifference.SquaredLength() - radius * radius;
    const auto dot = Dot(direction, pointDifference);
    const auto discriminant = dot * dot - difference;

    return 0.0f <= discriminant;
}

// private
template <typename T>
bool Rendering::Bound<T>::TestRayIntersection(const APoint& origin, const AVector& direction, [[maybe_unused]] T tMin) const noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    RENDERING_ASSERTION_2(Math::Approximate(tMin, Math::GetValue(0)), "tmin在射线中必须是零。\n");

    // 测试球——射线相交
    const auto pointDifference = origin - center;
    auto difference = pointDifference.SquaredLength() - radius * radius;
    if (difference <= 0.0f)
    {
        // 射线原点在球内部
        return true;
    }
    else
    {
        // 射线原点在球外部
        auto dot = Dot(direction, pointDifference);
        if (0.0f <= dot)
        {
            // 射线与pointDifference形成一个锐角，因此射线是从球体射出。
            // 因此，射线原点在球体外部，点P + t * D对于t > = 0远离球面。
            return false;
        }

        auto discriminant = dot * dot - difference;
        return 0.0f <= discriminant;
    }
}

// private
template <typename T>
bool Rendering::Bound<T>::TestSegmentIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const
{
    RENDERING_ASSERTION_1(tMin < tMax, "tmin < tmax在线段中的必需的。\n");

    // 测试球——线段相交

    const auto segmentExtent = Math::GetRational(1, 2) * (tMin + tMax);
    const auto segmentOrigin = origin + segmentExtent * direction;

    const auto pointDifference = segmentOrigin - center;
    auto difference = pointDifference.SquaredLength() - radius * radius;
    auto dot = Dot(direction, pointDifference);
    auto discriminant = dot * dot - difference;
    if (discriminant < 0.0f)
    {
        return false;
    }

    const auto q0 = segmentExtent * segmentExtent + difference;
    const auto q1 = Math::GetValue(2) * dot * segmentExtent;
    const auto qMinus = q0 - q1;
    const auto qPlus = q0 + q1;
    if (qMinus * qPlus <= Math::GetValue(0))
    {
        return true;
    }

    return Math::GetValue(0) < qMinus && Math::FAbs(dot) < segmentExtent;
}

template <typename T>
void Rendering::Bound<T>::ReadAggregate(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    APoint aCenter{};
    auto aRadius = Math::GetValue(0);

    source.ReadAggregate(aCenter);
    source.Read(aRadius);

    SetCenter(aCenter);
    SetRadius(aRadius);
}

template <typename T>
void Rendering::Bound<T>::WriteAggregate(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteAggregate(GetCenter());
    target.Write(GetRadius());
}

#endif  // RENDERING_DATA_TYPES_BOUND_ACHIEVE_H
