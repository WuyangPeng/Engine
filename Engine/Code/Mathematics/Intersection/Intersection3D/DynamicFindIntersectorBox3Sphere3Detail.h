///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:04)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_DETAIL_H

#include "DynamicFindIntersectorBox3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::DynamicFindIntersectorBox3Sphere3<Real>::DynamicFindIntersectorBox3Sphere3(const Box3& box, const Sphere3& sphere, Real tmax, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, box{ box }, sphere{ sphere }, contactPoint{}, x{}, y{}, z{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicFindIntersectorBox3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorBox3Sphere3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorBox3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DynamicFindIntersectorBox3Sphere3<Real>::GetContactPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return contactPoint;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorBox3Sphere3<Real>::Find()
{
    /// 查找相对于盒子的坐标系的交点。 球体将转换为盒子坐标，并且球体的速度是相对于盒子的。
    auto centerDiff = sphere.GetCenter() - box.GetCenter();
    auto relativeVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    auto centerDiffDotX = Vector3ToolsType::DotProduct(centerDiff, box.GetAxis(0));
    auto centerDiffDotY = Vector3ToolsType::DotProduct(centerDiff, box.GetAxis(1));
    auto centerDiffDotZ = Vector3ToolsType::DotProduct(centerDiff, box.GetAxis(2));
    auto relativeVelocityDotX = Vector3ToolsType::DotProduct(relativeVelocity, box.GetAxis(0));
    auto relativeVelocityDotY = Vector3ToolsType::DotProduct(relativeVelocity, box.GetAxis(1));
    auto relativeVelocityDotZ = Vector3ToolsType::DotProduct(relativeVelocity, box.GetAxis(2));

    // 将坐标框翻转到第一个八分圆。
    auto signX = 1;
    if (centerDiffDotX < MathType::GetValue(0))
    {
        centerDiffDotX = -centerDiffDotX;
        relativeVelocityDotX = -relativeVelocityDotX;
        signX = -1;
    }

    auto signY = 1;
    if (centerDiffDotY < MathType::GetValue(0))
    {
        centerDiffDotY = -centerDiffDotY;
        relativeVelocityDotY = -relativeVelocityDotY;
        signY = -1;
    }

    auto signZ = 1;
    if (centerDiffDotZ < MathType::GetValue(0))
    {
        centerDiffDotZ = -centerDiffDotZ;
        relativeVelocityDotZ = -relativeVelocityDotZ;
        signZ = -1;
    }

    // 交叉点坐标。
    auto result = 0;

    if (centerDiffDotX <= box.GetExtent(0))
    {
        if (centerDiffDotY <= box.GetExtent(1))
        {
            if (centerDiffDotZ <= box.GetExtent(2))
            {
                // 球体中心在盒子内部。 将其返回为接触点，但报告“其他”交叉点类型。
                this->SetContactTime(MathType::GetValue(0));
                contactPoint = sphere.GetCenter();
                this->SetIntersectionType(IntersectionType::Other);
                return;
            }
            else
            {
                // 球面在Z轴上的上方。
                result = FindFaceRegionIntersection(box.GetExtent(0), box.GetExtent(1), box.GetExtent(2), centerDiffDotX, centerDiffDotY, centerDiffDotZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ, true);
            }
        }
        else
        {
            if (centerDiffDotZ <= box.GetExtent(2))
            {
                // 球面在Y轴上的上方。
                result = FindFaceRegionIntersection(box.GetExtent(0), box.GetExtent(2), box.GetExtent(1), centerDiffDotX, centerDiffDotZ, centerDiffDotY, relativeVelocityDotX, relativeVelocityDotZ, relativeVelocityDotY, true);
            }
            else
            {
                // 球面位于面y和z形成的边缘上方。
                result = FindEdgeRegionIntersection(box.GetExtent(1), box.GetExtent(0), box.GetExtent(2), centerDiffDotY, centerDiffDotX, centerDiffDotZ, relativeVelocityDotY, relativeVelocityDotX, relativeVelocityDotZ, true);
            }
        }
    }
    else
    {
        if (centerDiffDotY <= box.GetExtent(1))
        {
            if (centerDiffDotZ <= box.GetExtent(2))
            {
                // 球面在X轴上的上方。
                result = FindFaceRegionIntersection(box.GetExtent(1), box.GetExtent(2), box.GetExtent(0), centerDiffDotY, centerDiffDotZ, centerDiffDotX, relativeVelocityDotY, relativeVelocityDotZ, relativeVelocityDotX, true);
            }
            else
            {
                // 球体在面x和z形成的边缘上方。
                result = FindEdgeRegionIntersection(box.GetExtent(0), box.GetExtent(1), box.GetExtent(2), centerDiffDotX, centerDiffDotY, centerDiffDotZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ, true);
            }
        }
        else
        {
            if (centerDiffDotZ <= box.GetExtent(2))
            {
                // 球体位于面x和y形成的边缘上方。
                result = FindEdgeRegionIntersection(box.GetExtent(0), box.GetExtent(2), box.GetExtent(1), centerDiffDotX, centerDiffDotZ, centerDiffDotY, relativeVelocityDotX, relativeVelocityDotZ, relativeVelocityDotY, true);
            }
            else
            {
                // 球体在由面x，y，z形成的角的上方
                result = FindVertexRegionIntersection(box.GetExtent(0), box.GetExtent(1), box.GetExtent(2), centerDiffDotX, centerDiffDotY, centerDiffDotZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ);
            }
        }
    }

    if (result == 0 || this->GetContactTime() > this->GetTMax())
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 计算实际的相交（将点移回世界坐标）。
    this->SetIntersectionType(IntersectionType::Point);
    contactPoint = box.GetCenter() + (signX * x) * box.GetAxis(0) + (signY * y) * box.GetAxis(1) + (signZ * z) * box.GetAxis(2);
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorBox3Sphere3<Real>::GetVertexIntersection(Real diffX,
                                                                                 Real diffY,
                                                                                 Real diffZ,
                                                                                 Real relativeVelocityDotX,
                                                                                 Real relativeVelocityDotY,
                                                                                 Real relativeVelocityDotZ,
                                                                                 Real radiusSqr) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    /// 查找直线P = Dt（其中P = (dx, dy, dz)和 D = (vx, vy, vz)与radius^ 2 rsqr的球体之间的3D线球交点的时间。
    /// 注意：仅在实际上存在交叉点时才有效。

    const auto velocitySqr = relativeVelocityDotX * relativeVelocityDotX + relativeVelocityDotY * relativeVelocityDotY + relativeVelocityDotZ * relativeVelocityDotZ;
    const auto dot = diffX * relativeVelocityDotX + diffY * relativeVelocityDotY + diffZ * relativeVelocityDotZ;
    const auto diff = diffX * diffX + diffY * diffY + diffZ * diffZ - radiusSqr;
    const auto inv = MathType::InvSqrt(MathType::FAbs(dot * dot - velocitySqr * diff));
    return diff * inv / (MathType::GetValue(1) - dot * inv);
}

