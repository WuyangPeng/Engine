///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:14)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_ACHIEVE_H

#include "StaticFindIntersectorSphere3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Objects3D/Circle3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::StaticFindIntersectorSphere3Sphere3(const Sphere3Type& sphere0, const Sphere3Type& sphere1, const Real epsilon)
    : ParentType{ epsilon }, sphere0{ sphere0 }, sphere1{ sphere1 }, circle{ Vector3Type::GetZero(), Vector3Type::GetZero(), Vector3Type::GetZero(), Vector3Type::GetZero(), MathType::GetValue(0) }, contactPoint{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::GetSphere0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere0;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::GetSphere1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::Find()
{
    // 相交平面必须以N为法线。
    auto center1MinusCenter0 = sphere1.GetCenter() - sphere0.GetCenter();
    auto sqrLen = Vector3ToolsType::GetLengthSquared(center1MinusCenter0);
    auto radius0 = sphere0.GetRadius();
    auto radius1 = sphere1.GetRadius();

    auto radiusSum = radius0 + radius1;
    auto radiusSumSqr = radiusSum * radiusSum;
    if (radiusSumSqr < sqrLen)
    {
        // 球体是不相交的/分离的。
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (MathType::Approximate(sqrLen, radiusSumSqr))
    {
        // 球体刚刚接触。 调用者必须调用GetIntersectionType() 以确定发生了哪种类型的相交。
        // 在这种情况下，应该调用 GetContactPoint()，而不是GetCircle()。 仅在调用者不测试交叉点类型的情况下设置圆形参数。
        center1MinusCenter0.Normalize();
        contactPoint = sphere0.GetCenter() + radius0 * center1MinusCenter0;
        circle = Circle3Type{ contactPoint, Vector3Type::GetZero(), Vector3Type::GetZero(), center1MinusCenter0, MathType::GetValue(0) };
        this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    auto radiusDiff = radius0 - radius1;
    auto radiusDiffSqr = radiusDiff * radiusDiff;
    if (sqrLen < radiusDiffSqr)
    {
        /// 一个领域严格包含在另一个领域中。 调用者必须调用 GetIntersectionType()以确定发生了哪种类型的相交。
        /// 在这种情况下，不应调用GetCircle()和GetContactPoint()。
        ///  仅在调用者不测试交叉点类型的情况下设置圆形和接触参数，但选择是任意的。
        center1MinusCenter0.Normalize();
        contactPoint = MathType::GetRational(1, 2) * (sphere0.GetCenter() + sphere1.GetCenter());
        circle = Circle3Type{ contactPoint, Vector3Type::GetZero(), Vector3Type::GetZero(), center1MinusCenter0, MathType::GetValue(0) };

        this->SetIntersectionType(radiusDiff <= MathType::GetValue(0) ? IntersectionType::Sphere0 : IntersectionType::Sphere1);
        return;
    }

    if (MathType::Approximate(sqrLen, radiusDiffSqr))
    {
        /// 一个球包含在另一个球中，但只有一个接触点。
        /// 调用者必须调用GetIntersectionType()以确定发生了哪种类型的相交。
        /// 在这种情况下，应调用GetContactPoint()。
        /// 仅在调用者不测试交叉点类型的情况下设置圆形参数。
        center1MinusCenter0.Normalize();

        if (radiusDiff <= MathType::GetValue(0))
        {
            contactPoint = sphere1.GetCenter() + radius1 * center1MinusCenter0;
            this->SetIntersectionType(IntersectionType::Sphere0Point);
        }
        else
        {
            contactPoint = sphere0.GetCenter() + radius0 * center1MinusCenter0;
            this->SetIntersectionType(IntersectionType::Sphere1Point);
        }

        circle = Circle3Type(contactPoint, Vector3Type::GetZero(), Vector3Type::GetZero(), center1MinusCenter0, MathType::GetValue(0));

        return;
    }

    // 计算相交圆具有中心的t：K = C0 + t*(C1 - C0)。
    auto t = MathType::GetRational(1, 2) * (MathType::GetValue(1) + radiusDiff * radiusSum / sqrLen);

    // 相交圆的中心和半径。

    // 计算圆平面的N，U和V。
    center1MinusCenter0.Normalize();

    const auto Vector3OrthonormalBasis = Vector3ToolsType::GenerateComplementBasis(center1MinusCenter0);
    circle = Circle3Type{ sphere0.GetCenter() + t * center1MinusCenter0, Vector3OrthonormalBasis.GetUVector(),
                      Vector3OrthonormalBasis.GetVVector(),
                      center1MinusCenter0,
                      MathType::Sqrt(MathType::FAbs(radius0 * radius0 - t * t * sqrLen)) };

    // 相交是一个圆。
    this->SetIntersectionType(IntersectionType::Circle);
}

template <typename Real>
Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorSphere3Sphere3<Real>::GetContactPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return contactPoint;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_ACHIEVE_H