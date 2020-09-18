//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/08/30 14:22)

#ifndef RENDERING_DATA_TYPES_BOUND_ACHIEVE_H
#define RENDERING_DATA_TYPES_BOUND_ACHIEVE_H

#include "Bound.h"
#include "Transform.h"
#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T>
Rendering::Bound<T>::Bound(const APoint& center, T radius)
    : m_Center{ center }, m_Radius{ radius }
{
    // 半径必须为正数。零半径表示边界无效。
    if (m_Radius < Math::GetValue(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("半径必须为正数"s));
    }

    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Rendering::Bound<T>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= m_Radius)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
void Rendering::Bound<T>::SetCenter(const APoint& center) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    m_Center = center;
}

template <typename T>
void Rendering::Bound<T>::SetRadius(T radius)
{
    RENDERING_CLASS_IS_VALID_1;

    if (radius < Math::GetValue(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("半径必须为正数"s));
    }

    m_Radius = radius;
}

template <typename T>
const typename Rendering::Bound<T>::APoint& Rendering::Bound<T>::GetCenter() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename T>
T Rendering::Bound<T>::GetRadius() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Radius;
}

template <typename T>
int Rendering::Bound<T>::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return MATHEMATICS_STREAM_SIZE(m_Center) + CORE_TOOLS_STREAM_SIZE(m_Radius);
}

template <typename T>
typename Rendering::Bound<T>::NumericalValueSymbol Rendering::Bound<T>::WhichSide(const Plane& plane) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto signedDistance = plane.DistanceTo(m_Center);
    const auto difference = signedDistance - m_Radius;

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

    if (bound.m_Radius <= Math::GetZeroTolerance())
    {
        // 输入边界是无效的，不影响增长
        return;
    }

    if (m_Radius <= Math::GetZeroTolerance())
    {
        // 当前边界是无效的，所以只赋值输入边界
        *this = bound;
        return;
    }

    const auto centerDifference = bound.m_Center - m_Center;
    auto lengthSqruared = centerDifference.SquaredLength();
    const auto radiusDifference = bound.m_Radius - m_Radius;
    const auto radiusDifferenceSqruared = radiusDifference * radiusDifference;

    if (lengthSqruared <= radiusDifferenceSqruared)
    {
        if (Math::GetValue(0) <= radiusDifference)
        {
            m_Center = bound.m_Center;
            m_Radius = bound.m_Radius;
        }

        return;
    }

    auto length = Math::Sqrt(lengthSqruared);
    if (Math::GetZeroTolerance() < length)
    {
        auto coefficient = (length + radiusDifference) / (Math::GetValue(2) * length);
        m_Center += coefficient * centerDifference;
    }

    m_Radius = Math::GetRational(1, 2) * (length + m_Radius + bound.m_Radius);
}

template <typename T>
const Rendering::Bound<T> Rendering::Bound<T>::TransformBy(const Transform& transform) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    Bound<T> bound{ transform * m_Center, transform.GetNorm() * m_Radius };

    return bound;
}

template <typename T>
void Rendering::Bound<T>::ComputeFromData(int numElements, int stride, SpanConstIterator data)
{
    RENDERING_CLASS_IS_VALID_1;

    std::vector<APoint> aPoint{};

    const auto difference = stride - CORE_TOOLS_STREAM_SIZE(m_Radius) * APoint::sm_APointSize;

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

    std::vector<APoint> aPoint;

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

    m_Center = sum / boost::numeric_cast<T>(data.size());

    // 半径是位置到中心的最大距离
    auto maxRadiusSquared = Math::GetValue(0);
    for (const auto& position : data)
    {
        const auto difference = position - m_Center;

        auto radiusSquared = difference.SquaredLength();

        if (maxRadiusSquared < radiusSquared)
        {
            maxRadiusSquared = radiusSquared;
        }
    }

    m_Radius = Math::Sqrt(maxRadiusSquared);
}

template <typename T>
bool Rendering::Bound<T>::TestIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (m_Radius <= Math::GetZeroTolerance())
    {
        // 边界是无效的，不相交。
        return false;
    }

    if (Math::Approximate(tMin, -Math::sm_MaxReal))
    {
        return TestLineIntersection(origin, direction, tMax);
    }

    if (Math::Approximate(tMax, Math::sm_MaxReal))
    {
        return TestRayIntersection(origin, direction, tMin);
    }

    return TestSegmentIntersection(origin, direction, tMin, tMax);
}

// private
template <typename T>
bool Rendering::Bound<T>::TestLineIntersection(const APoint& origin, const AVector& direction, [[maybe_unused]] T tMax) const noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_ASSERTION_2(Math::Approximate(tMax, Math::sm_MaxReal), "tmax对线必须是无穷大。\n");

    // 测试球——直线相交
    const auto pointDifference = origin - m_Center;
    auto difference = pointDifference.SquaredLength() - m_Radius * m_Radius;
    auto dot = Dot(direction, pointDifference);
    auto discriminant = dot * dot - difference;

    return 0.0f <= discriminant;
}

// private
template <typename T>
bool Rendering::Bound<T>::TestRayIntersection(const APoint& origin, const AVector& direction, [[maybe_unused]] T tMin) const noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_ASSERTION_2(Math::Approximate(tMin, Math::GetValue(0)), "tmin在射线中必须是零。\n");

    // 测试球——射线相交
    const auto pointDifference = origin - m_Center;
    auto difference = pointDifference.SquaredLength() - m_Radius * m_Radius;
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

    const auto pointDifference = segmentOrigin - m_Center;
    auto difference = pointDifference.SquaredLength() - m_Radius * m_Radius;
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

    APoint center{};
    auto radius = Math::GetValue(0);

    source.ReadAggregate(center);
    source.Read(radius);

    SetCenter(center);
    SetRadius(radius);
}

template <typename T>
void Rendering::Bound<T>::WriteAggregate(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteAggregate(GetCenter());
    target.Write(GetRadius());
}

#endif  // RENDERING_DATA_TYPES_BOUND_ACHIEVE_H
