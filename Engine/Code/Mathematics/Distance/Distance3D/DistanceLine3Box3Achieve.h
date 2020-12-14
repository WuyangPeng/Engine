///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/09 15:27)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_BOX3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_BOX3_ACHIEVE_H

#include "DistanceLine3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceLine3Box3<Real>::DistanceLine3Box3(const Line3& line, const Box3& box) noexcept
    : ParentType{}, m_Line{ line }, m_Box{ box }, m_LineParameter{}, m_Point{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceLine3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line3<Real> Mathematics::DistanceLine3Box3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DistanceLine3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
typename const Mathematics::DistanceLine3Box3<Real>::DistanceResult Mathematics::DistanceLine3Box3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto lhsMovedLine = m_Line.GetMove(t, lhsVelocity);
    const auto rhsMovedBox = m_Box.GetMove(t, rhsVelocity);

    ClassType distance{ lhsMovedLine, rhsMovedBox };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
typename const Mathematics::DistanceLine3Box3<Real>::DistanceResult Mathematics::DistanceLine3Box3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 在盒坐标系中计算线的坐标。
    auto diff = m_Line.GetOrigin() - m_Box.GetCenter();
    m_Point = Vector3D{ Vector3DTools::DotProduct(diff, m_Box.GetAxis0()),
                        Vector3DTools::DotProduct(diff, m_Box.GetAxis1()),
                        Vector3DTools::DotProduct(diff, m_Box.GetAxis2()) };
    Vector3D direction{ Vector3DTools::DotProduct(m_Line.GetDirection(), m_Box.GetAxis0()),
                        Vector3DTools::DotProduct(m_Line.GetDirection(), m_Box.GetAxis1()),
                        Vector3DTools::DotProduct(m_Line.GetDirection(), m_Box.GetAxis2()) };

    // 应用反射，使方向向量具有非负分量。
    constexpr auto size = 3;
    std::array<bool, size> reflect{};

    for (auto i = 0; i < size; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
        if (direction[i] < Math::GetValue(0))
        {
            m_Point[i] = -m_Point[i];
            direction[i] = -direction[i];
            reflect[i] = true;
        }
        else
        {
            reflect[i] = false;
        }
#include STSTEM_WARNING_POP
    }

    Real sqrDistance{};
    m_LineParameter = Math::GetValue(0);

    if (Math::GetValue(0) < direction.GetX())
    {
        if (Math::GetValue(0) < direction.GetY())
        {
            if (Math::GetValue(0) < direction.GetZ())  // (+,+,+)
            {
                sqrDistance = CaseNoZeros(direction);
            }
            else  // (+,+,0)
            {
                sqrDistance = Case0(0, 1, 2, direction);
            }
        }
        else
        {
            if (Math::GetValue(0) < direction.GetZ())  // (+,0,+)
            {
                sqrDistance = Case0(0, 2, 1, direction);
            }
            else  // (+,0,0)
            {
                sqrDistance = Case00(0, 1, 2, direction);
            }
        }
    }
    else
    {
        if (Math::GetValue(0) < direction.GetY())
        {
            if (Math::GetValue(0) < direction.GetZ())  // (0,+,+)
            {
                sqrDistance = Case0(1, 2, 0, direction);
            }
            else  // (0,+,0)
            {
                sqrDistance = Case00(1, 0, 2, direction);
            }
        }
        else
        {
            if (Math::GetValue(0) < direction.GetZ())  // (0,0,+)
            {
                sqrDistance = Case00(2, 0, 1, direction);
            }
            else  // (0,0,0)
            {
                sqrDistance = Case000();
            }
        }
    }

    // 计算线上的最近点。
    auto closestPoint0 = m_Line.GetOrigin() + m_LineParameter * m_Line.GetDirection();

    // 计算盒上的最近点。
    auto closestPoint1 = m_Box.GetCenter();
    for (auto i = 0; i < size; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
        // 撤消先前应用的反射。
        if (reflect[i])
        {
            m_Point[i] = -m_Point[i];
        }
#include STSTEM_WARNING_POP

        closestPoint1 += m_Point[i] * m_Box.GetAxis(i);
    }

    return DistanceResult{ sqrDistance, Math::GetValue(0), closestPoint0, closestPoint1, m_LineParameter, Math::GetValue(0) };
}

