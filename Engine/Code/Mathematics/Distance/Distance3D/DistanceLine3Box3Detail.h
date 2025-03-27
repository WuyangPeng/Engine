///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:28)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_BOX3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_BOX3_DETAIL_H

#include "DistanceLine3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceLine3Box3<Real>::DistanceLine3Box3(const Line3& line, const Box3& box) noexcept
    : ParentType{}, line{ line }, box{ box }
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
Mathematics::Line3<Real> Mathematics::DistanceLine3Box3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::DistanceLine3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
typename Mathematics::DistanceLine3Box3<Real>::DistanceResult Mathematics::DistanceLine3Box3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto lhsMovedLine = line.GetMove(t, lhsVelocity);
    const auto rhsMovedBox = box.GetMove(t, rhsVelocity);

    ClassType distance{ lhsMovedLine, rhsMovedBox };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
typename Mathematics::DistanceLine3Box3<Real>::DistanceResult Mathematics::DistanceLine3Box3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 在盒坐标系中计算线的坐标。
    auto diff = line.GetOrigin() - box.GetCenter();
    auto point = Vector3{ Vector3Tools::DotProduct(diff, box.GetAxis0()),
                          Vector3Tools::DotProduct(diff, box.GetAxis1()),
                          Vector3Tools::DotProduct(diff, box.GetAxis2()) };
    Vector3 direction{ Vector3Tools::DotProduct(line.GetDirection(), box.GetAxis0()),
                       Vector3Tools::DotProduct(line.GetDirection(), box.GetAxis1()),
                       Vector3Tools::DotProduct(line.GetDirection(), box.GetAxis2()) };

    // 应用反射，使方向向量具有非负分量。
    constexpr auto size = 3;
    std::array<bool, size> reflect{};

    for (auto i = 0; i < size; ++i)
    {
        if (direction[i] < MathType::GetValue(0))
        {
            point[i] = -point[i];
            direction[i] = -direction[i];
            reflect.at(i) = true;
        }
        else
        {
            reflect.at(i) = false;
        }
    }

    Real sqrDistance{};
    auto lineParameter = MathType::GetValue(0);

    if (MathType::GetValue(0) < direction.GetX())
    {
        if (MathType::GetValue(0) < direction.GetY())
        {
            // (+,+,+)
            if (MathType::GetValue(0) < direction.GetZ())
            {
                sqrDistance = CaseNoZeros(direction, lineParameter, point);
            }
            else  // (+,+,0)
            {
                sqrDistance = Case0(0, 1, 2, direction, lineParameter, point);
            }
        }
        else
        {
            // (+,0,+)
            if (MathType::GetValue(0) < direction.GetZ())
            {
                sqrDistance = Case0(0, 2, 1, direction, lineParameter, point);
            }
            else  // (+,0,0)
            {
                sqrDistance = Case00(0, 1, 2, direction, lineParameter, point);
            }
        }
    }
    else
    {
        if (MathType::GetValue(0) < direction.GetY())
        {
            // (0,+,+)
            if (MathType::GetValue(0) < direction.GetZ())
            {
                sqrDistance = Case0(1, 2, 0, direction, lineParameter, point);
            }
            else  // (0,+,0)
            {
                sqrDistance = Case00(1, 0, 2, direction, lineParameter, point);
            }
        }
        else
        {
            // (0,0,+)
            if (MathType::GetValue(0) < direction.GetZ())
            {
                sqrDistance = Case00(2, 0, 1, direction, lineParameter, point);
            }
            else  // (0,0,0)
            {
                sqrDistance = Case000(point);
            }
        }
    }

    // 计算线上的最近点。
    const auto closestPoint0 = line.GetOrigin() + lineParameter * line.GetDirection();

    // 计算盒上的最近点。
    auto closestPoint1 = box.GetCenter();
    for (auto i = 0; i < size; ++i)
    {
        // 撤消先前应用的反射。
        if (reflect.at(i))
        {
            point[i] = -point[i];
        }

        closestPoint1 += point[i] * box.GetAxis(i);
    }

    return DistanceResult{ sqrDistance, MathType::GetValue(0), closestPoint0, closestPoint1, lineParameter, MathType::GetValue(0) };
}

