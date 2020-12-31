///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/22 19:20)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_ACHIEVE_H

#include "StaticTestIntersectorBox2Box2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "Mathematics/Objects2D/Box2Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorBox2Box2<Real>::StaticTestIntersectorBox2Box2(const Box2& lhsBox, const Box2& rhsBox, const Real epsilon)
    : ParentType{ epsilon }, m_LhsBox{ lhsBox }, m_RhsBox{ rhsBox }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox2Box2<Real>::Test()
{
    // ��������ĵľ��룬D = C1 - C0��
    auto boxCentersDifference = m_RhsBox.GetCenter() - m_LhsBox.GetCenter();

    // �� C0 + t * A0
    auto absLhs0DotRhs0 = Math::FAbs(Vector2DTools::DotProduct(m_LhsBox.GetAxis0(), m_RhsBox.GetAxis0()));
    auto absLhs0DotRhs1 = Math::FAbs(Vector2DTools::DotProduct(m_LhsBox.GetAxis0(), m_RhsBox.GetAxis1()));

    auto absLhs0DotDifference = Math::FAbs(Vector2DTools::DotProduct(m_LhsBox.GetAxis0(), boxCentersDifference));
    auto sum = m_LhsBox.GetExtent0() + m_RhsBox.GetExtent0() * absLhs0DotRhs0 + m_RhsBox.GetExtent1() * absLhs0DotRhs1;

    if (sum < absLhs0DotDifference)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * A1
    auto absLhs1DotRhs0 = Math::FAbs(Vector2DTools::DotProduct(m_LhsBox.GetAxis1(), m_RhsBox.GetAxis0()));
    auto absLhs1DotRhs1 = Math::FAbs(Vector2DTools::DotProduct(m_LhsBox.GetAxis1(), m_RhsBox.GetAxis1()));

    auto absLhs1DotDifference = Math::FAbs(Vector2DTools::DotProduct(m_LhsBox.GetAxis1(), boxCentersDifference));

    sum = m_LhsBox.GetExtent1() + m_RhsBox.GetExtent0() * absLhs1DotRhs0 + m_RhsBox.GetExtent1() * absLhs1DotRhs1;

    if (sum < absLhs1DotDifference)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * B0
    auto absRhs0DotDifference = Math::FAbs(Vector2DTools::DotProduct(m_RhsBox.GetAxis0(), boxCentersDifference));

    sum = m_RhsBox.GetExtent0() + m_LhsBox.GetExtent0() * absLhs0DotRhs0 + m_LhsBox.GetExtent1() * absLhs1DotRhs0;

    if (sum < absRhs0DotDifference)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // �� C0 + t * B1
    auto absRhs1DotDifference = Math::FAbs(Vector2DTools::DotProduct(m_RhsBox.GetAxis1(), boxCentersDifference));
    sum = m_RhsBox.GetExtent1() + m_LhsBox.GetExtent0() * absLhs0DotRhs1 + m_LhsBox.GetExtent1() * absLhs1DotRhs1;

    if (sum < absRhs1DotDifference)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetIntersectionType(IntersectionType::Other);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorBox2Box2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Box2<Real> Mathematics::StaticTestIntersectorBox2Box2<Real>::GetLhsBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LhsBox;
}

template <typename Real>
const Mathematics::Box2<Real> Mathematics::StaticTestIntersectorBox2Box2<Real>::GetRhsBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RhsBox;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_ACHIEVE_H
