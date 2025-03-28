///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 18:04)

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
    /// ��������ں��ӵ�����ϵ�Ľ��㡣 ���彫ת��Ϊ�������꣬����������ٶ�������ں��ӵġ�
    auto centerDiff = sphere.GetCenter() - box.GetCenter();
    auto relativeVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    auto centerDiffDotX = Vector3ToolsType::DotProduct(centerDiff, box.GetAxis(0));
    auto centerDiffDotY = Vector3ToolsType::DotProduct(centerDiff, box.GetAxis(1));
    auto centerDiffDotZ = Vector3ToolsType::DotProduct(centerDiff, box.GetAxis(2));
    auto relativeVelocityDotX = Vector3ToolsType::DotProduct(relativeVelocity, box.GetAxis(0));
    auto relativeVelocityDotY = Vector3ToolsType::DotProduct(relativeVelocity, box.GetAxis(1));
    auto relativeVelocityDotZ = Vector3ToolsType::DotProduct(relativeVelocity, box.GetAxis(2));

    // �������ת����һ���˷�Բ��
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

    // ��������ꡣ
    auto result = 0;

    if (centerDiffDotX <= box.GetExtent(0))
    {
        if (centerDiffDotY <= box.GetExtent(1))
        {
            if (centerDiffDotZ <= box.GetExtent(2))
            {
                // ���������ں����ڲ��� ���䷵��Ϊ�Ӵ��㣬�����桰��������������͡�
                this->SetContactTime(MathType::GetValue(0));
                contactPoint = sphere.GetCenter();
                this->SetIntersectionType(IntersectionType::Other);
                return;
            }
            else
            {
                // ������Z���ϵ��Ϸ���
                result = FindFaceRegionIntersection(box.GetExtent(0), box.GetExtent(1), box.GetExtent(2), centerDiffDotX, centerDiffDotY, centerDiffDotZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ, true);
            }
        }
        else
        {
            if (centerDiffDotZ <= box.GetExtent(2))
            {
                // ������Y���ϵ��Ϸ���
                result = FindFaceRegionIntersection(box.GetExtent(0), box.GetExtent(2), box.GetExtent(1), centerDiffDotX, centerDiffDotZ, centerDiffDotY, relativeVelocityDotX, relativeVelocityDotZ, relativeVelocityDotY, true);
            }
            else
            {
                // ����λ����y��z�γɵı�Ե�Ϸ���
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
                // ������X���ϵ��Ϸ���
                result = FindFaceRegionIntersection(box.GetExtent(1), box.GetExtent(2), box.GetExtent(0), centerDiffDotY, centerDiffDotZ, centerDiffDotX, relativeVelocityDotY, relativeVelocityDotZ, relativeVelocityDotX, true);
            }
            else
            {
                // ��������x��z�γɵı�Ե�Ϸ���
                result = FindEdgeRegionIntersection(box.GetExtent(0), box.GetExtent(1), box.GetExtent(2), centerDiffDotX, centerDiffDotY, centerDiffDotZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ, true);
            }
        }
        else
        {
            if (centerDiffDotZ <= box.GetExtent(2))
            {
                // ����λ����x��y�γɵı�Ե�Ϸ���
                result = FindEdgeRegionIntersection(box.GetExtent(0), box.GetExtent(2), box.GetExtent(1), centerDiffDotX, centerDiffDotZ, centerDiffDotY, relativeVelocityDotX, relativeVelocityDotZ, relativeVelocityDotY, true);
            }
            else
            {
                // ����������x��y��z�γɵĽǵ��Ϸ�
                result = FindVertexRegionIntersection(box.GetExtent(0), box.GetExtent(1), box.GetExtent(2), centerDiffDotX, centerDiffDotY, centerDiffDotZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ);
            }
        }
    }

    if (result == 0 || this->GetContactTime() > this->GetTMax())
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // ����ʵ�ʵ��ཻ�������ƻ��������꣩��
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
    /// ����ֱ��P = Dt������P = (dx, dy, dz)�� D = (vx, vy, vz)��radius^ 2 rsqr������֮���3D���򽻵��ʱ�䡣
    /// ע�⣺����ʵ���ϴ��ڽ����ʱ����Ч��

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
    /// ������P = Dt������P = (dx,dz)��D = (vx, vz)����radius^ 2 rsqr��Բ֮��Ķ�ά��Բ�����ʱ�䡣
    /// ע�⣺����ʵ���ϴ��ڽ����ʱ����Ч��

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
    /// ������+Z�Ϸ������е����ʱ�Լ��Ƿ�����+Z�����κζ�����Ե�ཻ��
    /// ��x��y������x��y��Χ��ʱ��aboveFace������Ϊtrue��
    /// ������ǣ��ú����Խ������ã�����������Ϊfalse���Ա���ĳЩ����x��y�ڷ�Χ�ڵļ�顣
    /// �˹��ܼ����z�Լ��ٶȳ�����Ķ���������ߡ�

    // ������Ϸ��������Ƿ��Ѿ��ཻ��
    if (centerDiffDotZ <= extentZ + sphere.GetRadius() && aboveFace)
    {
        this->SetContactTime(MathType::GetValue(0));
        return -1;
    }

    /// ����Ƿ������ɿ�����Z���ƶ�����
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

    /// ��������ȷ�����ǰ�����򣬲��ҵ�CrossX��CrossY��ֵ��������Ĳ������������ǵ�ֵΪ����
    /// Ȼ��ֻ��Ҫ��������ߣ���Ͷ����Ƿ��ཻ��

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

    // Բ��x��Ե�ཻ��
    if (sphere.GetRadius() * relativeVelocityDotX * signX < crossX)
    {
        if (radiusSqr * velocitySqrX < crossX * crossX)
        {
            // ������X�ᣨ��һ�ࣩ�ϵĹ����
            return 0;
        }

        // Բ�Ƿ񴥼�y��Ե��
        if (sphere.GetRadius() * relativeVelocityDotY * signY < crossY)
        {
            // Ǳ�ڵĶ����ཻ��
            if (radiusSqr * velocitySqrY < crossY * crossY)
            {
                // ������y�ᣨ��һ�ࣩ�ϵĹ����
                return 0;
            }

            const Vector3 relVelocity{ relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ };
            const Vector3 diff{ diffX, diffY, diffZ };
            const auto cross = Vector3ToolsType::CrossProduct(diff, relVelocity);
            if (radiusSqr * Vector3ToolsType::GetLengthSquared(relVelocity) < Vector3ToolsType::GetLengthSquared(cross))
            {
                // Բ�����˽���Ŀ�
                return 0;
            }

            this->SetContactTime(GetVertexIntersection(diffX, diffY, diffZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ, radiusSqr));
            x = extentX * signX;
            y = extentY * signY;
        }
        else
        {
            // x�߽���
            this->SetContactTime(GetEdgeIntersection(diffX, diffZ, relativeVelocityDotX, relativeVelocityDotZ, velocitySqrX, radiusSqr));
            x = extentX * signX;
            y = centerDiffDotY + relativeVelocityDotY * this->GetContactTime();
        }
    }
    else
    {
        // Բ�Ƿ񴥼�y��Ե��
        if (sphere.GetRadius() * relativeVelocityDotY * signY < crossY)
        {
            // Ǳ�ڵ�y���ཻ��
            if (radiusSqr * velocitySqrY < crossY * crossY)
            {
                // ������y�ᣨ��һ�ࣩ�ϵĹ����
                return 0;
            }

            this->SetContactTime(GetEdgeIntersection(diffY, diffZ, relativeVelocityDotY, relativeVelocityDotZ, velocitySqrY, radiusSqr));
            x = centerDiffDotX + relativeVelocityDotX * this->GetContactTime();
            y = extentY * signY;
        }
        else
        {
            // �沿�ཻ���򵥣���
            this->SetContactTime((-diffZ + sphere.GetRadius()) / relativeVelocityDotZ);
            x = this->GetContactTime() * relativeVelocityDotX + centerDiffDotX;
            y = this->GetContactTime() * relativeVelocityDotY + centerDiffDotY;
        }
    }

    // �κν����z���������z���档
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
    /// ����Զ��y����ıߵĵ�dx��dz�Ľ��㡣 ������cy�㴦����Ե��ex�㴦�� ����ٶȳ���ı�Ե�Ͷ��㡣

    auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();
    auto diffY = MathType::GetValue(0);
    auto crossZ = MathType::GetValue(0);
    auto crossX = MathType::GetValue(0);  // ���ܵı�/�����ཻ
    auto signY = 0;

    // ����Vy�ķ��ţ�ѡ���ٶȳ����Ե�Ķ��㣬������crossX��crossZ���Ա������������Խ���ñ�Ե�����ǵķ��Ž�ʼ��Ϊ����

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

    // �����ཻ���ڱ�Ե���ĸ�λ�÷�����
    if (MathType::GetValue(0) <= crossZ && MathType::GetValue(0) <= crossX && relativeVelocityDotY * relativeVelocityDotY * sphere.GetRadius() * sphere.GetRadius() < crossX * crossX + crossZ * crossZ)
    {
        // ��������붥���ཻ��
        const Vector3 relVelocity{ relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ };
        const Vector3 diff{ diffX, diffY, diffZ };
        const auto cross = Vector3ToolsType::CrossProduct(diff, relVelocity);
        if (radiusSqr * Vector3ToolsType::GetLengthSquared(relVelocity) < Vector3ToolsType::GetLengthSquared(cross))
        {
            // ����ᳬ�������ϵĿ�
            return 0;
        }

        // ����ȷʵ�붥���ཻ��
        this->SetContactTime(GetVertexIntersection(diffX, diffY, diffZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ, radiusSqr));
        x = extentX;
        y = signY * extentY;
        z = extentZ;
    }
    else
    {
        // ��������ཻ��
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
    /// ����������x��zƽ���Ϸ��������С� ��y������y��Χ��ʱ���ϱߵ�����Ϊtrue��
    /// ������ǣ��ú����Խ������ã����Ǹú�������Ϊfalse���Ա���ĳЩ������y�ڷ�Χ�ڡ�
    /// �ù��ܼ�������Ϸ��ı�Ե��������䳯����沿�ġ��沿���򡱡�

    auto diffX = centerDiffDotX - extentX;
    auto diffZ = centerDiffDotZ - extentZ;
    auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();

    if (aboveEdge)
    {
        auto diff = diffX * diffX + diffZ * diffZ - radiusSqr;
        if (diff <= MathType::GetValue(0))
        {
            // Ȧ���Ѿ�������ཻ�ˡ�
            this->SetContactTime(MathType::GetValue(0));
            return -1;
        }
    }

    auto dot = relativeVelocityDotX * diffX + relativeVelocityDotZ * diffZ;
    if (MathType::GetValue(0) <= dot)
    {
        // ԲȦδ���򷽿�
        return 0;
    }

    // dotPerpֵ�ظ�������м��Ե������Ȥ����ָ��
    auto dotPerp = relativeVelocityDotZ * diffX - relativeVelocityDotX * diffZ;
    if (MathType::GetValue(0) <= dotPerp)
    {
        // ���泯+ z���ƶ���
        if (MathType::GetValue(0) <= relativeVelocityDotX)
        {
            // ���������뿪������
            return 0;
        }

        /// ����x-z��Ե�Ľ��㡣 ������ڡ��β�������Ķ���
        /// ����ֱ���淨�ߵ��ٶȣ��Լ���뾶����ƽ�����淨�ߵĽӴ��㣩�����⣬
        /// ��˼�������Ҫ���߰����ԣ����ڸ��������µĽ�С����Ĵ��󣩣�
        /// ��Ϊ��Ե�����Ҫ��ȡ���β���������Ϊ�����øõ�ײ����Ե����
        /// ���沿�����齫�޷�����ö�����Ϊ����û�г����沿�ƶ���
        if (dotPerp <= -sphere.GetRadius() * relativeVelocityDotX)
        {
            return FindJustEdgeIntersection(centerDiffDotY, extentZ, extentY, extentX, diffZ, diffX, relativeVelocityDotZ, relativeVelocityDotY, relativeVelocityDotX);
        }

        // ���ڣ����z�����Ƿ��н��㡣
        return FindFaceRegionIntersection(extentX, extentY, extentZ, centerDiffDotX, centerDiffDotY, centerDiffDotZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ, false);
    }
    else
    {
        // ���泯+ x���ƶ���
        if (MathType::GetValue(0) <= relativeVelocityDotZ)
        {
            // ���������뿪������
            return 0;
        }

        /// �����x-z��Ե�Ľ��㡣 ����������йء���ȡ�������ע�͡�
        if (sphere.GetRadius() * relativeVelocityDotZ <= dotPerp)
        {
            // ���ܵı�/�����ཻ��
            return FindJustEdgeIntersection(centerDiffDotY, extentX, extentY, extentZ, diffX, diffZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ);
        }

        // ���ڣ����x�Ľ��㡣
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
    /// ��������λ�ڶ��� +ex, +ey, +ez�Ϸ���
    auto diffX = centerDiffDotX - extentX;
    auto diffY = centerDiffDotY - extentY;
    auto diffZ = centerDiffDotZ - extentZ;
    auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();
    auto diff = diffX * diffX + diffY * diffY + diffZ * diffZ - radiusSqr;
    if (diff <= MathType::GetValue(0))
    {
        // ���Ѿ�������ཻ�ˡ�
        this->SetContactTime(MathType::GetValue(0));
        return -1;
    }

    if (MathType::GetValue(0) <= relativeVelocityDotX * diffX + relativeVelocityDotY * diffY + relativeVelocityDotZ * diffZ)
    {
        // ����δ������ӡ�
        return 0;
    }

    /// �ÿ�ɷ�Ϊ3�����򣬴Ӷ����˲鿴����ײ���ļ�顣 �����ĸ���Ե���ɶ����ĳ�����γɣ���ӽ��ٶ�ʸ�����֡�

    /// Ҫ������Ƿ��������㣬��鿴��Ҫ����ı�Ե��E����
    /// ����һ�������������ߣ���EΪƽ�淨�ߣ��γɵ�ƽ�棬����Ϊԭ�㡣
    /// �ظ�ƽ���������ĺ��ٶ���Ϊ�����ֱ�ߵ����ϵĽؾཫΪfCrossAxis/fVEdge��
    /// ��ˣ���ԭ�㵽�ٶȷ������������ֱ���ཻ��ƽ���еĵ�ľ��뽫���������ؾ��ƽ���͡�
    /// ������ܺ�С�ڰ뾶��ƽ���������彫ײ�����㣬�������������������㡣
    /// ���δ���У�������֪���������ĸ���Ե��������˿���ʹ�ò��ұ�Ե������ԡ�

    /// ͬ�����������������ƣ��������fCrossEdgeֵ�������������ÿ��������������ΪfCrossEdge����Ϊ+��-����

    /// ���������Ҳ��ʰȡD = V��������Ӷ������㽻�档

    auto crossX = relativeVelocityDotY * diffZ - relativeVelocityDotZ * diffY;
    auto crossY = relativeVelocityDotX * diffZ - relativeVelocityDotZ * diffX;
    auto crossZ = relativeVelocityDotY * diffX - relativeVelocityDotX * diffY;
    auto crossXSqr = crossX * crossX;
    auto crossYSqr = crossY * crossY;
    auto crossZSqr = crossZ * crossZ;
    auto relativeVelocityDotXSqr = relativeVelocityDotX * relativeVelocityDotX;
    auto relativeVelocityDotYSqr = relativeVelocityDotY * relativeVelocityDotY;
    auto relativeVelocityDotZSqr = relativeVelocityDotZ * relativeVelocityDotZ;

    // �붥���ཻ��
    if ((crossY < MathType::GetValue(0) && MathType::GetValue(0) <= crossZ && crossYSqr + crossZSqr <= radiusSqr * relativeVelocityDotXSqr) || (crossZ < MathType::GetValue(0) && crossX < MathType::GetValue(0) && crossXSqr + crossZSqr <= radiusSqr * relativeVelocityDotYSqr) || (MathType::GetValue(0) <= crossY && MathType::GetValue(0) <= crossX && crossXSqr + crossYSqr <= radiusSqr * relativeVelocityDotZSqr))
    {
        // ��׼���򽻵㡣
        this->SetContactTime(GetVertexIntersection(diffX, diffY, diffZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ, sphere.GetRadius() * sphere.GetRadius()));
        x = this->GetContactTime() * relativeVelocityDotX + centerDiffDotX;
        y = this->GetContactTime() * relativeVelocityDotY + centerDiffDotY;
        z = this->GetContactTime() * relativeVelocityDotZ + centerDiffDotZ;
        return 1;
    }
    else if (crossY < MathType::GetValue(0) && MathType::GetValue(0) <= crossZ)
    {
        // x��Ե���򣬼��y��zƽ�档
        const auto result = FindEdgeRegionIntersection(extentY, extentX, extentZ, centerDiffDotY, centerDiffDotX, centerDiffDotZ, relativeVelocityDotY, relativeVelocityDotX, relativeVelocityDotZ, false);
        std::swap(x, y);
        return result;
    }
    else if (crossZ < MathType::GetValue(0) && crossX < MathType::GetValue(0))
    {
        // y��Ե���򣬼��x��zƽ�档
        return FindEdgeRegionIntersection(extentX, extentY, extentZ, centerDiffDotX, centerDiffDotY, centerDiffDotZ, relativeVelocityDotX, relativeVelocityDotY, relativeVelocityDotZ, false);
    }
    else  // crossY >= 0 && crossX >= 0
    {
        // z��Ե���򣬼��x��yƽ�档
        const auto result = FindEdgeRegionIntersection(extentX, extentZ, extentY, centerDiffDotX, centerDiffDotZ, centerDiffDotY, relativeVelocityDotX, relativeVelocityDotZ, relativeVelocityDotY, false);
        std::swap(z, y);
        return result;
    }
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_DETAIL_H