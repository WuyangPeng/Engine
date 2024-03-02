/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/05 10:29)

#ifndef MATHEMATICS_ALGEBRA_BOUNDING_SPHERE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_BOUNDING_SPHERE_ACHIEVE_H

#include "BoundingSphere.h"
#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Mathematics/Algebra/TransformDetail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T>
requires std::is_floating_point_v<T>
Mathematics::BoundingSphere<T>::BoundingSphere(const APoint& center, T radius)
    : center{ center }, radius{ radius }
{
    // 半径必须为正数。零半径表示边界无效。
    if (radius < Math::GetValue(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("半径必须为正数"s))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
requires std::is_floating_point_v<T>
bool Mathematics::BoundingSphere<T>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= radius)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
requires std::is_floating_point_v<T>
void Mathematics::BoundingSphere<T>::SetCenter(const APoint& aCenter) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    center = aCenter;
}

template <typename T>
requires std::is_floating_point_v<T>
void Mathematics::BoundingSphere<T>::SetRadius(T aRadius)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (aRadius < Math::GetValue(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("半径必须为正数"s))
    }

    radius = aRadius;
}

template <typename T>
requires std::is_floating_point_v<T>
typename Mathematics::BoundingSphere<T>::APoint Mathematics::BoundingSphere<T>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename T>
requires std::is_floating_point_v<T>
T Mathematics::BoundingSphere<T>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

template <typename T>
requires std::is_floating_point_v<T>
Mathematics::NumericalValueSymbol Mathematics::BoundingSphere<T>::WhichSide(const Plane& plane, T epsilon) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto signedDistance = plane.DistanceTo(center);

    if (signedDistance + epsilon <= -radius)
    {
        return NumericalValueSymbol::Negative;
    }
    else if (radius <= signedDistance - epsilon)
    {
        return NumericalValueSymbol::Positive;
    }
    else
    {
        return NumericalValueSymbol::Zero;
    }
}

template <typename T>
requires std::is_floating_point_v<T>
void Mathematics::BoundingSphere<T>::GrowToContain(const BoundingSphere& bound, T epsilon)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (bound.radius <= epsilon)
    {
        // 输入边界是无效的，不影响增长
        return;
    }

    if (radius <= epsilon)
    {
        // 当前边界是无效的，所以只赋值输入边界
        *this = bound;
        return;
    }

    const auto centerDifference = bound.center - center;
    const auto lengthSquare = centerDifference.SquaredLength();
    const auto radiusDifference = bound.radius - radius;
    const auto radiusDifferenceSquare = radiusDifference * radiusDifference;

    if (lengthSquare <= radiusDifferenceSquare)
    {
        if (Math::GetValue(0) <= radiusDifference)
        {
            center = bound.center;
            radius = bound.radius;
        }

        return;
    }

    const auto length = Math::Sqrt(lengthSquare);
    if (epsilon < length)
    {
        const auto coefficient = (length + radiusDifference) / (Math::GetValue(2) * length);
        center += coefficient * centerDifference;
    }

    radius = Math::GetRational(1, 2) * (length + radius + bound.radius);
}

template <typename T>
requires std::is_floating_point_v<T>
Mathematics::BoundingSphere<T> Mathematics::BoundingSphere<T>::TransformBy(const Transform& transform) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    /// 谱范数（特征值的最大绝对值）小于或等于max-row-sum和max-col-sum的范数。因此，“范数”是最大尺度的近似值。
    BoundingSphere bound{ transform * center, transform.GetNorm() * radius };

    return bound;
}

template <typename T>
requires std::is_floating_point_v<T>
void Mathematics::BoundingSphere<T>::ComputeFromData(int numElements, int stride, SpanConstIterator data)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    APointContainer container{};

    const auto difference = (stride == 0) ? 0 : (stride - CoreTools::GetStreamSize<T>() * APoint::pointSize);

    if (difference < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("步幅值错误。"s))
    }

    for (auto i = 0; i < numElements; ++i)
    {
        // 假设位置偏移0，它们应该为顶点缓冲区数据。
        const auto x = data.Increase<T>();
        const auto y = data.Increase<T>();
        const auto z = data.Increase<T>();

        container.emplace_back(x, y, z);

        data += difference;
    }

    ComputeFromData(container);
}

