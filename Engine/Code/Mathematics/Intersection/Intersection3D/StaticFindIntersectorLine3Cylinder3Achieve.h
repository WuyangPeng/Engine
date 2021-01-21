///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/18 18:09)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_ACHIEVE_H

#include "StaticFindIntersectorLine3Cylinder3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::StaticFindIntersectorLine3Cylinder3(const Line3& line, const Cylinder3& cylinder, const Real epsilon)
    : ParentType{ epsilon }, m_Line{ line }, m_Cylinder{ cylinder }, m_Quantity{}, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Cylinder3<Real> Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::GetCylinder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Cylinder;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::Find()
{
    const auto findShared = Find(m_Line.GetOrigin(), m_Line.GetDirection(), m_Cylinder);
    m_Quantity = findShared.m_Quantity;

    if (m_Quantity == 2)
    {
        m_Point0 = m_Line.GetOrigin() + findShared.m_Parameter0 * m_Line.GetDirection();
        m_Point1 = m_Line.GetOrigin() + findShared.m_Parameter1 * m_Line.GetDirection();
        this->SetIntersectionType(IntersectionType::Segment);
    }
    else if (m_Quantity == 1)
    {
        m_Point0 = m_Line.GetOrigin() + findShared.m_Parameter0 * m_Line.GetDirection();
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else if (index == 1)
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

template <typename Real>
typename Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::FindShared Mathematics::StaticFindIntersectorLine3Cylinder3<Real>::Find(const Vector3D& origin, const Vector3D& dir, const Cylinder3& cylinder)
{
    FindShared findShared{};

    /// 为圆柱创建坐标系。 在该系统中，圆筒线段中心C为原点，圆筒轴方向W为z轴。 U和V是其他坐标轴方向。
    /// 如果P = x * U + y * V + z * W，则圆柱体为x^2 + y^2 = r^2，其中r为圆柱体半径。
    /// 端盖为 |z| = h/2，其中h是圆柱体高度。
    const auto wVector = cylinder.GetAxis().GetDirection();
    const auto generateComplementBasis = Vector3DTools::GenerateComplementBasis(wVector);
    const auto uVector = generateComplementBasis.GetUVector();
    const auto vVector = generateComplementBasis.GetVVector();

    auto halfHeight = Math::GetRational(1, 2) * cylinder.GetHeight();
    auto radiusSqr = cylinder.GetRadius() * cylinder.GetRadius();

    // 将输入线原点转换为圆柱坐标
    auto diff = origin - cylinder.GetAxis().GetOrigin();
    const Vector3D point{ Vector3DTools::DotProduct(uVector, diff), Vector3DTools::DotProduct(vVector, diff), Vector3DTools::DotProduct(wVector, diff) };

    // 获取传入线的单位长度方向的z值（以圆柱坐标表示）。
    auto dirZ = Vector3DTools::DotProduct(wVector, dir);

    if (Math::GetValue(1) - Math::GetZeroTolerance() <= Math::FAbs(dirZ))
    {
        // 该线平行于圆柱轴。 确定该线是否与圆筒端盘相交。
        auto radialSqrDist = radiusSqr - point.GetX() * point.GetX() - point.GetY() * point.GetY();
        if (radialSqrDist < Math::GetValue(0))
        {
            // 线在圆柱体外面，没有相交。
            return findShared;
        }

        // 线与圆筒端盘相交。
        if (Math::GetValue(0) < dirZ)
        {
            findShared.m_Parameter0 = -point.GetZ() - halfHeight;
            findShared.m_Parameter1 = -point.GetZ() + halfHeight;
        }
        else
        {
            findShared.m_Parameter0 = point.GetZ() - halfHeight;
            findShared.m_Parameter1 = point.GetZ() + halfHeight;
        }

        findShared.m_Quantity = 2;
        return findShared;
    }

    // 将输入线单位长度方向转换为圆柱坐标
    const Vector3D direction{ Vector3DTools::DotProduct(uVector, dir), Vector3DTools::DotProduct(vVector, dir), dirZ };

    if (Math::FAbs(direction.GetZ()) <= Math::GetZeroTolerance())
    {
        // 该线垂直于圆柱轴。
        if (halfHeight < Math::FAbs(point.GetZ()))
        {
            // 线在圆筒端盘的平面之外。
            return findShared;
        }

        // 测试线P + t * D与无限圆柱x^2 + y^2 = r^2的交点。
        // 这简化为计算二次方程式的根。 如果 P = (px,py,pz) 和D = (dx,dy,dz)，
        // 则二次方程为 (dx^2 + dy^2) * t^2 + 2 * (px * dx + py * dy) * t + (px^2 + py^2 - r^2) = 0
        auto a0 = point.GetX() * point.GetX() + point.GetY() * point.GetY() - radiusSqr;
        auto a1 = point.GetX() * direction.GetX() + point.GetY() * direction.GetY();
        auto a2 = direction.GetX() * direction.GetX() + direction.GetY() * direction.GetY();
        auto discr = a1 * a1 - a0 * a2;
        if (discr < Math::GetValue(0))
        {
            // 线不与圆柱相交。
            return findShared;
        }
        else if (Math::GetZeroTolerance() < discr)
        {
            // 线在两个位置与圆柱相交。
            auto root = Math::Sqrt(discr);
            auto inv = Math::GetValue(1) / a2;
            findShared.m_Parameter0 = (-a1 - root) * inv;
            findShared.m_Parameter1 = (-a1 + root) * inv;
            findShared.m_Quantity = 2;
            return findShared;
        }
        else
        {
            // 线与圆柱相切。
            findShared.m_Parameter0 = -a1 / a2;
            findShared.m_Quantity = 1;
            return findShared;
        }
    }

    // 首先测试平面相交点。
    int quantity = 0;

    auto t0 = (-halfHeight - point.GetZ()) / direction.GetZ();
    auto x = point.GetX() + t0 * direction.GetX();
    auto y = point.GetY() + t0 * direction.GetY();
    if (x * x + y * y <= radiusSqr)
    {
        // 顶部圆筒端盘内部的平面交点。
        findShared.m_Parameter0 = t0;
        ++quantity;
    }

    auto t1 = (+halfHeight - point.GetZ()) / direction.GetZ();
    x = point.GetX() + t1 * direction.GetX();
    y = point.GetY() + t1 * direction.GetY();
    if (x * x + y * y <= radiusSqr)
    {
        // 底部圆筒端盘内部的平面交点。
        if (quantity == 0)
        {
            findShared.m_Parameter0 = t1;
        }
        else
        {
            findShared.m_Parameter1 = t1;
        }
        ++quantity;
    }

    if (quantity == 2)
    {
        // 线与顶部和底部圆筒端盘相交。
        if (findShared.m_Parameter1 < findShared.m_Parameter0)
        {
            std::swap(findShared.m_Parameter0, findShared.m_Parameter1);
        }
        findShared.m_Quantity = quantity;
        return findShared;
    }

    /// 如果quantity == 1，则该线必须在端盘之间的某个点与圆柱壁相交。
    /// 在以下代码中检测到这种情况，该代码测试线与圆柱壁之间的相交。
    auto a0 = point.GetX() * point.GetX() + point.GetY() * point.GetY() - radiusSqr;
    auto a1 = point.GetX() * direction.GetX() + point.GetY() * direction.GetY();
    auto a2 = direction.GetX() * direction.GetX() + direction.GetY() * direction.GetY();
    auto discr = a1 * a1 - a0 * a2;
    if (discr < Math::GetValue(0))
    {
        // 线不与圆筒壁相交。
        MATHEMATICS_ASSERTION_0(quantity == 0, "意外状况\n");
        return findShared;
    }
    else if (Math::GetZeroTolerance() < discr)
    {
        auto root = Math::Sqrt(discr);
        auto tValue = (-a1 - root) / a2;
        if (t0 <= t1)
        {
            if (t0 <= tValue && tValue <= t1)
            {
                if (quantity == 0)
                {
                    findShared.m_Parameter0 = tValue;
                }
                else
                {
                    findShared.m_Parameter1 = tValue;
                }
                ++quantity;
            }
        }
        else
        {
            if (t1 <= tValue && tValue <= t0)
            {
                if (quantity == 0)
                {
                    findShared.m_Parameter0 = tValue;
                }
                else
                {
                    findShared.m_Parameter1 = tValue;
                }
                ++quantity;
            }
        }

        if (quantity == 2)
        {
            // 线与圆筒端盘之一相交，并与圆筒壁相交。
            if (findShared.m_Parameter1 < findShared.m_Parameter0)
            {
                std::swap(findShared.m_Parameter0, findShared.m_Parameter1);
            }
            findShared.m_Quantity = quantity;
            return findShared;
        }

        tValue = (-a1 + root) / a2;
        if (t0 <= t1)
        {
            if (t0 <= tValue && tValue <= t1)
            {
                if (quantity == 0)
                {
                    findShared.m_Parameter0 = tValue;
                }
                else
                {
                    findShared.m_Parameter1 = tValue;
                }
                ++quantity;
            }
        }
        else
        {
            if (t1 <= tValue && tValue <= t0)
            {
                if (quantity == 0)
                {
                    findShared.m_Parameter0 = tValue;
                }
                else
                {
                    findShared.m_Parameter1 = tValue;
                }
                ++quantity;
            }
        }
    }
    else
    {
        auto tValue = -a1 / a2;
        if (t0 <= t1)
        {
            if (t0 <= tValue && tValue <= t1)
            {
                if (quantity == 0)
                {
                    findShared.m_Parameter0 = tValue;
                }
                else
                {
                    findShared.m_Parameter1 = tValue;
                }
                ++quantity;
            }
        }
        else
        {
            if (t1 <= tValue && tValue <= t0)
            {
                if (quantity == 0)
                {
                    findShared.m_Parameter0 = tValue;
                }
                else
                {
                    findShared.m_Parameter1 = tValue;
                }
                ++quantity;
            }
        }
    }

    if (quantity == 2)
    {
        if (findShared.m_Parameter1 < findShared.m_Parameter0)
        {
            std::swap(findShared.m_Parameter0, findShared.m_Parameter1);
        }
    }

    findShared.m_Quantity = quantity;
    return findShared;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_ACHIEVE_H