template <typename Real>
Real Mathematics::DynamicFindIntersectorBox3Sphere3<Real>::GetEdgeIntersection(Real diffX,
                                                                               Real diffZ,
                                                                               Real relativeVelocityDotX,
                                                                               Real relativeVelocityDotZ,
                                                                               Real velocitySqr,
                                                                               Real radiusSqr) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    /// 查找线P = Dt（其中P = (dx,dz)和D = (vx, vz)）与radius^ 2 rsqr的圆之间的二维线圆交点的时间。
    /// 注意：仅在实际上存在交叉点时才有效。

    const auto dot = relativeVelocityDotX * diffX + relativeVelocityDotZ * diffZ;
    const auto diff = diffX * diffX + diffZ * diffZ - radiusSqr;
    const auto inv = MathType::InvSqrt(MathType::FAbs(dot * dot - velocitySqr * diff));
    return diff * inv / (MathType::GetValue(1) - dot * inv);
}

template <typename Real>
int Mathematics::DynamicFindIntersectorBox3Sphere3<Real>::FindFaceRegionIntersection(Real extentX,
                                                                                     Real extentY,
                                                                                     Real extentZ,
                                                                                     Real centerDiffDotX,
                                                                                     Real centerDiffDotY,
                                                                                     Real centerDiffDotZ,
                                                                                     Real relativeVelocityDotX,
                                                                                     Real relativeVelocityDotY,
                                                                                     Real relativeVelocityDotZ,
                                                                                     bool aboveFace) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    /// 返回面+Z上方区域中的球何时以及是否与面+Z或其任何顶点或边缘相交。
    /// 当x和y坐标在x和y范围内时，aboveFace的输入为true。
    /// 如果不是，该函数仍将起作用，但是它必须为false，以避免某些假设x和y在范围内的检查。
    /// 此功能检查面z以及速度朝向面的顶点和两个边。

    // 如果面上方，则检查是否已经相交。
    if (centerDiffDotZ <= extentZ + sphere.GetRadius() && aboveFace)
    {
        this->SetContactTime(MathType::GetValue(0));
        return -1;
    }

    /// 检查是否容易松开（沿Z轴移动）。
    if (MathType::GetValue(0) <= relativeVelocityDotZ)
    {
        return 0;
    }

    auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();

    auto velocitySqrX = relativeVelocityDotZ * relativeVelocityDotZ + relativeVelocityDotX * relativeVelocityDotX;
    auto velocitySqrY = relativeVelocityDotZ * relativeVelocityDotZ + relativeVelocityDotY * relativeVelocityDotY;
    auto diffX = MathType::GetValue(0);
    auto diffY = MathType::GetValue(0);
    auto diffZ = centerDiffDotZ - extentZ;
    auto crossX = MathType::GetValue(0);
    auto crossY = MathType::GetValue(0);
    auto signX = 0;
    auto signY = 0;

    /// 这样可以确定框的前进方向，并找到CrossX和CrossY的值，如果球心不穿过框，则它们的值为正。
    /// 然后只需要检查两个边，面和顶点是否相交。

    if (MathType::GetValue(0) <= relativeVelocityDotX)
    {
        signX = 1;
        diffX = centerDiffDotX - extentX;
        crossX = relativeVelocityDotX * diffZ - relativeVelocityDotZ * diffX;
    }
    else
    {
        signX = -1;
        diffX = centerDiffDotX + extentX;
        crossX = relativeVelocityDotZ * diffX - relativeVelocityDotX * diffZ;
    }

    if (MathType::GetValue(0) <= relativeVelocityDotY)
    {
        signY = 1;
        diffY = centerDiffDotY - extentY;
        crossY = relativeVelocityDotY * diffZ - relativeVelocityDotZ * diffY;
    }
    else
    {
        signY = -1;
        diffY = centerDiffDotY + extentY;
        crossY = relativeVelocityDotZ * diffY - relativeVelocityDotY * diffZ;
    }

    // 圆沿x边缘相交吗？
    if (sphere.GetRadius() * relativeVelocityDotX * signX < crossX)
    {
        if (radiusSqr * velocitySqrX < crossX * crossX)
        {
            // 球体在X轴（任一侧）上的过冲框。
            return 0;
        }

        // 圆是否触及y边缘？
        if (sphere.GetRadius() * relativeVelocityDotY * signY < crossY)
        {
            // 潜在的顶点相交。
            if (radiusSqr * velocitySqrY < crossY * crossY)
            {
                // 球体在y轴（任一侧）上的过冲框。
                return 0;
            }

            const Vector3 relVelocity{ relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ };
            const Vector3 diff{ diffX, diffY, diffZ };
            const auto cross = Vector3ToolsType::CrossProduct(diff, relVelocity);
            if (radiusSqr * Vector3ToolsType::GetLengthSquared(relVelocity) < Vector3ToolsType::GetLengthSquared(cross))
            {
                // 圆超出了角落的框。
                return 0;
            }

            this->SetContactTime(GetVertexIntersection(diffX, diffY, diffZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ, radiusSqr));
            x = extentX * signX;
            y = extentY * signY;
        }
        else
        {
            // x边交点
            this->SetContactTime(GetEdgeIntersection(diffX, diffZ, relativeVelocityDotX, relativeVelocityDotZ, velocitySqrX, radiusSqr));
            x = extentX * signX;
            y = centerDiffDotY + relativeVelocityDotY * this->GetContactTime();
        }
    }
    else
    {
        // 圆是否触及y边缘？
        if (sphere.GetRadius() * relativeVelocityDotY * signY < crossY)
        {
            // 潜在的y边相交。
            if (radiusSqr * velocitySqrY < crossY * crossY)
            {
                // 球体在y轴（任一侧）上的过冲框。
                return 0;
            }

            this->SetContactTime(GetEdgeIntersection(diffY, diffZ, relativeVelocityDotY, relativeVelocityDotZ, velocitySqrY, radiusSqr));
            x = centerDiffDotX + relativeVelocityDotX * this->GetContactTime();
            y = extentY * signY;
        }
        else
        {
            // 面部相交（简单）。
            this->SetContactTime((-diffZ + sphere.GetRadius()) / relativeVelocityDotZ);
            x = this->GetContactTime() * relativeVelocityDotX + centerDiffDotX;
            y = this->GetContactTime() * relativeVelocityDotY + centerDiffDotY;
        }
    }

    // 任何交点的z坐标必须是z的面。
    z = extentZ;
    return 1;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorBox3Sphere3<Real>::FindJustEdgeIntersection(Real centerDiffDotY,
                                                                                   Real extentX,
                                                                                   Real extentY,
                                                                                   Real extentZ,
                                                                                   Real diffX,
                                                                                   Real diffZ,
                                                                                   Real relativeVelocityDotX,
                                                                                   Real relativeVelocityDotY,
                                                                                   Real relativeVelocityDotZ) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    /// 查找远离y方向的边的点dx和dz的交点。 球体在cy点处，边缘在ex点处。 检查速度朝向的边缘和顶点。

    auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();
    auto diffY = MathType::GetValue(0);
    auto crossZ = MathType::GetValue(0);
    auto crossX = MathType::GetValue(0);  // 可能的边/顶点相交
    auto signY = 0;

    // 根据Vy的符号，选择速度朝向边缘的顶点，并创建crossX和crossZ，以便如果球体中心越过该边缘，它们的符号将始终为正。

    if (MathType::GetValue(0) <= relativeVelocityDotY)
    {
        signY = 1;
        diffY = centerDiffDotY - extentY;
        crossZ = diffX * relativeVelocityDotY - diffY * relativeVelocityDotX;
        crossX = diffZ * relativeVelocityDotY - diffY * relativeVelocityDotZ;
    }
    else
    {
        signY = -1;
        diffY = centerDiffDotY + extentY;
        crossZ = diffY * relativeVelocityDotX - diffX * relativeVelocityDotY;
        crossX = diffY * relativeVelocityDotZ - diffZ * relativeVelocityDotY;
    }

    // 检查此相交会在边缘的哪个位置发生。
    if (MathType::GetValue(0) <= crossZ && MathType::GetValue(0) <= crossX && relativeVelocityDotY * relativeVelocityDotY * sphere.GetRadius() * sphere.GetRadius() < crossX * crossX + crossZ * crossZ)
    {
        // 球体可能与顶点相交。
        const Vector3 relVelocity{ relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ };
        const Vector3 diff{ diffX, diffY, diffZ };
        const auto cross = Vector3ToolsType::CrossProduct(diff, relVelocity);
        if (radiusSqr * Vector3ToolsType::GetLengthSquared(relVelocity) < Vector3ToolsType::GetLengthSquared(cross))
        {
            // 球体会超出顶点上的框。
            return 0;
        }

        // 球体确实与顶点相交。
        this->SetContactTime(GetVertexIntersection(diffX, diffY, diffZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ, radiusSqr));
        x = extentX;
        y = signY * extentY;
        z = extentZ;
    }
    else
    {
        // 球体与边相交。
        auto vsqrX = relativeVelocityDotZ * relativeVelocityDotZ + relativeVelocityDotX * relativeVelocityDotX;
        this->SetContactTime(GetEdgeIntersection(diffX, diffZ, relativeVelocityDotX, relativeVelocityDotZ, vsqrX, radiusSqr));
        x = extentX;
        y = centerDiffDotY + this->GetContactTime() * relativeVelocityDotY;
        z = extentZ;
    }
    return 1;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorBox3Sphere3<Real>::FindEdgeRegionIntersection(Real extentX,
                                                                                     Real extentY,
                                                                                     Real extentZ,
                                                                                     Real centerDiffDotX,
                                                                                     Real centerDiffDotY,
                                                                                     Real centerDiffDotZ,
                                                                                     Real relativeVelocityDotX,
                                                                                     Real relativeVelocityDotY,
                                                                                     Real relativeVelocityDotZ,
                                                                                     bool aboveEdge) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    /// 假设球心在x和z平面上方的区域中。 当y坐标在y范围内时，上边的输入为true。
    /// 如果不是，该函数仍将起作用，但是该函数必须为false，以避免某些检查假设y在范围内。
    /// 该功能检查区域上方的边缘，并检查其朝向的面部的“面部区域”。

    auto diffX = centerDiffDotX - extentX;
    auto diffZ = centerDiffDotZ - extentZ;
    auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();

    if (aboveEdge)
    {
        auto diff = diffX * diffX + diffZ * diffZ - radiusSqr;
        if (diff <= MathType::GetValue(0))
        {
            // 圈子已经与盒子相交了。
            this->SetContactTime(MathType::GetValue(0));
            return -1;
        }
    }

    auto dot = relativeVelocityDotX * diffX + relativeVelocityDotZ * diffZ;
    if (MathType::GetValue(0) <= dot)
    {
        // 圆圈未移向方框。
        return 0;
    }

    // dotPerp值沿该区域的中间边缘将感兴趣区域分割开。
    auto dotPerp = relativeVelocityDotZ * diffX - relativeVelocityDotX * diffZ;
    if (MathType::GetValue(0) <= dotPerp)
    {
        // 球面朝+ z面移动。
        if (MathType::GetValue(0) <= relativeVelocityDotX)
        {
            // 经过角球，离开禁区。
            return 0;
        }

        /// 具有x-z边缘的交点。 如果存在“刮擦”表面的对象
        /// （垂直于面法线的速度，以及与半径方向平行于面法线的接触点）的问题，
        /// 则此检查可能需要更具包容性（由于浮动而导致的较小公差的错误），
        /// 因为边缘检查需要获取“刮擦”对象（因为它们用该点撞击边缘），
        /// 而面部区域检查将无法捕获该对象，因为对象没有朝着面部移动。
        if (dotPerp <= -sphere.GetRadius() * relativeVelocityDotX)
        {
            return FindJustEdgeIntersection(centerDiffDotY, extentZ, extentY, extentX, diffZ, diffX, relativeVelocityDotZ, relativeVelocityDotY, relativeVelocityDotX);
        }

        // 现在，检查z的面是否有交点。
        return FindFaceRegionIntersection(extentX, extentY, extentZ, centerDiffDotX, centerDiffDotY, centerDiffDotZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ, false);
    }
    else
    {
        // 球面朝+ x面移动。
        if (MathType::GetValue(0) <= relativeVelocityDotZ)
        {
            // 经过角球，离开禁区。
            return 0;
        }

        /// 检查与x-z边缘的交点。 请参阅上面有关“刮取”对象的注释。
        if (sphere.GetRadius() * relativeVelocityDotZ <= dotPerp)
        {
            // 可能的边/顶点相交。
            return FindJustEdgeIntersection(centerDiffDotY, extentX, extentY, extentZ, diffX, diffZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ);
        }

        // 现在，检查x的交点。
        const auto result = FindFaceRegionIntersection(extentZ, extentY, extentX, centerDiffDotZ, centerDiffDotY, centerDiffDotX, relativeVelocityDotZ, relativeVelocityDotY, relativeVelocityDotX, false);
        std::swap(x, z);
        return result;
    }
}