template <typename T>
requires std::is_floating_point_v<T>
void Mathematics::BoundingSphere<T>::ComputeFromData(const Vector3Container& data)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    APointContainer container{};

    for (const auto& value : data)
    {
        container.emplace_back(value);
    }

    ComputeFromData(container);
}

template <typename T>
requires std::is_floating_point_v<T>
void Mathematics::BoundingSphere<T>::ComputeFromData(const APointContainer& data)
{
    MATHEMATICS_CLASS_IS_VALID_1;

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
requires std::is_floating_point_v<T>
bool Mathematics::BoundingSphere<T>::TestIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

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

template <typename T>
requires std::is_floating_point_v<T>
bool Mathematics::BoundingSphere<T>::TestLineIntersection(const APoint& origin, const AVector& direction, T tMax) const noexcept(gAssert < 2 || gMathematicsAssert < 2)
{
    MATHEMATICS_ASSERTION_2(Math::Approximate(tMax, Math::maxReal), "tMax对线必须是无穷大。\n");

    System::UnusedFunction(tMax);

    // 测试球——直线相交
    const auto pointDifference = origin - center;
    const auto difference = pointDifference.SquaredLength() - radius * radius;
    const auto dot = Dot(direction, pointDifference);
    const auto discriminant = dot * dot - difference;

    return 0.0f <= discriminant;
}

template <typename T>
requires std::is_floating_point_v<T>
bool Mathematics::BoundingSphere<T>::TestRayIntersection(const APoint& origin, const AVector& direction, T tMin) const noexcept(gAssert < 2 || gMathematicsAssert < 2)
{
    MATHEMATICS_ASSERTION_2(Math::Approximate(tMin, Math::GetValue(0)), "tMin在射线中必须是零。\n");

    System::UnusedFunction(tMin);

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

template <typename T>
requires std::is_floating_point_v<T>
bool Mathematics::BoundingSphere<T>::TestSegmentIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const
{
    MATHEMATICS_ASSERTION_1(tMin < tMax, "tmin < tmax在线段中的必需的。\n");

    // 测试球——线段相交

    const auto segmentExtent = Math::GetRational(1, 2) * (tMin + tMax);
    const auto segmentOrigin = origin + segmentExtent * direction;

    const auto pointDifference = segmentOrigin - center;
    auto difference = pointDifference.SquaredLength() - radius * radius;
    if (difference < 0.0f)
    {
        // 线段中心位于球体内部。
        return false;
    }

    auto dot = Dot(direction, pointDifference);
    auto discriminant = dot * dot - difference;
    if (discriminant < 0.0f)
    {
        // 直线在球体之外，这意味着线段也在。
        return false;
    }

    auto absDot = Math::FAbs(dot);
    auto temp = segmentExtent - absDot;

    return temp * temp <= discriminant || absDot <= segmentExtent;

#if 0

    const auto q0 = segmentExtent * segmentExtent + difference;
    const auto q1 = Math::GetValue(2) * dot * segmentExtent;
    const auto qMinus = q0 - q1;
    const auto qPlus = q0 + q1;
    if (qMinus * qPlus <= Math::GetValue(0))
    {
        return true;
    }

    return Math::GetValue(0) < qMinus && Math::FAbs(dot) < segmentExtent;

#endif  // 0
}

template <typename T>
requires std::is_floating_point_v<T>
void Mathematics::BoundingSphere<T>::ReadAggregate(CoreTools::BufferSource& source)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    APoint aCenter{};
    auto aRadius = Math::GetValue(0);

    source.ReadAggregate(aCenter);
    source.Read(aRadius);

    SetCenter(aCenter);
    SetRadius(aRadius);
}

template <typename T>
requires std::is_floating_point_v<T>
void Mathematics::BoundingSphere<T>::WriteAggregate(CoreTools::BufferTarget& target) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    target.WriteAggregate(center);
    target.Write(radius);
}

template <typename T>
requires std::is_floating_point_v<T>
int Mathematics::BoundingSphere<T>::GetStreamingSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Mathematics::GetStreamSize(center) + CoreTools::GetStreamSize(radius);
}

#endif  // MATHEMATICS_ALGEBRA_BOUNDING_SPHERE_ACHIEVE_H