template <typename Real>
Real Mathematics::DistanceLine3Box3<Real>::CaseNoZeros(const Vector3& direction, Real& lineParameter, Vector3& point) const
{
    Real sqrDistance{};
    const Vector3 pointMinusExtent{ point.GetX() - box.GetExtent(0), point.GetY() - box.GetExtent(1), point.GetZ() - box.GetExtent(2) };

    auto prodDxPy = direction.GetX() * pointMinusExtent.GetY();
    auto prodDyPx = direction.GetY() * pointMinusExtent.GetX();
    auto prodDzPx = MathType::GetValue(0);
    auto prodDxPz = MathType::GetValue(0);
    auto prodDzPy = MathType::GetValue(0);
    auto prodDyPz = MathType::GetValue(0);

    if (prodDxPy <= prodDyPx)
    {
        prodDzPx = direction.GetZ() * pointMinusExtent.GetX();
        prodDxPz = direction.GetX() * pointMinusExtent.GetZ();
        if (prodDxPz <= prodDzPx)
        {
            // 线相交x = e0
            sqrDistance = Face(0, 1, 2, direction, pointMinusExtent, lineParameter, point);
        }
        else
        {
            // 线相交 z = e2
            sqrDistance = Face(2, 0, 1, direction, pointMinusExtent, lineParameter, point);
        }
    }
    else
    {
        prodDzPy = direction.GetZ() * pointMinusExtent.GetY();
        prodDyPz = direction.GetY() * pointMinusExtent.GetZ();
        if (prodDyPz <= prodDzPy)
        {
            // 线相交 y = e1
            sqrDistance = Face(1, 2, 0, direction, pointMinusExtent, lineParameter, point);
        }
        else
        {
            // 线相交 z = e2
            sqrDistance = Face(2, 0, 1, direction, pointMinusExtent, lineParameter, point);
        }
    }

    return sqrDistance;
}

