// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/18 14:07)

#include "Rendering/RenderingExport.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "BoundImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/Flags/MatrixFlags.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Base/MathDetail.h"

using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
Rendering::BoundImpl ::BoundImpl(const APoint& center, float radius) noexcept
    : m_Center{ center }, m_Radius{ radius }
{
    // 半径必须为正数。零半径表示边界无效。

    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::BoundImpl ::IsValid() const noexcept
{
    if (0.0f <= m_Radius)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void Rendering::BoundImpl ::SetCenter(const APoint& center) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    m_Center = center;
}

void Rendering::BoundImpl ::SetRadius(float radius) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    m_Radius = radius;
}

const Rendering::BoundImpl::APoint& Rendering::BoundImpl ::GetCenter() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

float Rendering::BoundImpl ::GetRadius() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Radius;
}

int Rendering::BoundImpl ::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return MATHEMATICS_STREAM_SIZE(m_Center) + CORE_TOOLS_STREAM_SIZE(m_Radius);
}

Rendering::BoundImpl::NumericalValueSymbol Rendering::BoundImpl ::WhichSide(const Plane& plane) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto signedDistance = plane.DistanceTo(m_Center);

    if (signedDistance <= -m_Radius)
    {
        return Mathematics::NumericalValueSymbol::Negative;
    }

    if (m_Radius <= signedDistance)
    {
        return Mathematics::NumericalValueSymbol::Positive;
    }

    return Mathematics::NumericalValueSymbol::Zero;
}

void Rendering::BoundImpl ::GrowToContain(const BoundImpl& bound)
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

    auto centerDifference = bound.m_Center - m_Center;
    auto lengthSqruared = centerDifference.SquaredLength();
    const auto radiusDifference = bound.m_Radius - m_Radius;
    const auto radiusDifferenceSqruared = radiusDifference * radiusDifference;

    if (lengthSqruared <= radiusDifferenceSqruared)
    {
        if (0.0f <= radiusDifference)
        {
            m_Center = bound.m_Center;
            m_Radius = bound.m_Radius;
        }

        return;
    }

    auto length = Math::Sqrt(lengthSqruared);
    if (Math::GetZeroTolerance() < length)
    {
        auto coefficient = (length + radiusDifference) / (2.0f * length);
        m_Center += coefficient * centerDifference;
    }

    m_Radius = 0.5f * (length + m_Radius + bound.m_Radius);
}

const Rendering::BoundImpl Rendering::BoundImpl ::TransformBy(const Transform& transform) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    BoundImpl bound{ transform * m_Center, transform.GetNorm() * m_Radius };

    return bound;
}

void Rendering::BoundImpl ::ComputeFromData(int numElements, int stride, const char* data)
{
    RENDERING_CLASS_IS_VALID_1;

    vector<APoint> aPoint;

    for (auto i = 0; i < numElements; ++i)
    {
        // 假设位置偏移0，它们应该为顶点缓冲区数据。
        auto position = reinterpret_cast<const float*>(data + i * stride);
        auto firstPosition = position[0];
        auto secondPosition = position[1];
        auto thirdPosition = position[2];

        aPoint.emplace_back(firstPosition, secondPosition, thirdPosition);
    }

    ComputeFromData(aPoint);
}

void Rendering::BoundImpl ::ComputeFromData(const vector<APoint>& data)
{
    RENDERING_CLASS_IS_VALID_1;

    // 中点是位置的平均值
    APoint sum{ 0.0f, 0.0f, 0.0f };
    for (auto i = 0u; i < data.size(); ++i)
    {
        // 假设位置偏移0，它们应该为顶点缓冲区数据。
        const auto& position = data[i];
        sum[0] += position[0];
        sum[1] += position[1];
        sum[2] += position[2];
    }

    m_Center = sum / boost::numeric_cast<float>(data.size());

    // 半径是位置到中心的最大距离
    m_Radius = 0.0f;
    for (auto i = 0u; i < data.size(); ++i)
    {
        // 假设位置偏移0，它们应该为顶点缓冲区数据。
        const auto& position = data[i];
        AVector difference{ position[0] - m_Center[0], position[1] - m_Center[1], position[2] - m_Center[2] };

        auto radiusSquared = difference.SquaredLength();

        if (m_Radius < radiusSquared)
        {
            m_Radius = radiusSquared;
        }
    }

    m_Radius = Math::Sqrt(m_Radius);
}

void Rendering::BoundImpl ::ComputeFromData(const std::vector<Vector3D>& data)
{
    RENDERING_CLASS_IS_VALID_1;

    vector<APoint> aPoint;

    for (auto i = 0u; i < data.size(); ++i)
    {
        aPoint.emplace_back(data[i]);
    }

    ComputeFromData(aPoint);
}

bool Rendering::BoundImpl ::TestIntersection(const APoint& origin, const AVector& direction, float tmin, float tmax) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (m_Radius <= Math::GetZeroTolerance())
    {
        // 边界是无效的，不相交。
        return false;
    }

    if (Math::Approximate(tmin, -Math::sm_MaxReal, 1e-8f))
    {
        RENDERING_ASSERTION_1(Math::Approximate(Math::sm_MaxReal, tmax, 1e-8f), "tmax对线必须是无穷大。\n");

        // 测试球-直线相交
        auto difference = origin - m_Center;
        auto a = difference.SquaredLength() - m_Radius * m_Radius;
        auto dot = Dot(direction, difference);
        auto discr = dot * dot - a;

        return 0.0f <= discr;
    }

    if (Math::Approximate(Math::sm_MaxReal, tmax, 1e-8f))
    {
        RENDERING_ASSERTION_1(Math::Approximate(tmin, 0.0f, 1e-8f), "tmin在射线中必须是零。\n");

        // 测试球-射线相交
        auto difference = origin - m_Center;
        auto a = difference.SquaredLength() - m_Radius * m_Radius;
        if (a <= 0.0f)
        {
            // 射线原点在球内部
            return true;
        }
        else
        {
            // 射线原点在球外部
            auto dot = Dot(direction, difference);
            if (0.0f <= dot)
            {
                // 射线与difference形成一个锐角,射线是从球体指向。
                // 因此,射线原点在球体外部,点P + t * D对t > = 0远离球面。
                return false;
            }

            auto discr = dot * dot - a;
            return 0.0f <= discr;
        }
    }

    RENDERING_ASSERTION_1(tmin < tmax, "tmin < tmax在线段中的必需的。\n");

    // 测试球-线段相交
    const auto segmentExtent = 0.5f * (tmin + tmax);
    auto segmentOrigin = origin + segmentExtent * direction;

    auto difference = segmentOrigin - m_Center;
    auto a = difference.SquaredLength() - m_Radius * m_Radius;
    auto dot = Dot(direction, difference);
    auto discr = dot * dot - a;
    if (discr < 0.0f)
    {
        return false;
    }

    const auto tmp0 = segmentExtent * segmentExtent + a;
    const auto tmp1 = 2.0f * dot * segmentExtent;
    const auto qm = tmp0 - tmp1;
    const auto qp = tmp0 + tmp1;
    if (qm * qp <= 0.0f)
    {
        return true;
    }

    return 0.0f < qm && Math::FAbs(dot) < segmentExtent;
}

#include STSTEM_WARNING_POP