template <typename Real>
Real Mathematics::DistanceLine3Box3<Real>::CaseNoZeros(const Vector3D& direction) const
{
    Real sqrDistance = Math::GetValue(0);
    const Vector3D pointMinusExtent{ m_Point.GetX() - m_Box.GetExtent(0), m_Point.GetY() - m_Box.GetExtent(1), m_Point.GetZ() - m_Box.GetExtent(2) };

    auto prodDxPy = direction.GetX() * pointMinusExtent.GetY();
    auto prodDyPx = direction.GetY() * pointMinusExtent.GetX();
    auto prodDzPx = Math::GetValue(0);
    auto prodDxPz = Math::GetValue(0);
    auto prodDzPy = Math::GetValue(0);
    auto prodDyPz = Math::GetValue(0);

    if (prodDxPy <= prodDyPx)
    {
        prodDzPx = direction.GetZ() * pointMinusExtent.GetX();
        prodDxPz = direction.GetX() * pointMinusExtent.GetZ();
        if (prodDxPz <= prodDzPx)
        {
            // 线相交x = e0
            sqrDistance = Face(0, 1, 2, direction, pointMinusExtent);
        }
        else
        {
            // 线相交 z = e2
            sqrDistance = Face(2, 0, 1, direction, pointMinusExtent);
        }
    }
    else
    {
        prodDzPy = direction.GetZ() * pointMinusExtent.GetY();
        prodDyPz = direction.GetY() * pointMinusExtent.GetZ();
        if (prodDyPz <= prodDzPy)
        {
            // 线相交 y = e1
            sqrDistance = Face(1, 2, 0, direction, pointMinusExtent);
        }
        else
        {
            // 线相交 z = e2
            sqrDistance = Face(2, 0, 1, direction, pointMinusExtent);
        }
    }

    return sqrDistance;
}