template <typename Real>
int Mathematics::DynamicFindIntersectorBox3Sphere3<Real>::FindVertexRegionIntersection(Real extentX,
                                                                                       Real extentY,
                                                                                       Real extentZ,
                                                                                       Real centerDiffDotX,
                                                                                       Real centerDiffDotY,
                                                                                       Real centerDiffDotZ,
                                                                                       Real relativeVelocityDotX,
                                                                                       Real relativeVelocityDotY,
                                                                                       Real relativeVelocityDotZ) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    /// 假设球体位于顶点 +ex, +ey, +ez上方。
    auto diffX = centerDiffDotX - extentX;
    auto diffY = centerDiffDotY - extentY;
    auto diffZ = centerDiffDotZ - extentZ;
    auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();
    auto diff = diffX * diffX + diffY * diffY + diffZ * diffZ - radiusSqr;
    if (diff <= MathType::GetValue(0))
    {
        // 球已经与盒子相交了。
        this->SetContactTime(MathType::GetValue(0));
        return -1;
    }

    if (MathType::GetValue(0) <= relativeVelocityDotX * diffX + relativeVelocityDotY * diffY + relativeVelocityDotZ * diffZ)
    {
        // 球体未移向盒子。
        return 0;
    }

    /// 该框可分为3个区域，从而简化了查看球体撞击的检查。 区域被哪个边缘（由顶点和某个轴形成）最接近速度矢量划分。

    /// 要检查它是否碰到顶点，请查看它要朝向的边缘（E）。
    /// 创建一个由其他两个边（以E为平面法线）形成的平面，顶点为原点。
    /// 沿该平面中由球心和速度作为方向的直线的轴上的截距将为fCrossAxis/fVEdge。
    /// 因此，从原点到速度方向上与球体的直线相交的平面中的点的距离将是这两个截距的平方和。
    /// 如果该总和小于半径的平方，则球体将撞击顶点，否则它将继续经过顶点。
    /// 如果未命中，则由于知道盒子在哪个边缘附近，因此可以使用查找边缘区域测试。

    /// 同样，由于条件的限制，仅会出现fCrossEdge值的这六个情况（每个区域两个，因为fCrossEdge可以为+或-）。

    /// 第三种情况也会拾取D = V的情况，从而导致零交叉。

    auto crossX = relativeVelocityDotY * diffZ - relativeVelocityDotZ * diffY;
    auto crossY = relativeVelocityDotX * diffZ - relativeVelocityDotZ * diffX;
    auto crossZ = relativeVelocityDotY * diffX - relativeVelocityDotX * diffY;
    auto crossXSqr = crossX * crossX;
    auto crossYSqr = crossY * crossY;
    auto crossZSqr = crossZ * crossZ;
    auto relativeVelocityDotXSqr = relativeVelocityDotX * relativeVelocityDotX;
    auto relativeVelocityDotYSqr = relativeVelocityDotY * relativeVelocityDotY;
    auto relativeVelocityDotZSqr = relativeVelocityDotZ * relativeVelocityDotZ;

    // 与顶点相交？
    if ((crossY < MathType::GetValue(0) && MathType::GetValue(0) <= crossZ && crossYSqr + crossZSqr <= radiusSqr * relativeVelocityDotXSqr) || (crossZ < MathType::GetValue(0) && crossX < MathType::GetValue(0) && crossXSqr + crossZSqr <= radiusSqr * relativeVelocityDotYSqr) || (MathType::GetValue(0) <= crossY && MathType::GetValue(0) <= crossX && crossXSqr + crossYSqr <= radiusSqr * relativeVelocityDotZSqr))
    {
        // 标准线球交点。
        this->SetContactTime(GetVertexIntersection(diffX, diffY, diffZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ, sphere.GetRadius() * sphere.GetRadius()));
        x = this->GetContactTime() * relativeVelocityDotX + centerDiffDotX;
        y = this->GetContactTime() * relativeVelocityDotY + centerDiffDotY;
        z = this->GetContactTime() * relativeVelocityDotZ + centerDiffDotZ;
        return 1;
    }
    else if (crossY < MathType::GetValue(0) && MathType::GetValue(0) <= crossZ)
    {
        // x边缘区域，检查y，z平面。
        const auto result = FindEdgeRegionIntersection(extentY, extentX, extentZ, centerDiffDotY, centerDiffDotX, centerDiffDotZ, relativeVelocityDotY, relativeVelocityDotX, relativeVelocityDotZ, false);
        std::swap(x, y);
        return result;
    }
    else if (crossZ < MathType::GetValue(0) && crossX < MathType::GetValue(0))
    {
        // y边缘区域，检查x，z平面。
        return FindEdgeRegionIntersection(extentX, extentY, extentZ, centerDiffDotX, centerDiffDotY, centerDiffDotZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ, false);
    }
    else  // crossY >= 0 && crossX >= 0
    {
        // z边缘区域，检查x，y平面。
        const auto result = FindEdgeRegionIntersection(extentX, extentZ, extentY, centerDiffDotX, centerDiffDotZ, centerDiffDotY, relativeVelocityDotX, relativeVelocityDotZ, relativeVelocityDotY, false);
        std::swap(z, y);
        return result;
    }
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_DETAIL_H