template <typename Real>
Real Mathematics::DistanceLine3Box3<Real>::Face(int i0, int i1, int i2, const Vector3& direction, const Vector3& pointMinusExtent, Real& lineParameter, Vector3& point) const
{
    Real sqrDistance{};
    Vector3 pointPlusExtent{};
    pointPlusExtent[i1] = point[i1] + box.GetExtent(i1);
    pointPlusExtent[i2] = point[i2] + box.GetExtent(i2);

    if (direction[i1] * pointMinusExtent[i0] <= direction[i0] * pointPlusExtent[i1])
    {
        if (direction[i2] * pointMinusExtent[i0] <= direction[i0] * pointPlusExtent[i2])
        {
            // v[i1] >= -e[i1], v[i2] >= -e[i2] (distance = 0)
            point[i0] = box.GetExtent(i0);

            point[i1] -= direction[i1] * pointMinusExtent[i0] / direction[i0];
            point[i2] -= direction[i2] * pointMinusExtent[i0] / direction[i0];
            lineParameter = -pointMinusExtent[i0] / direction[i0];
        }
        else
        {
            // v[i1] >= -e[i1], v[i2] < -e[i2]
            auto lenSqr = direction[i0] * direction[i0] + direction[i2] * direction[i2];
            auto value = lenSqr * pointPlusExtent[i1] - direction[i1] * (direction[i0] * pointMinusExtent[i0] + direction[i2] * pointPlusExtent[i2]);
            if (value <= (MathType::GetValue(2) * lenSqr * box.GetExtent(i1)))
            {
                auto t = value / lenSqr;
                lenSqr += direction[i1] * direction[i1];
                value = pointPlusExtent[i1] - t;
                auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * value + direction[i2] * pointPlusExtent[i2];
                auto param = -delta / lenSqr;
                sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + value * value + pointPlusExtent[i2] * pointPlusExtent[i2] + delta * param;

                lineParameter = param;
                point[i0] = box.GetExtent(i0);
                point[i1] = t - box.GetExtent(i1);
                point[i2] = -box.GetExtent(i2);
            }
            else
            {
                lenSqr += direction[i1] * direction[i1];
                auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * pointMinusExtent[i1] + direction[i2] * pointPlusExtent[i2];
                auto param = -delta / lenSqr;
                sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + pointMinusExtent[i1] * pointMinusExtent[i1] + pointPlusExtent[i2] * pointPlusExtent[i2] + delta * param;

                lineParameter = param;
                point[i0] = box.GetExtent(i0);
                point[i1] = box.GetExtent(i1);
                point[i2] = -box.GetExtent(i2);
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
            if (value <= (MathType::GetValue(2)) * lenSqr * box.GetExtent(i2))
            {
                auto t = value / lenSqr;
                lenSqr += direction[i2] * direction[i2];
                value = pointPlusExtent[i2] - t;
                auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * pointPlusExtent[i1] + direction[i2] * value;
                auto param = -delta / lenSqr;
                sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + pointPlusExtent[i1] * pointPlusExtent[i1] + value * value + delta * param;

                lineParameter = param;
                point[i0] = box.GetExtent(i0);
                point[i1] = -box.GetExtent(i1);
                point[i2] = t - box.GetExtent(i2);
            }
            else
            {
                lenSqr += direction[i2] * direction[i2];
                auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * pointPlusExtent[i1] + direction[i2] * pointMinusExtent[i2];
                auto param = -delta / lenSqr;
                sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + pointPlusExtent[i1] * pointPlusExtent[i1] + pointMinusExtent[i2] * pointMinusExtent[i2] + delta * param;

                lineParameter = param;
                point[i0] = box.GetExtent(i0);
                point[i1] = -box.GetExtent(i1);
                point[i2] = box.GetExtent(i2);
            }
        }
        else
        {
            // v[i1] < -e[i1], v[i2] < -e[i2]
            auto lenSqr = direction[i0] * direction[i0] + direction[i2] * direction[i2];
            auto value = lenSqr * pointPlusExtent[i1] - direction[i1] * (direction[i0] * pointMinusExtent[i0] + direction[i2] * pointPlusExtent[i2]);
            if (value >= MathType::GetValue(0))
            {
                // v[i1]-边是最近点
                if (value <= (MathType::GetValue(2)) * lenSqr * box.GetExtent(i1))
                {
                    auto t = value / lenSqr;
                    lenSqr += direction[i1] * direction[i1];
                    value = pointPlusExtent[i1] - t;
                    auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * value + direction[i2] * pointPlusExtent[i2];
                    auto param = -delta / lenSqr;
                    sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + value * value + pointPlusExtent[i2] * pointPlusExtent[i2] + delta * param;

                    lineParameter = param;
                    point[i0] = box.GetExtent(i0);
                    point[i1] = t - box.GetExtent(i1);
                    point[i2] = -box.GetExtent(i2);
                }
                else
                {
                    lenSqr += direction[i1] * direction[i1];
                    auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * pointMinusExtent[i1] + direction[i2] * pointPlusExtent[i2];
                    auto param = -delta / lenSqr;
                    sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + pointMinusExtent[i1] * pointMinusExtent[i1] + pointPlusExtent[i2] * pointPlusExtent[i2] + delta * param;

                    lineParameter = param;
                    point[i0] = box.GetExtent(i0);
                    point[i1] = box.GetExtent(i1);
                    point[i2] = -box.GetExtent(i2);
                }
                return sqrDistance;
            }

            lenSqr = direction[i0] * direction[i0] + direction[i1] * direction[i1];
            value = lenSqr * pointPlusExtent[i2] - direction[i2] * (direction[i0] * pointMinusExtent[i0] + direction[i1] * pointPlusExtent[i1]);
            if (MathType::GetValue(0) <= value)
            {
                // v[i2]-边是最近点
                if (value <= (MathType::GetValue(2)) * lenSqr * box.GetExtent(i2))
                {
                    auto t = value / lenSqr;
                    lenSqr += direction[i2] * direction[i2];
                    value = pointPlusExtent[i2] - t;
                    auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * pointPlusExtent[i1] + direction[i2] * value;
                    auto param = -delta / lenSqr;
                    sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + pointPlusExtent[i1] * pointPlusExtent[i1] + value * value + delta * param;

                    lineParameter = param;
                    point[i0] = box.GetExtent(i0);
                    point[i1] = -box.GetExtent(i1);
                    point[i2] = t - box.GetExtent(i2);
                }
                else
                {
                    lenSqr += direction[i2] * direction[i2];
                    auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * pointPlusExtent[i1] + direction[i2] * pointMinusExtent[i2];
                    auto param = -delta / lenSqr;
                    sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + pointPlusExtent[i1] * pointPlusExtent[i1] + pointMinusExtent[i2] * pointMinusExtent[i2] + delta * param;

                    lineParameter = param;
                    point[i0] = box.GetExtent(i0);
                    point[i1] = -box.GetExtent(i1);
                    point[i2] = box.GetExtent(i2);
                }
                return sqrDistance;
            }

            // (v[i1],v[i2])-角是最近点
            lenSqr += direction[i2] * direction[i2];
            auto delta = direction[i0] * pointMinusExtent[i0] + direction[i1] * pointPlusExtent[i1] + direction[i2] * pointPlusExtent[i2];
            auto param = -delta / lenSqr;
            sqrDistance += pointMinusExtent[i0] * pointMinusExtent[i0] + pointPlusExtent[i1] * pointPlusExtent[i1] + pointPlusExtent[i2] * pointPlusExtent[i2] + delta * param;

            lineParameter = param;
            point[i0] = box.GetExtent(i0);
            point[i1] = -box.GetExtent(i1);
            point[i2] = -box.GetExtent(i2);
        }
    }

    return sqrDistance;
}

template <typename Real>
Real Mathematics::DistanceLine3Box3<Real>::Case0(int i0, int i1, int i2, const Vector3& direction, Real& lineParameter, Vector3& point) const
{
    auto sqrDistance = MathType::GetValue(0);
    auto pointMinusE0 = point[i0] - box.GetExtent(i0);
    auto pointMinusE1 = point[i1] - box.GetExtent(i1);
    auto prod0 = direction[i1] * pointMinusE0;
    auto prod1 = direction[i0] * pointMinusE1;

    if (prod1 <= prod0)
    {
        // 线相交 P[i0] = e[i0]
        point[i0] = box.GetExtent(i0);

        auto pointPlusE1 = point[i1] + box.GetExtent(i1);
        auto delta = prod0 - direction[i0] * pointPlusE1;
        if (MathType::GetValue(0) <= delta)
        {
            auto invLSqr = (MathType::GetValue(1)) / (direction[i0] * direction[i0] + direction[i1] * direction[i1]);
            sqrDistance += delta * delta * invLSqr;
            point[i1] = -box.GetExtent(i1);
            lineParameter = -(direction[i0] * pointMinusE0 + direction[i1] * pointPlusE1) * invLSqr;
        }
        else
        {
            point[i1] -= prod0 / direction[i0];
            lineParameter = -pointMinusE0 / direction[i0];
        }
    }
    else
    {
        // 线相交 P[i1] = e[i1]
        point[i1] = box.GetExtent(i1);

        auto pointPlusE0 = point[i0] + box.GetExtent(i0);
        auto delta = prod1 - direction[i1] * pointPlusE0;
        if (MathType::GetValue(0) <= delta)
        {
            auto invLSqr = (MathType::GetValue(1)) / (direction[i0] * direction[i0] + direction[i1] * direction[i1]);
            sqrDistance += delta * delta * invLSqr;
            point[i0] = -box.GetExtent(i0);
            lineParameter = -(direction[i0] * pointPlusE0 + direction[i1] * pointMinusE1) * invLSqr;
        }
        else
        {
            point[i0] -= prod1 / direction[i1];
            lineParameter = -pointMinusE1 / direction[i1];
        }
    }

    if (point[i2] < -box.GetExtent(i2))
    {
        auto delta = point[i2] + box.GetExtent(i2);
        sqrDistance += delta * delta;
        point[i2] = -box.GetExtent(i2);
    }
    else if (box.GetExtent(i2) < point[i2])
    {
        auto delta = point[i2] - box.GetExtent(i2);
        sqrDistance += delta * delta;
        point[i2] = box.GetExtent(i2);
    }

    return sqrDistance;
}

template <typename Real>
Real Mathematics::DistanceLine3Box3<Real>::Case00(int i0, int i1, int i2, const Vector3& dir, Real& lineParameter, Vector3& point) const
{
    auto sqrDistance = MathType::GetValue(0);

    lineParameter = (box.GetExtent(i0) - point[i0]) / dir[i0];

    point[i0] = box.GetExtent(i0);

    if (point[i1] < -box.GetExtent(i1))
    {
        auto delta = point[i1] + box.GetExtent(i1);
        sqrDistance += delta * delta;
        point[i1] = -box.GetExtent(i1);
    }
    else if (box.GetExtent(i1) < point[i1])
    {
        auto delta = point[i1] - box.GetExtent(i1);
        sqrDistance += delta * delta;
        point[i1] = box.GetExtent(i1);
    }

    if (point[i2] < -box.GetExtent(i2))
    {
        auto delta = point[i2] + box.GetExtent(i2);
        sqrDistance += delta * delta;
        point[i2] = -box.GetExtent(i2);
    }
    else if (box.GetExtent(i2) < point[i2])
    {
        auto delta = point[i2] - box.GetExtent(i2);
        sqrDistance += delta * delta;
        point[i2] = box.GetExtent(i2);
    }

    return sqrDistance;
}

template <typename Real>
Real Mathematics::DistanceLine3Box3<Real>::Case000(Vector3& point) const
{
    auto sqrDistance = MathType::GetValue(0);

    if (point.GetX() < -box.GetExtent(0))
    {
        auto delta = point.GetX() + box.GetExtent(0);
        sqrDistance += delta * delta;
        point.SetX(-box.GetExtent(0));
    }
    else if (box.GetExtent(0) < point.GetX())
    {
        auto delta = point.GetX() - box.GetExtent(0);
        sqrDistance += delta * delta;
        point.SetX(box.GetExtent(0));
    }

    if (point.GetY() < -box.GetExtent(1))
    {
        auto delta = point.GetY() + box.GetExtent(1);
        sqrDistance += delta * delta;
        point.SetY(-box.GetExtent(1));
    }
    else if (box.GetExtent(1) < point.GetY())
    {
        auto delta = point.GetY() - box.GetExtent(1);
        sqrDistance += delta * delta;
        point.SetY(box.GetExtent(1));
    }

    if (point.GetZ() < -box.GetExtent(2))
    {
        auto delta = point.GetZ() + box.GetExtent(2);
        sqrDistance += delta * delta;
        point.SetZ(-box.GetExtent(2));
    }
    else if (point.GetZ() > box.GetExtent(2))
    {
        auto delta = point.GetZ() - box.GetExtent(2);
        sqrDistance += delta * delta;
        point.SetZ(box.GetExtent(2));
    }

    return sqrDistance;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_BOX3_DETAIL_H