template <typename Real>
Real Mathematics::DistanceLine3Box3<Real>::Face(int i0, int i1, int i2, const Vector3D& direction, const Vector3D& pointMinusExtent) const
{
    Real sqrDistance = Math::GetValue(0);
    Vector3D pointPlusExtent{};
    pointPlusExtent[i1] = m_Point[i1] + m_Box.GetExtent(i1);
    pointPlusExtent[i2] = m_Point[i2] + m_Box.GetExtent(i2);

    if (direction[i1] * pointMinusExtent[i0] <= direction[i0] * pointPlusExtent[i1])
    {
        if (direction[i2] * pointMinusExtent[i0] <= direction[i0] * pointPlusExtent[i2])
        {
            // v[i1] >= -e[i1], v[i2] >= -e[i2] (distance = 0)
            m_Point[i0] = m_Box.GetExtent(i0);

            m_Point[i1] -= direction[i1] * pointMinusExtent[i0] / direction[i0];
            m_Point[i2] -= direction[i2] * pointMinusExtent[i0] / direction[i0];
            m_LineParameter = -pointMinusExtent[i0] / direction[i0];
        }
        else
        {
            // v[i1] >= -e[i1], v[i2] < -e[i2]
            auto lenSqr = direction[i0] * direction[i0] + direction[i2] * direction[i2];
            auto value = lenSqr * pointPlusExtent[i1] - direction[i1] * (direction[i0] * pointMinusExtent[i0] + direction[i2] * pointPlusExtent[i2]);
            if (value <= (Math::GetValue(2) * lenSqr * m_Box.GetExtent(i1)))
            {
                auto t = value / lenSqr;
                lenSqr += direction[i1] * direction[i1];
                value = pointPlusExtent[i1] - t;
                auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * value + direction[i2] * pointPlusExtent[i2];
                auto param = -delta / lenSqr;
                sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + value * value + pointPlusExtent[i2] * pointPlusExtent[i2] + delta * param;

                m_LineParameter = param;
                m_Point[i0] = m_Box.GetExtent(i0);
                m_Point[i1] = t - m_Box.GetExtent(i1);
                m_Point[i2] = -m_Box.GetExtent(i2);
            }
            else
            {
                lenSqr += direction[i1] * direction[i1];
                auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * pointMinusExtent[i1] + direction[i2] * pointPlusExtent[i2];
                auto param = -delta / lenSqr;
                sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + pointMinusExtent[i1] * pointMinusExtent[i1] + pointPlusExtent[i2] * pointPlusExtent[i2] + delta * param;

                m_LineParameter = param;
                m_Point[i0] = m_Box.GetExtent(i0);
                m_Point[i1] = m_Box.GetExtent(i1);
                m_Point[i2] = -m_Box.GetExtent(i2);
            }
        }
    }
    else
    {
        if (direction[i2] * pointMinusExtent[i0] <= direction[i0] * pointPlusExtent[i2])
        {
            // v[i1] < -e[i1], v[i2] >= -e[i2]
            auto lenSqr = direction[i0] * direction[i0] + direction[i1] * direction[i1];
            auto value = lenSqr * pointPlusExtent[i2] - direction[i2] * (direction[i0] * pointMinusExtent[i0] + direction[i1] * pointPlusExtent[i1]);
            if (value <= (Math::GetValue(2)) * lenSqr * m_Box.GetExtent(i2))
            {
                auto t = value / lenSqr;
                lenSqr += direction[i2] * direction[i2];
                value = pointPlusExtent[i2] - t;
                auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * pointPlusExtent[i1] + direction[i2] * value;
                auto param = -delta / lenSqr;
                sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + pointPlusExtent[i1] * pointPlusExtent[i1] + value * value + delta * param;

                m_LineParameter = param;
                m_Point[i0] = m_Box.GetExtent(i0);
                m_Point[i1] = -m_Box.GetExtent(i1);
                m_Point[i2] = t - m_Box.GetExtent(i2);
            }
            else
            {
                lenSqr += direction[i2] * direction[i2];
                auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * pointPlusExtent[i1] + direction[i2] * pointMinusExtent[i2];
                auto param = -delta / lenSqr;
                sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + pointPlusExtent[i1] * pointPlusExtent[i1] + pointMinusExtent[i2] * pointMinusExtent[i2] + delta * param;

                m_LineParameter = param;
                m_Point[i0] = m_Box.GetExtent(i0);
                m_Point[i1] = -m_Box.GetExtent(i1);
                m_Point[i2] = m_Box.GetExtent(i2);
            }
        }
        else
        {
            // v[i1] < -e[i1], v[i2] < -e[i2]
            auto lenSqr = direction[i0] * direction[i0] + direction[i2] * direction[i2];
            auto value = lenSqr * pointPlusExtent[i1] - direction[i1] * (direction[i0] * pointMinusExtent[i0] + direction[i2] * pointPlusExtent[i2]);
            if (value >= Math::GetValue(0))
            {
                // v[i1]-边是最近点
                if (value <= (Math::GetValue(2)) * lenSqr * m_Box.GetExtent(i1))
                {
                    auto t = value / lenSqr;
                    lenSqr += direction[i1] * direction[i1];
                    value = pointPlusExtent[i1] - t;
                    auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * value + direction[i2] * pointPlusExtent[i2];
                    auto param = -delta / lenSqr;
                    sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + value * value + pointPlusExtent[i2] * pointPlusExtent[i2] + delta * param;

                    m_LineParameter = param;
                    m_Point[i0] = m_Box.GetExtent(i0);
                    m_Point[i1] = t - m_Box.GetExtent(i1);
                    m_Point[i2] = -m_Box.GetExtent(i2);
                }
                else
                {
                    lenSqr += direction[i1] * direction[i1];
                    auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * pointMinusExtent[i1] + direction[i2] * pointPlusExtent[i2];
                    auto param = -delta / lenSqr;
                    sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + pointMinusExtent[i1] * pointMinusExtent[i1] + pointPlusExtent[i2] * pointPlusExtent[i2] + delta * param;

                    m_LineParameter = param;
                    m_Point[i0] = m_Box.GetExtent(i0);
                    m_Point[i1] = m_Box.GetExtent(i1);
                    m_Point[i2] = -m_Box.GetExtent(i2);
                }
                return sqrDistance;
            }

            lenSqr = direction[i0] * direction[i0] + direction[i1] * direction[i1];
            value = lenSqr * pointPlusExtent[i2] - direction[i2] * (direction[i0] * pointMinusExtent[i0] + direction[i1] * pointPlusExtent[i1]);
            if (Math::GetValue(0) <= value)
            {
                // v[i2]-边是最近点
                if (value <= (Math::GetValue(2)) * lenSqr * m_Box.GetExtent(i2))
                {
                    auto t = value / lenSqr;
                    lenSqr += direction[i2] * direction[i2];
                    value = pointPlusExtent[i2] - t;
                    auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * pointPlusExtent[i1] + direction[i2] * value;
                    auto param = -delta / lenSqr;
                    sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + pointPlusExtent[i1] * pointPlusExtent[i1] + value * value + delta * param;

                    m_LineParameter = param;
                    m_Point[i0] = m_Box.GetExtent(i0);
                    m_Point[i1] = -m_Box.GetExtent(i1);
                    m_Point[i2] = t - m_Box.GetExtent(i2);
                }
                else
                {
                    lenSqr += direction[i2] * direction[i2];
                    auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * pointPlusExtent[i1] + direction[i2] * pointMinusExtent[i2];
                    auto param = -delta / lenSqr;
                    sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + pointPlusExtent[i1] * pointPlusExtent[i1] + pointMinusExtent[i2] * pointMinusExtent[i2] + delta * param;

                    m_LineParameter = param;
                    m_Point[i0] = m_Box.GetExtent(i0);
                    m_Point[i1] = -m_Box.GetExtent(i1);
                    m_Point[i2] = m_Box.GetExtent(i2);
                }
                return sqrDistance;
            }

            // (v[i1],v[i2])-角是最近点
            lenSqr += direction[i2] * direction[i2];
            auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * pointPlusExtent[i1] + direction[i2] * pointPlusExtent[i2];
            auto param = -delta / lenSqr;
            sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + pointPlusExtent[i1] * pointPlusExtent[i1] + pointPlusExtent[i2] * pointPlusExtent[i2] + delta * param;

            m_LineParameter = param;
            m_Point[i0] = m_Box.GetExtent(i0);
            m_Point[i1] = -m_Box.GetExtent(i1);
            m_Point[i2] = -m_Box.GetExtent(i2);
        }
    }

    return sqrDistance;
}

