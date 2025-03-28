///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:21)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_DETAIL_H

#include "StaticTestIntersectorBox3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorBox3Sphere3<Real>::StaticTestIntersectorBox3Sphere3(const Box3& box, const Sphere3& sphere, const Real epsilon)
    : ParentType{ epsilon }, box{ box }, sphere{ sphere }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorBox3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Box3<Real> Mathematics::StaticTestIntersectorBox3Sphere3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorBox3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox3Sphere3<Real>::Test()
{
    // ͨ��������ת��Ϊ������ϵ�����Ժ�������ϵ�еĽ�����
    auto centerDiff = sphere.GetCenter() - box.GetCenter();

    auto centerDiffX = MathType::FAbs(Vector3ToolsType::DotProduct(centerDiff, box.GetAxis(0)));
    auto centerDiffY = MathType::FAbs(Vector3ToolsType::DotProduct(centerDiff, box.GetAxis(1)));
    auto centerDiffZ = MathType::FAbs(Vector3ToolsType::DotProduct(centerDiff, box.GetAxis(2)));
    auto diffX = centerDiffX - box.GetExtent(0);
    auto diffY = centerDiffY - box.GetExtent(1);
    auto diffZ = centerDiffZ - box.GetExtent(2);

    if (centerDiffX <= box.GetExtent(0))
    {
        if (centerDiffY <= box.GetExtent(1))
        {
            if (centerDiffZ <= box.GetExtent(2))
            {
                // ���������ڿ���
                this->SetIntersectionType(IntersectionType::Other);
                return;
            }
            else
            {
                // ����z��Ǳ�������ཻ��
                if (diffZ <= sphere.GetRadius())
                {
                    this->SetIntersectionType(IntersectionType::Other);
                }
                else
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                }
            }
        }
        else
        {
            if (centerDiffZ <= box.GetExtent(2))
            {
                // Potential sphere-face intersection with face y.
                if (diffY <= sphere.GetRadius())
                {
                    this->SetIntersectionType(IntersectionType::Other);
                }
                else
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                }
            }
            else
            {
                // Ǳ�ڵ�������ߵĽ��㣬�������y��z�γɡ�
                auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();
                if (diffY * diffY + diffZ * diffZ <= radiusSqr)
                {
                    this->SetIntersectionType(IntersectionType::Other);
                }
                else
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                }
            }
        }
    }
    else
    {
        if (centerDiffY <= box.GetExtent(1))
        {
            if (centerDiffZ <= box.GetExtent(2))
            {
                // ����x��Ǳ�������ཻ��
                if (diffX <= sphere.GetRadius())
                {
                    this->SetIntersectionType(IntersectionType::Other);
                }
                else
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                }
            }
            else
            {
                // Ǳ�ڵ������Ե�ཻ���������x��z�γɡ�
                auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();
                if (diffX * diffX + diffZ * diffZ <= radiusSqr)
                {
                    this->SetIntersectionType(IntersectionType::Other);
                }
                else
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                }
            }
        }
        else
        {
            if (centerDiffZ <= box.GetExtent(2))
            {
                // Ǳ�ڵ�������ߵĽ��㣬�������x��y�γɡ�
                auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();
                if (diffX * diffX + diffY * diffY <= radiusSqr)
                {
                    this->SetIntersectionType(IntersectionType::Other);
                }
                else
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                }
            }
            else
            {
                // ����x��y��z�γɵĹսǴ���Ǳ������-���㽻�㡣
                auto radiusSqr = sphere.GetRadius() * sphere.GetRadius();
                if (diffX * diffX + diffY * diffY + diffZ * diffZ <= radiusSqr)
                {
                    this->SetIntersectionType(IntersectionType::Other);
                }
                else
                {
                    this->SetIntersectionType(IntersectionType::Empty);
                }
            }
        }
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_DETAIL_H