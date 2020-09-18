//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.1 (2020/08/30 14:22)

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
    // �뾶����Ϊ��������뾶��ʾ�߽���Ч��
    if (m_Radius < Math::GetValue(0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�뾶����Ϊ����"s));
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
        THROW_EXCEPTION(SYSTEM_TEXT("�뾶����Ϊ����"s));
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
        // ����߽�����Ч�ģ���Ӱ������
        return;
    }

    if (m_Radius <= Math::GetZeroTolerance())
    {
        // ��ǰ�߽�����Ч�ģ�����ֻ��ֵ����߽�
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
        THROW_EXCEPTION(SYSTEM_TEXT("����ֵ����"s));
    }

    for (auto i = 0; i < numElements; ++i)
    {
        // ����λ��ƫ��0������Ӧ��Ϊ���㻺�������ݡ�
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

    // �е���λ�õ�ƽ��ֵ
    APoint sum{};
    for (const auto& position : data)
    {
        sum += position;
    }

    m_Center = sum / boost::numeric_cast<T>(data.size());

    // �뾶��λ�õ����ĵ�������
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
        // �߽�����Ч�ģ����ཻ��
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
    RENDERING_ASSERTION_2(Math::Approximate(tMax, Math::sm_MaxReal), "tmax���߱����������\n");

    // �����򡪡�ֱ���ཻ
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
    RENDERING_ASSERTION_2(Math::Approximate(tMin, Math::GetValue(0)), "tmin�������б������㡣\n");

    // �����򡪡������ཻ
    const auto pointDifference = origin - m_Center;
    auto difference = pointDifference.SquaredLength() - m_Radius * m_Radius;
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

// private
template <typename T>
bool Rendering::Bound<T>::TestSegmentIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const
{
    RENDERING_ASSERTION_1(tMin < tMax, "tmin < tmax���߶��еı���ġ�\n");

    // �����򡪡��߶��ཻ

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
