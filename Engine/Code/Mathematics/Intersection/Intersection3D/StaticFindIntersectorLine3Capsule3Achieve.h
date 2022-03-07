///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/01 18:48)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Capsule3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Segment3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Capsule3<Real>::StaticFindIntersectorLine3Capsule3(const Line3& line, const Capsule3& capsule, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, capsule{ capsule }, quantity{}, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Capsule3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Capsule3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Capsule3<Real> Mathematics::StaticFindIntersectorLine3Capsule3<Real>::GetCapsule() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return capsule;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Capsule3<Real>::Find()
{
    const auto findShared = Find(line.GetOrigin(), line.GetDirection(), capsule);
    quantity = findShared.quantity;
    if (0 < quantity)
    {
        point0 = line.GetOrigin() + findShared.parameter0 * line.GetDirection();
    }

    if (1 < quantity)
    {
        point1 = line.GetOrigin() + findShared.parameter1 * line.GetDirection();
    }

    if (quantity == 2)
    {
        this->SetIntersectionType(IntersectionType::Segment);
    }
    else if (quantity == 1)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Capsule3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorLine3Capsule3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else if (index == 1)
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

template <typename Real>
typename Mathematics::StaticFindIntersectorLine3Capsule3<Real>::FindShared Mathematics::StaticFindIntersectorLine3Capsule3<Real>::Find(const Vector3& origin, const Vector3& direction, const Capsule3& capsule)
{
    FindShared findShared{};

    /// 为胶囊创建坐标系。 在该系统中，胶囊段中心C为原点，胶囊轴方向W为z轴。
    /// U和V是其他坐标轴方向。 如果P = x * U + y * V + z * W，则包含胶囊壁的圆柱体为x^2 + y^2 = r^2，其中r是胶囊半径。
    /// 组成胶囊减去其半球形端盖的有限圆柱体的z值|z| <= e，其中e是胶囊段的范围。
    /// 对于z > = e，上半球上限为x^2+y^2+(z-e)^2 = r^2；对于z <= -e，下半球上限为x^2+y^2+(z+e)^2 = r^2。
    const auto segmentDirection = capsule.GetSegment().GetDirection();
    const auto Vector3OrthonormalBasis = Vector3Tools::GenerateComplementBasis(segmentDirection);
    const auto uVector = Vector3OrthonormalBasis.GetUVector();
    const auto vVector = Vector3OrthonormalBasis.GetVVector();
    auto radiusSqr = capsule.GetRadius() * capsule.GetRadius();
    auto extent = capsule.GetSegment().GetExtent();

    // 将输入线的原点转换为胶囊坐标。
    auto diff = origin - capsule.GetSegment().GetCenterPoint();
    const Vector3 point{ Vector3Tools::DotProduct(uVector, diff), Vector3Tools::DotProduct(vVector, diff), Vector3Tools::DotProduct(segmentDirection, diff) };

    // 获取线的单位长度方向在胶囊坐标中的z值。
    auto directionDot = Vector3Tools::DotProduct(segmentDirection, direction);
    if (Math::GetValue(1) - Math::GetZeroTolerance() <= Math::FAbs(directionDot))
    {
        // 该线平行于胶囊轴线。 确定该线是否与胶囊半球相交。
        auto radialSqrDist = radiusSqr - point.GetX() * point.GetX() - point.GetY() * point.GetY();
        if (radialSqrDist < Math::GetValue(0))
        {
            // 线在胶囊圆柱体的外部，无相交处。
            return findShared;
        }

        // 线与半球帽相交
        auto zOffset = Math::Sqrt(radialSqrDist) + extent;
        if (Math::GetValue(0) < directionDot)
        {
            findShared.parameter0 = -point.GetZ() - zOffset;
            findShared.parameter1 = -point.GetZ() + zOffset;
        }
        else
        {
            findShared.parameter0 = point.GetZ() - zOffset;
            findShared.parameter1 = point.GetZ() + zOffset;
        }

        findShared.quantity = 2;
        return findShared;
    }

    // 将输入线单位长度方向转换为胶囊坐标。
    const Vector3 dot{ Vector3Tools::DotProduct(uVector, direction), Vector3Tools::DotProduct(vVector, direction), directionDot };

    /// 测试线 P + t * D与无限圆柱x^2 + y^2 = r^2的交点。 这简化为计算二次方程式的根。
    /// 如果P = (px,py,pz)和 D = (dx,dy,dz)，则二次方程为
    /// (dx^2 + dy^2) * t^2 + 2 * (px * dx + py * dy) * t + (px^2 + py^2 - r^2) = 0
    auto a0 = point.GetX() * point.GetX() + point.GetY() * point.GetY() - radiusSqr;
    auto a1 = point.GetX() * dot.GetX() + point.GetY() * dot.GetY();
    auto a2 = dot.GetX() * dot.GetX() + dot.GetY() * dot.GetY();
    auto discr = a1 * a1 - a0 * a2;
    if (discr < Math::GetValue(0))
    {
        // 线不与无限圆柱相交。
        return findShared;
    }

    int quantity = 0;
    if (Math::GetZeroTolerance() < discr)
    {
        // 线在两个地方与无限圆柱相交。
        auto root = Math::Sqrt(discr);
        auto inv = (Math::GetValue(1)) / a2;
        auto tValue = (-a1 - root) * inv;
        auto zValue = point.GetZ() + tValue * dot.GetZ();
        if (Math::FAbs(zValue) <= extent)
        {
            findShared.parameter0 = tValue;
            ++quantity;
        }

        tValue = (-a1 + root) * inv;
        zValue = point.GetZ() + tValue * dot.GetZ();
        if (Math::FAbs(zValue) <= extent)
        {
            if (quantity == 0)
            {
                findShared.parameter0 = tValue;
            }
            else
            {
                findShared.parameter1 = tValue;
            }
            ++quantity;
        }

        if (quantity == 2)
        {
            // 线在两个地方与胶囊壁相交。
            findShared.quantity = 2;
            return findShared;
        }
    }
    else
    {
        // 线与无限圆柱相切。
        auto tValue = -a1 / a2;
        auto zValue = point.GetZ() + tValue * dot.GetZ();
        if (Math::FAbs(zValue) <= extent)
        {
            findShared.parameter0 = tValue;

            findShared.quantity = 1;
            return findShared;
        }
    }

    /// 测试与下半球的交点。 二次方程是t^2 + 2 * (px * dx + py * dy + (pz + e) * dz) * t + (px^2 + py^2 + (pz + e)^2 - r^2) = 0
    /// 使用当前a1 = px * dx + py * dy和a0 = px^2 + py^2 - r^2的事实。 前导系数为a2 = 1，因此无需包含在构造中。
    auto zPlusExtent = point.GetZ() + extent;
    a1 += zPlusExtent * dot.GetZ();
    a0 += zPlusExtent * zPlusExtent;
    discr = a1 * a1 - a0;
    if (Math::GetZeroTolerance() < discr)
    {
        auto root = Math::Sqrt(discr);
        auto tValue = -a1 - root;
        auto zValue = point.GetZ() + tValue * dot.GetZ();
        if (zValue <= -extent)
        {
            if (quantity == 0)
            {
                findShared.parameter0 = tValue;
            }
            else
            {
                findShared.parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.parameter1 < findShared.parameter0)
                {
                    std::swap(findShared.parameter0, findShared.parameter1);
                }

                findShared.quantity = 2;
                return findShared;
            }
        }

        tValue = -a1 + root;
        zValue = point.GetZ() + tValue * dot.GetZ();
        if (zValue <= -extent)
        {
            if (quantity == 0)
            {
                findShared.parameter0 = tValue;
            }
            else
            {
                findShared.parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.parameter1 < findShared.parameter0)
                {
                    std::swap(findShared.parameter0, findShared.parameter1);
                }

                findShared.quantity = 2;
                return findShared;
            }
        }
    }
    else if (Math::FAbs(discr) <= Math::GetZeroTolerance())
    {
        auto tValue = -a1;
        auto zValue = point.GetZ() + tValue * dot.GetZ();
        if (zValue <= -extent)
        {
            if (quantity == 0)
            {
                findShared.parameter0 = tValue;
            }
            else
            {
                findShared.parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.parameter1 < findShared.parameter0)
                {
                    std::swap(findShared.parameter0, findShared.parameter1);
                }

                findShared.quantity = 2;
                return findShared;
            }
        }
    }

    /// 测试与上半球的交点。 二次方程是t^2 + 2 * (px * dx + py * dy + (pz - e) * dz) * t + (px^2 + py^2 + (pz - e)^2 - r^2) = 0
    /// 使用当前a1 = px * dx  + py * dy + (pz + e) * dz和a0 = px^2 + py^2 + (pz + e)^2 - r^2的事实。
    /// 前导系数为a2 = 1，因此无需包含在构造中。
    a1 -= (Math::GetValue(2)) * extent * dot.GetZ();
    a0 -= (Math::GetValue(4)) * extent * point.GetZ();
    discr = a1 * a1 - a0;
    if (Math::GetZeroTolerance() < discr)
    {
        auto root = Math::Sqrt(discr);
        auto tValue = -a1 - root;
        auto zValue = point.GetZ() + tValue * dot.GetZ();
        if (extent <= zValue)
        {
            if (quantity == 0)
            {
                findShared.parameter0 = tValue;
            }
            else
            {
                findShared.parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.parameter1 < findShared.parameter0)
                {
                    std::swap(findShared.parameter0, findShared.parameter1);
                }

                findShared.quantity = 2;
                return findShared;
            }
        }

        tValue = -a1 + root;
        zValue = point.GetZ() + tValue * dot.GetZ();
        if (extent <= zValue)
        {
            if (quantity == 0)
            {
                findShared.parameter0 = tValue;
            }
            else
            {
                findShared.parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.parameter1 < findShared.parameter0)
                {
                    std::swap(findShared.parameter0, findShared.parameter1);
                }

                findShared.quantity = 2;
                return findShared;
            }
        }
    }
    else if (Math::FAbs(discr) <= Math::GetZeroTolerance())
    {
        auto tValue = -a1;
        auto zValue = point.GetZ() + tValue * dot.GetZ();
        if (extent <= zValue)
        {
            if (quantity == 0)
            {
                findShared.parameter0 = tValue;
            }
            else
            {
                findShared.parameter1 = tValue;
            }
            ++quantity;
            if (quantity == 2)
            {
                if (findShared.parameter1 < findShared.parameter0)
                {
                    std::swap(findShared.parameter0, findShared.parameter1);
                }

                findShared.quantity = 2;
                return findShared;
            }
        }
    }

    findShared.quantity = quantity;

    return findShared;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_ACHIEVE_H