template <typename Real>
Real Mathematics::DistanceLine3Box3<Real>::Case0(int i0, int i1, int i2, const Vector3D& direction) const
{
    auto sqrDistance = Math::GetValue(0);
    auto pointMinusE0 = m_Point[i0] - m_Box.GetExtent(i0);
    auto pointMinusE1 = m_Point[i1] - m_Box.GetExtent(i1);
    auto prod0 = direction[i1] * pointMinusE0;
    auto prod1 = direction[i0] * pointMinusE1;

    if (prod1 <= prod0)
    {
        // 线相交 P[i0] = e[i0]
        m_Point[i0] = m_Box.GetExtent(i0);

        auto pointPlusE1 = m_Point[i1] + m_Box.GetExtent(i1);
        auto delta = prod0 - direction[i0] * pointPlusE1;
        if (Math::GetValue(0) <= delta)
        {
            auto invLSqr = (Math::GetValue(1)) / (direction[i0] * direction[i0] + direction[i1] * direction[i1]);
            sqrDistance += delta * delta * invLSqr;
            m_Point[i1] = -m_Box.GetExtent(i1);
            m_LineParameter = -(direction[i0] * pointMinusE0 + direction[i1] * pointPlusE1) * invLSqr;
        }
        else
        {
            m_Point[i1] -= prod0 / direction[i0];
            m_LineParameter = -pointMinusE0 / direction[i0];
        }
    }
    else
    {
        // 线相交 P[i1] = e[i1]
        m_Point[i1] = m_Box.GetExtent(i1);

        auto pointPlusE0 = m_Point[i0] + m_Box.GetExtent(i0);
        auto delta = prod1 - direction[i1] * pointPlusE0;
        if (Math::GetValue(0) <= delta)
        {
            auto invLSqr = (Math::GetValue(1)) / (direction[i0] * direction[i0] + direction[i1] * direction[i1]);
            sqrDistance += delta * delta * invLSqr;
            m_Point[i0] = -m_Box.GetExtent(i0);
            m_LineParameter = -(direction[i0] * pointPlusE0 + direction[i1] * pointMinusE1) * invLSqr;
        }
        else
        {
            m_Point[i0] -= prod1 / direction[i1];
            m_LineParameter = -pointMinusE1 / direction[i1];
        }
    }

    if (m_Point[i2] < -m_Box.GetExtent(i2))
    {
        auto delta = m_Point[i2] + m_Box.GetExtent(i2);
        sqrDistance += delta * delta;
        m_Point[i2] = -m_Box.GetExtent(i2);
    }
    else if (m_Box.GetExtent(i2) < m_Point[i2])
    {
        auto delta = m_Point[i2] - m_Box.GetExtent(i2);
        sqrDistance += delta * delta;
        m_Point[i2] = m_Box.GetExtent(i2);
    }

    return sqrDistance;
}

