///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/21 15:23)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_ACHIEVE_H

#include "StaticTestIntersectorBox3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorBox3Sphere3<Real>::StaticTestIntersectorBox3Sphere3(const Box3& box, const Sphere3& sphere, const Real epsilon)
    : ParentType{ epsilon }, m_Box{ box }, m_Sphere{ sphere }
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
const Mathematics::Box3<Real> Mathematics::StaticTestIntersectorBox3Sphere3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorBox3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox3Sphere3<Real>::Test()
{
    // ͨ��������ת��Ϊ������ϵ�����Ժ�������ϵ�еĽ�����
    auto centerDiff = m_Sphere.GetCenter() - m_Box.GetCenter();

    auto centerDiffX = Math::FAbs(Vector3DTools::DotProduct(centerDiff, m_Box.GetAxis(0)));
    auto centerDiffY = Math::FAbs(Vector3DTools::DotProduct(centerDiff, m_Box.GetAxis(1)));
    auto centerDiffZ = Math::FAbs(Vector3DTools::DotProduct(centerDiff, m_Box.GetAxis(2)));
    auto diffX = centerDiffX - m_Box.GetExtent(0);
    auto diffY = centerDiffY - m_Box.GetExtent(1);
    auto diffZ = centerDiffZ - m_Box.GetExtent(2);

    if (centerDiffX <= m_Box.GetExtent(0))
    {
        if (centerDiffY <= m_Box.GetExtent(1))
        {
            if (centerDiffZ <= m_Box.GetExtent(2))
            {
                // ���������ڿ���
                this->SetIntersectionType(IntersectionType::Other);
                return;
            }
            else
            {
                // ����z��Ǳ�������ཻ��
                if (diffZ <= m_Sphere.GetRadius())
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
            if (centerDiffZ <= m_Box.GetExtent(2))
            {
                // Potential sphere-face intersection with face y.
                if (diffY <= m_Sphere.GetRadius())
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
                auto radiusSqr = m_Sphere.GetRadius() * m_Sphere.GetRadius();
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
        if (centerDiffY <= m_Box.GetExtent(1))
        {
            if (centerDiffZ <= m_Box.GetExtent(2))
            {
                // ����x��Ǳ�������ཻ��
                if (diffX <= m_Sphere.GetRadius())
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
                auto radiusSqr = m_Sphere.GetRadius() * m_Sphere.GetRadius();
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
            if (centerDiffZ <= m_Box.GetExtent(2))
            {
                // Ǳ�ڵ�������ߵĽ��㣬�������x��y�γɡ�
                auto radiusSqr = m_Sphere.GetRadius() * m_Sphere.GetRadius();
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
                auto radiusSqr = m_Sphere.GetRadius() * m_Sphere.GetRadius();
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_ACHIEVE_H