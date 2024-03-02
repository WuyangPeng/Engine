/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/12/05 10:29)

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
    // �뾶����Ϊ��������뾶��ʾ�߽���Ч��
    if (radius < Math::GetValue(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�뾶����Ϊ����"s))
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
        THROW_EXCEPTION(SYSTEM_TEXT("�뾶����Ϊ����"s))
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
        // ����߽�����Ч�ģ���Ӱ������
        return;
    }

    if (radius <= epsilon)
    {
        // ��ǰ�߽�����Ч�ģ�����ֻ��ֵ����߽�
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

    /// �׷���������ֵ��������ֵ��С�ڻ����max-row-sum��max-col-sum�ķ�������ˣ��������������߶ȵĽ���ֵ��
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
        THROW_EXCEPTION(SYSTEM_TEXT("����ֵ����"s))
    }

    for (auto i = 0; i < numElements; ++i)
    {
        // ����λ��ƫ��0������Ӧ��Ϊ���㻺�������ݡ�
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

    // �е���λ�õ�ƽ��ֵ
    APoint sum{};
    for (const auto& position : data)
    {
        sum += position;
    }

    center = sum / boost::numeric_cast<T>(data.size());

    // �뾶��λ�õ����ĵ�������
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
        // �߽�����Ч�ģ����ཻ��
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
    MATHEMATICS_ASSERTION_2(Math::Approximate(tMax, Math::maxReal), "tMax���߱����������\n");

    System::UnusedFunction(tMax);

    // �����򡪡�ֱ���ཻ
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
    MATHEMATICS_ASSERTION_2(Math::Approximate(tMin, Math::GetValue(0)), "tMin�������б������㡣\n");

    System::UnusedFunction(tMin);

    // �����򡪡������ཻ
    const auto pointDifference = origin - center;
    auto difference = pointDifference.SquaredLength() - radius * radius;
    if (difference <= 0.0f)
    {
        // ����ԭ�������ڲ�
        return true;
    }
    else
    {
        // ����ԭ�������ⲿ
        auto dot = Dot(direction, pointDifference);
        if (0.0f <= dot)
        {
            // ������pointDifference�γ�һ����ǣ���������Ǵ����������
            // ��ˣ�����ԭ���������ⲿ����P + t * D����t > = 0Զ�����档
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
    MATHEMATICS_ASSERTION_1(tMin < tMax, "tmin < tmax���߶��еı���ġ�\n");

    // �����򡪡��߶��ཻ

    const auto segmentExtent = Math::GetRational(1, 2) * (tMin + tMax);
    const auto segmentOrigin = origin + segmentExtent * direction;

    const auto pointDifference = segmentOrigin - center;
    auto difference = pointDifference.SquaredLength() - radius * radius;
    if (difference < 0.0f)
    {
        // �߶�����λ�������ڲ���
        return false;
    }

    auto dot = Dot(direction, pointDifference);
    auto discriminant = dot * dot - difference;
    if (discriminant < 0.0f)
    {
        // ֱ��������֮�⣬����ζ���߶�Ҳ�ڡ�
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