template <typename Real>
Real Mathematics::DistanceLine3Box3<Real>::Case00(int i0, int i1, int i2, const Vector3D& dir) const
{
    auto sqrDistance = Math::GetValue(0);

    m_LineParameter = (m_Box.GetExtent(i0) - m_Point[i0]) / dir[i0];

    m_Point[i0] = m_Box.GetExtent(i0);

    if (m_Point[i1] < -m_Box.GetExtent(i1))
    {
        auto delta = m_Point[i1] + m_Box.GetExtent(i1);
        sqrDistance += delta * delta;
        m_Point[i1] = -m_Box.GetExtent(i1);
    }
    else if (m_Box.GetExtent(i1) < m_Point[i1])
    {
        auto delta = m_Point[i1] - m_Box.GetExtent(i1);
        sqrDistance += delta * delta;
        m_Point[i1] = m_Box.GetExtent(i1);
    }

    if (m_Point[i2] < -m_Box.GetExtent(i2))
    {
        auto delta = m_Point[i2] + m_Box.GetExtent(i2);
        sqrDistance += delta * delta;
        m_Point[i2] = -m_Box.GetExtent(i2);
    }
    else if (m_Box.GetExtent(i2) < m_Point[i2])
    {
        auto delta = m_Point[i2] - m_Box.GetExtent(i2);
        sqrDistance += delta * delta;
        m_Point[i2] = m_Box.GetExtent(i2);
    }

    return sqrDistance;
}

template <typename Real>
Real Mathematics::DistanceLine3Box3<Real>::Case000() const
{
    auto sqrDistance = Math::GetValue(0);

    if (m_Point.GetX() < -m_Box.GetExtent(0))
    {
        auto delta = m_Point.GetX() + m_Box.GetExtent(0);
        sqrDistance += delta * delta;
        m_Point.SetX(-m_Box.GetExtent(0));
    }
    else if (m_Box.GetExtent(0) < m_Point.GetX())
    {
        auto delta = m_Point.GetX() - m_Box.GetExtent(0);
        sqrDistance += delta * delta;
        m_Point.SetX(m_Box.GetExtent(0));
    }

    if (m_Point.GetY() < -m_Box.GetExtent(1))
    {
        auto delta = m_Point.GetY() + m_Box.GetExtent(1);
        sqrDistance += delta * delta;
        m_Point.SetY(-m_Box.GetExtent(1));
    }
    else if (m_Box.GetExtent(1) < m_Point.GetY())
    {
        auto delta = m_Point.GetY() - m_Box.GetExtent(1);
        sqrDistance += delta * delta;
        m_Point.SetY(m_Box.GetExtent(1));
    }

    if (m_Point.GetZ() < -m_Box.GetExtent(2))
    {
        auto delta = m_Point.GetZ() + m_Box.GetExtent(2);
        sqrDistance += delta * delta;
        m_Point.SetZ(-m_Box.GetExtent(2));
    }
    else if (m_Point.GetZ() > m_Box.GetExtent(2))
    {
        auto delta = m_Point.GetZ() - m_Box.GetExtent(2);
        sqrDistance += delta * delta;
        m_Point.SetZ(m_Box.GetExtent(2));
    }

    return sqrDistance;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_BOX3_ACHIEVE_H