///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:26)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_BOX3_DETAIL_H

#include "StaticTestIntersectorLine3Box3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine3Box3<Real>::StaticTestIntersectorLine3Box3(const Line3& line, const Box3& box, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, box{ box }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorLine3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticTestIntersectorLine3Box3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return line;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::StaticTestIntersectorLine3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine3Box3<Real>::Test()
{
    std::array<Real, 3> awdu{};
    std::array<Real, 3> awxddu{};

    auto diff = line.GetOrigin() - box.GetCenter();
    const auto wxD = Vector3Tools::CrossProduct(line.GetDirection(), diff);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    awdu[1] = MathType::FAbs(Vector3Tools::DotProduct(line.GetDirection(), box.GetAxis(1)));
    awdu[2] = MathType::FAbs(Vector3Tools::DotProduct(line.GetDirection(), box.GetAxis(2)));
    awxddu[0] = MathType::FAbs(Vector3Tools::DotProduct(wxD, box.GetAxis(0)));
    auto rhs = box.GetExtent(1) * awdu[2] + box.GetExtent(2) * awdu[1];
    if (rhs < awxddu[0])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    awdu[0] = MathType::FAbs(Vector3Tools::DotProduct(line.GetDirection(), box.GetAxis(0)));
    awxddu[1] = MathType::FAbs(Vector3Tools::DotProduct(wxD, box.GetAxis(1)));
    rhs = box.GetExtent(0) * awdu[2] + box.GetExtent(2) * awdu[0];
    if (rhs < awxddu[1])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    awxddu[2] = MathType::FAbs(Vector3Tools::DotProduct(wxD, box.GetAxis(2)));
    rhs = box.GetExtent(0) * awdu[1] + box.GetExtent(1) * awdu[0];
    if (rhs < awxddu[2])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

#include SYSTEM_WARNING_POP

    this->SetIntersectionType(IntersectionType::Point);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_BOX3_DETAIL_H