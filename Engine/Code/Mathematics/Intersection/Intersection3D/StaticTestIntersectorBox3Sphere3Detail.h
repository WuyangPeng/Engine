///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:21)

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
    // 通过将球体转换为该坐标系来测试盒子坐标系中的交集。
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
                // 球体中心在框内
                this->SetIntersectionType(IntersectionType::Other);
                return;
            }
            else
            {
                // 与面z的潜在球面相交。
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
                // 潜在的球面与边的交点，其边由面y和z形成。
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
                // 与面x的潜在球面相交。
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
                // 潜在的球面边缘相交，其边由面x和z形成。
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
                // 潜在的球面与边的交点，其边由面x和y形成。
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
                // 由面x，y，z形成的拐角处的潜在球体-顶点交点。
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